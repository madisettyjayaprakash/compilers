int counter=-1,label=-1;
FILE *fp;
struct Lsymbol*L4;
struct Gsymbol*temp;
struct ArgStruct *A4;
int s,step=0;
int getreg(){
  if(counter<20)
    return ++counter;

}
int freereg(){
 if(counter>=0)
   return counter--;
}
int getlabel(){
   return ++label;
}
int freeallreg(){
  counter=-1;
}
void inter_codegen(){
 int x=2056,z=0;
 fp=fopen("l1.txt","w+");
 if(fp==NULL){
    printf("Unable to allocate file\n");
    exit(1);
 }
 fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",z,x,z,z,z,z,z,z);
 fprintf(fp,"MOV SP,%d\n",sptr-1);
 fprintf(fp,"MOV BP,%d\n",sptr-1);
 fprintf(fp,"CALL MAIN\n");
 fprintf(fp,"MOV R0,\"Exit\"\n");
 fprintf(fp,"PUSH R0\n");
 /*fprintf(fp,"PUSH R0\n");
 fprintf(fp,"PUSH R0\n");
 fprintf(fp,"PUSH R0\n");
 fprintf(fp,"PUSH R0\n");*/
 fprintf(fp,"ADD SP,4\n");
 fprintf(fp,"CALL 0\n");
 return;
 }
