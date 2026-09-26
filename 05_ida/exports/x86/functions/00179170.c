/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x179170. */
int __cdecl vm_object_cache_object(int a1, char a2)
{
  volatile __int32 *v3; // edx
  int v4; // esi
  volatile __int32 *v5; // edx
  __int16 v6; // ax
  char v7; // al
  int v8; // eax
  int v9; // ebx

  if ( !a1 ) /*0x17917b*/
    return 4; /*0x179182*/
  do /*0x1791b5*/
  {
    while ( vm_cache_lock ) /*0x1791a3*/
      ; /*0x1791a1*/
  }
  while ( _InterlockedExchange(&vm_cache_lock, 1) == 1 ); /*0x1791b5*/
  v3 = (volatile __int32 *)(a1 + 16); /*0x1791b7*/
  do /*0x1791ce*/
  {
    while ( *v3 ) /*0x1791bc*/
      ; /*0x1791be*/
  }
  while ( _InterlockedExchange(v3, 1) == 1 ); /*0x1791ce*/
  *(_BYTE *)(a1 + 70) = (8 * (a2 & 1)) | *(_BYTE *)(a1 + 70) & 0xF7; /*0x1791e0*/
  _InterlockedExchange((volatile __int32 *)(a1 + 16), 0); /*0x1791e5*/
  _InterlockedExchange(&vm_cache_lock, 0); /*0x1791ea*/
  v4 = a1; /*0x1791f0*/
  while ( 1 ) /*0x179215*/
  {
    do /*0x179215*/
    {
      while ( vm_cache_lock ) /*0x179203*/
        ; /*0x179201*/
    }
    while ( _InterlockedExchange(&vm_cache_lock, 1) == 1 ); /*0x179215*/
    v5 = (volatile __int32 *)(v4 + 16); /*0x179217*/
    do /*0x17922e*/
    {
      while ( *v5 ) /*0x17921c*/
        ; /*0x17921e*/
    }
    while ( _InterlockedExchange(v5, 1) == 1 ); /*0x17922e*/
    v6 = *(_WORD *)(v4 + 24); /*0x179230*/
    *(_WORD *)(v4 + 24) = v6 - 1; /*0x179238*/
    if ( v6 != 1 ) /*0x179240*/
    {
      _InterlockedExchange((volatile __int32 *)(v4 + 16), 0); /*0x17918a*/
      _InterlockedExchange(&vm_cache_lock, 0); /*0x17918f*/
      return 0; /*0x179195*/
    }
    v7 = *(_BYTE *)(v4 + 70); /*0x179246*/
    if ( (v7 & 8) != 0 ) /*0x17924b*/
      break; /*0x17924b*/
LABEL_23:
    vm_object_remove(*(_DWORD *)(v4 + 40)); /*0x1792a5*/
    _InterlockedExchange(&vm_cache_lock, 0); /*0x1792b3*/
    v9 = *(_DWORD *)(v4 + 32); /*0x1792b9*/
    vm_object_terminate(v4); /*0x1792bd*/
    v4 = v9; /*0x1792c2*/
    if ( !v9 ) /*0x1792c9*/
      return 0; /*0x1792c9*/
  }
  if ( *(__int16 *)(v4 + 26) <= 0 ) /*0x179252*/
  {
    *(_BYTE *)(v4 + 70) = v7 & 0xF7; /*0x1792a2*/
    goto LABEL_23; /*0x1792a2*/
  }
  v8 = dword_1F6F3C; /*0x179254*/
  if ( (int *)dword_1F6F3C == &vm_object_cached_list ) /*0x17925e*/
    vm_object_cached_list = v4; /*0x179260*/
  else
    *(_DWORD *)(dword_1F6F3C + 76) = v4; /*0x179268*/
  *(_DWORD *)(v4 + 80) = v8; /*0x17926b*/
  *(_DWORD *)(v4 + 76) = &vm_object_cached_list; /*0x17926e*/
  dword_1F6F3C = v4; /*0x179275*/
  ++vm_object_cached; /*0x17927b*/
  _InterlockedExchange(&vm_cache_lock, 0); /*0x179283*/
  vm_object_deactivate_pages(v4); /*0x17928a*/
  _InterlockedExchange((volatile __int32 *)(v4 + 16), 0); /*0x179294*/
  vm_object_cache_trim(); /*0x179297*/
  return 0; /*0x1792d4*/
}
