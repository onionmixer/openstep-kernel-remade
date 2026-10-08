/*
 * objc-msg.s (plan 360). Kernel Objective-C runtime source: the message
 * dispatch wrapper of the kernel Objective-C runtime, OPENSTEP 4.2
 * kernel (D045, D046, D047; text 0x1ce960-0x1cec2d). With -DKERNEL
 * objc-config.h leaves OBJC_COLLECTING_CACHE undefined, so this file
 * includes objc-msg-i386-lock.s. The text is nearly the same as Darwin
 * 0.1 objc-1 objc-msg.s; kept as project-authored under D030/D047,
 * without Darwin's notices (license judgement: D017).
 */

#import "objc-config.h"

#if defined (m68k)
#if defined(OBJC_COLLECTING_CACHE)
#include "objc-msg-m68k-nolock.s"
#elif  defined(OBJC_COPY_CACHE)
#include "objc-msg-m68k-copycache-lock.s"
#else
#include "objc-msg-m68k-lock.s"
#endif

#elif defined (i386)
#if defined(OBJC_COLLECTING_CACHE)
#include "objc-msg-i386-nolock.s"
#elif  defined(OBJC_COPY_CACHE)
#include "objc-msg-i386-copycache-lock.s"
#else
#include "objc-msg-i386-lock.s"
#endif

#elif defined (ppc)
#include "objc-msg-ppc.s"

#elif defined (hppa)
#if defined(OBJC_COLLECTING_CACHE)
#include "objc-msg-hppa-nolock.s"
#elif defined(OBJC_COPY_CACHE)
#include "objc-msg-hppa-copycache-lock.s"
#else
#include "objc-msg-hppa-lock.s"
#endif

#elif defined (sparc)
#include "objc-msg-sparc.s"
#else
#error Architecture not supported
#endif
