#include "../toplevel.h"
char * int_tostring(var v){
	char * str = malloc(sizeof(char)*32);
	int * tmp = v.value;
	sprintf(str, "%d", *tmp);
	return str;
}