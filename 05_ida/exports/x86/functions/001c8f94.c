/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c8f94. */
void *__cdecl -[HashTable _insertKeyNoRehash:value:](HashTable *self, SEL a2, const void *a3, void *a4)
{
  const void **i; // ebx
  void *result; // eax
  $3D27A55567FB06BC0E416B979767FD15 *v6; // ebx
  $3D27A55567FB06BC0E416B979767FD15 *v7; // eax
  int v8; // eax
  const void **v9; // ebx
  int v10; // [esp+Ch] [ebp-14h]
  int v11; // [esp+10h] [ebp-10h]
  const void **__src; // [esp+14h] [ebp-Ch]
  unsigned int v13; // [esp+18h] [ebp-8h]
  _DWORD *buckets; // [esp+1Ch] [ebp-4h]

  buckets = self->_buckets; /*0x1c8fa3*/
  v13 = sub_1C8938(self->keyDesc, (unsigned int)a3, self->_nbBuckets); /*0x1c8fbd*/
  v11 = buckets[2 * v13]; /*0x1c8fc6*/
  __src = (const void **)buckets[2 * v13 + 1]; /*0x1c8fcd*/
  v10 = v11; /*0x1c8fd3*/
  for ( i = __src; --v10 != -1; i += 2 ) /*0x1c8fd6*/
  {
    if ( sub_1C89C8(self->keyDesc, (char *)a3, (char *)*i) ) /*0x1c8fee*/
    {
      result = (void *)i[1]; /*0x1c8ffa*/
      *i = a3; /*0x1c8ffd*/
      i[1] = a4; /*0x1c9002*/
      return result; /*0x1c9005*/
    }
  }
  v6 = -[Object zone](self, sel_zone); /*0x1c9028*/
  v7 = -[Object zone](self, sel_zone); /*0x1c903d*/
  v8 = ((int (__cdecl *)($3D27A55567FB06BC0E416B979767FD15 *))v6->var1)(v7); /*0x1c9049*/
  v9 = (const void **)v8; /*0x1c904b*/
  if ( v11 ) /*0x1c9054*/
    memmove((void *)(v8 + 8), __src, 8 * v11); /*0x1c9065*/
  *v9 = a3; /*0x1c9070*/
  v9[1] = a4; /*0x1c9075*/
  if ( v11 ) /*0x1c907c*/
    free(__src); /*0x1c9082*/
  ++buckets[2 * v13]; /*0x1c908d*/
  buckets[2 * v13 + 1] = v9; /*0x1c9090*/
  ++self->count; /*0x1c9097*/
  return nullptr; /*0x1c909f*/
}
