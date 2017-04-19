typedef struct Typetable{
    char *name;                 //type name
    int size;                   //size of the type
    struct Fieldlist *fields;   //pointer to the head of fields list
    struct Typetable *next;     // pointer to the next type table entry
}Typetable;

typedef struct Fieldlist{
  char *name;              //name of the field
  int fieldIndex;          //the position of the field in the field list
  struct Typetable *type;  //pointer to type table entry of the field's type
  struct Fieldlist *next;  //pointer to the next field
}Fieldlist;


typedef struct Gsymbol{

 char *name;
 struct Typetable *type;
 int size;
 int binding;
 struct ArgStruct *list;
 int argcount;
 struct Gsymbol *next;
 int flabel;
}Gsymbol;

typedef struct ArgStruct{
 char *name;
 struct Typetable *type;
 struct ArgStruct*next;
}ArgStruct;

typedef struct makelist{
 char *name;
 struct Typetable*type;
 struct makelist*next;

}makelist;

struct Gsymbol *Glookup(char *name);

struct Gsymbol *Gcreateentry(char *name,struct Typetable *type,int size,struct ArgStruct *list);

struct ArgStruct *Aentry(char *name,struct Typetable *type);

typedef struct Lsymbol{
 char *name;
 struct Typetable *type;
 int index;
 struct Lsymbol *next;
 
}Lsymbol;


struct Lsymbol *Llookup(char *name);

struct Lsymbol *Lcreateentry(char *name,struct Typetable *type);

void TypeTableCreate();
struct Typetable* TLookup(char *name);
struct Typetable* TInstall(char *name,int size, struct Fieldlist *fields);
struct Fieldlist* FInstall(struct Typetable *type, char *name);
struct Fieldlist* FLookup(struct Typetable *type, char *name);



