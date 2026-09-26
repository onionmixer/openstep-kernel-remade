/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14ab94. */
int __cdecl ipc_mqueue_copyin(int a1, unsigned int a2, volatile __int32 **a3, int *a4)
{
  volatile __int32 *v4; // edx
  int *v5; // eax
  int v6; // edi
  int v7; // ebx
  int v9; // eax
  volatile __int32 *v10; // edx

  v4 = (volatile __int32 *)(a1 + 8); /*0x14ab9d*/
  do /*0x14abb2*/
  {
    while ( *v4 ) /*0x14aba0*/
      ; /*0x14aba2*/
  }
  while ( _InterlockedExchange(v4, 1) == 1 ); /*0x14abb2*/
  if ( !*(_DWORD *)(a1 + 12) ) /*0x14abb4*/
    goto LABEL_21; /*0x14abb4*/
  v5 = ipc_entry_lookup((_DWORD *)a1, a2); /*0x14abc3*/
  if ( !v5 ) /*0x14abcd*/
    goto LABEL_21; /*0x14abcd*/
  v6 = v5[1]; /*0x14abd5*/
  if ( (*v5 & 0x20000) != 0 ) /*0x14abde*/
  {
    do /*0x14abfa*/
    {
      while ( *(_DWORD *)v6 ) /*0x14abe8*/
        ; /*0x14abea*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v6, 1) == 1 ); /*0x14abfa*/
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14abfe*/
    v7 = *(_DWORD *)(v6 + 48); /*0x14ac01*/
    if ( v7 ) /*0x14ac06*/
    {
      do /*0x14ac1a*/
      {
        while ( *(_DWORD *)v7 ) /*0x14ac08*/
          ; /*0x14ac0a*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v7, 1) == 1 ); /*0x14ac1a*/
      if ( *(int *)(v7 + 8) < 0 ) /*0x14ac20*/
      {
        _InterlockedExchange((volatile __int32 *)v7, 0); /*0x14ac24*/
        _InterlockedExchange((volatile __int32 *)v6, 0); /*0x14ac28*/
        return 268451850; /*0x14ac2f*/
      }
      ipc_pset_remove(v7, v6); /*0x14ac36*/
      v9 = *(_DWORD *)(v7 + 4); /*0x14ac3e*/
      _InterlockedExchange((volatile __int32 *)v7, 0); /*0x14ac43*/
      if ( !v9 ) /*0x14ac47*/
        zfree(ipc_object_zones[*(_WORD *)(v7 + 10) & 0x7FFF], v7); /*0x14ac5b*/
    }
    v10 = (volatile __int32 *)(v6 + 64); /*0x14ac60*/
    goto LABEL_22; /*0x14ac63*/
  }
  if ( (*v5 & 0x80000) == 0 ) /*0x14ac6e*/
  {
LABEL_21:
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14ac96*/
    return 268451842; /*0x14ac9e*/
  }
  do /*0x14ac86*/
  {
    while ( *(_DWORD *)v6 ) /*0x14ac74*/
      ; /*0x14ac76*/
  }
  while ( _InterlockedExchange((volatile __int32 *)v6, 1) == 1 ); /*0x14ac86*/
  _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14ac8a*/
  v10 = (volatile __int32 *)(v6 + 16); /*0x14ac8d*/
LABEL_22:
  ++*(_DWORD *)(v6 + 4); /*0x14aca0*/
  do /*0x14acb8*/
  {
    while ( *v10 ) /*0x14aca4*/
      ; /*0x14aca8*/
  }
  while ( _InterlockedExchange(v10, 1) == 1 ); /*0x14acb8*/
  _InterlockedExchange((volatile __int32 *)v6, 0); /*0x14acbc*/
  *a4 = v6; /*0x14acc1*/
  *a3 = v10; /*0x14acc6*/
  return 0; /*0x14accd*/
}
