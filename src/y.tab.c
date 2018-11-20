/* A Bison parser, made by GNU Bison 3.0.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "src/MJLALRParser.y" /* yacc.c:339  */


#include <stdio.h>
#include <string>
#include "ast/Node.h"
#include "ast/Expr.h"
#include "MJMessage.h"
#include "y.tab.h"
#include "../src/code-generation/MJCodeGenerator.cpp"
#include "frames/Frame.h"
#include "frames/Param.h"

extern int current_line;
extern int offset;
extern char * yytext;
extern int yychar;
extern int yylex();

void yyerror(char *s);

Position getPos();
Position getPos(YYLTYPE);

std::shared_ptr<Program> root;


#line 93 "src/y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_INCLUDE_Y_TAB_H_INCLUDED
# define YY_YY_INCLUDE_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    END_OF_FILE = 0,
    TOK_PROGRAM = 1,
    TOK_IDENTIFIER = 2,
    TOK_SEMICOLON = 3,
    TOK_CLASS = 4,
    TOK_LCURLY = 5,
    TOK_RCURLY = 6,
    TOK_DECLARATIONS = 7,
    TOK_ENDDECLARATIONS = 8,
    TOK_EQUALS = 9,
    TOK_COMMA = 10,
    TOK_INT = 11,
    TOK_STRING = 12,
    TOK_LRSQUARE = 13,
    TOK_METHOD = 14,
    TOK_LPAREN = 15,
    TOK_RPAREN = 16,
    TOK_VOID = 17,
    TOK_VAL = 18,
    TOK_ARROBA = 19,
    TOK_LSQUARE = 20,
    TOK_RSQUARE = 21,
    TOK_ASSIGN = 22,
    TOK_RETURN = 23,
    TOK_IF = 24,
    TOK_ELSE = 25,
    TOK_FOR = 26,
    TOK_TO = 27,
    TOK_STEP = 28,
    TOK_WHILE = 29,
    TOK_SWITCH = 30,
    TOK_CASE = 31,
    TOK_DEFAULT = 32,
    TOK_PRINT = 33,
    TOK_READ = 34,
    TOK_LESS = 35,
    TOK_LESSEQ = 36,
    TOK_EQEQ = 37,
    TOK_DIFF = 38,
    TOK_GREATEREQ = 39,
    TOK_GREATER = 40,
    TOK_PLUS = 41,
    TOK_UPLUS = 42,
    TOK_MINUS = 43,
    TOK_UMINUS = 44,
    TOK_NOT = 45,
    TOK_2PIPE = 46,
    TOK_ASTERISK = 47,
    TOK_SLASH = 48,
    TOK_AND = 49,
    TOK_MOD = 50,
    TOK_INTEGERCONSTANT = 51,
    TOK_STRINGCONSTANT = 52,
    TOK_DOT = 53,
    LAMBDA = 55
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 30 "src/MJLALRParser.y" /* yacc.c:355  */

    Var *var;
    Type *type;
    char * typeName;
    FormalParams *formalParams;
    VarInit *varInit;
    VarDeclId *varDeclId;
    ArrayInitVarInit *arrayInit;
    ArrayCreation* arrayCreation;
    AccessOperation *accessOp;
    ConstructList* constructList;
    Stmt* stmt;
    ReadStmt* readStmt;
    PrintStmt* printStmt;
    ReturnStmt* returnStmt;
    IfStmt* ifStmt;
    WhileStmt* whileStmt;
    ForStmt* forStmt;
    SwitchStmt* switchStmt;
    Case *case_;
    Expr *expr;
    AlExpr *alExpr;
    char* id;
    char* litString;
    int litInt;
    MethodReturnType* methodReturnType;
    MethodDecl* methodDecl;
    Block* block;
    Decls* decls;
    FieldDecl* fieldDecl;
    FieldDeclVar *fieldDeclVar;
    Program* program;
    ClassDecl* classDecl;
    ClassBody* classBody;

