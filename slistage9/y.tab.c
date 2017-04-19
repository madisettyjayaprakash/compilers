/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "sli9n.y" /* yacc.c:339  */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ArgStruct*A1,*A2;
struct Gsymbol *temp;
struct Lsymbol *L2,*L1,*L3;
struct Tnode*T1,*T2;
FILE *yyin;
int i=-1,b,sptr=4096,xyz=0,fst=0;
char *lt,id1[30],nm[100];
#include "symtbl.h"
#include "sliexptree.h"
#include "sliexptree.c"
#include "symtbl.c"
#include"codegen9.c"
#define YYSTYPE Tnode*

#line 85 "y.tab.c" /* yacc.c:339  */

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
    MAIN = 286,
    TYPE = 287,
    ENDTYPE = 288,
    ALLOC = 289,
    VOID = 290,
    INITIALIZE = 291,
    FREE = 292,
    NUL = 293
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
#define TYPE 287
#define ENDTYPE 288
#define ALLOC 289
#define VOID 290
#define INITIALIZE 291
#define FREE 292
#define NUL 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 212 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  24
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   588

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  256

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      52,    53,    41,    39,    49,    40,    54,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    48,
      44,    43,    45,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
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
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    30,    30,    31,    32,    33,    34,    35,    36,    37,
      40,    43,    44,    46,    49,    54,    61,    62,    65,    69,
      70,    71,    72,    80,    98,   100,   101,   103,   105,   106,
     108,   112,   115,   122,   123,   125,   130,   131,   132,   133,
     139,   140,   142,   157,   166,   181,   182,   184,   191,   192,
     194,   195,   197,   199,   203,   209,   218,   225,   226,   227,
     228,   235,   237,   240,   281,   297,   332,   346,   348,   354,
     360,   365,   400,   467,   516,   554,   607,   660,   700,   755,
     764,   773,   782,   792,   801,   811,   820,   829,   838,   846,
     854,   862,   870,   878,   879,   889,   913,   914,   949,   976,
     977,   978,   981,  1038,  1039,  1041,  1046,  1047
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUM", "RE", "WR", "IF", "ELSE",
  "ENDIF", "WHILE", "THEN", "DO", "ENDWHILE", "ISEQ", "BN", "END", "INT",
  "BOOL", "DECL", "ENDDECL", "GEQ", "NEQ", "LEQ", "T", "F", "AND", "OR",
  "LE", "GE", "RET", "MAIN", "TYPE", "ENDTYPE", "ALLOC", "VOID",
  "INITIALIZE", "FREE", "NUL", "'+'", "'-'", "'*'", "'/'", "'='", "'<'",
  "'>'", "'{'", "'}'", "';'", "','", "'['", "']'", "'('", "')'", "'.'",
  "$accept", "Program", "TypeDefBlock", "TypeDefList", "TypeDef",
  "Typedefh", "Typedefb", "FieldDeclList", "FieldDecl", "Type1",
  "GdeclBlock", "Gdecllist", "Gdecl", "Gidlist", "Gid", "Paramlist",
  "Plist", "Type2", "FdefBlock", "Fdef", "Arglist", "Arg", "LdeclBlock",
  "Ldecllist", "Ldecl", "Lidlist", "MainBlock", "Type", "slist", "stmt",
  "E", "Args", "Field", "Field1", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,    43,
      45,    42,    47,    61,    60,    62,   123,   125,    59,    44,
      91,    93,    40,    41,    46
};
# endif

