/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14e844. */
int __cdecl ipc_right_delta(unsigned int a1, unsigned int a2, int a3, int a4, int a5)
{
  volatile __int32 *v5; // ebx
  int v6; // esi
  volatile __int32 *v7; // ebx
  unsigned int v8; // edx
  int v9; // eax
  int v10; // esi
  int v11; // ebx
  unsigned int v12; // ebx
  int v13; // eax
  int v14; // ebx
  int v15; // esi
  int v16; // ebx
  unsigned int v17; // ebx
  unsigned int v18; // ebx
  int v19; // esi
  int v20; // ebx
  unsigned int v21; // ebx
  int v22; // eax
  unsigned int v23; // ecx
  int v24; // eax
  int result; // eax
  int v26; // [esp+Ch] [ebp-14h]
  int v27; // [esp+10h] [ebp-10h]
  int v28; // [esp+14h] [ebp-Ch]
  int v29; // [esp+1Ch] [ebp-4h]
  unsigned int v30; // [esp+1Ch] [ebp-4h]

  v29 = *(_DWORD *)a3; /*0x14e855*/
  switch ( a4 ) /*0x14e861*/
  {
    case 0: /*0x14e861*/
      v28 = 0; /*0x14ecec*/
      v27 = 0; /*0x14ecf3*/
      v26 = 0; /*0x14ecfa*/
      if ( (v29 & 0x10000) == 0 ) /*0x14ed0a*/
        goto LABEL_123; /*0x14ed0a*/
      if ( a5 < 0 && -a5 > (unsigned int)(unsigned __int16)v29 ) /*0x14ed23*/
        goto LABEL_124; /*0x14ed23*/
      if ( a5 > 0 ) /*0x14ed2d*/
      {
        v18 = (unsigned __int16)v29 + a5 + 1; /*0x14ed35*/
        if ( v18 <= (unsigned int)(unsigned __int16)v29 + 1 || v18 > 0xFFFF ) /*0x14ed4a*/
          goto LABEL_125; /*0x14ed4a*/
      }
      v19 = *(_DWORD *)(a3 + 4); /*0x14ed50*/
      do /*0x14ed66*/
      {
        while ( *(_DWORD *)v19 ) /*0x14ed54*/
          ; /*0x14ed56*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v19, 1) == 1 ); /*0x14ed66*/
      if ( *(int *)(v19 + 8) < 0 ) /*0x14ed6c*/
      {
        if ( a5 + (unsigned __int16)v29 ) /*0x14ee2f*/
        {
          v23 = a5 + v29; /*0x14ef03*/
        }
        else
        {
          v22 = *(_DWORD *)(v19 + 28); /*0x14ee38*/
          *(_DWORD *)(v19 + 28) = v22 - 1; /*0x14ee3e*/
          if ( v22 == 1 ) /*0x14ee44*/
          {
            v27 = *(_DWORD *)(v19 + 36); /*0x14ee49*/
            if ( v27 ) /*0x14ee4e*/
            {
              *(_DWORD *)(v19 + 36) = 0; /*0x14ee50*/
              v26 = *(_DWORD *)(v19 + 24); /*0x14ee5a*/
            }
          }
          if ( (v29 & 0x20000) == 0 ) /*0x14ee66*/
          {
            if ( *(_DWORD *)(a3 + 8) ) /*0x14ee74*/
            {
              v24 = ipc_port_dncancel(v19, a2, *(_DWORD *)(a3 + 8)); /*0x14ee81*/
              *(_DWORD *)(a3 + 8) = 0; /*0x14ee86*/
              if ( (*(_BYTE *)(a3 + 2) & 0x40) != 0 ) /*0x14ee94*/
              {
                ipc_space_release(a1); /*0x14ee9a*/
                v24 = 0; /*0x14ee9f*/
              }
              v28 = v24; /*0x14eea4*/
            }
            else
            {
              v28 = 0; /*0x14eeac*/
            }
            ipc_hash_delete(a1, v19, a2, a3); /*0x14eebd*/
            if ( (v29 & 0x200000) != 0 ) /*0x14eece*/
              ipc_marequest_cancel(a1, a2); /*0x14eed8*/
            --*(_DWORD *)(v19 + 4); /*0x14eee0*/
            *(_DWORD *)(a3 + 4) = 0; /*0x14eee3*/
            ipc_entry_dealloc((_DWORD *)a1, a2, (int *)a3); /*0x14eef3*/
            goto LABEL_116; /*0x14eefb*/
          }
          v23 = v29 & 0xFFFE0000; /*0x14ee68*/
        }
        *(_DWORD *)a3 = v23; /*0x14ef06*/
LABEL_116:
        _InterlockedExchange((volatile __int32 *)v19, 0); /*0x14ef08*/
        _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14ef11*/
        if ( v27 ) /*0x14ef18*/
          ipc_notify_no_senders(v27, v26); /*0x14ef22*/
        if ( v28 ) /*0x14ef2e*/
          ipc_notify_port_deleted(v28, a2); /*0x14ef38*/
        return 0; /*0x14ef3d*/
      }
      _InterlockedExchange((volatile __int32 *)v19, 0); /*0x14ed74*/
      v20 = *(_DWORD *)a3; /*0x14ed76*/
      if ( (*(_DWORD *)a3 & 0x10000) != 0 ) /*0x14ed7e*/
      {
        if ( (v20 & 0x200000) != 0 ) /*0x14ed86*/
        {
          v20 &= ~0x200000u; /*0x14ed88*/
          ipc_marequest_cancel(a1, a2); /*0x14ed96*/
        }
        ipc_hash_delete(a1, v19, a2, a3); /*0x14eda8*/
      }
      ipc_object_release(v19); /*0x14edb1*/
      if ( (v20 & 0x400000) == 0 ) /*0x14edbf*/
      {
        v21 = v20 & 0xFFE0FFFF | 0x100000; /*0x14edf1*/
        if ( *(_DWORD *)(a3 + 8) ) /*0x14edf7*/
        {
          *(_DWORD *)(a3 + 8) = 0; /*0x14edfd*/
          ++v21; /*0x14ee04*/
        }
        *(_DWORD *)a3 = v21; /*0x14ee05*/
        *(_DWORD *)(a3 + 4) = 0; /*0x14ee07*/
        goto LABEL_98; /*0x14ee07*/
      }
LABEL_94:
      *(_DWORD *)(a3 + 8) = 0; /*0x14edc1*/
      *(_DWORD *)(a3 + 4) = 0; /*0x14edc8*/
      ipc_entry_dealloc((_DWORD *)a1, a2, (int *)a3); /*0x14edd8*/
LABEL_98:
      if ( (v29 & 0x400000) == 0 ) /*0x14ee20*/
      {
LABEL_123:
        _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14ef58*/
        return 17; /*0x14ef65*/
      }
LABEL_126:
      _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14ef88*/
      return 15;
    case 1: /*0x14e861*/
      v6 = 0; /*0x14e8e4*/
      if ( (v29 & 0x20000) == 0 ) /*0x14e8ef*/
        goto LABEL_123; /*0x14e8ef*/
      if ( !a5 ) /*0x14e8f9*/
        goto LABEL_121; /*0x14e8f9*/
      if ( a5 != -1 ) /*0x14e903*/
        goto LABEL_124; /*0x14e903*/
      if ( (*(_DWORD *)a3 & 0x200000) != 0 ) /*0x14e90f*/
      {
        v29 &= ~0x200000u; /*0x14e917*/
        ipc_marequest_cancel(a1, a2); /*0x14e922*/
      }
      v7 = *(volatile __int32 **)(a3 + 4); /*0x14e92a*/
      do /*0x14e942*/
      {
        while ( *v7 ) /*0x14e930*/
          ; /*0x14e932*/
      }
      while ( _InterlockedExchange(v7, 1) == 1 ); /*0x14e942*/
      if ( (v29 & 0x400000) != 0 ) /*0x14e94d*/
        goto LABEL_23; /*0x14e94d*/
      if ( (v29 & 0x10000) != 0 ) /*0x14e961*/
      {
        v8 = v29 & 0xFFE0FFFF | 0x100000; /*0x14e969*/
        v30 = v8; /*0x14e96f*/
        if ( *(_DWORD *)(a3 + 8) ) /*0x14e972*/
        {
          *(_DWORD *)(a3 + 8) = 0; /*0x14e978*/
          v30 = v8 + 1; /*0x14e980*/
        }
        *(_DWORD *)a3 = v30; /*0x14e986*/
        *(_DWORD *)(a3 + 4) = 0; /*0x14e988*/
      }
      else
      {
        if ( *(_DWORD *)(a3 + 8) ) /*0x14e994*/
        {
LABEL_23:
          v9 = ipc_port_dncancel((int)v7, a2, *(_DWORD *)(a3 + 8)); /*0x14e99b*/
          *(_DWORD *)(a3 + 8) = 0; /*0x14e9a6*/
          if ( (*(_BYTE *)(a3 + 2) & 0x40) != 0 ) /*0x14e9b4*/
          {
            ipc_space_release(a1); /*0x14e9ba*/
            v9 = 0; /*0x14e9bf*/
          }
          v6 = v9; /*0x14e9c4*/
        }
        else
        {
          v6 = 0; /*0x14e9c8*/
        }
        *(_DWORD *)(a3 + 4) = 0; /*0x14e9ca*/
        ipc_entry_dealloc((_DWORD *)a1, a2, (int *)a3); /*0x14e9da*/
      }
      _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14e9e7*/
      ipc_port_clear_receiver((int)v7); /*0x14e9eb*/
      ipc_port_destroy((int)v7); /*0x14e9f1*/
      if ( v6 ) /*0x14e9fb*/
        ipc_notify_port_deleted(v6, a2); /*0x14ea06*/
      return 0; /*0x14ea0b*/
    case 2: /*0x14e861*/
      if ( (v29 & 0x40000) == 0 ) /*0x14ea19*/
        goto LABEL_123; /*0x14ea19*/
      if ( a5 != -1 && a5 != 0 ) /*0x14ea23*/
        goto LABEL_124; /*0x14ea26*/
      v10 = *(_DWORD *)(a3 + 4); /*0x14ea2c*/
      do /*0x14ea42*/
      {
        while ( *(_DWORD *)v10 ) /*0x14ea30*/
          ; /*0x14ea32*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v10, 1) == 1 ); /*0x14ea42*/
      if ( *(int *)(v10 + 8) < 0 ) /*0x14ea48*/
      {
        if ( !a5 ) /*0x14eafb*/
        {
          _InterlockedExchange((volatile __int32 *)v10, 0); /*0x14eaff*/
          goto LABEL_121; /*0x14eb01*/
        }
        if ( *(_DWORD *)(a3 + 8) ) /*0x14eb08*/
        {
          v13 = ipc_port_dncancel(v10, a2, *(_DWORD *)(a3 + 8)); /*0x14eb15*/
          *(_DWORD *)(a3 + 8) = 0; /*0x14eb1a*/
          if ( (*(_BYTE *)(a3 + 2) & 0x40) != 0 ) /*0x14eb28*/
          {
            ipc_space_release(a1); /*0x14eb2e*/
            v13 = 0; /*0x14eb33*/
          }
          v14 = v13; /*0x14eb38*/
        }
        else
        {
          v14 = 0; /*0x14eb3c*/
        }
        _InterlockedExchange((volatile __int32 *)v10, 0); /*0x14eb40*/
        *(_DWORD *)(a3 + 4) = 0; /*0x14eb42*/
        ipc_entry_dealloc((_DWORD *)a1, a2, (int *)a3); /*0x14eb52*/
        _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14eb5f*/
        ipc_notify_send_once(v10); /*0x14eb63*/
        if ( v14 ) /*0x14eb6d*/
          ipc_notify_port_deleted(v14, a2); /*0x14eb78*/
        return 0; /*0x14eb7d*/
      }
      _InterlockedExchange((volatile __int32 *)v10, 0); /*0x14ea50*/
      v11 = *(_DWORD *)a3; /*0x14ea52*/
      if ( (*(_DWORD *)a3 & 0x10000) != 0 ) /*0x14ea5a*/
      {
        if ( (v11 & 0x200000) != 0 ) /*0x14ea62*/
        {
          v11 &= ~0x200000u; /*0x14ea64*/
          ipc_marequest_cancel(a1, a2); /*0x14ea72*/
        }
        ipc_hash_delete(a1, v10, a2, a3); /*0x14ea84*/
      }
      ipc_object_release(v10); /*0x14ea8d*/
      if ( (v11 & 0x400000) == 0 ) /*0x14ea9b*/
      {
        v12 = v11 & 0xFFE0FFFF | 0x100000; /*0x14eacd*/
        if ( *(_DWORD *)(a3 + 8) ) /*0x14ead3*/
        {
          *(_DWORD *)(a3 + 8) = 0; /*0x14ead9*/
          ++v12; /*0x14eae0*/
        }
        *(_DWORD *)a3 = v12; /*0x14eae1*/
        *(_DWORD *)(a3 + 4) = 0; /*0x14eae3*/
        goto LABEL_98; /*0x14eaf1*/
      }
      goto LABEL_94; /*0x14ea9b*/
    case 3: /*0x14e861*/
      if ( (v29 & 0x80000) == 0 ) /*0x14e885*/
        goto LABEL_123; /*0x14e885*/
      if ( !a5 ) /*0x14e88f*/
        goto LABEL_121; /*0x14e88f*/
      if ( a5 != -1 ) /*0x14e899*/
        goto LABEL_124; /*0x14e899*/
      v5 = *(volatile __int32 **)(a3 + 4); /*0x14e89f*/
      *(_DWORD *)(a3 + 4) = 0; /*0x14e8a2*/
      ipc_entry_dealloc((_DWORD *)a1, a2, (int *)a3); /*0x14e8b2*/
      do /*0x14e8ce*/
      {
        while ( *v5 ) /*0x14e8bc*/
          ; /*0x14e8be*/
      }
      while ( _InterlockedExchange(v5, 1) == 1 ); /*0x14e8ce*/
      _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14e8d5*/
      ipc_pset_destroy((int)v5); /*0x14e8d9*/
      return 0; /*0x14e8de*/
    case 4: /*0x14e861*/
      if ( (v29 & 0x50000) != 0 ) /*0x14eb88*/
      {
        v15 = *(_DWORD *)(a3 + 4); /*0x14eb8e*/
        do /*0x14eba6*/
        {
          while ( *(_DWORD *)v15 ) /*0x14eb94*/
            ; /*0x14eb96*/
        }
        while ( _InterlockedExchange((volatile __int32 *)v15, 1) == 1 ); /*0x14eba6*/
        if ( *(int *)(v15 + 8) < 0 ) /*0x14ebac*/
        {
          _InterlockedExchange((volatile __int32 *)v15, 0); /*0x14ec59*/
          goto LABEL_123; /*0x14ec5b*/
        }
        _InterlockedExchange((volatile __int32 *)v15, 0); /*0x14ebb4*/
        v16 = *(_DWORD *)a3; /*0x14ebb6*/
        if ( (*(_DWORD *)a3 & 0x10000) != 0 ) /*0x14ebbe*/
        {
          if ( (v16 & 0x200000) != 0 ) /*0x14ebc6*/
          {
            v16 &= ~0x200000u; /*0x14ebc8*/
            ipc_marequest_cancel(a1, a2); /*0x14ebd6*/
          }
          ipc_hash_delete(a1, v15, a2, a3); /*0x14ebe8*/
        }
        ipc_object_release(v15); /*0x14ebf1*/
        if ( (v16 & 0x400000) != 0 ) /*0x14ebff*/
        {
          *(_DWORD *)(a3 + 8) = 0; /*0x14ec01*/
          *(_DWORD *)(a3 + 4) = 0; /*0x14ec08*/
          ipc_entry_dealloc((_DWORD *)a1, a2, (int *)a3); /*0x14ec18*/
        }
        else
        {
          v17 = v16 & 0xFFE0FFFF | 0x100000; /*0x14ec31*/
          if ( *(_DWORD *)(a3 + 8) ) /*0x14ec37*/
          {
            *(_DWORD *)(a3 + 8) = 0; /*0x14ec3d*/
            ++v17; /*0x14ec44*/
          }
          *(_DWORD *)a3 = v17; /*0x14ec45*/
          *(_DWORD *)(a3 + 4) = 0; /*0x14ec47*/
        }
        if ( (v29 & 0x400000) != 0 ) /*0x14ec69*/
          goto LABEL_126; /*0x14ec69*/
        v29 = *(_DWORD *)a3; /*0x14ec71*/
      }
      else if ( (v29 & 0x100000) == 0 ) /*0x14ec81*/
      {
        goto LABEL_123; /*0x14ec81*/
      }
      if ( a5 < 0 && -a5 > (unsigned int)(unsigned __int16)v29 ) /*0x14ec98*/
      {
LABEL_124:
        _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14ef68*/
        return 18; /*0x14ef70*/
      }
      else if ( a5 > 0 /*0x14ecb6*/
             && ((unsigned int)(unsigned __int16)v29 + a5 <= (unsigned __int16)v29
              || (unsigned int)(unsigned __int16)v29 + a5 > 0xFFFF) )
      {
LABEL_125:
        _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14ef78*/
        return 19; /*0x14ef80*/
      }
      else
      {
        if ( (unsigned __int16)v29 + a5 ) /*0x14ecbf*/
          *(_DWORD *)a3 = a5 + v29; /*0x14ecda*/
        else
          ipc_entry_dealloc((_DWORD *)a1, a2, (int *)a3); /*0x14eccc*/
LABEL_121:
        _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14ef4c*/
        return 0; /*0x14ef54*/
      }
    default:
      panic(aIpcRightDeltaS); /*0x14ef45*/
      return result; /*0x14ef45*/
  }
}
