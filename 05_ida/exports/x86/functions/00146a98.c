/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x146a98. */
__int32 __cdecl ipc_hash_global_insert(unsigned int a1, unsigned int a2, int a3, int a4)
{
  int v4; // edx

  ++*(_DWORD *)(a1 + 64); /*0x146aa5*/
  v4 = ipc_hash_global_table + 8 * (ipc_hash_global_mask & ((a2 >> 6) + (a1 >> 4))); /*0x146abc*/
  do /*0x146ad2*/
  {
    while ( *(_DWORD *)v4 ) /*0x146ac0*/
      ; /*0x146ac2*/
  }
  while ( _InterlockedExchange((volatile __int32 *)v4, 1) == 1 ); /*0x146ad2*/
  *(_DWORD *)(a4 + 12) = *(_DWORD *)(v4 + 4); /*0x146ad7*/
  *(_DWORD *)(v4 + 4) = a4; /*0x146ada*/
  return _InterlockedExchange((volatile __int32 *)v4, 0); /*0x146ae1*/
}
