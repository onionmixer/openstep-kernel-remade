/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18df80. */
void __cdecl thread_syscall_return(int a1)
{
  int v1; // eax
  int v2; // ebx
  int v3; // edx
  int v4; // edx
  thread_act_t v5; // [esp+Ch] [ebp-4h]

  v5 = active_threads; /*0x18df8f*/
  v1 = *(_DWORD *)(*(_DWORD *)(active_threads + 40) + 112); /*0x18df95*/
  if ( v1 ) /*0x18df9a*/
  {
    v2 = v1 + 132; /*0x18df9c*/
  }
  else
  {
    v3 = kalloc(0xE0u); /*0x18dfae*/
    *(_DWORD *)(*(_DWORD *)(v5 + 40) + 112) = v3; /*0x18dfb6*/
    qmemcpy((void *)(v3 + 132), &unk_1D15E0, 0x5Cu); /*0x18dfcc*/
    *(_DWORD *)(v3 + 196) = 512; /*0x18dfce*/
    *(_WORD *)(v3 + 192) = 99; /*0x18dfd8*/
    *(_WORD *)(v3 + 204) = 107; /*0x18dfe1*/
    *(_WORD *)(v3 + 144) = 107; /*0x18dfea*/
    *(_WORD *)(v3 + 140) = 107; /*0x18dff3*/
    *(_WORD *)(v3 + 136) = 0; /*0x18dffc*/
    *(_WORD *)(v3 + 132) = 0; /*0x18e005*/
    v2 = v3 + 132; /*0x18e00e*/
  }
  *(_DWORD *)(v2 + 44) = a1; /*0x18e016*/
  check_for_ast(v2); /*0x18e01a*/
  if ( (*(_BYTE *)(v2 + 66) & 2) != 0 ) /*0x18e02e*/
    v4 = v2 + 92; /*0x18e030*/
  else
    v4 = v2 + 76; /*0x18e038*/
  *(_DWORD *)(**(_DWORD **)(v5 + 40) + 4) = v4; /*0x18e03b*/
  _return_with_state(); /*0x18e03f*/
}
