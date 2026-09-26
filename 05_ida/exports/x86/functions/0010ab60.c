/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10ab60. */
int __cdecl wakeup_one(int a1)
{
  int v1; // esi

  v1 = splhigh(); /*0x10ab6d*/
  thread_wakeup_prim(a1, 1, 0); /*0x10ab74*/
  return splx(v1); /*0x10ab82*/
}
