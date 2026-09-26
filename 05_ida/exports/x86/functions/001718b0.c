/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1718b0. */
int __cdecl mach_debug_server_routine(int a1)
{
  unsigned int v1; // eax

  v1 = *(_DWORD *)(a1 + 20) - 3000; /*0x1718b9*/
  if ( v1 > 0x15 ) /*0x1718c1*/
    return 0; /*0x1718d0*/
  else
    return funcs_17189E[v1]; /*0x1718c3*/
}
