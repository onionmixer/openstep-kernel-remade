/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18a2cc. */
int __cdecl suibyte(unsigned int a1, unsigned __int8 a2)
{
  *(_DWORD *)(active_threads + 116) = sub_18A2F8; /*0x18a2da*/
  __writefsbyte(a1, a2); /*0x18a2e1*/
  *(_DWORD *)(active_threads + 116) = 0; /*0x18a2e9*/
  return 0; /*0x18a2f4*/
}
