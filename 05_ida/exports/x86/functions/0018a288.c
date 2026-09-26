/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18a288. */
int __cdecl subyte(unsigned int a1, unsigned __int8 a2)
{
  *(_DWORD *)(active_threads + 116) = sub_18A2B4; /*0x18a296*/
  __writefsbyte(a1, a2); /*0x18a29d*/
  *(_DWORD *)(active_threads + 116) = 0; /*0x18a2a5*/
  return 0; /*0x18a2b0*/
}
