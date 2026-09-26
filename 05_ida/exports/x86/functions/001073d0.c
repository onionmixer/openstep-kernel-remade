/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1073d0. */
int getproc()
{
  if ( max_proc <= dword_1E56C0 ) /*0x1073de*/
    return 0; /*0x1073f8*/
  ++dword_1E56C0; /*0x1073e1*/
  return zalloc(proc_zone); /*0x1073f4*/
}
