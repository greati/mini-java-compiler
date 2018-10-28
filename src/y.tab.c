/* A Bison parser, made by GNU Bison 3.1.  */

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
#define YYBISON_VERSION "3.1"

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

extern int current_line;
extern int offset;
extern char * yytext;
extern int yychar;
extern int yylex();

void yyerror(char *s);

Position getPos();

Program *root;


#line 89 "src/y.tab.c" /* yacc.c:339  */

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
/* Tokens.  */
#define END_OF_FILE 0
#define TOK_PROGRAM 1
#define TOK_IDENTIFIER 2
#define TOK_SEMICOLON 3
#define TOK_CLASS 4
#define TOK_LCURLY 5
#define TOK_RCURLY 6
#define TOK_DECLARATIONS 7
#define TOK_ENDDECLARATIONS 8
#define TOK_EQUALS 9
#define TOK_COMMA 10
#define TOK_INT 11
#define TOK_STRING 12
#define TOK_LRSQUARE 13
#define TOK_METHOD 14
#define TOK_LPAREN 15
#define TOK_RPAREN 16
#define TOK_VOID 17
#define TOK_VAL 18
#define TOK_ARROBA 19
#define TOK_LSQUARE 20
#define TOK_RSQUARE 21
#define TOK_ASSIGN 22
#define TOK_RETURN 23
#define TOK_IF 24
#define TOK_ELSE 25
#define TOK_FOR 26
#define TOK_TO 27
#define TOK_STEP 28
#define TOK_WHILE 29
#define TOK_SWITCH 30
#define TOK_CASE 31
#define TOK_DEFAULT 32
#define TOK_PRINT 33
#define TOK_READ 34
#define TOK_LESS 35
#define TOK_LESSEQ 36
#define TOK_EQEQ 37
#define TOK_DIFF 38
#define TOK_GREATEREQ 39
#define TOK_GREATER 40
#define TOK_PLUS 41
#define TOK_UPLUS 42
#define TOK_MINUS 43
#define TOK_UMINUS 44
#define TOK_NOT 45
#define TOK_2PIPE 46
#define TOK_ASTERISK 47
#define TOK_SLASH 48
#define TOK_AND 49
#define TOK_MOD 50
#define TOK_INTEGERCONSTANT 51
#define TOK_STRINGCONSTANT 52
#define TOK_DOT 53
#define LAMBDA 55

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 24 "src/MJLALRParser.y" /* yacc.c:355  */

    Var *var;
    Type *type;
    char * typeName;
    FormalParams *formalParams;
    VarInit *varInit;
    VarDeclId *varDeclId;
    ArrayInitVarInit *arrayInit;
    ArrayCreation* arrayCreation;
    AccessOperation *accessOp;
    ConstructList<Expr>* constructList;
    ConstructList<Case>* caseList;
    ConstructList<Stmt>* stmtList;
    ConstructList<VarInit>* varInitList;
    ConstructList<FormalParams> *formalParamsList;
    ConstructList<FieldDeclVar> *fieldDeclVarList;
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
    ConstructList<Id>* stringList;
    MethodReturnType* methodReturnType;
    MethodDecl* methodDecl;
    Block* block;
    Decls* decls;
    FieldDecl* fieldDecl;
    FieldDeclVar *fieldDeclVar;
    Program* program;
    ClassDecl* classDecl;
    ClassBody* classBody;
    ConstructList<ClassDecl>* classDeclList;
    ConstructList<MethodDecl>* methodDeclList;
    ConstructList<FieldDecl>* fieldDeclList;

#line 288 "src/y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INCLUDE_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 305 "src/y.tab.c" /* yacc.c:358  */

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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYLAST   279

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  218

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   257

#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
       0,   180,   180,   183,   186,   187,   190,   191,   193,   194,
     195,   196,   197,   198,   199,   205,   206,   212,   214,   216,
     218,   221,   223,   224,   225,   226,   227,   228,   229,   234,
     236,   237,   238,   240,   242,   245,   247,   250,   253,   254,
     255,   257,   258,   259,   260,   262,   263,   266,   268,   270,
     273,   275,   277,   278,   279,   282,   284,   286,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   301,
     303,   304,   305,   308,   312,   316,   322,   328,   330,   333,
     337,   338,   339,   341,   342,   345,   347,   348,   350,   353,
     356,   359,   362,   365,   368,   370,   372,   374,   376,   379,
     382,   385,   388,   391,   394,   397,   398,   399,   400,   401,
     402,   405,   406,   409,   410,   413
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

#define YYPACT_NINF -139

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-139)))

