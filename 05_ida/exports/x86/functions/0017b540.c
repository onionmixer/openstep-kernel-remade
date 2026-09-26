/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17b540. */
void __cdecl vm_page_free(int a1)
{
  int v1; // ebx
  int v2; // ecx
  int v3; // eax
  _DWORD *v4; // edx
  int v5; // edx
  _DWORD *v6; // eax

  if ( (*(_BYTE *)(a1 + 32) & 4) != 0 ) /*0x17b54d*/
  {
    v1 = vm_page_buckets + 8 * (vm_page_hash_mask & (*(_DWORD *)(a1 + 20) + (*(_DWORD *)(a1 + 24) >> page_shift))); /*0x17b56d*/
    v2 = splimp(); /*0x17b575*/
    do /*0x17b58a*/
    {
      while ( *(_DWORD *)v1 ) /*0x17b578*/
        ; /*0x17b57a*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v1, 1) == 1 ); /*0x17b58a*/
    v3 = *(_DWORD *)(v1 + 4); /*0x17b58c*/
    if ( v3 == a1 ) /*0x17b591*/
    {
      *(_DWORD *)(v1 + 4) = *(_DWORD *)(a1 + 16); /*0x17b596*/
    }
    else
    {
      do /*0x17b5a8*/
      {
        v4 = (_DWORD *)(v3 + 16); /*0x17b5a0*/
        v3 = *(_DWORD *)(v3 + 16); /*0x17b5a3*/
      }
      while ( v3 != a1 ); /*0x17b5a8*/
      *v4 = *(_DWORD *)(v3 + 16); /*0x17b5ad*/
    }
    _InterlockedExchange((volatile __int32 *)v1, 0); /*0x17b5b1*/
    splx(v2); /*0x17b5b4*/
    v5 = *(_DWORD *)(a1 + 8); /*0x17b5bc*/
    v6 = *(_DWORD **)(a1 + 12); /*0x17b5bf*/
    if ( *(_DWORD *)(a1 + 20) == v5 ) /*0x17b5c5*/
      *(_DWORD *)(v5 + 4) = v6; /*0x17b5c7*/
    else
      *(_DWORD *)(v5 + 12) = v6; /*0x17b5cc*/
    if ( *(_DWORD **)(a1 + 20) == v6 ) /*0x17b5d2*/
      *v6 = v5; /*0x17b59c*/
    else
      v6[2] = v5; /*0x17b5d4*/
    --*(_WORD *)(*(_DWORD *)(a1 + 20) + 26); /*0x17b5da*/
    *(_BYTE *)(a1 + 32) &= ~4u; /*0x17b5de*/
  }
  if ( (*(_BYTE *)(a1 + 30) & 8) == 0 ) /*0x17b5e6*/
    vm_page_addfree(a1); /*0x17b5e9*/
}
