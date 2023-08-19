#include "../toplevel.h"
void init_set(){
	function *set = malloc(sizeof(function));
	set->name = "set";
	set -> ip = 0;
	set -> _ip=0;
	set -> next = function_last;
	function_last = set;
}
var func_set(){
	var vtmp;
	vtmp.type = FL_TYPE_STRING;
	vtmp.name = get_var("1").value;//TODO: check
	vtmp.value = get_var("2").value;
	vtmp.level = ctx.level;
	vtmp.next = var_last;
	var_last = &vtmp;
}