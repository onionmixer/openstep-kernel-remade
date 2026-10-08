/*
 * objc-globaltext.m (plan 360). Kernel Objective-C runtime source: the
 * hash and map table prototype constants of the kernel Objective-C
 * runtime, OPENSTEP 4.2 kernel (D045, D046, D047; no module record, text
 * 0x1cde40-0x1cdeb0, 7 const data definitions). The text is nearly the
 * same as Darwin 0.1 objc-1 objc-globaltext.m; kept as project-authored
 * under D030/D047, without Darwin's notices (license judgement: D017).
 */

/* Required for compatiblity with 1.0 to turn off .const and .cstring */
#if !defined(__DYNAMIC__)
#pragma CC_NO_MACH_TEXT_SECTIONS
#endif

#ifdef SHLIB
#import "shlib.h"
#endif SHLIB

#import "hashtable.h"
#import "maptable.h"

/*
 * Global const data would go here and would look like:
 * 	const int foo = 1;
 */	
/*
 * hashtable globals
 */

extern unsigned hashPtrStructKey (const void *info, const void *data);
extern int isEqualPtrStructKey (const void *info, const void *data1, const void *data2);
extern unsigned hashStrStructKey (const void *info, const void *data);
extern int isEqualStrStructKey (const void *info, const void *data1, const void *data2);

const NXHashTablePrototype NXPtrPrototype = {
    NXPtrHash, NXPtrIsEqual, NXNoEffectFree, 0
    };
const NXHashTablePrototype NXStrPrototype = {
    NXStrHash, NXStrIsEqual, NXNoEffectFree, 0
    };


const NXHashTablePrototype NXPtrStructKeyPrototype = {
    hashPtrStructKey, isEqualPtrStructKey, NXReallyFree, 0
    };

const NXHashTablePrototype NXStrStructKeyPrototype = {
    hashStrStructKey, isEqualStrStructKey, NXReallyFree, 0
    };

extern unsigned _mapPtrHash(NXMapTable *table, const void *key);
extern unsigned _mapStrHash(NXMapTable *table, const void *key);
extern unsigned _mapObjectHash(NXMapTable *table, const void *key);
extern int _mapPtrIsEqual(NXMapTable *table, const void *key1, const void *key2);
extern int _mapStrIsEqual(NXMapTable *table, const void *key1, const void *key2);
extern int _mapObjectIsEqual(NXMapTable *table, const void *key1, const void *key2);
extern void _mapNoFree(NXMapTable *table, void *key, void *value);
extern void _mapObjectFree(NXMapTable *table, void *key, void *value);

const NXMapTablePrototype NXPtrValueMapPrototype = {
    _mapPtrHash, _mapPtrIsEqual, _mapNoFree, 0
};

const NXMapTablePrototype NXStrValueMapPrototype = {
    _mapStrHash, _mapStrIsEqual, _mapNoFree, 0
};

const NXMapTablePrototype NXObjectMapPrototype = {
    _mapObjectHash, _mapObjectIsEqual, _mapObjectFree, 0
};

#ifdef SHLIB
static const char _objc_global_text_pad[144] = {0};

/*
 * Declarations of static (literal) const data.
 */
static const char _objc_literal_text_pad[256] = {0};

#endif
