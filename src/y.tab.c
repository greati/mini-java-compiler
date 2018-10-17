/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

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



#line 88 "src/y.tab.c" /* yacc.c:339  */

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
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 23 "src/MJLALRParser.y" /* yacc.c:355  */

    Node *node;
    Var *var;
    AccessOperation *accessOp;
    ConstructList<Expr>* constructList;
    Expr *expr;
    AlExpr *alExpr;
    char* id;
    char* litString;
    int litInt;

#line 254 "src/y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INCLUDE_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 269 "src/y.tab.c" /* yacc.c:358  */

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
#define YYLAST   282

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  226

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
static const yytype_uint8 yyrline[] =
{
       0,   107,   107,   108,   108,   109,   110,   111,   112,   113,
     113,   114,   115,   116,   116,   117,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     174,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     197,   200,   203,   206,   209,   212,   214,   216,   218,   220,
     223,   226,   229,   232,   235,   238,   241,   242,   243,   244,
     245,   246,   249,   250,   252,   253,   255
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
  "field_decl_aux1", "field_decl_aux2", "type", "type_aux", "brackets_opt",
  "method_decl", "method_return_type", "formal_params",
  "formal_params_list", "id_list_comma", "formal_params_list_opt",
  "var_decl_id", "var_init", "array_init", "var_init_list_comma",
  "array_creation_expr", "array_dim_decl", "array_dim_decl_list", "block",
  "stmt_list", "stmt_list_semicolon", "stmt", "actual_params_list",
  "expr_list_comma", "return_stmt", "if_stmt", "for_stmt", "while_stmt",
  "switch_stmt", "case", "case_list", "print_stmt", "read_stmt", "expr",
  "al_expr", "var", "var_aux", YY_NULLPTR
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

#define YYPACT_NINF -150

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-150)))

