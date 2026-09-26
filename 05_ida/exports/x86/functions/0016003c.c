/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16003c. */
int __cdecl vm_info_free(_DWORD *a1)
{
  int v1; // eax

  v1 = *a1; /*0x160043*/
  if ( (*(_BYTE *)(*a1 + 56) & 0x10) != 0 && !*(_WORD *)(v1 + 4) ) /*0x16004b*/
    mfs_memfree(v1, 0); /*0x160055*/
  return zfree(vm_info_zone, *a1); /*0x16006c*/
}