#define YYPACT_NINF -116

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-116)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     460,  -116,   -28,  -116,   131,     3,  -116,    12,   304,   472,
     472,  -116,  -116,    27,   -20,  -116,  -116,   463,  -116,    47,
    -116,     4,  -116,   -11,  -116,   472,   472,  -116,   472,  -116,
    -116,  -116,    39,    31,  -116,  -116,   -23,    -7,  -116,  -116,
    -116,   484,  -116,   472,  -116,  -116,  -116,    16,    51,   101,
     491,  -116,    47,  -116,  -116,  -116,  -116,   121,  -116,   128,
    -116,    94,    28,  -116,   142,   136,   113,  -116,  -116,  -116,
    -116,   124,  -116,   159,  -116,  -116,  -116,   119,   136,   503,
     134,  -116,   468,   166,  -116,   491,  -116,  -116,  -116,   174,
    -116,   136,  -116,   479,  -116,   171,   437,  -116,    33,   179,
    -116,  -116,  -116,    59,    32,   146,   148,   149,   150,   163,
     167,   165,    33,   154,   161,   186,   454,  -116,   215,    49,
     111,   218,   219,   111,   111,   111,  -116,   220,   111,  -116,
      68,   228,   111,   189,   207,  -116,   -29,  -116,  -116,  -116,
     187,   188,   194,   111,   290,  -116,   227,  -116,    72,   190,
     143,   164,   185,    65,   191,   314,   200,   209,   338,  -116,
     362,  -116,   111,   111,    42,   205,   208,  -116,   206,    85,
     108,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,  -116,   217,   111,   216,   225,   231,   252,   253,   232,
     233,   266,   241,  -116,  -116,   268,   386,   248,  -116,   501,
     126,   237,  -116,  -116,  -116,   533,  -116,   533,   533,   533,
     533,   533,   522,   522,   543,   543,   533,   533,   111,   269,
    -116,  -116,  -116,    33,    33,  -116,  -116,   239,   254,   256,
     284,  -116,   111,  -116,  -116,   410,   262,   145,   288,  -116,
    -116,  -116,   258,   501,  -116,   276,    33,   277,   278,  -116,
    -116,   297,  -116,  -116,   279,  -116
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    60,    57,    58,     0,     0,    59,     0,     0,     0,
       0,    41,     6,     0,     0,    57,    24,     0,    26,     0,
      14,     0,    12,     0,     1,     0,     0,     9,     0,     5,
      40,     8,     0,     0,    23,    25,    30,     0,    29,    10,
      11,     0,    13,     0,     7,     3,     4,     0,     0,     0,
       0,    27,     0,    22,    19,    20,    21,     0,    17,     0,
       2,     0,     0,    46,     0,     0,     0,    39,    36,    37,
      38,     0,    34,     0,    28,    15,    16,     0,     0,     0,
       0,    47,     0,     0,    31,     0,    32,    35,    18,     0,
      45,     0,    49,     0,    51,     0,     0,    33,     0,     0,
      48,    50,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    62,     0,   105,     0,     0,    52,     0,     0,
       0,     0,     0,     0,     0,     0,    56,     0,     0,    61,
       0,     0,     0,     0,     0,    53,    97,    96,    99,   100,
       0,     0,     0,     0,     0,   102,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   106,
       0,    43,     0,     0,     0,     0,     0,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    63,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,    72,     0,     0,     0,    94,   104,
       0,     0,   101,    93,    85,    86,    87,    88,    89,    90,
      91,    92,    79,    81,    80,    82,    83,    84,     0,     0,
      65,    76,    67,     0,     0,    74,    75,     0,     0,     0,
       0,    98,     0,    95,    71,     0,     0,     0,     0,    55,
      73,    44,     0,   103,    64,     0,     0,     0,     0,    42,
      66,     0,    70,    69,     0,    68
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -116,  -116,  -116,  -116,   312,  -116,  -116,  -116,   280,  -116,
     336,  -116,   328,  -116,   294,  -116,   263,  -116,    91,    70,
    -116,   270,   -67,  -116,   257,  -116,   133,    -3,   -94,  -116,
    -115,  -116,   -96,  -116
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,    21,    22,    23,    42,    57,    58,    59,
       9,    17,    18,    37,    38,    71,    72,    73,    10,    11,
      62,    63,    83,    93,    94,   103,    12,    13,   111,   112,
     144,   200,   145,   114
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     113,    19,   113,    14,   115,   146,    20,    20,   150,   151,
     152,    89,    24,   155,    19,   158,   113,   160,   129,     1,
     113,   163,   134,   164,    99,   121,   149,    49,   168,    50,
      32,   154,    33,    15,     3,    41,   104,    39,   105,   106,
     107,    51,    52,   108,    64,   136,   137,   196,   197,   199,
      36,     6,   136,   137,   205,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   138,   139,   219,    61,
     110,   136,   137,   138,   139,   119,    64,    79,   141,    95,
      30,    80,   120,   140,    48,   141,   121,   142,   136,   137,
      95,    47,   138,   139,   143,   198,    30,    65,    30,    26,
      28,   143,   156,   235,   141,    66,   157,   117,   118,   138,
     139,   136,   137,    30,   136,   137,    43,   243,   189,   121,
     143,   141,   183,   204,    53,   184,   121,   113,   113,   237,
     238,    77,   138,   139,     1,   138,   139,   143,    54,    55,
      78,    27,    29,    31,   141,    81,   206,   141,    15,     3,
     113,    16,   251,   246,   247,    82,    56,   169,    44,    45,
     143,    46,    87,   143,    84,   170,     6,    88,    75,   171,
     172,   173,   174,    85,   102,   232,    60,    86,   169,   233,
      91,    96,   175,   176,   177,   178,   170,   179,   180,    98,
     171,   172,   173,   174,   116,   128,   186,   130,   122,   169,
     123,   124,   125,   175,   176,   177,   178,   170,   179,   180,
     126,   171,   172,   173,   174,   131,   132,   187,   135,   127,
     169,   147,   148,   153,   175,   176,   177,   178,   170,   179,
     180,   159,   171,   172,   173,   174,   161,   162,   188,   165,
     166,   169,   167,   185,   190,   175,   176,   177,   178,   170,
     179,   180,   192,   171,   172,   173,   174,   193,   201,   203,
     218,   202,   169,   223,   220,   224,   175,   176,   177,   178,
     170,   179,   180,   221,   171,   172,   173,   174,   182,   222,
     225,   226,   227,   169,   229,   234,   239,   175,   176,   177,
     178,   170,   179,   180,   228,   171,   172,   173,   174,   231,
     242,   248,   240,   241,   169,   249,   254,     1,   175,   176,
     177,   178,   170,   179,   180,   245,   171,   172,   173,   174,
     236,     2,     3,     4,   250,   252,   253,   255,   169,   175,
     176,   177,   178,    40,   179,   180,   170,    76,   181,     6,
     171,   172,   173,   174,    25,    35,    74,     0,    97,    90,
     101,     0,   169,   175,   176,   177,   178,     0,   179,   180,
     170,     0,   191,     0,   171,   172,   173,   174,     0,     0,
       0,     0,     0,     0,     0,     0,   169,   175,   176,   177,
     178,     0,   179,   180,   170,     0,   194,     0,   171,   172,
     173,   174,     0,     0,     0,     0,     0,     0,     0,     0,
     169,   175,   176,   177,   178,     0,   179,   180,   170,     0,
     195,     0,   171,   172,   173,   174,     0,     0,     0,     0,
       0,     0,     0,     0,   169,   175,   176,   177,   178,     0,
     179,   180,   170,     0,   230,     0,   171,   172,   173,   174,
     104,     0,   105,   106,   107,     0,     0,   108,     0,   175,
     176,   177,   178,   109,   179,   180,     0,   104,   244,   105,
     106,   107,     0,     1,   108,     0,     1,     0,     0,     0,
     133,     1,     0,     0,   110,     1,     0,     2,     3,     4,
      15,     3,     1,    34,     0,    15,     3,    53,    92,     2,
       3,   110,     5,     0,    67,     6,    15,     3,     6,   100,
       0,    54,    55,     6,     0,     0,     1,     6,    68,    69,
       0,     0,     0,     0,     6,   169,     0,     0,     0,    56,
      15,     3,     0,   170,     0,     0,    70,   171,   172,   173,
     174,     0,     0,     0,     0,     0,   169,     0,     6,     0,
     175,   176,   177,   178,   170,   179,   180,    -1,   171,   172,
     173,   174,     0,     0,     0,    -1,     0,   169,     0,    -1,
      -1,    -1,    -1,   177,   178,   170,   179,   180,     0,   171,
     172,   173,   174,     0,     0,     0,     0,    -1,    -1,     0,
       0,     0,     0,     0,     0,     0,     0,   179,   180
};

