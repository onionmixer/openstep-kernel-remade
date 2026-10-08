/*
 * objc.h (plan 356).
 *
 * Header of the kernel Objective-C runtime (D045, D046, D047).
 * The text is nearly the same as Darwin 0.1 objc-1 objc.h; kept as
 * project-authored under D030/D047, without Darwin's notices (license
 * judgement: D017).
 */

#ifndef _OBJC_OBJC_H_
#define _OBJC_OBJC_H_

typedef struct objc_class *Class;

typedef struct objc_object {
	Class isa;
} *id;

typedef struct objc_selector 	*SEL;    
typedef char *			STR;
typedef id 			(*IMP)(id, SEL, ...); 
typedef char			BOOL;

extern BOOL sel_isMapped(SEL sel);
extern const char *sel_getName(SEL sel);
extern SEL sel_getUid(const char *str);
extern SEL sel_registerName(const char *str);
extern const char *object_getClassName(id obj);
extern void *object_getIndexedIvars(id obj);

#define YES             (BOOL)1
#define NO              (BOOL)0
#define ISSELECTOR(sel) sel_isMapped(sel)
#define SELNAME(sel)	sel_getName(sel)
#define SELUID(str)	sel_getUid(str)
#define NAMEOF(obj)     object_getClassName(obj)
#define IV(obj)         object_getIndexedIvars(obj)

#define Nil (Class)0           /* id of Nil class */
#define nil (id)0              /* id of Nil instance */

#endif /* _OBJC_OBJC_H_ */