#line 227 "src/y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_INCLUDE_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 258 "src/y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   236

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  113
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  213

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   257

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,     2,    56,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   177,   177,   181,   184,   185,   188,   189,   191,   192,
     193,   194,   196,   197,   198,   204,   205,   211,   213,   215,
     217,   220,   222,   223,   224,   225,   226,   227,   228,   233,
     235,   236,   237,   239,   241,   244,   246,   249,   252,   253,
     254,   257,   258,   259,   260,   262,   263,   266,   268,   270,
     273,   275,   277,   278,   279,   282,   284,   286,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   301,
     303,   304,   305,   308,   312,   316,   322,   328,   330,   333,
     337,   338,   340,   341,   344,   346,   347,   349,   352,   355,
     358,   361,   364,   367,   369,   371,   373,   375,   378,   381,
     384,   387,   390,   393,   396,   397,   398,   399,   400,   401,
     404,   407,   408,   411
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "END_OF_FILE", "error", "$undefined", "TOK_PROGRAM", "TOK_IDENTIFIER",
  "TOK_SEMICOLON", "TOK_CLASS", "TOK_LCURLY", "TOK_RCURLY",
  "TOK_DECLARATIONS", "TOK_ENDDECLARATIONS", "TOK_EQUALS", "TOK_COMMA",
  "TOK_INT", "TOK_STRING", "TOK_LRSQUARE", "TOK_METHOD", "TOK_LPAREN",
  "TOK_RPAREN", "TOK_VOID", "TOK_VAL", "TOK_ARROBA", "TOK_LSQUARE",
  "TOK_RSQUARE", "TOK_ASSIGN", "TOK_RETURN", "TOK_IF", "TOK_ELSE",
  "TOK_FOR", "TOK_TO", "TOK_STEP", "TOK_WHILE", "TOK_SWITCH", "TOK_CASE",
  "TOK_DEFAULT", "TOK_PRINT", "TOK_READ", "TOK_LESS", "TOK_LESSEQ",
  "TOK_EQEQ", "TOK_DIFF", "TOK_GREATEREQ", "TOK_GREATER", "TOK_PLUS",
  "TOK_UPLUS", "TOK_MINUS", "TOK_UMINUS", "TOK_NOT", "TOK_2PIPE",
  "TOK_ASTERISK", "TOK_SLASH", "TOK_AND", "TOK_MOD", "TOK_INTEGERCONSTANT",
  "TOK_STRINGCONSTANT", "TOK_DOT", "LAMBDA", "$accept", "program",
  "class_decl_list", "class_decl", "class_body", "decls_opt", "decls",
  "method_decl_list", "field_decl_list_decls", "field_decl",
  "field_decl_aux", "field_decl_list", "type", "type_aux", "brackets_opt",
  "method_decl", "method_return_type", "formal_params",
  "formal_params_list", "id_list_comma", "formal_params_list_opt",
  "var_decl_id", "var_init", "array_init", "var_init_list_comma",
  "array_creation_expr", "array_dim_decl_list", "block", "stmt_list",
  "stmt_list_semicolon", "stmt", "actual_params_list", "expr_list_comma",
  "return_stmt", "if_stmt", "for_stmt", "while_stmt", "switch_stmt",
  "case", "case_list", "print_stmt", "read_stmt", "expr", "al_expr", "var",
  "var_aux", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    55
};
# endif

#define YYPACT_NINF -153

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-153)))

#define YYTABLE_NINF -84

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      30,    47,     8,    50,  -153,    60,    46,  -153,    60,    78,
      78,  -153,   132,  -153,  -153,    73,   181,    70,  -153,  -153,
      84,  -153,  -153,  -153,   112,    85,   111,   113,   139,   121,
      70,  -153,  -153,    12,   113,   120,  -153,   124,   113,  -153,
    -153,  -153,   140,  -153,  -153,  -153,  -153,   111,    11,  -153,
     125,  -153,    74,   -18,    11,    71,    12,    71,    71,    71,
    -153,  -153,  -153,  -153,  -153,  -153,   138,   129,    99,  -153,
    -153,    71,   143,  -153,   137,   142,   141,   166,   170,  -153,
    -153,  -153,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    44,   175,    12,   157,   192,
    -153,   182,   176,   194,   -18,    11,  -153,  -153,    71,  -153,
     153,   153,   153,   153,   153,   153,   105,   105,   105,  -153,
    -153,  -153,  -153,   189,  -153,   199,   157,   197,  -153,    63,
     199,   -18,    71,  -153,  -153,   187,  -153,    94,  -153,  -153,
     157,  -153,  -153,  -153,  -153,   170,   203,    95,  -153,  -153,
    -153,  -153,     4,    26,    71,   208,    71,    71,    71,   209,
     206,   210,  -153,  -153,  -153,  -153,  -153,  -153,  -153,    87,
    -153,  -153,  -153,    94,   193,    94,   211,  -153,  -153,  -153,
      95,    44,    71,   195,    71,  -153,    13,  -153,   198,  -153,
      67,   190,    94,    71,     2,     5,  -153,  -153,  -153,    71,
    -153,    94,  -153,  -153,    94,    77,  -153,   212,    71,  -153,
    -153,    94,  -153
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     2,     3,     0,
       0,     4,     0,     6,     5,     0,     0,    13,    10,     8,
       0,    23,    24,    25,     0,     0,     0,    26,     0,     0,
      13,    12,    11,    15,    26,    20,    17,    18,    26,    22,
      30,    31,     0,     7,    14,    16,    40,     0,     0,    27,
       0,    21,     0,   111,     0,     0,     0,     0,     0,     0,
     106,   107,    19,    42,    43,    41,    93,   108,     0,    45,
     105,     0,     0,   110,    46,     0,     0,     0,     0,    94,
      95,    96,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
      39,     0,     0,    68,   111,     0,    44,   104,     0,    48,
      88,    89,    87,    92,    90,    91,    97,    98,    99,   100,
     101,   102,   103,     0,    67,     9,     0,    36,    33,     0,
       9,   111,     0,   112,    47,     0,   109,     0,    29,    32,
       0,    35,    28,   113,    69,    49,     0,     0,    51,    37,
      50,    53,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    54,    59,    60,    62,    61,    63,    64,    65,     0,
      80,    58,    71,     0,     0,     0,     0,    85,    86,    52,
       0,     0,     0,    72,     0,    77,     0,    55,     0,    56,
       0,     0,     0,     0,     0,     0,    57,    74,    73,     0,
      82,     0,    84,    78,     0,     0,    81,     0,     0,    76,
      79,     0,    75
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -153,  -153,   213,  -153,   214,   215,  -153,   196,   200,  -153,
    -153,   178,   -27,  -153,   -14,  -153,  -153,  -153,   100,  -121,
    -153,  -153,   180,  -153,   118,  -153,    86,   102,  -152,    54,
    -153,    49,   -69,  -153,    45,  -153,  -153,  -153,  -153,    42,
    -153,  -153,   -48,    80,  -138,   -87
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,     8,    13,   137,    18,    29,    24,    25,
      35,    36,    26,    27,    39,    30,    42,    99,   100,   128,
     101,    37,    74,    63,    75,    64,   109,   138,   148,   160,
     161,   123,   124,   162,   163,   164,   165,   166,   194,   195,
     167,   168,   103,    66,    67,    73
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      65,    41,   102,   192,    71,   139,    65,    77,     4,   169,
     -83,   170,    52,   203,   192,    53,    21,   133,    54,   149,
      46,   183,   171,   185,    49,    22,    23,    76,    55,    78,
      53,   -70,    56,     1,   -70,   193,   -83,    72,   197,   204,
     200,    98,   169,    55,   143,    76,   193,     9,    53,   206,
      10,     3,   207,   209,    57,     5,    58,    65,    59,   212,
     135,    55,   -66,   144,    60,    61,     6,    21,   146,    57,
     126,    58,    76,    59,   147,    53,    22,    23,   146,    60,
      61,    19,    69,    97,   147,    12,    28,    57,    55,    58,
      33,    59,    70,   154,    31,   146,   152,    60,    61,    53,
      96,   147,    98,    21,   181,   172,   173,   208,   175,   176,
     177,   182,    22,    23,    57,    34,    58,   -38,    59,    97,
     153,   154,    32,   155,    60,    61,   156,   157,    38,    43,
     158,   159,    47,    15,   189,    48,   191,    79,    80,    81,
      -9,    16,    68,    21,    50,   201,    95,   104,    -9,   105,
     106,   205,    22,    23,    91,    92,    93,    94,    40,    70,
     211,   127,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,    82,    83,    84,    85,    86,
      87,    88,    20,    89,   107,    21,    90,    91,    92,    93,
      94,   -15,   108,   125,    22,    23,    88,   129,    89,   131,
     130,    90,    91,    92,    93,    94,   132,   136,    16,   140,
     145,   151,   174,   178,   179,   180,   196,   184,   186,   199,
     210,    11,   190,   134,    14,    51,    44,    17,    62,   141,
     188,   150,   142,    45,   187,   198,   202
};

