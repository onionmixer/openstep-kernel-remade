/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x165380. */
int swtch_continue()
{
  int v0; // edx

  v0 = 0; /*0x165388*/
  if ( *(int *)(processor_ptr[0] + 264) > 0 || *(int *)(*(_DWORD *)(processor_ptr[0] + 300) + 264) > 0 ) /*0x1653a0*/
    v0 = 1; /*0x1653a2*/
  return thread_syscall_return(v0); /*0x1653af*/
}
