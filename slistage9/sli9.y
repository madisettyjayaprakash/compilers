%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ArgStruct*A1,*A2;
struct Gsymbol *temp;
struct Lsymbol *L2,*L1,*L3;
struct Tnode*T1,*T2;
FILE *yyin;
int i=-1,b,sptr=4096,xyz=0,fst=0;
char *lt,cmp[8][30],cmp1[8][30],nm[100];
#include "symtbl.h"
#include "sliexptree.h"
#include "sliexptree.c"
#include "symtbl.c"
//#include"codegen8.c"
#define YYSTYPE Tnode*
%}

%token  ID NUM RE WR IF ELSE ENDIF WHILE THEN DO ENDWHILE ISEQ  BN END INT BOOL DECL ENDDECL  GEQ NEQ LEQ T F AND
        OR LE GE RET MAIN TYPE ENDTYPE ALLOC VOID INITIALIZE FREE NUL
%left '+' '-'
%left '*' '/'
%right '='
%nonassoc '<' '>' LEQ GEQ ISEQ NEQ AND OR LE GE
%%



Program :TypeDefBlock GdeclBlock FdefBlock MainBlock  {}
          |TypeDefBlock FdefBlock MainBlock        {}
          |GdeclBlock FdefBlock MainBlock          {}
          |GdeclBlock MainBlock                     {}
          |MainBlock                                  {}
          |TypeDefBlock GdeclBlock MainBlock  {}
          |FdefBlock MainBlock 
          |TypeDefBlock MainBlock                 {}
         ;

TypeDefBlock  : TYPE TypeDefList ENDTYPE          { /*TT2=TThead; 
                                                      printf("Complete\n");
                                                    while(TT2!=NULL){
                                                      printf("%s\n",TT2->name);
                                                      while(TT2->fields!=NULL){
                                                    printf("%s %s\n",TT2->fields->name,TT2->fields->type->name);
                                                        TT2->fields=TT2->fields->next;
                                                       }
                                                       TT2=TT2->next;
                                                     } */
                                                       }            
              ;         
TypeDefList   : TypeDefList TypeDef
              | TypeDef
              ;
TypeDef       : ID '{' FieldDeclList '}'   {  
                                             int z=0;
                                             if(xyz!=0)
                                             {
                                             for(z=0;z<xyz;z++)
                                             {
                                                 if( (strcmp(cmp[z],$1->name)==0) )
                                                {
                                                  if(z==0)
                                                  {
                                                    TInstall($1->name,cf+xyz,FHead);
                                                  }
                                                  TT2=TLookup($1->name);
                                                  FInstall(TT2,cmp1[z]);
                                               }
                                               else{
                                                    yyerror("type not defined");
                                                    exit(1);}
                                              }
                                              }
                                              else
                                              { TInstall($1->name,cf,FHead);
                                              }
                                                    
                                                xyz=0;    
                                               cf=0;
                                               FHead=NULL;
                                           }
              ;
FieldDeclList : FieldDeclList FieldDecl   {}
              | FieldDecl
              ;                                    

FieldDecl    : Type1 ID ';'               {
                                          if(TT2!=NULL)
                                             FInstall(TT2,$2->name);
                                          else{
                                            strcpy(cmp1[xyz],$2->name);
                                            xyz=xyz+1;}
                                            }
             ;

Type1    : INT   {TT2=TLookup("int");}      
         |BOOL  {TT2=TLookup("bool");}
         |VOID  {TT2=TLookup("void");}
         |ID    {TT2=TLookup($1->name);
                  if(TT2==NULL)
                     strcpy(cmp[xyz],$1->name);
                  }   
           ;
 
