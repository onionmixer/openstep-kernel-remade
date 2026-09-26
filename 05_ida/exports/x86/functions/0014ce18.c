/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14ce18. */
int __cdecl ipc_port_check_circularity(int a1, int a2)
{
  int v2; // ecx
  int v3; // ebx
  int v4; // esi
  int v5; // eax
  int v7; // eax

  v2 = a1; /*0x14ce1d*/
  v3 = a2; /*0x14ce20*/
  if ( a1 == a2 ) /*0x14ce25*/
    return 1; /*0x14cee2*/
  v4 = a2; /*0x14ce2b*/
  do /*0x14ce42*/
  {
    while ( *(_DWORD *)a1 ) /*0x14ce30*/
      ; /*0x14ce32*/
  }
  while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x14ce42*/
  if ( _InterlockedExchange((volatile __int32 *)a2, 1) != 1 ) /*0x14ce4b*/
  {
    if ( *(int *)(a2 + 8) >= 0 || *(_DWORD *)(a2 + 16) || !*(_DWORD *)(a2 + 12) ) /*0x14ce66*/
      goto LABEL_26; /*0x14ce6a*/
    _InterlockedExchange((volatile __int32 *)a2, 0); /*0x14ce72*/
  }
  _InterlockedExchange((volatile __int32 *)a1, 0); /*0x14ce76*/
  do /*0x14ce91*/
  {
    while ( ipc_port_multiple_lock_data ) /*0x14ce7f*/
      ; /*0x14ce7d*/
  }
  while ( _InterlockedExchange(&ipc_port_multiple_lock_data, 1) == 1 ); /*0x14ce91*/
  while ( 1 ) /*0x14cea6*/
  {
    do /*0x14cea6*/
    {
      while ( *(_DWORD *)v4 ) /*0x14ce94*/
        ; /*0x14ce96*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v4, 1) == 1 ); /*0x14cea6*/
    if ( *(int *)(v4 + 8) >= 0 || *(_DWORD *)(v4 + 16) || !*(_DWORD *)(v4 + 12) ) /*0x14ceb4*/
      break; /*0x14ceb4*/
    v4 = *(_DWORD *)(v4 + 12); /*0x14cebb*/
  }
  if ( a1 == v4 ) /*0x14cec2*/
  {
    _InterlockedExchange(&ipc_port_multiple_lock_data, 0); /*0x14cec6*/
    if ( a2 ) /*0x14cece*/
    {
      do /*0x14cedb*/
      {
        v5 = *(_DWORD *)(v3 + 12); /*0x14ced0*/
        _InterlockedExchange((volatile __int32 *)v3, 0); /*0x14ced5*/
        v3 = v5; /*0x14ced7*/
      }
      while ( v5 ); /*0x14cedb*/
    }
    return 1; /*0x14cedb*/
  }
  do /*0x14cef6*/
  {
    while ( *(_DWORD *)a1 ) /*0x14cee4*/
      ; /*0x14cee6*/
  }
  while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x14cef6*/
  _InterlockedExchange(&ipc_port_multiple_lock_data, 0); /*0x14cefa*/
LABEL_26:
  ++*(_DWORD *)(a2 + 4); /*0x14cf00*/
  *(_DWORD *)(a1 + 12) = a2; /*0x14cf03*/
  if ( a1 != v4 ) /*0x14cf08*/
  {
    do /*0x14cf17*/
    {
      v7 = *(_DWORD *)(v2 + 12); /*0x14cf0c*/
      _InterlockedExchange((volatile __int32 *)v2, 0); /*0x14cf11*/
      v2 = v7; /*0x14cf13*/
    }
    while ( v7 != v4 ); /*0x14cf17*/
  }
  _InterlockedExchange((volatile __int32 *)v4, 0); /*0x14cf1b*/
  return 0; /*0x14cf22*/
}
