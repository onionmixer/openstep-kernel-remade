/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x160cf8. */
int __cdecl kern_PMSetPowerState(int *a1, int a2, int a3)
{
  if ( a1 == &realhost ) /*0x160d02*/
    return PMSetPowerState(a2, a3); /*0x160d0c*/
  else
    return 22; /*0x160d18*/
}
