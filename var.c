#include "toplevel.h"
var get_var(char *name){
	var *v;
	v=&var_start;
	while(v->next!=(var *)-1){
		if(strcmp(v->name,name)==0){
			return *v;
		}
		v=v->next;
	}
	//var ret;
	//ret.name=name;
	//ret.type=FL_TYPE_NULL;
	return var_start;
}