#ifndef init
#define init
typedef struct _var{
	int type;
	char * name;
	void * value;
	int size;
	int level;
	struct _var * next;
}var;

typedef struct _function{
	void * ip;
	int _ip;
	char * name;
	int level;
	struct _function * next;
}function;

typedef struct _context{
	char * code;
	int ip;
	int level;
	char end_char;
}context;
#endif


#define MAX_STR_LEN 16