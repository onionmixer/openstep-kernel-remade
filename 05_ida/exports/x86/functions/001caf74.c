/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1caf74. */
_DWORD *sub_1CAF74()
{
  void *v0; // eax
  int v1; // ebx
  int v2; // eax
  NXHashTable *v3; // eax
  int v4; // eax
  void *v5; // edx
  NXHashTable *v6; // eax
  _DWORD *result; // eax
  int v8; // [esp-Ch] [ebp-10h]
  int v9; // [esp-8h] [ebp-Ch]
  int v10; // [esp-8h] [ebp-Ch]
  int v11; // [esp-8h] [ebp-Ch]
  size_t v12; // [esp-8h] [ebp-Ch]
  int v13; // [esp-4h] [ebp-8h]
  int v14; // [esp-4h] [ebp-8h]
  size_t v15; // [esp-4h] [ebp-8h]

  v0 = malloc(8u); /*0x1caf7a*/
  free(v0); /*0x1caf80*/
  v1 = NXDefaultMallocZone(v9, v13); /*0x1caf8a*/
  v2 = NXDefaultMallocZone(20, v10); /*0x1caf8e*/
  v3 = (NXHashTable *)(*(int (__stdcall **)(int, int, int, int))(v1 + 4))(v2, v8, v11, v14); /*0x1caf97*/
  table = v3; /*0x1caf99*/
  v3->prototype = (const NXHashTablePrototype *)&unk_1E5544; /*0x1caf9e*/
  v3->count = 1; /*0x1cafa4*/
  v3->nbBuckets = 1; /*0x1cafab*/
  v4 = NXDefaultMallocZone(1, 8); /*0x1cafb6*/
  v5 = (void *)NXZoneCalloc(v4, v12, v15); /*0x1cafc1*/
  v6 = table; /*0x1cafc3*/
  table->buckets = v5; /*0x1cafc8*/
  v6->info = nullptr; /*0x1cafcb*/
  *(_DWORD *)v6->buckets = 1; /*0x1cafd5*/
  result = v6->buckets; /*0x1cafdb*/
  result[1] = &unk_1E5544; /*0x1cafde*/
  return result; /*0x1cafe5*/
}
