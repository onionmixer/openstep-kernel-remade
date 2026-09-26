/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x161ec8. */
int __cdecl dequeue_tail(int a1)
{
  int v1; // edx

  v1 = *(_DWORD *)(a1 + 4); /*0x161ecf*/
  if ( v1 == a1 ) /*0x161ed4*/
    return 0; /*0x161ee8*/
  **(_DWORD **)(v1 + 4) = a1; /*0x161ed9*/
  *(_DWORD *)(a1 + 4) = *(_DWORD *)(v1 + 4); /*0x161ede*/
  return v1; /*0x161eea*/
}
