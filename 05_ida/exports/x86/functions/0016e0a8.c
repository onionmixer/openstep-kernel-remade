/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16e0a8. */
int (__cdecl *__cdecl mach_host_server_routine(int a1))(int, int)
{
  unsigned int v1; // eax

  v1 = *(_DWORD *)(a1 + 20) - 2600; /*0x16e0b1*/
  if ( v1 > 0x29 ) /*0x16e0b9*/
    return nullptr; /*0x16e0c8*/
  else
    return funcs_16E096[v1]; /*0x16e0bb*/
}
