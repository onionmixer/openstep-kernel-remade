/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17b134. */
int __cdecl vm_page_init(int a1, int a2, unsigned int a3, int a4)
{
  int v4; // ebx
  int v5; // edx
  int result; // eax

  qmemcpy((void *)a1, &vm_page_template, 0x30u); /*0x17b150*/
  *(_DWORD *)(a1 + 36) = a4; /*0x17b152*/
  if ( (*(_BYTE *)(a1 + 32) & 4) != 0 ) /*0x17b15c*/
    panic(aVmPageInsert); /*0x17b163*/
  *(_DWORD *)(a1 + 20) = a2; /*0x17b171*/
  *(_DWORD *)(a1 + 24) = a3; /*0x17b174*/
  v4 = vm_page_buckets + 8 * (vm_page_hash_mask & (a2 + (a3 >> page_shift))); /*0x17b191*/
  v5 = splimp(); /*0x17b199*/
  do /*0x17b1ae*/
  {
    while ( *(_DWORD *)v4 ) /*0x17b19c*/
      ; /*0x17b19e*/
  }
  while ( _InterlockedExchange((volatile __int32 *)v4, 1) == 1 ); /*0x17b1ae*/
  *(_DWORD *)(a1 + 16) = *(_DWORD *)(v4 + 4); /*0x17b1b6*/
  *(_DWORD *)(v4 + 4) = a1; /*0x17b1b9*/
  _InterlockedExchange((volatile __int32 *)v4, 0); /*0x17b1be*/
  splx(v5); /*0x17b1c1*/
  result = *(_DWORD *)(a2 + 4); /*0x17b1c9*/
  if ( a2 == result ) /*0x17b1ce*/
    *(_DWORD *)a2 = a1; /*0x17b1d3*/
  else
    *(_DWORD *)(result + 8) = a1; /*0x17b1db*/
  *(_DWORD *)(a1 + 12) = result; /*0x17b1e1*/
  *(_DWORD *)(a1 + 8) = a2; /*0x17b1e7*/
  *(_DWORD *)(a2 + 4) = a1; /*0x17b1ea*/
  *(_BYTE *)(a1 + 32) |= 4u; /*0x17b1ed*/
  ++*(_WORD *)(a2 + 26); /*0x17b1f1*/
  return result; /*0x17b1f8*/
}
