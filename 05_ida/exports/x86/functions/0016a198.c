/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16a198. */
int init_timers()
{
  char *v0; // esi
  int i; // ebx
  int result; // eax

  v0 = (char *)&kernel_timer; /*0x16a19d*/
  for ( i = 0; i <= 0; ++i ) /*0x16a1a2*/
  {
    result = timer_init(v0); /*0x16a1a5*/
    current_timer[i] = 0; /*0x16a1aa*/
    v0 += 16; /*0x16a1b9*/
  }
  return result; /*0x16a1c3*/
}
