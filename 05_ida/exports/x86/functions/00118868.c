/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x118868. */
int __cdecl unp_connect2(int a1, int a2)
{
  int v2; // ecx
  int v4; // eax

  v2 = *(_DWORD *)(a1 + 8); /*0x118874*/
  if ( *(_WORD *)a2 != *(_WORD *)a1 ) /*0x11887d*/
    return 41; /*0x11887f*/
  v4 = *(_DWORD *)(a2 + 8); /*0x118888*/
  *(_DWORD *)(v2 + 12) = v4; /*0x11888b*/
  if ( *(_WORD *)a1 == 1 ) /*0x118895*/
  {
    *(_DWORD *)(v4 + 12) = v2; /*0x1188a8*/
    soisconnected(a2); /*0x1188ac*/
  }
  else
  {
    if ( *(_WORD *)a1 != 2 ) /*0x11889b*/
      panic(aUnpConnect2); /*0x1188c1*/
    *(_DWORD *)(v2 + 20) = *(_DWORD *)(v4 + 16); /*0x1188a0*/
    *(_DWORD *)(v4 + 16) = v2; /*0x1188a3*/
  }
  soisconnected(a1); /*0x1188b2*/
  return 0; /*0x1188cb*/
}
