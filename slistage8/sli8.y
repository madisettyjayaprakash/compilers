%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ArgStruct*A1,*A2;
struct Gsymbol *temp;
struct Lsymbol *L2,*L1,*L3;
struct Tnode*T1,*T2;
FILE *yyin;
int i=-1,b,type,sptr=4096;
char *lt;
#include "symtbl.h"
#include "sliexptree.h"
#include "sliexptree.c"
#include "symtbl.c"
#include"codegen8.c"
#define YYSTYPE Tnode*


%}

%token  ID NUM RE WR IF ELSE ENDIF WHILE THEN DO ENDWHILE ISEQ  BN END INT BOOL DECL ENDDECL  GEQ NEQ LEQ T F AND
        OR LE GE RET MAIN

%left '+' '-'
%left '*' '/'
%right '='
%nonassoc '<' '>' LEQ GEQ ISEQ NEQ AND OR LE GE


%%

Program : GdeclBlock FdefBlock MainBlock  {}
          |GdeclBlock MainBlock           
          |MainBlock
         ;
GdeclBlock : DECL Gdecllist ENDDECL        {inter_codegen();
                                           }
            | DECL ENDDECL
            ;
Gdecllist : Gdecllist Gdecl
            |Gdecl
            ;
Gdecl    :Type Gidlist ';'                {i=-1;}
          ;
Gidlist :Gidlist ',' Gid
        |Gid
           ;
Gid :  ID                             { if(i==0)
		                         type=30;
		                      else if(i==1)
		                         type=40;
		                      temp=Gcreateentry($1->name,type,1,NULL); 
		                     }
       |ID '[' NUM ']'        {if(i==0)
                                 type=31;
                               else if(i==1)
                                 type=41;
                               temp=Gcreateentry($1->name, type,$3->value,NULL);}
       |ID '(' Paramlist ')'  {if(i==0)
                                 type=30;
                               else if(i==1)
                                 type=40;
                               temp=Gcreateentry($1->name, type,-1,Ahead);
                               argc=0;
                               Ahead=NULL;}
      ; 
Paramlist : Paramlist ',' Plist   {}
           |Plist                 {}
           ;
Plist    :Type ID             {if(i==0)
                                 type=30;
                               else if(i==1)
                                 type=40;
                               Ahead=Aentry($2->name,type);}
           ;

FdefBlock : FdefBlock Fdef
           |Fdef
           ;
Fdef     :Type ID '(' Arglist ')' '{' LdeclBlock BN slist RET E ';'END '}'  {
						          
						          //L3=Lhead;
                                                                temp=Glookup($2->name);
                                                                if(temp->type!=$11->type){
                                                                   yyerror("function return type error\n");
                                                                   exit(1);
                                                                }  
                                                               semfuncheck($2->name,Ahead);
                                                               $$=makenode(0,45,$2->name,0,$9,$11,NULL);
                                                               A1=Ahead;
                                                               codegen($$);
                                                               Ahead=NULL;
                                                               Lhead=NULL; 
                                                               }
                                                               
         |Type ID '(' Arglist ')' '{' LdeclBlock BN END '}'   {
                                                              semfuncheck($2->name,Ahead);
                                                              $$=makenode(0,46,$2->name,0,NULL,NULL,NULL);
                                                              A1=Ahead;
                                                              codegen($$);
                                                              Ahead=NULL;
                                                              Lhead=NULL;}
        
        
         |Type ID '(' ')' '{'   LdeclBlock BN slist RET E ';'END '}'  { 
                                                                //L3=Lhead;
                                                                temp=Glookup($2->name);
                                                                if(temp->type!=$10->type){
                                                                   yyerror("function return type error\n");
                                                                   exit(1);
                                                                }  
                                                               semfuncheck($2->name,Ahead);
                                                               $$=makenode(0,51,$2->name,0,$8,$10,NULL);
                                                               A1=Ahead;
                                                               codegen($$);
                                                               Ahead=NULL;
                                                               Lhead=NULL;  }
          
          
          ;
Arglist  :Arglist ',' Arg
         |Arg
         ;
Arg    : Type ID                           {if(i==0)
                                              type=30;
                                           else if(i==1)
                                               type=40;
                                           A1=Aentry($2->name,type);
                                          }
         ;
         
                 
LdeclBlock : DECL Ldecllist ENDDECL    {}
            | DECL ENDDECL             {}
           ;
Ldecllist  : Ldecllist Ldecl
             |Ldecl 
             ;
Ldecl      : Type Lidlist ';'     {}
             ;
Lidlist     :Lidlist ',' ID        {if(i==0)
                                      type=30;
                                    else if(i==1)
                                       type=40;
                                    L2=Lcreateentry($3->name,type);}
              |ID                  {if(i==0)
                                      type=30;
                                    else if(i==1)
                                       type=40;
                                    L2=Lcreateentry($1->name,type);}
             ;

