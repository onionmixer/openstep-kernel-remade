/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18a184. */
unsigned int __cdecl fuword(unsigned int a1)
{
  unsigned int v1; // edx

  *(_DWORD *)(active_threads + 116) = sub_18A1AC; /*0x18a190*/
  v1 = __readfsdword(a1); /*0x18a197*/
  *(_DWORD *)(active_threads + 116) = 0; /*0x18a19f*/
  return v1; /*0x18a1aa*/
}
