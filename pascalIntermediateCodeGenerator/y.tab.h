
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     AND = 258,
     ARRAY = 259,
     ASSIGNMENT = 260,
     CASE = 261,
     CHARACTER_STRING = 262,
     COLON = 263,
     COMMA = 264,
     CONST = 265,
     DIV = 266,
     DO = 267,
     DOT = 268,
     DOTDOT = 269,
     DOWNTO = 270,
     ELSE = 271,
     END = 272,
     EQUAL = 273,
     EXTERNAL = 274,
     FOR = 275,
     FORWARD = 276,
     FUNCTION = 277,
     GE = 278,
     GOTO = 279,
     GT = 280,
     IDENTIFIER = 281,
     IF = 282,
     IN = 283,
     INTEGER = 284,
     LABEL = 285,
     LBRAC = 286,
     LE = 287,
     LPAREN = 288,
     LT = 289,
     MINUS = 290,
     MOD = 291,
     NIL = 292,
     NOT = 293,
     NUMBER = 294,
     NOTEQUAL = 295,
     OF = 296,
     OR = 297,
     OTHERWISE = 298,
     PACKED = 299,
     PBEGIN = 300,
     PFILE = 301,
     PLUS = 302,
     PROCEDURE = 303,
     PROGRAM = 304,
     RBRAC = 305,
     REAL = 306,
     REALNUMBER = 307,
     RECORD = 308,
     REPEAT = 309,
     RPAREN = 310,
     SEMICOLON = 311,
     SET = 312,
     SLASH = 313,
     STAR = 314,
     STARSTAR = 315,
     THEN = 316,
     TO = 317,
     TYPE = 318,
     UNTIL = 319,
     UPARROW = 320,
     VAR = 321,
     WHILE = 322,
     WITH = 323,
     BOOL = 324
   };
#endif
/* Tokens.  */
#define AND 258
#define ARRAY 259
#define ASSIGNMENT 260
#define CASE 261
#define CHARACTER_STRING 262
#define COLON 263
#define COMMA 264
#define CONST 265
#define DIV 266
#define DO 267
#define DOT 268
#define DOTDOT 269
#define DOWNTO 270
#define ELSE 271
#define END 272
#define EQUAL 273
#define EXTERNAL 274
#define FOR 275
#define FORWARD 276
#define FUNCTION 277
#define GE 278
#define GOTO 279
#define GT 280
#define IDENTIFIER 281
#define IF 282
#define IN 283
#define INTEGER 284
#define LABEL 285
#define LBRAC 286
#define LE 287
#define LPAREN 288
#define LT 289
#define MINUS 290
#define MOD 291
#define NIL 292
#define NOT 293
#define NUMBER 294
#define NOTEQUAL 295
#define OF 296
#define OR 297
#define OTHERWISE 298
#define PACKED 299
#define PBEGIN 300
#define PFILE 301
#define PLUS 302
#define PROCEDURE 303
#define PROGRAM 304
#define RBRAC 305
#define REAL 306
#define REALNUMBER 307
#define RECORD 308
#define REPEAT 309
#define RPAREN 310
#define SEMICOLON 311
#define SET 312
#define SLASH 313
#define STAR 314
#define STARSTAR 315
#define THEN 316
#define TO 317
#define TYPE 318
#define UNTIL 319
#define UPARROW 320
#define VAR 321
#define WHILE 322
#define WITH 323
#define BOOL 324




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 34 "parser.y"
 int gen; struct listNode *symTabEntry;struct Attributes *attr;


/* Line 1676 of yacc.c  */
#line 194 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


