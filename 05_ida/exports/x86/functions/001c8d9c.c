/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c8d9c. */
id __cdecl -[HashTable empty](HashTable *self, SEL a2)
{
  void **buckets; // ebx
  unsigned int nbBuckets; // esi

  buckets = (void **)self->_buckets; /*0x1c8da5*/
  nbBuckets = self->_nbBuckets; /*0x1c8da8*/
  while ( --nbBuckets != -1 ) /*0x1c8dd1*/
  {
    if ( *buckets ) /*0x1c8db0*/
      free(buckets[1]); /*0x1c8db9*/
    *buckets = nullptr; /*0x1c8dc1*/
    buckets[1] = nullptr; /*0x1c8dc7*/
    buckets += 2; /*0x1c8dce*/
  }
  self->count = 0; /*0x1c8dd7*/
  return self; /*0x1c8de3*/
}
