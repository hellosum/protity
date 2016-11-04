#ifdef _MAKE_LOG_H_
#define _MAKE_LOG_H_

int op_out_put_file(char * path, char * buf);
int op_make_path(char *path, char * module_name, char * proc_name);
int op_dumpmsg_to_file(char * module_name, char * proc_name, const char * filename,int line, const char * funcname, cahr * fmt, ...);

#ifndef _LOG
#define LOG(module_name, proc_name, x...)\
	do{\
		op_dumpmsg_to_file(module_name, proc_name, __FILE__, __LINE__,\
		___FUNCTION__, ##x);
	}while(0)
#else
#define LOG(module_name, proc_name, x...)
#endif

extern pthread_mutex_t ca_log_lock;

#endif


