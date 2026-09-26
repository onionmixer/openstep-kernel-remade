/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18dec0. */
void thread_exception_return()
{
  thread_act_t v0; // ebx
  int v1; // eax
  int v2; // esi
  int v3; // edx
  int v4; // edx

  v0 = active_threads; /*0x18dec6*/
  v1 = *(_DWORD *)(*(_DWORD *)(active_threads + 40) + 112); /*0x18decf*/
  if ( v1 ) /*0x18ded4*/
  {
    v2 = v1 + 132; /*0x18ded6*/
  }
  else
  {
    v3 = kalloc(0xE0u); /*0x18deea*/
    *(_DWORD *)(*(_DWORD *)(v0 + 40) + 112) = v3; /*0x18deef*/
    qmemcpy((void *)(v3 + 132), &unk_1D15E0, 0x5Cu); /*0x18df05*/
    *(_DWORD *)(v3 + 196) = 512; /*0x18df07*/
    *(_WORD *)(v3 + 192) = 99; /*0x18df11*/
    *(_WORD *)(v3 + 204) = 107; /*0x18df1a*/
    *(_WORD *)(v3 + 144) = 107; /*0x18df23*/
    *(_WORD *)(v3 + 140) = 107; /*0x18df2c*/
    *(_WORD *)(v3 + 136) = 0; /*0x18df35*/
    *(_WORD *)(v3 + 132) = 0; /*0x18df3e*/
    v2 = v3 + 132; /*0x18df47*/
  }
  check_for_ast(v2); /*0x18df4d*/
  if ( (*(_BYTE *)(v2 + 66) & 2) != 0 ) /*0x18df5e*/
    v4 = v2 + 92; /*0x18df60*/
  else
    v4 = v2 + 76; /*0x18df68*/
  *(_DWORD *)(**(_DWORD **)(v0 + 40) + 4) = v4; /*0x18df6b*/
  _return_with_state(); /*0x18df6f*/
}
