#include "lib_logging.h"

//���Դ�ӡ��־����ͼ���ֻ�и����������Ż��ӡ��־
static LogLevel CURRENT_LEVEL = INFO;


/*
* ��������: log_setlevel
* ��������: ���ô�ӡ��־����ͼ���
* ��    ��: 
*			
* �� �� ֵ: ��
*/
void log_setlevel(LogLevel level) 
{
    CURRENT_LEVEL = level;
}

/*
* ��������: log_getlevel
* ��������: �鿴��ӡ����־����
* ��    ��: 
*			
* �� �� ֵ: ��
*/
LogLevel log_getlevel() {
    return CURRENT_LEVEL;
}

/*
* ��������: levelstr
* ��������: ���ز�ͬ������־��Ӧ�����
* ��    ��: 
*			
* �� �� ֵ: ��
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
* ��������: log_msg
* ��������: ��ӡ��־
* ��    ��: level��Ҫ��ӡ����־����
*			msg��Ҫ��ӡ������
*			
* �� �� ֵ: ��
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
