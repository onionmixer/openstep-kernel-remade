/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a19c8. */
int __cdecl sub_1A19C8(int a1)
{
  int result; // eax

  result = a1; /*0x1a19cb*/
  if ( (*(_BYTE *)(a1 + 124) & 2) != 0 ) /*0x1a19d2*/
  {
    if ( *(_DWORD *)(a1 + 72) ) /*0x1a19d4*/
      *(_BYTE *)(a1 + 120) |= 2u; /*0x1a19da*/
    *(_DWORD *)(a1 + 124) &= ~2u; /*0x1a19de*/
  }
  return result; /*0x1a19e4*/
}
