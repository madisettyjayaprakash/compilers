%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "sli2exptree.h"
#include "symboltable.h"
#include "sli2exptree.c"
#include "symboltable.c"
#include "codegen.c"
#define YYSTYPE Tnode*

struct Gsymbol*temp;
char a;
int i,b=0,p,q;
FILE *yyin;
%}

%token  ID NUM RE WR IF ELSE ENDIF WHILE THEN DO ENDWHILE ISEQ  BN END INT BOOL DECL ENDDECL  GEQ NEQ LEQ T F AND
        OR LE GE 

%left '+' '-'
%left '*' '/'
%right '='
%nonassoc '<' '>' LEQ GEQ ISEQ NEQ AND OR LE GE

%%
prog : decl body      {}
       ;
decl: DECL dlist ENDDECL  { }
     |DECL ENDDECL        {}
         ;
dlist :dlist type varlist ';' {}
      |type varlist  ';'      {}
         ;
varlist :varlist ','  var     {}   
        |var                  {}     
         ;
var : ID                      {if(i==1){
                                  // printf("%d\n",i);
                                   p=sptr;sptr++;Ghead=createentry($1->name,30,1,p,NULL);
                                   // INT - 30
                                   
                                   }
                               else{
                                   q=sptr;sptr++;createentry($1->name,40,1,q,NULL);
                                   //BOOL -40
                                   }
                                   }
     |ID '[' NUM ']'          {if(i==1){
                                   p=sptr;sptr=sptr+$3->value;createentry($1->name,31,$3->value,p,NULL);
                                   //INT_ARR - 31
                                 
                                   }
                               else{
                                   q=sptr;sptr=sptr+$3->value;createentry($1->name,41,$3->value,q,NULL);
                                   //BOOL_ARR - 41
                                   }
                              } 
     ;
type : INT {i=1;}
      |BOOL {i=2;}    
      ;
                 
          
body : BN slist END            { 
                                inter_codegen($2);
                               // b=evaluate($2);
                               exit(1);}
      | BN END                 {exit(1);}
        ;
slist : stmt slist           {$$=makenode(0,0," ",0,$1,$2,NULL);}
       |stmt                 {$$=$1;}
        ;
stmt  : ID '=' E ';'          {temp=Glookup($1->name);
                                 if(temp==NULL){yyerror("Variable not declared");exit(1);}
                                 else if(temp->type==31||temp->type==41){yyerror("conflict in nodetype ");exit(1);}
                                 else{ 
                                  $$=makenode(0,12," ",0,$1,$3,NULL);
                                   $1->Gentry=temp;     
                                    if(temp->type==30)
                                    $1->type=30;
                                   else if(temp->type==40)
                                   $1->type=40;
                                }
                                if($1->type!=$3->type){
                                 yyerror("conflicts in assign1");
                                 exit(1);
                                }
                                
                                }
       |ID '[' E ']' '=' E ';' {temp=Glookup($1->name);
                                if(temp==NULL){yyerror("array not declared");exit(1);}
                                 else if(temp->type==30||temp->type==40){yyerror("conflict in nodetype");exit(1);}
                                 
                                 else{
                                   $$=makenode(0,21," ",0,$1,$3,$6);
                                   $1->Gentry=temp;
                                   if(temp->type==31)
                                    $1->type=30;
                                   else if(temp->type==41)
                                   $1->type=40;
                                 }
                                  if($1->type!=$6->type){
                                 yyerror("conflicts in assign2");
                                 exit(1);
                                }
                                 }
       |RE '(' ID ')' ';'        { temp=Glookup($3->name); 
                                   if(temp==NULL){yyerror("id not declared");exit(1);}
                                   else if(temp->type==31||temp->type==41) {yyerror("type invalid");exit(1);}
                                   else{
                                      $$=makenode(0,3," ",0,$3,NULL,NULL);
                                      $3->Gentry=temp;
                                      if(temp->type==30)
                                         $3->type=30;
                                      else if(temp->type==40)
                                          $3->type=40;
                                    }
                                    
                                 }
       |RE '('ID '[' E ']' ')' ';' {  temp=Glookup($3->name); 
                                   if(temp==NULL){yyerror("array not declared");exit(1);}
                                   else if(temp->type==30||temp->type==40){yyerror("array type invalid");exit(1);}
                                   else if($5->type==40){yyerror("conflict in read");}
                                   else{
                                    $$=makenode(0,22," ",0,$3,$5,NULL);
                                    $3->Gentry=temp;
                                    if(temp->type==31)
                                     $3->type=31;
                                    else if(temp->type==41)
                                     $3->type=41;
                                   
                                   }
                                   
                                     }
       |WR '(' E ')' ';'         {  $$=makenode(0,4," ",0,$3,NULL,NULL);}
                                      
       |IF '(' E ')' THEN slist  ELSE  slist ENDIF  ';'  {
                                                        if($3->type!=40){
                                                        yyerror("conflict in ifelse");
                                                        exit(1);
                                                        }
                                                       $$=makenode(0,17," ",0,$3,$6,$8);}
       |WHILE '(' E ')' DO  slist  ENDWHILE ';'      { if($3->type!=40){
                                                        yyerror("conflict in while");exit(1);
                                                        }$$=makenode(0,18," ",0,$3,$6,NULL);}
       |IF '(' E ')' THEN  slist ENDIF  ';'  { if($3->type!=40){
                                                        yyerror("conflict in if");exit(1);
                                                        }$$=makenode(0,19," ",0,$3,$6,NULL);}
       ;
       