#define YYTABLE_NINF -67

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      43,     9,    14,    47,  -139,    51,    18,  -139,    51,    52,
      52,  -139,    15,  -139,  -139,    56,    82,    49,  -139,  -139,
      60,  -139,  -139,  -139,    67,    77,    83,    75,     7,    86,
      49,  -139,  -139,   119,    75,    85,  -139,    87,    75,  -139,
    -139,  -139,    97,  -139,  -139,  -139,  -139,    83,   123,  -139,
      94,  -139,   -18,     8,    46,   119,    98,    98,    98,  -139,
    -139,  -139,  -139,  -139,  -139,   217,    96,   233,    98,   113,
    -139,   111,   114,   121,   117,   120,   115,  -139,  -139,  -139,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    26,   124,   119,   127,   134,  -139,   131,
     139,   151,   -18,  -139,   123,  -139,  -139,  -139,    98,  -139,
     227,   227,   227,   227,   227,   227,   109,   109,   109,  -139,
    -139,  -139,  -139,   146,   149,  -139,   160,   127,   159,  -139,
     108,   160,   -18,    98,  -139,  -139,   152,  -139,  -139,   165,
    -139,  -139,   127,  -139,  -139,  -139,  -139,   115,   190,  -139,
    -139,  -139,   166,    98,    98,   177,    98,    71,    98,   178,
     175,   179,  -139,  -139,  -139,  -139,  -139,  -139,  -139,    21,
    -139,  -139,   165,   163,   165,   181,   185,  -139,  -139,  -139,
     213,    31,    98,   168,    98,  -139,  -139,     6,  -139,   180,
     182,  -139,    10,   164,   188,   103,   186,     0,  -139,  -139,
    -139,  -139,    98,  -139,   165,   165,  -139,  -139,   165,    11,
    -139,  -139,   191,    98,  -139,  -139,   165,  -139
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
       0,    21,   113,     0,     0,     0,     0,     0,     0,   107,
     108,    19,    42,    43,    41,    94,   109,     0,     0,     0,
     112,     0,    46,     0,     0,     0,     0,    95,    96,    97,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    34,    39,     0,
       0,    68,   113,    45,     0,    44,   106,   105,     0,    48,
      89,    90,    88,    93,    91,    92,    98,    99,   100,   101,
     102,   103,   104,     0,     0,    67,     9,     0,    36,    33,
       0,     9,   113,     0,   114,    47,     0,   111,   110,     0,
      29,    32,     0,    35,    28,   115,    69,    49,     0,    51,
      37,    50,     0,    70,     0,     0,     0,     0,     0,     0,
       0,    54,    59,    60,    62,    61,    63,    64,    65,     0,
      53,    71,     0,     0,     0,     0,     0,    86,    87,    52,
       0,     0,     0,    72,     0,    77,    80,     0,    55,     0,
       0,    56,     0,     0,     0,     0,    84,     0,    58,    57,
      74,    73,     0,    81,     0,     0,    85,    78,     0,     0,
      83,    82,     0,     0,    76,    79,     0,    75
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -139,  -139,   193,  -139,   210,   211,  -139,   194,   195,  -139,
    -139,   183,   -27,  -139,    20,  -139,  -139,  -139,    99,   -61,
    -139,  -139,   184,  -139,   129,  -139,    80,   100,   -19,    55,
    -139,    59,   -66,  -139,    44,  -139,  -139,  -139,  -139,    54,
    -139,  -139,   -48,   122,  -138,   -99
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,     8,    13,   139,    18,    29,    24,    25,
      35,    36,    26,    27,    39,    30,    42,    97,    98,   129,
      99,    37,    72,    62,    73,    63,   109,   140,   149,   160,
     161,   124,   125,   162,   163,   164,   165,   166,   196,   197,
     167,   168,   101,    65,    66,    70
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      64,    41,   100,   134,    68,    64,    75,   194,   207,    71,
     169,    21,    52,     3,     4,    53,    15,   148,   148,     9,
      22,    23,    10,    -9,    16,    54,    40,   123,    76,    55,
      52,    -9,   189,   145,   208,    52,   154,    69,   181,   195,
      96,   213,   169,    54,   -66,   182,     1,    74,    54,   -66,
      52,    56,     5,    57,    46,    58,    64,     6,    49,    12,
     136,    59,    60,    54,    19,    28,   141,   146,   127,    56,
      31,    57,   175,    58,    56,    52,    57,    32,    58,    59,
      60,   150,    33,    20,    59,    60,    21,    34,    54,    56,
      38,    57,   -15,    58,    43,    22,    23,    47,    48,    59,
      60,    50,    52,    96,   204,   171,   172,    52,   174,   176,
     177,    67,    21,    93,    56,    54,    57,   102,    58,   103,
      54,    22,    23,    21,    59,    60,   104,    52,    95,   105,
      53,   128,    22,    23,   191,   106,   193,   108,   107,   130,
      54,    56,   126,    57,    55,    58,    56,   205,    57,   131,
      58,    59,    60,   183,   209,   185,    59,    60,    89,    90,
      91,    92,   132,   133,   137,   216,    56,   138,    57,    16,
      58,   142,   148,   200,   170,   147,    59,    60,    77,    78,
      79,   173,   178,   179,   180,   210,   211,   184,   186,   212,
     214,   152,   187,   202,    52,   192,   203,   217,   198,   215,
     199,    11,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   153,   154,    52,   155,   195,
      14,   156,   157,    17,    44,   158,   159,   151,    45,   143,
      51,   144,    61,   135,    94,   188,   201,    21,   153,   154,
     190,   155,     0,     0,   156,   157,    22,    23,   158,   159,
     206,   -38,     0,    95,    80,    81,    82,    83,    84,    85,
      86,     0,    87,     0,     0,    88,    89,    90,    91,    92,
      86,     0,    87,     0,     0,    88,    89,    90,    91,    92
};

