/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x182118. */
int __cdecl kern_IOUnMapEISADevicePorts(id a1, int a2)
{
  if ( !a1 ) /*0x182123*/
    return -705; /*0x182125*/
  if ( *(_DWORD *)(*(_DWORD *)(a2 + 12) + 80) ) /*0x182133*/
    return 0; /*0x182148*/
  return kern_dev_map_port_com(a1, a2, 1); /*0x18212c*/
}
