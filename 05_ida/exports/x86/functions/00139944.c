/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x139944. */
int __cdecl isclosing(__int16 a1, int a2)
{
  int v2; // eax

  v2 = stable[((_BYTE)a1 + HIBYTE(a1)) & 0xF]; /*0x13995b*/
  if ( !v2 ) /*0x139964*/
    return 0; /*0x139986*/
  while ( *(_WORD *)(v2 + 66) != a1 || *(_DWORD *)(v2 + 44) != a2 || (*(_BYTE *)(v2 + 64) & 8) == 0 ) /*0x139977*/
  {
    v2 = *(_DWORD *)v2; /*0x139980*/
    if ( !v2 ) /*0x139984*/
      return 0; /*0x139984*/
  }
  return 1; /*0x139988*/
}