static const yytype_uint8 yycheck[] =
{
      48,    28,    71,     1,    22,   126,    54,    55,     0,   147,
       8,     7,     1,     8,     1,     4,     4,   104,     7,   140,
      34,   173,    18,   175,    38,    13,    14,     1,    17,    56,
       4,     5,    21,     3,     8,    33,    34,    55,   190,    34,
     192,    68,   180,    17,   131,     1,    33,     1,     4,   201,
       4,     4,   204,   205,    43,     5,    45,   105,    47,   211,
     108,    17,    18,   132,    53,    54,     6,     4,     1,    43,
      97,    45,     1,    47,     7,     4,    13,    14,     1,    53,
      54,     8,     8,    20,     7,     7,    16,    43,    17,    45,
       5,    47,    18,    26,    10,     1,     1,    53,    54,     4,
       1,     7,   129,     4,    17,   153,   154,    30,   156,   157,
     158,    24,    13,    14,    43,     4,    45,    18,    47,    20,
      25,    26,    10,    28,    53,    54,    31,    32,    15,     8,
      35,    36,    12,     1,   182,    11,   184,    57,    58,    59,
       8,     9,    17,     4,     4,   193,    17,     4,    16,    12,
       8,   199,    13,    14,    49,    50,    51,    52,    19,    18,
     208,     4,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    37,    38,    39,    40,    41,
      42,    43,     1,    45,    18,     4,    48,    49,    50,    51,
      52,    10,    22,    18,    13,    14,    43,     5,    45,    23,
      18,    48,    49,    50,    51,    52,    12,    18,     9,    12,
      23,     8,     4,     4,     8,     5,    18,    24,     7,    29,
       8,     8,    27,   105,    10,    47,    30,    12,    48,   129,
     181,   145,   130,    33,   180,   190,   194
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    58,     4,     0,     5,     6,    59,    60,     1,
       4,    59,     7,    61,    61,     1,     9,    62,    63,     8,
       1,     4,    13,    14,    65,    66,    69,    70,    16,    64,
      72,    10,    10,     5,     4,    67,    68,    78,    15,    71,
      19,    69,    73,     8,    64,    65,    71,    12,    11,    71,
       4,    68,     1,     4,     7,    17,    21,    43,    45,    47,
      53,    54,    79,    80,    82,    99,   100,   101,    17,     8,
      18,    22,    55,   102,    79,    81,     1,    99,    69,   100,
     100,   100,    37,    38,    39,    40,    41,    42,    43,    45,
      48,    49,    50,    51,    52,    17,     1,    20,    69,    74,
      75,    77,    89,    99,     4,    12,     8,    18,    22,    83,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,    88,    89,    18,    69,     4,    76,     5,
      18,    23,    12,   102,    81,    99,    18,    62,    84,    76,
      12,    75,    84,   102,    89,    23,     1,     7,    85,    76,
      83,     8,     1,    25,    26,    28,    31,    32,    35,    36,
      86,    87,    90,    91,    92,    93,    94,    97,    98,   101,
       7,    18,    99,    99,     4,    99,    99,    99,     4,     8,
       5,    17,    24,    85,    24,    85,     7,    86,    88,    99,
      27,    99,     1,    33,    95,    96,    18,    85,    91,    29,
      85,    99,    96,     8,    34,    99,    85,    85,    30,    85,
       8,    99,    85
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    61,    61,    62,
      62,    63,    63,    64,    64,    65,    65,    66,    67,    67,
      68,    68,    69,    70,    70,    70,    71,    71,    72,    72,
      73,    73,    74,    74,    75,    75,    76,    76,    77,    77,
      78,    79,    79,    79,    80,    80,    81,    81,    82,    83,
      83,    84,    85,    85,    86,    86,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    88,    88,    89,    89,
      90,    90,    91,    91,    91,    92,    92,    93,    94,    94,
      94,    95,    95,    96,    96,    97,    98,    99,    99,    99,
      99,    99,    99,    99,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     101,   102,   102,   102
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     1,     2,     3,     3,     4,     3,     0,
       1,     3,     3,     0,     2,     0,     3,     2,     1,     3,
       1,     3,     2,     1,     1,     1,     0,     2,     7,     7,
       1,     1,     3,     2,     1,     3,     1,     3,     0,     1,
       2,     1,     1,     1,     3,     2,     1,     3,     3,     3,
       4,     2,     3,     2,     1,     3,     3,     4,     2,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     3,
       1,     2,     3,     5,     5,     9,     7,     3,     5,     7,
       2,     3,     2,     1,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     1,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     1,     1,     1,     4,
       2,     0,     3,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 177 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.program) = new Program(getPos((yylsp[-3])), 
                                                                                std::make_shared<Id>(getPos((yylsp[-2])), (yyvsp[-2].id)),
			                                                                  std::shared_ptr<ConstructList>((yyvsp[0].constructList))); 
                                                                                    root = std::shared_ptr<Program>((yyval.program));}
