/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18dc54. */
int __cdecl thread_user_state(int a1)
{
  int v1; // edx
  int v2; // edx

  v1 = *(_DWORD *)(*(_DWORD *)(a1 + 40) + 112); /*0x18dc5f*/
  if ( v1 ) /*0x18dc64*/
    return v1 + 132; /*0x18dcd0*/
  v2 = kalloc(0xE0u); /*0x18dc70*/
  *(_DWORD *)(*(_DWORD *)(a1 + 40) + 112) = v2; /*0x18dc75*/
  qmemcpy((void *)(v2 + 132), &unk_1D15E0, 0x5Cu); /*0x18dc8b*/
  *(_DWORD *)(v2 + 196) = 512; /*0x18dc8d*/
  *(_WORD *)(v2 + 192) = 99; /*0x18dc97*/
  *(_WORD *)(v2 + 204) = 107; /*0x18dca0*/
  *(_WORD *)(v2 + 144) = 107; /*0x18dca9*/
  *(_WORD *)(v2 + 140) = 107; /*0x18dcb2*/
  *(_WORD *)(v2 + 136) = 0; /*0x18dcbb*/
  *(_WORD *)(v2 + 132) = 0; /*0x18dcc4*/
  return v2 + 132; /*0x18dcd9*/
}
