/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cb5c8. */
void *__cdecl NXHashInsert(NXHashTable *table, const void *data)
{
  char *v2; // edi
  int v3; // esi
  void *result; // eax
  const void **v5; // eax
  NXHashTable *v6; // ecx
  const void **i; // ebx
  const void **v8; // ebx
  int v9; // [esp+Ch] [ebp-4h]

  v2 = (char *)table->buckets + 8 * (table->prototype->hash(table->info, data) % table->nbBuckets); /*0x1cb5f5*/
  v3 = *(_DWORD *)v2; /*0x1cb5f8*/
  v9 = NXZoneFromPtr(table); /*0x1cb600*/
  if ( v3 ) /*0x1cb608*/
  {
    if ( v3 == 1 ) /*0x1cb623*/
    {
      if ( *((const void **)v2 + 1) == data || table->prototype->isEqual(table->info, data, *((const void **)v2 + 1)) ) /*0x1cb644*/
      {
        result = *((void **)v2 + 1); /*0x1cb64d*/
        *((_DWORD *)v2 + 1) = data; /*0x1cb653*/
        return result; /*0x1cb656*/
      }
      v5 = (const void **)NXZoneCalloc(v9, 2u, 4u); /*0x1cb664*/
      v5[1] = *((const void **)v2 + 1); /*0x1cb66e*/
      *v5 = data; /*0x1cb674*/
      ++*(_DWORD *)v2; /*0x1cb676*/
      *((_DWORD *)v2 + 1) = v5; /*0x1cb678*/
      v6 = table; /*0x1cb67b*/
      ++table->count; /*0x1cb67e*/
    }
    else
    {
      for ( i = *((const void ***)v2 + 1); --v3 != -1; ++i ) /*0x1cb68c*/
      {
        if ( *i == data || table->prototype->isEqual(table->info, data, *i) ) /*0x1cb6b1*/
        {
          result = (void *)*i; /*0x1cb6ba*/
          *i = data; /*0x1cb6bf*/
          return result; /*0x1cb6c1*/
        }
      }
      v8 = (const void **)NXZoneCalloc(v9, *(_DWORD *)v2 + 1, 4u); /*0x1cb6dc*/
      if ( *(_DWORD *)v2 ) /*0x1cb6e1*/
        memmove(v8 + 1, *((const void **)v2 + 1), 4 * *(_DWORD *)v2); /*0x1cb6f8*/
      *v8 = data; /*0x1cb703*/
      free(*((void **)v2 + 1)); /*0x1cb709*/
      ++*(_DWORD *)v2; /*0x1cb70e*/
      *((_DWORD *)v2 + 1) = v8; /*0x1cb710*/
      v6 = table; /*0x1cb713*/
      ++table->count; /*0x1cb716*/
    }
    if ( v6->nbBuckets < v6->count ) /*0x1cb722*/
      sub_1CB504(v6); /*0x1cb725*/
  }
  else
  {
    ++*(_DWORD *)v2; /*0x1cb60a*/
    *((_DWORD *)v2 + 1) = data; /*0x1cb60f*/
    ++table->count; /*0x1cb615*/
  }
  return nullptr; /*0x1cb72f*/
}