static const yytype_int16 yycheck[] =
{
      48,    28,    68,   102,    22,    53,    54,     1,     8,     1,
     148,     4,     4,     4,     0,     7,     1,     7,     7,     1,
      13,    14,     4,     8,     9,    17,    19,     1,    55,    21,
       4,    16,     1,   132,    34,     4,    26,    55,    17,    33,
      67,    30,   180,    17,    18,    24,     3,     1,    17,    18,
       4,    43,     5,    45,    34,    47,   104,     6,    38,     7,
     108,    53,    54,    17,     8,    16,   127,   133,    95,    43,
      10,    45,     1,    47,    43,     4,    45,    10,    47,    53,
      54,   142,     5,     1,    53,    54,     4,     4,    17,    43,
      15,    45,    10,    47,     8,    13,    14,    12,    11,    53,
      54,     4,     4,   130,     1,   153,   154,     4,   156,   157,
     158,    17,     4,    17,    43,    17,    45,     4,    47,     8,
      17,    13,    14,     4,    53,    54,    12,     4,    20,     8,
       7,     4,    13,    14,   182,    18,   184,    22,    18,     5,
      17,    43,    18,    45,    21,    47,    43,   195,    45,    18,
      47,    53,    54,   172,   202,   174,    53,    54,    49,    50,
      51,    52,    23,    12,    18,   213,    43,    18,    45,     9,
      47,    12,     7,   192,     8,    23,    53,    54,    56,    57,
      58,     4,     4,     8,     5,   204,   205,    24,     7,   208,
     209,     1,     7,    29,     4,    27,     8,   216,    18,     8,
      18,     8,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    25,    26,     4,    28,    33,
      10,    31,    32,    12,    30,    35,    36,   147,    33,   130,
      47,   131,    48,   104,     1,   180,   192,     4,    25,    26,
     181,    28,    -1,    -1,    31,    32,    13,    14,    35,    36,
     196,    18,    -1,    20,    37,    38,    39,    40,    41,    42,
      43,    -1,    45,    -1,    -1,    48,    49,    50,    51,    52,
      43,    -1,    45,    -1,    -1,    48,    49,    50,    51,    52
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
       4,    68,     4,     7,    17,    21,    43,    45,    47,    53,
      54,    79,    80,    82,    99,   100,   101,    17,    22,    55,
     102,     1,    79,    81,     1,    99,    69,   100,   100,   100,
      37,    38,    39,    40,    41,    42,    43,    45,    48,    49,
      50,    51,    52,    17,     1,    20,    69,    74,    75,    77,
      89,    99,     4,     8,    12,     8,    18,    18,    22,    83,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,     1,    88,    89,    18,    69,     4,    76,
       5,    18,    23,    12,   102,    81,    99,    18,    18,    62,
      84,    76,    12,    75,    84,   102,    89,    23,     7,    85,
      76,    83,     1,    25,    26,    28,    31,    32,    35,    36,
      86,    87,    90,    91,    92,    93,    94,    97,    98,   101,
       8,    99,    99,     4,    99,     1,    99,    99,     4,     8,
       5,    17,    24,    85,    24,    85,     7,     7,    86,     1,
      88,    99,    27,    99,     1,    33,    95,    96,    18,    18,
      85,    91,    29,     8,     1,    99,    96,     8,    34,    99,
      85,    85,    85,    30,    85,     8,    99,    85
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
      94,    94,    95,    95,    96,    96,    97,    98,    99,    99,
      99,    99,    99,    99,    99,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   101,   102,   102,   102
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     1,     2,     3,     3,     4,     3,     0,
       1,     3,     3,     0,     2,     0,     3,     2,     1,     3,
       1,     3,     2,     1,     1,     1,     0,     2,     7,     7,
       1,     1,     3,     2,     1,     3,     1,     3,     0,     1,
       2,     1,     1,     1,     3,     3,     1,     3,     3,     3,
       4,     2,     3,     3,     1,     3,     3,     4,     4,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     3,
       1,     2,     3,     5,     5,     9,     7,     3,     5,     7,
       3,     5,     3,     3,     1,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     1,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       4,     4,     2,     0,     3,     4
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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
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
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 180 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.program) = new Program(getPos(), 
                                                                                std::make_shared<Id>(getPos(), (yyvsp[-2].id)),
			                                                                  std::shared_ptr<ConstructList<ClassDecl>>((yyvsp[0].classDeclList))); root = (yyval.program);}
