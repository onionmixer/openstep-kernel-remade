/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x174600. */
__int32 vm_map_init()
{
  vm_map_zone = zinit(80, 102400, 0, 0, (int)aMaps); /*0x174618*/
  vm_map_entry_zone = zinit(44, (int)&dword_100000, 0, 0, (int)aNonKernelMapEn); /*0x174632*/
  vm_map_kentry_zone = zinit(44, kentry_data_size, 0, 0, (int)aKernelMapEntri); /*0x174651*/
  zchange(vm_map_kentry_zone, 0, 0, 0, 0); /*0x17465f*/
  zcram(vm_map_zone, (_DWORD *)map_data, map_data_size); /*0x17467c*/
  return zcram(vm_map_kentry_zone, (_DWORD *)kentry_data, kentry_data_size); /*0x17469d*/
}
