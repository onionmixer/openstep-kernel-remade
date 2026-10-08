/*
 * A List object for C-strings.
 *
 * Its sole purpose is to make whitespace-separated lists of words
 * easier to deal with, since we use them a lot in driverkit string tables.
 *
 *
 */
 
#import <objc/Object.h>

@interface KernStringList : Object
{
@private
    char	**strings;
    unsigned	count;
}

/*
 * Takes a whitespace-separated list of words,
 * and separates it into a list of null-terminated strings.
 */
- initWithWhitespaceDelimitedString:(const char *)string;

- (unsigned)count;
- (const char *)stringAt:(unsigned)index;
- (const char *)lastString;

@end
