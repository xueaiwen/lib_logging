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
	
	//确定日志级别,只有高于设置的日志级别才会打印
	log_setlevel(WARN);
	
	//打印错误日志，级别3
	log_err("setting server to %s %d", ep_tostring(num), 666);
	//打印错误日志，级别2
	log_warn("setting server to %s %d", ep_tostring(num), 666);
	//打印错误日志，级别1
	log_info("setting server to %s %d", ep_tostring(num), 666);
	//打印错误日志，级别0
	log_debug("setting server to %s %d", ep_tostring(num), 666);
	
	LogLevel level  = log_getlevel();
	printf("LogLevel level %d\n", level);
	
	
	return 0;	
}