static const yytype_int16 yycheck[] =
{
      96,     4,    98,    31,    98,   120,     3,     3,   123,   124,
     125,    78,     0,   128,    17,   130,   112,   132,   112,     3,
     116,    50,   116,    52,    91,    54,   122,    50,   143,    52,
       3,   127,    52,    17,    18,    46,     3,    33,     5,     6,
       7,    48,    49,    10,    47,     3,     4,   162,   163,   164,
       3,    35,     3,     4,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,    24,    25,   183,    53,
      37,     3,     4,    24,    25,    43,    79,    49,    36,    82,
      10,    53,    50,    34,    53,    36,    54,    38,     3,     4,
      93,    52,    24,    25,    52,    53,    26,    46,    28,     8,
       9,    52,    34,   218,    36,     4,    38,    48,    49,    24,
      25,     3,     4,    43,     3,     4,    25,   232,    53,    54,
      52,    36,    50,    38,     3,    53,    54,   223,   224,   223,
     224,     3,    24,    25,     3,    24,    25,    52,    17,    18,
      46,     8,     9,    10,    36,     3,    38,    36,    17,    18,
     246,    20,   246,     8,     9,    19,    35,    14,    25,    26,
      52,    28,     3,    52,    51,    22,    35,    48,    47,    26,
      27,    28,    29,    49,     3,    49,    43,    53,    14,    53,
      46,    15,    39,    40,    41,    42,    22,    44,    45,    15,
      26,    27,    28,    29,    15,    30,    53,    43,    52,    14,
      52,    52,    52,    39,    40,    41,    42,    22,    44,    45,
      47,    26,    27,    28,    29,    54,    30,    53,     3,    52,
      14,     3,     3,     3,    39,    40,    41,    42,    22,    44,
      45,     3,    26,    27,    28,    29,    47,    30,    53,    52,
      52,    14,    48,    53,    53,    39,    40,    41,    42,    22,
      44,    45,    52,    26,    27,    28,    29,    48,    53,    53,
      43,    53,    14,    11,    48,    12,    39,    40,    41,    42,
      22,    44,    45,    48,    26,    27,    28,    29,    51,    48,
      48,    48,    16,    14,    16,    48,    47,    39,    40,    41,
      42,    22,    44,    45,    53,    26,    27,    28,    29,    51,
      16,    13,    48,    47,    14,    47,     9,     3,    39,    40,
      41,    42,    22,    44,    45,    53,    26,    27,    28,    29,
      51,    17,    18,    19,    48,    48,    48,    48,    14,    39,
      40,    41,    42,    21,    44,    45,    22,    57,    48,    35,
      26,    27,    28,    29,     8,    17,    52,    -1,    85,    79,
      93,    -1,    14,    39,    40,    41,    42,    -1,    44,    45,
      22,    -1,    48,    -1,    26,    27,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    14,    39,    40,    41,
      42,    -1,    44,    45,    22,    -1,    48,    -1,    26,    27,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      14,    39,    40,    41,    42,    -1,    44,    45,    22,    -1,
      48,    -1,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    14,    39,    40,    41,    42,    -1,
      44,    45,    22,    -1,    48,    -1,    26,    27,    28,    29,
       3,    -1,     5,     6,     7,    -1,    -1,    10,    -1,    39,
      40,    41,    42,    16,    44,    45,    -1,     3,    48,     5,
       6,     7,    -1,     3,    10,    -1,     3,    -1,    -1,    -1,
      16,     3,    -1,    -1,    37,     3,    -1,    17,    18,    19,
      17,    18,     3,    20,    -1,    17,    18,     3,    20,    17,
      18,    37,    32,    -1,     3,    35,    17,    18,    35,    20,
      -1,    17,    18,    35,    -1,    -1,     3,    35,    17,    18,
      -1,    -1,    -1,    -1,    35,    14,    -1,    -1,    -1,    35,
      17,    18,    -1,    22,    -1,    -1,    35,    26,    27,    28,
      29,    -1,    -1,    -1,    -1,    -1,    14,    -1,    35,    -1,
      39,    40,    41,    42,    22,    44,    45,    14,    26,    27,
      28,    29,    -1,    -1,    -1,    22,    -1,    14,    -1,    26,
      27,    28,    29,    41,    42,    22,    44,    45,    -1,    26,
      27,    28,    29,    -1,    -1,    -1,    -1,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    17,    18,    19,    32,    35,    56,    57,    65,
      73,    74,    81,    82,    31,    17,    20,    66,    67,    82,
       3,    58,    59,    60,     0,    65,    73,    81,    73,    81,
      74,    81,     3,    52,    20,    67,     3,    68,    69,    33,
      59,    46,    61,    73,    81,    81,    81,    52,    53,    50,
      52,    48,    49,     3,    17,    18,    35,    62,    63,    64,
      81,    53,    75,    76,    82,    46,     4,     3,    17,    18,
      35,    70,    71,    72,    69,    47,    63,     3,    46,    49,
      53,     3,    19,    77,    51,    49,    53,     3,    48,    77,
      76,    46,    20,    78,    79,    82,    15,    71,    15,    77,
      20,    79,     3,    80,     3,     5,     6,     7,    10,    16,
      37,    83,    84,    87,    88,    83,    15,    48,    49,    43,
      50,    54,    52,    52,    52,    52,    47,    52,    30,    83,
      43,    54,    30,    16,    83,     3,     3,     4,    24,    25,
      34,    36,    38,    52,    85,    87,    85,     3,     3,    87,
      85,    85,    85,     3,    87,    85,    34,    38,    85,     3,
      85,    47,    30,    50,    52,    52,    52,    48,    85,    14,
      22,    26,    27,    28,    29,    39,    40,    41,    42,    44,
      45,    48,    51,    50,    53,    53,    53,    53,    53,    53,
      53,    48,    52,    48,    48,    48,    85,    85,    53,    85,
      86,    53,    53,    53,    38,    85,    38,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    43,    85,
      48,    48,    48,    11,    12,    48,    48,    16,    53,    16,
      48,    51,    49,    53,    48,    85,    51,    83,    83,    47,
      48,    47,    16,    85,    48,    53,     8,     9,    13,    47,
      48,    83,    48,    48,     9,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    56,    56,    56,    56,    56,    56,    56,
      57,    58,    58,    59,    60,    61,    62,    62,    63,    64,
      64,    64,    64,    65,    65,    66,    66,    67,    68,    68,
      69,    69,    69,    70,    70,    71,    72,    72,    72,    72,
      73,    73,    74,    74,    74,    75,    75,    76,    77,    77,
      78,    78,    79,    80,    80,    81,    81,    82,    82,    82,
      82,    83,    83,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    86,    86,    87,    88,    88
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     3,     2,     1,     3,     2,     2,
       3,     2,     1,     2,     1,     3,     2,     1,     3,     1,
       1,     1,     1,     3,     2,     2,     1,     3,     3,     1,
       1,     4,     4,     3,     1,     2,     1,     1,     1,     1,
       2,     1,    14,    10,    13,     3,     1,     2,     3,     2,
       2,     1,     3,     3,     1,    13,     9,     1,     1,     1,
       1,     2,     1,     4,     7,     5,     8,     5,    10,     8,
       8,     6,     4,     6,     5,     5,     5,     4,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     1,     1,     4,     1,
       1,     3,     1,     3,     1,     1,     3,     3
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
        case 2:
#line 30 "sli9n.y" /* yacc.c:1646  */
    {}
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 31 "sli9n.y" /* yacc.c:1646  */
    {}
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 32 "sli9n.y" /* yacc.c:1646  */
    {}
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 33 "sli9n.y" /* yacc.c:1646  */
    {}
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 34 "sli9n.y" /* yacc.c:1646  */
    {}
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 35 "sli9n.y" /* yacc.c:1646  */
    {}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 37 "sli9n.y" /* yacc.c:1646  */
    {}
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 40 "sli9n.y" /* yacc.c:1646  */
    {  printf("typedef Completed\n");
                                                       }
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 46 "sli9n.y" /* yacc.c:1646  */
    {}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 49 "sli9n.y" /* yacc.c:1646  */
    { strcpy(id1,(yyvsp[0])->name);
                                                TT4=TLookup(id1);
                                                if(TT4==NULL){
                                                  TInstall((yyvsp[0])->name,0,NULL);}}
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 54 "sli9n.y" /* yacc.c:1646  */
    { TT3=TLookup(id1); 
                                              TT3->fields=FHead;
                                              TT3->size=cf;
                                              cf=0;
                                              FHead=NULL;
                                            }
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 61 "sli9n.y" /* yacc.c:1646  */
    {}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 65 "sli9n.y" /* yacc.c:1646  */
    { FInstall(TT2,(yyvsp[-1])->name);
                                            }
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 69 "sli9n.y" /* yacc.c:1646  */
    {TT2=TLookup("int");}
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 70 "sli9n.y" /* yacc.c:1646  */
    {TT2=TLookup("bool");}
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 71 "sli9n.y" /* yacc.c:1646  */
    {TT2=TLookup("void");}
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 72 "sli9n.y" /* yacc.c:1646  */
    {TT2=TLookup((yyvsp[0])->name);
                  if(TT2==NULL){
                    TInstall((yyvsp[0])->name,0,NULL);
                    TT2=TLookup((yyvsp[0])->name);
                   }
                }
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 80 "sli9n.y" /* yacc.c:1646  */
    {   /*    temp=Ghead;
                                                  
                                               while(temp!=NULL){
	                                              printf("%s ",temp->name);
	                                              printf("%d ",temp->argcount);
	                                              printf("%s ",temp->type->name);
	                                              if(temp->list!=NULL){
	                                                  A1=temp->list;
	                                              while(A1!=NULL){
	                                                  printf("%s ",A1->name);
	                                                  printf("%s ",A1->type->name);
	                                                  A1=A1->next;
	                                               }}
                                               printf("\n");
                                               temp=temp->next;
                                             }*/
                                              inter_codegen();
                                           }
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 103 "sli9n.y" /* yacc.c:1646  */
    { }
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 108 "sli9n.y" /* yacc.c:1646  */
    {
		                      type1=TT2;
		                      temp=Gcreateentry((yyvsp[0])->name,type1,1,NULL); 
		                     }
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 112 "sli9n.y" /* yacc.c:1646  */
    {
                               type1=TT2;
                               temp=Gcreateentry((yyvsp[-3])->name, type1,(yyvsp[-1])->value,NULL);}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 115 "sli9n.y" /* yacc.c:1646  */
    {   
                               type1=TT2;
                               temp=Gcreateentry((yyvsp[-3])->name, type1,-1,Ahead);
                               argc=0;
                               Ahead=NULL;
                               }
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 122 "sli9n.y" /* yacc.c:1646  */
    {}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 123 "sli9n.y" /* yacc.c:1646  */
    {}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 125 "sli9n.y" /* yacc.c:1646  */
    { type1=TT3;
                               Ahead=Aentry((yyvsp[0])->name,type1);
                               }
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 130 "sli9n.y" /* yacc.c:1646  */
    {TT3=TLookup("int");}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 131 "sli9n.y" /* yacc.c:1646  */
    {TT3=TLookup("bool");}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 132 "sli9n.y" /* yacc.c:1646  */
    {TT3=TLookup("void");}
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 133 "sli9n.y" /* yacc.c:1646  */
    {TT3=TLookup((yyvsp[0])->name);
                  if(TT3==NULL){
                   yyerror("No type\n");
                   }}
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 142 "sli9n.y" /* yacc.c:1646  */
    {
                                                                temp=Glookup((yyvsp[-12])->name);
                                                                if(temp->type!=(yyvsp[-3])->type){
                                                                   yyerror("function2 return type error\n");
                                                                   exit(1);
                                                                }  
                                                               semfuncheck((yyvsp[-12])->name,Ahead);
                                                         (yyval)=makenode(TLookup("void"),45,(yyvsp[-12])->name,0,(yyvsp[-5]),(yyvsp[-3]),NULL);
                                                               A1=Ahead;
                                                               codegen((yyval));
                                                               Ahead=NULL;
                                                               Lhead=NULL; 
                                                              // printf("%s\n",$2->name);
                                                               }
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 157 "sli9n.y" /* yacc.c:1646  */
    {
                                                              semfuncheck((yyvsp[-8])->name,Ahead);
                                                        (yyval)=makenode(TLookup("void"),46,(yyvsp[-8])->name,0,NULL,NULL,NULL);
                                                              A1=Ahead;
                                                              codegen((yyval));
                                                              Ahead=NULL;
                                                              Lhead=NULL;}
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 166 "sli9n.y" /* yacc.c:1646  */
    { 
                                                                temp=Glookup((yyvsp[-11])->name);
                                                                if(temp->type!=(yyvsp[-3])->type){
                                                                   yyerror("function1 return type error\n");
                                                                   exit(1);
                                                                }  
                                                               semfuncheck((yyvsp[-11])->name,Ahead);
                                                           (yyval)=makenode(TLookup("void"),51,(yyvsp[-11])->name,0,(yyvsp[-5]),(yyvsp[-3]),NULL);
                                                               A1=Ahead;
                                                               codegen((yyval));
                                                               Ahead=NULL;
                                                               Lhead=NULL;  }
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 181 "sli9n.y" /* yacc.c:1646  */
    {}
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 184 "sli9n.y" /* yacc.c:1646  */
    {  
                                          type1=TT2;
                                           A1=Aentry((yyvsp[0])->name,type1);
                                          }
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 191 "sli9n.y" /* yacc.c:1646  */
    {}
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 192 "sli9n.y" /* yacc.c:1646  */
    {  }
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 197 "sli9n.y" /* yacc.c:1646  */
    {}
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 199 "sli9n.y" /* yacc.c:1646  */
    {
                                    type1=TT2;
                                    L2=Lcreateentry((yyvsp[0])->name,type1);
                                   }
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 203 "sli9n.y" /* yacc.c:1646  */
    {
                                    type1=TT2;
                                    L2=Lcreateentry((yyvsp[0])->name,type1);
                                    }
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 209 "sli9n.y" /* yacc.c:1646  */
    { 
                                                                   if((yyvsp[-3])->type!=TLookup("int")){
                                                                      yyerror("main function return type error\n");
                                                                      exit(1);}
                                                              (yyval)=makenode(TLookup("void"),44," ",0,(yyvsp[-5]),(yyvsp[-3]),NULL); 
                                                                   codegen((yyval));
                                                                   Lhead=NULL;
                                                                   printf("main Completed\n");
                                                                    }
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 218 "sli9n.y" /* yacc.c:1646  */
    { 
           					     (yyval)=makenode(TLookup("void"),48," ",0,NULL,NULL,NULL);
            						         codegen((yyval));
            						         Lhead=NULL;
            						         printf("Main Completed\n");}
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 225 "sli9n.y" /* yacc.c:1646  */
    {  TT2=TLookup("int");}
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 226 "sli9n.y" /* yacc.c:1646  */
    {TT2=TLookup("bool");}
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 227 "sli9n.y" /* yacc.c:1646  */
    {TT2=TLookup("void");}
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 228 "sli9n.y" /* yacc.c:1646  */
    {  TT2=TLookup((yyvsp[0])->name);
                  if(TT2==NULL){
                   yyerror("No type\n");
                   }
                  }
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 235 "sli9n.y" /* yacc.c:1646  */
    {TT2=TLookup("void");
                                                      (yyval)=makenode(TT2,0," ",0,(yyvsp[-1]),(yyvsp[0]),NULL);}
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 237 "sli9n.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 240 "sli9n.y" /* yacc.c:1646  */
    { //printf("in id=e\n");
                                            L1=Llookup((yyvsp[-3])->name);
                                              if(L1==NULL){
				              A2=A1;
				              while(A2!=NULL){
						   if(strcmp(A2->name,(yyvsp[-3])->name)==0){
						        type=A2->type;
						        break;}
						   A2=A2->next;
						    }
					     if(A2==NULL){
						  (yyvsp[-3])->Lentry=NULL;
						  temp=Glookup((yyvsp[-3])->name);
						  if(temp==NULL){
						  yyerror("Hi conflict : Undeclared variable");
						  exit(1);
					           }
					           if(temp->size > 1)
						    {
						       yyerror("id type mismatch");
						       exit(1);
						     }
						  type=temp->type;
						  (yyvsp[-3])->Gentry=temp;
					        }
					    }
				       else{
					     (yyvsp[-3])->Lentry=L1;  
					     type=L1->type;           
					     (yyvsp[-3])->Gentry=NULL;
					     temp=NULL;}
			 		     //printf("%s\n",type->name);
		                  
				    
			              if(type!=(yyvsp[-1])->type){
				       yyerror("conflicts in assign4");
				       exit(1);
                                               }
                                       TT2=TLookup("void");
                                      (yyval)=makenode(TT2,12," ",0,(yyvsp[-3]),(yyvsp[-1]),NULL);
                                            fst=0;     }
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 281 "sli9n.y" /* yacc.c:1646  */
    { temp=Glookup((yyvsp[-6])->name);
                                                if(temp==NULL){
                                                     yyerror("array not declared");exit(1);}
                                                else if(temp->size==1){
                                                     yyerror("conflict in nodetype");exit(1);}
                                                else{
				                 (yyval)=makenode(TLookup("void"),21," ",0,(yyvsp[-6]),(yyvsp[-4]),(yyvsp[-1]));
				                 (yyvsp[-6])->Gentry=temp;
				                 (yyvsp[-6])->type=temp->type;
                                                     }
				           if((yyvsp[-6])->type!=(yyvsp[-1])->type){
				               printf("%s %d\n",(yyvsp[-6])->type->name,(yyvsp[-1])->nodetype);
				               yyerror("conflicts in assign5");
				               exit(1);
                                               }
                                              fst=0; }
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 297 "sli9n.y" /* yacc.c:1646  */
    { L1=Llookup((yyvsp[-2])->name);
                                                if(L1==NULL){
						A2=A1;
					       while(A2!=NULL){
						 if(strcmp(A2->name,(yyvsp[-2])->name)==0){
						        type=A2->type;
						        break;}
						   A2=A2->next;
						    }
					          if(A2==NULL){
						    (yyvsp[-2])->Lentry=NULL;
						    temp=Glookup((yyvsp[-2])->name);
						    if(temp==NULL){
						   yyerror("conflict : Undeclared variable ");
						   exit(1);
					             }
						    if(temp->size!=1)
						    {
						       yyerror("id type mismatch");
						       exit(1);
						     }
						    type=temp->type;
						    (yyvsp[-2])->Gentry=temp;
					             }
					    }
				            else{
					        (yyvsp[-2])->Lentry=L1;  
					        type=L1->type;           
					        (yyvsp[-2])->Gentry=NULL;
					        temp=NULL;}
					   
				           (yyvsp[-2])->type=type;
					   (yyval)=makenode(TLookup("void"),3," ",0,(yyvsp[-2]),NULL,NULL);
					//printf("after read\n");
					}
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 332 "sli9n.y" /* yacc.c:1646  */
    { temp=Glookup((yyvsp[-5])->name); 
				         if(temp==NULL){
				             yyerror("array not declared");exit(1);}
				         else if(temp->size==1){
				             yyerror("array type invalid");exit(1);}
				         else if((yyvsp[-3])->type!=TLookup("int")){
				             yyerror("conflict in read");}
				          else{
			                      (yyval)=makenode(TLookup("void"),22," ",0,(yyvsp[-5]),(yyvsp[-3]),NULL);
			                      (yyvsp[-5])->Gentry=temp;
			                      (yyvsp[-5])->Lentry=NULL;
			                      (yyvsp[-5])->type=temp->type;
                                                 }
                                                 fst=0;}
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 346 "sli9n.y" /* yacc.c:1646  */
    {(yyval)=makenode(TLookup("void"),4," ",0,(yyvsp[-2]),NULL,NULL);
                                                             fst=0;}
#line 2035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 348 "sli9n.y" /* yacc.c:1646  */
    {if((yyvsp[-7])->type!=TLookup("bool") ){
                                                           yyerror("conflict in ifelse");
                                                           exit(1);}
                                                          (yyval)=makenode(TLookup("void"),17," ",0,(yyvsp[-7]),(yyvsp[-4]),(yyvsp[-2]));
                                                          fst=0;}
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 354 "sli9n.y" /* yacc.c:1646  */
    {if((yyvsp[-5])->type!=TLookup("bool")){
                                                             yyerror("conflict in while");
                                                             exit(1);}
                                                         (yyval)=makenode(TLookup("void"),18," ",0,(yyvsp[-5]),(yyvsp[-2]),NULL);
                                                         fst=0;}
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 360 "sli9n.y" /* yacc.c:1646  */
    {if((yyvsp[-5])->type!=TLookup("bool")){
                                                            yyerror("conflict in if");exit(1);
                                                        }
                                                       (yyval)=makenode(TLookup("void"),19," ",0,(yyvsp[-5]),(yyvsp[-2]),NULL);
                                                     fst=0; }
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 365 "sli9n.y" /* yacc.c:1646  */
    {
                                           L1=Llookup((yyvsp[-5])->name);
                                              if(L1==NULL){
				              A2=A1;
				              while(A2!=NULL){
						   if(strcmp(A2->name,(yyvsp[-5])->name)==0){
						        type=A2->type;
						        break;}
						   A2=A2->next;
						    }
					     if(A2==NULL){
						  (yyvsp[-5])->Lentry=NULL;
						  temp=Glookup((yyvsp[-5])->name);
						  if(temp==NULL){
						  yyerror("Hi conflict : Undeclared variable");
						  exit(1);
					           }
					           if(temp->size!=1)
						    {
						       yyerror("id type mismatch");
						       exit(1);
						   }
						  type=temp->type;
						  (yyvsp[-5])->Gentry=temp;
					        }
					    }
				       else{
					     (yyvsp[-5])->Lentry=L1;  
					     type=L1->type;           
					     (yyvsp[-5])->Gentry=NULL;
					     temp=NULL;}
                                          TT2=TLookup("void");
                                          (yyval)=makenode(TT2,57," ",0,(yyvsp[-5]),NULL,NULL);}
#line 2103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 400 "sli9n.y" /* yacc.c:1646  */
    {//printf("in field=e\n");
                                       
                                       (yyval)=makenode(TLookup("void"),58," ",0,(yyvsp[-1]),NULL,NULL);    
                                        flisthead=flist3;
                                             strcpy(nm,flist3->name);
                                             strcpy((yyval)->name,flist3->name);
                                            // printf("%s\n",nm);
                                             L1=Llookup(nm);
                                           temp=NULL;
	                                  if(L1==NULL){
	                                             A2=A1;
	                                         while(A2!=NULL){
	                                                if(strcmp(A2->name,nm)==0){
	                                                     type=A2->type;
	                                                     break;}
	                                                A2=A2->next;}
	                                         if(A2==NULL){
	                                               (yyval)->Lentry=NULL;
	                                               temp=Glookup(nm);
	                                               if(temp==NULL){
	                                               yyerror("Hi conflict2 : Undeclared variable");
	                                               exit(1);
	                                               }
	                                              type=temp->type;
	                                               (yyval)->Gentry=temp;
	                                            }
	                                         
	                                       }
	                                    else{ 
	                                            (yyval)->Lentry=L1;  
	                                            type=L1->type;           
	                                            (yyval)->Gentry=NULL;
	                                            temp=NULL;}
	                                     flist3->type=type;
	                                     FHead=type->fields;
	                                     /* while(flist3!=NULL){
		                              printf("hello %s\n",flist3->name);
		                             flist3=flist3->next;
		                                      }
		          
		                                    flist3=flisthead;
	                                     */
	                                     
                                             while(flist3->next!=NULL){
                                                Ft2=FLookup(type,flist3->next->name);
                                                if(Ft2==NULL){
                                                   yyerror("Hello Field not declared");
                                                   exit(1);
                                                  }
                                                  type=Ft2->type;
                                                  flist3=flist3->next;
                                                  flist3->type=type;
	                                         FHead=type->fields;
                                              }
                                        // printf("H1 %s %s\n",type->name,$3->type->name);
                                        
                                      if(type!=(yyvsp[-1])->type){
                                       yyerror("conflict in assigning types");
                                       exit(1);
                                      }
                                     
                                     (yyval)->typeentry=flisthead;
                                     flisthead=NULL;
                                      fst=0;
                              }
#line 2173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 467 "sli9n.y" /* yacc.c:1646  */
    {
                                        (yyval)=makenode(TLookup("void"),59," ",0,NULL,NULL,NULL);
                                       flisthead=flist2;
                                             strcpy(nm,flist2->name);
                                             strcpy((yyval)->name,flist2->name);
                                             L1=Llookup(nm);
                                           temp=NULL;
	                                  if(L1==NULL){
	                                             A2=A1;
	                                         while(A2!=NULL){
	                                                if(strcmp(A2->name,nm)==0){
	                                                     type=A2->type;
	                                                     break;}
	                                                A2=A2->next;}
	                                         if(A2==NULL){
	                                               (yyval)->Lentry=NULL;
	                                               temp=Glookup(nm);
	                                               if(temp==NULL){
	                                               yyerror("Hi1 conflict : Undeclared variable");
	                                               exit(1);
	                                               }
	                                              type=temp->type;
	                                               (yyval)->Gentry=temp;
	                                            }
	                                         
	                                       }
	                                    else{ 
	                                            (yyval)->Lentry=L1;  
	                                            type=L1->type;           
	                                            (yyval)->Gentry=NULL;
	                                            temp=NULL;}
	                                     flist2->type=type;
	                                     FHead=type->fields;
                                             while(flist2->next!=NULL){
                                                Ft2=FLookup(type,flist2->next->name);
                                                if(Ft2==NULL){
                                                   yyerror("Field1 not declared");
                                                   exit(1);
                                                  }
                                                  type=Ft2->type;
                                                  flist2=flist2->next;
                                                  flist2->type=type;
	                                         FHead=type->fields;
                                              }
                                        
                                       (yyval)->typeentry=flisthead;
                                       flisthead=NULL;
                                       fst=0;
                                       }
#line 2227 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 516 "sli9n.y" /* yacc.c:1646  */
    {   (yyval)=makenode(TLookup("void"),61," ",0,(yyvsp[-2]),NULL,NULL);
                                       L1=Llookup((yyvsp[-2])->name);
                                                if(L1==NULL){
						A2=A1;
					       while(A2!=NULL){
						 if(strcmp(A2->name,(yyvsp[-2])->name)==0){
						        type=A2->type;
						        break;}
						   A2=A2->next;
						    }
					          if(A2==NULL){
						    (yyvsp[-2])->Lentry=NULL;
						    temp=Glookup((yyvsp[-2])->name);
						    if(temp==NULL){
						   yyerror("conflict : Undeclared variable ");
						   exit(1);
					             }
						    if(temp->size!=1)
						    {
						       yyerror("id type mismatch");
						       exit(1);
						     }
						    type=temp->type;
						    (yyvsp[-2])->Gentry=temp;
					             }
					          
					    }
				            else{
					        (yyvsp[-2])->Lentry=L1;  
					        type=L1->type;           
					        (yyvsp[-2])->Gentry=NULL;
					        temp=NULL;}
					   
				           (yyvsp[-2])->type=type;
				           
					  
                                    }
#line 2269 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 554 "sli9n.y" /* yacc.c:1646  */
    {
                                      (yyval)=makenode(TLookup("void"),62," ",0,NULL,NULL,NULL);
                                      flisthead=flist2;
                                             strcpy(nm,flist2->name);
                                             strcpy((yyval)->name,flist2->name);
                                             L1=Llookup(nm);
                                           temp=NULL;
	                                  if(L1==NULL){
	                                             A2=A1;
	                                         while(A2!=NULL){
	                                                if(strcmp(A2->name,nm)==0){
	                                                     type=A2->type;
	                                                     break;}
	                                                A2=A2->next;}
	                                         if(A2==NULL){
	                                               (yyval)->Lentry=NULL;
	                                               temp=Glookup(nm);
	                                               if(temp==NULL){
	                                               yyerror("Hi conflict : Undeclared variable");
	                                               exit(1);
	                                               }
	                                              type=temp->type;
	                                               (yyval)->Gentry=temp;
	                                            }
	                                         
	                                       }
	                                    else{ 
	                                            (yyval)->Lentry=L1;  
	                                            type=L1->type;           
	                                            (yyval)->Gentry=NULL;
	                                            temp=NULL;}
	                                     flist2->type=type;
	                                     FHead=type->fields;
                                             while(flist2->next!=NULL){
                                                Ft2=FLookup(type,flist2->next->name);
                                                if(Ft2==NULL){
                                                   yyerror("Field3 not declared");
                                                   exit(1);
                                                  }
                                                  type=Ft2->type;
                                                  flist2=flist2->next;
                                                  flist2->type=type;
	                                         FHead=type->fields;
                                              }
                                        if(type==TLookup("int")||type==TLookup("bool")){
                                          yyerror("field in the structure cannot be freed");
                                          exit(1);
                                        }
                                       (yyval)->typeentry=flisthead;
                                       flisthead=NULL;
                                       fst=0;
                                    }
#line 2326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 607 "sli9n.y" /* yacc.c:1646  */
    { 
                                      (yyval)=makenode(TLookup("void"),63," ",0,NULL,NULL,NULL);
                                      flisthead=flist2;
                                             strcpy(nm,flist2->name);
                                             strcpy((yyval)->name,flist2->name);
                                             L1=Llookup(nm);
                                           temp=NULL;
	                                  if(L1==NULL){
	                                             A2=A1;
	                                         while(A2!=NULL){
	                                                if(strcmp(A2->name,nm)==0){
	                                                     type=A2->type;
	                                                     break;}
	                                                A2=A2->next;}
	                                         if(A2==NULL){
	                                               (yyval)->Lentry=NULL;
	                                               temp=Glookup(nm);
	                                               if(temp==NULL){
	                                               yyerror("Hi conflict : Undeclared variable");
	                                               exit(1);
	                                               }
	                                              type=temp->type;
	                                               (yyval)->Gentry=temp;
	                                            }
	                                         
	                                       }
	                                    else{ 
	                                            (yyval)->Lentry=L1;  
	                                            type=L1->type;           
	                                            (yyval)->Gentry=NULL;
	                                            temp=NULL;}
	                                     flist2->type=type;
	                                     FHead=type->fields;
                                             while(flist2->next!=NULL){
                                                Ft2=FLookup(type,flist2->next->name);
                                                if(Ft2==NULL){
                                                   yyerror("Field4 not declared");
                                                   exit(1);
                                                  }
                                                  type=Ft2->type;
                                                  flist2=flist2->next;
                                                  flist2->type=type;
	                                         FHead=type->fields;
                                              }
                                           if(type!=TLookup("int")){
                                          yyerror("structure cannot be read only fields can read");
                                          exit(1);
                                        }
                                         
                                         (yyval)->typeentry=flisthead;
                                         flisthead=NULL;
                                          fst=0;}
#line 2383 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 660 "sli9n.y" /* yacc.c:1646  */
    {    
                                              L1=Llookup((yyvsp[-3])->name);
                                              if(L1==NULL){
				              A2=A1;
				              while(A2!=NULL){
						   if(strcmp(A2->name,(yyvsp[-3])->name)==0){
						        type=A2->type;
						        break;}
						   A2=A2->next;
						    }
					     if(A2==NULL){
						  (yyvsp[-3])->Lentry=NULL;
						  temp=Glookup((yyvsp[-3])->name);
						  if(temp==NULL){
						  yyerror("Hi3 conflict : Undeclared variable");
						  exit(1);
					           }
					           if(temp->size > 1)
						    {
						       yyerror("id type mismatch");
						       exit(1);
						     }
						  type=temp->type;
						  (yyvsp[-3])->Gentry=temp;
					        }
					    }
				       else{
					     (yyvsp[-3])->Lentry=L1;  
					     type=L1->type;           
					     (yyvsp[-3])->Gentry=NULL;
					     temp=NULL;}
			               if(type==TLookup("int")||type==TLookup("bool")){
				               yyerror("conflicts in assign2");
				               exit(1);
                                               }
                                          TT2=TLookup("void");
                                           (yyval)=makenode(TT2,64," ",0,(yyvsp[-3]),NULL,NULL);
                                                 //printf("id=null\n"); 
                                                 }
#line 2427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 700 "sli9n.y" /* yacc.c:1646  */
    {   (yyval)=makenode(TLookup("void"),54," ",0,NULL,NULL,NULL);
                                             flisthead=flist2;
                                             strcpy(nm,flist2->name);
                                             strcpy((yyval)->name,flist2->name);
                                             L1=Llookup(nm);
                                           temp=NULL;
	                                  if(L1==NULL){
	                                             A2=A1;
	                                         while(A2!=NULL){
	                                                if(strcmp(A2->name,nm)==0){
	                                                     type=A2->type;
	                                                     break;}
	                                                A2=A2->next;}
	                                         if(A2==NULL){
	                                               (yyval)->Lentry=NULL;
	                                               temp=Glookup(nm);
	                                               if(temp==NULL){
	                                               yyerror("Hi2 conflict : Undeclared variable");
	                                               exit(1);
	                                               }
	                                              type=temp->type;
	                                               (yyval)->Gentry=temp;
	                                            }
	                                         
	                                       }
	                                    else{ 
	                                            (yyval)->Lentry=L1;  
	                                            type=L1->type;           
	                                            (yyval)->Gentry=NULL;
	                                            temp=NULL;}
	                                     flist2->type=type;
	                                     FHead=type->fields;
                                             while(flist2->next!=NULL){
                                                Ft2=FLookup(type,flist2->next->name);
                                                if(Ft2==NULL){
                                                   yyerror("Field5 not declared");
                                                   exit(1);
                                                  }
                                                  type=Ft2->type;
                                                  flist2=flist2->next;
                                                  flist2->type=type;
	                                         FHead=type->fields;
                                              }
                                             
                                               if(type==TLookup("int")||type==TLookup("bool")){
                                                 yyerror("NULL assigned to wrong field\n");
                                                 exit(1);
                                                }
                                               (yyval)->type=type;
                                               (yyval)->typeentry=flisthead;
                                               flisthead=NULL;
                                               fst=0;}
#line 2484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 755 "sli9n.y" /* yacc.c:1646  */
    { TT2=TLookup("bool");
                             TT3=TLookup("int");
                              if((yyvsp[-2])->type==TT3&&(yyvsp[0])->type==TT3){
		                  (yyval)=makenode(TT3,5," ",0,(yyvsp[-2]),(yyvsp[0]),NULL);}
		            else{
		                  yyerror("conflicting types in addition\n");
		                  exit(1);
                                  }
                                  fst=0;}
#line 2498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 764 "sli9n.y" /* yacc.c:1646  */
    { TT2=TLookup("bool");
                             TT3=TLookup("int");
                              if((yyvsp[-2])->type==TT3&&(yyvsp[0])->type==TT3){
		                  (yyval)=makenode(TT3,7," ",0,(yyvsp[-2]),(yyvsp[0]),NULL);
		            }
		            else{
		                  yyerror("conflicting types in multiplication");
		                  exit(1);
                             }fst=0;}
#line 2512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 773 "sli9n.y" /* yacc.c:1646  */
    { TT2=TLookup("bool");
                             TT3=TLookup("int");
                              if((yyvsp[-2])->type==TT3&&(yyvsp[0])->type==TT3){
		                  (yyval)=makenode(TT3,6," ",0,(yyvsp[-2]),(yyvsp[0]),NULL);
		            }
		            else{
		                  yyerror("conflicting types in subtraction");
		                  exit(1);
                               }fst=0;}
#line 2526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 782 "sli9n.y" /* yacc.c:1646  */
    {
                               TT3=TLookup("int");
                              if((yyvsp[-2])->type==TT3&&(yyvsp[0])->type==TT3){
                                    printf("divvvvvvvvvvvvvvvvvvvvvvvvvv\n");
		                  (yyval)=makenode(TT3,8," ",0,(yyvsp[-2]),(yyvsp[0]),NULL);
		            }
		            else{
		                  yyerror("conflicting types in division");
		                  exit(1);
                             }fst=0;}
#line 2541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 792 "sli9n.y" /* yacc.c:1646  */
    {TT2=TLookup("bool");
                             TT3=TLookup("int");
                              if((yyvsp[-2])->type==TT3&&(yyvsp[0])->type==TT3){
		                  (yyval)=makenode(TT2,15," ",0,(yyvsp[-2]),(yyvsp[0]),NULL);
		            }
		            else{
		                  yyerror("conflicting types in lesserthan");
		                  exit(1);
                             }fst=0;}
#line 2555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 801 "sli9n.y" /* yacc.c:1646  */
    {TT2=TLookup("bool");
                             TT3=TLookup("int");
                             if((yyvsp[-2])->type==TT3&&(yyvsp[0])->type==TT3){
		                   (yyval)=makenode(TT2,16," ",0,(yyvsp[-2]),(yyvsp[0]),NULL);
		            }
		            else{
		                   yyerror("conflicting types in greaterthan");
		                   exit(1);
                            }fst=0;}
#line 2569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 811 "sli9n.y" /* yacc.c:1646  */
    { TT2=TLookup("bool");
                             TT3=TLookup("int");
                             if((yyvsp[-2])->type==TT2||(yyvsp[-2])->type==TT3){
                              yyerror("conflict in comparing with null");
                              exit(1);
                               } 
                             (yyval)=makenode(TT2,65," ",0,(yyvsp[-2]),NULL,NULL);
                             fst=0;}
#line 2582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 820 "sli9n.y" /* yacc.c:1646  */
    {TT2=TLookup("bool");
                             TT3=TLookup("int");
                              if((yyvsp[-2])->type==TT3&&(yyvsp[0])->type==TT3){
		                   (yyval)=makenode(TT2,32," ",0,(yyvsp[-2]),(yyvsp[0]),NULL);
		            }
		            else{
		                  yyerror("conflicting types in not equalto");
		                  exit(1);
                             }fst=0;}
#line 2596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 829 "sli9n.y" /* yacc.c:1646  */
    { TT2=TLookup("bool");
                               TT3=TLookup("int");
                             if((yyvsp[-2])->type==TT2||(yyvsp[-2])->type==TT3){
                              yyerror("conflict in comparing with null");
                              exit(1);
                               } 
                             (yyval)=makenode(TT2,66," ",0,(yyvsp[-2]),NULL,NULL);fst=0;
                             }
#line 2609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 838 "sli9n.y" /* yacc.c:1646  */
    {TT2=TLookup("bool");
                             TT3=TLookup("int");
                              if((yyvsp[-2])->type==TT3&&(yyvsp[0])->type==TT3){
		                  (yyval)=makenode(TT2,60," ",0,(yyvsp[-2]),(yyvsp[0]),NULL);}
		            else{
		                  yyerror("conflicting types in not equalto");
		                  exit(1);
                                }fst=0;}
#line 2622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 846 "sli9n.y" /* yacc.c:1646  */
    {TT2=TLookup("bool");
                             TT3=TLookup("int");
                              if((yyvsp[-2])->type==TT2&&(yyvsp[0])->type==TT2){
		                 (yyval)=makenode(TT2,30," ",0,(yyvsp[-2]),(yyvsp[0]),NULL);}
		            else{
		            yyerror("conflicting types in AND");
		            exit(1);
                           }fst=0;}
#line 2635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 854 "sli9n.y" /* yacc.c:1646  */
    {TT2=TLookup("bool");
                             TT3=TLookup("int");
                             if((yyvsp[-2])->type==TT2&&(yyvsp[0])->type==TT2){
		              (yyval)=makenode(TT2,31," ",0,(yyvsp[-2]),(yyvsp[0]),NULL);}
		            else{
		              yyerror("conflicting types in OR");
		              exit(1);
                           }fst=0;}
#line 2648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 862 "sli9n.y" /* yacc.c:1646  */
    { TT2=TLookup("bool");
                             TT3=TLookup("int");
                               if((yyvsp[-2])->type==TT3&&(yyvsp[0])->type==TT3){
		                (yyval)=makenode(TT2,33," ",0,(yyvsp[-2]),(yyvsp[0]),NULL);}
		             else{
		                yyerror("conflicting types in less than or equalto");
		                exit(1);
                              }fst=0;}
#line 2661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 870 "sli9n.y" /* yacc.c:1646  */
    { TT2=TLookup("bool");
                             TT3=TLookup("int");
                              if((yyvsp[-2])->type==TT3&&(yyvsp[0])->type==TT3){
		               (yyval)=makenode(TT2,34," ",0,(yyvsp[-2]),(yyvsp[0]),NULL);}
		            else{
		               yyerror("conflicting types in greater than or equalto");
		               exit(1);
                              }fst=0;}
#line 2674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 878 "sli9n.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);fst=0;}
#line 2680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 879 "sli9n.y" /* yacc.c:1646  */
    {  temp=Glookup((yyvsp[-2])->name);
     			   if(temp==NULL){
				yyerror("Function not declared");
				exit(1);}
	                      A2=temp->list;
		            if(A2!=NULL||T2!=NULL){
                                yyerror("Error in count of arguments\n");
                                exit(1);
                              }
                              (yyval)=makenode((yyvsp[-2])->type,37," ",0,(yyvsp[-2]),NULL,NULL);}
#line 2695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 889 "sli9n.y" /* yacc.c:1646  */
    {  //printf("name is %s\n",$1->name);
                              temp=Glookup((yyvsp[-3])->name);
     			   if(temp==NULL){
				yyerror("Function not declared");
				exit(1);}
		            type=temp->type;
		            A2=temp->list;
		            T2=(yyvsp[-1]);
                              while(T2!=NULL){
                                  T1=T2->ptr2;
                                  if(T1->type!=A2->type){
                                    yyerror("call arguments type mismatch\n");
                                    exit(1);
                                    }
                                    T2=T2->ptr1;
                                    A2=A2->next;
                              }
                              if(A2!=NULL||T2!=NULL){
                              yyerror("Error in count of Arguments\n");
                              exit(1);
                              }
                            // printf("args %s\n",type->name);
                            (yyval)=makenode(type,38," ",0,(yyvsp[-3]),(yyvsp[-1]),NULL);
                            }
#line 2724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 913 "sli9n.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 914 "sli9n.y" /* yacc.c:1646  */
    { 
                         L1=Llookup((yyvsp[0])->name);
                         temp=NULL;
		       if(L1==NULL){
		                  A2=A1;
		              while(A2!=NULL){
		                     if(strcmp(A2->name,(yyvsp[0])->name)==0){
		                          type=A2->type;
		                          break;}
		                     A2=A2->next;}
		                     
		              if(A2==NULL){
		                    (yyvsp[0])->Lentry=NULL;
		                    temp=Glookup((yyvsp[0])->name);
		                    if(temp==NULL){
		                    yyerror("Hi4 conflict : Undeclared variable");
		                    exit(1);
		                    }
		                    if(temp->size > 1){
		                           yyerror("conflict : type");
		                           exit(1);}
		                    type=temp->type;
		                    (yyvsp[0])->Gentry=temp;
		                 }
		              
		            }
		      else{ 
		                (yyvsp[0])->Lentry=L1;  
		                 type=L1->type;           
		                 (yyvsp[0])->Gentry=NULL;
		                 temp=NULL;}
		      (yyvsp[0])->type=type;
		      (yyval)=(yyvsp[0]);
		     // printf("%s\n",$$->type->name);
		      }
#line 2770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 949 "sli9n.y" /* yacc.c:1646  */
    { temp=Glookup((yyvsp[-3])->name);
                             TT2=TLookup("bool");
                             TT3=TLookup("int");
		              if(temp==NULL){
		                 yyerror("conflict : Undeclared Array");
		                 exit(1);
		              }
		              else if(temp->size==1){
		                 yyerror("conflict : type");
		                 exit(1);
		              }
		              else if((yyvsp[-1])->type==TT2){
		                  yyerror(" conflict :Expression  found boolean");
		                  exit(1);
		              }
		              else{
		               
		              (yyvsp[-3])->Gentry=temp;
		               if(temp->type==TT3)
		                 (yyvsp[-3])->type=TT3;
		               else 
		                 (yyvsp[-3])->type=TT2;
		              
		               }
                        fst=0;
                       printf("%s %s\n",(yyvsp[-3])->type->name,(yyvsp[-3])->name);
                       (yyval)=makenode((yyvsp[-3])->type,24," ",0,(yyvsp[-3]),(yyvsp[-1]),NULL);}
#line 2802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 976 "sli9n.y" /* yacc.c:1646  */
    {TT2=TLookup("bool");(yyval)=makenode(TT2,28," ",1,NULL,NULL,NULL);}
#line 2808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 977 "sli9n.y" /* yacc.c:1646  */
    {TT2=TLookup("bool");(yyval)=makenode(TT2,29," ",0,NULL,NULL,NULL);}
#line 2814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 978 "sli9n.y" /* yacc.c:1646  */
    {(yyval)=makenode(TLookup("int"),56,"",0,NULL,NULL,NULL);
                          // printf("initialize\n");
                           }
#line 2822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 981 "sli9n.y" /* yacc.c:1646  */
    {   (yyval)=makenode(TLookup("void"),55," ",0,NULL,NULL,NULL); 
                          flisthead=flist2;
                           strcpy(nm,flist2->name);
                           strcpy((yyval)->name,flisthead->name);
                           L1=Llookup(nm);
                         temp=NULL;
		       if(L1==NULL){
		                  A2=A1;
		              while(A2!=NULL){
		                     if(strcmp(A2->name,nm)==0){
		                          type=A2->type;
		                          break;}
		                     A2=A2->next;}
		              if(A2==NULL){
		                    temp=Glookup(nm);
		                    if(temp==NULL){
		                    yyerror("Hi conflict : Undeclared variable");
		                    exit(1);
		                    }
		                    type=temp->type;
		                    (yyval)->Lentry=NULL;
		                    (yyval)->Gentry=temp;
		                 }
		              
		            }
		         else{ 
		                 (yyval)->Lentry=L1;  
		                 type=L1->type;           
		                 (yyval)->Gentry=NULL;
		                 temp=NULL;}
		          flist2->type=type;
		          //printf("H2 %s\n",type->name);
		          FHead=type->fields;
		          
		        /* while(flist2!=NULL){
		           printf("hello %s\n",flist2->name);
		           flist2=flist2->next;
		           }
		          
		          flist2=flisthead;*/
		          
                           while(flist2->next!=NULL){
                              Ft2=FLookup(type,flist2->next->name);
                              if(Ft2==NULL){
                                 yyerror("Field not declared");
                                 exit(1);
                                }
                                type=Ft2->type;
                                flist2=flist2->next;
                                flist2->type=type;
                                FHead=type->fields;
                            }
                             (yyval)->type=type;
                             (yyval)->typeentry=flisthead;
                             flisthead=NULL;
                          }
#line 2883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1038 "sli9n.y" /* yacc.c:1646  */
    {(yyval)=makenode(TLookup("void"),35," ",0,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 2889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1039 "sli9n.y" /* yacc.c:1646  */
    {(yyval)=makenode(TLookup("void"),36," ",0,NULL,(yyvsp[0]),NULL);}
#line 2895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1041 "sli9n.y" /* yacc.c:1646  */
    {if(fst==0) {
                    flist3=flisthead;
                    fst++;}
                 flisthead=NULL;}
#line 2904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1046 "sli9n.y" /* yacc.c:1646  */
    {flist2=makelistfield((yyvsp[0]));}
#line 2910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1047 "sli9n.y" /* yacc.c:1646  */
    {flist2=makelistfield((yyvsp[-2]));
                            flist2=makelistfield((yyvsp[0]));}
#line 2917 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2921 "y.tab.c" /* yacc.c:1646  */
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
#line 1051 "sli9n.y" /* yacc.c:1906  */



int yyerror(char const *s){
      printf("Error %s\n",s);
      exit(1);
}

int main(int argc,char*argv[]){
      if(argc==2){
	yyin=fopen(argv[1],"r");}
	
      TypeTableCreate();
      printf("Typetable default\n");
      yyparse();
/*temp=Ghead;
  while(temp!=NULL){
	 printf("%s ",temp->name);
	 printf("%d ",temp->argcount);
	 if(temp->list!=NULL){
	     A1=temp->list;
	 while(A1!=NULL){
	     printf("%s ",A1->name);
	     A1=A1->next;
	  }}
  printf("\n");
  temp=temp->next;
}*/
return 1;
}

