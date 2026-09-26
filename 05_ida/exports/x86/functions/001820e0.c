/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1820e0. */
int __cdecl kern_IOMapEISADevicePorts(id a1, int a2)
{
  if ( !a1 ) /*0x1820eb*/
    return -705; /*0x1820ed*/
  if ( *(_DWORD *)(*(_DWORD *)(a2 + 12) + 80) ) /*0x1820fb*/
    return 0; /*0x182110*/
  return kern_dev_map_port_com(a1, a2, 0); /*0x1820f4*/
}
