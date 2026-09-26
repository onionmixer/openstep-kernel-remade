/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cb738. */
void *__cdecl NXHashInsertIfAbsent(NXHashTable *table, const void *data)
{
  char *v2; // edi
  int v3; // esi
  const void **v5; // eax
  void **i; // ebx
  const void **v7; // ebx
  int v8; // [esp+Ch] [ebp-4h]

  v2 = (char *)table->buckets + 8 * (table->prototype->hash(table->info, data) % table->nbBuckets); /*0x1cb765*/
  v3 = *(_DWORD *)v2; /*0x1cb768*/
  v8 = NXZoneFromPtr(table); /*0x1cb770*/
  if ( !v3 ) /*0x1cb778*/
  {
    ++*(_DWORD *)v2; /*0x1cb77a*/
    *((_DWORD *)v2 + 1) = data; /*0x1cb77f*/
    ++table->count; /*0x1cb785*/
    return (void *)data; /*0x1cb788*/
  }
  if ( v3 != 1 ) /*0x1cb793*/
  {
    for ( i = *((void ***)v2 + 1); --v3 != -1; ++i ) /*0x1cb804*/
    {
      if ( *i == data || table->prototype->isEqual(table->info, data, *i) ) /*0x1cb829*/
        return *i; /*0x1cb834*/
    }
    v7 = (const void **)NXZoneCalloc(v8, *(_DWORD *)v2 + 1, 4u); /*0x1cb850*/
    if ( *(_DWORD *)v2 ) /*0x1cb855*/
      memmove(v7 + 1, *((const void **)v2 + 1), 4 * *(_DWORD *)v2); /*0x1cb86c*/
    *v7 = data; /*0x1cb877*/
    free(*((void **)v2 + 1)); /*0x1cb87d*/
    ++*(_DWORD *)v2; /*0x1cb882*/
    *((_DWORD *)v2 + 1) = v7; /*0x1cb884*/
    if ( table->nbBuckets >= ++table->count ) /*0x1cb896*/
      return (void *)data; /*0x1cb896*/
    goto LABEL_18; /*0x1cb896*/
  }
  if ( *((const void **)v2 + 1) == data || table->prototype->isEqual(table->info, data, *((const void **)v2 + 1)) ) /*0x1cb7b4*/
    return *((void **)v2 + 1); /*0x1cb7c0*/
  v5 = (const void **)NXZoneCalloc(v8, 2u, 4u); /*0x1cb7d0*/
  v5[1] = *((const void **)v2 + 1); /*0x1cb7da*/
  *v5 = data; /*0x1cb7e0*/
  ++*(_DWORD *)v2; /*0x1cb7e2*/
  *((_DWORD *)v2 + 1) = v5; /*0x1cb7e4*/
  if ( table->nbBuckets < ++table->count ) /*0x1cb7f6*/
LABEL_18:
    sub_1CB504(table); /*0x1cb898*/
  return (void *)data; /*0x1cb8a4*/
}