#line 1557 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 3:
#line 183 "src/MJLALRParser.y" /* yacc.c:1651  */
    {std::vector<std::shared_ptr<Node>> classes;
			                                                             classes.push_back(std::shared_ptr<ClassDecl>((yyvsp[0].classDecl)));
                                                                                     (yyval.classDeclList) = new ConstructList<ClassDecl>(getPos(),classes);}
#line 1565 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 4:
#line 186 "src/MJLALRParser.y" /* yacc.c:1651  */
    {auto lst = (yyvsp[0].classDeclList); lst->push_back(std::shared_ptr<ClassDecl>((yyvsp[-1].classDecl)));(yyval.classDeclList)=lst;}
#line 1571 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 5:
#line 187 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.classDecl) = new ClassDecl(getPos(), 
                                                                                        std::make_shared<Id>(getPos(), std::string((yyvsp[-1].id))),
			                                                                  std::shared_ptr<ClassBody>((yyvsp[0].classBody)));}
#line 1579 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 6:
#line 190 "src/MJLALRParser.y" /* yacc.c:1651  */
    {}
#line 1585 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 7:
#line 191 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.classBody) = new ClassBody(getPos(), std::shared_ptr<Decls>((yyvsp[-2].decls)),
			                                                                  std::shared_ptr<ConstructList<MethodDecl>>((yyvsp[-1].methodDeclList)));}
#line 1592 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 8:
#line 193 "src/MJLALRParser.y" /* yacc.c:1651  */
    {}
#line 1598 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 9:
#line 194 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.decls) = nullptr;}
#line 1604 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 10:
#line 195 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.decls) = (yyvsp[0].decls);}
#line 1610 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 11:
#line 196 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.decls) = new Decls(getPos(), std::shared_ptr<ConstructList<FieldDecl>>((yyvsp[-1].fieldDeclList)));}
#line 1616 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 12:
#line 197 "src/MJLALRParser.y" /* yacc.c:1651  */
    {}
#line 1622 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 13:
#line 198 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.methodDeclList) = nullptr;}
#line 1628 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 14:
#line 199 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.methodDeclList)=(yyvsp[0].methodDeclList); std::vector<std::shared_ptr<Node>> methodDecls;
                                                                                     auto lst = (yyvsp[0].methodDeclList) == nullptr
                                                                                              ? new ConstructList<MethodDecl>(getPos(), methodDecls)
                                                                                              : (yyvsp[0].methodDeclList);
                                                                                     lst->push_back(std::shared_ptr<MethodDecl>((yyvsp[-1].methodDecl)));
                                                                                     (yyval.methodDeclList) = lst;}
#line 1639 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 15:
#line 205 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.fieldDeclList) = nullptr;}
#line 1645 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 16:
#line 206 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.fieldDeclList)=(yyvsp[0].fieldDeclList); std::vector<std::shared_ptr<Node>> fieldDecls;
                                                                                     auto lst = (yyvsp[0].fieldDeclList) == nullptr
                                                                                              ? new ConstructList<FieldDecl>(getPos(), fieldDecls)
                                                                                              : (yyvsp[0].fieldDeclList);
                                                                                     lst->push_back(std::shared_ptr<FieldDecl>((yyvsp[-2].fieldDecl)));
                                                                                     (yyval.fieldDeclList) = lst;}
#line 1656 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 17:
#line 212 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.fieldDecl) = new FieldDecl(getPos(), std::shared_ptr<Type>((yyvsp[-1].type)),
			                                                                  std::shared_ptr<ConstructList<FieldDeclVar>>((yyvsp[0].fieldDeclVarList)));}
#line 1663 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 18:
#line 214 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.fieldDeclVar) = new FieldDeclVar(getPos(),std::shared_ptr<VarDeclId>((yyvsp[0].varDeclId)),
                                                                                        std::shared_ptr<VarInit>(nullptr));}
#line 1670 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 19:
#line 216 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.fieldDeclVar) = new FieldDeclVar(getPos(),std::shared_ptr<VarDeclId>((yyvsp[-2].varDeclId)),
                                                                                          std::shared_ptr<VarInit> ((yyvsp[0].varInit)));}
#line 1677 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 20:
#line 218 "src/MJLALRParser.y" /* yacc.c:1651  */
    {std::vector<std::shared_ptr<Node>> fieldDeclVars;
			                                                             fieldDeclVars.push_back(std::shared_ptr<FieldDeclVar>((yyvsp[0].fieldDeclVar)));
                                                                                     (yyval.fieldDeclVarList) = new ConstructList<FieldDeclVar>(getPos(),fieldDeclVars);}
#line 1685 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 21:
#line 221 "src/MJLALRParser.y" /* yacc.c:1651  */
    {auto lst = (yyvsp[0].fieldDeclVarList); lst->push_back(std::shared_ptr<FieldDeclVar>((yyvsp[-2].fieldDeclVar)));
                                                                                     (yyval.fieldDeclVarList) = lst;}
