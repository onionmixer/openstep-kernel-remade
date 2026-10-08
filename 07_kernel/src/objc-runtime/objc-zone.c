/*
 * objc-zone.c (plan 360).
 *
 * The NXZone interface of the kernel Objective-C runtime, written for
 * this project from the OPENSTEP 4.2 kernel bytes (D024, D027; original
 * text 0x1cdeb0-0x1cdf30, KernelZone table 0x1e55e4-0x1e55f4).  The
 * original file name and the names of the four static functions are not
 * known (they are not in the original symbol table); both are
 * reconstruction choices.
 *
 * kern_destroy, the KernelZone initializer, NXDefaultMallocZone,
 * NXZoneFromPtr, NXCreateZone and NXNameZone are nearly the same as
 * Darwin 0.1 kernel/driverkit/objc_support.m.  kern_realloc, kern_malloc,
 * kern_free and NXZoneCalloc differ from it: in the 4.2 bytes they call
 * the kernel malloc family (realloc, malloc, free, calloc) instead of
 * kalloc/kfree; they are written from the original bytes (plan 360).
 */

#import <stdlib.h>
#import <objc/zone.h>

static void *kern_realloc(NXZone *zonep, void *ptr, size_t size)
{
	return realloc(ptr, size);
}

static void *kern_malloc(NXZone *zonep, size_t size)
{
	return malloc(size);
}

static void kern_free(NXZone *zonep, void *ptr)
{
	if (ptr)
		free(ptr);
}

static void kern_destroy(NXZone *zonep)
{
}

NXZone KernelZone = {
	kern_realloc,
	kern_malloc,
	kern_free,
	kern_destroy,
};

NXZone *NXDefaultMallocZone(void)
{
	return &KernelZone;
}

NXZone *NXZoneFromPtr(void *ptr)
{
	return &KernelZone;
}

NXZone *NXCreateZone(size_t startSize, size_t granularity, int canFree)
{
	return &KernelZone;
}

void NXNameZone(NXZone *zonep, const char *name)
{
}

void *NXZoneCalloc(NXZone *zonep, size_t numElements, size_t byteSize)
{
	return calloc(numElements, byteSize);
}
