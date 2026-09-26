/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x125464. */
int __cdecl in_rtchange(int a1)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 36); /*0x12546b*/
  if ( result ) /*0x125470*/
  {
    result = rtfree(*(_DWORD *)(a1 + 36)); /*0x125473*/
    *(_DWORD *)(a1 + 36) = 0; /*0x125478*/
  }
  return result; /*0x12547f*/
}