#line 1692 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 22:
#line 223 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.type) = new Type(getPos(), (yyvsp[0].litInt), (yyvsp[-1].litString));}
#line 1698 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 23:
#line 224 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.litString) = (yyvsp[0].id);}
#line 1704 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 24:
#line 225 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.litString) = (yyvsp[0].typeName);}
#line 1710 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 25:
#line 226 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.litString) = (yyvsp[0].typeName);}
#line 1716 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 26:
#line 227 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.litInt) = 0;}
#line 1722 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 27:
#line 228 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.litInt) = 1 + (yyvsp[0].litInt);}
#line 1728 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 28:
#line 230 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.methodDecl) = new MethodDecl(getPos(), std::shared_ptr<MethodReturnType>((yyvsp[-5].methodReturnType)),
                                                                                          std::make_shared<Id>(getPos(), std::string((yyvsp[-4].id))), 
                                                                                          std::shared_ptr<ConstructList<FormalParams>>((yyvsp[-2].formalParamsList)),
                                                                                          std::shared_ptr<Block>((yyvsp[0].block)));}
#line 1737 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 29:
#line 235 "src/MJLALRParser.y" /* yacc.c:1651  */
    {}
#line 1743 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 30:
#line 236 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.methodReturnType) = new MethodReturnType(getPos(), std::shared_ptr<Type>(nullptr));}
#line 1749 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 31:
#line 237 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.methodReturnType) = new MethodReturnType(getPos(), std::shared_ptr<Type>((yyvsp[0].type)));}
#line 1755 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 32:
#line 238 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.formalParams) = new FormalParams(getPos(), true, std::shared_ptr<Type>((yyvsp[-1].type)),
			                                                                  std::shared_ptr<ConstructList<Id>>((yyvsp[0].stringList)));}
#line 1762 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 33:
#line 240 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.formalParams) = new FormalParams(getPos(), false, std::shared_ptr<Type>((yyvsp[-1].type)),
                                                                                          std::shared_ptr<ConstructList<Id>>((yyvsp[0].stringList)));}
#line 1769 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 34:
#line 242 "src/MJLALRParser.y" /* yacc.c:1651  */
    {std::vector<std::shared_ptr<Node>> formalParams;
		                                                                     formalParams.push_back(std::shared_ptr<FormalParams>((yyvsp[0].formalParams)));
                                                                                     (yyval.formalParamsList) = new ConstructList<FormalParams>(getPos(),formalParams);}
#line 1777 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 35:
#line 245 "src/MJLALRParser.y" /* yacc.c:1651  */
    {auto lst = (yyvsp[0].formalParamsList); lst->push_back(std::shared_ptr<FormalParams>((yyvsp[-2].formalParams)));
                                                                                     (yyval.formalParamsList) = lst;}
#line 1784 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 36:
#line 247 "src/MJLALRParser.y" /* yacc.c:1651  */
    {std::vector<std::shared_ptr<Node>> ids;
			                                                             ids.push_back(std::make_shared<Id>(getPos(), std::string((yyvsp[0].id))));
                                                                                     (yyval.stringList) = new ConstructList<Id>(getPos(),ids);}
#line 1792 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 37:
#line 250 "src/MJLALRParser.y" /* yacc.c:1651  */
    {auto lst = (yyvsp[0].stringList); 
                                                                                    lst->push_back(std::make_shared<Id>(getPos(), std::string((yyvsp[-2].id))));
                                                                                     (yyval.stringList) = lst;}
#line 1800 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 38:
#line 253 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.formalParamsList) = nullptr;}
#line 1806 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 39:
#line 254 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.formalParamsList) = (yyvsp[0].formalParamsList);}
#line 1812 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 40:
#line 255 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.varDeclId) = new VarDeclId(getPos(), 
                                                                                                        std::make_shared<Id>(getPos(), std::string((yyvsp[-1].id))), (yyvsp[0].litInt));}
#line 1819 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 41:
#line 257 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.varInit) = new ExprVarInit(getPos(),std::shared_ptr<Expr>((yyvsp[0].expr)));}
#line 1825 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 42:
#line 258 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.varInit) = (yyvsp[0].arrayInit);}
#line 1831 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 43:
#line 259 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.varInit) = (yyvsp[0].arrayCreation);}
#line 1837 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 44:
#line 260 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.arrayInit) = new ArrayInitVarInit(getPos(),
			                                                                      std::shared_ptr<ConstructList<VarInit>>((yyvsp[-1].varInitList)));}
#line 1844 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 45:
#line 262 "src/MJLALRParser.y" /* yacc.c:1651  */
    {}
#line 1850 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 46:
#line 263 "src/MJLALRParser.y" /* yacc.c:1651  */
    {std::vector<std::shared_ptr<Node>> varInits;
		                                                                     varInits.push_back(std::shared_ptr<VarInit>((yyvsp[0].varInit)));
                                                                                     (yyval.varInitList) = new ConstructList<VarInit>(getPos(),varInits);}
