# ----------------------
# MACROS
# ----------------------

# DIRS
INCDIR = include
BINDIR = bin
SRCDIR = src
BUILDDIR = build
LIBDIR = lib
CCFLEX = cc
# LEXER
LEXER = $(BINDIR)/mjclexer
# TARGET
TARGET = $(BINDIR)/mjc
# EXTENSIONS
CPPSRCEXT = hpp
HEADEREXT = h
# SOURCES LIST
SOURCES = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
# OBJECTS
OBJS = $(patsubst $(SRCDIR)/%, $(BUILDDIR)/%, $(SOURCES:.$(SRCEXT)=.o))  
# COMPILER
CC = g++ 
# FLEX
FLEX = flex
# FOR CLEANING
RM = /bin/rm
# WARNING FLAG
WARN = -Wall
# DEBUG FLAGS
DEBUG = -g
# LINKING FLAGS
LIBOPTS = 
LIBFLAG = -L $(LIBDIR) $(LIBOPTS)
INCFLAG = -I $(INCDIR)
LFLAGS = $(DEBUG) $(WARN) $(INCFLAG) $(LIBFLAG)
# COMPILATION FLAGS
CFLAGS = $(DEBUG) -c $(WARN) -std=c++11

# ----------------------
# ENTRIES
# ----------------------

$(TARGET): $(OBJS)
	@echo "Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LFLAGS)"; $(CC) $^ -o $(TARGET) $(LFLAGS)
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(CPPSRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INCFLAG) -o $@ $<"; $(CC) $(CFLAGS) $(INCFLAG) -o $@ $<	

# DUMMY ENTRIES
ll1parser:
	@echo "Making lexer...";
	$(FLEX) -o $(SRCDIR)/lex.yy.c -ll $(SRCDIR)/mjclexer.l;
	g++ $(SRCDIR)/MJMessage.cpp $(SRCDIR)/MJNonRecursiveParser.cpp $(SRCDIR)/MJRecursiveParser.cpp $(SRCDIR)/lex.yy.c $(SRCDIR)/MJToken.cpp $(SRCDIR)/MJLexLexer.cpp $(SRCDIR)/ParserDriver.cpp -o $(BINDIR)/mjcll1 $(INCFLAG) -std=c++11 -Wall


lexer:
	@echo "Building lexer...";
	@mkdir -p $(BUILDDIR)
	@mkdir -p $(BINDIR)
	$(FLEX) -o $(BUILDDIR)/lex.yy.c $(SRCDIR)/mjclexer.l;
	g++ $(SRCDIR)/MJToken.cpp $(BUILDDIR)/lex.yy.c -D__EXECUTABLE__ -o $(LEXER) $(INCFLAG);
	$(RM) -r $(BUILDDIR)/lex.yy.c;

clean:
	@echo "Cleaning..."
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

.PHONY: clean lexer

