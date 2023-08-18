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
	ctx.ip += p-start;
	return ret;

}

void get_function_args(char *start){
	char _tmp=' '
	while(*start=='{'){
		char * tmp = malloc(sizeof(char)*MAX_STR_LEN);
		memset(tmp, 0, MAX_STR_LEN);
		while(*start!='}'){
			_tmp[0]=*start;
			tmp = str_appened(_tmp, start,&start,&ctx.plus_times);
		}
		var _tmp;
		
	}

}