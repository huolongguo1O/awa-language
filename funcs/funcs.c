#include "../toplevel.h"

var  call_function(char * name){
	_dprintf("call_function %s\n", name);
	function *v;
	v=function_last;
	while(v!=(function *)-1){
		if(strcmp(v->name,name)==0){
			if(v->ip==NULL&&v->_ip!=0){
				int orgip=ctx.ip;
				ctx.ip=v->_ip;
				char * tmp=parse(ctx.code,'}');
				ctx.ip=orgip;
				var *vtmp=malloc(sizeof(var));
		
				vtmp->type = FL_TYPE_STRING;
				//vtmp->name = _i;
				vtmp->value = tmp;
				vtmp->level = ctx.level;
				//vtmp->next = var_last;
				//var_last = vtmp;
				return *vtmp;
			}else
			if(v->ip!=NULL && v->_ip==0) {
				
				//var *func()=v->ip;
				
				var ret=((var (*)())v->ip)();
				return ret;
			}
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
	char tmp[2]=" ";
	p=start;
	while(*p!=' '&&*p!='{'){
		tmp[0]=*p;
		int q = p-start;
		ret = str_appened(ret, tmp,&q,&plus_times);
		p++;
		ctx.ip++;
		check_overflow();
		fuckcheck
	}
	//ctx.ip += p-start;
	return ret;

}

void get_function_args(char *start){
	_dprintf("get_function_args\n");
	//char * orgstart=start;
	int i = 1;
	
	//char  _tmp[]= " ";
	while(*(ctx.code+ctx.ip)=='{'){
		
		
		//int plus_times = 1;
		//int pret =0;
		start++;
		ctx.ip++;
		check_overflow();
		_fuckcheck
		char * _i;
		_i = malloc(sizeof(char)*MAX_STR_LEN);
		memset(_i, 0, MAX_STR_LEN);
		//convert i to str _i 
		sprintf(_i,"%d",i);

		char * tmp = malloc(sizeof(char)*MAX_STR_LEN);
		memset(tmp, 0, MAX_STR_LEN);
		tmp = parse(ctx.code,'}');

		start++;
		ctx.ip++;
		check_overflow();
		_fuckcheck
		var *vtmp=malloc(sizeof(var));
		
		vtmp->type = FL_TYPE_STRING;
		vtmp->name = _i;
		vtmp->value = tmp;
		vtmp->level = ctx.level;
		vtmp->next = var_last;
		var_last = vtmp;
		i++;
	}
	ctx.ip--;
	_fuckcheck


}

void init_function(){
	init_set();
	init_if();
	init_eq();
	init_def();
	init_input();
}
void clean_func(){
	return;
	function *v;
	v=function_last;
	while(v->level==ctx.level){
		free(v);
		v=v->next;
		function_last=v;
	}

}