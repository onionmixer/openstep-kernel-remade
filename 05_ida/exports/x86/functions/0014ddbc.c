/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14ddbc. */
int __cdecl ipc_right_dncancel(int a1, int a2, int a3, int a4)
{
  int result; // eax

  result = ipc_port_dncancel(a2, a3, *(_DWORD *)(a4 + 8)); /*0x14ddcf*/
  *(_DWORD *)(a4 + 8) = 0; /*0x14ddd4*/
  if ( (*(_BYTE *)(a4 + 2) & 0x40) != 0 ) /*0x14dde2*/
  {
    ipc_space_release(a1); /*0x14dde8*/
    return 0; /*0x14dded*/
  }
  return result; /*0x14ddef*/
}
