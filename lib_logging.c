#include "lib_logging.h"

//可以打印日志的最低级别，只有高于这个级别才会打印日志
static LogLevel CURRENT_LEVEL = INFO;


/*
* 函数名称: log_setlevel
* 函数功能: 设置打印日志的最低级别
* 参    数: 
*			
* 返 回 值: 无
*/
void log_setlevel(LogLevel level) 
{
    CURRENT_LEVEL = level;
}

/*
* 函数名称: log_getlevel
* 函数功能: 查看打印的日志级别
* 参    数: 
*			
* 返 回 值: 无
*/
LogLevel log_getlevel() {
    return CURRENT_LEVEL;
}

/*
* 函数名称: levelstr
* 函数功能: 返回不同级别日志对应的输出
* 参    数: 
*			
* 返 回 值: 无
*/
const char *levelstr(LogLevel level) {
    switch (level) {
        case DEBUG:
            return "DBG";
        case INFO:
            return "INF";
        case WARN:
            return "WAR";
        case ERROR:
            return "ERR";
        default:
            return "???";
    }
}

/*
* 函数名称: log_msg
* 函数功能: 打印日志
* 参    数: level：要打印的日志级别
*			msg：要打印的内容
*			
* 返 回 值: 无
*/
void log_msg(LogLevel level, const char *msg, ...) {
    if (level < CURRENT_LEVEL) return;
    va_list ap;
    va_start(ap, msg);
    char fmt[LOGBUF] = {0};
    char timestamp[26];
    struct timeb tp;
    ftime(&tp);
    struct tm *st = localtime(&tp.time);
    sprintf(timestamp, "%02d:%02d:%02d.%03d",
            st->tm_hour, st->tm_min, st->tm_sec, tp.millitm);
    sprintf(fmt, "%s %s: ", timestamp, levelstr(level));
    strcat(fmt, msg);
    strcat(fmt, "\n");
    vprintf(fmt, ap);
    va_end(ap);
}
