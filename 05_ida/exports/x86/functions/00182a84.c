/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x182a84. */
int __cdecl driverServer_server_routine(int a1)
{
  unsigned int v1; // eax

  v1 = *(_DWORD *)(a1 + 20) - 2700; /*0x182a8d*/
  if ( v1 > 0x26 ) /*0x182a95*/
    return 0; /*0x182aa4*/
  else
    return funcs_182A72[v1]; /*0x182a97*/
}
