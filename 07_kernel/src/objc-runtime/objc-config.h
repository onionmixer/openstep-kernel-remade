/*
 * objc-config.h (plan 356).
 *
 * Header of the kernel Objective-C runtime (D045, D046, D047).
 * The text is nearly the same as Darwin 0.1 objc-1 objc-config.h; kept as
 * project-authored under D030/D047, without Darwin's notices (license
 * judgement: D017).
 */

#ifndef KERNEL
#ifndef SHLIB
#define RUNTIME_DYLD 1
#endif
#endif

/* Turn on support for class refs. */
#define OBJC_CLASS_REFS

#if defined(hppa) || defined (i386) || defined (m68k)
#if !defined(KERNEL) && !defined(SHLIB)
#define OBJC_COLLECTING_CACHE
#endif
#endif

#ifdef FREEZE
#define __S(x) __objcopt ## x
#else
#define __S(x) x
#endif