MainBlock :INT MAIN '(' ')' '{' LdeclBlock BN slist RET E ';'END '}'  { 
 						             //L3=Lhead;
							    
                                                                   if($10->type!=30){
                                                                      yyerror("main function return type error\n");
                                                                      exit(1);}
                                                                   $$=makenode(0,44," ",0,$8,$10,NULL); 
                                                                   codegen($$);
                                                                   Lhead=NULL;
                                                                     printf("Complete\n");   } 
           |INT MAIN '(' ')' '{' LdeclBlock BN END '}'                { //L3=Lhead;
           							$$=makenode(0,48," ",0,NULL,NULL,NULL);
            						         codegen($$);
            						         Lhead=NULL;
            						         printf("Complete\n");}
          ;
Type    : INT   {i=0;}      
         |BOOL  {i=1;}   
           ;

slist : stmt slist                                   {$$=makenode(0,0," ",0,$1,$2,NULL);}
       |stmt                                         {$$=$1;}
        ;

stmt  : ID '=' E ';'                       { 
                                            L1=Llookup($1->name);
                                              if(L1==NULL){
				              A2=A1;
				              while(A2!=NULL){
						   if(strcmp(A2->name,$1->name)==0){
						        type=A2->type;
						        break;}
						   A2=A2->next;
						    }
					     if(A2==NULL){
						  $1->Lentry=NULL;
						  temp=Glookup($1->name);
						  $1->Gentry=temp;
					        }
					     if(A2==NULL&&temp==NULL){
						  yyerror("Hi conflict : Undeclared variable");
						  exit(1);
					        }
					     else if(temp!=NULL){
						 type=temp->type;
						}}
				       else{
					     $1->Lentry=L1;  
					     type=L1->type;           
					     $1->Gentry=NULL;
					     temp=NULL;}
			               if(type!=$3->type){
				               yyerror("conflicts in assign2");
				               exit(1);
                                               }
                                          $$=makenode(0,12," ",0,$1,$3,NULL);
                                                 }
        |ID '[' E ']' '=' E ';'               { temp=Glookup($1->name);
                                                if(temp==NULL){
                                                     yyerror("array not declared");exit(1);}
                                                else if(temp->type==30||temp->type==40){
                                                     yyerror("conflict in nodetype");exit(1);}
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
                                               $$=makenode(0,21," ",0,$1,$3,$6);
                                               }
        |RE '(' ID ')' ';'                    { L1=Llookup($3->name);
                                                if(L1==NULL){
						A2=A1;
					       while(A2!=NULL){
						 if(strcmp(A2->name,$3->name)==0){
						        type=A2->type;
						        break;}
						   A2=A2->next;
						    }
					          if(A2==NULL){
						    $3->Lentry=NULL;
						    temp=Glookup($3->name);
						    $3->Gentry=temp;
					             }
					          if(A2==NULL&&temp==NULL){
						   yyerror("conflict : Undeclared variable ");
						   exit(1);
					             }
					          else if(temp!=NULL){
						 type=temp->type;
					        
						}}
				            else{
					        $3->Lentry=L1;  
					        type=L1->type;           
					        $3->Gentry=NULL;
					        temp=NULL;}
					   if(type==31||type==41){
						yyerror("conflict : type");
						exit(1);}
					   else {
						 $3->type=type;
					        }
					   $$=makenode(0,3," ",0,$3,NULL,NULL);
					}
        |RE '('ID '[' E ']' ')' ';'        { temp=Glookup($3->name); 
				         if(temp==NULL){
				             yyerror("array not declared");exit(1);}
				         else if(temp->type==30||temp->type==40){
				             yyerror("array type invalid");exit(1);}
				         else if($5->type==40){
				             yyerror("conflict in read");}
				          else{
			                      $$=makenode(0,22," ",0,$3,$5,NULL);
			                      $3->Gentry=temp;
			                      $3->Lentry=NULL;
			                      if(temp->type==31)
			                          $3->type=31;
			                      else if(temp->type==41)
			                          $3->type=41;
                                                 }}
        |WR '(' E ')' ';'                                {$$=makenode(0,4," ",0,$3,NULL,NULL);}
        |IF '(' E ')' THEN slist  ELSE  slist ENDIF  ';' {if($3->type!=40){
                                                           yyerror("conflict in ifelse");
                                                           exit(1);}
                                                          $$=makenode(0,17," ",0,$3,$6,$8);
                                                          }
                                                        
        |WHILE '(' E ')' DO  slist  ENDWHILE ';'        {if($3->type!=40){
                                                             yyerror("conflict in while");
                                                             exit(1);}
                                                         $$=makenode(0,18," ",0,$3,$6,NULL);}
                                                        
        |IF '(' E ')' THEN  slist ENDIF  ';'          {if($3->type!=40){
                                                            yyerror("conflict in if");exit(1);
                                                        }
                                                       $$=makenode(0,19," ",0,$3,$6,NULL);
                                                      }
        ;
        
