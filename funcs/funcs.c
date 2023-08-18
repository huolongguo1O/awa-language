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

char * get_function_name(char * start){
	char * ret = malloc(sizeof(char)*MAX_STR_LEN);
	memset(ret, 0, MAX_STR_LEN);
	int plus_times = 1;
	char *p;
	char *tmp=" ";
	p=start;
	while(*p!=' '&&*p!='{'){
		tmp[0]=p;
		ret = str_appened(ret, tmp,&p,&plus_times);
		p++;
	}
	return ret;

}