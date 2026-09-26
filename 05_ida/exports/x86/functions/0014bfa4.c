/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14bfa4. */
int __cdecl ipc_object_copyout_dest(int a1, int a2, int a3, _DWORD *a4)
{
  int v4; // esi
  int v5; // eax
  int v6; // edx
  int v7; // eax
  int result; // eax
  int v9; // [esp+Ch] [ebp-4h]

  v4 = 0; /*0x14bfb3*/
  v5 = *(_DWORD *)(a2 + 4); /*0x14bfb5*/
  *(_DWORD *)(a2 + 4) = v5 - 1; /*0x14bfbb*/
  if ( a3 == 17 ) /*0x14bfc1*/
  {
    v6 = 0; /*0x14bfce*/
    v9 = 0; /*0x14bfd0*/
    v7 = *(_DWORD *)(a2 + 28); /*0x14bfd7*/
    *(_DWORD *)(a2 + 28) = v7 - 1; /*0x14bfdd*/
    if ( v7 == 1 ) /*0x14bfe3*/
    {
      v6 = *(_DWORD *)(a2 + 36); /*0x14bfe5*/
      if ( v6 ) /*0x14bfea*/
      {
        *(_DWORD *)(a2 + 36) = 0; /*0x14bfec*/
        v9 = *(_DWORD *)(a2 + 24); /*0x14bff6*/
      }
    }
    v4 = 0; /*0x14bff9*/
    if ( *(_DWORD *)(a2 + 12) == a1 ) /*0x14c001*/
      v4 = *(_DWORD *)(a2 + 16); /*0x14c003*/
    result = _InterlockedExchange((volatile __int32 *)a2, 0); /*0x14c008*/
    if ( v6 ) /*0x14c00c*/
      result = ipc_notify_no_senders(v6, v9); /*0x14c013*/
  }
  else
  {
    if ( a3 != 18 ) /*0x14bfc6*/
      panic(aIpcObjectCopyo); /*0x14c049*/
    if ( *(_DWORD *)(a2 + 12) == a1 ) /*0x14c024*/
    {
      --*(_DWORD *)(a2 + 32); /*0x14c026*/
      v4 = *(_DWORD *)(a2 + 16); /*0x14c029*/
      result = _InterlockedExchange((volatile __int32 *)a2, 0); /*0x14c02e*/
    }
    else
    {
      *(_DWORD *)(a2 + 4) = v5; /*0x14c034*/
      _InterlockedExchange((volatile __int32 *)a2, 0); /*0x14c039*/
      result = ipc_notify_send_once(a2); /*0x14c03c*/
    }
  }
  *a4 = v4; /*0x14c051*/
  return result; /*0x14c056*/
}
