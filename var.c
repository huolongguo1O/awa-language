#include "toplevel.h"
var get_var(char *name){
	var *v;
	v=var_last;
	while(v!=(var *)1){
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
void clean_var(){
	return ;
	var *v;
	v=var_last;
	while(v->level==ctx.level){
		
		//free(v->name);
		//free(v->value);
		//free(v);
		v=v->next;
		var_last=v;
	}
	//var_last=(var *)1;
	//var_start.type=FL_TYPE_NULL;
}