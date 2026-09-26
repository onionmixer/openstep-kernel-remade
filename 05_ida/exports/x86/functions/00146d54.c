/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x146d54. */
int __cdecl ipc_hash_info(int a1, unsigned int a2)
{
  unsigned int v2; // esi
  unsigned int v3; // ebx
  int v4; // edx
  int v5; // ecx
  int i; // eax

  v2 = a2; /*0x146d5d*/
  if ( ipc_hash_global_size < a2 ) /*0x146d67*/
    v2 = ipc_hash_global_size; /*0x146d69*/
  v3 = 0; /*0x146d6b*/
  if ( v2 ) /*0x146d6f*/
  {
    v4 = ipc_hash_global_table; /*0x146d71*/
    do /*0x146dad*/
    {
      v5 = 0; /*0x146d78*/
      do /*0x146d8e*/
      {
        while ( *(_DWORD *)v4 ) /*0x146d7c*/
          ; /*0x146d7e*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v4, 1) == 1 ); /*0x146d8e*/
      for ( i = *(_DWORD *)(v4 + 4); i; i = *(_DWORD *)(i + 12) ) /*0x146d95*/
        ++v5; /*0x146d98*/
      _InterlockedExchange((volatile __int32 *)v4, 0); /*0x146da2*/
      *(_DWORD *)(a1 + 4 * v3) = v5; /*0x146da4*/
      v4 += 8; /*0x146da7*/
      ++v3; /*0x146daa*/
    }
    while ( v3 < v2 ); /*0x146dad*/
  }
  return ipc_hash_global_size; /*0x146db7*/
}