#line 1858 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 47:
#line 266 "src/MJLALRParser.y" /* yacc.c:1651  */
    {auto lst = (yyvsp[0].varInitList); lst->push_back(std::shared_ptr<VarInit>((yyvsp[-2].varInit)));
                                                                                     (yyval.varInitList) = lst;}
#line 1865 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 48:
#line 268 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.arrayCreation) = new ArrayCreation(getPos(), std::shared_ptr<Type>((yyvsp[-1].type)),
			                                                                      std::shared_ptr<ConstructList<Expr>>((yyvsp[0].constructList)));}
#line 1872 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 49:
#line 270 "src/MJLALRParser.y" /* yacc.c:1651  */
    {std::vector<std::shared_ptr<Node>> exprs;
			                                                             exprs.push_back(std::shared_ptr<Expr>((yyvsp[-1].expr)));
                                                                                     (yyval.constructList) = new ConstructList<Expr>(getPos(),exprs);}
#line 1880 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 50:
#line 273 "src/MJLALRParser.y" /* yacc.c:1651  */
    {auto lst = (yyvsp[0].constructList); lst->push_back(std::shared_ptr<Expr>((yyvsp[-2].expr)));
                                                                                     (yyval.constructList) = lst;}
#line 1887 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 51:
#line 275 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.block) = new Block(getPos(), std::shared_ptr<Decls>((yyvsp[-1].decls)),
			                                                                       std::shared_ptr<ConstructList<Stmt>>((yyvsp[0].stmtList)));}
#line 1894 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 52:
#line 277 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.stmtList) = (yyvsp[-1].stmtList);}
#line 1900 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 53:
#line 278 "src/MJLALRParser.y" /* yacc.c:1651  */
    {}
#line 1906 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 54:
#line 279 "src/MJLALRParser.y" /* yacc.c:1651  */
    {std::vector<std::shared_ptr<Node>> stmts;
			                                                             stmts.push_back(std::shared_ptr<Stmt>((yyvsp[0].stmt)));
                                                                                     (yyval.stmtList) = new ConstructList<Stmt>(getPos(),stmts);}
#line 1914 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 55:
#line 282 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.stmtList)=(yyvsp[0].stmtList); auto lst = (yyvsp[0].stmtList); lst->push_back(std::shared_ptr<Stmt>((yyvsp[-2].stmt)));
                                                                                     (yyval.stmtList) = lst;}
#line 1921 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 56:
#line 284 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.stmt) = new AssignStmt(getPos(), std::shared_ptr<Var>((yyvsp[-2].var)),
			                                                                                 std::shared_ptr<Expr>((yyvsp[0].expr)));}
#line 1928 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 57:
#line 286 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.stmt) = new FunctionCallStmt(getPos(), std::shared_ptr<Var>((yyvsp[-3].var)),
                                                                                                         std::shared_ptr<ConstructList<Expr>>((yyvsp[-1].constructList)));}
#line 1935 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 58:
#line 288 "src/MJLALRParser.y" /* yacc.c:1651  */
    {}
#line 1941 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 59:
#line 289 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.stmt) = (yyvsp[0].returnStmt);}
#line 1947 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 60:
#line 290 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.stmt) = (yyvsp[0].ifStmt);}
#line 1953 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 61:
#line 291 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.stmt) = (yyvsp[0].whileStmt);}
#line 1959 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 62:
#line 292 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.stmt) = (yyvsp[0].forStmt);}
#line 1965 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 63:
#line 293 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.stmt) = (yyvsp[0].switchStmt);}
#line 1971 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 64:
#line 294 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.stmt) = (yyvsp[0].printStmt);}
#line 1977 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 65:
#line 295 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.stmt) = (yyvsp[0].readStmt);}
#line 1983 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 66:
#line 296 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.constructList) = nullptr;}
#line 1989 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 67:
#line 297 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.constructList) = (yyvsp[0].constructList);}
#line 1995 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 68:
#line 298 "src/MJLALRParser.y" /* yacc.c:1651  */
    {std::vector<std::shared_ptr<Node>> exps; 
                                                                                     exps.push_back(std::shared_ptr<Expr>((yyvsp[0].expr)));
                                                                                     (yyval.constructList) = new ConstructList<Expr>(getPos(),exps);}
#line 2003 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 69:
#line 301 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.constructList)=(yyvsp[0].constructList); auto lst = (yyvsp[0].constructList); lst->push_back(std::shared_ptr<Expr>((yyvsp[-2].expr)));
                                                                                     (yyval.constructList) = lst;}
#line 2010 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 70:
#line 303 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.returnStmt) = new ReturnStmt(getPos(), std::shared_ptr<Expr>(nullptr));}
#line 2016 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 71:
#line 304 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.returnStmt) = new ReturnStmt(getPos(), std::shared_ptr<Expr>((yyvsp[0].expr)));}
#line 2022 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 72:
#line 305 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.ifStmt) = new IfStmt(getPos(), std::shared_ptr<Expr>((yyvsp[-1].expr)),
			                                                                             std::shared_ptr<ConstructList<Stmt>>((yyvsp[0].stmtList)),
                                                                                                     nullptr);}
