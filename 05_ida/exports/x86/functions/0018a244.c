/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18a244. */
int __cdecl suword(unsigned int a1, unsigned int a2)
{
  *(_DWORD *)(active_threads + 116) = sub_18A270; /*0x18a252*/
  __writefsdword(a1, a2); /*0x18a259*/
  *(_DWORD *)(active_threads + 116) = 0; /*0x18a261*/
  return 0; /*0x18a26c*/
}
