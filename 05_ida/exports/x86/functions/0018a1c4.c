/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18a1c4. */
int __cdecl fubyte(unsigned int a1)
{
  signed __int8 v1; // dl

  *(_DWORD *)(active_threads + 116) = sub_18A1EC; /*0x18a1cf*/
  v1 = __readfsbyte(a1); /*0x18a1d6*/
  *(_DWORD *)(active_threads + 116) = 0; /*0x18a1de*/
  return v1; /*0x18a1ea*/
}