#line 1599 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 3:
#line 181 "src/MJLALRParser.y" /* yacc.c:1648  */
    {std::deque<std::shared_ptr<Node>> classes;
			                                                             classes.push_front(std::shared_ptr<ClassDecl>((yyvsp[0].classDecl)));
                                                                                     (yyval.constructList) = new ConstructList(getPos((yylsp[0])),classes);}
#line 1607 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 4:
#line 184 "src/MJLALRParser.y" /* yacc.c:1648  */
    {auto lst = (yyvsp[0].constructList); lst->push_front(std::shared_ptr<ClassDecl>((yyvsp[-1].classDecl)));(yyval.constructList)=lst;}
#line 1613 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 5:
#line 185 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.classDecl) = new ClassDecl(getPos((yylsp[-2])), 
                                                                                        std::make_shared<Id>(getPos((yylsp[-1])), std::string((yyvsp[-1].id))),
			                                                                  std::shared_ptr<ClassBody>((yyvsp[0].classBody)));}
#line 1621 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 6:
#line 188 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.classDecl)=nullptr;}
#line 1627 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 7:
#line 189 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.classBody) = new ClassBody(getPos((yyloc)), std::shared_ptr<Decls>((yyvsp[-2].decls)),
			                                                                  std::shared_ptr<ConstructList>((yyvsp[-1].constructList)));}
#line 1634 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 8:
#line 191 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.classBody)=nullptr;}
#line 1640 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 9:
#line 192 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.decls) = nullptr;}
#line 1646 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 10:
#line 193 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.decls) = (yyvsp[0].decls);}
#line 1652 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 11:
#line 194 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.decls) = new Decls(getPos((yylsp[-2])), 
                                                                                            std::shared_ptr<ConstructList>((yyvsp[-1].constructList)));}
#line 1659 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 12:
#line 196 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.decls)=nullptr;}
#line 1665 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 13:
#line 197 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.constructList) = nullptr;}
#line 1671 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 14:
#line 198 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.constructList)=(yyvsp[0].constructList); std::deque<std::shared_ptr<Node>> methodDecls;
                                                                                     auto lst = (yyvsp[0].constructList) == nullptr
                                                                                              ? new ConstructList(getPos((yylsp[-1])), methodDecls)
                                                                                              : (yyvsp[0].constructList);
                                                                                     lst->push_front(std::shared_ptr<MethodDecl>((yyvsp[-1].methodDecl)));
                                                                                     (yyval.constructList) = lst;}
#line 1682 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 15:
#line 204 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.constructList) = nullptr;}
#line 1688 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 16:
#line 205 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.constructList)=(yyvsp[0].constructList); std::deque<std::shared_ptr<Node>> fieldDecls;
                                                                                     auto lst = (yyvsp[0].constructList) == nullptr
                                                                                              ? new ConstructList(getPos((yylsp[-2])), fieldDecls)
                                                                                              : (yyvsp[0].constructList);
                                                                                     lst->push_front(std::shared_ptr<FieldDecl>((yyvsp[-2].fieldDecl)));
                                                                                     (yyval.constructList) = lst;}
#line 1699 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 17:
#line 211 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.fieldDecl) = new FieldDecl(getPos((yyloc)), std::shared_ptr<Type>((yyvsp[-1].type)),
			                                                                  std::shared_ptr<ConstructList>((yyvsp[0].constructList)));}