#line 2030 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 73:
#line 308 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.ifStmt) = new IfStmt(getPos(), std::shared_ptr<Expr>((yyvsp[-3].expr)),
                                                                                                     std::shared_ptr<ConstructList<Stmt>>((yyvsp[-2].stmtList)),
                                                                                                     std::make_shared<ElseIf>(getPos(),
                                                                                                                std::shared_ptr<IfStmt>((yyvsp[0].ifStmt))));}
#line 2039 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 74:
#line 312 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.ifStmt) = new IfStmt(getPos(), std::shared_ptr<Expr>((yyvsp[-3].expr)),
                                                                                                     std::shared_ptr<ConstructList<Stmt>>((yyvsp[-2].stmtList)),
                                                                                                     std::make_shared<Else>(getPos(),
                                                                                                       std::shared_ptr<ConstructList<Stmt>>((yyvsp[0].stmtList))));}
#line 2048 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 75:
#line 317 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.forStmt) = new ForStmt(getPos(), std::make_shared<Id>(getPos(), std::string((yyvsp[-7].id))), 
                                                                                                    std::shared_ptr<Expr>((yyvsp[-5].expr)),
                                                                                                      std::shared_ptr<Expr>((yyvsp[-3].expr)),
                                                                                                      std::shared_ptr<Expr>((yyvsp[-1].expr)),
                                                                                                      std::shared_ptr<ConstructList<Stmt>>((yyvsp[0].stmtList)));}
#line 2058 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 76:
#line 323 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.forStmt) = new ForStmt(getPos(), 
                                                                                                    std::make_shared<Id>(getPos(), std::string((yyvsp[-5].id))), 
                                                                                                    std::shared_ptr<Expr>((yyvsp[-3].expr)),
                                                                                                      std::shared_ptr<Expr>((yyvsp[-1].expr)), nullptr,
                                                                                                      std::shared_ptr<ConstructList<Stmt>>((yyvsp[0].stmtList)));}
#line 2068 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 77:
#line 328 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.whileStmt) = new WhileStmt(getPos(), std::shared_ptr<Expr>((yyvsp[-1].expr)),
			                                                                                std::shared_ptr<ConstructList<Stmt>>((yyvsp[0].stmtList)));}
#line 2075 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 78:
#line 330 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.switchStmt) = new SwitchStmt(getPos(), std::shared_ptr<Expr>((yyvsp[-3].expr)),
			                                                                             std::shared_ptr<ConstructList<Case>>((yyvsp[-1].caseList)),
                                                                                                     nullptr);}
#line 2083 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 79:
#line 334 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.switchStmt) = new SwitchStmt(getPos(), std::shared_ptr<Expr>((yyvsp[-5].expr)),
                                                                                                     std::shared_ptr<ConstructList<Case>>((yyvsp[-3].caseList)),
                                                                                                     std::shared_ptr<ConstructList<Stmt>>((yyvsp[-1].stmtList)));}
#line 2091 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 80:
#line 337 "src/MJLALRParser.y" /* yacc.c:1651  */
    {}
#line 2097 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 81:
#line 338 "src/MJLALRParser.y" /* yacc.c:1651  */
    {}
#line 2103 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 82:
#line 339 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.case_) = new Case(getPos(), std::shared_ptr<Expr>((yyvsp[-1].expr)),
			                                                                           std::shared_ptr<ConstructList<Stmt>>((yyvsp[0].stmtList)));}
#line 2110 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 83:
#line 341 "src/MJLALRParser.y" /* yacc.c:1651  */
    {}
#line 2116 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 84:
#line 342 "src/MJLALRParser.y" /* yacc.c:1651  */
    {std::vector<std::shared_ptr<Node>> cases;
			                                                                                     cases.push_back(std::shared_ptr<Case>((yyvsp[0].case_)));
                                                                                     (yyval.caseList) = new ConstructList<Case>(getPos(),cases);}
#line 2124 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 85:
#line 345 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.caseList)=(yyvsp[0].caseList); auto lst = (yyvsp[0].caseList); lst->push_back(std::shared_ptr<Case>((yyvsp[-1].case_)));
                                                                                     (yyval.caseList) = lst;}
#line 2131 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 86:
#line 347 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.printStmt) = new PrintStmt(getPos(), std::shared_ptr<Expr>((yyvsp[0].expr)));}
#line 2137 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 87:
#line 348 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.readStmt) = new ReadStmt(getPos(), 
                                                                                                    std::make_shared<Id>(getPos(), std::string((yyvsp[0].id))));}