#define YYTABLE_NINF -68

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      18,    27,    33,    42,  -150,    51,    16,    51,    56,    56,
    -150,    51,    14,  -150,  -150,  -150,    64,    75,    43,  -150,
    -150,    68,  -150,  -150,  -150,    77,    81,    87,    83,    30,
      88,    43,  -150,  -150,    70,    83,  -150,   113,    83,  -150,
    -150,  -150,    99,  -150,  -150,  -150,  -150,   128,    87,  -150,
    -150,    97,   -18,     7,    52,    70,   123,   123,   123,  -150,
    -150,   106,  -150,  -150,  -150,   201,   105,  -150,   217,   123,
     127,  -150,   125,   124,   116,   119,   117,  -150,  -150,  -150,
    -150,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,    28,   120,    70,   140,   148,  -150,
     136,   144,   157,   -18,  -150,   128,   177,  -150,  -150,   123,
     117,   211,   211,   211,   211,   211,   211,    59,    59,    59,
    -150,  -150,  -150,  -150,   169,   170,  -150,   182,   188,   184,
     138,   182,   -18,   123,  -150,   124,  -150,   174,   117,  -150,
    -150,  -150,   192,  -150,   184,   194,  -150,  -150,  -150,  -150,
    -150,  -150,  -150,  -150,   158,  -150,  -150,   184,   193,   123,
     123,   196,   123,    76,   123,   198,   215,  -150,  -150,  -150,
    -150,  -150,  -150,  -150,     1,  -150,  -150,  -150,   192,   200,
     192,   218,   221,  -150,  -150,   191,   224,    47,   123,   202,
     123,  -150,  -150,     8,   215,  -150,   216,   227,  -150,     9,
     204,   228,   103,   214,     4,  -150,  -150,  -150,  -150,  -150,
     123,  -150,   192,   192,  -150,  -150,   192,    12,  -150,  -150,
     240,   123,  -150,  -150,   192,  -150
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     3,     0,     0,
       2,     3,     0,     6,     5,     4,     0,     0,    13,    10,
       8,     0,    23,    24,    25,     0,     0,     0,    26,     0,
       0,    13,    12,    11,    15,    26,    17,    20,    26,    22,
      30,    31,     0,     7,    14,    16,    40,     0,     0,    18,
      27,     0,   114,     0,     0,     0,     0,     0,     0,   108,
     109,    20,    42,    43,    41,    95,   110,    21,     0,     0,
       0,   113,     0,    46,     0,     0,     0,    96,    97,    98,
      19,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    34,    39,
       0,     0,    69,   114,    45,     0,     0,   107,   106,     0,
      50,    90,    91,    89,    94,    92,    93,    99,   100,   101,
     102,   103,   104,   105,     0,     0,    68,     9,     0,    36,
       0,     9,   114,     0,   115,    46,    44,     0,    50,    48,
     112,   111,     0,    29,    36,     0,    33,    35,    28,   116,
      70,    47,    49,    51,     0,    52,    32,    36,     0,    71,
       0,     0,     0,     0,     0,     0,    55,    60,    61,    63,
      62,    64,    65,    66,     0,    37,    54,    72,     0,     0,
       0,     0,     0,    87,    88,     0,     0,     0,     0,    73,
       0,    78,    81,     0,    55,    53,     0,     0,    57,     0,
       0,     0,     0,    85,     0,    56,    59,    58,    75,    74,
       0,    82,     0,     0,    86,    79,     0,     0,    84,    83,
       0,     0,    77,    80,     0,    76
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -150,  -150,   244,   252,   249,   253,  -150,   233,   232,  -150,
     219,   207,   -28,  -150,    32,  -150,  -150,  -150,   139,  -131,
    -150,  -150,   -50,  -150,   135,  -150,   195,   134,   142,   -52,
      80,    90,    89,   -67,  -150,    78,  -150,  -150,  -150,  -150,
      79,  -150,  -150,   -47,   122,  -149,   -93
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    10,    11,    13,   142,    19,    30,    25,    26,
      36,    49,    27,    28,    39,    31,    42,    98,    99,   146,
     100,    37,    61,    62,   106,    63,   138,   139,   143,   155,
     186,   166,   125,   126,   167,   168,   169,   170,   171,   203,
     204,   172,   173,   102,    65,    66,    71
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      64,    41,   101,    73,    69,   174,    64,    75,    72,   201,
     134,    52,   215,   156,    53,    16,   154,     8,   187,   154,
       9,     1,    -9,    17,    54,   188,   175,    76,    55,   124,
      -9,     3,    52,     4,    22,   160,   174,    70,   216,   149,
      97,   202,   221,    23,    24,    54,   -67,     5,   196,    40,
      56,    52,    57,    74,    58,   135,    52,     6,    64,    29,
      59,    60,   137,    12,    54,   -67,   150,    46,   128,    54,
      50,    56,    20,    57,    22,    58,    21,   181,    32,    22,
      52,    59,    60,    23,    24,   -15,    34,    33,    23,    24,
      56,    35,    57,    54,    58,    56,    43,    57,    38,    58,
      59,    60,    97,    51,   212,    59,    60,    52,    90,    91,
      92,    93,   177,   178,    68,   180,   182,   183,    48,    56,
      54,    57,    94,    58,    47,    48,   189,    52,   191,    59,
      60,   103,    52,   104,   107,    53,   105,   108,   127,   109,
      54,   198,    22,   200,   129,    54,    56,   208,    57,    55,
      58,    23,    24,   130,   131,   213,    59,    60,    96,   158,
     218,   219,    52,   217,   220,   222,    56,   132,    57,   133,
      58,    56,   225,    57,   224,    58,    59,    60,    77,    78,
      79,    59,    60,   159,   160,   136,   161,   140,   141,   162,
     163,    17,   144,   164,   165,    52,   145,   152,   157,   154,
     179,   176,   184,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   159,   160,    95,   161,
     185,    22,   162,   163,   190,   192,   164,   165,   193,   199,
      23,    24,   195,   210,   206,   -38,   211,    96,    81,    82,
      83,    84,    85,    86,    87,   207,    88,   202,   223,    89,
      90,    91,    92,    93,    87,    15,    88,     7,    14,    89,
      90,    91,    92,    93,    44,    18,    45,    67,    80,   147,
     151,   110,   153,   148,   205,   194,   197,   209,     0,     0,
       0,     0,   214
};

