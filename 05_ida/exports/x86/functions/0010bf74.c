/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10bf74. */
int logwakeup()
{
  int result; // eax

  if ( log_open ) /*0x10bf7e*/
    return calloutEntryDispatch(dword_1E97CC); /*0x10bf86*/
  return result; /*0x10bf8d*/
}
