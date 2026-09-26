/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10ab38. */
int __cdecl wakeup(int a1)
{
  int v1; // esi

  v1 = splhigh(); /*0x10ab45*/
  thread_wakeup_prim(a1, 0, 0); /*0x10ab4c*/
  return splx(v1); /*0x10ab5a*/
}
