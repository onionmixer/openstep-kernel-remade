/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x165494. */
int thread_switch_continue()
{
  if ( *(int *)(active_threads + 100) >= 0 ) /*0x1654a0*/
    thread_depress_abort(active_threads); /*0x1654a3*/
  return thread_syscall_return(0); /*0x1654b4*/
}
