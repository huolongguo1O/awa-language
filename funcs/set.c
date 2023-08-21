#include "../toplevel.h"
char * name_set="set";
var func_set();
void init_set(){

	function *set = malloc(sizeof(function));
	set -> name = name_set;
	set -> ip = func_set;
	set -> _ip=0;
	set -> next = function_last;
	function_last = set;
}
var func_set(){
	_dprintf("In set\n");
	var * vtmp;
	vtmp=malloc(sizeof(var));
	vtmp->type = FL_TYPE_STRING;
	vtmp->name = get_var("1").value;//TODO: check
	vtmp->value = get_var("2").value;
	_dprintf("set: %s = %s\n", vtmp->name, vtmp->value);
	vtmp->level = ctx.level;
	vtmp->next = var_last;
	var_last = vtmp;
	return *var_last;
}