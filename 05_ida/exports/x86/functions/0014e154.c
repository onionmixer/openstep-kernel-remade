/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14e154. */
int __cdecl ipc_right_destroy(unsigned int a1, unsigned int a2, int a3)
{
  unsigned int v3; // esi
  volatile __int32 *v4; // ebx
  int v5; // ebx
  int v6; // ecx
  int v8; // eax
  int v9; // eax
  int v10; // [esp+Ch] [ebp-10h]
  int v11; // [esp+10h] [ebp-Ch]
  int v12; // [esp+14h] [ebp-8h]
  int v13; // [esp+18h] [ebp-4h]

  v13 = *(_DWORD *)a3; /*0x14e162*/
  v3 = *(_DWORD *)a3 & 0x1F0000; /*0x14e167*/
  if ( v3 != 196608 ) /*0x14e173*/
  {
    if ( (*(_DWORD *)a3 & 0x1F0000u) > 0x30000 ) /*0x14e179*/
    {
      if ( v3 == 0x80000 ) /*0x14e19e*/
      {
        v4 = *(volatile __int32 **)(a3 + 4); /*0x14e1d8*/
        *(_DWORD *)(a3 + 4) = 0; /*0x14e1db*/
        ipc_entry_dealloc((_DWORD *)a1, a2, (int *)a3); /*0x14e1eb*/
        do /*0x14e206*/
        {
          while ( *v4 ) /*0x14e1f4*/
            ; /*0x14e1f6*/
        }
        while ( _InterlockedExchange(v4, 1) == 1 ); /*0x14e206*/
        _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14e20d*/
        ipc_pset_destroy((int)v4); /*0x14e211*/
        return 0; /*0x14e216*/
      }
      if ( v3 > 0x80000 ) /*0x14e1a0*/
      {
        if ( (int *)v3 != &dword_100000 ) /*0x14e1b6*/
          goto LABEL_45; /*0x14e1b6*/
        ipc_entry_dealloc((_DWORD *)a1, a2, (int *)a3); /*0x14e1c5*/
        _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14e1cf*/
        return 0; /*0x14e1d2*/
      }
      if ( v3 != 0x40000 ) /*0x14e1a8*/
        goto LABEL_45; /*0x14e1a8*/
    }
    else if ( v3 != 0x10000 && v3 != 0x20000 ) /*0x14e18d*/
    {
LABEL_45:
      panic(aIpcRightDestro); /*0x14e3dc*/
    }
  }
  v5 = *(_DWORD *)(a3 + 4); /*0x14e21c*/
  v12 = 0; /*0x14e21f*/
  v11 = 0; /*0x14e226*/
  if ( (v13 & 0x200000) != 0 ) /*0x14e236*/
    ipc_marequest_cancel(a1, a2); /*0x14e240*/
  if ( v3 == 0x10000 ) /*0x14e24e*/
    ipc_hash_delete(a1, v5, a2, a3); /*0x14e25a*/
  do /*0x14e276*/
  {
    while ( *(_DWORD *)v5 ) /*0x14e264*/
      ; /*0x14e266*/
  }
  while ( _InterlockedExchange((volatile __int32 *)v5, 1) == 1 ); /*0x14e276*/
  if ( *(int *)(v5 + 8) < 0 ) /*0x14e27c*/
  {
    if ( *(_DWORD *)(a3 + 8) ) /*0x14e2e8*/
    {
      v8 = ipc_port_dncancel(v5, a2, *(_DWORD *)(a3 + 8)); /*0x14e2f5*/
      *(_DWORD *)(a3 + 8) = 0; /*0x14e2fa*/
      if ( (*(_BYTE *)(a3 + 2) & 0x40) != 0 ) /*0x14e308*/
      {
        ipc_space_release(a1); /*0x14e30e*/
        v8 = 0; /*0x14e313*/
      }
      v10 = v8; /*0x14e318*/
    }
    else
    {
      v10 = 0; /*0x14e320*/
    }
    *(_DWORD *)(a3 + 4) = 0; /*0x14e327*/
    ipc_entry_dealloc((_DWORD *)a1, a2, (int *)a3); /*0x14e337*/
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14e344*/
    if ( (v3 & 0x10000) != 0 ) /*0x14e34d*/
    {
      v9 = *(_DWORD *)(v5 + 28); /*0x14e34f*/
      *(_DWORD *)(v5 + 28) = v9 - 1; /*0x14e355*/
      if ( v9 == 1 ) /*0x14e35b*/
      {
        v12 = *(_DWORD *)(v5 + 36); /*0x14e360*/
        if ( v12 ) /*0x14e365*/
        {
          *(_DWORD *)(v5 + 36) = 0; /*0x14e367*/
          v11 = *(_DWORD *)(v5 + 24); /*0x14e371*/
        }
      }
    }
    if ( (v3 & 0x20000) != 0 ) /*0x14e37a*/
    {
      ipc_port_clear_receiver(v5); /*0x14e37d*/
      ipc_port_destroy(v5); /*0x14e383*/
    }
    else if ( (v3 & 0x40000) != 0 ) /*0x14e396*/
    {
      _InterlockedExchange((volatile __int32 *)v5, 0); /*0x14e39a*/
      ipc_notify_send_once(v5); /*0x14e39d*/
    }
    else
    {
      --*(_DWORD *)(v5 + 4); /*0x14e3a8*/
      _InterlockedExchange((volatile __int32 *)v5, 0); /*0x14e3ad*/
    }
    if ( v12 ) /*0x14e3b3*/
      ipc_notify_no_senders(v12, v11); /*0x14e3bd*/
    if ( v10 ) /*0x14e3c9*/
      ipc_notify_port_deleted(v10, a2); /*0x14e3d3*/
  }
  else
  {
    v6 = *(_DWORD *)(v5 + 4) - 1; /*0x14e281*/
    *(_DWORD *)(v5 + 4) = v6; /*0x14e284*/
    _InterlockedExchange((volatile __int32 *)v5, 0); /*0x14e28a*/
    if ( !v6 ) /*0x14e28e*/
      zfree(ipc_object_zones[*(_WORD *)(v5 + 10) & 0x7FFF], v5); /*0x14e2a2*/
    *(_DWORD *)(a3 + 8) = 0; /*0x14e2aa*/
    *(_DWORD *)(a3 + 4) = 0; /*0x14e2b1*/
    ipc_entry_dealloc((_DWORD *)a1, a2, (int *)a3); /*0x14e2c1*/
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14e2cb*/
    if ( (v13 & 0x400000) != 0 ) /*0x14e2d7*/
      return 15; /*0x14e2e2*/
  }
  return 0; /*0x14e3eb*/
}
