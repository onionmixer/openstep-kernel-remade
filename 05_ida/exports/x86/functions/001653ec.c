/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1653ec. */
int swtch_pri_continue()
{
  int v0; // edx

  if ( *(int *)(active_threads + 100) >= 0 ) /*0x1653f8*/
    thread_depress_abort(active_threads); /*0x1653fb*/
  v0 = 0; /*0x165408*/
  if ( *(int *)(processor_ptr[0] + 264) > 0 || *(int *)(*(_DWORD *)(processor_ptr[0] + 300) + 264) > 0 ) /*0x165420*/
    v0 = 1; /*0x165422*/
  return thread_syscall_return(v0); /*0x16542f*/
}
