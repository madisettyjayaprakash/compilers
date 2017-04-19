typedef struct Gsymbol{
 char *name;
 int type;
 int size;
 int *binding;
 struct Gsymbol *next;
}Gsymbol;

struct Gsymbol *createentry(char *name,int type,int size,int *binding,struct Gsymbol*next);

struct Gsymbol *Ghead=NULL, *Gtail,*t,*t2,*temp1;

struct Gsymbol* Glookup(char *name);

