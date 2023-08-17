// A new language
/////////////////////////////////////////////////////////////////////////////////////////
/*                           The Fly(FLy yes) Language                                 */
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

int main(){
	var_start.type=FL_TYPE_NULL;
	var_start.name=name_null;
	var_start.value=(void *)name_null;
	var_start.size=5;
	var_start.next=(var *)-1;
	var_last=&var_start;
	char * code = get_input();
	return printf("%s\n",parse(code,'\0'));
}