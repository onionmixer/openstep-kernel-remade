/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x142c24. */
_BOOL4 __cdecl isblock(int a1, int a2, int a3)
{
  int v3; // eax
  unsigned __int8 v5; // dl
  int v6; // eax

  v3 = *(_DWORD *)(a1 + 56); /*0x142c32*/
  if ( v3 == 2 ) /*0x142c38*/
  {
    v5 = 3 << (2 * (a3 & 3)); /*0x142c88*/
    v6 = a3 >> 2; /*0x142c8c*/
    return (v5 & *(_BYTE *)(v6 + a2)) == v5; /*0x142c8f*/
  }
  if ( v3 <= 2 ) /*0x142c3a*/
  {
    if ( v3 != 1 ) /*0x142c3f*/
LABEL_12:
      panic(aIsblock); /*0x142cb8*/
    v5 = 1 << (a3 & 7); /*0x142ca0*/
    v6 = a3 >> 3; /*0x142ca4*/
    return (v5 & *(_BYTE *)(v6 + a2)) == v5; /*0x142ca4*/
  }
  if ( v3 == 4 ) /*0x142c47*/
  {
    v5 = 15 << (4 * (a3 & 1)); /*0x142c6f*/
    v6 = a3 >> 1; /*0x142c73*/
    return (v5 & *(_BYTE *)(v6 + a2)) == v5; /*0x142cb6*/
  }
  if ( v3 != 8 ) /*0x142c4c*/
    goto LABEL_12; /*0x142c4c*/
  return *(_BYTE *)(a3 + a2) == 0xFF; /*0x142cc7*/
}
