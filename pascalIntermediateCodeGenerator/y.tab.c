
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

/**
 * Parser for subset of the pascal language
 * Authors: Rajkishan G
 *           Garimella Jagannadh Kashyap
 *           Kashyap R Puranik
 **/
#include <stdio.h>
#include "map.h"

// TODO: add documentation for these variables, currFuncSign makes no sense

// variable declarations

int lineNo = 1;
void yyerror(char *s);
struct listNode *symTabEntryList[100];
int symTabEntryListIndex = 0;
int isArray,lowerBound,upperBound;
int isFunction;
int functionSignature[MAX_ARGUMENTS];
int exprListType[MAX_ARGUMENTS];
int exprListTypeIndex = 0;
int currFuncSign;
int temp;

// Function declarations
void declareId(int type);
void undeclaredID(token id);
void checkFuncSign(token func);
char* getOperation(int operation);
struct listNode* newTemp();


/* Line 189 of yacc.c  */
#line 108 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 214 of yacc.c  */
#line 35 "parser.y"
 int gen; struct listNode *symTabEntry;struct Attributes *attr;


/* Line 214 of yacc.c  */
#line 286 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 298 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   176

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNRULES -- Number of states.  */
#define YYNSTATES  167

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   324

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    11,    12,    20,    21,    28,    33,    35,
      38,    40,    42,    46,    47,    48,    49,    58,    59,    61,
      70,    72,    74,    76,    80,    81,    86,    87,    92,    93,
      94,   102,   103,   104,   110,   114,   118,   119,   123,   129,
     133,   135,   136,   138,   142,   146,   150,   152,   154,   161,
     166,   168,   173,   178,   183,   185,   190,   195,   197,   201,
     202,   204,   208,   210,   213,   217,   219,   223,   225,   230,
     235,   237,   241,   244,   246,   248,   250,   252,   254,   256,
     258,   260,   262,   264,   266,   268,   270,   272,   274,   276,
     278,   280,   282,   284,   286,   288,   290,   292,   294,   296
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      71,     0,    -1,    49,   107,    33,    76,    55,   111,    74,
      -1,    -1,    49,   107,    33,    76,   111,    72,    74,    -1,
      -1,    49,   107,    76,   111,    73,    74,    -1,    77,    82,
      92,    75,    -1,    13,    -1,     1,   111,    -1,   111,    -1,
     107,    -1,    76,   109,   107,    -1,    -1,    -1,    -1,    77,
      66,    78,    76,    79,   110,    80,   111,    -1,    -1,    81,
      -1,     4,    31,   114,    14,   114,    50,    41,    81,    -1,
     112,    -1,   113,    -1,   107,    -1,    82,    83,   111,    -1,
      -1,    85,   111,    77,    92,    -1,    -1,    85,    84,    77,
      92,    -1,    -1,    -1,    22,    86,   107,    87,    90,   110,
      81,    -1,    -1,    -1,    48,    88,   107,    89,    90,    -1,
      33,    91,    55,    -1,    33,     1,    55,    -1,    -1,    76,
     110,    80,    -1,    91,   111,    76,   110,    80,    -1,    45,
      93,    17,    -1,    94,    -1,    -1,    95,    -1,    94,   111,
      95,    -1,    94,     1,    95,    -1,    96,   106,    99,    -1,
      97,    -1,    92,    -1,    27,    99,    61,    95,    16,    95,
      -1,    67,    99,    12,    95,    -1,   107,    -1,   107,    31,
      99,    50,    -1,   107,    31,   114,    50,    -1,   107,    31,
      99,    55,    -1,   107,    -1,   107,    33,    98,    55,    -1,
     107,    33,    98,   111,    -1,    99,    -1,    98,   109,    99,
      -1,    -1,   100,    -1,   100,   108,   100,    -1,   101,    -1,
     103,   101,    -1,   100,   104,   101,    -1,   102,    -1,   101,
     105,   102,    -1,   107,    -1,   107,    33,    98,    55,    -1,
     107,    33,    98,   111,    -1,   114,    -1,    33,    99,    55,
      -1,    38,   102,    -1,    47,    -1,    35,    -1,    47,    -1,
      35,    -1,    42,    -1,   107,    -1,    59,    -1,    58,    -1,
      11,    -1,    36,    -1,     3,    -1,     5,    -1,    26,    -1,
      18,    -1,    40,    -1,    34,    -1,    25,    -1,    32,    -1,
      23,    -1,    28,    -1,     9,    -1,     8,    -1,    56,    -1,
      29,    -1,    51,    -1,    39,    -1,    52,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   126,   126,   127,   127,   128,   128,   131,   136,   137,
     138,   141,   142,   143,   145,   145,   145,   146,   149,   150,
     153,   154,   155,   158,   159,   162,   163,   163,   167,   167,
     167,   181,   181,   181,   199,   200,   201,   205,   206,   210,
     216,   217,   221,   222,   223,   227,   240,   241,   242,   244,
     248,   254,   269,   285,   297,   308,   323,   337,   338,   339,
     343,   348,   361,   365,   368,   384,   388,   405,   415,   429,
     442,   450,   454,   461,   462,   466,   467,   468,   469,   473,
     474,   475,   476,   477,   480,   483,   487,   488,   489,   490,
     491,   492,   493,   496,   499,   502,   505,   508,   511,   512
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AND", "ARRAY", "ASSIGNMENT", "CASE",
  "CHARACTER_STRING", "COLON", "COMMA", "CONST", "DIV", "DO", "DOT",
  "DOTDOT", "DOWNTO", "ELSE", "END", "EQUAL", "EXTERNAL", "FOR", "FORWARD",
  "FUNCTION", "GE", "GOTO", "GT", "IDENTIFIER", "IF", "IN", "INTEGER",
  "LABEL", "LBRAC", "LE", "LPAREN", "LT", "MINUS", "MOD", "NIL", "NOT",
  "NUMBER", "NOTEQUAL", "OF", "OR", "OTHERWISE", "PACKED", "PBEGIN",
  "PFILE", "PLUS", "PROCEDURE", "PROGRAM", "RBRAC", "REAL", "REALNUMBER",
  "RECORD", "REPEAT", "RPAREN", "SEMICOLON", "SET", "SLASH", "STAR",
  "STARSTAR", "THEN", "TO", "TYPE", "UNTIL", "UPARROW", "VAR", "WHILE",
  "WITH", "BOOL", "$accept", "program", "$@1", "$@2", "rest", "dot",
  "identifier_list", "declarations", "$@3", "$@4", "type", "standard_type",
  "subprogram_declarations", "subprogram_declaration", "$@5",
  "subprogram_head", "$@6", "$@7", "$@8", "$@9", "arguments",
  "parameter_list", "compound_statement", "optional_statements",
  "statement_list", "statement", "variable", "procedure_statement",
  "expression_list", "expression", "simple_expression", "term", "factor",
  "sign", "addop", "mulop", "assignop", "id", "relop", "comma", "colon",
  "semicolon", "integer", "real", "num", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    72,    71,    73,    71,    74,    75,    75,
      75,    76,    76,    76,    78,    79,    77,    77,    80,    80,
      81,    81,    81,    82,    82,    83,    84,    83,    86,    87,
      85,    88,    89,    85,    90,    90,    90,    91,    91,    92,
      93,    93,    94,    94,    94,    95,    95,    95,    95,    95,
      96,    96,    96,    96,    97,    97,    97,    98,    98,    98,
      99,    99,   100,   100,   100,   101,   101,   102,   102,   102,
     102,   102,   102,   103,   103,   104,   104,   104,   104,   105,
     105,   105,   105,   105,   106,   107,   108,   108,   108,   108,
     108,   108,   108,   109,   110,   111,   112,   113,   114,   114
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     0,     7,     0,     6,     4,     1,     2,
       1,     1,     3,     0,     0,     0,     8,     0,     1,     8,
       1,     1,     1,     3,     0,     4,     0,     4,     0,     0,
       7,     0,     0,     5,     3,     3,     0,     3,     5,     3,
       1,     0,     1,     3,     3,     3,     1,     1,     6,     4,
       1,     4,     4,     4,     1,     4,     4,     1,     3,     0,
       1,     3,     1,     2,     3,     1,     3,     1,     4,     4,
       1,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    85,    13,     1,    13,     0,    11,     0,
      93,    95,     0,     5,     0,     3,    12,    17,    17,    17,
       6,    24,     2,     4,    14,     0,    13,    28,    41,    31,
       0,    26,     0,    15,     0,     0,     0,    47,     0,     0,
      42,     0,    46,    54,     0,    23,    17,    17,     0,     8,
       7,    10,     0,    29,     0,    74,     0,    98,    73,    99,
       0,    60,    62,    65,     0,    67,    70,     0,    39,     0,
       0,    84,     0,     0,    59,    32,     0,     0,     9,    94,
       0,    36,     0,    72,     0,    86,    91,    89,    92,    90,
      88,    76,    87,    77,    75,     0,    78,     0,    83,    81,
      82,    80,    79,     0,    63,    59,     0,    44,    43,    45,
       0,    70,     0,    57,    36,    27,    25,     0,    96,    97,
       0,    18,    22,    20,    21,     0,     0,    71,     0,    64,
      61,    66,     0,    49,    51,    53,    52,    55,     0,    56,
      33,     0,    16,     0,     0,     0,     0,     0,    68,    69,
      58,     0,    35,     0,    34,    13,    30,    48,     0,    37,
       0,     0,     0,     0,    38,     0,    19
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    19,    17,    20,    50,     7,    21,    26,    52,
     120,   121,    25,    30,    46,    31,    34,    81,    44,   114,
     126,   145,    37,    38,    39,    40,    41,    42,   112,   113,
      61,    62,    63,    64,    95,   103,    72,    65,    97,    12,
      80,    13,   123,   124,    66
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -94
static const yytype_int16 yypact[] =
{
     -27,    22,    82,   -94,   102,   -94,    22,     1,   -94,     8,
     -94,   -94,    22,   -94,    32,   -94,   -94,   -94,   -94,   -94,
     -94,    43,   -94,   -94,   -94,    77,    22,   -94,     9,   -94,
      32,    32,     5,   104,    22,   101,   101,   -94,   106,     3,
     -94,   132,   -94,    60,    22,   -94,   -94,   -94,    32,   -94,
     -94,   -94,   136,   -94,   101,   -94,    63,   -94,   -94,   -94,
      90,    72,    13,   -94,    63,   114,   -94,   143,   -94,     9,
       9,   -94,   101,   101,   101,   -94,    -4,    -4,   -94,   -94,
      27,   127,   110,   -94,     9,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,    63,   -94,   101,   -94,   -94,
     -94,   -94,   -94,    63,    13,   101,     9,   -94,   -94,   -94,
      -8,   117,    25,   -94,   127,   -94,   -94,   135,   -94,   -94,
      32,   -94,   -94,   -94,   -94,   148,   136,   -94,   152,    13,
      91,   -94,    29,   -94,   -94,   -94,   -94,   -94,   101,   -94,
     -94,    69,   -94,   115,   123,    86,    26,     9,   -94,   -94,
     -94,   155,   -94,    27,   -94,    22,   -94,   -94,    69,   -94,
     123,   121,    27,   131,   -94,    26,   -94
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -94,   -94,   -94,   -94,   140,   -94,    -5,   116,   -94,   -94,
     -59,   -54,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
      59,   -94,   -10,   -94,   -94,   -61,   -94,   -94,    70,   -22,
      79,   -20,   -30,   -94,   -94,   -94,   -94,    -1,   -94,   -93,
     -86,    -2,   -94,   -94,   -71
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -51
static const yytype_int16 yytable[] =
{
       4,     9,   111,     8,    69,     8,    48,    15,   107,   108,
      10,    16,    18,    60,    67,    32,    98,    10,    49,   138,
     -40,    33,     1,   128,    99,     8,    83,    43,    45,    47,
      51,   117,    82,    53,    10,     3,    35,    70,    10,   138,
     146,    28,   134,    75,   104,   133,    78,   135,     3,   100,
     109,   110,     3,     3,    28,   118,   118,    11,   153,    11,
      96,    11,    24,    14,    11,   -50,   115,   116,    43,    43,
     151,   101,   102,   131,   162,   129,    36,   119,   119,   122,
     137,    11,     5,    43,   148,    11,   157,   161,    11,     3,
      85,    73,   156,    74,   159,    86,    54,    87,     3,    27,
      88,    56,    57,   164,    89,    43,    90,    91,    57,    24,
     139,   166,    92,    10,    93,    59,   150,     3,   142,    94,
     144,    59,    28,    68,     8,    29,    91,     3,     3,    96,
     149,    79,    10,    93,    54,     6,    55,    71,    94,    56,
      57,   154,    11,   155,    79,   122,    43,   105,    58,   143,
     160,    84,   122,    59,     8,   106,   -13,   -13,    22,    23,
     125,   122,    76,    77,   122,   127,   141,   136,   147,   158,
     152,   163,   165,   140,     3,   132,   130
};

static const yytype_uint8 yycheck[] =
{
       1,     6,    73,     4,     1,     6,     1,     9,    69,    70,
       9,    12,    14,    35,    36,    25,     3,     9,    13,   112,
      17,    26,    49,    84,    11,    26,    56,    28,    30,    31,
      32,     4,    54,    34,     9,    26,    27,    39,     9,   132,
     126,    45,    50,    44,    64,   106,    48,    55,    26,    36,
      72,    73,    26,    26,    45,    29,    29,    56,   144,    56,
      61,    56,    66,    55,    56,     5,    76,    77,    69,    70,
     141,    58,    59,   103,   160,    95,    67,    51,    51,    80,
      55,    56,     0,    84,    55,    56,   147,   158,    56,    26,
      18,    31,   146,    33,   153,    23,    33,    25,    26,    22,
      28,    38,    39,   162,    32,   106,    34,    35,    39,    66,
     112,   165,    40,     9,    42,    52,   138,    26,   120,    47,
     125,    52,    45,    17,   125,    48,    35,    26,    26,   130,
     132,     8,     9,    42,    33,    33,    35,     5,    47,    38,
      39,    55,    56,   145,     8,   146,   147,    33,    47,     1,
     155,    61,   153,    52,   155,    12,     8,     9,    18,    19,
      33,   162,    46,    47,   165,    55,    31,    50,    16,    14,
      55,    50,    41,   114,    26,   105,    97
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    49,    71,    26,   107,     0,    33,    76,   107,    76,
       9,    56,   109,   111,    55,   111,   107,    73,   111,    72,
      74,    77,    74,    74,    66,    82,    78,    22,    45,    48,
      83,    85,    92,    76,    86,    27,    67,    92,    93,    94,
      95,    96,    97,   107,    88,   111,    84,   111,     1,    13,
      75,   111,    79,   107,    33,    35,    38,    39,    47,    52,
      99,   100,   101,   102,   103,   107,   114,    99,    17,     1,
     111,     5,   106,    31,    33,   107,    77,    77,   111,     8,
     110,    87,    99,   102,    61,    18,    23,    25,    28,    32,
      34,    35,    40,    42,    47,   104,   107,   108,     3,    11,
      36,    58,    59,   105,   101,    33,    12,    95,    95,    99,
      99,   114,    98,    99,    89,    92,    92,     4,    29,    51,
      80,    81,   107,   112,   113,    33,    90,    55,    95,   101,
     100,   102,    98,    95,    50,    55,    50,    55,   109,   111,
      90,    31,   111,     1,    76,    91,   110,    16,    55,   111,
      99,   114,    55,   110,    55,   111,    81,    95,    14,    80,
      76,   114,   110,    50,    80,    41,    81
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:

/* Line 1455 of yacc.c  */
#line 127 "parser.y"
    {yyerror("Error, missing matching paranthesis");}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 128 "parser.y"
    {yyerror("Error, missing matching paranthesis");}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 136 "parser.y"
    {printf("Parsing Complete!\n");}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 137 "parser.y"
    {yyerror("Error: . is missing");}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 138 "parser.y"
    {yyerror("Expected . got ;");}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 141 "parser.y"
    {symTabEntryList[symTabEntryListIndex++] = (yyvsp[(1) - (1)].symTabEntry);}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 142 "parser.y"
    {symTabEntryList[symTabEntryListIndex++] = (yyvsp[(3) - (3)].symTabEntry);}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 143 "parser.y"
    {yyerror("Warning, missing identifiers");}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 145 "parser.y"
    {isDeclaration = 1;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 145 "parser.y"
    {isDeclaration = 0;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 145 "parser.y"
    {declareId((yyvsp[(7) - (8)].gen));}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 149 "parser.y"
    {(yyval.gen) = (yyvsp[(1) - (1)].gen);}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 150 "parser.y"
    {(yyval.gen) = (yyvsp[(8) - (8)].gen); isArray = 1;lowerBound = atoi((yyvsp[(3) - (8)].symTabEntry)->data.key);upperBound = atoi((yyvsp[(5) - (8)].symTabEntry)->data.key);}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 153 "parser.y"
    {(yyval.gen)=INTEGER;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 154 "parser.y"
    {(yyval.gen) = REAL;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 155 "parser.y"
    {yyerror("Error, invalid type");}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 159 "parser.y"
    {currentST = 0;totalST++;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 163 "parser.y"
    {yyerror("Missing semicolon");}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 167 "parser.y"
    {temp = currentST; currentST = 0;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 167 "parser.y"
    {currentST = temp; temp = 0; currentST++;totalST++;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 168 "parser.y"
    {
    (yyvsp[(3) - (7)].symTabEntry)->data.type = (yyvsp[(7) - (7)].gen);
    (yyvsp[(3) - (7)].symTabEntry)->data.isFunc = 1;
    // install function signature
    int i;
    (yyvsp[(3) - (7)].symTabEntry)->data.funcSignature = (int *) malloc(currFuncSign*sizeof(int));
    for(i=0;i<currFuncSign;i++)
    {
		(yyvsp[(3) - (7)].symTabEntry)->data.funcSignature[i]=functionSignature[i];
    }
    (yyvsp[(3) - (7)].symTabEntry)->data.numArgs = currFuncSign;
    currFuncSign=0;
}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 181 "parser.y"
    {temp = currentST; currentST = 0;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 181 "parser.y"
    {currentST = temp; temp = 0; currentST++;totalST++;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 182 "parser.y"
    {
	//TODO need to decide, but it should not be -1
    (yyvsp[(3) - (5)].symTabEntry)->data.type = FUNCTION;	
    (yyvsp[(3) - (5)].symTabEntry)->data.isFunc = 1;
    // install function signature
    int i;
    (yyvsp[(3) - (5)].symTabEntry)->data.funcSignature = (int *) malloc(currFuncSign*sizeof(int));
    for(i=0;i<currFuncSign;i++)
    {
		(yyvsp[(3) - (5)].symTabEntry)->data.funcSignature[i]=functionSignature[i];
    }
    (yyvsp[(3) - (5)].symTabEntry)->data.numArgs = currFuncSign;
    currFuncSign=0;
}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 200 "parser.y"
    {yyerror("Error, malformed/missing arguments");}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 201 "parser.y"
    {(yyval.gen)=-1;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 205 "parser.y"
    {isFunction=1;declareId((yyvsp[(3) - (3)].gen));}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 206 "parser.y"
    {isFunction=1;declareId((yyvsp[(5) - (5)].gen));}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 227 "parser.y"
    {
	if((yyvsp[(1) - (3)].symTabEntry)->data.type != (yyvsp[(3) - (3)].attr)->type)
	{
		yyerror("Type error");
	}
	(yyval.attr) = (struct Attributes *)malloc(sizeof(struct Attributes));
	strcpy((yyval.attr)->code,(yyvsp[(3) - (3)].attr)->code); // s.code = e.code
	char buf[100];
	sprintf(buf,"%s = %s;\n",(yyvsp[(1) - (3)].symTabEntry)->data.key,(yyvsp[(3) - (3)].attr)->place);
	strcat((yyval.attr)->code,buf);
	printf("%s",(yyval.attr)->code);

}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 240 "parser.y"
    {(yyval.attr) = NULL;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 241 "parser.y"
    {(yyval.attr) = NULL;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 242 "parser.y"
    {
	(yyval.attr) = (struct Attributes *)malloc(sizeof(struct Attributes));}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 244 "parser.y"
    {(yyval.attr) = NULL;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 249 "parser.y"
    { 
    if ((yyvsp[(1) - (1)].symTabEntry)->data.type == -1)
	    undeclaredID((yyvsp[(1) - (1)].symTabEntry)->data);
    (yyval.symTabEntry) = (yyvsp[(1) - (1)].symTabEntry);
}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 255 "parser.y"
    { 
    
    /*	TODO: if possible check the bounds
    checkBounds($1->data.lowerBound, $1->data.upperBound,
    	0 get the value of the expression here); */
    if ((yyvsp[(1) - (4)].symTabEntry)->data.type == -1)
    	undeclaredID((yyvsp[(1) - (4)].symTabEntry)->data);
    else if(!(yyvsp[(1) - (4)].symTabEntry)->data.isArray)
    {
	    yyerror("Error trying to index a scalar variable");
    }
    //we copy the ST entry of id to variable
    (yyval.symTabEntry) = (yyvsp[(1) - (4)].symTabEntry);
}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 270 "parser.y"
    {
    if((yyvsp[(3) - (4)].symTabEntry)->data.type != INTEGER)
    {
	    yyerror("Error in array index type");
    }
    else if((yyvsp[(3) - (4)].symTabEntry)->data.type == INTEGER && (yyvsp[(3) - (4)].symTabEntry)->data.isNum)
    {
	    if((yyvsp[(3) - (4)].symTabEntry)->data.constVal>(yyvsp[(1) - (4)].symTabEntry)->data.upperBound||(yyvsp[(3) - (4)].symTabEntry)->data.constVal<(yyvsp[(1) - (4)].symTabEntry)->data.lowerBound)
		    yyerror("Bound error");
    }
   
    //we copy the ST entry of id to variable
    (yyval.symTabEntry) = (yyvsp[(1) - (4)].symTabEntry);
}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 286 "parser.y"
    { 
    if ((yyvsp[(1) - (4)].symTabEntry)->data.type == -1)
    	undeclaredID((yyvsp[(1) - (4)].symTabEntry)->data);
	yyerror("Error, malformed expression");

    //we copy the ST entry of id to variable
    (yyval.symTabEntry) = (yyvsp[(1) - (4)].symTabEntry);
}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 298 "parser.y"
    { 
    //TODO: check the function signature
    checkFuncSign((yyvsp[(1) - (1)].symTabEntry)->data);
    if ((yyvsp[(1) - (1)].symTabEntry)->data.isFunc == -1) 
    	undeclaredID((yyvsp[(1) - (1)].symTabEntry)->data);
	(yyval.attr) = (struct Attributes *)malloc(sizeof(struct Attributes));
	//generate code here
	(yyval.attr) = NULL; //TODO generate code and remove this

}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 309 "parser.y"
    {
    ///exprListTypeIndex = 0;	
    //TODO: check the function signature
    checkFuncSign((yyvsp[(1) - (4)].symTabEntry)->data);
    exprListTypeIndex=0;
    if ((yyvsp[(1) - (4)].symTabEntry)->data.isFunc == -1)
    	undeclaredID((yyvsp[(1) - (4)].symTabEntry)->data);
    checkFuncSign((yyvsp[(1) - (4)].symTabEntry)->data);
	(yyval.attr) = (struct Attributes *)malloc(sizeof(struct Attributes));
	//generate code here
	(yyval.attr) = NULL; //TODO generate code and remove this


}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 324 "parser.y"
    { 
    exprListTypeIndex = 0;	
    if ((yyvsp[(1) - (4)].symTabEntry)->data.isFunc == -1)
    	undeclaredID((yyvsp[(1) - (4)].symTabEntry)->data);
	yyerror("Error, unmatched paranthesis");
	(yyval.attr) = (struct Attributes *)malloc(sizeof(struct Attributes));
	//generate code here
	(yyval.attr) = NULL; //TODO generate code and remove this

}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 337 "parser.y"
    {exprListType[exprListTypeIndex++]=(yyvsp[(1) - (1)].attr)->type;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 338 "parser.y"
    {exprListType[exprListTypeIndex++]=(yyvsp[(3) - (3)].attr)->type;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 339 "parser.y"
    {yyerror("Warning, empty expression");}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 343 "parser.y"
    {
		//$$ = (struct Attributes *)malloc(sizeof(struct Attributes));
		(yyval.attr) = (yyvsp[(1) - (1)].attr);
}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 348 "parser.y"
    {
	(yyval.attr) = (struct Attributes* ) malloc(sizeof(struct Attributes));
	(yyval.attr)->type = BOOL;
    char buf[100];
    ListNodePtr temp = newTemp();
    strcpy((yyval.attr)->place, temp->data.key);
	sprintf(buf,"%s = %s %s %s;\n",temp->data.key,(yyvsp[(1) - (3)].attr)->place,getOperation((yyvsp[(2) - (3)].gen)),(yyvsp[(3) - (3)].attr)->place);
	strcat((yyval.attr)->code,buf);
	//printf("%s",$$->code);
}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 361 "parser.y"
    {
	//$$ = (struct Attributes *)malloc(sizeof(struct Attributes));
	(yyval.attr) = (yyvsp[(1) - (1)].attr);
}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 365 "parser.y"
    {(yyval.attr)=(yyvsp[(2) - (2)].attr);}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 368 "parser.y"
    {
	if((yyvsp[(1) - (3)].attr)->type != (yyvsp[(3) - (3)].attr)->type) yyerror("Type error");
	(yyval.attr) =(struct Attributes *) malloc(sizeof(struct Attributes));
	//generate code here
	(yyval.attr)->type = (yyvsp[(3) - (3)].attr)->type;
	char buf[100];
    ListNodePtr temp = newTemp();
    strcpy((yyval.attr)->place, temp->data.key);
    // Addop will be replaced here
	sprintf(buf,"%s = %s %s %s;\n",temp->data.key,(yyvsp[(1) - (3)].attr)->place,getOperation((yyvsp[(2) - (3)].gen)),(yyvsp[(3) - (3)].attr)->place);
	strcat((yyval.attr)->code,buf);
	//printf("%s",$$->code);	
}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 384 "parser.y"
    {
	//$$ = (struct Attributes *)malloc(sizeof(struct Attributes *));
	(yyval.attr) = (yyvsp[(1) - (1)].attr);
}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 388 "parser.y"
    {
	if((yyvsp[(1) - (3)].attr)->type!=(yyvsp[(3) - (3)].attr)->type)
		yyerror("Type error");
	(yyval.attr) = (struct Attributes *)malloc(sizeof(struct Attributes *));
	//generate code here
	(yyval.attr)->type = (yyvsp[(3) - (3)].attr)->type;
	char buf[100];
    ListNodePtr temp = newTemp();
    strcpy((yyval.attr)->place, temp->data.key);
    // Addop will be replaced here
	sprintf(buf,"%s = %s %s %s;\n",temp->data.key,(yyvsp[(1) - (3)].attr)->place,getOperation((yyvsp[(2) - (3)].gen)),(yyvsp[(3) - (3)].attr)->place);
	strcat((yyval.attr)->code,buf);
	printf("%s",(yyval.attr)->code);	
}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 406 "parser.y"
    { 
    if ((yyvsp[(1) - (1)].symTabEntry)->data.type == -1)
    	undeclaredID((yyvsp[(1) - (1)].symTabEntry)->data);
	
	(yyval.attr) = (struct Attributes *)malloc(sizeof(struct Attributes));
	//generate code here
	strcpy((yyval.attr)->place,(yyvsp[(1) - (1)].symTabEntry)->data.key);
    (yyval.attr)->type = (yyvsp[(1) - (1)].symTabEntry)->data.type;
}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 416 "parser.y"
    {
    //exprListTypeIndex = 0;	
    //TODO: check the function signature
    checkFuncSign((yyvsp[(1) - (4)].symTabEntry)->data);
    exprListTypeIndex = 0;
    if ((yyvsp[(1) - (4)].symTabEntry)->data.type == -1 || (yyvsp[(1) - (4)].symTabEntry)->data.isFunc == -1) 
    	undeclaredID((yyvsp[(1) - (4)].symTabEntry)->data);
	(yyval.attr) = (struct Attributes *)malloc(sizeof(struct Attributes));
	//generate code here
    (yyval.attr)->type = (yyvsp[(1) - (4)].symTabEntry)->data.type;
    
}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 430 "parser.y"
    { 

    exprListTypeIndex = 0;	
    if ((yyvsp[(1) - (4)].symTabEntry)->data.type == -1)
    	undeclaredID((yyvsp[(1) - (4)].symTabEntry)->data);
    yyerror("Unmatched paranthesis");
    //$$=$1->data.type;
	(yyval.attr) = (struct Attributes *)malloc(sizeof(struct Attributes));
	//generate code here
    (yyval.attr)->type = (yyvsp[(1) - (4)].symTabEntry)->data.type;

}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 442 "parser.y"
    {
	
	(yyval.attr) = (struct Attributes *)malloc(sizeof(struct Attributes));
	//generate code here ??????
	strcpy((yyval.attr)->place,(yyvsp[(1) - (1)].symTabEntry)->data.key);
	(yyval.attr)->type = (yyvsp[(1) - (1)].symTabEntry)->data.type;
	
}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 450 "parser.y"
    {
		(yyval.attr) = (struct Attributes *)malloc(sizeof(struct Attributes));
		*(yyval.attr) = *(yyvsp[(2) - (3)].attr);
}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 454 "parser.y"
    {
		(yyval.attr) = (struct Attributes *)malloc(sizeof(struct Attributes));
		*(yyval.attr) = *(yyvsp[(2) - (2)].attr);
}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 466 "parser.y"
    {(yyval.gen) = PLUS;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 467 "parser.y"
    {(yyval.gen) = MINUS;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 468 "parser.y"
    {(yyval.gen) = OR;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 469 "parser.y"
    {yyerror("Missing operator");}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 473 "parser.y"
    {(yyval.gen) = STAR;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 474 "parser.y"
    {(yyval.gen) = SLASH;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 475 "parser.y"
    {(yyval.gen) = DIV;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 476 "parser.y"
    {(yyval.gen) = MOD;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 477 "parser.y"
    {(yyval.gen) = AND;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 483 "parser.y"
    { (yyval.symTabEntry) = (yyvsp[(1) - (1)].symTabEntry); /*bug: $$->data.type=-1;*/}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 487 "parser.y"
    {(yyval.gen)=EQUAL;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 488 "parser.y"
    {(yyval.gen)=NOTEQUAL;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 489 "parser.y"
    {(yyval.gen)=LT;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 490 "parser.y"
    {(yyval.gen)=GT;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 491 "parser.y"
    {(yyval.gen)=LE;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 492 "parser.y"
    {(yyval.gen)=GE;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 493 "parser.y"
    {(yyval.gen)=IN;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 511 "parser.y"
    {(yyval.symTabEntry)=(yyvsp[(1) - (1)].symTabEntry);}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 512 "parser.y"
    {(yyval.symTabEntry)=(yyvsp[(1) - (1)].symTabEntry);}
    break;



/* Line 1455 of yacc.c  */
#line 2376 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 515 "parser.y"

// Declares an identifier
void declareId(int type)
{
	int i;
	for(i = 0;i<symTabEntryListIndex;i++)
	{
		if ( symTabEntryList[i]->data.type != -1  )
		{	// Redeclaration of a variable
			printf("Redeclaration of %s in line No %d, previous declaration at line No %d\n",
				symTabEntryList[i]->data.key,
				lineNo, symTabEntryList[i]->data.lineNo);
			continue;
		}
		symTabEntryList[i]->data.lineNo = lineNo;
		symTabEntryList[i]->data.tableNo = currentST;
		symTabEntryList[i]->data.type = type;
//		printf(" symTabEntry[%d] = %s type=%d ptr=%x ",i,symTabEntryList[i]->data.key,symTabEntryList[i]->data.type,symTabEntryList[i]);
		if(isArray)
		{
			symTabEntryList[i]->data.lowerBound = lowerBound;
			symTabEntryList[i]->data.upperBound = upperBound;
			symTabEntryList[i]->data.isArray = 1;
		}
		else
		{
			symTabEntryList[i]->data.lowerBound = -1;
			symTabEntryList[i]->data.upperBound = -1;
			symTabEntryList[i]->data.isArray = 0;
		}
		if (isFunction)
		{
		    /* install the function signature in the local array */
		    functionSignature[currFuncSign++] = type;
		    if(currFuncSign == MAX_ARGUMENTS)
			printf("Maximum arguments for any function is %d\n", MAX_ARGUMENTS);
		}

	}
	isArray = 0;
	isFunction=0;
	lowerBound = upperBound = -1;
	symTabEntryListIndex = 0;
}

// Prints an Undeclared Identifier error
void undeclaredID(token id)
{
	if(lookup(id.key,0,0)==NULL)
		printf("Line no %d: Undefined variable %s\n",lineNo, id.key); 
}

// Converts type to an enumeration
int getTypeNo(int type)
{
	switch (type)
	{
		case INTEGER: return 0;
		case REAL: return 1;
		case BOOL: return 2;
	}
}

// Check function Signature
void checkFuncSign(token func)
{
	int i;
	char dataTypes[][5] = {"int", "real", "bool"};
	if(func.isFunc && func.type != -1){
	if(func.numArgs!=exprListTypeIndex)
		printf("Line no %d:%d arguments required, %d got.\n", lineNo ,func.numArgs,exprListTypeIndex); }
	if(func.numArgs>0)
	{
		for ( i = 0 ; i < func.numArgs ; i ++ )
		{
			int type1 = getTypeNo(func.funcSignature[i]),type2 = getTypeNo(exprListType[i]);
			if ( func.funcSignature[i] != exprListType[i])
				printf("line no %d: paramenter %d: expected %s but got %d",
					lineNo,i+1, dataTypes[type1], type2);
		}
		putchar('\n');
	}
}

// The main function
int main()
{
	yyparse();
	return 0;
}

/*
 * Returns the ST entry pointer for new local variable 
 * generated by the compiler
 */
struct listNode* newTemp()
{
	static int ctr = 0;
	char *varName = (char *)malloc(SIZE_OF_TEMP);
	//this creates a new variable __ti and increments i
	sprintf(varName,"__t%d",ctr++);
	ListNodePtr lookupToken = lookup(varName,currentST,0);
	if(lookupToken != NULL)
	{
		printf("ERROR, TERMINATING!!!\n");
		exit(0);
	}
	token entry;
	initToken(&entry);
	strcpy(entry.key,varName);
	ListNodePtr entryPtr=insertIntoMap(varName,entry,currentST);
	return entryPtr;
}

char* getOperation(int operation)
{
	switch (operation)
	{
		case EQUAL: return"==";
		case NOTEQUAL: return"!=";
		case LT: return"<";
		case GT: return">";
		case LE: return"<=";
		case GE: return">=";
		case IN: return"??";
		
		case PLUS:return"+";
		case MINUS:return"-";
		case OR:return"|";
		
		case STAR:return"*";
		case DIV:return"/";
		case SLASH:return"\\";
		case MOD:return"%";
		case AND:return"&";
		default: printf("%d",operation);return ("relop");
	}
}


