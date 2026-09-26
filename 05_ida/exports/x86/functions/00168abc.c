/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x168abc. */
int consider_thread_collect()
{
  int result; // eax

  if ( !thread_collect_max_rate ) /*0x168ac6*/
    thread_collect_max_rate = hz; /*0x168ace*/
  if ( thread_collect_allowed ) /*0x168adb*/
  {
    result = thread_collect_max_rate + thread_collect_last_tick; /*0x168ae2*/
    if ( sched_tick > (unsigned int)(thread_collect_max_rate + thread_collect_last_tick) ) /*0x168af0*/
      thread_collect_last_tick = sched_tick; /*0x168af2*/
  }
  return result; /*0x168afa*/
}
