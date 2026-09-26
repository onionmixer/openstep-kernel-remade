/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x187938. */
int __cdecl sub_187938(int *a1)
{
  clock_interrupt(tick, a1[1] == 3); /*0x187960*/
  return hardclock(*a1, a1[1] | (a1[2] << 8)); /*0x187977*/
}
