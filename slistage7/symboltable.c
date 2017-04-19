struct Gsymbol* Glookup(char *nam){
struct Gsymbol*temp=Ghead;
  while(temp!=NULL){
  if(strcmp(temp->name,nam)==0){
    return temp;
  }
  temp=temp->next;}
  return temp;

}

struct Gsymbol *createentry(char *nam,int typ,int siz,int bind,struct Gsymbol*nxt){

struct Gsymbol*temp;
//printf("%s\n",nam);
   temp=Glookup(nam);
   if(temp!=NULL){
   yyerror("Variable reinitialized");
   exit(1);
   }
//printf("%s\n",nam);
t=(struct Gsymbol*)malloc(sizeof(struct Gsymbol));
t->name=(char*)malloc(100*sizeof(char));
strcpy(t->name,nam);
t->type=typ;
t->size=siz;
t->binding=bind;
t->next=nxt;
if(Ghead==NULL){
Ghead=t;
t2=t;
}
else{
t2->next=t;
t2=t;
}
return Ghead;
}
