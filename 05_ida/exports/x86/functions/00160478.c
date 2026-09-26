/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x160478. */
int ns_hardclock_init()
{
  ns_per_tick = 1000000000 / hz; /*0x16049a*/
  return hardclock_init(1000000000 / hz, (1000000000 / hz) >> 31); /*0x1604aa*/
}
