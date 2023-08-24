#include "../toplevel.h"
char * name_if="if";
char * name_True="True";
char * name_None="";
//var func_if();
void init_if(){

	function * fif = malloc(sizeof(function));
	fif -> name = name_if;
	fif -> ip = func_if;
	fif -> _ip=0;
	fif -> next = function_last;
	function_last = fif;
}
var func_if(){
	_dprintf("In if\n");
	var *vtmp=malloc(sizeof(var));
		
	vtmp->type = FL_TYPE_STRING;
	//vtmp->name = _i;
	vtmp->value = name_None;
	vtmp->level = ctx.level;
	//vtmp->next = var_last;
	//var_last = vtmp;
	if(strcmp(get_var("1").value,name_True)==0){
		ctx.ip++;
		return *vtmp;
	}else{
		while(ctx.code[ctx.ip]!=ctx.end_char) ctx.ip++;
		return *vtmp;
	}
	
	//return *var_last;
}