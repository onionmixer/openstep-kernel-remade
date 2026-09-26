/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x139560. */
int __cdecl sub_139560(int *a1, int a2)
{
  int v2; // ebx

  --*(_WORD *)(a2 + 138); /*0x13956a*/
  if ( *(int **)(a2 + 108) == a1 ) /*0x139574*/
  {
    *(_DWORD *)(a2 + 108) = 0; /*0x139576*/
    v2 = 0; /*0x13957d*/
  }
  else
  {
    v2 = *a1; /*0x139584*/
  }
  kmem_free(kernel_map, a1, dword_1DE6B4); /*0x139595*/
  if ( fifo_alloc >= dword_1DE6B8 ) /*0x1395a8*/
    wakeup((int)&fifo_alloc); /*0x1395af*/
  fifo_alloc -= dword_1DE6B4; /*0x1395ba*/
  return v2; /*0x1395c2*/
}
