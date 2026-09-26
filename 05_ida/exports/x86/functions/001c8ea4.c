/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c8ea4. */
char __cdecl -[HashTable isKey:](HashTable *self, SEL a2, const void *a3)
{
  _DWORD *buckets; // ebx
  unsigned int v4; // eax
  int v5; // ebx
  char **i; // esi
  char **v8; // [esp+10h] [ebp-4h]

  buckets = self->_buckets; /*0x1c8eb0*/
  v4 = sub_1C8938(self->keyDesc, (unsigned int)a3, self->_nbBuckets); /*0x1c8ebf*/
  v8 = (char **)buckets[2 * v4 + 1]; /*0x1c8ece*/
  v5 = buckets[2 * v4]; /*0x1c8ed1*/
  if ( v5 ) /*0x1c8ed9*/
  {
    for ( i = v8; --v5 != -1; i += 2 ) /*0x1c8ee8*/
    {
      if ( sub_1C89C8(self->keyDesc, (char *)a3, *i) ) /*0x1c8efb*/
        return 1; /*0x1c8ee5*/
    }
  }
  return 0; /*0x1c8f15*/
}
