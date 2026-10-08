/*
 * objc-errors.m (plan 356).
 *
 * Kernel Objective-C runtime source of the OPENSTEP 4.2 kernel (D045,
 * D046, D047; original module "objc-errors.m", text 0x1cdd10-0x1cde3f).
 * The text is nearly the same as Darwin 0.1 objc-1 objc-errors.m; kept as
 * project-authored under D030/D047, without Darwin's notices (license
 * judgement: D017).
 */

#ifdef SHLIB
#import "shlib.h"
#endif SHLIB

#include <stdarg.h>
#import <syslog.h>

#import "objc-private.h"

/*	
 *	this routine handles errors that involve an object (or class).
 */
volatile void __objc_error(id rcv, const char *fmt, ...) 
{ 
	va_list vp; 

	va_start(vp,fmt); 
	(*_error)(rcv, fmt, vp); 
	va_end(vp);
	_objc_error (rcv, fmt, vp);	/* In case (*_error)() returns. */
}

#ifndef KERNEL

static int hasTerminal()
{
    static char hasTerm = -1;

    if (hasTerm == -1) {
	int fd = open("/dev/tty", O_RDWR, 0);
	if (fd >= 0) {
	    (void)close(fd);
	    hasTerm = 1;
	} else
	    hasTerm = 0;
    }
    return hasTerm;
}

void _NXLogError(const char *format, ...)
{
    va_list ap;
    char bigBuffer[4*1024];

    va_start(ap, format);
    vsprintf(bigBuffer, format, ap);
    va_end(ap);
    if (hasTerminal()) {
	fwrite(bigBuffer, sizeof(char), strlen(bigBuffer), stderr);
	if (bigBuffer[strlen(bigBuffer)-1] != '\n')
	    fputc('\n', stderr);
    } else
	syslog(LOG_ERR, "%s", bigBuffer);
}

/*
 * 	this routine is never called directly...it is only called indirectly
 * 	through "_error", which can be overriden by an application. It is
 *	not declared static because it needs to be referenced in 
 *	"objc-globaldata.m" (this file organization simplifies the shlib
 *	maintenance problem...oh well). It is, however, a "private extern".
 */
volatile void _objc_error(id self, const char *fmt, va_list ap) 
{ 
    char bigBuffer[4*1024];

    vsprintf (bigBuffer, fmt, ap);
    _NXLogError ("objc: %s: %s", object_getClassName (self), bigBuffer);

    abort();		/* generates a core file */
}

/*	
 *	this routine handles severe runtime errors...like not being able
 * 	to read the mach headers, allocate space, etc...very uncommon.
 */
volatile void _objc_fatal(const char *msg)
{
    _NXLogError("objc: %s\n", msg);

    exit(1);
}

/*
 *	this routine handles soft runtime errors...like not being able
 *      add a category to a class (because it wasn't linked in).
 */
void _objc_inform(const char *fmt, ...)
{
    va_list ap; 
    char bigBuffer[4*1024];

    va_start (ap,fmt); 
    vsprintf (bigBuffer, fmt, ap);
    _NXLogError ("objc: %s", bigBuffer);
    va_end (ap);
}

#else /* not KERNEL */

extern int vlog(int level, const char *format, va_list ap);
extern volatile void panic(const char *reason);

/* special panic versions of the objc error routines */

void _NXLogError(const char *format, ...)
{
        va_list ap;
        
        va_start(ap, format);
        vlog(LOG_ERR, format, ap);
        va_end(ap);
	if(format[strlen(format)-1] != '\n') {
		log(LOG_ERR, "\n");
	}
}

volatile void _objc_error(id self, const char *fmt, va_list ap) 
{ 
	log(LOG_ERR, "objc error: %s ", object_getClassName(self));
	vlog(LOG_ERR, fmt, ap);
	if(fmt[strlen(fmt)-1] != '\n') {
		log(LOG_ERR, "\n");
	}
	abort();
}

volatile void _objc_fatal(const char *msg)
{
	printf("objc fatal: %s\n", msg);
	panic("Objective-C fatal");
}

void _objc_inform(const char *fmt, ...)
{
        va_list ap;

        va_start(ap, fmt);
	vlog(LOG_ERR, fmt, ap);
	va_end(ap);
	if(fmt[strlen(fmt)-1] != '\n') {
		log(LOG_ERR, "\n");
	}
}

#endif /* not KERNEL */