E  :  E '+' E                { if($1->type==30&&$3->type==30){
		                  $$=makenode(30,5," ",0,$1,$3,NULL);}
		            else{
		                  yyerror("conflicting types in addition\n");
		                  exit(1);
                                  }}
     |E '*' E                { if($1->type==30&&$3->type==30){
		                  $$=makenode(30,7," ",0,$1,$3,NULL);
		            }
		            else{
		                  yyerror("conflicting types in multiplication");
		                  exit(1);
                             }}
     |E '-' E               { if($1->type==30&&$3->type==30){
		                  $$=makenode(30,6," ",0,$1,$3,NULL);
		            }
		            else{
		                  yyerror("conflicting types in subtraction");
		                  exit(1);
                               }}
     |E '/' E                {if($1->type==30&&$3->type==30){
		                  $$=makenode(30,8," ",0,$1,$3,NULL);
		            }
		            else{
		                  yyerror("conflicting types in division");
		                  exit(1);
                             }}
     |E '<' E               {if($1->type==30&&$3->type==30){
		                  $$=makenode(40,15," ",0,$1,$3,NULL);
		            }
		            else{
		                  yyerror("conflicting types in lesserthan");
		                  exit(1);
                             }}
     |E '>' E               {if($1->type==30&&$3->type==30){
		                   $$=makenode(40,16," ",0,$1,$3,NULL);
		            }
		            else{
		                   yyerror("conflicting types in greaterthan");
		                   exit(1);
                            }}
     |E ISEQ E              {if($1->type==30&&$3->type==30){
		                   $$=makenode(40,32," ",0,$1,$3,NULL);
		            }
		            else{
		                  yyerror("conflicting types in not equalto");
		                  exit(1);
                             }}
     |E NEQ E                 {if($1->type==30&&$3->type==30){
		                  $$=makenode(40,60," ",0,$1,$3,NULL);}
		            else{
		                  yyerror("conflicting types in not equalto");
		                  exit(1);
                                }}                       
     |E AND E                {if($1->type==40&&$3->type==40){
		                 $$=makenode(40,30," ",0,$1,$3,NULL);}
		            else{
		            yyerror("conflicting types in AND");
		            exit(1);
                           }}
     |E OR E               {if($1->type==40&&$3->type==40){
		              $$=makenode(40,31," ",0,$1,$3,NULL);}
		            else{
		              yyerror("conflicting types in OR");
		              exit(1);
                           }}
     |E LE E                { if($1->type==30&&$3->type==30){
		                $$=makenode(40,33," ",0,$1,$3,NULL);}
		             else{
		                yyerror("conflicting types in less than or equalto");
		                exit(1);
                              }}
     |E GE E               { if($1->type==30&&$3->type==30){
		               $$=makenode(40,34," ",0,$1,$3,NULL);}
		            else{
		               yyerror("conflicting types in greater than or equalto");
		               exit(1);
                              }}
     |'(' E ')'            {$$=$2;}
     |ID '(' ')'           {  temp=Glookup($1->name);
     			   if(temp==NULL){
				yyerror("Function not declared");
				exit(1);}
	                      A2=temp->list;
		            if(A2!=NULL||T2!=NULL){
                                yyerror("Error in count of arguments\n");
                                exit(1);
                              }
                              $$=makenode($1->type,37," ",0,$1,NULL,NULL);}
     |ID  '(' Args ')'      {  
                              temp=Glookup($1->name);
     			   if(temp==NULL){
				yyerror("Function not declared");
				exit(1);}
		            type=temp->type;
		            A2=temp->list;
		            T2=$3;
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
                              printf("Error in count of Arguments\n");
                              printf("J\n");
                              exit(5);
                              }
                             
                            $$=makenode(type,38," ",0,$1,$3,NULL);
                            }
     |NUM                  {$$=$1;}
     |ID                   { 
                         L1=Llookup($1->name);
                         temp=NULL;
		       if(L1==NULL){
		                  A2=A1;
		              while(A2!=NULL){
		                     if(strcmp(A2->name,$1->name)==0){
		                          type=A2->type;
		                          break;}
		                     A2=A2->next;}
		              if(A2==NULL){
		                    $1->Lentry=NULL;
		                    temp=Glookup($1->name);
		                    $1->Gentry=temp;
		                 }
		              if(A2==NULL&&temp==NULL){
		                    yyerror("Hi conflict : Undeclared variable");
		                    exit(1);
		                 }
		              if(temp!=NULL){
		                   type=temp->type;
		                  }}
		      else{ 
		                $1->Lentry=L1;  
		                 type=L1->type;           
		                 $1->Gentry=NULL;
		                 temp=NULL;}
		                 
		                
		      if(type==31||type==41){
		                 yyerror("conflict : type");
		                 exit(1);}
		      else {
		                 $1->type=type;
		                 }
		       
		         
		      $$=$1;
		               }
     |ID '[' E ']'        { temp=Glookup($1->name);
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
     |T                {$$=makenode(40,28," ",1,NULL,NULL,NULL);}
     |F                {$$=makenode(40,29," ",0,NULL,NULL,NULL);}
     ;
Args : Args ',' E         {$$=makenode(0,35," ",0,$1,$3,NULL);}  
      |E                  {$$=makenode(0,36," ",0,NULL,$1,NULL);}
      ;                        
%%


int yyerror(char const *s){
      printf("Error hi %s\n",s);
      printf("Hello\n");
      exit(1);
}

int main(int argc,char*argv[]){
      if(argc==2){
	yyin=fopen(argv[1],"r");}
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

