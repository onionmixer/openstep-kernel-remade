/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x161e5c. */
_DWORD *__cdecl enqueue_head(_DWORD *a1, _DWORD *a2)
{
  *a2 = *a1; /*0x161e68*/
  a2[1] = a1; /*0x161e6a*/
  *(_DWORD *)(*a2 + 4) = a2; /*0x161e6f*/
  *a1 = a2; /*0x161e72*/
  return a1; /*0x161e74*/
}
