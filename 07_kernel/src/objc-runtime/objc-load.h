/*
 * objc-load.h (plan 356).
 *
 * Header of the kernel Objective-C runtime (D045, D046, D047).
 * The text is nearly the same as Darwin 0.1 objc-1 objc-load.h; kept as
 * project-authored under D030/D047, without Darwin's notices (license
 * judgement: D017).
 */

#ifndef _OBJC_LOAD_H_
#define _OBJC_LOAD_H_

#import "objc.h"
#import "objc-class.h"
#import <streams/streams.h>
#import <mach-o/loader.h>

/* dynamically loading Mach-O object files that contain Objective-C code */

extern long objc_loadModules(
	char *moduleList[], 				/* input */
	NXStream *errorStream,				/* input (optional) */
	void (*loadCallback)(Class, Category),		/* input (optional) */
	struct mach_header **headerAddr,		/* output (optional) */
	char *debugFileName				/* input (optional) */
);

extern long objc_unloadModules(
	NXStream *errorStream,				/* input (optional) */
	void (*unloadCallback)(Class, Category)		/* input (optional) */
);

#endif /* _OBJC_LOAD_H_ */
