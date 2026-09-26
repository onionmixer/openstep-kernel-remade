/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x165bec. */
void __cdecl task_deallocate(int a1)
{
  int v1; // ecx
  int v2; // esi
  volatile __int32 *v3; // edx

  if ( a1 ) /*0x165bf6*/
  {
    do /*0x165c0e*/
    {
      while ( *(_DWORD *)a1 ) /*0x165bfc*/
        ; /*0x165bfe*/
    }
    while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x165c0e*/
    v1 = *(_DWORD *)(a1 + 4) - 1; /*0x165c13*/
    *(_DWORD *)(a1 + 4) = v1; /*0x165c16*/
    _InterlockedExchange((volatile __int32 *)a1, 0); /*0x165c1c*/
    if ( !v1 ) /*0x165c20*/
    {
      v2 = *(_DWORD *)(a1 + 44); /*0x165c22*/
      v3 = (volatile __int32 *)(v2 + 344); /*0x165c25*/
      do /*0x165c3e*/
      {
        while ( *v3 ) /*0x165c2c*/
          ; /*0x165c2e*/
      }
      while ( _InterlockedExchange(v3, 1) == 1 ); /*0x165c3e*/
      pset_remove_task((_DWORD *)v2, (_DWORD *)a1); /*0x165c42*/
      _InterlockedExchange((volatile __int32 *)(v2 + 344), 0); /*0x165c4c*/
      pset_deallocate(v2); /*0x165c53*/
      vm_map_deallocate(*(_DWORD *)(a1 + 12)); /*0x165c5c*/
      ipc_space_release(*(_DWORD *)(a1 + 136)); /*0x165c68*/
      pcb_common_terminate(a1); /*0x165c6e*/
      utask_free(*(int **)(a1 + 56)); /*0x165c77*/
      zfree(task_zone, a1); /*0x165c84*/
    }
  }
}
