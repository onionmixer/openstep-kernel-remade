/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x140c90. */
__int16 __cdecl irele(int a1)
{
  __int16 v1; // ax

  if ( (*(_BYTE *)(a1 + 68) & 1) != 0 ) /*0x140c9b*/
    panic(aIrele); /*0x140ca2*/
  v1 = *(_WORD *)(a1 + 68); /*0x140caa*/
  if ( (v1 & 0x46) != 0 ) /*0x140cb0*/
  {
    LOBYTE(v1) = v1 | 8; /*0x140cb2*/
    *(_WORD *)(a1 + 68) = v1; /*0x140cb4*/
    microtime(&iuniqtime); /*0x140cbd*/
    if ( (*(_BYTE *)(a1 + 68) & 4) != 0 ) /*0x140cc9*/
      *(_DWORD *)(a1 + 116) = iuniqtime; /*0x140cd1*/
    if ( (*(_BYTE *)(a1 + 68) & 2) != 0 ) /*0x140cd8*/
      *(_DWORD *)(a1 + 124) = iuniqtime; /*0x140ce0*/
    if ( (*(_BYTE *)(a1 + 68) & 0x40) != 0 ) /*0x140ce7*/
    {
      *(_DWORD *)(a1 + 76) = 0; /*0x140ce9*/
      *(_DWORD *)(a1 + 132) = iuniqtime; /*0x140cf6*/
    }
    *(_BYTE *)(a1 + 68) &= 0xB9u; /*0x140cfc*/
  }
  return vn_rele(a1 + 12); /*0x140d09*/
}
