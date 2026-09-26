/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x107400. */
int proc_cache_clear()
{
  int v0; // eax
  int result; // eax

  for ( ; freeproc; result = zfree(proc_zone, v0) ) /*0x10740a*/
  {
    --dword_1E56C0; /*0x10740c*/
    v0 = freeproc; /*0x107412*/
    freeproc = *(_DWORD *)(freeproc + 8); /*0x10741a*/
  }
  return result; /*0x10743b*/
}
