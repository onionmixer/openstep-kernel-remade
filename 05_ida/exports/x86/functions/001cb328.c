/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cb328. */
NXHashTable *__cdecl NXCopyHashTable(NXHashTable *table)
{
  int v1; // esi
  NXHashTable *v2; // ebx
  size_t nbBuckets; // ecx
  void *data; // [esp+Ch] [ebp-Ch] BYREF
  NXHashState state; // [esp+10h] [ebp-8h] BYREF

  state = NXInitHashState(table); /*0x1cb33a*/
  v1 = NXZoneFromPtr(table); /*0x1cb346*/
  v2 = (NXHashTable *)(*(int (__cdecl **)(int, int))(v1 + 4))(v1, 20); /*0x1cb350*/
  v2->prototype = table->prototype; /*0x1cb354*/
  v2->count = 0; /*0x1cb356*/
  v2->info = table->info; /*0x1cb360*/
  nbBuckets = table->nbBuckets; /*0x1cb363*/
  v2->nbBuckets = nbBuckets; /*0x1cb366*/
  v2->buckets = (void *)NXZoneCalloc(v1, nbBuckets, 8u); /*0x1cb372*/
  while ( NXNextHashState(table, &state, &data) ) /*0x1cb38c*/
    NXHashInsert(v2, data); /*0x1cb393*/
  return v2; /*0x1cb3a5*/
}
