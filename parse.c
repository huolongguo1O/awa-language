#include "toplevel.h"
context ctx;
char * parse(char * code,char end_char){
	char * ret = malloc(sizeof(char)*MAX_STR_LEN);
	int pret=0;
	int max_len_plus_times=2;
	while(code[ctx.ip]!=end_char){
		if(code[ctx.ip]=='('){
			ctx.ip++;
			char * tmp = parse(code,')');
			free(tmp);
		}
		if(code[ctx.ip]=='{'){
			ctx.ip++;
			char * tmp = parse(code,'}');
			if(pret+1+strlen(tmp) <= MAX_STR_LEN*(max_len_plus_times-1)){
				strcpy(ret+pret,tmp);
				pret+=strlen(tmp);
			}
			else{
				char * _ret = malloc(
					sizeof(char)*
					MAX_STR_LEN*
					(max_len_plus_times++)
				);
				strcpy(_ret,ret);
				strcpy(_ret+pret,tmp);
				pret+=strlen(tmp);
				free(ret);
				free(tmp);
				ret = _ret;
			}
			free(tmp);
		}
		if(code[ctx.ip]=='['){
			if(pret+1+10 <= MAX_STR_LEN*(max_len_plus_times-1)){
				strcpy(ret+pret,"Bad syntax");
				pret+=10;
			}
			else{
				char * _ret = malloc(
					sizeof(char)*
					MAX_STR_LEN*
					(max_len_plus_times++)
				);
				strcpy(_ret,ret);
				//ctx.ip++;
				strcat(_ret+pret,"Bad syntax");
				pret+=10;
				free(ret);
				ret = _ret;

			}
		}
		if(code[ctx.ip]=='$'){
			char * var_name=malloc(sizeof(char)*MAX_STR_LEN);
			int pvar_name=0;
			int max_len_plus_times_tmp=2;
			while(code[++ctx.ip]!='$'){
				if(pvar_name+2>MAX_STR_LEN*(max_len_plus_times_tmp-1)){
					var_name[pvar_name++]=code[ctx.ip];
				}else{
					char * _tmp = malloc(
						sizeof(char)*
						MAX_STR_LEN*
						(max_len_plus_times_tmp++)
					);
					strcpy(_tmp,var_name);
					free(var_name);
					var_name=_tmp;
					var_name[pvar_name++]=code[ctx.ip];
				}
			}
			char * tmp=tostring(get_var(var_name));
			if(pret+1+strlen(tmp) <= MAX_STR_LEN*(max_len_plus_times-1)){
				strcat(ret+pret,tmp);
				pret+=strlen(tmp);
			}
			else{
				char * _ret = malloc(
					sizeof(char)*
					MAX_STR_LEN*
					(max_len_plus_times++)
				);
				strcpy(_ret,ret);
				strcpy(_ret+pret,tmp);
				pret+=strlen(tmp);
				free(ret);
				free(tmp);
				ret = _ret;
			}
		}
		if(code[ctx.ip]=='\\')
		ctx.ip++;
	}
	return ret;
}