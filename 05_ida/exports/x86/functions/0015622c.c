/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15622c. */
int __cdecl port_status(int a1, int a2, _DWORD *a3, _DWORD *a4, _DWORD *a5, _DWORD *a6, _DWORD *a7)
{
  int v8; // edi
  int v9; // ebx
  int v10; // esi
  int v11; // eax
  int v12; // eax
  int v13; // edx
  _BYTE v14[4]; // [esp+10h] [ebp-Ch] BYREF
  int v15; // [esp+14h] [ebp-8h] BYREF
  int v16; // [esp+18h] [ebp-4h] BYREF

  if ( !a1 || ipc_right_lookup_write(a1, a2, &v16) || ipc_right_info(a1, a2, v16, &v15, v14) ) /*0x15625f*/
    return 4; /*0x156269*/
  if ( (v15 & 0x170000) == 0 ) /*0x156273*/
  {
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x156277*/
    return 4; /*0x15627f*/
  }
  if ( (v15 & 0x20000) == 0 ) /*0x156289*/
  {
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x15633e*/
    *a6 = 0; /*0x156344*/
    *a7 = 0; /*0x15634d*/
    *a3 = 0; /*0x156356*/
    *a4 = -1; /*0x15635f*/
    *a5 = 0; /*0x156368*/
    return 0; /*0x156368*/
  }
  v8 = *(_DWORD *)(v16 + 4); /*0x156292*/
  do /*0x1562aa*/
  {
    while ( *(_DWORD *)v8 ) /*0x156298*/
      ; /*0x15629a*/
  }
  while ( _InterlockedExchange((volatile __int32 *)v8, 1) == 1 ); /*0x1562aa*/
  _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x1562ae*/
  if ( !*(_DWORD *)(v8 + 48) ) /*0x1562b6*/
    goto LABEL_19; /*0x1562b6*/
  v9 = *(_DWORD *)(v8 + 48); /*0x1562b8*/
  do /*0x1562ce*/
  {
    while ( *(_DWORD *)v9 ) /*0x1562bc*/
      ; /*0x1562be*/
  }
  while ( _InterlockedExchange((volatile __int32 *)v9, 1) == 1 ); /*0x1562ce*/
  if ( *(int *)(v9 + 8) >= 0 ) /*0x1562d4*/
  {
    ipc_pset_remove(v9, v8); /*0x1562e2*/
    v11 = *(_DWORD *)(v9 + 4); /*0x1562ea*/
    _InterlockedExchange((volatile __int32 *)v9, 0); /*0x1562ef*/
    if ( !v11 ) /*0x1562f3*/
      zfree(ipc_object_zones[*(_WORD *)(v9 + 10) & 0x7FFF], v9); /*0x156307*/
LABEL_19:
    v10 = 0; /*0x15630c*/
    goto LABEL_20; /*0x15630c*/
  }
  v10 = *(_DWORD *)(v9 + 12); /*0x1562d6*/
  _InterlockedExchange((volatile __int32 *)v9, 0); /*0x1562db*/
LABEL_20:
  v12 = *(_DWORD *)(v8 + 60); /*0x15630e*/
  v13 = *(_DWORD *)(v8 + 56); /*0x156311*/
  _InterlockedExchange((volatile __int32 *)v8, 0); /*0x156316*/
  *a6 = 1; /*0x15631b*/
  *a7 = 1; /*0x156324*/
  *a3 = v10; /*0x15632d*/
  *a4 = v13; /*0x156332*/
  *a5 = v12; /*0x156337*/
  return 0; /*0x156373*/
}
