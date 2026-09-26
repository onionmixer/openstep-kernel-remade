/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16cd9c. */
int __cdecl kern_serv_get_log(int *a1, int a2)
{
  int v2; // esi
  int v4; // eax
  int v5; // edx
  int v6; // ebx
  int v7; // edx
  _BYTE v8[4]; // [esp+Ch] [ebp-8h] BYREF
  int v9; // [esp+10h] [ebp-4h] BYREF

  v2 = *a1; /*0x16cdab*/
  if ( *(_DWORD *)(*a1 + 48) ) /*0x16cdad*/
  {
    v4 = *(_DWORD *)(v2 + 40); /*0x16cdc8*/
    v5 = *(_DWORD *)(v2 + 36); /*0x16cdcb*/
    if ( v4 == v5 ) /*0x16cdd0*/
    {
      *(_DWORD *)(v2 + 24) = a2; /*0x16cdd2*/
      return 0; /*0x16cdd5*/
    }
    else
    {
      v6 = ~page_mask & (page_mask + v4 - v5); /*0x16cde9*/
      vm_read_EXTERNAL(*(_DWORD *)(v2 + 1228), v5, v6, &v9, v8); /*0x16cdfc*/
      kern_serv_log_data(a2, v9, (*(_DWORD *)(v2 + 40) - *(_DWORD *)(v2 + 36)) >> 5); /*0x16ce10*/
      port_deallocate_EXTERNAL(*(_DWORD *)(v2 + 8), a2); /*0x16ce1d*/
      vm_deallocate_EXTERNAL(*(_DWORD *)(v2 + 8), v9, v6); /*0x16ce2b*/
      v7 = splhigh(); /*0x16ce38*/
      do /*0x16ce4e*/
      {
        while ( *(_DWORD *)v2 ) /*0x16ce3c*/
          ; /*0x16ce3e*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v2, 1) == 1 ); /*0x16ce4e*/
      *(_DWORD *)(v2 + 40) = *(_DWORD *)(v2 + 36); /*0x16ce53*/
      _InterlockedExchange((volatile __int32 *)v2, 0); /*0x16ce58*/
      splx(v7); /*0x16ce5b*/
      return 0; /*0x16ce60*/
    }
  }
  else
  {
    port_deallocate_EXTERNAL(*(_DWORD *)(v2 + 8), a2); /*0x16cdb8*/
    return 101; /*0x16cdbd*/
  }
}
