/*
 * KernStringList.m (plan 304).
 *
 * Written for this project from the OPENSTEP 4.2 kernel bytes (D024,
 * original module "/BinarySourceCache_Mario1A/mk/mk-183.34.4/driverkit/KernStringList.m", methods 0x181a60-0x181c97).
 * The text is nearly the same as Darwin 0.1
 * kernel/driverkit/KernStringList.m; kept as project-authored
 * under D027/D030, without Darwin's notices (license judgement: D017).
 */

#import "KernStringList.h"

#define isspace(c) (((c) == ' ') || ((c) == '\t') || ((c) == '\n'))

static void *my_malloc(unsigned len)
{
#if KERNEL
    extern void *IOMalloc(int);
    return IOMalloc(len);
#else
    extern void *malloc(unsigned);
    void *ptr = malloc(len);
    char *p = (char *)ptr;
    
    while (len--)
	*p++ = 'X';
    return ptr;
#endif
}

static void my_free(void *ptr, unsigned len)
{
#if KERNEL
    extern void IOFree(void *, int);
    IOFree(ptr, len);
#else
    extern void free(void *);
    free(ptr);
#endif
}

@implementation KernStringList

- init
{
    return [self initWithWhitespaceDelimitedString:NULL];
}


- initWithWhitespaceDelimitedString:(const char *)str
{
    char *sp;
    int index;
    unsigned len;
    extern int strncpy(char *,const char *, int);
    
    [super init];

    while (*str && isspace(*str))
	str++;

    sp = (char *)str;
    while (*sp) {
	while (*sp && isspace(*sp))
	    sp++;
	if (*sp)
	    count++;
	while (*sp && !isspace(*sp))
	    sp++;
    }
    
    strings = (char **)my_malloc(sizeof(char *) * count);

    for (index = 0; str && *str; index++) {
	char *s;
	
	for (sp = (char *)str; *sp && !isspace(*sp); sp++)
	    continue;
	len = sp - str + 1;
	s = strings[index] = (char *)my_malloc(len);
	strncpy(s, str, len - 1);
	s[len - 1] = '\0';
	for (str = sp; *str && isspace(*str); str++)
	    continue;
    }
    return self;
}

- free
{
    int i;
    
    for (i=0; i<count; i++) {
	my_free((char *)strings[i], strlen(strings[i])+1);
    }
    my_free(strings, sizeof(char *) * count);
    return [super free];
}

- (unsigned)count
{
    return count;
}

- (const char *)stringAt:(unsigned)index
{
    if (index >= 0 && index < count)
	return strings[index];
    return NULL;
}

- (const char *)lastString
{
    return strings[count - 1];
}


@end
