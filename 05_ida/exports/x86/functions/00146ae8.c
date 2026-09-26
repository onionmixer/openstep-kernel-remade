/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x146ae8. */
__int32 __cdecl ipc_hash_global_delete(unsigned int a1, unsigned int a2, int a3, int a4)
{
  int v4; // edx
  _DWORD *v5; // ecx
  int v6; // eax

  --*(_DWORD *)(a1 + 64); /*0x146af5*/
  v4 = ipc_hash_global_table + 8 * (ipc_hash_global_mask & ((a2 >> 6) + (a1 >> 4))); /*0x146b0c*/
  do /*0x146b22*/
  {
    while ( *(_DWORD *)v4 ) /*0x146b10*/
      ; /*0x146b12*/
  }
  while ( _InterlockedExchange((volatile __int32 *)v4, 1) == 1 ); /*0x146b22*/
  v5 = (_DWORD *)(v4 + 4); /*0x146b24*/
  v6 = *(_DWORD *)(v4 + 4); /*0x146b27*/
  if ( v6 ) /*0x146b2c*/
  {
    while ( v6 != a4 ) /*0x146b32*/
    {
      v5 = (_DWORD *)(v6 + 12); /*0x146b3c*/
      v6 = *(_DWORD *)(v6 + 12); /*0x146b3f*/
      if ( !v6 ) /*0x146b44*/
        return _InterlockedExchange((volatile __int32 *)v4, 0); /*0x146b44*/
    }
    *v5 = *(_DWORD *)(v6 + 12); /*0x146b37*/
  }
  return _InterlockedExchange((volatile __int32 *)v4, 0); /*0x146b4a*/
}
