/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16c98c. */
int __cdecl kern_serv_boot_port(int a1, int a2)
{
  *(_DWORD *)(*(_DWORD *)a1 + 16) = a2; /*0x16c997*/
  return 0; /*0x16c99e*/
}
