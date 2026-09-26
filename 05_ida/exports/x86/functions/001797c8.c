/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1797c8. */
__int32 vm_object_cache_clear()
{
  int v0; // esi
  int v1; // ebx
  int *v2; // edx
  int *v3; // eax
  int v4; // ecx
  volatile __int32 *v5; // edx
  int *v6; // edx
  int *v7; // eax
  int v8; // eax

  do /*0x1797e9*/
  {
    while ( vm_cache_lock ) /*0x1797d7*/
      ; /*0x1797d5*/
  }
  while ( _InterlockedExchange(&vm_cache_lock, 1) == 1 ); /*0x1797e9*/
  while ( (int *)vm_object_cached_list != &vm_object_cached_list ) /*0x1797f5*/
  {
    v0 = vm_object_cached_list; /*0x1797fc*/
    _InterlockedExchange(&vm_cache_lock, 0); /*0x179804*/
    v1 = *(_DWORD *)(vm_object_cached_list + 40); /*0x17980a*/
    v2 = &vm_object_hashtable[2 * (v1 & 0x7F)]; /*0x179812*/
    do /*0x179835*/
    {
      while ( vm_cache_lock ) /*0x179823*/
        ; /*0x179821*/
    }
    while ( _InterlockedExchange(&vm_cache_lock, 1) == 1 ); /*0x179835*/
    v3 = (int *)*v2; /*0x179837*/
    if ( v2 == (int *)*v2 ) /*0x17983b*/
    {
LABEL_22:
      _InterlockedExchange(&vm_cache_lock, 0); /*0x1798b2*/
      v8 = 0; /*0x1798ba*/
    }
    else
    {
      while ( 1 ) /*0x179840*/
      {
        v4 = v3[2]; /*0x179840*/
        if ( *(_DWORD *)(v4 + 40) == v1 ) /*0x179846*/
          break; /*0x179846*/
        v3 = (int *)*v3; /*0x1798ac*/
        if ( v2 == v3 ) /*0x1798b0*/
          goto LABEL_22; /*0x1798b0*/
      }
      v5 = (volatile __int32 *)(v4 + 16); /*0x179848*/
      do /*0x17985e*/
      {
        while ( *v5 ) /*0x17984c*/
          ; /*0x17984e*/
      }
      while ( _InterlockedExchange(v5, 1) == 1 ); /*0x17985e*/
      if ( !*(_WORD *)(v4 + 24) ) /*0x179860*/
      {
        v6 = *(int **)(v4 + 76); /*0x179867*/
        v7 = *(int **)(v4 + 80); /*0x17986a*/
        if ( v6 == &vm_object_cached_list ) /*0x179873*/
          dword_1F6F3C = *(_DWORD *)(v4 + 80); /*0x179875*/
        else
          v6[20] = (int)v7; /*0x17987c*/
        if ( v7 == &vm_object_cached_list ) /*0x179884*/
          vm_object_cached_list = (int)v6; /*0x1798a4*/
        else
          v7[19] = (int)v6; /*0x179886*/
        --vm_object_cached; /*0x179889*/
      }
      ++*(_WORD *)(v4 + 24); /*0x17988f*/
      _InterlockedExchange((volatile __int32 *)(v4 + 16), 0); /*0x179895*/
      _InterlockedExchange(&vm_cache_lock, 0); /*0x17989a*/
      v8 = v4; /*0x1798a0*/
    }
    if ( v0 != v8 ) /*0x1798be*/
      panic(aVmObjectCacheC); /*0x1798c5*/
    vm_object_cache_object(v0, 0); /*0x1798d0*/
    do /*0x1798f1*/
    {
      while ( vm_cache_lock ) /*0x1798df*/
        ; /*0x1798dd*/
    }
    while ( _InterlockedExchange(&vm_cache_lock, 1) == 1 ); /*0x1798f1*/
  }
  return _InterlockedExchange(&vm_cache_lock, 0); /*0x17990e*/
}
