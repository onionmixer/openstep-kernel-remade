/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x160e0c. */
int __cdecl kern_PMGetPowerStatus(int *a1, int a2)
{
  if ( a1 == &realhost ) /*0x160e16*/
    return PMGetPowerStatus(a2); /*0x160e1c*/
  else
    return 22; /*0x160e28*/
}
