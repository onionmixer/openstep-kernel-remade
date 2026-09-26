/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x161e7c. */
int __cdecl enqueue_tail(int a1, _DWORD *a2)
{
  *a2 = a1; /*0x161e86*/
  a2[1] = *(_DWORD *)(a1 + 4); /*0x161e8b*/
  *(_DWORD *)a2[1] = a2; /*0x161e91*/
  *(_DWORD *)(a1 + 4) = a2; /*0x161e93*/
  return a1; /*0x161e96*/
}
