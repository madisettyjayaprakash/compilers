%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"label.c"
char b[30],f,c[10],h[10];
int x=0,k=0,s1=0;
int c1=2048;
FILE *fp;
%}


letter   [A-Z a-z]
number   [0-9]
colon    [:]
newln     [\n]
space     [ ]
comma    [,]
minus    [-]
lpara      "["
rpara      "]"
quot        ["]
%%

({number}+){newln}                                   { if(k==0)
                                                           c1+=1;
                                                         
                                                       if(k==1&&s1!=1){
                                                         
                                                           fprintf(fp,"%s",yytext);}
                                                       else if(s1==1){
                                                           s1=0;
                                                             
                                                                     }}
                                                           
({letter}*)({number}+){colon}{newln}                    { if(k==0){              //L3:
                                                            // printf("%s %d",yytext,c1);
                                                           q=lookup(yytext);
                                                          if(q==NULL)
                                                           t1=createlabel(yytext,c1);} 
                                                           if(k==1){}
                                                             }
                                                    
                                                     
                                                      
({letter}+){colon}{newln}                            {  if(k==0){              //MAIN:
                                                          
                                                           q=lookup(yytext);
                                                        if(q==NULL)
                                                           t1=createlabel(yytext,c1);}  
                                                           
                                                        if(k==1){}    }

"RET"{newln}                                          {  if(k==0) 
                                                            c1=c1+2;
                                                         if(k==1)
                                                            fprintf(fp,"%s",yytext);}
"BRKP"{newln}                                          {  if(k==0) 
                                                            c1=c1+2;
                                                         if(k==1)
                                                            fprintf(fp,"%s",yytext);}
                                                                                       
"INT"{space}{number}*                                  {               if(k==0)
                                                                         c1+=2;
                                                                       if(k==1)
                                                                      fprintf(fp,"%s",yytext); }
 
                                                  
"JMP"{space}({letter}*|{letter}*{number}*){newln}      {  if(k==0)
                                                           c1=c1+2;
                                                          if(k==1){
                                                           q=lookup(yytext+4);
                                                           x=q->address;
                                                           yyless(4);
                                                           s1=1;
                                                           fprintf(fp,"%s%d\n",yytext,x);
                                                            }                            } 
"JZ"{space}({letter}{number}){comma}({letter}*|{letter}*{number}*){newln}    {  if(k==0)
                                                                                   c1=c1+2;
                                                                                if(k==1){
                                                                                   q=lookup(yytext+6);
                                                                                   x=q->address;
                                                                                   yyless(6);
                                                                                   s1=1;
                                                                                   fprintf(fp,"%s%d\n",yytext,x);
                                                                              }}
"JNZ"{space}({letter}{number}){comma}({letter}*|{letter}*{number}*){newln}   {  if(k==0)
                                                                                   c1=c1+2;
                                                                                if(k==1){
                                                                                   q=lookup(yytext+7);
                                                                                   x=q->address;
                                                                                   yyless(7);
                                                                                   s1=1;
                                                                                   fprintf(fp,"%s%d\n",yytext,x);
                                                                              }}                                                          

"CALL"{space}"0"{newln}                                                    {if(k==0)
                                                                                   c1=c1+2;
                                                                            if(k==1)
                                                                                   fprintf(fp,"%s",yytext); }


"CALL"{space}(({letter}*{number}*)|{letter}*){newln}                           {  if(k==0)
                                                                                   c1=c1+2;
                                                                                if(k==1)
                                                                               {
                                                                                 q=lookup(yytext+5);
                                                                                 x=q->address;
                                                                                 yyless(5);
                                                                                 s1=1;
                                                                                 fprintf(fp,"%s%d\n",yytext,x);
                                                                                }}
  
                                                             
({letter}+){space}(({letter}+)|{letter}*{number}*){newln}         {    if(k==0)    //PUSH R0
                                                                         c1+=2;
                                                                       if(k==1)
                                                                      fprintf(fp,"%s",yytext);
                                                          }  

                                                                                                             
({letter}+){space}(({letter}+)|{letter}*{number}*){comma}({quot}*{minus}*{letter}*{number}*{quot}*){newln}                                                         {           if(k==0)
                                                                                c1+=2;          //MOV RO,"Read"
                                                                            if(k==1)
                                                                                fprintf(fp,"%s",yytext);
                                                          }  
                                                       
                                                    

({letter}+){space}{lpara}({number}*|{letter}*{number}*|{letter}*){rpara}{comma}(({letter}+)|{minus}*{letter}*{number}*){newln}                                                         {   if(k==0)
                                                                       c1+=2;          //MOV [4096],R0
                                                                    if(k==1)
                                                                       fprintf(fp,"%s",yytext);
                                                          }
                                                     

({letter}+){space}(({letter}+)|{minus}*{letter}*{number}*){comma}{lpara}({number}*|{letter}*{number}*|{letter}*){rpara}{newln}                                                    {    if(k==0)
                                                                 c1+=2;               //MOV R0,[4096]
                                                                if(k==1)
                                                                    fprintf(fp,"%s",yytext);
                                                          }                                                                   

{newln}                                                      {}
.                                                           {
                                                              
                                                             // printf("%s %d\n",yytext,k);
                                                              
                                                            }

%%

int yywrap(){
   if(k==0){
   /*  q=head;
       while(q!=NULL){
          printf("%s %d\n",q->name,q->address);
          q=q->next;
        }*/
   
       yyin=fopen(h,"r");
       fp=fopen("/home/jayaprakash21/xsm_expl/tar.xsm","w");
       k=1;
       return 0;
   }
  else
    return 1;
}


int main(int argc,char*argv[]){
head=NULL;
 if(argc==2)
   yyin=fopen(argv[1],"r");
   
 strcpy(h,argv[1]);  
 yylex();



return 0;

}
