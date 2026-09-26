/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14e3f4. */
int __cdecl ipc_right_dealloc(unsigned int a1, unsigned int a2, int a3)
{
  int *v3; // eax
  int v4; // esi
  int v5; // ebx
  unsigned int v6; // ebx
  int v7; // eax
  int v8; // ebx
  int v9; // esi
  int v10; // ebx
  unsigned int v11; // ebx
  int v12; // eax
  int v13; // eax
  int v14; // esi
  int v15; // ebx
  int v16; // edx
  int v17; // eax
  unsigned int v18; // ecx
  int v20; // [esp+Ch] [ebp-10h]
  int v21; // [esp+10h] [ebp-Ch]
  int v22; // [esp+14h] [ebp-8h]
  int v23; // [esp+18h] [ebp-4h]

  v23 = *(_DWORD *)a3; /*0x14e402*/
  v3 = (int *)(*(_DWORD *)a3 & 0x1F0000); /*0x14e407*/
  if ( v3 == (int *)196608 ) /*0x14e411*/
  {
    v14 = 0; /*0x14e7a8*/
    v15 = 0; /*0x14e7aa*/
    v16 = *(_DWORD *)(a3 + 4); /*0x14e7ac*/
    do /*0x14e7c2*/
    {
      while ( *(_DWORD *)v16 ) /*0x14e7b0*/
        ; /*0x14e7b2*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v16, 1) == 1 ); /*0x14e7c2*/
    if ( (_WORD)v23 == 1 ) /*0x14e7c9*/
    {
      v17 = *(_DWORD *)(v16 + 28); /*0x14e7cb*/
      *(_DWORD *)(v16 + 28) = v17 - 1; /*0x14e7d1*/
      if ( v17 == 1 ) /*0x14e7d7*/
      {
        v14 = *(_DWORD *)(v16 + 36); /*0x14e7d9*/
        if ( v14 ) /*0x14e7de*/
        {
          *(_DWORD *)(v16 + 36) = 0; /*0x14e7e0*/
          v15 = *(_DWORD *)(v16 + 24); /*0x14e7e7*/
        }
      }
      v18 = v23 & 0xFFFE0000; /*0x14e7ed*/
    }
    else
    {
      v18 = v23 - 1; /*0x14e7fb*/
    }
    *(_DWORD *)a3 = v18; /*0x14e7fc*/
    _InterlockedExchange((volatile __int32 *)v16, 0); /*0x14e800*/
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14e807*/
    if ( v14 ) /*0x14e80c*/
      ipc_notify_no_senders(v14, v15); /*0x14e810*/
    return 0; /*0x14e815*/
  }
  if ( (*(_DWORD *)a3 & 0x1F0000u) > 0x30000 ) /*0x14e417*/
  {
    if ( v3 != (int *)0x40000 ) /*0x14e431*/
    {
      if ( v3 != &dword_100000 ) /*0x14e438*/
      {
LABEL_73:
        _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14e818*/
        return 17; /*0x14e825*/
      }
      goto LABEL_7; /*0x14e438*/
    }
    v4 = *(_DWORD *)(a3 + 4); /*0x14e46c*/
    do /*0x14e482*/
    {
      while ( *(_DWORD *)v4 ) /*0x14e470*/
        ; /*0x14e472*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v4, 1) == 1 ); /*0x14e482*/
    if ( *(int *)(v4 + 8) < 0 ) /*0x14e488*/
    {
      if ( *(_DWORD *)(a3 + 8) ) /*0x14e537*/
      {
        v7 = ipc_port_dncancel(v4, a2, *(_DWORD *)(a3 + 8)); /*0x14e544*/
        *(_DWORD *)(a3 + 8) = 0; /*0x14e549*/
        if ( (*(_BYTE *)(a3 + 2) & 0x40) != 0 ) /*0x14e557*/
        {
          ipc_space_release(a1); /*0x14e55d*/
          v7 = 0; /*0x14e562*/
        }
        v8 = v7; /*0x14e567*/
      }
      else
      {
        v8 = 0; /*0x14e56c*/
      }
      _InterlockedExchange((volatile __int32 *)v4, 0); /*0x14e570*/
      *(_DWORD *)(a3 + 4) = 0; /*0x14e572*/
      ipc_entry_dealloc((_DWORD *)a1, a2, (int *)a3); /*0x14e582*/
      _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14e58f*/
      ipc_notify_send_once(v4); /*0x14e593*/
      if ( v8 ) /*0x14e59d*/
        ipc_notify_port_deleted(v8, a2); /*0x14e5a8*/
      return 0; /*0x14e5ad*/
    }
    _InterlockedExchange((volatile __int32 *)v4, 0); /*0x14e490*/
    v5 = *(_DWORD *)a3; /*0x14e492*/
    if ( (*(_DWORD *)a3 & 0x10000) != 0 ) /*0x14e49a*/
    {
      if ( (v5 & 0x200000) != 0 ) /*0x14e4a2*/
      {
        v5 &= ~0x200000u; /*0x14e4a4*/
        ipc_marequest_cancel(a1, a2); /*0x14e4b2*/
      }
      ipc_hash_delete(a1, v4, a2, a3); /*0x14e4c4*/
    }
    ipc_object_release(v4); /*0x14e4cd*/
    if ( (v5 & 0x400000) != 0 ) /*0x14e4db*/
      goto LABEL_39; /*0x14e4db*/
    v6 = v5 & 0xFFE0FFFF | 0x100000; /*0x14e50d*/
    if ( *(_DWORD *)(a3 + 8) ) /*0x14e513*/
    {
      *(_DWORD *)(a3 + 8) = 0; /*0x14e519*/
      ++v6; /*0x14e520*/
    }
    *(_DWORD *)a3 = v6; /*0x14e521*/
    *(_DWORD *)(a3 + 4) = 0; /*0x14e523*/
  }
  else
  {
    if ( v3 != (int *)0x10000 ) /*0x14e41e*/
      goto LABEL_73; /*0x14e41e*/
    v22 = 0; /*0x14e5b4*/
    v21 = 0; /*0x14e5bb*/
    v20 = 0; /*0x14e5c2*/
    v9 = *(_DWORD *)(a3 + 4); /*0x14e5c9*/
    do /*0x14e5de*/
    {
      while ( *(_DWORD *)v9 ) /*0x14e5cc*/
        ; /*0x14e5ce*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v9, 1) == 1 ); /*0x14e5de*/
    if ( *(int *)(v9 + 8) < 0 ) /*0x14e5e4*/
    {
      if ( (_WORD)v23 == 1 ) /*0x14e6ad*/
      {
        v12 = *(_DWORD *)(v9 + 28); /*0x14e6b3*/
        *(_DWORD *)(v9 + 28) = v12 - 1; /*0x14e6b9*/
        if ( v12 == 1 ) /*0x14e6bf*/
        {
          v21 = *(_DWORD *)(v9 + 36); /*0x14e6c4*/
          if ( v21 ) /*0x14e6c9*/
          {
            *(_DWORD *)(v9 + 36) = 0; /*0x14e6cb*/
            v20 = *(_DWORD *)(v9 + 24); /*0x14e6d5*/
          }
        }
        if ( *(_DWORD *)(a3 + 8) ) /*0x14e6d8*/
        {
          v13 = ipc_port_dncancel(v9, a2, *(_DWORD *)(a3 + 8)); /*0x14e6e5*/
          *(_DWORD *)(a3 + 8) = 0; /*0x14e6ea*/
          if ( (*(_BYTE *)(a3 + 2) & 0x40) != 0 ) /*0x14e6f8*/
          {
            ipc_space_release(a1); /*0x14e6fe*/
            v13 = 0; /*0x14e703*/
          }
          v22 = v13; /*0x14e708*/
        }
        else
        {
          v22 = 0; /*0x14e710*/
        }
        ipc_hash_delete(a1, v9, a2, a3); /*0x14e721*/
        if ( (v23 & 0x200000) != 0 ) /*0x14e732*/
          ipc_marequest_cancel(a1, a2); /*0x14e73c*/
        --*(_DWORD *)(v9 + 4); /*0x14e744*/
        *(_DWORD *)(a3 + 4) = 0; /*0x14e747*/
        ipc_entry_dealloc((_DWORD *)a1, a2, (int *)a3); /*0x14e757*/
      }
      else
      {
        *(_DWORD *)a3 = v23 - 1; /*0x14e768*/
      }
      _InterlockedExchange((volatile __int32 *)v9, 0); /*0x14e76c*/
      _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14e773*/
      if ( v21 ) /*0x14e77a*/
        ipc_notify_no_senders(v21, v20); /*0x14e784*/
      if ( v22 ) /*0x14e790*/
        ipc_notify_port_deleted(v22, a2); /*0x14e79e*/
      return 0; /*0x14e7a3*/
    }
    _InterlockedExchange((volatile __int32 *)v9, 0); /*0x14e5ec*/
    v10 = *(_DWORD *)a3; /*0x14e5ee*/
    if ( (*(_DWORD *)a3 & 0x10000) != 0 ) /*0x14e5f6*/
    {
      if ( (v10 & 0x200000) != 0 ) /*0x14e5fe*/
      {
        v10 &= ~0x200000u; /*0x14e600*/
        ipc_marequest_cancel(a1, a2); /*0x14e60e*/
      }
      ipc_hash_delete(a1, v9, a2, a3); /*0x14e620*/
    }
    ipc_object_release(v9); /*0x14e629*/
    if ( (v10 & 0x400000) != 0 ) /*0x14e637*/
    {
LABEL_39:
      *(_DWORD *)(a3 + 8) = 0; /*0x14e639*/
      *(_DWORD *)(a3 + 4) = 0; /*0x14e640*/
      ipc_entry_dealloc((_DWORD *)a1, a2, (int *)a3); /*0x14e650*/
      goto LABEL_43; /*0x14e65d*/
    }
    v11 = v10 & 0xFFE0FFFF | 0x100000; /*0x14e669*/
    if ( *(_DWORD *)(a3 + 8) ) /*0x14e66f*/
    {
      *(_DWORD *)(a3 + 8) = 0; /*0x14e675*/
      ++v11; /*0x14e67c*/
    }
    *(_DWORD *)a3 = v11; /*0x14e67d*/
    *(_DWORD *)(a3 + 4) = 0; /*0x14e67f*/
  }
LABEL_43:
  if ( (v23 & 0x400000) == 0 ) /*0x14e698*/
  {
    v23 = *(_DWORD *)a3; /*0x14e6a0*/
LABEL_7:
    if ( (_WORD)v23 == 1 ) /*0x14e443*/
      ipc_entry_dealloc((_DWORD *)a1, a2, (int *)a3); /*0x14e44e*/
    else
      *(_DWORD *)a3 = v23 - 1; /*0x14e45c*/
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14e463*/
    return 0; /*0x14e82a*/
  }
  _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14e831*/
  return 15; /*0x14e83c*/
}
