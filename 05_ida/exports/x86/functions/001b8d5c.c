/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b8d5c. */
id __cdecl -[AudioStream freeRegion:](AudioStream *self, SEL a2, $4BA88FAFA6E9A53AC825FB6F75E82BF2 *a3)
{
  IOFree((int)a3, 68); /*0x1b8d65*/
  return self; /*0x1b8d6f*/
}
