#include "../structs.h"
#define FL_TYPE_NULL 0
#define FL_TYPE_INT 1
#define FL_TYPE_FLOAT 2
#define FL_TYPE_STRING 3
#define FL_TYPE_LIST 4
#define FL_TYPE_OBJECT 5
#define FL_TYPE_FUNCTION 6
// #define FL_TYPE_CHAR 7

#define FL_SUBTYPE_LIST 8
#define FL_SUBTYPE_CHAR 9
#define FL_SUBTYPE_BOOL 10
#define FL_SUBTYPE_INT 11
#define FL_SUBTYPE_FLOAT 12
#define FL_SUBTYPE_STRING 13
#define FL_SUBTYPE_OBJECT 15

typedef struct _list{
	int type;// = FL_TYPE_LIST;
	int subtype;
	var *items;
}list;
char * tostring(var  v);
char * int_tostring(var v);