static const yytype_int16 yycheck[] =
{
      47,    29,    69,    53,    22,   154,    53,    54,     1,     1,
     103,     4,     8,   144,     7,     1,     7,     1,    17,     7,
       4,     3,     8,     9,    17,    24,   157,    55,    21,     1,
      16,     4,     4,     0,     4,    26,   185,    55,    34,   132,
      68,    33,    30,    13,    14,    17,    18,     5,     1,    19,
      43,     4,    45,     1,    47,   105,     4,     6,   105,    16,
      53,    54,   109,     7,    17,    18,   133,    35,    96,    17,
      38,    43,     8,    45,     4,    47,     1,     1,    10,     4,
       4,    53,    54,    13,    14,    10,     5,    10,    13,    14,
      43,     4,    45,    17,    47,    43,     8,    45,    15,    47,
      53,    54,   130,     4,     1,    53,    54,     4,    49,    50,
      51,    52,   159,   160,    17,   162,   163,   164,    12,    43,
      17,    45,    17,    47,    11,    12,   178,     4,   180,    53,
      54,     4,     4,     8,    18,     7,    12,    18,    18,    22,
      17,   188,     4,   190,     4,    17,    43,   199,    45,    21,
      47,    13,    14,     5,    18,   202,    53,    54,    20,     1,
     212,   213,     4,   210,   216,   217,    43,    23,    45,    12,
      47,    43,   224,    45,   221,    47,    53,    54,    56,    57,
      58,    53,    54,    25,    26,     8,    28,    18,    18,    31,
      32,     9,     4,    35,    36,     4,    12,    23,     4,     7,
       4,     8,     4,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    25,    26,     1,    28,
       5,     4,    31,    32,    24,     7,    35,    36,     7,    27,
      13,    14,     8,    29,    18,    18,     8,    20,    37,    38,
      39,    40,    41,    42,    43,    18,    45,    33,     8,    48,
      49,    50,    51,    52,    43,    11,    45,     5,     9,    48,
      49,    50,    51,    52,    31,    12,    34,    48,    61,   130,
     135,    76,   138,   131,   194,   185,   187,   199,    -1,    -1,
      -1,    -1,   203
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    58,     4,     0,     5,     6,    60,     1,     4,
      59,    60,     7,    61,    61,    59,     1,     9,    62,    63,
       8,     1,     4,    13,    14,    65,    66,    69,    70,    16,
      64,    72,    10,    10,     5,     4,    67,    78,    15,    71,
      19,    69,    73,     8,    64,    65,    71,    11,    12,    68,
      71,     4,     4,     7,    17,    21,    43,    45,    47,    53,
      54,    79,    80,    82,   100,   101,   102,    67,    17,    22,
      55,   103,     1,    79,     1,   100,    69,   101,   101,   101,
      68,    37,    38,    39,    40,    41,    42,    43,    45,    48,
      49,    50,    51,    52,    17,     1,    20,    69,    74,    75,
      77,    90,   100,     4,     8,    12,    81,    18,    18,    22,
      83,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,     1,    89,    90,    18,    69,     4,
       5,    18,    23,    12,   103,    79,     8,   100,    83,    84,
      18,    18,    62,    85,     4,    12,    76,    75,    85,   103,
      90,    81,    23,    84,     7,    86,    76,     4,     1,    25,
      26,    28,    31,    32,    35,    36,    88,    91,    92,    93,
      94,    95,    98,    99,   102,    76,     8,   100,   100,     4,
     100,     1,   100,   100,     4,     5,    87,    17,    24,    86,
      24,    86,     7,     7,    88,     8,     1,    89,   100,    27,
     100,     1,    33,    96,    97,    87,    18,    18,    86,    92,
      29,     8,     1,   100,    97,     8,    34,   100,    86,    86,
      86,    30,    86,     8,   100,    86
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    61,    61,    62,
      62,    63,    63,    64,    64,    65,    65,    66,    67,    67,
      68,    68,    69,    70,    70,    70,    71,    71,    72,    72,
      73,    73,    74,    74,    75,    75,    76,    76,    77,    77,
      78,    79,    79,    79,    80,    80,    81,    81,    82,    83,
      84,    84,    85,    86,    86,    87,    87,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    89,    89,    90,
      90,    91,    91,    92,    92,    92,    93,    93,    94,    95,
      95,    95,    95,    96,    96,    97,    97,    98,    99,   100,
     100,   100,   100,   100,   100,   100,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   102,   103,   103,   103
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     0,     2,     3,     3,     4,     3,     0,
       1,     3,     3,     0,     2,     0,     3,     2,     2,     4,
       0,     2,     2,     1,     1,     1,     0,     2,     7,     7,
       1,     1,     4,     3,     1,     3,     0,     3,     0,     1,
       2,     1,     1,     1,     4,     3,     0,     3,     4,     3,
       0,     2,     2,     4,     3,     0,     3,     3,     4,     4,
       1,     1,     1,     1,     1,     1,     1,     0,     1,     1,
       3,     1,     2,     3,     5,     5,     9,     7,     3,     5,
       7,     3,     5,     3,     3,     1,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     1,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     4,     4,     2,     0,     3,     4
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
        case 67:
#line 168 "src/MJLALRParser.y" /* yacc.c:1646  */
    {(yyval.constructList) = nullptr;}
#line 1523 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 169 "src/MJLALRParser.y" /* yacc.c:1646  */
    {(yyval.constructList) = (yyvsp[0].constructList);}
#line 1529 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 170 "src/MJLALRParser.y" /* yacc.c:1646  */
    {std::vector<std::shared_ptr<Expr>> exps; 
                                                                                     exps.push_back(std::shared_ptr<Expr>((yyvsp[0].expr)));
                                                                                     (yyval.constructList) = new ConstructList<Expr>(getPos(),
                                                                                         exps);}
#line 1538 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 174 "src/MJLALRParser.y" /* yacc.c:1646  */
    {auto lst = (yyvsp[0].constructList); lst->push_back(std::shared_ptr<Expr>((yyvsp[-2].expr)));
                                                                                    (yyval.constructList) = lst;}
#line 1545 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 194 "src/MJLALRParser.y" /* yacc.c:1646  */
    {(yyval.expr) = new RelExpr(getPos(), RelExpr::RelOp::EQEQ,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 1553 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 197 "src/MJLALRParser.y" /* yacc.c:1646  */
    {(yyval.expr) = new RelExpr(getPos(), RelExpr::RelOp::LESS,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 1561 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 200 "src/MJLALRParser.y" /* yacc.c:1646  */
    {(yyval.expr) = new RelExpr(getPos(), RelExpr::RelOp::LESS_EQ,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 1569 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 203 "src/MJLALRParser.y" /* yacc.c:1646  */
    {(yyval.expr) = new RelExpr(getPos(), RelExpr::RelOp::GREATER_EQ,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 1577 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 206 "src/MJLALRParser.y" /* yacc.c:1646  */
    {(yyval.expr) = new RelExpr(getPos(), RelExpr::RelOp::GREATER,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 1585 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 209 "src/MJLALRParser.y" /* yacc.c:1646  */
    {(yyval.expr) = new RelExpr(getPos(), RelExpr::RelOp::DIFF,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 1593 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 212 "src/MJLALRParser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].alExpr);}
#line 1599 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 214 "src/MJLALRParser.y" /* yacc.c:1646  */
    {(yyval.alExpr) = new AlUnExpr(getPos(), AlUnExpr::AlUnOp::PLUS,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 1606 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 216 "src/MJLALRParser.y" /* yacc.c:1646  */
    {(yyval.alExpr) = new AlUnExpr(getPos(), AlUnExpr::AlUnOp::MINUS,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 1613 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 218 "src/MJLALRParser.y" /* yacc.c:1646  */
    {(yyval.alExpr) = new AlUnExpr(getPos(), AlUnExpr::AlUnOp::NOT,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 1620 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 220 "src/MJLALRParser.y" /* yacc.c:1646  */
    {(yyval.alExpr) = new AlBinExpr(getPos(), AlBinExpr::AlBinOp::PLUS,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 1628 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 223 "src/MJLALRParser.y" /* yacc.c:1646  */
    {(yyval.alExpr) = new AlBinExpr(getPos(), AlBinExpr::AlBinOp::MINUS,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 1636 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 226 "src/MJLALRParser.y" /* yacc.c:1646  */
    {(yyval.alExpr) = new AlBinExpr(getPos(), AlBinExpr::AlBinOp::OR,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 1644 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 229 "src/MJLALRParser.y" /* yacc.c:1646  */
    {(yyval.alExpr) = new AlBinExpr(getPos(), AlBinExpr::AlBinOp::TIMES,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 1652 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 232 "src/MJLALRParser.y" /* yacc.c:1646  */
    {(yyval.alExpr) = new AlBinExpr(getPos(), AlBinExpr::AlBinOp::DIV,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 1660 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 235 "src/MJLALRParser.y" /* yacc.c:1646  */
    {(yyval.alExpr) = new AlBinExpr(getPos(), AlBinExpr::AlBinOp::AND,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 1668 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 238 "src/MJLALRParser.y" /* yacc.c:1646  */
    {(yyval.alExpr) = new AlBinExpr(getPos(), AlBinExpr::AlBinOp::MOD,
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[-2].alExpr)),
                                                                                                        std::shared_ptr<AlExpr>((yyvsp[0].alExpr)));}
#line 1676 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 241 "src/MJLALRParser.y" /* yacc.c:1646  */
    {(yyval.alExpr) = new ExprParen(getPos(), std::shared_ptr<Expr>((yyvsp[-1].expr)));}
#line 1682 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 242 "src/MJLALRParser.y" /* yacc.c:1646  */
    {}
#line 1688 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 243 "src/MJLALRParser.y" /* yacc.c:1646  */
    {(yyval.alExpr) = new LitExpr<int>(getPos(), (yyvsp[0].litInt));}
#line 1694 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 244 "src/MJLALRParser.y" /* yacc.c:1646  */
    {(yyval.alExpr) = new LitExpr<std::string>(getPos(), std::string((yyvsp[0].litString)));}
#line 1700 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 245 "src/MJLALRParser.y" /* yacc.c:1646  */
    {(yyval.alExpr) = (yyvsp[0].var);}
#line 1706 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 246 "src/MJLALRParser.y" /* yacc.c:1646  */
    {(yyval.alExpr) = new FunctionCallExpr(getPos(),
                                                                                          std::shared_ptr<Var>((yyvsp[-3].var)),
                                                                                          std::shared_ptr<ConstructList<Expr>>((yyvsp[-1].constructList)));}
#line 1714 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 249 "src/MJLALRParser.y" /* yacc.c:1646  */
    {}
#line 1720 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 250 "src/MJLALRParser.y" /* yacc.c:1646  */
    {(yyval.var) = new Var(getPos(), std::string((yyvsp[-1].id)), 
                                                                                                        std::shared_ptr<AccessOperation>((yyvsp[0].accessOp)));}
#line 1727 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 252 "src/MJLALRParser.y" /* yacc.c:1646  */
    {(yyval.accessOp) = nullptr;}
#line 1733 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 253 "src/MJLALRParser.y" /* yacc.c:1646  */
    {(yyval.accessOp) = new DotAccess(getPos(), std::string((yyvsp[-1].id)),
                                                                                                        std::shared_ptr<AccessOperation>((yyvsp[0].accessOp)));}
#line 1740 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 255 "src/MJLALRParser.y" /* yacc.c:1646  */
    {(yyval.accessOp) = new BracketAccess(getPos(),
                                                                                          std::shared_ptr<ConstructList<Expr>>((yyvsp[-2].constructList)),
                                                                                          std::shared_ptr<AccessOperation>((yyvsp[0].accessOp)));}
#line 1748 "src/y.tab.c" /* yacc.c:1646  */
    break;


#line 1752 "src/y.tab.c" /* yacc.c:1646  */
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
#line 258 "src/MJLALRParser.y" /* yacc.c:1906  */



Position getPos() {
    return Position{current_line, offset};
}

void yyerror(char *s) { 
    std::string parse_error = "parse error near " + get_token_name(yychar) + ", lexeme " + std::string(yytext);
    MJMessage::print(MJMessage::Type::ERROR, parse_error, Lexer::Position {current_line, offset});
}

int main() {
    return (yyparse());
}

int yywrap() {
    return 1;
}
