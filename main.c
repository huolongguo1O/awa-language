// A new language
/////////////////////////////////////////////////////////////////////////////////////////
/*                           The AwA(AwA WaW Awa) Language                                 */
/////////////////////////////////////////////////////////////////////////////////////////
/*                               By huolongguo10                                       */
/////////////////////////////////////////////////////////////////////////////////////////
/*                              Publish under GPL                                       */
/////////////////////////////////////////////////////////////////////////////////////////
/*After I learnt LaTeX, I come up with an idea that write a language like LaTeX        */
/*Usage: `fly code.fly`                                                                */
/*Example: (\set{o}{o})\print{\add{Hel}{l$o$} w\if{\eq{$o$}{o}}{orld}\n}               */
/////////////////////////////////////////////////////////////////////////////////////////
/*                                  Note                                               */
/////////////////////////////////////////////////////////////////////////////////////////
/*This language is still in development, so it may not work well.                      */
/*The syntax is not finalized yet.                                                     */
/*Thanks CodeGeeX                                                                      */
/////////////////////////////////////////////////////////////////////////////////////////
/*                                  Todo                                               */
/////////////////////////////////////////////////////////////////////////////////////////
/*1. Add more operators, and normal mode;                                              */
/*2. Add more functions;                                                               */
/*3. Add more macros;                                                                  */
/////////////////////////////////////////////////////////////////////////////////////////
/*Strange code-style ye?                                                               */
/*Oh let's start                                                                       */
/////////////////////////////////////////////////////////////////////////////////////////
#include "toplevel.h"

var var_start;
var * var_last;
function function_start;
function * function_last;
char * name_null="null";
//char * parse(char * code);

int main(int argc, char * argv[]){
	var_start.type=FL_TYPE_NULL;
	var_start.name=name_null;
	var_start.value=(void *)name_null;
	var_start.size=5;
	var_start.next=(var *)-1;
	var_last=&var_start;
	function_start.name=name_null;
	function_start.ip=(void *)-1;
	function_start.next=(function *)-1;
	function_last=&function_start;
	init_function();
	if(argc==0) abort();

	char * code = get_input(argv[1]);
	ctx.code = code;
	printf("%s\n",parse(code,'\0'));
	return 0;
}
int LLVMFuzzerTestOneInput(char *Data, size_t Size) {
	codelen=Size;
	var_start.type=FL_TYPE_NULL;
	var_start.name=name_null;
	var_start.value=(void *)name_null;
	var_start.size=5;
	var_start.next=(var *)-1;
	var_last=&var_start;
	function_start.name=name_null;
	function_start.ip=(void *)0;
	function_start._ip=0;
	function_start.next=(function *)-1;
	function_last=&function_start;
	init_function();
	ctx.code = Data;
  parse(Data,'\0');
  return 0;  // Values other than 0 and -1 are reserved for future use.
}