/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cf3c0. */
NXHashTable *sub_1CF3C0()
{
  void *zone; // eax

  zone = (void *)_objc_create_zone(); /*0x1cf3c3*/
  return NXCreateHashTableFromZone(stru_1E560C, 8u, nullptr, zone); /*0x1cf3f0*/
}
