/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16b338. */
int zone_init()
{
  int result; // eax

  result = kmem_suballoc(kernel_map, &zone_min, &zone_max, zone_map_size, 0); /*0x16b355*/
  zone_map = result; /*0x16b35a*/
  return result; /*0x16b361*/
}
