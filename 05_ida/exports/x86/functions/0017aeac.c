/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17aeac. */
void __cdecl vm_page_remove(int a1)
{
  int v1; // ebx
  int v2; // ecx
  int v3; // eax
  _DWORD *v4; // edx
  int v5; // edx
  _DWORD *v6; // eax

  if ( (*(_BYTE *)(a1 + 32) & 4) != 0 ) /*0x17aeb9*/
  {
    v1 = vm_page_buckets + 8 * (vm_page_hash_mask & (*(_DWORD *)(a1 + 20) + (*(_DWORD *)(a1 + 24) >> page_shift))); /*0x17aed9*/
    v2 = splimp(); /*0x17aee1*/
    do /*0x17aef6*/
    {
      while ( *(_DWORD *)v1 ) /*0x17aee4*/
        ; /*0x17aee6*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v1, 1) == 1 ); /*0x17aef6*/
    v3 = *(_DWORD *)(v1 + 4); /*0x17aef8*/
    if ( v3 == a1 ) /*0x17aefd*/
    {
      *(_DWORD *)(v1 + 4) = *(_DWORD *)(a1 + 16); /*0x17af02*/
    }
    else
    {
      do /*0x17af14*/
      {
        v4 = (_DWORD *)(v3 + 16); /*0x17af0c*/
        v3 = *(_DWORD *)(v3 + 16); /*0x17af0f*/
      }
      while ( v3 != a1 ); /*0x17af14*/
      *v4 = *(_DWORD *)(v3 + 16); /*0x17af19*/
    }
    _InterlockedExchange((volatile __int32 *)v1, 0); /*0x17af1d*/
    splx(v2); /*0x17af20*/
    v5 = *(_DWORD *)(a1 + 8); /*0x17af25*/
    v6 = *(_DWORD **)(a1 + 12); /*0x17af28*/
    if ( *(_DWORD *)(a1 + 20) == v5 ) /*0x17af2e*/
      *(_DWORD *)(v5 + 4) = v6; /*0x17af30*/
    else
      *(_DWORD *)(v5 + 12) = v6; /*0x17af38*/
    if ( *(_DWORD **)(a1 + 20) == v6 ) /*0x17af3e*/
      *v6 = v5; /*0x17af08*/
    else
      v6[2] = v5; /*0x17af40*/
    --*(_WORD *)(*(_DWORD *)(a1 + 20) + 26); /*0x17af46*/
    *(_BYTE *)(a1 + 32) &= ~4u; /*0x17af4a*/
  }
}
