/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c8aa0. */
id __cdecl -[HashTable _initBare:::](HashTable *self, SEL a2, const char *a3, const char *a4, unsigned int a5)
{
  self->count = 0; /*0x1c8aad*/
  self->_nbBuckets = a5; /*0x1c8ab7*/
  self->keyDesc = (char *)a3; /*0x1c8aba*/
  if ( !a3 ) /*0x1c8abf*/
    self->keyDesc = "@"; /*0x1c8ac1*/
  self->valueDesc = (char *)a4; /*0x1c8ac8*/
  if ( !a4 ) /*0x1c8acd*/
    self->valueDesc = "@"; /*0x1c8acf*/
  self->_buckets = nullptr; /*0x1c8ad6*/
  return self; /*0x1c8adf*/
}
