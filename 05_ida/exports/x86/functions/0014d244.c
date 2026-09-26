/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14d244. */
int __cdecl ipc_port_dealloc_special(int a1)
{
  int v1; // ebx
  int v2; // eax
  volatile __int32 *v3; // edx
  volatile __int32 *v4; // edx

  do /*0x14d25e*/
  {
    while ( *(_DWORD *)a1 ) /*0x14d24c*/
      ; /*0x14d24e*/
  }
  while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x14d25e*/
  *(_DWORD *)(a1 + 16) = 0; /*0x14d260*/
  *(_DWORD *)(a1 + 12) = 0; /*0x14d267*/
  v1 = *(_DWORD *)(a1 + 48); /*0x14d26e*/
  if ( v1 ) /*0x14d273*/
  {
    do /*0x14d28a*/
    {
      while ( *(_DWORD *)v1 ) /*0x14d278*/
        ; /*0x14d27a*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v1, 1) == 1 ); /*0x14d28a*/
    ipc_pset_remove(v1, a1); /*0x14d28e*/
    v2 = *(_DWORD *)(v1 + 4); /*0x14d296*/
    _InterlockedExchange((volatile __int32 *)v1, 0); /*0x14d29b*/
    if ( !v2 ) /*0x14d29f*/
      zfree(ipc_object_zones[*(_WORD *)(v1 + 10) & 0x7FFF], v1); /*0x14d2b3*/
  }
  else
  {
    v3 = (volatile __int32 *)(a1 + 64); /*0x14d2c0*/
    do /*0x14d2d6*/
    {
      while ( *v3 ) /*0x14d2c4*/
        ; /*0x14d2c6*/
    }
    while ( _InterlockedExchange(v3, 1) == 1 ); /*0x14d2d6*/
    ipc_mqueue_changed(a1 + 64, 268451849); /*0x14d2e1*/
    _InterlockedExchange((volatile __int32 *)(a1 + 64), 0); /*0x14d2eb*/
  }
  *(_DWORD *)(a1 + 24) = 0; /*0x14d2ee*/
  v4 = (volatile __int32 *)(a1 + 64); /*0x14d2f5*/
  do /*0x14d30a*/
  {
    while ( *v4 ) /*0x14d2f8*/
      ; /*0x14d2fa*/
  }
  while ( _InterlockedExchange(v4, 1) == 1 ); /*0x14d30a*/
  *(_DWORD *)(a1 + 52) = 0; /*0x14d30c*/
  _InterlockedExchange((volatile __int32 *)(a1 + 64), 0); /*0x14d315*/
  return ipc_port_destroy(a1); /*0x14d321*/
}