int codegen(struct Tnode*t){
 int r0,r1,r2,l1,l2,offset,r3;
 if(fp==NULL){
   printf("Error while generating assembly code\n");
   exit(1);
 }
 
   switch(t->nodetype){
   
   case 44 :  { int lc=0;
                fprintf(fp,"MAIN:\n");
                fprintf(fp,"PUSH BP\n");
                fprintf(fp,"MOV BP,SP\n");
                L4=Lhead;
               // Lhead=L3;
                while(L4!=NULL){
                   lc++;
                   L4=L4->next;
                }
                fprintf(fp,"ADD SP,%d\n",lc);
                codegen(t->ptr1);
                fprintf(fp,"SUB SP,%d\n",lc);  
                r1=getreg();
                fprintf(fp,"MOV BP,[SP]\n");
                fprintf(fp,"POP R%d\n",r1);
                fprintf(fp,"RET\n");
                freereg();
                break;
                 } 
   case 0:   {codegen(t->ptr1);    //slist->stmnt slist
              codegen(t->ptr2);
              break;}
    
    case 28: {r1=getreg();                             //TRUE
              fprintf(fp,"MOV R%d,%d\n",r1,t->value);
              return r1;}   
    case 29: {r1=getreg();                             //FALSE
              fprintf(fp,"MOV R%d,%d\n",r1,t->value);
              return r1;}
    case 1 : {  int c1=0;
                r1=getreg();                             //ID
                r2=getreg();
                //Lhead=L3;
                L4=Llookup(t->name);       
                if(L4!=NULL){
                   fprintf(fp,"MOV R%d,BP\n",r2);
                   fprintf(fp,"ADD R%d,%d\n",r2,L4->index);
                   fprintf(fp,"MOV R%d,[R%d]\n",r1,r2);
                   }
                else if(L4==NULL){
		       Ahead=A1;
		       A4=A1;
		       while(A4!=NULL){
		           c1++;
		         if(strcmp(A4->name,t->name)==0){
		                       break;}  
		       A4=A4->next;
		       }
                          if(A4!=NULL){
		          fprintf(fp,"MOV R%d,BP\n",r2);
		          fprintf(fp,"SUB R%d,%d\n",r2,2);
		          fprintf(fp,"ADD R%d,%d\n",r2,c1-1);
		          fprintf(fp,"SUB R%d,%d\n",r2,step);
		          fprintf(fp,"MOV R%d,[R%d]\n",r1,r2);}
		          if(A4==NULL){
                            fprintf(fp,"MOV R%d,[%d]\n",r1,t->Gentry->binding);
                              }
		          }
               freereg();
               return r1;}
               
    case 2 : {  r1=getreg();                              //NUM
                fprintf(fp,"MOV R%d,%d\n",r1,t->value);
                return r1;}
                
    case 24 : {offset=codegen(t->ptr2);
               r1=getreg();                              //ARRAY [ E ]
               fprintf(fp,"MOV R%d,%d\n",r1,t->ptr1->Gentry->binding);
               fprintf(fp,"ADD R%d,R%d\n",r1,offset);
               fprintf(fp,"MOV R%d,[R%d]\n",offset,r1);
               freereg();
               return offset;
               }
               
    case 5 :  { //printf("in +\n");
               r1=codegen(t->ptr1);               //add
               //printf("after +1\n");
               r2=codegen(t->ptr2);
                //printf("after +2\n");
               fprintf(fp,"ADD R%d,R%d\n",r1,r2);
               freereg();
               return r1;}
    case 6 :  {r1=codegen(t->ptr1);          //sub
               r2=codegen(t->ptr2);
               fprintf(fp,"SUB R%d,R%d\n",r1,r2);
               freereg();
               return r1;}
    case 7 :   {r1=codegen(t->ptr1);           //mul
               r2=codegen(t->ptr2);
               fprintf(fp,"MUL R%d,R%d\n",r1,r2);
               freereg();
               return r1;}
     case 8 : {r1=codegen(t->ptr1);               //div
               r2=codegen(t->ptr2);
               fprintf(fp,"DIV R%d,R%d\n",r1,r2);
               freereg();
               return r1;}   
                       
     case 14 :{ r1=codegen(t->ptr1);        
               r2=codegen(t->ptr2);
               fprintf(fp,"EQ R%d,R%d\n",r1,r2);
               freereg();
               return r1;}
     case 60 :{ r1=codegen(t->ptr1);        
               r2=codegen(t->ptr2);
               fprintf(fp,"NE R%d,R%d\n",r1,r2);
               freereg();
               return r1;}          
               
               
     case 32 : {r1=codegen(t->ptr1);
               r2=codegen(t->ptr2);
               fprintf(fp,"EQ R%d,R%d\n",r1,r2);
               freereg();
               return r1;}
     case 15 : {r1=codegen(t->ptr1);
               r2=codegen(t->ptr2);
               fprintf(fp,"LT R%d,R%d\n",r1,r2);
               freereg();
               return r1;}         
     case 33 : {r1=codegen(t->ptr1);
               r2=codegen(t->ptr2);
               fprintf(fp,"LE R%d,R%d\n",r1,r2);
               freereg();
               return r1;}
               
     case 16 : {r1=codegen(t->ptr1);
               r2=codegen(t->ptr2);
               fprintf(fp,"GT R%d,R%d\n",r1,r2);
               freereg();
               return r1;}
     case 34 : {r1=codegen(t->ptr1);
               r2=codegen(t->ptr2);
               fprintf(fp,"GE R%d,R%d\n",r1,r2);
               freereg();
               return r1;}
                
     case 12 : {//printf("in id=e\n");
                int c1=0;
                r0=codegen(t->ptr2);                     //ID = E
                r1=getreg();
                L4=Llookup(t->ptr1->name);        
                if(L4!=NULL){
                   fprintf(fp,"MOV R%d,BP\n",r1);
                   fprintf(fp,"ADD R%d,%d\n",r1,L4->index);
                   fprintf(fp,"MOV [R%d],R%d\n",r1,r0);
                   }
                else if(L4==NULL){
		       Ahead=A1;
		       A4=A1;
		       while(A4!=NULL){
		         c1++;
		         if(strcmp(A4->name,t->name)==0){
		                       break;}  
		         A4=A4->next;
		       }
                          if(A4!=NULL){
		          fprintf(fp,"MOV R%d,BP\n",r1);
		          fprintf(fp,"SUB R%d,%d\n",r1,2);
		          fprintf(fp,"ADD R%d,%d\n",r1,c1-1);
		          fprintf(fp,"SUB R%d,%d\n",r1,step);
		          fprintf(fp,"MOV [R%d],R%d\n",r1,r0);
		          }
		          if(A4==NULL){
                            fprintf(fp,"MOV [%d],R%d\n",t->ptr1->Gentry->binding,r0);
                            }
		          }
                  freereg();
                  freereg();
                  break;}         
     case 21 : {                                         // ID [ E ] = E
                r1=codegen(t->ptr2);
                r2=getreg();
                fprintf(fp,"MOV R%d,%d\n",r2,t->ptr1->Gentry->binding);
                fprintf(fp,"ADD R%d,R%d\n",r1,r2);
                freereg();
                r2=codegen(t->ptr3);
                 fprintf(fp,"MOV [R%d],R%d\n",r1,r2);
                 freereg();
                 freereg();
                 break;
                }
     case 3 : { //printf("read\n");
     		int c2,c1=0;
                for(s=0;s<=counter;s++)
                { fprintf(fp,"PUSH R%d\n",s);}
                c2=counter;
                freeallreg();
               r0=getreg();
               r1=getreg();                       //read
                 //Lhead=L3;
                L4=Llookup(t->ptr1->name);
                if(L4!=NULL){
                     //printf("ghj1\n");
                  // printf("%s\n",L4->name);
                   fprintf(fp,"MOV R%d,BP\n",r0);
                   fprintf(fp,"ADD R%d,%d\n",r0,L4->index);
                   }
                else if(L4==NULL){
		       Ahead=A1;
		       A4=A1;
		       while(A4!=NULL){
		        c1++;
		         if(strcmp(A4->name,t->name)==0){
		                       break;}  
		       A4=A4->next;
		       }
                          if(A4!=NULL){
                          // printf("ghj2\n");
		          fprintf(fp,"MOV R%d,BP\n",r0);
		          fprintf(fp,"SUB R%d,%d\n",r0,2);
		          fprintf(fp,"ADD R%d,%d\n",r0,c1-1);
		          fprintf(fp,"SUB R%d,%d\n",r0,step);
		          }
		          if(A4==NULL){
                            fprintf(fp,"MOV R%d,%d\n",r0,t->ptr1->Gentry->binding);
                             }
		          }
               fprintf(fp,"MOV R%d,\"Read\"\n",r1);
               fprintf(fp,"PUSH R%d\n",r1);
               fprintf(fp,"MOV R%d,-1\n",r1);
               fprintf(fp,"PUSH R%d\n",r1);
               fprintf(fp,"PUSH R%d\n",r0);          //arg2~read
               fprintf(fp,"MOV R%d,-1\n",r1);
               fprintf(fp,"PUSH R%d\n",r1);
               fprintf(fp,"PUSH R%d\n",r1);
               fprintf(fp,"CALL 0\n");
               fprintf(fp,"SUB SP,5\n");
               freereg();
               freereg();
               counter=c2;
               for(s=counter;s>=0;s--)
                { fprintf(fp,"POP R%d\n",s);}
               break; }  
               
     case 22 : {  int c1;            //read(a[E])
                for(s=0;s<=counter;s++)
                { fprintf(fp,"PUSH R%d\n",s);}
                c1=counter;
                freeallreg();
                r1=codegen(t->ptr2);
                r2=getreg();
                fprintf(fp,"MOV R%d,%d\n",r2,t->ptr1->Gentry->binding);
                fprintf(fp,"ADD R%d,R%d\n",r1,r2);
               fprintf(fp,"MOV R%d,\"Read\"\n",r2);
               fprintf(fp,"PUSH R%d\n",r2);
               fprintf(fp,"MOV R%d,-1\n",r2);
               fprintf(fp,"PUSH R%d\n",r2);
               fprintf(fp,"PUSH R%d\n",r1);
               fprintf(fp,"MOV R%d,-1\n",r2);
               fprintf(fp,"PUSH R%d\n",r2);
               fprintf(fp,"PUSH R%d\n",r2);
               fprintf(fp,"CALL 0\n");
               /*fprintf(fp,"POP R%d\n",r1);
               fprintf(fp,"POP R%d\n",r2);
               fprintf(fp,"POP R%d\n",r2);
               fprintf(fp,"POP R%d\n",r2);
               fprintf(fp,"POP R%d\n",r2); */
               fprintf(fp,"SUB SP,5\n");           
                freereg();
                freereg(); 
                counter=c1;
                for(s=counter;s>=0;s--)
                { fprintf(fp,"POP R%d\n",s);}
                  
                break;
               }         
     case 4 : { printf(" in write\n");
     		int c1;
               for(s=0;s<=counter;s++)
               { fprintf(fp,"PUSH R%d\n",s);}             //write(E)
               c1=counter;
               freeallreg();
               r1=codegen(t->ptr1); 
               r2=getreg();
               fprintf(fp,"PUSH R%d\n",r1);
               fprintf(fp,"MOV R%d,SP\n",r1);
               fprintf(fp,"MOV R%d,\"Write\"\n",r2);
               fprintf(fp,"PUSH R%d\n",r2);
               fprintf(fp,"MOV R%d,-2\n",r2);
               fprintf(fp,"PUSH R%d\n",r2);
               fprintf(fp,"PUSH R%d\n",r1);
               fprintf(fp,"MOV R%d,0\n",r2);
               fprintf(fp,"PUSH R%d\n",r2);
               fprintf(fp,"PUSH R%d\n",r2);
               fprintf(fp,"CALL 0\n");
               /*fprintf(fp,"POP R%d\n",r1);
               fprintf(fp,"POP R%d\n",r2);
               fprintf(fp,"POP R%d\n",r2);
               fprintf(fp,"POP R%d\n",r2);
               fprintf(fp,"POP R%d\n",r2);
               fprintf(fp,"POP R%d\n",r2);*/
               fprintf(fp,"SUB SP,6\n");
               freereg();
               freereg();
               counter=c1;
               for(s=counter;s>=0;s--)
                { fprintf(fp,"POP R%d\n",s);}
                // fprintf(fp,"BRKP\n");
               break;}   
     case 19 :{r1=codegen(t->ptr1);
              l1=getlabel();
              fprintf(fp,"JZ R%d,L%d\n",r1,l1);
              freereg();
              codegen(t->ptr2);
              fprintf(fp,"L%d:\n",l1);
              break;}
     case 17 : {r1=codegen(t->ptr1);
                l1=getlabel();
                l2=getlabel();
                fprintf(fp,"JZ R%d,L%d\n",r1,l1);
                freereg();
                codegen(t->ptr2);
                fprintf(fp,"JMP L%d\n",l2);
                fprintf(fp,"L%d:\n",l1);
                codegen(t->ptr3);
                fprintf(fp,"L%d:\n",l2);
                break;
             }   
     case 18: {
               l1=getlabel();
               l2=getlabel();
               fprintf(fp,"L%d:\n",l1);
               r1=codegen(t->ptr1);
               fprintf(fp,"JZ R%d,L%d\n",r1,l2);
               freereg();
               codegen(t->ptr2);
               fprintf(fp,"JMP L%d\n",l1);
               fprintf(fp,"L%d:\n",l2);
               break;
               } 
      case 38 :{  //printf("In args\n");
                  int c1,c2,c3;
                  struct Tnode*travrt;
                  for(s=0;s<=counter;s++)
                  {fprintf(fp,"PUSH R%d\n",s);}            //saving old state of registers
                  c1=counter;
                  freeallreg();
                  r1=getreg();
                  temp=Glookup(t->ptr1->name);
                  c2=temp->argcount;
                  travrt=t->ptr2;
                  while(c2!=0){                      //args are pushed into stack with stack top arg1
                    r1=codegen(travrt->ptr2);               //args(n,n-1,n-2,...,1) are pushed into stack
                    c2--;
                    fprintf(fp,"PUSH R%d\n",r1);
                    travrt=travrt->ptr1;
                   }
                 fprintf(fp,"PUSH R%d\n",r1);              //space for return value
                 freereg();
                 temp=Glookup(t->ptr1->name);
                 fprintf(fp,"CALL F%d\n",temp->flabel);
                 r1=getreg();
                 c2=temp->argcount;
                 c3=c2;
                fprintf(fp,"POP R%d\n",r1);                //pop return val into r1
               /* while(c2!=0){
                  fprintf(fp,"POP R%d\n",r1);              //pop arg values
                  c2--;
                }*/
                fprintf(fp,"SUB SP,%d\n",c2);
                freereg();
               counter=c1; 
                for(s=counter;s>=0;s--)
                { fprintf(fp,"POP R%d\n",s);}
                if(counter>=0)
                  c3=c3+counter+2;                //arguments count~c2, counter+1~ old registers,retval
                else
                  c3=c3+1;
                r1=getreg();
                r2=getreg();
                fprintf(fp,"MOV R%d,SP\n",r2);
                fprintf(fp,"ADD R%d,%d\n",r2,c3);
                fprintf(fp,"MOV R%d,[R%d]\n",r1,r2);   
                freereg();
                return r1;
              
      }      
    case 37:{   int c1,c2;                              //is to be done
                  for(s=0;s<=counter;s++)
                  {fprintf(fp,"PUSH R%d\n",s);}            //saving old state of registers
                 c1=counter;
                 freeallreg();
                 r1=getreg();
                 fprintf(fp,"PUSH R%d\n",r1);              //space for return value
                 freereg();
                   temp=Glookup(t->ptr1->name);
                fprintf(fp,"CALL F%d\n",temp->flabel);
                r1=getreg();
                fprintf(fp,"POP R%d\n",r1);               //pop return val into r1
                 counter=c1; 
                for(s=counter;s>=0;s--)
                { fprintf(fp,"POP R%d\n",s);}     
                freereg();
                return r1;
               }
     case 45 : {int c2=0;                              //function with arguments
                 temp=Glookup(t->name); 
                  step=temp->argcount;
                  //printf("%d\n",step);
                 fprintf(fp,"F%d:\n",temp->flabel); 
                 fprintf(fp,"PUSH BP\n");
                 fprintf(fp,"MOV BP,SP\n");
                 L4=Lhead;
                 //r1=getreg();
                 while(L4!=NULL){
                   //fprintf(fp,"PUSH R%d\n",r1);
                   c2++;
                   L4=L4->next;
                 }
                 fprintf(fp,"ADD SP,%d\n",c2);
                 //freereg();
                 codegen(t->ptr1);
                 r1=codegen(t->ptr2);
                 r2=getreg();
                 fprintf(fp,"MOV R%d,BP\n",r2);
                 fprintf(fp,"SUB R%d,%d\n",r2,2);
                 fprintf(fp,"MOV [R%d],R%d\n",r2,r1);
                 /*while(c2!=0){
                     fprintf(fp,"POP R%d\n",r1);  
                     c2--;
                 }*/
                 fprintf(fp,"SUB SP,%d\n",c2);
                 fprintf(fp,"MOV BP,[SP]\n");
                 fprintf(fp,"POP R%d\n",r1);
                 fprintf(fp,"RET\n");
                 freereg();
                 freereg();
                 break;
                  }
    case 46 :  {  int c2=0;                             //function without arguments
                 temp=Glookup(t->name); 
                   step=temp->argcount;
                 fprintf(fp,"F%d:\n",temp->flabel); 
                 fprintf(fp,"PUSH BP\n");
                 fprintf(fp,"MOV BP,SP\n");
                 L4=Lhead;
                 r1=getreg();
                 while(L4!=NULL){
                   //fprintf(fp,"PUSH R%d\n",r1);
                   L4=L4->next;
                   c2++;
                 } 
                 fprintf(fp,"ADD SP,%d\n",c2);
                 /*while(c2!=0){
                     fprintf(fp,"POP R%d\n",r1);  
                     c2--;
                 }*/
                 fprintf(fp,"SUB SP,%d\n",c2);
                 fprintf(fp,"MOV BP,[SP]\n");
                 fprintf(fp,"POP R%d\n",r1);
                 fprintf(fp,"RET\n");
                 freereg();
                 break;
                 }              
     case 35 :  {//printf("in 35\n");
                 r1=getreg();
                 //printf("%d\n",t->ptr2->nodetype);
                 r1=codegen(t->ptr2);
                 return r1;}
     case 36:   {r1=getreg();
                 // printf("%d\n",t->ptr2->nodetype);
                 r1=codegen(t->ptr2);
                 return r1;
                break;}    
     case 57 :  {  printf("in alloc\n");
                   int c1=0;
                  for(s=0;s<=counter;s++)
                 fprintf(fp,"PUSH R%d\n",s);             //ID=ALLOC();
                 c1=counter;
                 freeallreg();
                  r1=getreg();
                  fprintf(fp,"MOV R%d,\"Alloc\"\n",r1);
                  fprintf(fp,"PUSH R%d\n",r1);
               //   fprintf(fp,"PUSH 8\n");
                  fprintf(fp,"ADD SP,4\n");
                  fprintf(fp,"CALL 0\n");
                  fprintf(fp,"SUB SP,5\n");
                  freereg();
                  counter=c1;
                  for(s=counter;s>=0;s--)
                  fprintf(fp,"POP R%d\n",s);
                  r0=getreg();
                  fprintf(fp,"MOV R%d,SP\n",r0);
                  fprintf(fp,"ADD R%d,%d\n",r0,5+1+c1);
                 
                  fprintf(fp,"MOV R%d,[R%d]\n",r0,r0);
                  c1=0;
                  r1=getreg();
                L4=Llookup(t->ptr1->name);        
                if(L4!=NULL){
                   fprintf(fp,"MOV R%d,BP\n",r1);
                   fprintf(fp,"ADD R%d,%d\n",r1,L4->index);
                   fprintf(fp,"MOV [R%d],R%d\n",r1,r0);
                   }
                else if(L4==NULL){
		       Ahead=A1;
		       A4=A1;
		       while(A4!=NULL){
		         c1++;
		         if(strcmp(A4->name,t->ptr1->name)==0){
		                       break;}  
		         A4=A4->next;
		       }
                          if(A4!=NULL){
		          fprintf(fp,"MOV R%d,BP\n",r1);
		          fprintf(fp,"SUB R%d,%d\n",r1,2);
		          fprintf(fp,"ADD R%d,%d\n",r1,c1-1);
		          fprintf(fp,"SUB R%d,%d\n",r1,step);
		          fprintf(fp,"MOV [R%d],R%d\n",r1,r0);
		          }
		          if(A4==NULL){
                            fprintf(fp,"MOV [%d],R%d\n",t->ptr1->Gentry->binding,r0);
                            }
		          }
		          //fprintf(fp,"BRKP\n");
		          freereg();
		          printf("in alloc\n");
		          break;
               
               }
   case 58:  {r0=codegen(t->ptr1);          //field=E
               int var=0;
               flist3=t->typeentry;
                int c1=0;
                  r1=getreg();
                L4=Llookup(flist3->name);        
                if(L4!=NULL){
                   fprintf(fp,"MOV R%d,BP\n",r1);
                   fprintf(fp,"ADD R%d,%d\n",r1,L4->index);
                   fprintf(fp,"MOV R%d,[R%d]\n",r1,r1);
                   }
                else if(L4==NULL){
		       Ahead=A1;
		       A4=A1;
		       while(A4!=NULL){
		         c1++;
		         if(strcmp(A4->name,t->name)==0){
		                       break;}  
		         A4=A4->next;
		       }
                          if(A4!=NULL){
		          fprintf(fp,"MOV R%d,BP\n",r1);
		          fprintf(fp,"SUB R%d,%d\n",r1,2);
		          fprintf(fp,"ADD R%d,%d\n",r1,c1-1);
		          fprintf(fp,"SUB R%d,%d\n",r1,step);
		          fprintf(fp,"MOV R%d,[R%d]\n",r1,r1);
		          }
		          if(A4==NULL){
                            fprintf(fp,"MOV R%d,[%d]\n",r1,t->Gentry->binding);
                            }
		          }
		         
		         
                       while(flist3->next!=NULL){
                        Ft4=FLookup(flist3->type,flist3->next->name);
                        var=Ft4->fieldIndex-1;
                        fprintf(fp,"ADD R%d,%d\n",r1,var);
                        flist3=flist3->next;
                        if(flist3->next!=NULL)
                             fprintf(fp,"MOV R%d,[R%d]\n",r1,r1);
                        
                        }
                        fprintf(fp,"MOV [R%d],R%d\n",r1,r0);
                        freereg();
                        freereg();
                        //fprintf(fp,"BRKP\n");
               break;
                  }     
               
   case 59 :{     int c2;
                  for(s=0;s<=counter;s++)
                 fprintf(fp,"PUSH R%d\n",s);             //field=ALLOC();
                 c2=counter;
                 freeallreg();
                  r1=getreg();
                  fprintf(fp,"MOV R%d,\"Alloc\"\n",r1);
                  fprintf(fp,"PUSH R%d\n",r1);
                 // fprintf(fp,"PUSH 8\n");
                  fprintf(fp,"ADD SP,4\n");
                  fprintf(fp,"CALL 0\n");
                  fprintf(fp,"SUB SP,5\n");
                  freereg();
                  counter=c2;
                  for(s=counter;s>=0;s--)
                  fprintf(fp,"POP R%d\n",s);
                  r0=getreg();
                  fprintf(fp,"MOV R%d,SP\n",r0);
                  fprintf(fp,"ADD R%d,%d\n",r0,5+1+c2);
                  fprintf(fp,"MOV R%d,[R%d]\n",r0,r0);
                  
                   int var=0;
               flist3=t->typeentry;
                int c1=0;
                  r1=getreg();
                L4=Llookup(flist3->name);        
                if(L4!=NULL){
                   fprintf(fp,"MOV R%d,BP\n",r1);
                   fprintf(fp,"ADD R%d,%d\n",r1,L4->index);
                   fprintf(fp,"MOV R%d,[R%d]\n",r1,r1);
                   }
                else if(L4==NULL){
		       Ahead=A1;
		       A4=A1;
		       while(A4!=NULL){
		         c1++;
		         if(strcmp(A4->name,t->name)==0){
		                       break;}  
		         A4=A4->next;
		       }
                          if(A4!=NULL){
		          fprintf(fp,"MOV R%d,BP\n",r1);
		          fprintf(fp,"SUB R%d,%d\n",r1,2);
		          fprintf(fp,"ADD R%d,%d\n",r1,c1-1);
		          fprintf(fp,"SUB R%d,%d\n",r1,step);
		          fprintf(fp,"MOV R%d,[R%d]\n",r1,r1);
		          }
		          if(A4==NULL){
                            fprintf(fp,"MOV R%d,[%d]\n",r1,t->Gentry->binding);
                            }
		          }
                       while(flist3->next!=NULL){
                        Ft4=FLookup(flist3->type,flist3->next->name);
                        var=Ft4->fieldIndex-1;
                        fprintf(fp,"ADD R%d,%d\n",r1,var);
                        flist3=flist3->next;
                        if(flist3->next!=NULL)
                             fprintf(fp,"MOV R%d,[R%d]\n",r1,r1);
                        }
                         fprintf(fp,"MOV [R%d],R%d\n",r1,r0);
                        freereg();
                        freereg();
                     break;
   
                     }
                     
 case 61:          {                          //free(id)  
                     int c1=0;
                   r1=getreg();
                L4=Llookup(t->ptr1->name);        
                if(L4!=NULL){
                   fprintf(fp,"MOV R%d,BP\n",r1);
                   fprintf(fp,"ADD R%d,%d\n",r1,L4->index);
                   fprintf(fp,"MOV R%d,[R%d]\n",r1,r1);
                   }
                else if(L4==NULL){
		       Ahead=A1;
		       A4=A1;
		       while(A4!=NULL){
		         c1++;
		         if(strcmp(A4->name,t->ptr1->name)==0){
		                       break;}  
		         A4=A4->next;
		       }
                          if(A4!=NULL){
		          fprintf(fp,"MOV R%d,BP\n",r1);
		          fprintf(fp,"SUB R%d,%d\n",r1,2);
		          fprintf(fp,"ADD R%d,%d\n",r1,c1-1);
		          fprintf(fp,"SUB R%d,%d\n",r1,step);
		          fprintf(fp,"MOV R%d,[R%d]\n",r1,r1);
		          }
		          if(A4==NULL){
                            fprintf(fp,"MOV R%d,[%d]\n",r1,t->ptr1->Gentry->binding);
                            }
		          }
		          fprintf(fp,"MOV R%d,[R%d]\n",r1,r1);
		          
		          int c2;
                           for(s=0;s<=counter;s++)
                          fprintf(fp,"PUSH R%d\n",s);  
                           r2=getreg();
                           fprintf(fp,"MOV R%d,\"Free\"\n",r2);
                           fprintf(fp,"PUSH R%d\n",r2);
                           fprintf(fp,"PUSH R%d\n",r1);
                           fprintf(fp,"ADD SP,3\n");
                           fprintf(fp,"CALL 0\n");
                           fprintf(fp,"SUB SP,5\n");
                           freereg();
                           for(s=counter;s>=0;s--)
                              fprintf(fp,"POP R%d\n",s);
                              fprintf(fp,"MOV [R%d],-1\n",r1);
                           freereg();
                           break;
                           }
case 62:            {                                   //free(field)
                                  int var=0;
                        flist3=t->typeentry;
                         int c1=0;
                           r1=getreg();
                         L4=Llookup(flist3->name);        
                         if(L4!=NULL){
                            fprintf(fp,"MOV R%d,BP\n",r1);
                            fprintf(fp,"ADD R%d,%d\n",r1,L4->index);
                            fprintf(fp,"MOV R%d,[R%d]\n",r1,r1);
                            }
                         else if(L4==NULL){
		                Ahead=A1;
		                A4=A1;
		                while(A4!=NULL){
		                  c1++;
		                  if(strcmp(A4->name,t->name)==0){
		                                break;}  
		                  A4=A4->next;
		                }
                                   if(A4!=NULL){
		                   fprintf(fp,"MOV R%d,BP\n",r1);
		                   fprintf(fp,"SUB R%d,%d\n",r1,2);
		                   fprintf(fp,"ADD R%d,%d\n",r1,c1-1);
		                   fprintf(fp,"SUB R%d,%d\n",r1,step);
		                   fprintf(fp,"MOV R%d,[R%d]\n",r1,r1);
		                   }
		                   if(A4==NULL){
                                     fprintf(fp,"MOV R%d,[%d]\n",r1,t->Gentry->binding);
                                     }
		                   }
                                while(flist3->next!=NULL){
                                 Ft4=FLookup(flist3->type,flist3->next->name);
                                 var=Ft4->fieldIndex-1;
                                 fprintf(fp,"ADD R%d,%d\n",r1,var);
                                 flist3=flist3->next;
                                 if(flist3->next!=NULL)
                                      fprintf(fp,"MOV R%d,[R%d]\n",r1,r1);
                                 } 
                                 fprintf(fp,"MOV R%d,[R%d]\n",r1,r1);
                                 
                                 int c2;
                           for(s=0;s<=counter;s++)
                          fprintf(fp,"PUSH R%d\n",s);  
                           r2=getreg();
                           fprintf(fp,"MOV R%d,\"Free\"\n",r2);
                           fprintf(fp,"PUSH R%d\n",r2);
                           fprintf(fp,"PUSH R%d\n",r1);
                           fprintf(fp,"ADD SP,3\n");
                           fprintf(fp,"CALL 0\n");
                           fprintf(fp,"SUB SP,5\n");
                           freereg();
                           for(s=counter;s>=0;s--)
                              fprintf(fp,"POP R%d\n",s);
                              fprintf(fp,"MOV [R%d],-1\n",r1);
                           freereg();
                           break;
                  }  
case 63:          {                                   //read(field)
                           int var=0;
                        flist3=t->typeentry;
                         int c1=0;
                           r1=getreg();
                         L4=Llookup(flist3->name);        
                         if(L4!=NULL){
                            fprintf(fp,"MOV R%d,BP\n",r1);
                            fprintf(fp,"ADD R%d,%d\n",r1,L4->index);
                            fprintf(fp,"MOV R%d,[R%d]\n",r1,r1);
                            }
                         else if(L4==NULL){
		                Ahead=A1;
		                A4=A1;
		                while(A4!=NULL){
		                  c1++;
		                  if(strcmp(A4->name,t->name)==0){
		                                break;}  
		                  A4=A4->next;
		                }
                                   if(A4!=NULL){
		                   fprintf(fp,"MOV R%d,BP\n",r1);
		                   fprintf(fp,"SUB R%d,%d\n",r1,2);
		                   fprintf(fp,"ADD R%d,%d\n",r1,c1-1);
		                   fprintf(fp,"SUB R%d,%d\n",r1,step);
		                   fprintf(fp,"MOV R%d,[R%d]\n",r1,r1);
		                   }
		                   if(A4==NULL){
                                     fprintf(fp,"MOV R%d,[%d]\n",r1,t->Gentry->binding);
                                     }
		                   }
                                while(flist3->next!=NULL){
                                 Ft4=FLookup(flist3->type,flist3->next->name);
                                 var=Ft4->fieldIndex-1;
                                 fprintf(fp,"ADD R%d,%d\n",r1,var);
                                 flist3=flist3->next;
                                 if(flist3->next!=NULL)
                                      fprintf(fp,"MOV R%d,[R%d]\n",r1,r1);
                                 }
                                 for(s=0;s<=counter;s++)
                                    fprintf(fp,"PUSH R%d\n",s);  
                                 r2=getreg();
                                 fprintf(fp,"MOV R%d,\"Read\"\n",r2);
                                 fprintf(fp,"PUSH R%d\n",r2);
                                 fprintf(fp,"MOV R%d,-1\n",r2);
                                 fprintf(fp,"PUSH R%d\n",r2);
                                 fprintf(fp,"PUSH R%d\n",r1);          //arg2~read
                                 fprintf(fp,"MOV R%d,-1\n",r2);
                                 fprintf(fp,"PUSH R%d\n",r2);
                                 fprintf(fp,"PUSH R%d\n",r2);
                                 fprintf(fp,"CALL 0\n");
                                 fprintf(fp,"SUB SP,5\n");
                                 freereg();
                                 for(s=counter;s>=0;s--)
                                    fprintf(fp,"POP R%d\n",s);
                                freereg();
                                break;
                                    }                                              
 case 64:          {     printf("Hello1\n");                                //id=null
                         int c1=0;
                   r1=getreg();
                L4=Llookup(t->ptr1->name);        
                if(L4!=NULL){
                   fprintf(fp,"MOV R%d,BP\n",r1);
                   fprintf(fp,"ADD R%d,%d\n",r1,L4->index);
                   }
                else if(L4==NULL){
		       Ahead=A1;
		       A4=A1;
		       while(A4!=NULL){
		         c1++;
		         if(strcmp(A4->name,t->ptr1->name)==0){
		                       break;}  
		         A4=A4->next;
		       }
                          if(A4!=NULL){
		          fprintf(fp,"MOV R%d,BP\n",r1);
		          fprintf(fp,"SUB R%d,%d\n",r1,2);
		          fprintf(fp,"ADD R%d,%d\n",r1,c1-1);
		          fprintf(fp,"SUB R%d,%d\n",r1,step);
		          //fprintf(fp,"MOV [R%d],R%d\n",r1,r0);
		          }
		          if(A4==NULL){
                            fprintf(fp,"MOV R%d,%d\n",r1,t->ptr1->Gentry->binding);
                            }
		          }
		          fprintf(fp,"MOV [R%d],-1\n",r1);
		          freereg();
		           printf("Hello2\n");
		          break;  
                     }
 case 54 : {                            //field=null
                 int var=0;
                        flist3=t->typeentry;
                         int c1=0;
                           r1=getreg();
                         L4=Llookup(flist3->name);        
                         if(L4!=NULL){
                            fprintf(fp,"MOV R%d,BP\n",r1);
                            fprintf(fp,"ADD R%d,%d\n",r1,L4->index);
                            fprintf(fp,"MOV R%d,[R%d]\n",r1,r1);
                            }
                         else if(L4==NULL){
		                Ahead=A1;
		                A4=A1;
		                while(A4!=NULL){
		                  c1++;
		                  if(strcmp(A4->name,t->name)==0){
		                                break;}  
		                  A4=A4->next;
		                }
                                   if(A4!=NULL){
		                   fprintf(fp,"MOV R%d,BP\n",r1);
		                   fprintf(fp,"SUB R%d,%d\n",r1,2);
		                   fprintf(fp,"ADD R%d,%d\n",r1,c1-1);
		                   fprintf(fp,"SUB R%d,%d\n",r1,step);
		                   fprintf(fp,"MOV R%d,[R%d]\n",r1,r1);
		                   }
		                   if(A4==NULL){
                                     fprintf(fp,"MOV R%d,[%d]\n",r1,t->Gentry->binding);
                                     }
		                   }
                                while(flist3->next!=NULL){
                                 Ft4=FLookup(flist3->type,flist3->next->name);
                                 var=Ft4->fieldIndex-1;
                                 fprintf(fp,"ADD R%d,%d\n",r1,var);
                                 flist3=flist3->next;
                                 if(flist3->next!=NULL)
                                      fprintf(fp,"MOV R%d,[R%d]\n",r1,r1);
                                 }
                                 fprintf(fp,"MOV [R%d],-1\n",r1);
                                 freereg();
                                 break;
          }
          
 case 65:          {                          //E==NULL
                           r1=codegen(t->ptr1);
                           r2=getreg();
                           fprintf(fp,"MOV R%d,%d\n",r2,-1);
                           fprintf(fp,"EQ R%d,R%d\n",r1,r2);
                           return r1;
                           break;
                     }   
 case 66  :         {                                 //E!=NULL
                           r1=codegen(t->ptr1);
                           r2=getreg();
                           fprintf(fp,"MOV R%d,%d\n",r2,-1);
                           fprintf(fp,"NE R%d,R%d\n",r1,r2);
                           freereg();
                           return r1;
                           break;
                   }
 case 56 :   {                                      //initialize()
                       int c2;
                           for(s=0;s<=counter;s++)
                          fprintf(fp,"PUSH R%d\n",s);            
                          c2=counter;
                          freeallreg();
                           r1=getreg();
                           fprintf(fp,"MOV R%d,\"Heapset\"\n",r1);
                           fprintf(fp,"PUSH R%d\n",r1);
                           fprintf(fp,"ADD SP,4\n");
                           fprintf(fp,"CALL 0\n");
                           fprintf(fp,"SUB SP,5\n");
                           freereg();
                           counter=c2;
                           for(s=counter;s>=0;s--)
                           fprintf(fp,"POP R%d\n",s);
                           r0=getreg();
                           fprintf(fp,"MOV R%d,SP\n",r0);
                           fprintf(fp,"ADD R%d,5\n",r0);
                           fprintf(fp,"MOV R%d,[R%d]\n",r0,r0);
                            
                           return r0;
                           break;
          }
 case 55:   {                           //field
                            int var=0;
                        flist3=t->typeentry;
                         int c1=0;
                           r1=getreg();
                         L4=Llookup(flist3->name);        
                         if(L4!=NULL){
                            fprintf(fp,"MOV R%d,BP\n",r1);
                            fprintf(fp,"ADD R%d,%d\n",r1,L4->index);
                            fprintf(fp,"MOV R%d,[R%d]\n",r1,r1);
                            }
                         else if(L4==NULL){
		                Ahead=A1;
		                A4=A1;
		                while(A4!=NULL){
		                  c1++;
		                  if(strcmp(A4->name,t->name)==0){
		                                break;}  
		                  A4=A4->next;
		                }
                                   if(A4!=NULL){
		                   fprintf(fp,"MOV R%d,BP\n",r1);
		                   fprintf(fp,"SUB R%d,%d\n",r1,2);
		                   fprintf(fp,"ADD R%d,%d\n",r1,c1-1);
		                   fprintf(fp,"SUB R%d,%d\n",r1,step);
		                   fprintf(fp,"MOV R%d,[R%d]\n",r1,r1);
		                   }
		                   if(A4==NULL){
                                     fprintf(fp,"MOV R%d,[%d]\n",r1,t->Gentry->binding);
                                     }
		                   }
                                while(flist3->next!=NULL){
                                 Ft4=FLookup(flist3->type,flist3->next->name);
                                 var=Ft4->fieldIndex-1;
                                 fprintf(fp,"ADD R%d,%d\n",r1,var);
                                 flist3=flist3->next;
                                 if(flist3->next!=NULL)
                                      fprintf(fp,"MOV R%d,[R%d]\n",r1,r1);
                                 }
                                 fprintf(fp,"MOV R%d,[R%d]\n",r1,r1);
                                 return r1;
                                 break;                  
            }
                             
                                                      
     default: {printf("Nodetype Unknown : %d",t->nodetype);
              break;}         
                        
}
return 0;
}

