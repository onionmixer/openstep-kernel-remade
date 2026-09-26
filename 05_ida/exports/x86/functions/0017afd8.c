/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17afd8. */
__int32 __cdecl vm_page_rename(int a1, int a2, unsigned int a3)
{
  int v3; // ebx
  int v4; // eax
  _DWORD *v5; // edx
  int v6; // edx
  _DWORD *v7; // eax
  int v8; // ebx
  int v9; // edx
  int v10; // eax
  int v12; // [esp+Ch] [ebp-4h]

  do /*0x17affd*/
  {
    while ( vm_page_queue_lock ) /*0x17afeb*/
      ; /*0x17afe9*/
  }
  while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x17affd*/
  if ( (*(_BYTE *)(a1 + 32) & 4) != 0 ) /*0x17b003*/
  {
    v3 = vm_page_buckets + 8 * (vm_page_hash_mask & (*(_DWORD *)(a1 + 20) + (*(_DWORD *)(a1 + 24) >> page_shift))); /*0x17b023*/
    v12 = splimp(); /*0x17b02b*/
    do /*0x17b042*/
    {
      while ( *(_DWORD *)v3 ) /*0x17b030*/
        ; /*0x17b032*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v3, 1) == 1 ); /*0x17b042*/
    v4 = *(_DWORD *)(v3 + 4); /*0x17b044*/
    if ( v4 == a1 ) /*0x17b049*/
    {
      *(_DWORD *)(v3 + 4) = *(_DWORD *)(a1 + 16); /*0x17b04e*/
    }
    else
    {
      do /*0x17b060*/
      {
        v5 = (_DWORD *)(v4 + 16); /*0x17b058*/
        v4 = *(_DWORD *)(v4 + 16); /*0x17b05b*/
      }
      while ( v4 != a1 ); /*0x17b060*/
      *v5 = *(_DWORD *)(v4 + 16); /*0x17b065*/
    }
    _InterlockedExchange((volatile __int32 *)v3, 0); /*0x17b069*/
    splx(v12); /*0x17b06f*/
    v6 = *(_DWORD *)(a1 + 8); /*0x17b077*/
    v7 = *(_DWORD **)(a1 + 12); /*0x17b07a*/
    if ( *(_DWORD *)(a1 + 20) == v6 ) /*0x17b080*/
      *(_DWORD *)(v6 + 4) = v7; /*0x17b082*/
    else
      *(_DWORD *)(v6 + 12) = v7; /*0x17b088*/
    if ( *(_DWORD **)(a1 + 20) == v7 ) /*0x17b08e*/
      *v7 = v6; /*0x17b054*/
    else
      v7[2] = v6; /*0x17b090*/
    --*(_WORD *)(*(_DWORD *)(a1 + 20) + 26); /*0x17b096*/
    *(_BYTE *)(a1 + 32) &= ~4u; /*0x17b09a*/
  }
  *(_DWORD *)(a1 + 20) = a2; /*0x17b0a1*/
  *(_DWORD *)(a1 + 24) = a3; /*0x17b0a7*/
  v8 = vm_page_buckets + 8 * (vm_page_hash_mask & (a2 + (a3 >> page_shift))); /*0x17b0c4*/
  v9 = splimp(); /*0x17b0cc*/
  do /*0x17b0e2*/
  {
    while ( *(_DWORD *)v8 ) /*0x17b0d0*/
      ; /*0x17b0d2*/
  }
  while ( _InterlockedExchange((volatile __int32 *)v8, 1) == 1 ); /*0x17b0e2*/
  *(_DWORD *)(a1 + 16) = *(_DWORD *)(v8 + 4); /*0x17b0e7*/
  *(_DWORD *)(v8 + 4) = a1; /*0x17b0ea*/
  _InterlockedExchange((volatile __int32 *)v8, 0); /*0x17b0ef*/
  splx(v9); /*0x17b0f2*/
  v10 = *(_DWORD *)(a2 + 4); /*0x17b0fa*/
  if ( a2 == v10 ) /*0x17b0ff*/
    *(_DWORD *)a2 = a1; /*0x17b101*/
  else
    *(_DWORD *)(v10 + 8) = a1; /*0x17b108*/
  *(_DWORD *)(a1 + 12) = v10; /*0x17b10b*/
  *(_DWORD *)(a1 + 8) = a2; /*0x17b111*/
  *(_DWORD *)(a2 + 4) = a1; /*0x17b114*/
  *(_BYTE *)(a1 + 32) |= 4u; /*0x17b117*/
  ++*(_WORD *)(a2 + 26); /*0x17b11b*/
  return _InterlockedExchange(&vm_page_queue_lock, 0); /*0x17b12a*/
}
