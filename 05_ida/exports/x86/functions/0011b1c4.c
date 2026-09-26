/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11b1c4. */
int __cdecl geterror(int a1)
{
  int result; // eax

  result = 0; /*0x11b1ca*/
  if ( (*(_BYTE *)a1 & 4) != 0 ) /*0x11b1cf*/
  {
    result = *(__int16 *)(a1 + 28); /*0x11b1d1*/
    if ( !*(_WORD *)(a1 + 28) ) /*0x11b1d1*/
      return 5; /*0x11b1d9*/
  }
  return result; /*0x11b1e0*/
}
