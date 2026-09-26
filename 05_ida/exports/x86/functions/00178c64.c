/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x178c64. */
void __cdecl vm_object_deallocate(int a1)
{
  int v1; // esi
  volatile __int32 *v2; // edx
  __int16 v3; // ax
  char v4; // al
  int v5; // eax
  int v6; // ebx

  v1 = a1; /*0x178c69*/
  if ( !a1 ) /*0x178c6e*/
    return; /*0x178c6e*/
  while ( 1 ) /*0x178c8d*/
  {
    do /*0x178c8d*/
    {
      while ( vm_cache_lock ) /*0x178c7b*/
        ; /*0x178c79*/
    }
    while ( _InterlockedExchange(&vm_cache_lock, 1) == 1 ); /*0x178c8d*/
    v2 = (volatile __int32 *)(v1 + 16); /*0x178c8f*/
    do /*0x178ca6*/
    {
      while ( *v2 ) /*0x178c94*/
        ; /*0x178c96*/
    }
    while ( _InterlockedExchange(v2, 1) == 1 ); /*0x178ca6*/
    v3 = *(_WORD *)(v1 + 24); /*0x178ca8*/
    *(_WORD *)(v1 + 24) = v3 - 1; /*0x178cb0*/
    if ( v3 != 1 ) /*0x178cb8*/
    {
      _InterlockedExchange((volatile __int32 *)(v1 + 16), 0); /*0x178cbc*/
      _InterlockedExchange(&vm_cache_lock, 0); /*0x178cc1*/
      return; /*0x178cc7*/
    }
    v4 = *(_BYTE *)(v1 + 70); /*0x178ccc*/
    if ( (v4 & 8) != 0 ) /*0x178cd1*/
      break; /*0x178cd1*/
LABEL_16:
    vm_object_remove(*(_DWORD *)(v1 + 40)); /*0x178d2d*/
    _InterlockedExchange(&vm_cache_lock, 0); /*0x178d3b*/
    v6 = *(_DWORD *)(v1 + 32); /*0x178d41*/
    vm_object_terminate((int *)v1); /*0x178d45*/
    v1 = v6; /*0x178d4a*/
    if ( !v6 ) /*0x178d51*/
      return; /*0x178d51*/
  }
  if ( *(__int16 *)(v1 + 26) <= 0 ) /*0x178cd8*/
  {
    *(_BYTE *)(v1 + 70) = v4 & 0xF7; /*0x178d2a*/
    goto LABEL_16; /*0x178d2a*/
  }
  v5 = dword_1F6F3C; /*0x178cda*/
  if ( (int *)dword_1F6F3C == &vm_object_cached_list ) /*0x178ce4*/
    vm_object_cached_list = v1; /*0x178ce6*/
  else
    *(_DWORD *)(dword_1F6F3C + 76) = v1; /*0x178cf0*/
  *(_DWORD *)(v1 + 80) = v5; /*0x178cf3*/
  *(_DWORD *)(v1 + 76) = &vm_object_cached_list; /*0x178cf6*/
  dword_1F6F3C = v1; /*0x178cfd*/
  ++vm_object_cached; /*0x178d03*/
  _InterlockedExchange(&vm_cache_lock, 0); /*0x178d0b*/
  vm_object_deactivate_pages((_DWORD *)v1); /*0x178d12*/
  _InterlockedExchange((volatile __int32 *)(v1 + 16), 0); /*0x178d1c*/
  vm_object_cache_trim(); /*0x178d1f*/
}
