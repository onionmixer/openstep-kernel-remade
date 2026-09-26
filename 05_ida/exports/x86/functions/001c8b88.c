/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c8b88. */
id __cdecl -[HashTable initKeyDesc:valueDesc:capacity:](
        HashTable *self,
        SEL a2,
        const char *a3,
        const char *a4,
        unsigned int a5)
{
  char v5; // al
  int v6; // eax
  $3D27A55567FB06BC0E416B979767FD15 *v7; // eax
  size_t nbBuckets; // [esp-24h] [ebp-30h]

  v5 = sub_1C8900(a5); /*0x1c8b9b*/
  v6 = sub_1C8920(v5 + 1); /*0x1c8ba2*/
  -[HashTable _initBare:::](self, sel__initBare_::, a3, a4, v6); /*0x1c8bb2*/
  nbBuckets = self->_nbBuckets; /*0x1c8bbc*/
  v7 = -[Object zone](self, sel_zone); /*0x1c8bc5*/
  self->_buckets = (void *)NXZoneCalloc((int)v7, nbBuckets, 8u); /*0x1c8bd3*/
  return self; /*0x1c8bdb*/
}
