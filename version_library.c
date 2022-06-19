#include "version_library.h"




/* helper functions */
#define _MONTH_IS_JAN(d)    (d[0] == 'J' && d[1] == 'a' && d[2] == 'n')
#define _MONTH_IS_FEB(d)    (d[0] == 'F')
#define _MONTH_IS_MAR(d)    (d[0] == 'M' && d[1] == 'a' && d[2] == 'r')
#define _MONTH_IS_APR(d)    (d[0] == 'A' && d[1] == 'p')
#define _MONTH_IS_MAY(d)    (d[0] == 'M' && d[1] == 'a' && d[2] == 'y')
#define _MONTH_IS_JUN(d)    (d[0] == 'J' && d[1] == 'u' && d[2] == 'n')
#define _MONTH_IS_JUL(d)    (d[0] == 'J' && d[1] == 'u' && d[2] == 'l')
#define _MONTH_IS_AUG(d)    (d[0] == 'A' && d[1] == 'u')
#define _MONTH_IS_SEP(d)    (d[0] == 'S')
#define _MONTH_IS_OCT(d)    (d[0] == 'O')
#define _MONTH_IS_NOV(d)    (d[0] == 'N')
#define _MONTH_IS_DEC(d)    (d[0] == 'D')


/* get macros */
#define GET_MONTH(d)        ((_MONTH_IS_JAN(d)) ?  1 : \
                             (_MONTH_IS_FEB(d)) ?  2 : \
                             (_MONTH_IS_MAR(d)) ?  3 : \
                             (_MONTH_IS_APR(d)) ?  4 : \
                             (_MONTH_IS_MAY(d)) ?  5 : \
                             (_MONTH_IS_JUN(d)) ?  6 : \
                             (_MONTH_IS_JUL(d)) ?  7 : \
                             (_MONTH_IS_AUG(d)) ?  8 : \
                             (_MONTH_IS_SEP(d)) ?  9 : \
                             (_MONTH_IS_OCT(d)) ? 10 : \
                             (_MONTH_IS_NOV(d)) ? 11 : \
                             12)

#define GET_DAY(d)          (((d[4] >= '0') ? (d[4] - '0') * 10 : 0) + (d[5] - '0'))

#define GET_YEAR(d)         ((d[7] - '0') * 1000 + (d[8] - '0') *  100 + (d[9] - '0') *   10 + (d[10] - '0'))


/* get date timestamp macro */
#define GET_DATE(d)         ((GET_YEAR(d) * 10000) + (GET_MONTH(d) * 100) + GET_DAY(d))

/* get macros */
#define GET_HOUR(d)                 ((d[0] - '0') * 10 + d[1] - '0')

#define GET_MINUTE(d)               ((d[3] - '0') * 10 + d[4] - '0')

#define GET_SECOND(d)               ((d[6] - '0') * 10 + d[7] - '0')


/* get time timestamp macro */
#define GET_TIME(d)                 ((GET_HOUR(d) * 10000) + (GET_MINUTE(d) * 100) + GET_SECOND(d))




/* library name */
const char LIB_NAME[] = "CMacroLibrary";

/* library version major, minor */
const int  LIB_VERSION_MAJOR = 1;
const int  LIB_VERSION_MINOR = 4;


/* library version buid specification */
char* Version_GetName(void)
{
	return((char*)&LIB_NAME);
}

unsigned long Version_GetMajor(void)
{
	return((unsigned long)LIB_VERSION_MAJOR);
}

unsigned long Version_GetMinor(void)
{
	return((unsigned long)LIB_VERSION_MINOR);
}

unsigned long Version_GetBuild(void)
{
	return((unsigned long)GET_DATE(__DATE__));
}

unsigned long Version_GetRevision(void)
{
	return((unsigned long)GET_TIME(__TIME__));
}
