/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a19e8. */
int __cdecl sub_1A19E8(int a1)
{
  int result; // eax

  result = a1; /*0x1a19eb*/
  if ( (*(_BYTE *)(a1 + 124) & 4) != 0 ) /*0x1a19f2*/
  {
    *(_BYTE *)(a1 + 120) |= 4u; /*0x1a19f4*/
    *(_DWORD *)(a1 + 124) &= ~4u; /*0x1a19f8*/
  }
  return result; /*0x1a19fe*/
}
