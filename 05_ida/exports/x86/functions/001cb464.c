/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cb464. */
void *__cdecl NXHashGet(NXHashTable *table, const void *data)
{
  char *v2; // ebx
  int v3; // esi
  void **i; // ebx

  v2 = (char *)table->buckets + 8 * (table->prototype->hash(table->info, data) % table->nbBuckets); /*0x1cb489*/
  v3 = *(_DWORD *)v2; /*0x1cb48c*/
  if ( *(_DWORD *)v2 ) /*0x1cb48c*/
  {
    if ( v3 == 1 ) /*0x1cb498*/
    {
      if ( *((const void **)v2 + 1) == data /*0x1cb4b3*/
        || ((int (__stdcall *)(const void *, const void *, _DWORD))table->prototype->isEqual)(
             table->info,
             data,
             *((_DWORD *)v2 + 1)) )
      {
        return *((void **)v2 + 1); /*0x1cb4bc*/
      }
    }
    else
    {
      for ( i = *((void ***)v2 + 1); --v3 != -1; ++i ) /*0x1cb4c0*/
      {
        if ( *i == data || table->prototype->isEqual(table->info, data, *i) ) /*0x1cb4df*/
          return *i; /*0x1cb4ea*/
      }
    }
  }
  return nullptr; /*0x1cb4fa*/
}
