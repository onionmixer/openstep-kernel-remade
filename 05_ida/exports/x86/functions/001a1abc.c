/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a1abc. */
_BOOL4 __cdecl PCtimersPending(int a1)
{
  return (*(_BYTE *)(a1 + 120) & 6) != 0; /*0x1a1ad0*/
}
