/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cafec. */
NXHashTable *__cdecl NXCreateHashTable(NXHashTablePrototype prototype, unsigned int capacity, const void *info)
{
  void *v3; // eax
  int v5; // [esp+0h] [ebp-8h]
  int v6; // [esp+4h] [ebp-4h]

  v3 = (void *)NXDefaultMallocZone(v5, v6); /*0x1caff7*/
  return NXCreateHashTableFromZone(prototype, capacity, info, v3); /*0x1cb017*/
}
