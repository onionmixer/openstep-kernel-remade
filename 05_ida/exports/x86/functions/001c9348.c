/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c9348. */
char __cdecl -[HashTable nextState:key:value:](
        HashTable *self,
        SEL a2,
        $2825F4736939C4A6D3AD43837233062D *a3,
        const void **a4,
        void **a5)
{
  _DWORD *buckets; // eax
  int v7; // edx
  int v8; // ecx
  const void *v9; // edx
  void *v10; // ecx

  buckets = self->_buckets; /*0x1c9359*/
  if ( a3->var1 ) /*0x1c935c*/
  {
LABEL_5:
    --a3->var1; /*0x1c938a*/
    v8 = buckets[2 * a3->var0 + 1] + 8 * a3->var1; /*0x1c9396*/
    v9 = *(const void **)v8; /*0x1c9399*/
    v10 = *(void **)(v8 + 4); /*0x1c939b*/
    *a4 = v9; /*0x1c939e*/
    *a5 = v10; /*0x1c93a0*/
    return 1; /*0x1c93a2*/
  }
  else
  {
    while ( a3->var0 ) /*0x1c9367*/
    {
      --a3->var0; /*0x1c937c*/
      v7 = buckets[2 * a3->var0]; /*0x1c9380*/
      a3->var1 = v7; /*0x1c9383*/
      if ( v7 ) /*0x1c9388*/
        goto LABEL_5; /*0x1c9388*/
    }
    *a4 = nullptr; /*0x1c9369*/
    *a5 = nullptr; /*0x1c936f*/
    return 0; /*0x1c9375*/
  }
}
