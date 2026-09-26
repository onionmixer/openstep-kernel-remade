/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16ba88. */
__int32 consider_zone_gc()
{
  __int32 result; // eax

  if ( !zone_gc_max_rate ) /*0x16ba92*/
    zone_gc_max_rate = hz; /*0x16ba9a*/
  if ( zone_gc_allowed ) /*0x16baa7*/
  {
    result = zone_gc_max_rate + zone_gc_last_tick; /*0x16baae*/
    if ( sched_tick > (unsigned int)(zone_gc_max_rate + zone_gc_last_tick) ) /*0x16babc*/
    {
      zone_gc_last_tick = sched_tick; /*0x16babe*/
      return zone_gc(); /*0x16bac4*/
    }
  }
  return result; /*0x16bacb*/
}
