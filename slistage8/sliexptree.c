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


