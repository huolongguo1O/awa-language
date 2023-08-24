#include "structs.h"
#include "utils/utils.h"
#include "funcs/funcs.h"
#include "types/types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

var get_var(char * name);
extern var var_start;
extern function function_start;
extern function * function_last;
extern var * var_last;
extern int codelen;
extern context ctx;
char * parse(char * code,char end_char);
char * tostring(var  v);
void donothing(char* fmt,...);
void check_overflow();
extern int isoverflow;
void clean_func();
void clean_var();

//#define DEBUG
#ifdef DEBUG
#define _dprintf printf
#define fuckcheck if(isoverflow==1) return (void *)0;
#define _fuckcheck if(isoverflow==1) return;
#else
#define _dprintf donothing
#define fuckcheck  
#define _fuckcheck  
#endif