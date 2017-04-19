int counter=-1,label=-1;
FILE *fp;
int getreg(){
  if(counter<8)
    return ++counter;

}
int freereg(){
 if(counter>=0)
   return counter--;

}
int getlabel(){
   return ++label;
}

void inter_codegen(struct Tnode*t){
 fp=fopen("target.txt","w+");
 if(fp==NULL){
 printf("Unable to allocate file\n");
 exit(1);
 }

 fprintf(fp,"START\n");
 fprintf(fp,"MOV SP,4095\n");
 codegen(t);
 fprintf(fp,"HALT");
 fclose(fp);
 return;
 }
int codegen(struct Tnode*t){
//printf("%d ",t->nodetype);
 int r1,r2,l1,l2,offset;
 struct Tnode*temp;
 if(fp==NULL){
 printf("Error while generating assembly code\n");
 exit(1);
 }
 
   switch(t->nodetype){
   
   case 0:   {codegen(t->ptr1);    //slist->stmnt slist
              codegen(t->ptr2);
              break;}
    
    case 28: {r1=getreg();                             //TRUE
              fprintf(fp,"MOV R%d,%d\n",r1,t->value);
              return r1;}   
    case 29: {r1=getreg();                             //FALSE
              fprintf(fp,"MOV R%d,%d\n",r1,t->value);
              return r1;}
    case 1 : {r1=getreg();                             //ID
               fprintf(fp,"MOV R%d,[%d]\n",r1,t->Gentry->binding);
               
               return r1;}
    case 2 : {r1=getreg();                              //NUM
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
    case 5 :  {r1=codegen(t->ptr1);               //add
               r2=codegen(t->ptr2);
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
     case 32 : {r1=codegen(t->ptr1);
               r2=codegen(t->ptr2);
               fprintf(fp,"NE R%d,R%d\n",r1,r2);
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
                
     case 12 : {r1=codegen(t->ptr2);                     //ID = E
                  fprintf(fp,"MOV [%d],R%d\n",t->ptr1->Gentry->binding,r1);
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
     case 3 : {r1=getreg();                       //read
               fprintf(fp,"IN R%d\n",r1);
               fprintf(fp,"MOV [%d],R%d\n",t->ptr1->Gentry->binding,r1);
               freereg();
               break; }  
     case 22 : {r1=codegen(t->ptr2);              //read(a[E])
                r2=getreg();
                fprintf(fp,"MOV R%d,%d\n",r2,t->ptr1->Gentry->binding);
                fprintf(fp,"ADD R%d,R%d\n",r1,r2);
                fprintf(fp,"IN R%d\n",r2);
                fprintf(fp,"MOV [R%d],R%d\n",r1,r2);
                freereg();
                freereg();
                break;
               }         
     case 4 : {r1=codegen(t->ptr1);              //write(E)
               fprintf(fp,"OUT R%d\n",r1);
               freereg();
               break;}  
     case 19 :{r1=codegen(t->ptr1);
              l1=getlabel();
              fprintf(fp,"JZ R%d,L%d\n",r1,l1);
              freereg();
              r1=codegen(t->ptr2);
              fprintf(fp,"L%d:\n",l1);
              freereg();
              break;}
     case 17 : {r1=codegen(t->ptr1);
                l1=getlabel();
                l2=getlabel();
                fprintf(fp,"JZ R%d,L%d\n",r1,l1);
                freereg();
                r1=codegen(t->ptr2);
                fprintf(fp,"JMP L%d\n",l2);
                fprintf(fp,"L%d:\n",l1);
                freereg();
                r1=codegen(t->ptr3);
                fprintf(fp,"L%d:\n",l2);
                freereg();
                break;
             }   
     case 18: {l1=getlabel();
               l2=getlabel();
               fprintf(fp,"L%d:\n",l1);
               r1=codegen(t->ptr1);
               fprintf(fp,"JZ R%d,L%d\n",r1,l2);
               freereg();
               r1=codegen(t->ptr2);
               fprintf(fp,"JMP L%d\n",l1);
               fprintf(fp,"L%d:\n",l2);
              
               freereg();
               break;
               }        
             
     default: {printf("Nodetype Unknown : %d",t->nodetype);
              break;}         
                        
}


return 0;
}


