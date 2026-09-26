/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1111b0. */
int __cdecl ttwakeup(int a1)
{
  int v1; // esi
  int v2; // edx

  v1 = spltty(); /*0x1111bd*/
  v2 = *(_DWORD *)(a1 + 40); /*0x1111bf*/
  if ( v2 ) /*0x1111c4*/
  {
    selwakeup(v2, *(_DWORD *)(a1 + 64) & 0x800); /*0x1111d0*/
    selthreadclear((_DWORD *)(a1 + 40)); /*0x1111d9*/
    *(_DWORD *)(a1 + 64) &= ~0x800u; /*0x1111de*/
  }
  splx(v1); /*0x1111e9*/
  if ( (*(_BYTE *)(a1 + 65) & 0x40) != 0 ) /*0x1111f5*/
    gsignal((_DWORD *)*(__int16 *)(a1 + 68), (char *)0x17); /*0x1111fe*/
  return wakeup(a1); /*0x11120f*/
}
