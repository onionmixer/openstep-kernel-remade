/*
 * IOConfigTable.m (plan 323).
 *
 * Written for this project from the OPENSTEP 4.2 kernel bytes (D024,
 * original module "Kernel/IOConfigTable.m", functions and methods 0x1a5220-0x1a5447).
 * The text is nearly the same as Darwin 0.1
 * driverkit-1/libDriver/Kernel/IOConfigTable.m; kept as project-authored
 * under D027/D030, without Darwin's notices (license judgement: D017).
 */

#import <driverkit/IOConfigTable.h>
#import <driverkit/configTableKern.h>
#import <driverkit/configTablePrivate.h>
#import <driverkit/generalFuncs.h>
#if i386
/*
 * plan 323 (D035): no i386 <machdep/i386/kernBootStruct.h> in any reference
 * tree.  The boot loader's parameter block at physical 0x11000; only the
 * field used here, at the original's offset.
 */
typedef struct {
	char	_reserved0[0x24fc];
	char	config[1];		/* +0x24fc */
} KERNBOOTSTRUCT;
#define	KERNSTRUCT_ADDR	((KERNBOOTSTRUCT *) 0x11000)
#endif i386
#import <string.h>

/*
 * This really should be static, but it has a prototype in <ansi/string.h>.
 */
char *strstr(const char *s1, const char *s2);

/*
 * The _private ivar is a char *. 
 */
@implementation IOConfigTable

- free
{
	char *configData = (char *)_private;
	
	if(configData) {
		IOFree(configData, strlen(configData)+1);
	}
	return [super free];
}

/*
 * Obtain the system-wide configuration table.
 */
+ newFromSystemConfig
{
#if i386
	KERNBOOTSTRUCT *bootstruct = KERNSTRUCT_ADDR;
	return [self newForConfigData: &bootstruct->config[0]];
#else i386
	/* 
	 * FIXME - where is KERNBOOTSTRUCT?
	 */
	return nil;
#endif i386
}

/*
 * Obtain value for specified string key. Returns null of key not
 * found.
 * The string here must eventually be freed (by the caller) via
 * IOFree(buf, strlen(buf) + 1). This is kinda bogus...
 */
- (const char *)valueForStringKey:(const char *)key
{
	const char *configData = (char *)_private;
	const char *valueEnd;
	const char *valueStart;
	char *out;
	int length;
	
	length = strlen(key);
	{
	    char	quotedkey[length + 3];
	    
	    quotedkey[0] = '"';
	    strcpy(&quotedkey[1], key);
	    quotedkey[length + 1] = '"';
	    quotedkey[length + 2] = 0;
	    
	    valueStart = strstr(configData, quotedkey);
	    if (valueStart == NULL)
	    	return NULL;
		
	    valueStart += (length + 2);	// point past the quoted key
	}
	
	/*
	 * ValueStart points just past the quoted key
	 */
	valueStart = strchr(valueStart, '"');
	valueStart++;
	
	/*
	 * valueStart points to the first character of the desired value.
	 */
	valueEnd = strchr(valueStart, '"');
	if (valueEnd != NULL) {
		length = valueEnd - valueStart;
		out = IOMalloc(length + 1);
		strncpy(out, valueStart, length);
		out[length] = '\0';
		return out;
	}
	else {
		return NULL;
	}
}


+ (void)freeString : (const char *)string
{
	IOFree((char *)string, strlen(string) + 1);
}

- (void)freeString : (const char *)string
{
	[IOConfigTable freeString:string];
}	


@end

@implementation IOConfigTable(KernelPrivate)

/*
 * Create a new instance for specified IOConfigData text. 
 */
+ newForConfigData : (const char *)configData
{
	IOConfigTable *configTable = [self alloc];	/* plan 323: no init in the original */
	char *data;
	int ssize = strlen(configData) + 1;
	
	if(ssize > IO_CONFIG_DATA_SIZE) {
		ssize = IO_CONFIG_DATA_SIZE;
	}
	data = IOMalloc(ssize);
	bcopy(configData, data, ssize-1);
	data[ssize-1] = 0;
	configTable->_private = data;
	return configTable;
}

@end

/* 
 * Like strchr, but searches for a string. Returns pointer to start of 
 * the found string, else returns NULL.
 */
char *strstr(const char *s1, const char *s2) {
	char c1;
  	const char c2 = *s2;

	while ((c1 = *s1++) != '\0') {
		if (c1 == c2) {
			const char *p1, *p2;

			p1 = s1;
			p2 = &s2[1];
			while (*p1++ == (c1 = *p2++) && c1) {
				continue;
			}
			if (c1 == '\0') {
				return ((char *)s1) - 1;
			}
	     }
      }
      return NULL;
}
