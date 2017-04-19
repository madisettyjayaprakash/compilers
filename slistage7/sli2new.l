%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"y.tab.h"
char *x;

%}

%%


[0-9]+  {yylval=makenode(30,2," ",atoi(yytext),NULL,NULL,NULL);return NUM;}
" "     {}
"["     {return *yytext;}
"]"     {return *yytext;}
"+"	{return *yytext;}
"*"	{return *yytext;}
"="     {return *yytext;}
"("     {return *yytext;}
")"     {return *yytext;}
";"     {return *yytext;}
"=="    {return ISEQ;}
"<="    {return LE;}
">="    {return GE;}
">"     {return *yytext;}
","      {return *yytext;}
"<"      {return *yytext;}
"-"        {return *yytext;}
"/"        {return *yytext;}
"read"    {return RE;}
"write"   {return WR;}
[\n]      {}
"if"      {return IF;}
"then"   {return THEN;}
"else"   {return ELSE;}
"while" {return WHILE;}
"do"       {return DO;}
"endif"    {return ENDIF;}
"endwhile"  {return ENDWHILE;}
"begin"      {return BN;}
"end"        {return END;}
"decl"       {return DECL;}
"enddecl"    {return ENDDECL;}
"int"        {return INT;}
"bool"       {return BOOL;}
"true"|"True"   {return T;}
"false"|"False" {return F;}
"&&"             {return AND;}
"||"              {return OR;}
"!="              {return NEQ;}
[a-z]+   {x=(char*)malloc(100*sizeof(char));strcpy(x,yytext);
          yylval=makenode(0,1,x,0,NULL,NULL,NULL);return ID;}

%%

int yywrap(){
return 1;

}




