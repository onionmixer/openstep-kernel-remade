/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x174ed0. */
int **__cdecl _vm_map_clip_end(int a1, int a2, int a3)
{
  int v3; // eax
  int v4; // edx
  int **result; // eax
  int v6; // edx
  volatile __int32 *v7; // ecx
  int *v8; // [esp+10h] [ebp-4h]

  if ( *(_DWORD *)(a1 + 20) ) /*0x174edf*/
    v3 = vm_map_entry_zone; /*0x174ee5*/
  else
    v3 = vm_map_kentry_zone; /*0x174eec*/
  v8 = (int *)zalloc(v3); /*0x174ef7*/
  if ( !v8 ) /*0x174eff*/
    panic(aVmMapEntryCrea); /*0x174f06*/
  qmemcpy(v8, (const void *)a2, 0x2Cu); /*0x174f23*/
  *(_DWORD *)(a2 + 12) = a3; /*0x174f28*/
  v8[2] = a3; /*0x174f2e*/
  v8[5] += a3 - *(_DWORD *)(a2 + 8); /*0x174f37*/
  ++*(_DWORD *)(a1 + 16); /*0x174f3d*/
  *v8 = a2; /*0x174f40*/
  v8[1] = *(_DWORD *)(a2 + 4); /*0x174f45*/
  v4 = *v8; /*0x174f48*/
  result = (int **)v8[1]; /*0x174f4a*/
  *result = v8; /*0x174f4d*/
  *(_DWORD *)(v4 + 4) = v8; /*0x174f4f*/
  if ( (*(_BYTE *)(a2 + 24) & 5) == 0 ) /*0x174f56*/
    return (int **)vm_object_reference(v8[4]); /*0x174f8b*/
  v6 = v8[4]; /*0x174f58*/
  if ( v6 ) /*0x174f5d*/
  {
    v7 = (volatile __int32 *)(v6 + 52); /*0x174f5f*/
    do /*0x174f76*/
    {
      while ( *v7 ) /*0x174f64*/
        ; /*0x174f66*/
    }
    while ( _InterlockedExchange(v7, 1) == 1 ); /*0x174f76*/
    ++*(_DWORD *)(v6 + 48); /*0x174f78*/
    return (int **)_InterlockedExchange((volatile __int32 *)(v6 + 52), 0); /*0x174f7d*/
  }
  return result; /*0x174f93*/
}
