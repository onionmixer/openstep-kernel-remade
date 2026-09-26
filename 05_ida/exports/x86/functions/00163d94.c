/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x163d94. */
int recompute_priorities()
{
  int result; // eax

  ++sched_tick; /*0x163d97*/
  set_timeout((int)recompute_priorities_timer, hz); /*0x163da9*/
  result = sched_thread_id; /*0x163db1*/
  if ( sched_thread_id ) /*0x163db8*/
    return clear_wait(sched_thread_id, 0, 0); /*0x163dbf*/
  return result; /*0x163dc6*/
}
