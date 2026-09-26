/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x160e60. */
int __cdecl kern_PMRestoreDefaults(int *a1)
{
  if ( a1 == &realhost ) /*0x160e6a*/
    return PMRestoreDefaults(); /*0x160e6c*/
  else
    return 22; /*0x160e78*/
}
