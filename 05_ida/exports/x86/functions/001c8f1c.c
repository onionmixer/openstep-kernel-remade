/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c8f1c. */
void *__cdecl -[HashTable valueForKey:](HashTable *self, SEL a2, const void *a3)
{
  _DWORD *buckets; // ebx
  unsigned int v4; // eax
  int v5; // ebx
  int i; // esi
  int v8; // [esp+10h] [ebp-4h]

  buckets = self->_buckets; /*0x1c8f28*/
  v4 = sub_1C8938(self->keyDesc, (unsigned int)a3, self->_nbBuckets); /*0x1c8f37*/
  v8 = buckets[2 * v4 + 1]; /*0x1c8f46*/
  v5 = buckets[2 * v4]; /*0x1c8f49*/
  if ( v5 ) /*0x1c8f51*/
  {
    for ( i = v8; --v5 != -1; i += 8 ) /*0x1c8f60*/
    {
      if ( sub_1C89C8(self->keyDesc, (char *)a3, *(char **)i) ) /*0x1c8f73*/
        return *(void **)(i + 4); /*0x1c8f5b*/
    }
  }
  return nullptr; /*0x1c8f8d*/
}
