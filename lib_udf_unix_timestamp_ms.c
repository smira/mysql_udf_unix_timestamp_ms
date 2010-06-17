#if defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(WIN32)
#define DLLEXP __declspec(dllexport) 
#else
#define DLLEXP
#endif

#ifdef STANDARD
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#ifdef __WIN__
typedef unsigned __int64 ulonglong;
typedef __int64 longlong;
#else
typedef unsigned long long ulonglong;
typedef long long longlong;
#endif /*__WIN__*/
#else
#include <my_global.h>
#include <my_sys.h>
#endif
#include <mysql.h>
#include <m_ctype.h>
#include <m_string.h>
#include <stdlib.h>

#include <ctype.h>

#ifdef	__cplusplus
extern "C" {
#endif

DLLEXP 
my_bool unix_timestamp_ms_init(
	UDF_INIT *initid
,	UDF_ARGS *args
,	char *message
);

DLLEXP 
void unix_timestamp_ms_deinit(
	UDF_INIT *initid
);

DLLEXP 
double unix_timestamp_ms(
	UDF_INIT *initid
,	UDF_ARGS *args
,	char *is_null
,	char *error
);

#ifdef	__cplusplus
}
#endif

my_bool unix_timestamp_ms_init(
	UDF_INIT *initid
,	UDF_ARGS *args
,	char *message
){
	my_bool status;
	if(args->arg_count!=0){
		strcpy(
			message
		,	"No arguments allowed (udf: lib_mysqludf_json_info)"
		);
		status = 1;
	} else {
		status = 0;
	}
	return status;
}

void unix_timestamp_ms_deinit(
	UDF_INIT *initid
){	
}

double unix_timestamp_ms(
	UDF_INIT *initid
,	UDF_ARGS *args
,	char *is_null
,	char *error
){
    struct timeval now;

    gettimeofday(&now, NULL);

    return now.tv_sec + now.tv_usec / 1000000.0;
}

