/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14fecc. */
int __cdecl ipc_right_copyin_compat(unsigned int a1, unsigned int a2, int a3, int a4, int a5, int *a6)
{
  int v6; // esi
  int v7; // ebx
  unsigned int v8; // ebx
  int v9; // eax
  int v10; // ebx
  int v11; // ebx
  int v12; // esi
  unsigned int v13; // esi
  int v14; // eax
  int v15; // esi
  int v16; // eax
  int v18; // [esp+Ch] [ebp-Ch]
  int v19; // [esp+10h] [ebp-8h]
  int v20; // [esp+14h] [ebp-4h]

  v20 = *(_DWORD *)a3; /*0x14fee0*/
  if ( a4 == 5 ) /*0x14fee6*/
  {
    if ( a5 ) /*0x15017e*/
    {
      v19 = 0; /*0x150184*/
      v18 = 0; /*0x15018b*/
      if ( (v20 & 0x20000) == 0 ) /*0x15019b*/
        goto LABEL_77; /*0x15019b*/
      v11 = *(_DWORD *)(a3 + 4); /*0x1501a1*/
      do /*0x1501b6*/
      {
        while ( *(_DWORD *)v11 ) /*0x1501a4*/
          ; /*0x1501a6*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v11, 1) == 1 ); /*0x1501b6*/
      if ( *(_DWORD *)(a3 + 8) ) /*0x1501b8*/
      {
        v14 = ipc_port_dncancel(v11, a2, *(_DWORD *)(a3 + 8)); /*0x1501c5*/
        *(_DWORD *)(a3 + 8) = 0; /*0x1501ca*/
        if ( (*(_BYTE *)(a3 + 2) & 0x40) != 0 ) /*0x1501d8*/
        {
          ipc_space_release(a1); /*0x1501de*/
          v14 = 0; /*0x1501e3*/
        }
        v15 = v14; /*0x1501e8*/
      }
      else
      {
        v15 = 0; /*0x1501ec*/
      }
      if ( (v20 & 0x200000) != 0 ) /*0x1501f7*/
        ipc_marequest_cancel(a1, a2); /*0x150201*/
      *(_DWORD *)(a3 + 4) = 0; /*0x150209*/
      ipc_entry_dealloc((_DWORD *)a1, a2, (int *)a3); /*0x150219*/
      _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x150226*/
      if ( (v20 & 0x10000) != 0 ) /*0x150232*/
      {
        v16 = *(_DWORD *)(v11 + 28); /*0x150234*/
        *(_DWORD *)(v11 + 28) = v16 - 1; /*0x15023a*/
        if ( v16 == 1 ) /*0x150240*/
        {
          v19 = *(_DWORD *)(v11 + 36); /*0x150245*/
          if ( v19 ) /*0x15024a*/
          {
            *(_DWORD *)(v11 + 36) = 0; /*0x15024c*/
            v18 = *(_DWORD *)(v11 + 24); /*0x150256*/
          }
        }
      }
      ipc_port_clear_receiver(v11); /*0x15025a*/
      *(_DWORD *)(v11 + 16) = 0; /*0x15025f*/
      *(_DWORD *)(v11 + 12) = 0; /*0x150266*/
      _InterlockedExchange((volatile __int32 *)v11, 0); /*0x150272*/
      if ( v19 ) /*0x150278*/
        ipc_notify_no_senders(v19, v18); /*0x150282*/
      if ( v15 ) /*0x15028c*/
        ipc_notify_port_deleted(v15, a2); /*0x150297*/
LABEL_74:
      *a6 = v11; /*0x150323*/
      return 0; /*0x150328*/
    }
    if ( (v20 & 0x20000) == 0 ) /*0x1502ad*/
      goto LABEL_77; /*0x1502ad*/
    v11 = *(_DWORD *)(a3 + 4); /*0x1502b3*/
    do /*0x1502ca*/
    {
      while ( *(_DWORD *)v11 ) /*0x1502b8*/
        ; /*0x1502ba*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v11, 1) == 1 ); /*0x1502ca*/
    if ( (v20 & 0x10000) == 0 ) /*0x1502d5*/
    {
      ++*(_DWORD *)(v11 + 28); /*0x1502d7*/
      v20 |= 0x10001u; /*0x1502e0*/
    }
    ipc_hash_insert(a1, v11, a2, a3); /*0x1502ed*/
    *(_DWORD *)a3 = v20 & 0xFFFDFFFF; /*0x1502fb*/
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x150305*/
    ipc_port_clear_receiver(v11); /*0x150309*/
    *(_DWORD *)(v11 + 16) = 0; /*0x15030e*/
    *(_DWORD *)(v11 + 12) = 0; /*0x150315*/
LABEL_73:
    ++*(_DWORD *)(v11 + 4); /*0x15031c*/
    _InterlockedExchange((volatile __int32 *)v11, 0); /*0x150321*/
    goto LABEL_74; /*0x150321*/
  }
  if ( a4 != 6 ) /*0x14feef*/
    panic(aIpcRightCopyin_1); /*0x150331*/
  if ( a5 ) /*0x14fef7*/
  {
    if ( (*(_DWORD *)a3 & 0x1F0000) == 0x10000 ) /*0x14ff09*/
    {
      v6 = *(_DWORD *)(a3 + 4); /*0x14ff0f*/
      do /*0x14ff26*/
      {
        while ( *(_DWORD *)v6 ) /*0x14ff14*/
          ; /*0x14ff16*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v6, 1) == 1 ); /*0x14ff26*/
      if ( *(int *)(v6 + 8) >= 0 ) /*0x14ff2c*/
      {
        _InterlockedExchange((volatile __int32 *)v6, 0); /*0x14ff34*/
        v7 = *(_DWORD *)a3; /*0x14ff36*/
        if ( (*(_DWORD *)a3 & 0x10000) != 0 ) /*0x14ff3e*/
        {
          if ( (v7 & 0x200000) != 0 ) /*0x14ff46*/
          {
            v7 &= ~0x200000u; /*0x14ff48*/
            ipc_marequest_cancel(a1, a2); /*0x14ff56*/
          }
          ipc_hash_delete(a1, v6, a2, a3); /*0x14ff68*/
        }
        ipc_object_release(v6); /*0x14ff71*/
        if ( (v7 & 0x400000) == 0 ) /*0x14ff7f*/
        {
          v8 = v7 & 0xFFE0FFFF | 0x100000; /*0x14ffb1*/
          if ( *(_DWORD *)(a3 + 8) ) /*0x14ffb7*/
          {
            *(_DWORD *)(a3 + 8) = 0; /*0x14ffbd*/
            ++v8; /*0x14ffc4*/
          }
          *(_DWORD *)a3 = v8; /*0x14ffc5*/
          *(_DWORD *)(a3 + 4) = 0; /*0x14ffc7*/
          goto LABEL_41; /*0x14ffd5*/
        }
LABEL_37:
        *(_DWORD *)(a3 + 8) = 0; /*0x1500f5*/
        *(_DWORD *)(a3 + 4) = 0; /*0x1500fc*/
        ipc_entry_dealloc((_DWORD *)a1, a2, (int *)a3); /*0x15010c*/
        goto LABEL_41; /*0x150116*/
      }
      if ( *(_DWORD *)(a3 + 8) ) /*0x14ffdb*/
      {
        v9 = ipc_port_dncancel(v6, a2, *(_DWORD *)(a3 + 8)); /*0x14ffe8*/
        *(_DWORD *)(a3 + 8) = 0; /*0x14ffed*/
        if ( (*(_BYTE *)(a3 + 2) & 0x40) != 0 ) /*0x14fffb*/
        {
          ipc_space_release(a1); /*0x150001*/
          v9 = 0; /*0x150006*/
        }
        v10 = v9; /*0x15000b*/
      }
      else
      {
        v10 = 0; /*0x150010*/
      }
      _InterlockedExchange((volatile __int32 *)v6, 0); /*0x150014*/
      if ( (v20 & 0x200000) != 0 ) /*0x15001f*/
        ipc_marequest_cancel(a1, a2); /*0x150029*/
      ipc_hash_delete(a1, v6, a2, a3); /*0x15003b*/
      *(_DWORD *)(a3 + 4) = 0; /*0x150040*/
      ipc_entry_dealloc((_DWORD *)a1, a2, (int *)a3); /*0x150050*/
      _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x15005d*/
      if ( v10 ) /*0x150062*/
        ipc_notify_port_deleted(v10, a2); /*0x150069*/
      *a6 = v6; /*0x150071*/
      return 0; /*0x150338*/
    }
LABEL_77:
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x15033c*/
    return 17; /*0x150349*/
  }
  if ( (v20 & 0x30000) == 0 ) /*0x15007c*/
    goto LABEL_77; /*0x15007c*/
  v11 = *(_DWORD *)(a3 + 4); /*0x150082*/
  do /*0x15009a*/
  {
    while ( *(_DWORD *)v11 ) /*0x150088*/
      ; /*0x15008a*/
  }
  while ( _InterlockedExchange((volatile __int32 *)v11, 1) == 1 ); /*0x15009a*/
  if ( *(int *)(v11 + 8) < 0 ) /*0x1500a0*/
  {
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x150161*/
    if ( (v20 & 0x10000) == 0 ) /*0x15016d*/
      ++*(_DWORD *)(v11 + 24); /*0x15016f*/
    ++*(_DWORD *)(v11 + 28); /*0x150172*/
    goto LABEL_73; /*0x150175*/
  }
  _InterlockedExchange((volatile __int32 *)v11, 0); /*0x1500a8*/
  v12 = *(_DWORD *)a3; /*0x1500aa*/
  if ( (*(_DWORD *)a3 & 0x10000) != 0 ) /*0x1500b2*/
  {
    if ( (v12 & 0x200000) != 0 ) /*0x1500ba*/
    {
      v12 &= ~0x200000u; /*0x1500bc*/
      ipc_marequest_cancel(a1, a2); /*0x1500ca*/
    }
    ipc_hash_delete(a1, v11, a2, a3); /*0x1500dc*/
  }
  ipc_object_release(v11); /*0x1500e5*/
  if ( (v12 & 0x400000) != 0 ) /*0x1500f3*/
    goto LABEL_37; /*0x1500f3*/
  v13 = v12 & 0xFFE0FFFF | 0x100000; /*0x150121*/
  if ( *(_DWORD *)(a3 + 8) ) /*0x150127*/
  {
    *(_DWORD *)(a3 + 8) = 0; /*0x15012d*/
    ++v13; /*0x150134*/
  }
  *(_DWORD *)a3 = v13; /*0x150135*/
  *(_DWORD *)(a3 + 4) = 0; /*0x150137*/
LABEL_41:
  if ( (v20 & 0x400000) == 0 ) /*0x150150*/
    goto LABEL_77; /*0x150150*/
  _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x150351*/
  return 15; /*0x15035c*/
}
