/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18e634. */
int __cdecl set_thread_fpstate(int a1, int a2, unsigned int a3)
{
  int v3; // ebx

  if ( a3 <= 0x1A ) /*0x18e63e*/
    return 4; /*0x18e680*/
  v3 = *(_DWORD *)(a1 + 40); /*0x18e643*/
  fp_terminate(a1); /*0x18e64a*/
  qmemcpy((void *)(v3 + 124), (const void *)a2, 0x1Cu); /*0x18e658*/
  qmemcpy((void *)(v3 + 152), (const void *)(a2 + 28), 0x50u); /*0x18e66c*/
  *(_BYTE *)(*(_DWORD *)(a1 + 40) + 240) |= 2u; /*0x18e674*/
  return 0; /*0x18e688*/
}
