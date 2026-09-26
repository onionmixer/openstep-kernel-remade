/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1405c4. */
char __cdecl disksort_free(int a1)
{
  char result; // al

  result = *(_BYTE *)(a1 + 12); /*0x1405ca*/
  if ( (result & 1) != 0 ) /*0x1405cf*/
  {
    result &= ~1u; /*0x1405d1*/
    *(_BYTE *)(a1 + 12) = result; /*0x1405d3*/
    if ( dword_1F50EC ) /*0x1405dd*/
      return dword_1F50E8(a1); /*0x1405e5*/
  }
  return result; /*0x1405e9*/
}
