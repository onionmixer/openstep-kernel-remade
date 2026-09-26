/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14d050. */
int __cdecl ipc_port_release_send(int a1)
{
  int v1; // edx
  int v2; // ebx
  int v3; // eax
  int result; // eax
  int v5; // eax

  v1 = 0; /*0x14d058*/
  v2 = 0; /*0x14d05a*/
  do /*0x14d06e*/
  {
    while ( *(_DWORD *)a1 ) /*0x14d05c*/
      ; /*0x14d05e*/
  }
  while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x14d06e*/
  v3 = *(_DWORD *)(a1 + 4); /*0x14d070*/
  *(_DWORD *)(a1 + 4) = v3 - 1; /*0x14d076*/
  if ( *(int *)(a1 + 8) < 0 ) /*0x14d07d*/
  {
    v5 = *(_DWORD *)(a1 + 28); /*0x14d0a4*/
    *(_DWORD *)(a1 + 28) = v5 - 1; /*0x14d0aa*/
    if ( v5 == 1 ) /*0x14d0b0*/
    {
      v1 = *(_DWORD *)(a1 + 36); /*0x14d0b2*/
      if ( v1 ) /*0x14d0b7*/
      {
        *(_DWORD *)(a1 + 36) = 0; /*0x14d0b9*/
        v2 = *(_DWORD *)(a1 + 24); /*0x14d0c0*/
      }
    }
    result = _InterlockedExchange((volatile __int32 *)a1, 0); /*0x14d0c5*/
    if ( v1 ) /*0x14d0c9*/
      return ipc_notify_no_senders(v1, v2); /*0x14d0cd*/
  }
  else
  {
    result = v3 - 1; /*0x14d07f*/
    _InterlockedExchange((volatile __int32 *)a1, 0); /*0x14d082*/
    if ( !result ) /*0x14d086*/
      return zfree(ipc_object_zones[*(_WORD *)(a1 + 10) & 0x7FFF], a1); /*0x14d09a*/
  }
  return result; /*0x14d0d5*/
}
