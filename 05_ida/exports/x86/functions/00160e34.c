/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x160e34. */
int __cdecl kern_PMSetPowerManagement(int *a1, int a2, int a3)
{
  if ( a1 == &realhost ) /*0x160e3e*/
    return PMSetPowerManagement(a2, a3); /*0x160e48*/
  else
    return 22; /*0x160e54*/
}
