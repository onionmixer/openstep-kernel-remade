/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c91c8. */
void *__cdecl -[HashTable removeKey:](HashTable *self, SEL a2, const void *a3)
{
  int v3; // edi
  $3D27A55567FB06BC0E416B979767FD15 *v4; // eax
  int v6; // [esp+10h] [ebp-28h]
  char *__src; // [esp+14h] [ebp-24h]
  $3D27A55567FB06BC0E416B979767FD15 *v8; // [esp+20h] [ebp-18h]
  void *v9; // [esp+24h] [ebp-14h]
  char *__dst; // [esp+28h] [ebp-10h]
  char *v11; // [esp+2Ch] [ebp-Ch]
  unsigned int v12; // [esp+30h] [ebp-8h]
  _DWORD *buckets; // [esp+34h] [ebp-4h]

  buckets = self->_buckets; /*0x1c91d7*/
  v12 = sub_1C8938(self->keyDesc, (unsigned int)a3, self->_nbBuckets); /*0x1c91f1*/
  v6 = buckets[2 * v12]; /*0x1c91fa*/
  __src = (char *)buckets[2 * v12 + 1]; /*0x1c9201*/
  v11 = __src; /*0x1c920a*/
  v3 = v6 - 1; /*0x1c9210*/
  if ( !v6 ) /*0x1c9214*/
    return nullptr; /*0x1c9322*/
  while ( !sub_1C89C8(self->keyDesc, (char *)a3, *(char **)v11) ) /*0x1c9247*/
  {
    v11 += 8; /*0x1c9314*/
    if ( --v3 == -1 ) /*0x1c931c*/
      return nullptr; /*0x1c931c*/
  }
  v9 = *((void **)v11 + 1); /*0x1c9253*/
  if ( v6 == 1 ) /*0x1c925a*/
  {
    __dst = nullptr; /*0x1c9298*/
  }
  else
  {
    v8 = -[Object zone](self, sel_zone); /*0x1c926f*/
    v4 = -[Object zone](self, sel_zone); /*0x1c927e*/
    __dst = (char *)((int (__cdecl *)($3D27A55567FB06BC0E416B979767FD15 *))v8->var1)(v4); /*0x1c9292*/
  }
  if ( v6 - 1 != v3 ) /*0x1c92a2*/
    memmove(__dst, __src, 8 * (v6 - v3) - 8); /*0x1c92b9*/
  if ( v3 ) /*0x1c92c3*/
    memmove(&__dst[8 * v6 - 8 + -8 * v3], &__src[8 * v6 + -8 * v3], 8 * v3); /*0x1c92e7*/
  free(__src); /*0x1c92f3*/
  --self->count; /*0x1c92fb*/
  --buckets[2 * v12]; /*0x1c9304*/
  buckets[2 * v12 + 1] = __dst; /*0x1c930a*/
  return v9; /*0x1c9327*/
}
