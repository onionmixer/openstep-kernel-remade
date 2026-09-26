/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x187fec. */
int __cdecl isbad(int a1, int a2, int a3, int a4)
{
  int v4; // edx
  int v5; // esi
  int v6; // ebx
  int v7; // ecx
  int v8; // eax

  v4 = a3 << 8; /*0x187ffe*/
  v5 = a4 + (a3 << 8) + (a2 << 16); /*0x188005*/
  v6 = 0; /*0x188008*/
  v7 = 0; /*0x18800a*/
  do /*0x188033*/
  {
    LOWORD(v4) = *(_WORD *)(v7 + a1 + 8); /*0x18800c*/
    v4 <<= 16; /*0x188011*/
    v8 = v4 + *(unsigned __int16 *)(v7 + a1 + 10); /*0x188019*/
    if ( v5 == v8 ) /*0x18801d*/
      return v6; /*0x188021*/
    if ( v5 < v8 ) /*0x188026*/
      break; /*0x188026*/
    if ( v8 < 0 ) /*0x18802a*/
      break; /*0x18802a*/
    v7 += 4; /*0x18802c*/
    ++v6; /*0x18802f*/
  }
  while ( v6 <= 125 ); /*0x188033*/
  return -1; /*0x18803d*/
}