#line 1706 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 18:
#line 213 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.fieldDeclVar) = new FieldDeclVar(getPos((yylsp[0])),std::shared_ptr<VarDeclId>((yyvsp[0].varDeclId)),
                                                                                        std::shared_ptr<VarInit>(nullptr));}
#line 1713 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 19:
#line 215 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.fieldDeclVar) = new FieldDeclVar(getPos((yylsp[-2])),std::shared_ptr<VarDeclId>((yyvsp[-2].varDeclId)),
                                                                                          std::shared_ptr<VarInit> ((yyvsp[0].varInit)));}
#line 1720 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 20:
#line 217 "src/MJLALRParser.y" /* yacc.c:1648  */
    {std::deque<std::shared_ptr<Node>> fieldDeclVars;
			                                                             fieldDeclVars.push_front(std::shared_ptr<FieldDeclVar>((yyvsp[0].fieldDeclVar)));
                                                                                     (yyval.constructList) = new ConstructList(getPos((yylsp[0])),fieldDeclVars);}
#line 1728 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 21:
#line 220 "src/MJLALRParser.y" /* yacc.c:1648  */
    {auto lst = (yyvsp[0].constructList); lst->push_front(std::shared_ptr<FieldDeclVar>((yyvsp[-2].fieldDeclVar)));
                                                                                     (yyval.constructList) = lst;}
#line 1735 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 22:
#line 222 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.type) = new Type(getPos((yylsp[-1])), (yyvsp[0].litInt), (yyvsp[-1].litString));}
#line 1741 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 23:
#line 223 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.litString) = (yyvsp[0].id);}
#line 1747 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 24:
#line 224 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.litString) = (yyvsp[0].typeName);}
#line 1753 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 25:
#line 225 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.litString) = (yyvsp[0].typeName);}
#line 1759 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 26:
#line 226 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.litInt) = 0;}
#line 1765 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 27:
#line 227 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.litInt) = 1 + (yyvsp[0].litInt);}
#line 1771 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 28:
#line 229 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.methodDecl) = new MethodDecl(getPos((yylsp[-6])), std::shared_ptr<MethodReturnType>((yyvsp[-5].methodReturnType)),
                                                                                          std::make_shared<Id>(getPos((yylsp[-4])), std::string((yyvsp[-4].id))), 
                                                                                          std::shared_ptr<ConstructList>((yyvsp[-2].constructList)),
                                                                                          std::shared_ptr<Block>((yyvsp[0].block)));}
#line 1780 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 29:
#line 234 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.methodDecl)=nullptr;}
#line 1786 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 30:
#line 235 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.methodReturnType) = new MethodReturnType(getPos((yylsp[0])), std::shared_ptr<Type>(nullptr));}
#line 1792 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 31:
#line 236 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.methodReturnType) = new MethodReturnType(getPos((yylsp[0])), std::shared_ptr<Type>((yyvsp[0].type)));}
#line 1798 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 32:
#line 237 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.formalParams) = new FormalParams(getPos((yylsp[-2])), true, std::shared_ptr<Type>((yyvsp[-1].type)),
			                                                                  std::shared_ptr<ConstructList>((yyvsp[0].constructList)));}
#line 1805 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 33:
#line 239 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.formalParams) = new FormalParams(getPos((yyloc)), false, std::shared_ptr<Type>((yyvsp[-1].type)),
                                                                                          std::shared_ptr<ConstructList>((yyvsp[0].constructList)));}
#line 1812 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 34:
#line 241 "src/MJLALRParser.y" /* yacc.c:1648  */
    {std::deque<std::shared_ptr<Node>> formalParams;
		                                                                     formalParams.push_front(std::shared_ptr<FormalParams>((yyvsp[0].formalParams)));
                                                                                     (yyval.constructList) = new ConstructList(getPos((yylsp[0])),formalParams);}
#line 1820 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 35:
#line 244 "src/MJLALRParser.y" /* yacc.c:1648  */
    {auto lst = (yyvsp[0].constructList); lst->push_front(std::shared_ptr<FormalParams>((yyvsp[-2].formalParams)));
                                                                                     (yyval.constructList) = lst;}
#line 1827 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 36:
#line 246 "src/MJLALRParser.y" /* yacc.c:1648  */
    {std::deque<std::shared_ptr<Node>> ids;
			                                                             ids.push_front(std::make_shared<Id>(getPos((yylsp[0])), std::string((yyvsp[0].id))));
                                                                                     (yyval.constructList) = new ConstructList(getPos((yyloc)),ids);}
#line 1835 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 37:
#line 249 "src/MJLALRParser.y" /* yacc.c:1648  */
    {auto lst = (yyvsp[0].constructList); 
                                                                                    lst->push_front(std::make_shared<Id>(getPos((yylsp[-2])), std::string((yyvsp[-2].id))));
                                                                                     (yyval.constructList) = lst;}
#line 1843 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 38:
#line 252 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.constructList) = nullptr;}
#line 1849 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 39:
#line 253 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.constructList) = (yyvsp[0].constructList);}
#line 1855 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 40:
#line 254 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.varDeclId) = new VarDeclId(getPos((yyloc)), 
                                                                                                        std::make_shared<Id>(getPos((yylsp[-1])), 
                                                                                                        std::string((yyvsp[-1].id))), (yyvsp[0].litInt));}
