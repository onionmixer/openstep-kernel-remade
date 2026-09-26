/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x140bf0. */
__int16 __cdecl iput(int a1)
{
  __int16 v1; // ax
  __int16 v2; // ax

  if ( (*(_BYTE *)(a1 + 68) & 1) == 0 ) /*0x140bfb*/
    panic(aIput); /*0x140c02*/
  v1 = *(_WORD *)(a1 + 68); /*0x140c0a*/
  *(_WORD *)(a1 + 68) = v1 & 0xFFFE; /*0x140c13*/
  if ( (v1 & 0x10) != 0 ) /*0x140c19*/
  {
    LOBYTE(v1) = v1 & 0xEE; /*0x140c1b*/
    *(_WORD *)(a1 + 68) = v1; /*0x140c1d*/
    wakeup(a1); /*0x140c22*/
  }
  v2 = *(_WORD *)(a1 + 68); /*0x140c2a*/
  if ( (v2 & 0x46) != 0 ) /*0x140c30*/
  {
    LOBYTE(v2) = v2 | 8; /*0x140c32*/
    *(_WORD *)(a1 + 68) = v2; /*0x140c34*/
    microtime(&iuniqtime); /*0x140c3d*/
    if ( (*(_BYTE *)(a1 + 68) & 4) != 0 ) /*0x140c49*/
      *(_DWORD *)(a1 + 116) = iuniqtime; /*0x140c51*/
    if ( (*(_BYTE *)(a1 + 68) & 2) != 0 ) /*0x140c58*/
      *(_DWORD *)(a1 + 124) = iuniqtime; /*0x140c60*/
    if ( (*(_BYTE *)(a1 + 68) & 0x40) != 0 ) /*0x140c67*/
    {
      *(_DWORD *)(a1 + 76) = 0; /*0x140c69*/
      *(_DWORD *)(a1 + 132) = iuniqtime; /*0x140c76*/
    }
    *(_BYTE *)(a1 + 68) &= 0xB9u; /*0x140c7c*/
  }
  return vn_rele(a1 + 12); /*0x140c89*/
}
