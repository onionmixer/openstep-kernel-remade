/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14ba60. */
int __cdecl ipc_object_alloc_name(unsigned int a1, int a2, int a3, int a4, unsigned int a5, int *a6)
{
  int v6; // ebx
  int v8; // esi
  unsigned int *v9; // eax
  unsigned int *v10; // [esp+Ch] [ebp-4h] BYREF

  v6 = zalloc(ipc_object_zones[a2]); /*0x14ba79*/
  if ( !v6 ) /*0x14ba80*/
    return 6; /*0x14ba82*/
  v8 = ipc_entry_alloc_name(a1, a5, &v10); /*0x14ba9d*/
  if ( v8 ) /*0x14baa4*/
  {
    zfree(ipc_object_zones[a2], v6); /*0x14baaf*/
    return v8; /*0x14bab4*/
  }
  else if ( ipc_right_inuse(a1, a5, v10) ) /*0x14bac4*/
  {
    zfree(ipc_object_zones[a2], v6); /*0x14bad9*/
    return 13; /*0x14bade*/
  }
  else
  {
    v9 = v10; /*0x14bae8*/
    *v10 |= a4 | a3; /*0x14baf1*/
    v9[1] = v6; /*0x14baf3*/
    *(_DWORD *)v6 = 0; /*0x14baf6*/
    do /*0x14bb0e*/
    {
      while ( *(_DWORD *)v6 ) /*0x14bafc*/
        ; /*0x14bafe*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v6, 1) == 1 ); /*0x14bb0e*/
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14bb15*/
    *(_DWORD *)(v6 + 4) = 1; /*0x14bb18*/
    *(_DWORD *)(v6 + 8) = (a2 << 16) | 0x80000000; /*0x14bb29*/
    *a6 = v6; /*0x14bb2f*/
    return 0; /*0x14bb31*/
  }
}
