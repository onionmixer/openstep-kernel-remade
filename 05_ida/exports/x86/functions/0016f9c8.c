/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16f9c8. */
int __cdecl mach_server_routine(int a1)
{
  unsigned int v1; // eax

  v1 = *(_DWORD *)(a1 + 20) - 2000; /*0x16f9d1*/
  if ( v1 > 0x67 ) /*0x16f9d9*/
    return 0; /*0x16f9e8*/
  else
    return funcs_16F9B6[v1]; /*0x16f9db*/
}
