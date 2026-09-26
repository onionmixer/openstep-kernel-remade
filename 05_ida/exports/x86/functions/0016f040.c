/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16f040. */
int (__cdecl *__cdecl mach_port_server_routine(int a1))(int, int)
{
  unsigned int v1; // eax

  v1 = *(_DWORD *)(a1 + 20) - 3200; /*0x16f049*/
  if ( v1 > 0x12 ) /*0x16f051*/
    return nullptr; /*0x16f060*/
  else
    return funcs_16F02E[v1]; /*0x16f053*/
}