#line 2144 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 88:
#line 350 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.expr) = new RelExpr(getPos(), RelExpr::RelOp::EQEQ,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 2152 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 89:
#line 353 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.expr) = new RelExpr(getPos(), RelExpr::RelOp::LESS,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 2160 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 90:
#line 356 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.expr) = new RelExpr(getPos(), RelExpr::RelOp::LESS_EQ,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 2168 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 91:
#line 359 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.expr) = new RelExpr(getPos(), RelExpr::RelOp::GREATER_EQ,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 2176 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 92:
#line 362 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.expr) = new RelExpr(getPos(), RelExpr::RelOp::GREATER,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 2184 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 93:
#line 365 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.expr) = new RelExpr(getPos(), RelExpr::RelOp::DIFF,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 2192 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 94:
#line 368 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.expr) = (yyvsp[0].alExpr);}
#line 2198 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 95:
#line 370 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.alExpr) = new AlUnExpr(getPos(), AlUnExpr::AlUnOp::PLUS,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 2205 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 96:
#line 372 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.alExpr) = new AlUnExpr(getPos(), AlUnExpr::AlUnOp::MINUS,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 2212 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 97:
#line 374 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.alExpr) = new AlUnExpr(getPos(), AlUnExpr::AlUnOp::NOT,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 2219 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 98:
#line 376 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.alExpr) = new AlBinExpr(getPos(), AlBinExpr::AlBinOp::PLUS,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 2227 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 99:
#line 379 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.alExpr) = new AlBinExpr(getPos(), AlBinExpr::AlBinOp::MINUS,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 2235 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 100:
#line 382 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.alExpr) = new AlBinExpr(getPos(), AlBinExpr::AlBinOp::OR,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 2243 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 101:
#line 385 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.alExpr) = new AlBinExpr(getPos(), AlBinExpr::AlBinOp::TIMES,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 2251 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 102:
#line 388 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.alExpr) = new AlBinExpr(getPos(), AlBinExpr::AlBinOp::DIV,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 2259 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 103:
#line 391 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.alExpr) = new AlBinExpr(getPos(), AlBinExpr::AlBinOp::AND,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 2267 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 104:
#line 394 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.alExpr) = new AlBinExpr(getPos(), AlBinExpr::AlBinOp::MOD,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 2275 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 105:
#line 397 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.alExpr) = new ExprParen(getPos(), std::shared_ptr<Expr>((yyvsp[-1].expr)));}
#line 2281 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 106:
#line 398 "src/MJLALRParser.y" /* yacc.c:1651  */
    {}
#line 2287 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 107:
#line 399 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.alExpr) = new LitExpr<int>(getPos(), (yyvsp[0].litInt));}
#line 2293 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 108:
#line 400 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.alExpr) = new LitExpr<std::string>(getPos(), std::string((yyvsp[0].litString)));}
#line 2299 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 109:
#line 401 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.alExpr) = (yyvsp[0].var);}
#line 2305 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 110:
#line 402 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.alExpr) = new FunctionCallExpr(getPos(),
                                                                                          std::shared_ptr<Var>((yyvsp[-3].var)),
                                                                                          std::shared_ptr<ConstructList<Expr>>((yyvsp[-1].constructList)));}
#line 2313 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 111:
#line 405 "src/MJLALRParser.y" /* yacc.c:1651  */
    {}
#line 2319 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 112:
#line 406 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.var) = new Var(getPos(), 
                                                                                                        std::make_shared<Id>(getPos(), std::string((yyvsp[-1].id))), 
                                                                                                        std::shared_ptr<AccessOperation>((yyvsp[0].accessOp)));}
#line 2327 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 113:
#line 409 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.accessOp) = nullptr;}
#line 2333 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 114:
#line 410 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.accessOp) = new DotAccess(getPos(), 
                                                                                                        std::make_shared<Id>(getPos(), std::string((yyvsp[-1].id))),
                                                                                                        std::shared_ptr<AccessOperation>((yyvsp[0].accessOp)));}
#line 2341 "src/y.tab.c" /* yacc.c:1651  */
    break;

  case 115:
#line 413 "src/MJLALRParser.y" /* yacc.c:1651  */
    {(yyval.accessOp) = new BracketAccess(getPos(),
                                                                                          std::shared_ptr<ConstructList<Expr>>((yyvsp[-2].constructList)),
                                                                                          std::shared_ptr<AccessOperation>((yyvsp[0].accessOp)));}
#line 2349 "src/y.tab.c" /* yacc.c:1651  */
    break;


#line 2353 "src/y.tab.c" /* yacc.c:1651  */
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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
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
#line 416 "src/MJLALRParser.y" /* yacc.c:1910  */



Position getPos() {
    return Position{current_line, offset};
}

void yyerror(char *s) { 
    std::string parse_error = "parse error near " + get_token_name(yychar) + ", lexeme " + std::string(yytext);
    MJMessage::print(MJMessage::Type::ERROR, parse_error, Lexer::Position {current_line, offset});
}

int main() {
    auto ret = yyparse();
    root->computeLevel();
    std::cout << root->print() << std::endl;
    return ret;
}

int yywrap() {
    return 1;
}