GdeclBlock : DECL Gdecllist ENDDECL        {     /*  temp=Ghead;
                                                  printf("Complete1\n");
                                               while(temp!=NULL){
	                                              printf("%s ",temp->name);
	                                              printf("%d ",temp->argcount);
	                                              printf("%s ",temp->type->name);
	                                              if(temp->list!=NULL){
	                                                  A1=temp->list;
	                                              while(A1!=NULL){
	                                                  printf("%s ",A1->name);
	                                                  printf("%s ",temp->type->name);
	                                                  A1=A1->next;
	                                               }}
                                               printf("\n");
                                               temp=temp->next;
                                             }*/
                                              //inter_codegen();
                                           }
            | DECL ENDDECL
            ;
Gdecllist : Gdecllist Gdecl
            |Gdecl
            ;
Gdecl    :Type Gidlist ';'                {}
          ;
Gidlist :Gidlist ',' Gid
        |Gid
           ;
Gid :  ID                             {
		                      type1=TT2;
		                      temp=Gcreateentry($1->name,type1,1,NULL); 
		                     }
       |ID '[' NUM ']'        {
                               type1=TT2;
                               temp=Gcreateentry($1->name, type1,$3->value,NULL);}
       |ID '(' Paramlist ')'  {
                               type1=TT2;
                               temp=Gcreateentry($1->name, type1,-1,Ahead);
                               argc=0;
                               Ahead=NULL;}
      ; 
Paramlist : Paramlist ',' Plist   {}
           |Plist                 {}
           ;
Plist    :Type2 ID             {
                               type1=TT3;
                               Ahead=Aentry($2->name,type1);}
           ;

Type2  : INT    {TT3=TLookup("int");}      
         |BOOL  {TT3=TLookup("bool");}
         |VOID  {TT3=TLookup("void");}
         |ID    {TT3=TLookup($1->name);
                  if(TT3==NULL){
                   yyerror("No type\n");
                   }
                     
                  }   
           ;

FdefBlock : FdefBlock Fdef
           |Fdef
           ;
Fdef     :Type ID '(' Arglist ')' '{' LdeclBlock BN slist RET E ';'END '}'  {
                                                                temp=Glookup($2->name);
                                                                if(temp->type!=$11->type){
                                                                   yyerror("function return type error\n");
                                                                   exit(1);
                                                                }  
                                                               semfuncheck($2->name,Ahead);
                                                         $$=makenode(TLookup("void"),45,$2->name,0,$9,$11,NULL);
                                                               A1=Ahead;
                                                               //codegen($$);
                                                               Ahead=NULL;
                                                               Lhead=NULL; 
                                                               }
                                                               
         |Type ID '(' Arglist ')' '{' LdeclBlock BN END '}'   {
                                                              semfuncheck($2->name,Ahead);
                                                        $$=makenode(TLookup("void"),46,$2->name,0,NULL,NULL,NULL);
                                                              A1=Ahead;
                                                              //codegen($$);
                                                              Ahead=NULL;
                                                              Lhead=NULL;}
        
        
         |Type ID '(' ')' '{'   LdeclBlock BN slist RET E ';'END '}'  { 
                                                                temp=Glookup($2->name);
                                                                if(temp->type!=$10->type){
                                                                   yyerror("function return type error\n");
                                                                   exit(1);
                                                                }  
                                                               semfuncheck($2->name,Ahead);
                                                           $$=makenode(TLookup("void"),51,$2->name,0,$8,$10,NULL);
                                                               A1=Ahead;
                                                              // codegen($$);
                                                               Ahead=NULL;
                                                               Lhead=NULL;  }
          
          
          ;
Arglist  :Arglist ',' Arg
         |Arg
         ;
