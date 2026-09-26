/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10372c. */
int __cdecl ticks_to_timeval(int a1, int *a2)
{
  int result; // eax
  int v3; // edx

  result = a1 / hz; /*0x103733*/
  v3 = a1 % hz; /*0x103733*/
  *a2 = a1 / hz; /*0x10373c*/
  a2[1] = tick * v3; /*0x103745*/
  return result; /*0x10374a*/
}
