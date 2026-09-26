/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cb504. */
void __cdecl sub_1CB504(NXHashTable *table)
{
  int v1; // esi
  NXHashTable *v2; // ebx
  void *data; // [esp+Ch] [ebp-Ch] BYREF
  NXHashState state; // [esp+10h] [ebp-8h] BYREF

  v1 = NXZoneFromPtr(table); /*0x1cb516*/
  v2 = (NXHashTable *)(*(int (__cdecl **)(int, int))(v1 + 4))(v1, 20); /*0x1cb520*/
  v2->prototype = table->prototype; /*0x1cb524*/
  v2->count = table->count; /*0x1cb529*/
  v2->nbBuckets = table->nbBuckets; /*0x1cb52f*/
  v2->buckets = table->buckets; /*0x1cb535*/
  table->nbBuckets += 1 + table->nbBuckets; /*0x1cb53c*/
  table->count = 0; /*0x1cb53f*/
  table->buckets = (void *)NXZoneCalloc(v1, table->nbBuckets, 8u); /*0x1cb552*/
  state = NXInitHashState(v2); /*0x1cb55b*/
  while ( NXNextHashState(v2, &state, &data) ) /*0x1cb578*/
    NXHashInsert(table, data); /*0x1cb57f*/
  sub_1CB174(v2, 0); /*0x1cb58f*/
  if ( table->count != v2->count )
    _NXLogError(
      "*** hashtable: count differs after rehashing; probably indicates a broken invariant: there are x and y such as isE"
      "qual(x, y) is TRUE but hash(x) != hash (y)\n");
  free(v2->buckets); /*0x1cb5b0*/
  free(v2); /*0x1cb5b6*/
}
