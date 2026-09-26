/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17ae0c. */
int __cdecl vm_page_insert(int a1, int a2, unsigned int a3)
{
  int v3; // ebx
  int v4; // edx
  int result; // eax

  if ( (*(_BYTE *)(a1 + 32) & 4) != 0 ) /*0x17ae1f*/
    panic(aVmPageInsert); /*0x17ae26*/
  *(_DWORD *)(a1 + 20) = a2; /*0x17ae2e*/
  *(_DWORD *)(a1 + 24) = a3; /*0x17ae31*/
  v3 = vm_page_buckets + 8 * (vm_page_hash_mask & (a2 + (a3 >> page_shift))); /*0x17ae4c*/
  v4 = splimp(); /*0x17ae54*/
  do /*0x17ae6a*/
  {
    while ( *(_DWORD *)v3 ) /*0x17ae58*/
      ; /*0x17ae5a*/
  }
  while ( _InterlockedExchange((volatile __int32 *)v3, 1) == 1 ); /*0x17ae6a*/
  *(_DWORD *)(a1 + 16) = *(_DWORD *)(v3 + 4); /*0x17ae6f*/
  *(_DWORD *)(v3 + 4) = a1; /*0x17ae72*/
  _InterlockedExchange((volatile __int32 *)v3, 0); /*0x17ae77*/
  splx(v4); /*0x17ae7a*/
  result = *(_DWORD *)(a2 + 4); /*0x17ae7f*/
  if ( a2 == result ) /*0x17ae84*/
    *(_DWORD *)a2 = a1; /*0x17ae86*/
  else
    *(_DWORD *)(result + 8) = a1; /*0x17ae8c*/
  *(_DWORD *)(a1 + 12) = result; /*0x17ae8f*/
  *(_DWORD *)(a1 + 8) = a2; /*0x17ae92*/
  *(_DWORD *)(a2 + 4) = a1; /*0x17ae95*/
  *(_BYTE *)(a1 + 32) |= 4u; /*0x17ae98*/
  ++*(_WORD *)(a2 + 26); /*0x17ae9c*/
  return result; /*0x17aea3*/
}