Arg    : Type ID                           {
                                           type1=TT2;
                                           A1=Aentry($2->name,type1);
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
Lidlist     :Lidlist ',' ID        {
                                    type1=TT2;
                                    L2=Lcreateentry($3->name,type1);
                                   }
              |ID                  {
                                    type1=TT2;
                                    L2=Lcreateentry($1->name,type1);
                                    }
             ;

MainBlock :INT MAIN '(' ')' '{' LdeclBlock BN slist RET E ';'END '}'  { 
                                                                   if($10->type!=TLookup("int")){
                                                                      yyerror("main function return type error\n");
                                                                      exit(1);}
                                                              $$=makenode(TLookup("void"),44," ",0,$8,$10,NULL); 
                                                                  // codegen($$);
                                                                   Lhead=NULL;
                                                                   printf("Completed\n");
                                                                    } 
           |INT MAIN '(' ')' '{' LdeclBlock BN END '}'                { 
           					     $$=makenode(TLookup("void"),48," ",0,NULL,NULL,NULL);
            						        // codegen($$);
            						         Lhead=NULL;
            						         printf("Completed\n");}
          ;

Type    : INT   {TT2=TLookup("int");}      
         |BOOL  {TT2=TLookup("bool");}
         |VOID  {TT2=TLookup("void");}
         |ID    {TT2=TLookup($1->name);
                  if(TT2==NULL){
                   yyerror("No type\n");
                   }
                     
                  }   
           ;

slist : stmt slist                                   {TT2=TLookup("void");
                                                      $$=makenode(TT2,0," ",0,$1,$2,NULL);}
       |stmt                                         {$$=$1;}
        ;

stmt  : ID '=' E ';'                       { //printf("in id=e\n");
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
						  $1->Gentry=temp;
					        }
					    }
				       else{
					     $1->Lentry=L1;  
					     type=L1->type;           
					     $1->Gentry=NULL;
					     temp=NULL;}
			 		     //printf("%s\n",type->name);
		                 if($3->type==TLookup("void")&&(type!=TLookup("int")) ){
				            yyerror("conflicts in assign3");
				            exit(1);
				        } 
				    if($3->type!=TLookup("void")){
			              if(type!=$3->type){
				       yyerror("conflicts in assign4");
				       exit(1);
                                               }}
                                       TT2=TLookup("void");
                                      $$=makenode(TT2,12," ",0,$1,$3,NULL);
                                            fst=0;     }
        |ID '[' E ']' '=' E ';'               { temp=Glookup($1->name);
                                                if(temp==NULL){
                                                     yyerror("array not declared");exit(1);}
                                                else if(temp->size==1){
                                                     yyerror("conflict in nodetype");exit(1);}
                                                else{
				                 $$=makenode(TLookup("void"),21," ",0,$1,$3,$6);
				                 $1->Gentry=temp;
                                                     }
				           if($1->type!=$6->type){
				               yyerror("conflicts in assign2");
				               exit(1);
                                               }
                                              fst=0; }
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
						    $3->Gentry=temp;
					             }
					    }
				            else{
					        $3->Lentry=L1;  
					        type=L1->type;           
					        $3->Gentry=NULL;
					        temp=NULL;}
					   
				           $3->type=type;
					   $$=makenode(TLookup("void"),3," ",0,$3,NULL,NULL);
					//printf("after read\n");
					}
        |RE '('ID '[' E ']' ')' ';'        { temp=Glookup($3->name); 
				         if(temp==NULL){
				             yyerror("array not declared");exit(1);}
				         else if(temp->size==1){
				             yyerror("array type invalid");exit(1);}
				         else if($5->type!=TLookup("int")){
				             yyerror("conflict in read");}
				          else{
			                      $$=makenode(TLookup("void"),22," ",0,$3,$5,NULL);
			                      $3->Gentry=temp;
			                      $3->Lentry=NULL;
			                      $3->type=temp->type;
                                                 }
                                                 fst=0;}
        |WR '(' E ')' ';'                                {$$=makenode(TLookup("void"),4," ",0,$3,NULL,NULL);
                                                             fst=0;}
        |IF '(' E ')' THEN slist  ELSE  slist ENDIF  ';' {if($3->type!=TLookup("bool") ){
                                                           yyerror("conflict in ifelse");
                                                           exit(1);}
                                                          $$=makenode(TLookup("void"),17," ",0,$3,$6,$8);
                                                          fst=0;}
                                                        
        |WHILE '(' E ')' DO  slist  ENDWHILE ';'        {if($3->type!=TLookup("bool")){
                                                             yyerror("conflict in while");
                                                             exit(1);}
                                                         $$=makenode(TLookup("void"),18," ",0,$3,$6,NULL);
                                                         fst=0;}
                                                        
        |IF '(' E ')' THEN  slist ENDIF  ';'          {if($3->type!=TLookup("bool")){
                                                            yyerror("conflict in if");exit(1);
                                                        }
                                                       $$=makenode(TLookup("void"),19," ",0,$3,$6,NULL);
                                                     fst=0; }
        |ID '=' ALLOC'(' ')' ';'         {// printf("in id=alloc();\n");
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
						  $1->Gentry=temp;
					        }
					    }
				       else{
					     $1->Lentry=L1;  
					     type=L1->type;           
					     $1->Gentry=NULL;
					     temp=NULL;}
                                          TT2=TLookup("void");
                                          $$=makenode(TT2,57," ",0,$1,NULL,NULL);} 
        
                           
        |Field '=' E ';'              {//printf("in field=e\n");
                                       
                                       $$=makenode(TLookup("void"),58," ",0,$3,NULL,NULL);    
                                        flisthead=flist3;
                                             strcpy(nm,flist3->name);
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
	                                               $$->Lentry=NULL;
	                                               temp=Glookup(nm);
	                                               if(temp==NULL){
	                                               yyerror("Hi conflict2 : Undeclared variable");
	                                               exit(1);
	                                               }
	                                              type=temp->type;
	                                               $$->Gentry=temp;
	                                            }
	                                         
	                                       }
	                                    else{ 
	                                            $$->Lentry=L1;  
	                                            type=L1->type;           
	                                            $$->Gentry=NULL;
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
                                                //printf("ghi %s\n",flist3->next->name);
                                                Ft2=FLookup(type,flist3->next->name);
                                                if(Ft2==NULL){
                                                   yyerror("Field not declared");
                                                   exit(1);
                                                  }
                                                  type=Ft2->type;
                                                  flist3=flist3->next;
                                                  flist3->type=type;
	                                         FHead=type->fields;
                                              }
                                        // printf("H1 %s %s\n",type->name,$3->type->name);
                                      if(type!=$3->type){
                                       yyerror("conflict in assigning types");
                                       exit(1);
                                      }
                                     
                                     $$->typeentry=flisthead;
                                     flisthead=NULL;
                                      fst=0;
                              }
        
        
        |Field '=' ALLOC'(' ')' ';'  {
                                        $$=makenode(TLookup("void"),59," ",0,NULL,NULL,NULL);
                                       flisthead=flist2;
                                             strcpy(nm,flist2->name);
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
	                                               $$->Lentry=NULL;
	                                               temp=Glookup(nm);
	                                               if(temp==NULL){
	                                               yyerror("Hi conflict : Undeclared variable");
	                                               exit(1);
	                                               }
	                                              type=temp->type;
	                                               $$->Gentry=temp;
	                                            }
	                                         
	                                       }
	                                    else{ 
	                                            $$->Lentry=L1;  
	                                            type=L1->type;           
	                                            $$->Gentry=NULL;
	                                            temp=NULL;}
	                                     flist2->type=type;
	                                     FHead=type->fields;
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
                                        
                                       $$->typeentry=flisthead;
                                       flisthead=NULL;
                                       fst=0;
                                       }
        |FREE '(' ID ')' ';'       {
                                       L1=Llookup($3->name);
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
						    $3->Gentry=temp;
					             }
					          
					    }
				            else{
					        $3->Lentry=L1;  
					        type=L1->type;           
					        $3->Gentry=NULL;
					        temp=NULL;}
					   
				           $3->type=type;
					   $$=makenode(TLookup("void"),61," ",0,$3,NULL,NULL);
                                    }
          
        |FREE '(' Field ')' ';'    {
                                      $$=makenode(TLookup("void"),62," ",0,NULL,NULL,NULL);
                                      flisthead=flist2;
                                             strcpy(nm,flist2->name);
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
	                                               $$->Lentry=NULL;
	                                               temp=Glookup(nm);
	                                               if(temp==NULL){
	                                               yyerror("Hi conflict : Undeclared variable");
	                                               exit(1);
	                                               }
	                                              type=temp->type;
	                                               $$->Gentry=temp;
	                                            }
	                                         
	                                       }
	                                    else{ 
	                                            $$->Lentry=L1;  
	                                            type=L1->type;           
	                                            $$->Gentry=NULL;
	                                            temp=NULL;}
	                                     flist2->type=type;
	                                     FHead=type->fields;
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
                                       $$->typeentry=flisthead;
                                       flisthead=NULL;
                                       fst=0;
                                    }
        
        |RE '(' Field ')' ';'  { 
                                      $$=makenode(TLookup("void"),63," ",0,NULL,NULL,NULL);
                                      flisthead=flist2;
                                             strcpy(nm,flist2->name);
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
	                                               $$->Lentry=NULL;
	                                               temp=Glookup(nm);
	                                               if(temp==NULL){
	                                               yyerror("Hi conflict : Undeclared variable");
	                                               exit(1);
	                                               }
	                                              type=temp->type;
	                                               $$->Gentry=temp;
	                                            }
	                                         
	                                       }
	                                    else{ 
	                                            $$->Lentry=L1;  
	                                            type=L1->type;           
	                                            $$->Gentry=NULL;
	                                            temp=NULL;}
	                                     flist2->type=type;
	                                     FHead=type->fields;
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
                                         
                                         $$->typeentry=flisthead;
                                         flisthead=NULL;
                                          fst=0;}
                                    
        |ID '=' NUL ';'                   {    
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
						  $1->Gentry=temp;
					        }
					    }
				       else{
					     $1->Lentry=L1;  
					     type=L1->type;           
					     $1->Gentry=NULL;
					     temp=NULL;}
			               if(type==TLookup("int")||type==TLookup("bool")){
				               yyerror("conflicts in assign2");
				               exit(1);
                                               }
                                          TT2=TLookup("void");
                                           $$=makenode(TT2,64," ",0,$1,NULL,NULL);
                                                 //printf("id=null\n"); 
                                                 }
        
        |Field '=' NUL ';'               {   $$=makenode(TLookup("void"),54," ",0,NULL,NULL,NULL);
                                             flisthead=flist2;
                                             strcpy(nm,flist2->name);
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
	                                               $$->Lentry=NULL;
	                                               temp=Glookup(nm);
	                                               if(temp==NULL){
	                                               yyerror("Hi conflict : Undeclared variable");
	                                               exit(1);
	                                               }
	                                              type=temp->type;
	                                               $$->Gentry=temp;
	                                            }
	                                         
	                                       }
	                                    else{ 
	                                            $$->Lentry=L1;  
	                                            type=L1->type;           
	                                            $$->Gentry=NULL;
	                                            temp=NULL;}
	                                     flist2->type=type;
	                                     FHead=type->fields;
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
                                             
                                               if(type==TLookup("int")||type==TLookup("bool")){
                                                 yyerror("NULL assigned to wrong field\n");
                                                 exit(1);
                                                }
                                               $$->type=type;
                                               $$->typeentry=flisthead;
                                               flisthead=NULL;
                                               fst=0;}                           
        
        ;
   
