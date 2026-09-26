/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x121300. */
int __cdecl raw_attach(int a1, __int16 a2)
{
  int *v2; // ebx
  int v4; // eax

  v2 = m_getclr(0, 4); /*0x121312*/
  if ( !v2 ) /*0x121319*/
    return 55; /*0x121320*/
  if ( sbreserve(a1 + 60, 0x800u) ) /*0x121331*/
  {
    if ( sbreserve(a1 + 36, 0x824u) ) /*0x121346*/
    {
      v4 = (int)v2 + v2[1]; /*0x121354*/
      *(_DWORD *)(v4 + 8) = a1; /*0x121357*/
      *(_DWORD *)(a1 + 8) = v4; /*0x12135a*/
      *(_DWORD *)(v4 + 48) = 0; /*0x12135d*/
      *(_WORD *)(v4 + 44) = **(_WORD **)(*(_DWORD *)(a1 + 12) + 4); /*0x12136d*/
      *(_WORD *)(v4 + 46) = a2; /*0x121375*/
      *(_DWORD *)v4 = rawcb; /*0x12137f*/
      *(_DWORD *)(v4 + 4) = &rawcb; /*0x121381*/
      *(_DWORD *)(rawcb + 4) = v4; /*0x12138e*/
      rawcb = v4; /*0x121391*/
      return 0; /*0x121398*/
    }
    sbrelease(a1 + 60); /*0x12139d*/
  }
  m_free((int)v2); /*0x1213a6*/
  return 55; /*0x1213b3*/
}
