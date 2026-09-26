/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x174e00. */
int **__cdecl _vm_map_clip_start(int a1, int a2, int a3)
{
  int v3; // eax
  int v4; // edx
  int **result; // eax
  int v6; // edx
  volatile __int32 *v7; // ecx
  int *v8; // [esp+10h] [ebp-4h]

  if ( *(_DWORD *)(a1 + 20) ) /*0x174e0f*/
    v3 = vm_map_entry_zone; /*0x174e15*/
  else
    v3 = vm_map_kentry_zone; /*0x174e1c*/
  v8 = (int *)zalloc(v3); /*0x174e27*/
  if ( !v8 ) /*0x174e2f*/
    panic(aVmMapEntryCrea); /*0x174e36*/
  qmemcpy(v8, (const void *)a2, 0x2Cu); /*0x174e53*/
  v8[3] = a3; /*0x174e58*/
  *(_DWORD *)(a2 + 20) += a3 - *(_DWORD *)(a2 + 8); /*0x174e61*/
  *(_DWORD *)(a2 + 8) = a3; /*0x174e64*/
  ++*(_DWORD *)(a1 + 16); /*0x174e6a*/
  *v8 = *(_DWORD *)a2; /*0x174e72*/
  v8[1] = *(_DWORD *)(*(_DWORD *)a2 + 4); /*0x174e79*/
  v4 = *v8; /*0x174e7c*/
  result = (int **)v8[1]; /*0x174e7e*/
  *result = v8; /*0x174e81*/
  *(_DWORD *)(v4 + 4) = v8; /*0x174e83*/
  if ( (*(_BYTE *)(a2 + 24) & 5) == 0 ) /*0x174e8a*/
    return (int **)vm_object_reference(v8[4]); /*0x174ebf*/
  v6 = v8[4]; /*0x174e8c*/
  if ( v6 ) /*0x174e91*/
  {
    v7 = (volatile __int32 *)(v6 + 52); /*0x174e93*/
    do /*0x174eaa*/
    {
      while ( *v7 ) /*0x174e98*/
        ; /*0x174e9a*/
    }
    while ( _InterlockedExchange(v7, 1) == 1 ); /*0x174eaa*/
    ++*(_DWORD *)(v6 + 48); /*0x174eac*/
    return (int **)_InterlockedExchange((volatile __int32 *)(v6 + 52), 0); /*0x174eb1*/
  }
  return result; /*0x174ec7*/
}
