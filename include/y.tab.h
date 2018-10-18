/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#line 23 "src/MJLALRParser.y" /* yacc.c:1909  */

    Node *node;
    Var *var;
    AccessOperation *accessOp;
    ConstructList<Expr>* constructList;
    ConstructList<Case>* caseList;
    ConstructList<Stmt>* stmtList;
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

#line 191 "include/y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INCLUDE_Y_TAB_H_INCLUDED  */
