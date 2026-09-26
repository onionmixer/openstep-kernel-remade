/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c90a8. */
void *__cdecl -[HashTable insertKey:value:](HashTable *self, SEL a2, const void *a3, void *a4)
{
  void *result; // eax
  $3D27A55567FB06BC0E416B979767FD15 *v5; // eax
  id v6; // eax
  _DWORD *v7; // esi
  $3D27A55567FB06BC0E416B979767FD15 *v8; // eax
  int v9; // edx
  size_t nbBuckets; // [esp-1Ch] [ebp-34h]
  int v11; // [esp+8h] [ebp-10h] BYREF
  int v12; // [esp+Ch] [ebp-Ch] BYREF
  _DWORD v13[2]; // [esp+10h] [ebp-8h] BYREF

  result = -[HashTable _insertKeyNoRehash:value:](self, sel__insertKeyNoRehash_value_, a3, a4); /*0x1c90c3*/
  if ( !result ) /*0x1c90cd*/
  {
    if ( self->_nbBuckets < self->count ) /*0x1c90d9*/
    {
      v5 = -[Object zone](self, sel_zone); /*0x1c90fa*/
      v6 = +[Object allocFromZone:](aHashtable, sel_allocFromZone_, v5); /*0x1c9111*/
      v7 = objc_msgSend(v6, sel__initBare_::); /*0x1c911f*/
      v7[1] = self->count; /*0x1c9124*/
      v7[5] = self->_buckets; /*0x1c912a*/
      self->_nbBuckets += 1 + self->_nbBuckets; /*0x1c9131*/
      self->count = 0; /*0x1c9134*/
      nbBuckets = self->_nbBuckets; /*0x1c9140*/
      v8 = -[Object zone](self, sel_zone); /*0x1c9149*/
      self->_buckets = (void *)NXZoneCalloc((int)v8, nbBuckets, 8u); /*0x1c9157*/
      v13[0] = objc_msgSend(v7, sel_initState); /*0x1c916a*/
      v13[1] = v9; /*0x1c916d*/
      while ( (unsigned __int8)objc_msgSend(v7, sel_nextState_key_value_, v13, &v12, &v11) ) /*0x1c9192*/
        -[HashTable insertKey:value:](self, sel_insertKey_value_, v12, v11); /*0x1c91a4*/
      objc_msgSend(v7, sel_free); /*0x1c91b8*/
    }
    return nullptr; /*0x1c91bd*/
  }
  return result; /*0x1c91c2*/
}
