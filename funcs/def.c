#include "../toplevel.h"
char * name_def="def";

void init_def(){

	function * tmp = malloc(sizeof(function));
	tmp -> name = name_def;
	tmp -> ip = func_def;
	tmp -> _ip = 0;
	tmp -> next = function_last;
	function_last = tmp;
}
var func_def(){
	_dprintf("In set\n");
	function * func=malloc(sizeof(function));
	func -> name       = get_var("1").value;
	func -> ip         = 0;
	func -> _ip        = ctx.ip+1;
	func -> level      = ctx.level;
	func -> next       = function_last;
	function_last      = func;
	_dprintf("Func %s\n",func->name);
	return *var_last;
}