#include "../toplevel.h"
char * input = "{\\set{o}{o}}\\add{Hel}{l$o$} w\\if{\\eq{$o$}{o}}{orld}";
char * get_input(){
	return input;
}
void donothing(char* fmt,...){
	//do nothing
}
char * str_appened(char * a, char * b, int * pret, int * max_len_plus_times){
	if(*pret+1+strlen(b) <= MAX_STR_LEN*(*max_len_plus_times-1)){
		strcpy(a+*pret,b);
		*pret+=strlen(b);
		return a;
	}else{
		char * _ret = malloc(
			sizeof(char)*
			MAX_STR_LEN*
			(*(max_len_plus_times)++)
		);
		memset(_ret, 0, MAX_STR_LEN*(*(max_len_plus_times)-1));
		strcpy(_ret,a);
		strcpy(_ret+*pret,b);
		*pret+=strlen(b);
		free(a);
				//free(tmp);
		return _ret;
	}
}