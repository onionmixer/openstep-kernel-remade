/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18e8b8. */
int __cdecl get_thread_exceptstate(int a1, _DWORD *a2, _DWORD *a3)
{
  int v4; // eax
  int v5; // eax
  int v6; // edx

  if ( *a3 <= 1u ) /*0x18e8c7*/
    return 4; /*0x18e8c9*/
  v4 = *(_DWORD *)(*(_DWORD *)(a1 + 40) + 112); /*0x18e8da*/
  if ( v4 ) /*0x18e8df*/
  {
    v5 = v4 + 132; /*0x18e8e1*/
  }
  else
  {
    v6 = kalloc(0xE0u); /*0x18e8f2*/
    *(_DWORD *)(*(_DWORD *)(a1 + 40) + 112) = v6; /*0x18e8f7*/
    v5 = v6 + 132; /*0x18e8fa*/
    qmemcpy((void *)(v6 + 132), &unk_1D15E0, 0x5Cu); /*0x18e90d*/
    *(_DWORD *)(v6 + 196) = 512; /*0x18e90f*/
    *(_WORD *)(v6 + 192) = 99; /*0x18e919*/
    *(_WORD *)(v6 + 204) = 107; /*0x18e922*/
    *(_WORD *)(v6 + 144) = 107; /*0x18e92b*/
    *(_WORD *)(v6 + 140) = 107; /*0x18e934*/
    *(_WORD *)(v6 + 136) = 0; /*0x18e93d*/
    *(_WORD *)(v6 + 132) = 0; /*0x18e946*/
  }
  *a2 = *(_DWORD *)(v5 + 48); /*0x18e952*/
  a2[1] = *(_DWORD *)(v5 + 52); /*0x18e957*/
  *a3 = 2; /*0x18e95d*/
  return 0; /*0x18e968*/
}
