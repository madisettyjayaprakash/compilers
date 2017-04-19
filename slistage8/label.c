struct label{
int address;
char *name;
struct label*next;
};
struct label*head,*p,*t1,*q;

struct label*lookup(char*nam){
char *name1;
int i,k;
struct label*temp=head;
name1=(char*)malloc(100*sizeof(char));
for(i=0;i<strlen(nam);i++){
 if(nam[i]==':')
  continue;
 else{
   name1[k]=nam[i];k++;}
}


  while(temp!=NULL){
 
      if(strcmp(temp->name,name1)==0){
             return temp;
         }
       temp=temp->next;
   }
return temp;
}


struct label*createlabel(char*nam,int val){
char c;
int i,k=0;
  t1=lookup(nam);
    if(t1!=NULL){
    return head;
    }

struct label*temp=(struct label*)malloc(sizeof(struct label));
temp->address=val;
temp->name=(char*)malloc(100*sizeof(char));
for(i=0;i<strlen(nam);i++){
 if(nam[i]==':')
  continue;
 else{
   temp->name[k]=nam[i];k++;}
}
temp->next=NULL;
  if(head==NULL){
     head=temp;
     p=temp;
   }
  else{
    p->next=temp;
    p=temp;
   }
return head;
}

