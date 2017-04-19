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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    ID = 258,
    NUM = 259,
    RE = 260,
    WR = 261,
    IF = 262,
    ELSE = 263,
    ENDIF = 264,
    WHILE = 265,
    THEN = 266,
    DO = 267,
    ENDWHILE = 268,
    ISEQ = 269,
    BN = 270,
    END = 271,
    INT = 272,
    BOOL = 273,
    DECL = 274,
    ENDDECL = 275,
    GEQ = 276,
    NEQ = 277,
    LEQ = 278,
    T = 279,
    F = 280,
    AND = 281,
    OR = 282,
    LE = 283,
    GE = 284,
    RET = 285,
    MAIN = 286
  };
#endif
/* Tokens.  */
#define ID 258
#define NUM 259
#define RE 260
#define WR 261
#define IF 262
#define ELSE 263
#define ENDIF 264
#define WHILE 265
#define THEN 266
#define DO 267
#define ENDWHILE 268
#define ISEQ 269
#define BN 270
#define END 271
#define INT 272
#define BOOL 273
#define DECL 274
#define ENDDECL 275
#define GEQ 276
#define NEQ 277
#define LEQ 278
#define T 279
#define F 280
#define AND 281
#define OR 282
#define LE 283
#define GE 284
#define RET 285
#define MAIN 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
