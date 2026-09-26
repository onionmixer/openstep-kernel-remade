/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14a5bc. */
int __cdecl ipc_marequest_info(_DWORD *a1, int a2, unsigned int a3)
{
  unsigned int v3; // ebx
  int v4; // edx
  int v5; // ecx
  int i; // eax

  if ( a3 > ipc_marequest_size ) /*0x14a5ca*/
    a3 = ipc_marequest_size; /*0x14a5cc*/
  v3 = 0; /*0x14a5cf*/
  if ( a3 ) /*0x14a5d4*/
  {
    v4 = ipc_marequest_table; /*0x14a5d6*/
    do /*0x14a615*/
    {
      v5 = 0; /*0x14a5dc*/
      do /*0x14a5f2*/
      {
        while ( *(_DWORD *)v4 ) /*0x14a5e0*/
          ; /*0x14a5e2*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v4, 1) == 1 ); /*0x14a5f2*/
      for ( i = *(_DWORD *)(v4 + 4); i; i = *(_DWORD *)(i + 12) ) /*0x14a5f9*/
        ++v5; /*0x14a5fc*/
      _InterlockedExchange((volatile __int32 *)v4, 0); /*0x14a606*/
      *(_DWORD *)(a2 + 4 * v3) = v5; /*0x14a60b*/
      v4 += 8; /*0x14a60e*/
      ++v3; /*0x14a611*/
    }
    while ( a3 > v3 ); /*0x14a615*/
  }
  *a1 = ipc_marequest_max; /*0x14a620*/
  return ipc_marequest_size; /*0x14a62a*/
}
