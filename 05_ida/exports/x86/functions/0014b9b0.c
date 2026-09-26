/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14b9b0. */
int __cdecl ipc_object_alloc(int a1, int a2, int a3, int a4, _DWORD *a5, int *a6)
{
  int v6; // ebx
  int v8; // esi
  int *v9; // eax
  int *v10; // [esp+Ch] [ebp-4h] BYREF

  v6 = zalloc(ipc_object_zones[a2]); /*0x14b9c9*/
  if ( !v6 ) /*0x14b9d0*/
    return 6; /*0x14b9d2*/
  v8 = ipc_entry_alloc(a1, a5, &v10); /*0x14b9ed*/
  if ( v8 ) /*0x14b9f4*/
  {
    zfree(ipc_object_zones[a2], v6); /*0x14b9ff*/
    return v8; /*0x14ba04*/
  }
  else
  {
    v9 = v10; /*0x14ba08*/
    *v10 |= a4 | a3; /*0x14ba11*/
    v9[1] = v6; /*0x14ba13*/
    *(_DWORD *)v6 = 0; /*0x14ba16*/
    do /*0x14ba2e*/
    {
      while ( *(_DWORD *)v6 ) /*0x14ba1c*/
        ; /*0x14ba1e*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v6, 1) == 1 ); /*0x14ba2e*/
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14ba35*/
    *(_DWORD *)(v6 + 4) = 1; /*0x14ba38*/
    *(_DWORD *)(v6 + 8) = (a2 << 16) | 0x80000000; /*0x14ba49*/
    *a6 = v6; /*0x14ba4f*/
    return 0; /*0x14ba51*/
  }
}
