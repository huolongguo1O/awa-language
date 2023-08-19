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
		ctx.ip++;
	}
	//ctx.ip += p-start;
	return ret;

}

void get_function_args(char *start){
	int i = 0;
	char * _tmp= " ";
	while(*start=='{'){
		int plus_times = 1;
		start++;
		ctx.ip++;
		char * _i;
		_i = malloc(sizeof(char)*MAX_STR_LEN);
		memset(_i, 0, MAX_STR_LEN);
		//convert i to str _i 
		sprintf(_i,MAX_STR_LEN-1,"%d",i);

		char * tmp = malloc(sizeof(char)*MAX_STR_LEN);
		memset(tmp, 0, MAX_STR_LEN);
		while(*start!='}'){
			_tmp[0]=*start;
			tmp = str_appened(tmp, _tmp,&start,&plus_times);
			start++;
			ctx.ip++;
		}
		start++;
		ctx.ip++;
		var vtmp;
		vtmp.type = FL_TYPE_STRING;
		vtmp.name = _i;
		vtmp.value = tmp;
		vtmp.level = ctx.level;
		vtmp.next = var_last;
		var_last = &vtmp;
		i++;
	}

}

void init_function(){

}