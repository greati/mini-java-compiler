/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_SRC_Y_TAB_H_INCLUDED
# define YY_YY_SRC_Y_TAB_H_INCLUDED
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
    TOK_PROGRAM = 258,
    TOK_IDENTIFIER = 259,
    TOK_SEMICOLON = 260,
    TOK_CLASS = 261,
    TOK_LCURLY = 262,
    TOK_RCURLY = 263,
    TOK_DECLARATIONS = 264,
    TOK_ENDDECLARATIONS = 265,
    TOK_EQUALS = 266,
    TOK_COMMA = 267,
    TOK_INT = 268,
    TOK_STRING = 269,
    TOK_LRSQUARE = 270,
    TOK_METHOD = 271,
    TOK_LPAREN = 272,
    TOK_RPAREN = 273,
    TOK_VOID = 274,
    TOK_VAL = 275,
    TOK_ARROBA = 276,
    TOK_LSQUARE = 277,
    TOK_RSQUARE = 278,
    TOK_ASSIGN = 279,
    TOK_RETURN = 280,
    TOK_IF = 281,
    TOK_ELSE = 282,
    TOK_FOR = 283,
    TOK_TO = 284,
    TOK_STEP = 285,
    TOK_WHILE = 286,
    TOK_SWITCH = 287,
    TOK_CASE = 288,
    TOK_DEFAULT = 289,
    TOK_PRINT = 290,
    TOK_READ = 291,
    TOK_LESS = 292,
    TOK_LESSEQ = 293,
    TOK_EQEQ = 294,
    TOK_DIFF = 295,
    TOK_GREATEREQ = 296,
    TOK_GREATER = 297,
    TOK_PLUS = 298,
    TOK_UPLUS = 299,
    TOK_MINUS = 300,
    TOK_UMINUS = 301,
    TOK_NOT = 302,
    TOK_2PIPE = 303,
    TOK_ASTERISK = 304,
    TOK_SLASH = 305,
    TOK_AND = 306,
    TOK_MOD = 307,
    TOK_INTEGERCONSTANT = 308,
    TOK_STRINGCONSTANT = 309,
    TOK_DOT = 310
  };
#endif
/* Tokens.  */
#define TOK_PROGRAM 258
#define TOK_IDENTIFIER 259
#define TOK_SEMICOLON 260
#define TOK_CLASS 261
#define TOK_LCURLY 262
#define TOK_RCURLY 263
#define TOK_DECLARATIONS 264
#define TOK_ENDDECLARATIONS 265
#define TOK_EQUALS 266
#define TOK_COMMA 267
#define TOK_INT 268
#define TOK_STRING 269
#define TOK_LRSQUARE 270
#define TOK_METHOD 271
#define TOK_LPAREN 272
#define TOK_RPAREN 273
#define TOK_VOID 274
#define TOK_VAL 275
#define TOK_ARROBA 276
#define TOK_LSQUARE 277
#define TOK_RSQUARE 278
#define TOK_ASSIGN 279
#define TOK_RETURN 280
#define TOK_IF 281
#define TOK_ELSE 282
#define TOK_FOR 283
#define TOK_TO 284
#define TOK_STEP 285
#define TOK_WHILE 286
#define TOK_SWITCH 287
#define TOK_CASE 288
#define TOK_DEFAULT 289
#define TOK_PRINT 290
#define TOK_READ 291
#define TOK_LESS 292
#define TOK_LESSEQ 293
#define TOK_EQEQ 294
#define TOK_DIFF 295
#define TOK_GREATEREQ 296
#define TOK_GREATER 297
#define TOK_PLUS 298
#define TOK_UPLUS 299
#define TOK_MINUS 300
#define TOK_UMINUS 301
#define TOK_NOT 302
#define TOK_2PIPE 303
#define TOK_ASTERISK 304
#define TOK_SLASH 305
#define TOK_AND 306
#define TOK_MOD 307
#define TOK_INTEGERCONSTANT 308
#define TOK_STRINGCONSTANT 309
#define TOK_DOT 310

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_Y_TAB_H_INCLUDED  */