#line 1863 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 41:
#line 257 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.varInit) = new ExprVarInit(getPos((yylsp[0])),std::shared_ptr<Expr>((yyvsp[0].expr)));}
#line 1869 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 42:
#line 258 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.varInit) = (yyvsp[0].arrayInit);}
#line 1875 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 43:
#line 259 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.varInit) = (yyvsp[0].arrayCreation);}
#line 1881 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 44:
#line 260 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.arrayInit) = new ArrayInitVarInit(getPos((yyloc)),
			                                                                      std::shared_ptr<ConstructList>((yyvsp[-1].constructList)));}
#line 1888 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 45:
#line 262 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.arrayInit)=nullptr;}
#line 1894 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 46:
#line 263 "src/MJLALRParser.y" /* yacc.c:1648  */
    {std::deque<std::shared_ptr<Node>> varInits;
		                                                                     varInits.push_front(std::shared_ptr<VarInit>((yyvsp[0].varInit)));
                                                                                     (yyval.constructList) = new ConstructList(getPos((yyloc)),varInits);}
#line 1902 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 47:
#line 266 "src/MJLALRParser.y" /* yacc.c:1648  */
    {auto lst = (yyvsp[0].constructList); lst->push_front(std::shared_ptr<VarInit>((yyvsp[-2].varInit)));
                                                                                     (yyval.constructList) = lst;}
#line 1909 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 48:
#line 268 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.arrayCreation) = new ArrayCreation(getPos((yyloc)), std::shared_ptr<Type>((yyvsp[-1].type)),
			                                                                      std::shared_ptr<ConstructList>((yyvsp[0].constructList)));}
#line 1916 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 49:
#line 270 "src/MJLALRParser.y" /* yacc.c:1648  */
    {std::deque<std::shared_ptr<Node>> exprs;
			                                                             exprs.push_front(std::shared_ptr<Expr>((yyvsp[-1].expr)));
                                                                                     (yyval.constructList) = new ConstructList(getPos((yyloc)),exprs);}
#line 1924 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 50:
#line 273 "src/MJLALRParser.y" /* yacc.c:1648  */
    {auto lst = (yyvsp[0].constructList); lst->push_front(std::shared_ptr<Expr>((yyvsp[-2].expr)));
                                                                                     (yyval.constructList) = lst;}
#line 1931 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 51:
#line 275 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.block) = new Block(getPos((yyloc)), std::shared_ptr<Decls>((yyvsp[-1].decls)),
			                                                                       std::shared_ptr<ConstructList>((yyvsp[0].constructList)));}
#line 1938 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 52:
#line 277 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.constructList) = (yyvsp[-1].constructList);}
#line 1944 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 53:
#line 278 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.constructList)=nullptr;}
#line 1950 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 54:
#line 279 "src/MJLALRParser.y" /* yacc.c:1648  */
    {std::deque<std::shared_ptr<Node>> stmts;
			                                                             stmts.push_front(std::shared_ptr<Stmt>((yyvsp[0].stmt)));
                                                                                     (yyval.constructList) = new ConstructList(getPos((yyloc)),stmts);}
#line 1958 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 55:
#line 282 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.constructList)=(yyvsp[0].constructList); auto lst = (yyvsp[0].constructList); lst->push_front(std::shared_ptr<Stmt>((yyvsp[-2].stmt)));
                                                                                     (yyval.constructList) = lst;}
#line 1965 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 56:
#line 284 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.stmt) = new AssignStmt(getPos((yyloc)), std::shared_ptr<Var>((yyvsp[-2].var)),
			                                                                                 std::shared_ptr<Expr>((yyvsp[0].expr)));}
#line 1972 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 57:
#line 286 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.stmt) = new FunctionCallStmt(getPos((yyloc)), std::shared_ptr<Var>((yyvsp[-3].var)),
                                                                                                         std::shared_ptr<ConstructList>((yyvsp[-1].constructList)));}
#line 1979 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 58:
#line 288 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.stmt)=nullptr;}
#line 1985 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 59:
#line 289 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.stmt) = (yyvsp[0].returnStmt);}
#line 1991 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 60:
#line 290 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.stmt) = (yyvsp[0].ifStmt);}
#line 1997 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 61:
#line 291 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.stmt) = (yyvsp[0].whileStmt);}
#line 2003 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 62:
#line 292 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.stmt) = (yyvsp[0].forStmt);}
#line 2009 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 63:
#line 293 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.stmt) = (yyvsp[0].switchStmt);}
#line 2015 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 64:
#line 294 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.stmt) = (yyvsp[0].printStmt);}
#line 2021 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 65:
#line 295 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.stmt) = (yyvsp[0].readStmt);}
#line 2027 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 66:
#line 296 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.constructList) = nullptr;}
#line 2033 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 67:
#line 297 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.constructList) = (yyvsp[0].constructList);}
#line 2039 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 68:
#line 298 "src/MJLALRParser.y" /* yacc.c:1648  */
    {std::deque<std::shared_ptr<Node>> exps; 
                                                                                     exps.push_front(std::shared_ptr<Expr>((yyvsp[0].expr)));
                                                                                     (yyval.constructList) = new ConstructList(getPos((yylsp[0])),exps);}
#line 2047 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 69:
#line 301 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.constructList)=(yyvsp[0].constructList); auto lst = (yyvsp[0].constructList); lst->push_front(std::shared_ptr<Expr>((yyvsp[-2].expr)));
                                                                                     (yyval.constructList) = lst;}
