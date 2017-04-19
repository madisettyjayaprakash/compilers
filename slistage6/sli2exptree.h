typedef struct Tnode{
      int type;       
      int nodetype;
      char *name;
      int value;
      struct Tnode *ArgList;
      struct Gsymbol *Gentry; // For global identifiers/functions
      struct Lsymbol *Lentry; // For Local variables
      struct Tnode *ptr1,*ptr2,*ptr3;
            
}Tnode;

struct Tnode* makenode(int type,int nodetype,char *name,int value,struct Tnode *ptr1,struct Tnode*ptr2,struct Tnode*ptr3);


int evaluate(struct Tnode *t);


