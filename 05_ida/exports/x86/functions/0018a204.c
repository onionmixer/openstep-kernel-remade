/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18a204. */
int __cdecl fuibyte(unsigned int a1)
{
  signed __int8 v1; // dl

  *(_DWORD *)(active_threads + 116) = sub_18A22C; /*0x18a20f*/
  v1 = __readfsbyte(a1); /*0x18a216*/
  *(_DWORD *)(active_threads + 116) = 0; /*0x18a21e*/
  return v1; /*0x18a22a*/
}
