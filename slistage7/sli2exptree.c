int b,x;
char d[10];
struct Gsymbol *temp1,*t;

struct Tnode* makenode(int t,int nt,char *nam,int val,struct Tnode *p1,struct Tnode *p2,struct Tnode *p3){

struct Tnode*temp2;
//printf("%s\n",nam);
temp2=(struct Tnode*)malloc(sizeof(struct Tnode));
temp2->type=t;
temp2->nodetype=nt;
temp2->name=(char*)malloc(10*sizeof(char));
strcpy(temp2->name,nam);
temp2->value=val;
temp2->ptr1=p1;
temp2->ptr2=p2;
temp2->ptr3=p3;
//printf("In node\n");
return temp2;
}

/*int evaluate(struct Tnode*t1){
  
 switch(t1->nodetype){
 
 case 0 : {evaluate(t1->ptr1);evaluate(t1->ptr2);break;}   
 case 1 : {temp1=t1->Gentry;
            //printf("value :%d\n",*(temp1->binding));     
            return *(temp1->binding);}   
 case 2 : {return t1->value; }
 case 3 : {  
           temp1=t1->ptr1->Gentry;
             if(temp1->type==30)
             scanf("%d",&b);
             else if(temp1->type==40){
               scanf("%s",d);
               if(strcmp(d,"true")==0)
               b=1;
               else if(strcmp(d,"false")==0)
               b=0;
             }
            *(temp1->binding)=b;
           break;}
 case 4 : {t1->value=evaluate(t1->ptr1); printf("%d\n",t1->value);break;}
 case 5 : {return evaluate(t1->ptr1) + evaluate(t1->ptr2); }
 case 6 : {return evaluate(t1->ptr1) - evaluate(t1->ptr2); }
 case 7 : {return evaluate(t1->ptr1) * evaluate(t1->ptr2); }
 case 8:  {return evaluate(t1->ptr1) / evaluate(t1->ptr2); }
 case 12 :{
            //printf("In assign\n");
            temp1=t1->ptr1->Gentry;
             *(temp1->binding)=evaluate(t1->ptr2);
            break;}
 case 14 : {if(evaluate(t1->ptr1)==evaluate(t1->ptr2))
              return 1; 
            else 
              return 0; 
            }
 case 15 :  {if(evaluate(t1->ptr1) < evaluate(t1->ptr2))
              return 1; 
            else 
              return 0; 
            }
 case 16 : {if(evaluate(t1->ptr1) > evaluate(t1->ptr2))
              return 1; 
            else 
              return 0; 
            }
 case 17 : { if(evaluate(t1->ptr1))
               evaluate(t1->ptr2);
             else
               evaluate(t1->ptr3);
               break;
              }
 case 18:  {while(evaluate(t1->ptr1)){
             evaluate(t1->ptr2);
             }
             break;
             }
 case 19 : { if(evaluate(t1->ptr1))
               evaluate(t1->ptr2);
               break;
              }
 case 21 : {
                           t=t1->ptr1->Gentry;
                 *(t->binding+evaluate(t1->ptr2)*sizeof(int))=evaluate(t1->ptr3);
             break;
            }  
 case 22 : {  //  printf("In read a[i]");
              
                            temp1=t1->ptr1->Gentry;
                           // printf("%d\n",temp1->type);
             if(temp1->type==31)
                scanf("%d",&b);
             else if(temp1->type==41){
               scanf("%s",d);
               if(strcmp(d,"true")==0)
               b=1;
               else if(strcmp(d,"false")==0)
               b=0;
          }
                           
     			*(temp1->binding+evaluate(t1->ptr2)*sizeof(int))=b;
             break;
           }
 case 24: {  t=t1->ptr1->Gentry;       
              return *(t->binding+evaluate(t1->ptr2)*sizeof(int));
           }
 case 25 :   {if(evaluate(t1->ptr1) <= evaluate(t1->ptr2))
              return 1; 
            else 
              return 0; 
            }
 case 26:   {if(evaluate(t1->ptr1) >= evaluate(t1->ptr2))
              return 1; 
            else 
              return 0; 
            }                                                           
 case 27: {if(evaluate(t1->ptr1) != evaluate(t1->ptr2))
              return 1; 
            else 
              return 0; 
            }
 case 28:  {return t1->value;}
 case 29: {return t1->value;}
 case 30: {if(evaluate(t1->ptr1) && evaluate(t1->ptr2))
            return 1;
           else
            return 0;}
  case 31: {if(evaluate(t1->ptr1) || evaluate(t1->ptr2))
            return 1;
           else
            return 0;}
  case 32: {if(evaluate(t1->ptr1) != evaluate(t1->ptr2))
            return 1;
           else
            return 0;}
  case 33 : {if(evaluate(t1->ptr1) <= evaluate(t1->ptr2))
            return 1;
           else
            return 0;}
  case 34 : {if(evaluate(t1->ptr1) >= evaluate(t1->ptr2))
            return 1;
           else
            return 0;}          
 }



}*/
