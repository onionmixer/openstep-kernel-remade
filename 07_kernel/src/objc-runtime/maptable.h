/*
 * maptable.h (plan 356).
 *
 * Header of the kernel Objective-C runtime (D045, D046, D047).
 * The text is nearly the same as Darwin 0.1 objc-1 maptable.h; kept as
 * project-authored under D030/D047, without Darwin's notices (license
 * judgement: D017).
 */

#ifndef _OBJC_MAPTABLE_H_
#define _OBJC_MAPTABLE_H_

#import "objc.h"
#import <objc/zone.h>

/***************	Definitions		***************/

    /* This module allows hashing of arbitrary associations [key -> value].  Keys and values must be pointers or integers, and client is responsible for allocating/deallocating this data.  A deallocation call-back is provided.
    NX_MAPNOTAKEY (-1) is used internally as a marker, and therefore keys must always be different from -1.
    As well-behaved scalable data structures, hash tables double in size when they start becoming full, thus guaranteeing both average constant time access and linear size. */

typedef struct _NXMapTable {
    /* private data structure; may change */
    const struct _NXMapTablePrototype	*prototype;
    unsigned	count;
    unsigned	nbBuckets;
    void	*buckets;
} NXMapTable;

typedef struct _NXMapTablePrototype {
    unsigned	(*hash)(NXMapTable *, const void *key);
    int		(*isEqual)(NXMapTable *, const void *key1, const void *key2);
    void	(*free)(NXMapTable *, void *key, void *value);
    int		style; /* reserved for future expansion; currently 0 */
} NXMapTablePrototype;
    
    /* invariants assumed by the implementation: 
	A - key != -1
	B - key1 == key2 => hash(key1) == hash(key2)
	    when key varies over time, hash(key) must remain invariant
	    e.g. if string key, the string must not be changed
	C - isEqual(key1, key2) => key1 == key2
    */

#define NX_MAPNOTAKEY	((void *)(-1))

/***************	Functions		***************/

extern NXMapTable *NXCreateMapTableFromZone(NXMapTablePrototype prototype, unsigned capacity, NXZone *zone);
extern NXMapTable *NXCreateMapTable(NXMapTablePrototype prototype, unsigned capacity);
    /* capacity is only a hint; 0 creates a small table */

extern void NXFreeMapTable(NXMapTable *table);
    /* call free for each pair, and recovers table */
	
extern void NXResetMapTable(NXMapTable *table);
    /* free each pair; keep current capacity */

extern BOOL NXCompareMapTables(NXMapTable *table1, NXMapTable *table2);
    /* Returns YES if the two sets are equal (each member of table1 in table2, and table have same size) */

extern unsigned NXCountMapTable(NXMapTable *table);
    /* current number of data in table */
	
extern void *NXMapMember(NXMapTable *table, const void *key, void **value);
    /* return original table key or NX_MAPNOTAKEY.  If key is found, value is set */
	
extern void *NXMapGet(NXMapTable *table, const void *key);
    /* return original corresponding value or NULL.  When NULL need be stored as value, NXMapMember can be used to test for presence */
	
extern void *NXMapInsert(NXMapTable *table, const void *key, const void *value);
    /* override preexisting pair; Return previous value or NULL. */
	
extern void *NXMapRemove(NXMapTable *table, const void *key);
    /* previous value or NULL is returned */
	
/* Iteration over all elements of a table consists in setting up an iteration state and then to progress until all entries have been visited.  An example of use for counting elements in a table is:
    unsigned	count = 0;
    const MyKey	*key;
    const MyValue	*value;
    NXMapState	state = NXInitMapState(table);
    while(NXNextMapState(table, &state, &key, &value)) {
	count++;
    }
*/

typedef struct {int index;} NXMapState;
    /* callers should not rely on actual contents of the struct */

extern NXMapState NXInitMapState(NXMapTable *table);

extern int NXNextMapState(NXMapTable *table, NXMapState *state, const void **key, const void **value);
    /* returns 0 when all elements have been visited */

/***************	Conveniences		***************/

extern const NXMapTablePrototype NXPtrValueMapPrototype;
    /* hashing is pointer/integer hashing;
      isEqual is identity;
      free is no-op. */
extern const NXMapTablePrototype NXStrValueMapPrototype;
    /* hashing is string hashing;
      isEqual is strcmp;
      free is no-op. */
extern const NXMapTablePrototype NXObjectMapPrototype;
    /* for objects; uses methods: hash, isEqual:, free, all for key. */

#endif /* _OBJC_MAPTABLE_H_ */
