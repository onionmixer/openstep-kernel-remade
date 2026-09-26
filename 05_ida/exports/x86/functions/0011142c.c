/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11142c. */
int __cdecl ttselwakeup(int a1)
{
  int v1; // esi
  int v2; // edx

  v1 = spltty(); /*0x111439*/
  v2 = *(_DWORD *)(a1 + 40); /*0x11143b*/
  if ( v2 ) /*0x111440*/
  {
    selwakeup(v2, *(_DWORD *)(a1 + 64) & 0x800); /*0x11144c*/
    *(_DWORD *)(a1 + 64) &= ~0x800u; /*0x111451*/
    selthreadclear((_DWORD *)(a1 + 40)); /*0x11145c*/
  }
  return splx(v1); /*0x11146d*/
}