#line 2054 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 70:
#line 303 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.returnStmt) = new ReturnStmt(getPos((yylsp[0])), std::shared_ptr<Expr>(nullptr));}
#line 2060 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 71:
#line 304 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.returnStmt) = new ReturnStmt(getPos((yylsp[-1])), std::shared_ptr<Expr>((yyvsp[0].expr)));}
#line 2066 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 72:
#line 305 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.ifStmt) = new IfStmt(getPos((yylsp[-2])), std::shared_ptr<Expr>((yyvsp[-1].expr)),
			                                                                             std::shared_ptr<ConstructList>((yyvsp[0].constructList)),
                                                                                                     nullptr);}
#line 2074 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 73:
#line 308 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.ifStmt) = new IfStmt(getPos((yylsp[-4])), std::shared_ptr<Expr>((yyvsp[-3].expr)),
                                                                                                     std::shared_ptr<ConstructList>((yyvsp[-2].constructList)),
                                                                                                     std::make_shared<ElseIf>(getPos((yylsp[-1])),
                                                                                                                std::shared_ptr<IfStmt>((yyvsp[0].ifStmt))));}
#line 2083 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 74:
#line 312 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.ifStmt) = new IfStmt(getPos((yylsp[-4])), std::shared_ptr<Expr>((yyvsp[-3].expr)),
                                                                                                     std::shared_ptr<ConstructList>((yyvsp[-2].constructList)),
                                                                                                     std::make_shared<Else>(getPos((yylsp[-1])),
                                                                                                       std::shared_ptr<ConstructList>((yyvsp[0].constructList))));}
#line 2092 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 75:
#line 317 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.forStmt) = new ForStmt(getPos((yylsp[-8])), std::make_shared<Id>(getPos((yylsp[-7])), std::string((yyvsp[-7].id))), 
                                                                                                    std::shared_ptr<Expr>((yyvsp[-5].expr)),
                                                                                                      std::shared_ptr<Expr>((yyvsp[-3].expr)),
                                                                                                      std::shared_ptr<Expr>((yyvsp[-1].expr)),
                                                                                                      std::shared_ptr<ConstructList>((yyvsp[0].constructList)));}
#line 2102 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 76:
#line 323 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.forStmt) = new ForStmt(getPos((yylsp[-6])), 
                                                                                                    std::make_shared<Id>(getPos((yylsp[-5])), std::string((yyvsp[-5].id))), 
                                                                                                    std::shared_ptr<Expr>((yyvsp[-3].expr)),
                                                                                                      std::shared_ptr<Expr>((yyvsp[-1].expr)), nullptr,
                                                                                                      std::shared_ptr<ConstructList>((yyvsp[0].constructList)));}
#line 2112 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 77:
#line 328 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.whileStmt) = new WhileStmt(getPos((yylsp[-2])), std::shared_ptr<Expr>((yyvsp[-1].expr)),
			                                                                                std::shared_ptr<ConstructList>((yyvsp[0].constructList)));}
#line 2119 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 78:
#line 330 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.switchStmt) = new SwitchStmt(getPos((yylsp[-4])), std::shared_ptr<Expr>((yyvsp[-3].expr)),
			                                                                             std::shared_ptr<ConstructList>((yyvsp[-1].constructList)),
                                                                                                     nullptr);}
#line 2127 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 79:
#line 334 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.switchStmt) = new SwitchStmt(getPos((yylsp[-6])), std::shared_ptr<Expr>((yyvsp[-5].expr)),
                                                                                                     std::shared_ptr<ConstructList>((yyvsp[-3].constructList)),
                                                                                                     std::shared_ptr<ConstructList>((yyvsp[-1].constructList)));}
#line 2135 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 80:
#line 337 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.switchStmt)=nullptr;}
#line 2141 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 81:
#line 338 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.case_) = new Case(getPos((yylsp[-2])), std::shared_ptr<Expr>((yyvsp[-1].expr)),
			                                                                           std::shared_ptr<ConstructList>((yyvsp[0].constructList)));}
#line 2148 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 82:
#line 340 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.case_)=nullptr;}
#line 2154 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 83:
#line 341 "src/MJLALRParser.y" /* yacc.c:1648  */
    {std::deque<std::shared_ptr<Node>> cases;
			                                                                                     cases.push_front(std::shared_ptr<Case>((yyvsp[0].case_)));
                                                                                     (yyval.constructList) = new ConstructList(getPos((yylsp[0])),cases);}
#line 2162 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 84:
#line 344 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.constructList)=(yyvsp[0].constructList); auto lst = (yyvsp[0].constructList); lst->push_front(std::shared_ptr<Case>((yyvsp[-1].case_)));
                                                                                     (yyval.constructList) = lst;}
#line 2169 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 85:
#line 346 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.printStmt) = new PrintStmt(getPos((yylsp[-1])), std::shared_ptr<Expr>((yyvsp[0].expr)));}
#line 2175 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 86:
#line 347 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.readStmt) = new ReadStmt(getPos((yylsp[-1])), 
                                                                                                    std::make_shared<Id>(getPos((yylsp[0])), std::string((yyvsp[0].id))));}
