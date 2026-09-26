/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x178f7c. */
int __cdecl vm_object_destroy(int a1)
{
  int result; // eax
  int v2; // esi
  volatile __int32 *v3; // edx
  __int16 v4; // ax
  char v5; // al
  int v6; // eax
  int v7; // ebx

  result = vm_object_lookup(a1); /*0x178f85*/
  if ( !result ) /*0x178f8f*/
    return result; /*0x178f8f*/
  v2 = result; /*0x178f95*/
  while ( 1 ) /*0x178fb1*/
  {
    do /*0x178fb1*/
    {
      while ( vm_cache_lock ) /*0x178f9f*/
        ; /*0x178f9d*/
    }
    while ( _InterlockedExchange(&vm_cache_lock, 1) == 1 ); /*0x178fb1*/
    v3 = (volatile __int32 *)(v2 + 16); /*0x178fb3*/
    do /*0x178fca*/
    {
      while ( *v3 ) /*0x178fb8*/
        ; /*0x178fba*/
    }
    while ( _InterlockedExchange(v3, 1) == 1 ); /*0x178fca*/
    v4 = *(_WORD *)(v2 + 24); /*0x178fcc*/
    *(_WORD *)(v2 + 24) = v4 - 1; /*0x178fd4*/
    if ( v4 != 1 ) /*0x178fdc*/
    {
      _InterlockedExchange((volatile __int32 *)(v2 + 16), 0); /*0x178fe0*/
      return _InterlockedExchange(&vm_cache_lock, 0); /*0x178feb*/
    }
    v5 = *(_BYTE *)(v2 + 70); /*0x178ff0*/
    if ( (v5 & 8) != 0 ) /*0x178ff5*/
      break; /*0x178ff5*/
LABEL_17:
    vm_object_remove(*(_DWORD *)(v2 + 40)); /*0x179051*/
    _InterlockedExchange(&vm_cache_lock, 0); /*0x17905f*/
    v7 = *(_DWORD *)(v2 + 32); /*0x179065*/
    result = vm_object_terminate((int *)v2); /*0x179069*/
    v2 = v7; /*0x17906e*/
    if ( !v7 ) /*0x179075*/
      return result; /*0x179075*/
  }
  if ( *(__int16 *)(v2 + 26) <= 0 ) /*0x178ffc*/
  {
    *(_BYTE *)(v2 + 70) = v5 & 0xF7; /*0x17904e*/
    goto LABEL_17; /*0x17904e*/
  }
  v6 = dword_1F6F3C; /*0x178ffe*/
  if ( (int *)dword_1F6F3C == &vm_object_cached_list ) /*0x179008*/
    vm_object_cached_list = v2; /*0x17900a*/
  else
    *(_DWORD *)(dword_1F6F3C + 76) = v2; /*0x179014*/
  *(_DWORD *)(v2 + 80) = v6; /*0x179017*/
  *(_DWORD *)(v2 + 76) = &vm_object_cached_list; /*0x17901a*/
  dword_1F6F3C = v2; /*0x179021*/
  ++vm_object_cached; /*0x179027*/
  _InterlockedExchange(&vm_cache_lock, 0); /*0x17902f*/
  vm_object_deactivate_pages((_DWORD *)v2); /*0x179036*/
  _InterlockedExchange((volatile __int32 *)(v2 + 16), 0); /*0x179040*/
  return vm_object_cache_trim(); /*0x17907e*/
}
