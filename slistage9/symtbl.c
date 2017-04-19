struct Gsymbol *Ghead=NULL,*t2,*pos1;
struct ArgStruct *Ahead=NULL,*t3;
struct Lsymbol *Lhead=NULL,*t4,*pos2;
struct Typetable*TThead=NULL,*TT1,*TT2,*TT3,*type1,*type,*TT4;
struct makelist*flisthead=NULL,*flist1,*flist2,*flist3;
struct Fieldlist*FHead=NULL,*Ft1,*Ft2,*Ft3,*Ft4;
int ci,argc=0;
int lab=-1,cf=0;

void TypeTableCreate(){
  int c=0;

  while(c<4){
     struct Typetable*TTtemp=(struct Typetable*)malloc(sizeof(struct Typetable));
      TTtemp->name=(char*)malloc(20*sizeof(char));
      if(TThead==NULL){
           TTtemp->name="int";
           TTtemp->fields=NULL;
           TTtemp->size=1;
           TTtemp->next=NULL;
           TThead=TTtemp;
           TT1=TTtemp;
           c++;
         }
      else{
          if(c==1)
            TTtemp->name="str";
          else if(c==2)
            TTtemp->name="bool";
          else if(c==3)
            TTtemp->name="void";
            
          TTtemp->size=1;
          TTtemp->fields=NULL;
          TTtemp->next=NULL;
          TT1->next=TTtemp;
          TT1=TTtemp;
        c++;   
      }
  }
}
struct Typetable* TLookup(char *name1){
  struct Typetable*TTtemp;
  TTtemp=TThead;
  while(TTtemp!=NULL){
   if(strcmp(TTtemp->name,name1)==0){
      return TTtemp;
    }
   TTtemp=TTtemp->next;
   }
return TTtemp;
}

struct Typetable* TInstall(char *name1,int size1, struct Fieldlist *fields1){
  
  struct Typetable*TTtemp;
  TTtemp=TLookup(name1);
  if(TTtemp!=NULL){
    yyerror("Typename already used\n");
    exit(1);
   }
  else{
    TTtemp=(struct Typetable*)malloc(sizeof(struct Typetable));
    TTtemp->name=(char*)malloc(20*sizeof(char));
    strcpy(TTtemp->name,name1);
    TTtemp->size=size1;
    TTtemp->fields=fields1;
    TTtemp->next=NULL;
    TT1->next=TTtemp;
    TT1=TTtemp;
  }  
 return TThead;
}
struct Fieldlist*FLookup(struct Typetable *type1, char *name1){
   struct Fieldlist*Ftemp=type1->fields;
   /*struct Typetable*TT5;
   TT5=TThead; 
                                                      
         while(TT5!=NULL){
         printf("%s\n",TT5->name);
         Ft3=TT5->fields;
         while(Ft3!=NULL){
         printf("uuo %s %s\n",TT5->fields->name,TT5->fields->type->name);
           Ft3=Ft3->next;
          }
          TT5=TT5->next;
         } */
   while(Ftemp!=NULL){
   //printf("sh\n");
    if(strcmp(Ftemp->name,name1)==0){
     return Ftemp;
    }
    Ftemp=Ftemp->next;
   }
  return Ftemp;
}

struct Fieldlist* FInstall(struct Typetable *type1, char *name1){
  struct Fieldlist*Ftemp;
  Ftemp=FLookup(type1,name1);
  if(Ftemp!=NULL){
     yyerror("Field names are already present\n");
     exit(1);
   }
  
     Ftemp=(struct Fieldlist*)malloc(sizeof(struct Fieldlist));
     Ftemp->name=(char*)malloc(20*sizeof(char));
     strcpy(Ftemp->name,name1);
     Ftemp->type=type1;
     Ftemp->next=NULL;
     Ftemp->fieldIndex=++cf;
     if(FHead==NULL){
      FHead=Ftemp;
      Ft1=FHead;
     }
     else{
       Ft1->next=Ftemp;
       Ft1=Ftemp;
     }
  return FHead;
}



struct Gsymbol *Glookup(char *nam){
  struct Gsymbol*temp=Ghead;
  temp=Ghead;
  while(temp!=NULL){
  if(strcmp(temp->name,nam)==0){
    return temp;
  }
  temp=temp->next;}
  return temp;
  }


struct Gsymbol *Gcreateentry(char *nam,struct Typetable *typ,int siz,struct ArgStruct*l1){

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
 
struct  ArgStruct *Aentry(char *nam,struct Typetable *typ){      //args stored in (arg n,arg n-1,arg n-2,...1)
 
   struct ArgStruct*t=(struct ArgStruct*)malloc(sizeof(struct ArgStruct));
   t->name=(char*)malloc(100*sizeof(char));
   strcpy(t->name,nam);
   //printf(" arg %s\n",typ->name);
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
 
  
 
 
 struct Lsymbol *Lcreateentry(char *nam,struct Typetable *typ){
   struct Lsymbol*temp,*t;
   struct ArgStruct*temp1=Ahead;
    while(temp1!=NULL){
      if(strcmp(temp1->name,nam)==0){
        yyerror("Variable already in argument list");exit(1);
         }
    temp1=temp1->next;}
   
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
 
 struct makelist*makelistfield(struct Tnode*f1){
  
  struct makelist*Ttemp=(struct  makelist*)malloc(sizeof(makelist));
  Ttemp->name=(char*)malloc(30*sizeof(char));
  strcpy(Ttemp->name,f1->name);
  Ttemp->type=NULL;
  Ttemp->next=NULL;
  if(flisthead==NULL){
    flisthead=Ttemp;
    flist1=Ttemp;
   }
  else{
    flist1->next=Ttemp;
    flist1=Ttemp;
  }
  return flisthead;
  }

 
 
