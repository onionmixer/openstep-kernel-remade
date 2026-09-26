/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14d4e4. */
int __cdecl ipc_port_copyout_send_compat(int a1, int a2)
{
  int v2; // edx
  int v3; // ecx
  int v4; // eax
  int v5; // eax
  int v7; // [esp+8h] [ebp-4h] BYREF

  if ( !a1 || a1 == -1 ) /*0x14d4fa*/
    return a1; /*0x14d5a0*/
  if ( ipc_object_copyout_compat(a2, a1, 17, &v7) ) /*0x14d50b*/
  {
    v2 = 0; /*0x14d51b*/
    v3 = 0; /*0x14d51d*/
    do /*0x14d532*/
    {
      while ( *(_DWORD *)a1 ) /*0x14d520*/
        ; /*0x14d522*/
    }
    while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x14d532*/
    v4 = *(_DWORD *)(a1 + 4); /*0x14d534*/
    *(_DWORD *)(a1 + 4) = v4 - 1; /*0x14d53a*/
    if ( *(int *)(a1 + 8) < 0 ) /*0x14d541*/
    {
      v5 = *(_DWORD *)(a1 + 28); /*0x14d568*/
      *(_DWORD *)(a1 + 28) = v5 - 1; /*0x14d56e*/
      if ( v5 == 1 ) /*0x14d574*/
      {
        v2 = *(_DWORD *)(a1 + 36); /*0x14d576*/
        if ( v2 ) /*0x14d57b*/
        {
          *(_DWORD *)(a1 + 36) = 0; /*0x14d57d*/
          v3 = *(_DWORD *)(a1 + 24); /*0x14d584*/
        }
      }
      _InterlockedExchange((volatile __int32 *)a1, 0); /*0x14d589*/
      if ( v2 ) /*0x14d58d*/
        ipc_notify_no_senders(v2, v3); /*0x14d591*/
    }
    else
    {
      _InterlockedExchange((volatile __int32 *)a1, 0); /*0x14d546*/
      if ( v4 == 1 ) /*0x14d54a*/
        zfree(ipc_object_zones[*(_WORD *)(a1 + 10) & 0x7FFF], a1); /*0x14d55e*/
    }
    return 0; /*0x14d596*/
  }
  return v7; /*0x14d5a9*/
}
