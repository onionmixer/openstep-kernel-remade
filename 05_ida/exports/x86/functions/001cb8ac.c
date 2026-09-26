/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cb8ac. */
void *__cdecl NXHashRemove(NXHashTable *table, const void *data)
{
  char *v2; // edi
  int v3; // esi
  const void **v5; // ebx
  char *v6; // ebx
  int v7; // [esp+14h] [ebp-4h]
  void *datac; // [esp+24h] [ebp+Ch]
  void *dataa; // [esp+24h] [ebp+Ch]
  void *datab; // [esp+24h] [ebp+Ch]

  v2 = (char *)table->buckets + 8 * (table->prototype->hash(table->info, data) % table->nbBuckets); /*0x1cb8d9*/
  v3 = *(_DWORD *)v2; /*0x1cb8dc*/
  v7 = NXZoneFromPtr(table); /*0x1cb8e4*/
  if ( v3 ) /*0x1cb8ec*/
  {
    if ( v3 == 1 ) /*0x1cb8f5*/
    {
      if ( *((const void **)v2 + 1) == data /*0x1cb916*/
        || ((int (__stdcall *)(const void *, const void *, _DWORD))table->prototype->isEqual)(
             table->info,
             data,
             *((_DWORD *)v2 + 1)) )
      {
        datac = *((void **)v2 + 1); /*0x1cb923*/
        --table->count; /*0x1cb929*/
        --*(_DWORD *)v2; /*0x1cb92c*/
        *((_DWORD *)v2 + 1) = 0; /*0x1cb92e*/
        return datac; /*0x1cb938*/
      }
      return nullptr; /*0x1cb91a*/
    }
    v5 = *((const void ***)v2 + 1); /*0x1cb940*/
    if ( v3 == 2 ) /*0x1cb946*/
    {
      if ( *v5 == data || table->prototype->isEqual(table->info, data, *v5) ) /*0x1cb969*/
      {
        *((_DWORD *)v2 + 1) = v5[1]; /*0x1cb975*/
        dataa = (void *)*v5; /*0x1cb97a*/
LABEL_13:
        free(v5); /*0x1cb9b7*/
        --table->count; /*0x1cb9c0*/
        --*(_DWORD *)v2; /*0x1cb9c3*/
        return dataa; /*0x1cb9c8*/
      }
      if ( v5[1] == data || table->prototype->isEqual(table->info, data, v5[1]) ) /*0x1cb99f*/
      {
        *((_DWORD *)v2 + 1) = *v5; /*0x1cb9ae*/
        dataa = (void *)v5[1]; /*0x1cb9b4*/
        goto LABEL_13; /*0x1cb9b4*/
      }
    }
    else
    {
      while ( --v3 != -1 ) /*0x1cba87*/
      {
        if ( *v5 == data || table->prototype->isEqual(table->info, data, *v5) ) /*0x1cb9ed*/
        {
          datab = (void *)*v5; /*0x1cb9fc*/
          if ( *(_DWORD *)v2 == 1 ) /*0x1cba02*/
            v6 = nullptr; /*0x1cba1c*/
          else
            v6 = (char *)NXZoneCalloc(v7, *(_DWORD *)v2 - 1, 4u); /*0x1cba16*/
          if ( *(_DWORD *)v2 - 1 != v3 ) /*0x1cba23*/
            memmove(v6, *((const void **)v2 + 1), 4 * (*(_DWORD *)v2 - v3) - 4); /*0x1cba36*/
          if ( v3 ) /*0x1cba40*/
            memmove( /*0x1cba63*/
              &v6[4 * *(_DWORD *)v2 - 4 + -4 * v3],
              (const void *)(*((_DWORD *)v2 + 1) + 4 * *(_DWORD *)v2 - 4 * v3),
              4 * v3);
          free(*((void **)v2 + 1)); /*0x1cba6f*/
          --table->count; /*0x1cba77*/
          --*(_DWORD *)v2; /*0x1cba7a*/
          *((_DWORD *)v2 + 1) = v6; /*0x1cba7c*/
          return datab; /*0x1cba82*/
        }
        ++v5; /*0x1cba84*/
      }
    }
  }
  return nullptr; /*0x1cba96*/
}
