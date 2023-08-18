#include "toplevel.h"
context ctx;
/*
char * parse(char * code,char end_char){
	char * ret = malloc(sizeof(char)*MAX_STR_LEN);
	memset(ret,0,sizeof(char)*MAX_STR_LEN);
	int pret=0;
	int max_len_plus_times=2;
	while(code[ctx.ip]!=end_char){
		if(code[ctx.ip]=='('){
			ctx.ip++;
			char * tmp = parse(code,')');
			free(tmp);
			goto end;
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
				memset(_ret, 0, MAX_STR_LEN*(max_len_plus_times-1));
				strcpy(_ret,ret);
				strcpy(_ret+pret,tmp);
				pret+=strlen(tmp);
				free(ret);
				//free(tmp);
				ret = _ret;
			}
			free(tmp);
			goto end;
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
				memset(_ret, 0, MAX_STR_LEN*(max_len_plus_times-1));
				strcpy(_ret,ret);
				//ctx.ip++;
				strcat(_ret+pret,"Bad syntax");
				pret+=10;
				free(ret);
				ret = _ret;

			}
			goto end;
		}
		if(code[ctx.ip]=='$'){
			char * var_name=malloc(sizeof(char)*MAX_STR_LEN);
			memset(var_name,0,sizeof(char)*MAX_STR_LEN);
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
					memset(_tmp,0,sizeof(char)*MAX_STR_LEN*(max_len_plus_times_tmp-1));
					strcpy(_tmp,var_name);
					
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
				memset(_ret, 0, MAX_STR_LEN*(max_len_plus_times-1));
				strcpy(_ret,ret);
				strcpy(_ret+pret,tmp);
				pret+=strlen(tmp);
				free(ret);
				
				ret = _ret;
			}
			_dprintf("var_name: %s\n",var_name);
			//free(tmp);
			free(var_name);
			goto end;
		}
		if(code[ctx.ip]=='\\'){
			char * tmp=malloc(sizeof(char)*MAX_STR_LEN);
			memset(tmp,0,sizeof(char)*MAX_STR_LEN);
			int count=0;
			//_dprintf("Fn searching \n");
			while(code[++ctx.ip]!='{'&&
				code[ctx.ip]!=' '&&
				code[ctx.ip]!='\0'&&
				code[ctx.ip]!=end_char) {
					//_dprintf("ctx.ip=%d, char=%c\n",ctx.ip,code[ctx.ip]);
					if(count+1>MAX_STR_LEN){
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
							memset(_ret, 0, MAX_STR_LEN*(max_len_plus_times-1));
							strcpy(_ret,ret);
							//ctx.ip++;
							strcat(_ret+pret,"Bad syntax");
							pret+=10;
							free(ret);
							ret = _ret;

						}
						break;
					}
					tmp[count++]=code[ctx.ip];
			}
			//_dprintf("Fn name:%s\n",tmp);
			while(code[ctx.ip]=='{'){
				++ctx.ip;
				char * _tmp = parse(code,'}');
				//_dprintf("Parse result: %s\n",_tmp);
				//++ctx.ip;
			}
			//--ctx.ip;
			//--ctx.ip;
			//++ctx.ip;
			goto end;
		}
		end:
		if(code[ctx.ip]!='\\'&&
			code[ctx.ip]!='{'&&
			code[ctx.ip]!='$'&&
			code[ctx.ip]!='('&&
			code[ctx.ip]!='['){
			if(pret+2<=MAX_STR_LEN*(max_len_plus_times-1))
				ret[pret++]=code[ctx.ip];
			else{
				char * _ret = malloc(
					sizeof(char)*
					MAX_STR_LEN*
					(max_len_plus_times++));
				memset(_ret, 0, MAX_STR_LEN*(max_len_plus_times-1));
				strcpy(_ret,ret);
				//ctx.ip++;
				ret[pret++]=code[ctx.ip];
				free(ret);
				ret = _ret;
			}
		}
		//else
		ctx.ip++;
	}
	ctx.ip++;
	_dprintf("_Parse_result: %s\n", ret);
	return ret;
}*/

char * parse(char * code, char end){
	char * ret = malloc(sizeof(char)*MAX_STR_LEN);
	memset(ret, 0, MAX_STR_LEN);
	int pret = 0;
	int count = 0;
	int plus_times=1;
	char * tmp ;
	char _tmp[2]={0,0};
	while(code[ctx.ip]!=end){
		switch(code[ctx.ip]){
			case '{':
				ctx.ip++;
				tmp=parse(code,'}');
				ret=str_appened(ret,tmp,&pret,&plus_times);
				break;
			case '(':
				ctx.ip++;
				tmp=parse(code,')');
				break;
			case '$':
				ctx.ip++;
				tmp=parse(code,'$');
				ret=str_appened(ret,tostring(get_var(tmp)),&pret,&plus_times);
				break;
			case '\\':
				ctx.ip++;
			    //char * fn_name=parse(code,'{');
				//char * fn_args=parse(code,'}');
				char * fn_name=get_function_name(code+ctx.ip);
				
				break;
			default:
				//char _tmp[2]={0,0};
				_tmp[0]=code[ctx.ip];
				ret=str_appened(ret,_tmp,&pret,&plus_times);
				break;
		}
		ctx.ip++;
	}
	//ctx.ip++;
	return ret;
}
