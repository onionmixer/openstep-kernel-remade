/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x107224. */
int __cdecl munmapfd(int a1)
{
  int result; // eax

  result = *(_DWORD *)(active_u + 340); /*0x10722f*/
  *(_BYTE *)(a1 + result) &= ~2u; /*0x107235*/
  return result; /*0x10723b*/
}
