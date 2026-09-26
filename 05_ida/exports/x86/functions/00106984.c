/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x106984. */
int __cdecl newproc(int a1)
{
  int v1; // eax

  v1 = alloc_posix_proc(); /*0x10698b*/
  return cloneproc(*(_DWORD *)active_u, a1, v1); /*0x10699f*/
}
