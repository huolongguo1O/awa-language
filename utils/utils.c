#include "../toplevel.h"
char * input = "11111111111111111111111111111111111111111111111111111";
char * get_input(){
	return input;
}
void donothing(char* fmt,...){
	//do nothing
}
char * str_appened(char * a, char * b, int * pret, int * max_len_plus_times){
	_dprintf("str_appened called, %s %s %d %d %n %n\n", a, b, *pret, *max_len_plus_times, pret, max_len_plus_times);
	if(*pret+1+strlen(b) <= MAX_STR_LEN*(*max_len_plus_times)){
		strcpy(a+*pret,b);
		*pret+=strlen(b);
		return a;
	}else{
		*max_len_plus_times += 1;
		char * _ret = malloc(
			sizeof(char)*
			MAX_STR_LEN*
			(*(max_len_plus_times))
		);
		_dprintf("%n, %d\n",(int )_ret,*(max_len_plus_times));
		memset(_ret, 0, MAX_STR_LEN*(*(max_len_plus_times)-1));
		strcpy(_ret,a);
		strcpy(_ret+*pret,b);
		*pret+=strlen(b);
		free(a);
				//free(tmp);
		return _ret;
	}
}