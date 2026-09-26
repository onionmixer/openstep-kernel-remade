/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cb020. */
NXHashTable *__cdecl NXCreateHashTableFromZone(
        NXHashTablePrototype prototype,
        unsigned int capacity,
        const void *info,
        void *z)
{
  void *v4; // edi
  NXHashTable *v5; // esi
  const NXHashTablePrototype *v6; // ebx
  int v7; // ebx
  int v8; // eax
  void *v9; // ebx
  char v11; // al
  size_t v12; // eax
  int v13; // [esp+0h] [ebp-Ch]
  int v14; // [esp+0h] [ebp-Ch]
  int v15; // [esp+4h] [ebp-8h]

  v4 = z; /*0x1cb026*/
  v5 = (NXHashTable *)(*((int (__cdecl **)(void *, int))z + 1))(z, 20); /*0x1cb031*/
  if ( !table ) /*0x1cb03d*/
    sub_1CAF74(); /*0x1cb03f*/
  if ( !prototype.hash ) /*0x1cb048*/
    prototype.hash = NXPtrHash; /*0x1cb04a*/
  if ( !prototype.isEqual ) /*0x1cb055*/
    prototype.isEqual = NXPtrIsEqual; /*0x1cb057*/
  if ( !prototype.free ) /*0x1cb062*/
    prototype.free = NXNoEffectFree; /*0x1cb064*/
  if ( prototype.style )
  {
    _NXLogError("*** NXCreateHashTable: invalid style\n");
    return nullptr; /*0x1cb0e5*/
  }
  v6 = (const NXHashTablePrototype *)NXHashGet(table, &prototype); /*0x1cb088*/
  if ( !v6 )
  {
    v7 = NXDefaultMallocZone(v13, v15); /*0x1cb096*/
    v8 = NXDefaultMallocZone(16, v14); /*0x1cb09a*/
    v9 = (void *)(*(int (__cdecl **)(int))(v7 + 4))(v8); /*0x1cb0a5*/
    memmove(v9, &prototype, 0x10u); /*0x1cb0ae*/
    NXHashInsert(table, v9); /*0x1cb0bb*/
    v6 = (const NXHashTablePrototype *)NXHashGet(table, &prototype); /*0x1cb0d0*/
    if ( !v6 )
    {
      _NXLogError("*** NXCreateHashTable: bug\n");
      return nullptr; /*0x1cb0de*/
    }
  }
  v5->prototype = v6; /*0x1cb0e8*/
  v5->count = 0; /*0x1cb0ea*/
  v5->info = info; /*0x1cb0f4*/
  v11 = sub_1CAEBC(capacity); /*0x1cb0fb*/
  v12 = sub_1CAEDC(v11 + 1); /*0x1cb102*/
  v5->nbBuckets = v12; /*0x1cb107*/
  v5->buckets = (void *)NXZoneCalloc((int)v4, v12, 8u); /*0x1cb113*/
  return v5; /*0x1cb11b*/
}