#line 2182 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 87:
#line 349 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.expr) = new RelExpr(getPos((yylsp[-1])), RelExpr::RelOp::EQEQ,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 2190 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 88:
#line 352 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.expr) = new RelExpr(getPos((yylsp[-1])), RelExpr::RelOp::LESS,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 2198 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 89:
#line 355 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.expr) = new RelExpr(getPos((yylsp[-1])), RelExpr::RelOp::LESS_EQ,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 2206 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 90:
#line 358 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.expr) = new RelExpr(getPos((yylsp[-1])), RelExpr::RelOp::GREATER_EQ,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 2214 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 91:
#line 361 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.expr) = new RelExpr(getPos((yylsp[-1])), RelExpr::RelOp::GREATER,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 2222 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 92:
#line 364 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.expr) = new RelExpr(getPos((yylsp[-1])), RelExpr::RelOp::DIFF,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 2230 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 93:
#line 367 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.expr) = (yyvsp[0].alExpr);}
#line 2236 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 94:
#line 369 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.alExpr) = new AlUnExpr(getPos((yylsp[-1])), AlUnExpr::AlUnOp::PLUS,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 2243 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 95:
#line 371 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.alExpr) = new AlUnExpr(getPos((yylsp[-1])), AlUnExpr::AlUnOp::MINUS,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 2250 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 96:
#line 373 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.alExpr) = new AlUnExpr(getPos((yylsp[-1])), AlUnExpr::AlUnOp::NOT,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 2257 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 97:
#line 375 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.alExpr) = new AlBinExpr(getPos((yylsp[-1])), AlBinExpr::AlBinOp::PLUS,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 2265 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 98:
#line 378 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.alExpr) = new AlBinExpr(getPos((yylsp[-1])), AlBinExpr::AlBinOp::MINUS,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 2273 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 99:
#line 381 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.alExpr) = new AlBinExpr(getPos((yylsp[-1])), AlBinExpr::AlBinOp::OR,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 2281 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 100:
#line 384 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.alExpr) = new AlBinExpr(getPos((yylsp[-1])), AlBinExpr::AlBinOp::TIMES,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 2289 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 101:
#line 387 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.alExpr) = new AlBinExpr(getPos((yylsp[-1])), AlBinExpr::AlBinOp::DIV,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 2297 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 102:
#line 390 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.alExpr) = new AlBinExpr(getPos((yylsp[-1])), AlBinExpr::AlBinOp::AND,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 2305 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 103:
#line 393 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.alExpr) = new AlBinExpr(getPos((yylsp[-1])), AlBinExpr::AlBinOp::MOD,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 2313 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 104:
#line 396 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.alExpr) = new ExprParen(getPos((yylsp[-2])), std::shared_ptr<Expr>((yyvsp[-1].expr)));}
#line 2319 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 105:
#line 397 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.alExpr)=nullptr;}
#line 2325 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 106:
#line 398 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.alExpr) = new LitExpr<int>(getPos((yylsp[0])), (yyvsp[0].litInt));}
#line 2331 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 107:
#line 399 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.alExpr) = new LitExpr<std::string>(getPos((yylsp[0])), std::string((yyvsp[0].litString)));}
#line 2337 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 108:
#line 400 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.alExpr) = (yyvsp[0].var);}
#line 2343 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 109:
#line 401 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.alExpr) = new FunctionCallExpr(getPos((yylsp[-2])),
                                                                                          std::shared_ptr<Var>((yyvsp[-3].var)),
                                                                                          std::shared_ptr<ConstructList>((yyvsp[-1].constructList)));}
#line 2351 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 110:
#line 404 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.var) = new Var(getPos((yyloc)), 
                                                                                                        std::make_shared<Id>(getPos((yylsp[-1])), std::string((yyvsp[-1].id))), 
                                                                                                        std::shared_ptr<AccessOperation>((yyvsp[0].accessOp)));}
#line 2359 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 111:
#line 407 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.accessOp) = nullptr;}
#line 2365 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 112:
#line 408 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.accessOp) = new DotAccess(getPos((yylsp[-2])), 
                                                                                                        std::make_shared<Id>(getPos((yylsp[-1])), std::string((yyvsp[-1].id))),
                                                                                                        std::shared_ptr<AccessOperation>((yyvsp[0].accessOp)));}
#line 2373 "src/y.tab.c" /* yacc.c:1648  */
    break;

  case 113:
#line 411 "src/MJLALRParser.y" /* yacc.c:1648  */
    {(yyval.accessOp) = new BracketAccess(getPos((yylsp[-3])),
                                                                                          std::shared_ptr<ConstructList>((yyvsp[-2].constructList)),
                                                                                          std::shared_ptr<AccessOperation>((yyvsp[0].accessOp)));}
#line 2381 "src/y.tab.c" /* yacc.c:1648  */
    break;


#line 2385 "src/y.tab.c" /* yacc.c:1648  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 414 "src/MJLALRParser.y" /* yacc.c:1907  */



Position getPos() {
    return Position{-1,-1};
}
Position getPos(YYLTYPE loc) {
    return Position{loc.first_line, loc.first_column};
}

void yyerror(char *s) { 
    std::string parse_error = "parse error near " + get_token_name(yychar) + ", lexeme " + std::string(yytext);
    MJMessage::print(MJMessage::Type::ERROR, parse_error, Lexer::Position {current_line, offset});
}


int main() {
    auto ret = yyparse();
    if (root != nullptr) {
        //root->computeLevel();
        //std::cout << root->print() << std::endl;
        generateCode(root);
    }
    return ret;
}


int yywrap() {
    return 1;
}
