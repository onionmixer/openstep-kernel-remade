/*
 * objc-globaldata.m (plan 397, 398). Kernel Objective-C runtime source: the
 * runtime hook pointers (_poseAs ... _zoneRealloc) of the OPENSTEP 4.2
 * kernel, __DATA,__data [0x1e55b8, 0x1e55e4) 44 B (no module record; SHLIB
 * not defined). The text is nearly the same as Darwin 0.1 objc-1
 * objc-globaldata.m; kept as project-authored under D030/D047, without
 * Darwin's notices (license judgement: D017).
 */

#ifdef SHLIB
#import "shlib.h"
#endif SHLIB

#import "objc-private.h"
#import "objc-class.h"
#import <objc/zone.h>

/*
 * Declarations of non-const global data.
 */
extern id _internal_class_createInstance(Class, unsigned);
extern id _internal_class_createInstanceFromZone(Class, unsigned, NXZone *);
extern id _internal_object_dispose(id);
extern id _internal_object_realloc(id, unsigned);
extern id _internal_object_reallocFromZone(id, unsigned, NXZone *);
extern id _internal_object_copy(id, unsigned);
extern id _internal_object_copyFromZone(id, unsigned, NXZone *);

id (*_poseAs)() = (id (*)())class_poseAs;
id (*_alloc)(Class, unsigned) = _internal_class_createInstance;
id (*_copy)(id, unsigned) = _internal_object_copy;
id (*_realloc)(id, unsigned) = _internal_object_realloc;
id (*_dealloc)(id)  = _internal_object_dispose;

id (*_cvtToId)(const char *)= objc_lookUpClass;
SEL (*_cvtToSel)(const char *)= sel_getUid;
void (*_error)() = (void(*)())_objc_error;

id (*_zoneAlloc)(Class, unsigned, NXZone *) = _internal_class_createInstanceFromZone;
id (*_zoneCopy)(id, unsigned, NXZone *) = _internal_object_copyFromZone;
id (*_zoneRealloc)(id, unsigned, NXZone *) = _internal_object_reallocFromZone;

#ifdef SHLIB
char _objc_global_data_pad[468] = {0};
#endif