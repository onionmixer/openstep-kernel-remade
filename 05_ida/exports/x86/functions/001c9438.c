/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c9438. */
void __cdecl -[HashTable printForDebugger:](HashTable *self, SEL a2, $FDB6067EFA2BACD1029BBA668871BE41 *a3)
{
  int v3; // ebx
  id *v4; // esi
  _DWORD *buckets; // [esp+Ch] [ebp-8h]
  unsigned int nbBuckets; // [esp+10h] [ebp-4h]

  nbBuckets = self->_nbBuckets; /*0x1c944a*/
  buckets = self->_buckets; /*0x1c9453*/
  NXPrintf(
    (int)a3,
    (int)"Table [%s -> %s]: \tcount: %d\tcapacity: %d\n",
    self->keyDesc,
    self->valueDesc,
    self->count,
    nbBuckets);
  while ( --nbBuckets != -1 )
  {
    if ( *buckets )
    {
      v3 = *buckets; /*0x1c9484*/
      v4 = (id *)buckets[1]; /*0x1c9486*/
      NXPrintf((int)a3, (int)"%d\t", *buckets); /*0x1c9490*/
      while ( --v3 != -1 )
      {
        sub_1C93C8((int)a3, self->keyDesc, *v4); /*0x1c94a7*/
        NXPrintf((int)a3, (int)": ");
        sub_1C93C8((int)a3, self->valueDesc, v4[1]); /*0x1c94c3*/
        NXPrintf((int)a3, (int)"\t"); /*0x1c94d1*/
        v4 += 2; /*0x1c94d6*/
      }
      NXPrintf((int)a3, (int)"\n"); /*0x1c94e8*/
    }
    buckets += 2; /*0x1c94f0*/
  }
  NXPrintf((int)a3, (int)"\n"); /*0x1c9507*/
  NXFlush(); /*0x1c950d*/
}
