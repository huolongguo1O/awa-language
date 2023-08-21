#include "../toplevel.h"
int codelen;
char * input = "(\\set{aa}{bb})$aa$";
int isoverflow = 0;
char * get_input(){
	codelen=strlen(input);
	return input;
}
void donothing(char* fmt,...){
	//do nothing
}
char * str_appened(char * a, char * b, int * pret, int * max_len_plus_times){
	_dprintf("str_appened called, %s %s %d %d %x %x\n", a, b, *pret, *max_len_plus_times, pret, max_len_plus_times);
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
		_dprintf("%x, %d\n",_ret,*(max_len_plus_times));
		memset(_ret, 0, MAX_STR_LEN*(*(max_len_plus_times)-1));
		strcpy(_ret,a);
		strcpy(_ret+*pret,b);
		*pret+=strlen(b);
		free(a);
				//free(tmp);
		return _ret;
	}
}
int _check_overflow(){
	return ctx.ip < codelen+1 ? 0 : 1;
}
void check_overflow(){
	if(_check_overflow()){
		printf("Overflowed! \n");
		//abort();
		isoverflow = 1;
	}
}