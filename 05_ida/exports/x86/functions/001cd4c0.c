/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cd4c0. */
IMP __cdecl class_lookupMethod(Class cls, SEL sel)
{
  Method *buckets; // ecx
  unsigned int i; // edx
  Method v4; // eax
  unsigned int mask; // [esp+Ch] [ebp-4h]

  if ( !sel ) /*0x1cd4d1*/
    -[objc_class error:](cls, sel_error_, "invalid selector %s", 0); /*0x1cd4e2*/
  mask = cls->cache->mask; /*0x1cd4ef*/
  buckets = cls->cache->buckets; /*0x1cd4f5*/
  for ( i = (unsigned int)sel & mask; buckets[i]; i = mask & (i + 1) ) /*0x1cd4fa*/
  {
    v4 = buckets[i]; /*0x1cd502*/
    if ( v4->method_name == sel ) /*0x1cd507*/
      return v4->method_imp; /*0x1cd50c*/
  }
  return (IMP)_class_lookupMethodAndLoadCache(cls, sel); /*0x1cd522*/
}
