struct Gsymbol *Ghead=NULL,*t2,*pos1;
struct ArgStruct *Ahead=NULL,*t3;
struct Lsymbol *Lhead=NULL,*t4,*pos2;
int ci,argc=0;
int lab=-1;
struct Gsymbol *Glookup(char *nam){
  struct Gsymbol*temp=Ghead;
  temp=Ghead;
  while(temp!=NULL){
 // printf("%s \n",temp->name);
  if(strcmp(temp->name,nam)==0){
    return temp;
  }
  temp=temp->next;}
  return temp;
  
  }


struct Gsymbol *Gcreateentry(char *nam,int typ,int siz,struct ArgStruct*l1){

   struct Gsymbol*temp,*t;
   temp=Glookup(nam);
   if(temp!=NULL){
   yyerror("Variable reinitialized");
   exit(1);
   }
  
  //printf("Hi\n");
  t=(struct Gsymbol*)malloc(sizeof(struct Gsymbol));
  t->name=(char*)malloc(100*sizeof(char));
  strcpy(t->name,nam);
  t->type=typ;
  t->size=siz;
  t->list=l1;
  t->argcount=argc;
  if(siz==1){
  t->binding=sptr;
  t->flabel=-1;
  sptr++;}
  else if(siz>1){
  t->binding=sptr;
  sptr=sptr+siz;
  t->flabel=-1;
  }
  else if(siz==-1){
  t->binding=NULL;
  t->flabel=++lab;
  }
  t->next=NULL;
  if(Ghead==NULL){
    Ghead=t;
    t2=t; 
    }
  else{
    t2->next=t;
    t2=t;
  
  } 
  //printf("%s ",t->name);
  return Ghead;
  
  
 }
 
struct  ArgStruct *Aentry(char *nam,int typ){          //args stored in (arg n,arg n-1,arg n-2,...1)
 
   struct ArgStruct*t=(struct ArgStruct*)malloc(sizeof(struct ArgStruct));
   t->name=(char*)malloc(100*sizeof(char));
   strcpy(t->name,nam);
   t->type=typ;
   t->next=NULL;
  if(Ahead==NULL){
    Ahead=t;
    t3=t; 
    }
  else{
    t->next=t3;
    t3=t;
    Ahead=t3;
  } 
  argc++;
 // printf("%s",t->name);
  return Ahead;
 
 }
 
 struct Lsymbol *Llookup(char *nam){
   struct Lsymbol*temp=Lhead;
    while(temp!=NULL){
      if(strcmp(temp->name,nam)==0){
        return temp;
         }
    temp=temp->next;}
    return temp; 
 
 
 }
 
 
 struct Lsymbol *Lcreateentry(char *nam,int typ){
   struct Lsymbol*temp,*t;
   
   temp=Llookup(nam);
   // printf("Hi3\n");
   if(temp!=NULL){
   yyerror("Variable reinitialized");
   exit(1);
   }
   pos1=Glookup(nam);
   if(pos1!=NULL&&pos1->list!=NULL){
     yyerror("Variable Used as a function name\n");
     exit(1);
   }
    //printf("Hi1\n");
   t= (struct Lsymbol*)malloc(sizeof(struct Lsymbol));
   t->name=(char*)malloc(100*sizeof(char));
   strcpy(t->name,nam);
   t->type=typ;
   t->next=NULL;
   t->binding=(int*)malloc(sizeof(int));
   if(Lhead==NULL){
       
       ci=0;
       t->index=++ci;
       Lhead=t;
       t4=t;
    }
    else{
       t->index=++ci;
       t4->next=t;
       t4=t;
      
    }
    
  return Lhead;
  }
 
 void semfuncheck(char *nam,struct ArgStruct *l1){
   
   struct Gsymbol *temp=Glookup(nam);
   int x,c=1;
   char nc[100];
   //printf("%s\n",temp->name);
   if(temp==NULL){
   yyerror("Function not declared\n");
   }
   if(temp->size!=-1){
    yyerror("Function not defined\n");
   }
   struct ArgStruct *A=temp->list;
   
   while(A!=NULL){
    x=A->type;
    strcpy(nc,A->name);
    if(x!=l1->type){
     yyerror("Type error of %d Argument\n",c);
     exit(1);
    }
    //printf("%s\n",l1->name);
    if(strcmp(nc,l1->name)!=0){
     yyerror("%d Argument name not matching\n",c);
     exit(1);
    }
     A=A->next;
     l1=l1->next;
     c++;
   }
   
   
   if(l1!=NULL||A!=NULL){
   
   yyerror("No of arguments not matching1\n");
   //printf("%s\n",l1->name);
   exit(1);
   }
  return;
 }
 
 

 
 
