/*
 * objc-runtime.h (plan 356).
 *
 * Header of the kernel Objective-C runtime (D045, D046, D047).
 * The text is nearly the same as Darwin 0.1 objc-1 objc-runtime.h; kept as
 * project-authored under D030/D047, without Darwin's notices (license
 * judgement: D017).
 */

#ifndef _OBJC_RUNTIME_H_
#define _OBJC_RUNTIME_H_

#import "objc.h"
#import "objc-class.h"
#import "hashtable.h"
#import "Object.h"

typedef struct objc_symtab *Symtab;

struct objc_symtab {
	unsigned long 	sel_ref_cnt;
	SEL 		*refs;		
	unsigned short 	cls_def_cnt;
	unsigned short 	cat_def_cnt;
	void  		*defs[1];	/* variable size */
};

typedef struct objc_module *Module;

struct objc_module {
	unsigned long	version;
	unsigned long	size;
	const char	*name;
	Symtab 		symtab;	
};

struct objc_super {
	id receiver;
	Class class;
};

/* kernel operations */

extern id objc_getClass(const char *name);
extern id objc_getMetaClass(const char *name);
extern id objc_msgSend(id self, SEL op, ...);
extern id objc_msgSendSuper(struct objc_super *super, SEL op, ...);

/* forwarding operations */

extern id objc_msgSendv(id self, SEL op, unsigned arg_size, marg_list arg_frame);

/* 
   iterating over all the classes in the application...
  
   NXHashTable *class_hash = objc_getClasses();
   NXHashState state = NXInitHashState(class_hash);
   Class class;
  
   while (NXNextHashState(class_hash, &state, &class)
     ...;
 */
extern NXHashTable *objc_getClasses();
extern Module *objc_getModules();
extern id objc_lookUpClass(const char *name);
extern void objc_addClass(Class myClass);

/* customizing the error handling for objc_getClass/objc_getMetaClass */

extern void objc_setClassHandler(int (*)(const char *));

/* Making the Objective-C runtime thread safe. */
extern void objc_setMultithreaded (BOOL flag);

/* overriding the default object allocation and error handling routines */

extern id	(*_alloc)(Class, unsigned int);
extern id	(*_copy)(Object *, unsigned int);
extern id	(*_realloc)(Object *, unsigned int);
extern id	(*_dealloc)(Object *);
extern id	(*_zoneAlloc)(Class, unsigned int, NXZone *);
extern id	(*_zoneRealloc)(Object *, unsigned int, NXZone *);
extern id	(*_zoneCopy)(Object *, unsigned int, NXZone *);
extern void	(*_error)(Object *, const char *, va_list);

#endif /* _OBJC_RUNTIME_H_ */
