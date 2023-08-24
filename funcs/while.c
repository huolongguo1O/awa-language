#include "../toplevel.h"
char * name_wil="while";
char * name_True="True";
//char * name_None="";
var func_while();
void init_while(){

	function *wil = malloc(sizeof(function));
	wil -> name = name_wil;
	wil -> ip = func_while;
	wil -> _ip = 0;
	wil-> next = function_last;
	function_last = wil;
}
var func_while(){
	_dprintf("In while\n");
	char * tmp = malloc(sizeof());
    var *vtmp=malloc(sizeof(var));
		
	vtmp->type = FL_TYPE_STRING;
	//vtmp->name = _i;
	vtmp->value = name_None;
	vtmp->level = ctx.level;
	//vtmp->next = var_last;
	//var_last = vtmp;
	ctx.ip+=2;
	while(parse(code,'}'),name_True)==0){
		if(code[ctx.ip]=='{'){
			tmp=str_append(parse(code,'}'));
		}
	}
	//e，你这结构体各个子变量功能能解释下吗（
	//return *var_last;
}
