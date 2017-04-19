%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"y.tab.h"
char *xyc;

%}

%%

"main"    {return MAIN;}
"("     {return *yytext;}
")"     {return *yytext;}
[0-9]+  {yylval=makenode(TLookup("int"),2," ",atoi(yytext),NULL,NULL,NULL);return NUM;}
"["     {return *yytext;}
"{"     {return *yytext;}
"}"     {return *yytext;}
"]"     {return *yytext;}
"+"	{return *yytext;}
"*"	{return *yytext;}
"="     {return *yytext;}
";"     {return *yytext;}
"=="    {return ISEQ;}
"<="    {return LE;}
">="    {return GE;}
">"     {return *yytext;}
","      {return *yytext;}
"<"      {return *yytext;}
"-"        {return *yytext;}
"/"        {return *yytext;}
"null"       {return NUL;}
"initialize" {return INITIALIZE;}
"void"     {return VOID;}
"type"     {return TYPE;}
"endtype"  {return ENDTYPE;}
"alloc"    { return ALLOC;}
"read"    {return RE;}
"write"   {return WR;}
[\n]      {}
[ ]        {}
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
"free"          {return FREE;}
"false"|"False" {return F;}
"&&"             {return AND;}
"return"          {return RET;}
"||"              {return OR;}
"!="              {return NEQ;}
[A-Z|a-z|0-9]+   {xyc=(char*)malloc(100*sizeof(char));strcpy(xyc,yytext);
                           //printf("Hoo %s\n",yytext);
                     yylval=makenode(TLookup("void"),1,xyc,0,NULL,NULL,NULL);return ID;}
"."             {return *yytext;}

%%

int yywrap(){
return 1;

}
