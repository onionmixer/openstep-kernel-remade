/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x139990. */
int __cdecl other_specvp(int a1)
{
  int v1; // eax
  __int16 v2; // bx
  int v3; // edx

  v1 = *(_DWORD *)(a1 + 48); /*0x139998*/
  v2 = *(_WORD *)(v1 + 66); /*0x13999b*/
  v3 = stable[((_BYTE)v2 + *(_BYTE *)(v1 + 67)) & 0xF]; /*0x1399ab*/
  if ( !v3 ) /*0x1399b4*/
    return 0; /*0x1399da*/
  while ( *(_WORD *)(v3 + 66) != v2 || v3 + 4 == a1 || *(_DWORD *)(v3 + 44) != *(_DWORD *)(a1 + 40) ) /*0x1399cb*/
  {
    v3 = *(_DWORD *)v3; /*0x1399d4*/
    if ( !v3 ) /*0x1399d8*/
      return 0; /*0x1399d8*/
  }
  return v3 + 4; /*0x1399df*/
}
