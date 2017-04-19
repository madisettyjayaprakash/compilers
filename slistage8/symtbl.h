typedef struct Gsymbol{

 char *name;
 int type;
 int size;
 int binding;
 struct ArgStruct *list;
 int argcount;
 struct Gsymbol *next;
 int flabel;
}Gsymbol;

typedef struct ArgStruct{
 char *name;
 int type;
 struct ArgStruct*next;
}ArgStruct;



struct Gsymbol *Glookup(char *name);

struct Gsymbol *Gcreateentry(char *name,int type,int size,struct ArgStruct *list);

struct ArgStruct *Aentry(char *name,int type);

typedef struct Lsymbol{
 char *name;
 int type;
 int binding;
 int index;
 struct Lsymbol *next;
 
}Lsymbol;


struct Lsymbol *Llookup(char *name);

struct Lsymbol *Lcreateentry(char *name,int type);




