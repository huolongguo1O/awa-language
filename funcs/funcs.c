#include "../toplevel.h"

var  call_function(char * name){
	function *v;
	v=&function_start;
	while(v->next!=(function *)-1){
		if(strcmp(v->name,name)==0){
			if(v->ip==NULL)
				break;
			//var *func()=v->ip;
			
			var ret=((var (*)())v->ip)();
			return ret;
		}
		v=v->next;
	}
	return var_start;
}