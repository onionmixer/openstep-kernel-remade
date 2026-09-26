/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cfe1c. */
void __cdecl objc_setMultithreaded(bool flag)
{
  if ( flag ) /*0x1cfe23*/
    _objc_multithread_mask = 0; /*0x1cfe25*/
  else
    _objc_multithread_mask = -1; /*0x1cfe34*/
}
