/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1212d0. */
int netisr_thread()
{
  thread_act_t v0; // ebx

  v0 = active_threads; /*0x1212d4*/
  stack_privilege(active_threads); /*0x1212db*/
  thread_bind(v0, master_processor); /*0x1212e8*/
  return thread_block_with_continuation(netisr_thread_continue); /*0x1212f7*/
}
