#include <stdio.h>
#include "logging.h"

#define TUPLE_LEN 16


char *ep_tostring(int num) {
    static char tuple[TUPLE_LEN];
    
    sprintf(tuple, "%s,%d", "sde", num);
    
    return tuple;
}


int main()
{
	int num = 5;
	
	//ȷ����־����,ֻ�и������õ���־����Ż��ӡ
	log_setlevel(WARN);
	
	//��ӡ������־������3
	log_err("setting server to %s %d", ep_tostring(num), 666);
	//��ӡ������־������2
	log_warn("setting server to %s %d", ep_tostring(num), 666);
	//��ӡ������־������1
	log_info("setting server to %s %d", ep_tostring(num), 666);
	//��ӡ������־������0
	log_debug("setting server to %s %d", ep_tostring(num), 666);
	
	LogLevel level  = log_getlevel();
	printf("LogLevel level %d\n", level);
	
	
	return 0;	
}