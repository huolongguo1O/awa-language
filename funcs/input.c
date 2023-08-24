#include "../toplevel.h"
char * name_ipt="input";
var func_input();
void init_input(){

	function *ipt = malloc(sizeof(function));
	ipt -> name = name_ipt;
	ipt -> ip = func_input;
	ipt -> _ip = 0;
	ipt-> next = function_last;
	function_last = ipt;
}
var func_input(){
	_dprintf("In set\n");
	var * vtmp;
	vtmp=malloc(sizeof(var));
	vtmp->type = FL_TYPE_STRING;
    char * tmp;
    tmp = malloc(sizeof(char)*1024);
    fgets(tmp,1024,stdin);
    vtmp->value = tmp;
	_dprintf("set: %s = %s\n", vtmp->name, vtmp->value);
	vtmp->level = ctx.level;
	//vtmp->next = var_last;
	//var_last = vtmp;
	return *vtmp;
}