#include "../toplevel.h"
char * name_eq="eq";
//char * name_True="True";
char * name_False="False";
//var func_if();
void init_eq(){

	function * tmp = malloc(sizeof(function));
	tmp -> name = name_eq;
	tmp -> ip = func_eq;
	tmp -> _ip=0;
	tmp -> next = function_last;
	function_last = tmp;
}
var func_eq(){
	_dprintf("In eq\n");
	if(strcmp(get_var("1").value,get_var("2").value) == 0){
		var *vtmp=malloc(sizeof(var));
		
		vtmp->type = FL_TYPE_STRING;
		//vtmp->name = _i;
		vtmp->value = name_True;
		vtmp->level = ctx.level;
		vtmp->next = var_last;
		//var_last = vtmp;

		return *vtmp;
	}else{
		var *vtmp=malloc(sizeof(var));
		
		vtmp->type = FL_TYPE_STRING;
		//vtmp->name = _i;
		vtmp->value = name_False;
		vtmp->level = ctx.level;
		vtmp->next = var_last;
		//var_last = vtmp;

		return *vtmp;
	}
	
	//return *var_last;
}