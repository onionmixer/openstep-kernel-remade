/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1113c8. */
int __cdecl ttyselwait(thread_act_t *a1, int a2)
{
  int v2; // edi

  v2 = spltty(); /*0x1113d9*/
  if ( a2 == 1 ) /*0x1113de*/
  {
    if ( selthreadcache(a1 + 10) ) /*0x1113ec*/
      a1[16] |= 0x800u; /*0x1113f8*/
  }
  else if ( a2 == 2 && selthreadcache(a1 + 11) ) /*0x111408*/
  {
    a1[16] |= 0x1000u; /*0x111414*/
  }
  return splx(v2); /*0x111424*/
}
