/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x168ed4. */
void swapper_init()
{
  dword_1F6D94 = (int)&swapin_queue; /*0x168ed7*/
  swapin_queue = (int)&swapin_queue; /*0x168ee1*/
  swapper_lock_data = 0; /*0x168eeb*/
}
