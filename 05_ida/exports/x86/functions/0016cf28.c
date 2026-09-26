/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16cf28. */
int __cdecl sub_16CF28(int a1)
{
  int v1; // edi
  int v2; // edx
  int v3; // esi
  int result; // eax
  int v5; // edx
  _BYTE v6[4]; // [esp+Ch] [ebp-8h] BYREF
  int v7; // [esp+10h] [ebp-4h] BYREF

  v1 = ~page_mask & (page_mask + *(_DWORD *)(a1 + 40) - *(_DWORD *)(a1 + 36)); /*0x16cf45*/
  v2 = splhigh(); /*0x16cf4c*/
  do /*0x16cf62*/
  {
    while ( *(_DWORD *)a1 ) /*0x16cf50*/
      ; /*0x16cf52*/
  }
  while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x16cf62*/
  v3 = *(_DWORD *)(a1 + 24); /*0x16cf64*/
  *(_DWORD *)(a1 + 24) = 0; /*0x16cf67*/
  _InterlockedExchange((volatile __int32 *)a1, 0); /*0x16cf70*/
  result = splx(v2); /*0x16cf73*/
  if ( v3 ) /*0x16cf7d*/
  {
    vm_read_EXTERNAL(*(_DWORD *)(a1 + 1228), *(_DWORD *)(a1 + 36), v1, &v7, v6); /*0x16cf93*/
    kern_serv_log_data(v3, v7, (*(_DWORD *)(a1 + 40) - *(_DWORD *)(a1 + 36)) >> 5); /*0x16cfa7*/
    port_deallocate_EXTERNAL(*(_DWORD *)(a1 + 8), v3); /*0x16cfb4*/
    vm_deallocate_EXTERNAL(*(_DWORD *)(a1 + 8), v7, v1); /*0x16cfc2*/
    v5 = splhigh(); /*0x16cfcc*/
    do /*0x16cfe6*/
    {
      while ( *(_DWORD *)a1 ) /*0x16cfd4*/
        ; /*0x16cfd6*/
    }
    while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x16cfe6*/
    *(_DWORD *)(a1 + 40) = *(_DWORD *)(a1 + 36); /*0x16cfeb*/
    _InterlockedExchange((volatile __int32 *)a1, 0); /*0x16cff0*/
    return splx(v5); /*0x16cff3*/
  }
  return result; /*0x16cffb*/
}
