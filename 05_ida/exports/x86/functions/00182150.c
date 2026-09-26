/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x182150. */
int __cdecl kern_IOMapEISADeviceMemory(id a1, int a2, int a3, int a4, int a5, char a6, int a7)
{
  if ( a1 ) /*0x18215f*/
    return kern_dev_map_phys(a1, *(_DWORD *)(a2 + 12), a3, a4, a5, a6, a7); /*0x18217a*/
  else
    return -705; /*0x182184*/
}