E  :  E '+' E      {
                      if($1->type==30&&$3->type==30){
                      $$=makenode(30,5," ",0,$1,$3,NULL);
                     }
                     else{
                     yyerror("conflicting types in addition\n");
                     exit(1);
                     }

                    }
     |E '*' E      {   
                      if($1->type==30&&$3->type==30){
                      $$=makenode(30,7," ",0,$1,$3,NULL);
                     }
                     else{
                     yyerror("conflicting types in multiplication");
                     exit(1);
                     }
                       }
     |E '-' E      {
                      if($1->type==30&&$3->type==30){
                      $$=makenode(30,6," ",0,$1,$3,NULL);
                     }
                     else{
                     yyerror("conflicting types in subtraction");
                     exit(1);
                     }}
     |E '/' E      {
                       if($1->type==30&&$3->type==30){
                      $$=makenode(30,8," ",0,$1,$3,NULL);
                     }
                     else{
                     yyerror("conflicting types in division");
                     exit(1);
                     }
                       }
     |E '<' E      {
                      if($1->type==30&&$3->type==30){
                      $$=makenode(40,15," ",0,$1,$3,NULL);
                     }
                     else{
                     yyerror("conflicting types in lesserthan");
                     exit(1);
                     }
                      
                      }
     |E '>' E      {
                     if($1->type==30&&$3->type==30){
                      $$=makenode(40,16," ",0,$1,$3,NULL);
                     }
                     else{
                     yyerror("conflicting types in greaterthan");
                     exit(1);
                     }
                     }
                     
     |E ISEQ E     {
                     if($1->type==30&&$3->type==30){
                       $$=makenode(40,14," ",0,$1,$3,NULL);
                     }
                     else{
                     yyerror("conflicting types in equalto");
                     exit(1);
                     }
                    }
     |E AND E      {  if($1->type==40&&$3->type==40){
                       $$=makenode(40,30," ",0,$1,$3,NULL);
                     }
                     else{
                     yyerror("conflicting types in AND");
                     exit(1);
                     }  }
     |E OR E        {  if($1->type==40&&$3->type==40){
                       $$=makenode(40,31," ",0,$1,$3,NULL);
                     }
                     else{
                     yyerror("conflicting types in OR");
                     exit(1);
                     }}
     |E NEQ E      { if($1->type==30&&$3->type==30){
                       $$=makenode(40,32," ",0,$1,$3,NULL);
                     }
                     else{
                     yyerror("conflicting types in not equalto");
                     exit(1);
                     }}
     |E LE E        {if($1->type==30&&$3->type==30){
                       $$=makenode(40,33," ",0,$1,$3,NULL);
                     }
                     else{
                     yyerror("conflicting types in less than or equalto");
                     exit(1);
                     } }
     |E GE E         {if($1->type==30&&$3->type==30){
                       $$=makenode(40,34," ",0,$1,$3,NULL);
                     }
                     else{
                     yyerror("conflicting types in greater than or equalto");
                     exit(1);
                     }}                                             
     |'(' E ')'    {$$=$2;}
     |NUM          {$$=$1;}
     |ID           {temp=Glookup($1->name);
                     if(temp==NULL){
                     yyerror("conflict : Undeclared variable");
                     exit(1);
                     }
                     else if(temp->type==31||temp->type==41){
                      yyerror("conflict : type");
                      exit(1);
                      }
                     else {
                     $1->Gentry=temp;
                     $1->type=temp->type;
                     
                     }
                   
                     $$=$1;
                        }
     |ID '[' E ']' { temp=Glookup($1->name);
                      if(temp==NULL){
                       yyerror("conflict : Undeclared Array");
                       exit(1);
                     }
                      else if(temp->type==30||temp->type==40){
                      yyerror("conflict : type");
                      exit(1);
                      }
                      else if($3->type==40){
                      yyerror(" conflict :Expression  found boolean");
                      exit(1);
                      }
                      else{
                      $1->Gentry=temp;
                      if(temp->type==31)
                        $1->type=30;
                       else 
                       $1->type=40;
                       
                        }
                        
                       $$=makenode($1->type,24," ",0,$1,$3,NULL);}
       |T             {$$=makenode(40,28," ",1,NULL,NULL,NULL);}
       |F              {$$=makenode(40,29," ",0,NULL,NULL,NULL);}
     ;

%%

yyerror(char const *s){
printf("Error %s\n",s);
}

int main(int argc,char*argv[]){
if(argc==2){
yyin=fopen(argv[1],"r");
}



yyparse();
return 1;
}

