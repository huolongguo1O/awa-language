#include "../toplevel.h"
char * nullstring = "null";
char * tostring(var  v){
	switch(v.type){
		case FL_TYPE_NULL:
			return var_start.value;
			break;
		case FL_TYPE_INT:
			return int_tostring(v);
			break;
		case FL_TYPE_STRING:
			return v.value;
			break;
		default:
			return var_start.value;
			break;
	}
}