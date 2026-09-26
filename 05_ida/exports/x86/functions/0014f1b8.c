/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14f1b8. */
int __cdecl ipc_right_copyin(_DWORD *a1, unsigned int a2, int a3, int a4, int a5, int *a6, int *a7)
{
  int v7; // ebx
  int v8; // ebx
  int v9; // esi
  int v10; // ebx
  int v11; // eax
  int v12; // esi
  unsigned int v13; // esi
  int v14; // esi
  int v15; // ebx
  unsigned int v16; // ebx
  int v17; // eax
  int v18; // ebx
  unsigned int v19; // ebx
  int v20; // eax
  int v21; // ebx
  int result; // eax
  int v23; // [esp+Ch] [ebp-8h]
  int v24; // [esp+10h] [ebp-4h]

  v24 = *(_DWORD *)a3; /*0x14f1c6*/
  switch ( a4 ) /*0x14f1d8*/
  {
    case 16: /*0x14f1d8*/
      v9 = 0; /*0x14f270*/
      if ( (v24 & 0x20000) == 0 ) /*0x14f27b*/
        return 17; /*0x14f27b*/
      v10 = *(_DWORD *)(a3 + 4); /*0x14f281*/
      do /*0x14f296*/
      {
        while ( *(_DWORD *)v10 ) /*0x14f284*/
          ; /*0x14f286*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v10, 1) == 1 ); /*0x14f296*/
      if ( (v24 & 0x10000) != 0 ) /*0x14f2a1*/
      {
        ipc_hash_insert((int)a1, v10, a2, a3); /*0x14f2ad*/
        ++*(_DWORD *)(v10 + 4); /*0x14f2b5*/
      }
      else
      {
        if ( *(_DWORD *)(a3 + 8) ) /*0x14f2bc*/
        {
          v11 = ipc_port_dncancel(v10, a2, *(_DWORD *)(a3 + 8)); /*0x14f2c9*/
          *(_DWORD *)(a3 + 8) = 0; /*0x14f2ce*/
          if ( (*(_BYTE *)(a3 + 2) & 0x40) != 0 ) /*0x14f2dc*/
          {
            ipc_space_release(a1); /*0x14f2e2*/
            v11 = 0; /*0x14f2e7*/
          }
          v9 = v11; /*0x14f2ec*/
        }
        else
        {
          v9 = 0; /*0x14f2f0*/
        }
        if ( (v24 & 0x200000) != 0 ) /*0x14f2fb*/
          ipc_marequest_cancel((unsigned int)a1, a2); /*0x14f305*/
        *(_DWORD *)(a3 + 4) = 0; /*0x14f30d*/
      }
      *(_DWORD *)a3 = v24 & 0xFFFDFFFF; /*0x14f31d*/
      ipc_port_clear_receiver(v10); /*0x14f320*/
      *(_DWORD *)(v10 + 16) = 0; /*0x14f325*/
      *(_DWORD *)(v10 + 12) = 0; /*0x14f32c*/
      _InterlockedExchange((volatile __int32 *)v10, 0); /*0x14f335*/
      *a6 = v10; /*0x14f33a*/
      *a7 = v9; /*0x14f33f*/
      return 0; /*0x14f341*/
    case 17: /*0x14f1d8*/
      v23 = 0; /*0x14f464*/
      if ( (v24 & 0x100000) != 0 ) /*0x14f474*/
        goto LABEL_107; /*0x14f474*/
      if ( (*(_DWORD *)a3 & 0x50000) == 0 ) /*0x14f480*/
        return 17; /*0x14f480*/
      v14 = *(_DWORD *)(a3 + 4); /*0x14f486*/
      do /*0x14f49e*/
      {
        while ( *(_DWORD *)v14 ) /*0x14f48c*/
          ; /*0x14f48e*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v14, 1) == 1 ); /*0x14f49e*/
      if ( *(int *)(v14 + 8) >= 0 ) /*0x14f4a4*/
      {
        _InterlockedExchange((volatile __int32 *)v14, 0); /*0x14f4ac*/
        v15 = *(_DWORD *)a3; /*0x14f4ae*/
        if ( (*(_DWORD *)a3 & 0x10000) != 0 ) /*0x14f4b6*/
        {
          if ( (v15 & 0x200000) != 0 ) /*0x14f4be*/
          {
            v15 &= ~0x200000u; /*0x14f4c0*/
            ipc_marequest_cancel((unsigned int)a1, a2); /*0x14f4ce*/
          }
          ipc_hash_delete((int)a1, v14, a2, a3); /*0x14f4e0*/
        }
        ipc_object_release(v14); /*0x14f4e9*/
        if ( (v15 & 0x400000) != 0 ) /*0x14f4f7*/
        {
          *(_DWORD *)(a3 + 8) = 0; /*0x14f4f9*/
          *(_DWORD *)(a3 + 4) = 0; /*0x14f500*/
          ipc_entry_dealloc(a1, a2, (int *)a3); /*0x14f510*/
        }
        else
        {
          v16 = v15 & 0xFFE0FFFF | 0x100000; /*0x14f529*/
          if ( *(_DWORD *)(a3 + 8) ) /*0x14f52f*/
          {
            *(_DWORD *)(a3 + 8) = 0; /*0x14f535*/
            ++v16; /*0x14f53c*/
          }
          *(_DWORD *)a3 = v16; /*0x14f53d*/
          *(_DWORD *)(a3 + 4) = 0; /*0x14f53f*/
        }
        if ( (v24 & 0x400000) == 0 ) /*0x14f558*/
        {
          v24 = *(_DWORD *)a3; /*0x14f560*/
          goto LABEL_107; /*0x14f563*/
        }
        return 15; /*0x14f558*/
      }
      if ( (v24 & 0x10000) == 0 ) /*0x14f571*/
        goto LABEL_97; /*0x14f571*/
      if ( (_WORD)v24 == 1 ) /*0x14f57c*/
      {
        if ( (v24 & 0x20000) != 0 ) /*0x14f58b*/
        {
          ++*(_DWORD *)(v14 + 4); /*0x14f58d*/
        }
        else
        {
          if ( *(_DWORD *)(a3 + 8) ) /*0x14f594*/
          {
            v17 = ipc_port_dncancel(v14, a2, *(_DWORD *)(a3 + 8)); /*0x14f5a1*/
            *(_DWORD *)(a3 + 8) = 0; /*0x14f5a6*/
            if ( (*(_BYTE *)(a3 + 2) & 0x40) != 0 ) /*0x14f5b4*/
            {
              ipc_space_release(a1); /*0x14f5ba*/
              v17 = 0; /*0x14f5bf*/
            }
            v23 = v17; /*0x14f5c4*/
          }
          else
          {
            v23 = 0; /*0x14f5cc*/
          }
          ipc_hash_delete((int)a1, v14, a2, a3); /*0x14f5dd*/
          if ( (v24 & 0x200000) != 0 ) /*0x14f5ee*/
            ipc_marequest_cancel((unsigned int)a1, a2); /*0x14f5f8*/
          *(_DWORD *)(a3 + 4) = 0; /*0x14f5fd*/
        }
        *(_DWORD *)a3 = v24 & 0xFFFE0000; /*0x14f60d*/
      }
      else
      {
        ++*(_DWORD *)(v14 + 28); /*0x14f614*/
        ++*(_DWORD *)(v14 + 4); /*0x14f617*/
        *(_DWORD *)a3 = v24 - 1; /*0x14f61e*/
      }
      _InterlockedExchange((volatile __int32 *)v14, 0); /*0x14f622*/
      *a6 = v14; /*0x14f627*/
      *a7 = v23; /*0x14f62f*/
      return 0; /*0x14f631*/
    case 18: /*0x14f1d8*/
      if ( (v24 & 0x100000) != 0 ) /*0x14f641*/
        goto LABEL_107; /*0x14f641*/
      if ( (*(_DWORD *)a3 & 0x50000) == 0 ) /*0x14f64d*/
        return 17; /*0x14f64d*/
      v14 = *(_DWORD *)(a3 + 4); /*0x14f653*/
      do /*0x14f66a*/
      {
        while ( *(_DWORD *)v14 ) /*0x14f658*/
          ; /*0x14f65a*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v14, 1) == 1 ); /*0x14f66a*/
      if ( *(int *)(v14 + 8) < 0 ) /*0x14f670*/
      {
        if ( (v24 & 0x40000) == 0 ) /*0x14f73d*/
        {
LABEL_97:
          _InterlockedExchange((volatile __int32 *)v14, 0); /*0x14f73f*/
          return 17; /*0x14f743*/
        }
        if ( *(_DWORD *)(a3 + 8) ) /*0x14f748*/
        {
          v20 = ipc_port_dncancel(v14, a2, *(_DWORD *)(a3 + 8)); /*0x14f755*/
          *(_DWORD *)(a3 + 8) = 0; /*0x14f75a*/
          if ( (*(_BYTE *)(a3 + 2) & 0x40) != 0 ) /*0x14f768*/
          {
            ipc_space_release(a1); /*0x14f76e*/
            v20 = 0; /*0x14f773*/
          }
          v21 = v20; /*0x14f775*/
        }
        else
        {
          v21 = 0; /*0x14f77c*/
        }
        _InterlockedExchange((volatile __int32 *)v14, 0); /*0x14f780*/
        *(_DWORD *)(a3 + 4) = 0; /*0x14f782*/
        *(_DWORD *)a3 = v24 & 0xFFFBFFFF; /*0x14f792*/
        *a6 = v14; /*0x14f797*/
        *a7 = v21; /*0x14f79c*/
        return 0; /*0x14f79e*/
      }
      _InterlockedExchange((volatile __int32 *)v14, 0); /*0x14f678*/
      v18 = *(_DWORD *)a3; /*0x14f67a*/
      if ( (*(_DWORD *)a3 & 0x10000) != 0 ) /*0x14f682*/
      {
        if ( (v18 & 0x200000) != 0 ) /*0x14f68a*/
        {
          v18 &= ~0x200000u; /*0x14f68c*/
          ipc_marequest_cancel((unsigned int)a1, a2); /*0x14f69a*/
        }
        ipc_hash_delete((int)a1, v14, a2, a3); /*0x14f6ac*/
      }
      ipc_object_release(v14); /*0x14f6b5*/
      if ( (v18 & 0x400000) != 0 ) /*0x14f6c3*/
      {
        *(_DWORD *)(a3 + 8) = 0; /*0x14f6c5*/
        *(_DWORD *)(a3 + 4) = 0; /*0x14f6cc*/
        ipc_entry_dealloc(a1, a2, (int *)a3); /*0x14f6dc*/
      }
      else
      {
        v19 = v18 & 0xFFE0FFFF | 0x100000; /*0x14f6f5*/
        if ( *(_DWORD *)(a3 + 8) ) /*0x14f6fb*/
        {
          *(_DWORD *)(a3 + 8) = 0; /*0x14f701*/
          ++v19; /*0x14f708*/
        }
        *(_DWORD *)a3 = v19; /*0x14f709*/
        *(_DWORD *)(a3 + 4) = 0; /*0x14f70b*/
      }
      if ( (v24 & 0x400000) != 0 ) /*0x14f724*/
        return 15; /*0x14f724*/
      v24 = *(_DWORD *)a3; /*0x14f72c*/
LABEL_107:
      if ( a5 ) /*0x14f7b8*/
      {
        if ( (_WORD)v24 == 1 ) /*0x14f7bf*/
          *(_DWORD *)a3 = v24 & 0xFFEFFFFF; /*0x14f7ca*/
        else
          *(_DWORD *)a3 = v24 - 1; /*0x14f7d4*/
        goto LABEL_111; /*0x14f7cc*/
      }
      return 17; /*0x14f7b8*/
    case 19: /*0x14f1d8*/
      if ( (v24 & 0x100000) != 0 ) /*0x14f351*/
        goto LABEL_105; /*0x14f351*/
      if ( (*(_DWORD *)a3 & 0x50000) == 0 ) /*0x14f35d*/
        return 17; /*0x14f35d*/
      v7 = *(_DWORD *)(a3 + 4); /*0x14f363*/
      do /*0x14f37a*/
      {
        while ( *(_DWORD *)v7 ) /*0x14f368*/
          ; /*0x14f36a*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v7, 1) == 1 ); /*0x14f37a*/
      if ( *(int *)(v7 + 8) < 0 ) /*0x14f380*/
      {
        if ( (v24 & 0x10000) != 0 ) /*0x14f445*/
        {
LABEL_46:
          ++*(_DWORD *)(v7 + 28); /*0x14f450*/
          ++*(_DWORD *)(v7 + 4); /*0x14f453*/
          _InterlockedExchange((volatile __int32 *)v7, 0); /*0x14f458*/
          *a6 = v7; /*0x14f45d*/
          goto LABEL_112; /*0x14f45f*/
        }
        _InterlockedExchange((volatile __int32 *)v7, 0); /*0x14f449*/
        return 17; /*0x14f7f1*/
      }
      _InterlockedExchange((volatile __int32 *)v7, 0); /*0x14f388*/
      v12 = *(_DWORD *)a3; /*0x14f38a*/
      if ( (*(_DWORD *)a3 & 0x10000) != 0 ) /*0x14f392*/
      {
        if ( (v12 & 0x200000) != 0 ) /*0x14f39a*/
        {
          v12 &= ~0x200000u; /*0x14f39c*/
          ipc_marequest_cancel((unsigned int)a1, a2); /*0x14f3aa*/
        }
        ipc_hash_delete((int)a1, v7, a2, a3); /*0x14f3bc*/
      }
      ipc_object_release(v7); /*0x14f3c5*/
      if ( (v12 & 0x400000) != 0 ) /*0x14f3d3*/
      {
        *(_DWORD *)(a3 + 8) = 0; /*0x14f3d5*/
        *(_DWORD *)(a3 + 4) = 0; /*0x14f3dc*/
        ipc_entry_dealloc(a1, a2, (int *)a3); /*0x14f3ec*/
      }
      else
      {
        v13 = v12 & 0xFFE0FFFF | 0x100000; /*0x14f401*/
        if ( *(_DWORD *)(a3 + 8) ) /*0x14f407*/
        {
          *(_DWORD *)(a3 + 8) = 0; /*0x14f40d*/
          ++v13; /*0x14f414*/
        }
        *(_DWORD *)a3 = v13; /*0x14f415*/
        *(_DWORD *)(a3 + 4) = 0; /*0x14f417*/
      }
      if ( (v24 & 0x400000) != 0 ) /*0x14f430*/
        return 15; /*0x14f7f4*/
LABEL_105:
      if ( !a5 ) /*0x14f7b0*/
        return 17; /*0x14f7b0*/
LABEL_111:
      *a6 = -1; /*0x14f7d6*/
LABEL_112:
      *a7 = 0; /*0x14f7df*/
      return 0;
    case 20: /*0x14f1d8*/
      if ( (v24 & 0x20000) == 0 ) /*0x14f201*/
        return 17; /*0x14f201*/
      v7 = *(_DWORD *)(a3 + 4); /*0x14f207*/
      do /*0x14f21e*/
      {
        while ( *(_DWORD *)v7 ) /*0x14f20c*/
          ; /*0x14f20e*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v7, 1) == 1 ); /*0x14f21e*/
      ++*(_DWORD *)(v7 + 24); /*0x14f220*/
      goto LABEL_46; /*0x14f223*/
    case 21: /*0x14f1d8*/
      if ( (v24 & 0x20000) == 0 ) /*0x14f231*/
        return 17; /*0x14f231*/
      v8 = *(_DWORD *)(a3 + 4); /*0x14f237*/
      do /*0x14f24e*/
      {
        while ( *(_DWORD *)v8 ) /*0x14f23c*/
          ; /*0x14f23e*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v8, 1) == 1 ); /*0x14f24e*/
      ++*(_DWORD *)(v8 + 32); /*0x14f250*/
      ++*(_DWORD *)(v8 + 4); /*0x14f253*/
      _InterlockedExchange((volatile __int32 *)v8, 0); /*0x14f258*/
      *a6 = v8; /*0x14f25d*/
      *a7 = 0; /*0x14f262*/
      return 0; /*0x14f268*/
    default:
      panic(aIpcRightCopyin_0); /*0x14f7a5*/
      return result; /*0x14f7a5*/
  }
}
