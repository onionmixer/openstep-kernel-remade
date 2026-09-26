/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x111c00. */
int pty_init()
{
  return lock_init(&pty_alloc_lock, 1); /*0x111c11*/
}
