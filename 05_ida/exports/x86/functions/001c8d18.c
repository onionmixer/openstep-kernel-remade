/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c8d18. */
id __cdecl -[HashTable freeKeys:values:](HashTable *self, SEL a2, void *a3, void *a4)
{
  char *buckets; // edi
  _DWORD *v5; // esi
  int v6; // ebx
  unsigned int v8; // [esp+Ch] [ebp-4h]

  buckets = (char *)self->_buckets; /*0x1c8d24*/
  v8 = self->_nbBuckets - 1; /*0x1c8d2b*/
  if ( self->_nbBuckets ) /*0x1c8d27*/
  {
    do /*0x1c8d80*/
    {
      if ( *(_DWORD *)buckets ) /*0x1c8d34*/
      {
        v5 = *((_DWORD **)buckets + 1); /*0x1c8d39*/
        v6 = *(_DWORD *)buckets; /*0x1c8d3c*/
        while ( --v6 != -1 ) /*0x1c8d57*/
        {
          ((void (__cdecl *)(_DWORD))a3)(*v5); /*0x1c8d46*/
          ((void (__cdecl *)(_DWORD))a4)(v5[1]); /*0x1c8d4f*/
          v5 += 2; /*0x1c8d51*/
        }
        free(*((void **)buckets + 1)); /*0x1c8d61*/
        *(_DWORD *)buckets = 0; /*0x1c8d66*/
        *((_DWORD *)buckets + 1) = 0; /*0x1c8d6c*/
      }
      buckets += 8; /*0x1c8d76*/
      --v8; /*0x1c8d79*/
    }
    while ( v8 != -1 ); /*0x1c8d80*/
  }
  self->count = 0; /*0x1c8d85*/
  return self; /*0x1c8d92*/
}