E  :  E '+' E                { TT2=TLookup("bool");
                             TT3=TLookup("int");
                              if($1->type==TT3&&$3->type==TT3){
		                  $$=makenode(TT3,5," ",0,$1,$3,NULL);}
		            else{
		                  yyerror("conflicting types in addition\n");
		                  exit(1);
                                  }
                                  fst=0;}
     |E '*' E                { TT2=TLookup("bool");
                             TT3=TLookup("int");
                              if($1->type==TT3&&$3->type==TT3){
		                  $$=makenode(TT3,7," ",0,$1,$3,NULL);
		            }
		            else{
		                  yyerror("conflicting types in multiplication");
		                  exit(1);
                             }fst=0;}
     |E '-' E               { TT2=TLookup("bool");
                             TT3=TLookup("int");
                              if($1->type==TT3&&$3->type==TT3){
		                  $$=makenode(TT3,6," ",0,$1,$3,NULL);
		            }
		            else{
		                  yyerror("conflicting types in subtraction");
		                  exit(1);
                               }fst=0;}
     |E '/' E                {TT2=TLookup("bool");
                             TT3=TLookup("int");
                              if($1->type==TT3&&$3->type==TT3){
		                  $$=makenode(TT3,8," ",0,$1,$3,NULL);
		            }
		            else{
		                  yyerror("conflicting types in division");
		                  exit(1);
                             }fst=0;}
     |E '<' E               {TT2=TLookup("bool");
                             TT3=TLookup("int");
                              if($1->type==TT3&&$3->type==TT3){
		                  $$=makenode(TT2,15," ",0,$1,$3,NULL);
		            }
		            else{
		                  yyerror("conflicting types in lesserthan");
		                  exit(1);
                             }fst=0;}
     |E '>' E               {TT2=TLookup("bool");
                             TT3=TLookup("int");
                             if($1->type==TT3&&$3->type==TT3){
		                   $$=makenode(TT2,16," ",0,$1,$3,NULL);
		            }
		            else{
		                   yyerror("conflicting types in greaterthan");
		                   exit(1);
                            }fst=0;}
                            
     |E ISEQ NUL           { TT2=TLookup("bool");
                             TT3=TLookup("int");
                             if($1->type==TT2||$1->type==TT3){
                              yyerror("conflict in comparing with null");
                              exit(1);
                               } 
                             $$=makenode(TT2,65," ",0,$1,NULL,NULL);
                             fst=0;}                       
                            
     |E ISEQ E              {TT2=TLookup("bool");
                             TT3=TLookup("int");
                              if($1->type==TT3&&$3->type==TT3){
		                   $$=makenode(TT2,32," ",0,$1,$3,NULL);
		            }
		            else{
		                  yyerror("conflicting types in not equalto");
		                  exit(1);
                             }fst=0;}
     |E NEQ NUL              { TT2=TLookup("bool");
                               TT3=TLookup("int");
                             if($1->type==TT2||$1->type==TT3){
                              yyerror("conflict in comparing with null");
                              exit(1);
                               } 
                             $$=makenode(TT2,66," ",0,$1,NULL,NULL);fst=0;
                             }  
                                      
     |E NEQ E                 {TT2=TLookup("bool");
                             TT3=TLookup("int");
                              if($1->type==TT3&&$3->type==TT3){
		                  $$=makenode(TT2,60," ",0,$1,$3,NULL);}
		            else{
		                  yyerror("conflicting types in not equalto");
		                  exit(1);
                                }fst=0;}                       
     |E AND E                {TT2=TLookup("bool");
                             TT3=TLookup("int");
                              if($1->type==TT2&&$3->type==TT2){
		                 $$=makenode(TT2,30," ",0,$1,$3,NULL);}
		            else{
		            yyerror("conflicting types in AND");
		            exit(1);
                           }fst=0;}
     |E OR E               {TT2=TLookup("bool");
                             TT3=TLookup("int");
                             if($1->type==TT2&&$3->type==TT2){
		              $$=makenode(TT2,31," ",0,$1,$3,NULL);}
		            else{
		              yyerror("conflicting types in OR");
		              exit(1);
                           }fst=0;}
     |E LE E                { TT2=TLookup("bool");
                             TT3=TLookup("int");
                               if($1->type==TT3&&$3->type==TT3){
		                $$=makenode(TT2,33," ",0,$1,$3,NULL);}
		             else{
		                yyerror("conflicting types in less than or equalto");
		                exit(1);
                              }fst=0;}
     |E GE E               { TT2=TLookup("bool");
                             TT3=TLookup("int");
                              if($1->type==TT3&&$3->type==TT3){
		               $$=makenode(TT2,34," ",0,$1,$3,NULL);}
		            else{
		               yyerror("conflicting types in greater than or equalto");
		               exit(1);
                              }fst=0;}
     |'(' E ')'            {$$=$2;fst=0;}
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
     |ID  '(' Args ')'      {  //printf("name is %s\n",$1->name);
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
                              yyerror("Error in count of Arguments\n");
                              exit(1);
                              }
                            // printf("args %s\n",type->name);
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
		                    if(temp==NULL){
		                    yyerror("Hi conflict : Undeclared variable");
		                    exit(1);
		                    }
		                    if(temp->size > 1){
		                           yyerror("conflict : type");
		                           exit(1);}
		                    type=temp->type;
		                    $1->Gentry=temp;
		                 }
		              
		            }
		      else{ 
		                $1->Lentry=L1;  
		                 type=L1->type;           
		                 $1->Gentry=NULL;
		                 temp=NULL;}
		      $1->type=type;
		      $$=$1;
		               }
     |ID '[' E ']'        { temp=Glookup($1->name);
                             TT2=TLookup("bool");
                             TT3=TLookup("int");
		              if(temp==NULL){
		                 yyerror("conflict : Undeclared Array");
		                 exit(1);
		              }
		              else if(temp->size==1||temp->size==1){
		                 yyerror("conflict : type");
		                 exit(1);
		              }
		              else if($3->type==TT2){
		                  yyerror(" conflict :Expression  found boolean");
		                  exit(1);
		              }
		              else{
		               
		              $1->Gentry=temp;
		               if(temp->type==TT3)
		                 $1->type=TT3;
		               else 
		                 $1->type=TT2;
		              
		               }
                        fst=0;
                       $$=makenode($1->type,24," ",0,$1,$3,NULL);}
     |T                {TT2=TLookup("bool");$$=makenode(TT2,28," ",1,NULL,NULL,NULL);}
     |F                {TT2=TLookup("bool");$$=makenode(TT2,29," ",0,NULL,NULL,NULL);}
     |INITIALIZE '(' ')'  {$$=makenode(TLookup("void"),56,"",0,NULL,NULL,NULL);
                          // printf("initialize\n");
                           }        
     |Field            {   
                           $$=makenode(TLookup("void"),55," ",0,NULL,NULL,NULL); 
                          flisthead=flist2;
                           strcpy(nm,flist2->name);
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
		                    //$1->Lentry=NULL;
		                    temp=Glookup(nm);
		                    if(temp==NULL){
		                    yyerror("Hi conflict : Undeclared variable");
		                    exit(1);
		                    }
		                    type=temp->type;
		                    $$->Gentry=temp;
		                 }
		              
		            }
		         else{ 
		                 $$->Lentry=L1;  
		                 type=L1->type;           
		                 $$->Gentry=NULL;
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
                             $$->type=type;
                             $$->typeentry=flisthead;
                             flisthead=NULL;
                          }
     ;
Args : Args ',' E         {$$=makenode(TLookup("void"),35," ",0,$1,$3,NULL);}  
      |E                  {$$=makenode(TLookup("void"),36," ",0,NULL,$1,NULL);}
      ;         
Field  : Field1  {if(fst==0) {
                    flist3=flisthead;
                    fst++;}
                 flisthead=NULL;}      
         ;            
Field1   :Field1 '.' ID    {flist2=makelistfield($3);}
        |ID '.' ID         {flist2=makelistfield($1);
                            flist2=makelistfield($3);}
        ;

%%


int yyerror(char const *s){
      printf("Error %s\n",s);
    
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

