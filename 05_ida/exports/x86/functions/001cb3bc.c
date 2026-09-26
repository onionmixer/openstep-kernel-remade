/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cb3bc. */
int __cdecl NXHashMember(NXHashTable *table, const void *data)
{
  int *v2; // edx
  int v3; // ebx
  int v4; // ebx
  const void **i; // esi

  v2 = (int *)((char *)table->buckets + 8 * (table->prototype->hash(table->info, data) % table->nbBuckets)); /*0x1cb3e1*/
  v3 = *v2; /*0x1cb3e4*/
  if ( !*v2 ) /*0x1cb3eb*/
    return 0; /*0x1cb455*/
  if ( v3 != 1 ) /*0x1cb3f0*/
  {
    for ( i = (const void **)v2[1]; --v3 != -1; ++i ) /*0x1cb41c*/
    {
      if ( *i == data || table->prototype->isEqual(table->info, data, *i) ) /*0x1cb43b*/
        return 1; /*0x1cb449*/
    }
    return 0; /*0x1cb453*/
  }
  v4 = 0; /*0x1cb3f2*/
  if ( (const void *)v2[1] == data /*0x1cb40a*/
    || ((int (__stdcall *)(const void *, const void *, int))table->prototype->isEqual)(table->info, data, v2[1]) )
  {
    return 1; /*0x1cb410*/
  }
  return v4; /*0x1cb45a*/
}
