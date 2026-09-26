/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x116144. */
int __cdecl soisconnected(int a1)
{
  int v1; // ebx
  __int16 v2; // ax

  v1 = *(_DWORD *)(a1 + 16); /*0x11614c*/
  if ( v1 ) /*0x116151*/
  {
    if ( !soqremque(a1, 0) ) /*0x116156*/
      panic(aSoisconnected); /*0x116167*/
    soqinsque(v1, a1, 1); /*0x116173*/
    sowakeup(v1, v1 + 36); /*0x11617d*/
    wakeup(v1 + 84); /*0x116186*/
  }
  v2 = *(_WORD *)(a1 + 6); /*0x11618e*/
  LOBYTE(v2) = v2 & 0xF1 | 2; /*0x116194*/
  *(_WORD *)(a1 + 6) = v2; /*0x116196*/
  wakeup(a1 + 84); /*0x11619e*/
  sowakeup(a1, a1 + 36); /*0x1161a8*/
  return sowakeup(a1, a1 + 60); /*0x1161ba*/
}
