/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1477c0. */
int __cdecl ipc_kmsg_copyin_header(unsigned int *a1, int a2, unsigned int a3)
{
  unsigned int v3; // eax
  volatile __int32 *v4; // edx
  unsigned __int64 v5; // kr00_8
  unsigned int v6; // edx
  unsigned int v7; // eax
  volatile __int32 *v8; // edx
  unsigned __int64 v9; // kr08_8
  _DWORD *v10; // ebx
  unsigned __int64 v11; // kr10_8
  _DWORD *v12; // ebx
  unsigned int v13; // edx
  volatile __int32 *v15; // edx
  unsigned __int64 v16; // rcx
  volatile __int32 *v17; // edx
  int *v18; // eax
  int *v19; // eax
  int *v20; // ebx
  int *v21; // ebx
  int v22; // ebx
  int v23; // edx
  _DWORD *v24; // [esp+Ch] [ebp-48h]
  unsigned int v25; // [esp+Ch] [ebp-48h]
  _DWORD *v26; // [esp+Ch] [ebp-48h]
  _BOOL4 v27; // [esp+Ch] [ebp-48h]
  int v28; // [esp+10h] [ebp-44h]
  int *v29; // [esp+10h] [ebp-44h]
  int v30; // [esp+14h] [ebp-40h]
  int *v31; // [esp+18h] [ebp-3Ch]
  int v32; // [esp+1Ch] [ebp-38h]
  int v33; // [esp+20h] [ebp-34h]
  int v34; // [esp+24h] [ebp-30h]
  unsigned int v35; // [esp+30h] [ebp-24h]
  unsigned int v36; // [esp+34h] [ebp-20h]
  unsigned int v37; // [esp+38h] [ebp-1Ch]
  unsigned int v38; // [esp+3Ch] [ebp-18h]
  int v39; // [esp+40h] [ebp-14h] BYREF
  int v40; // [esp+44h] [ebp-10h] BYREF
  int v41; // [esp+48h] [ebp-Ch] BYREF
  int v42; // [esp+4Ch] [ebp-8h] BYREF
  int v43; // [esp+50h] [ebp-4h] BYREF

  v38 = *a1 & 0xBFFFFFFF; /*0x1477d9*/
  v37 = a1[2]; /*0x1477df*/
  v36 = a1[3]; /*0x1477e8*/
  if ( !a3 ) /*0x1477ef*/
  {
    v3 = (unsigned __int16)*a1; /*0x1477f5*/
    if ( v3 == 19 ) /*0x1477fd*/
    {
      if ( v36 ) /*0x147824*/
        goto LABEL_52; /*0x147824*/
      v4 = (volatile __int32 *)(a2 + 8); /*0x14782a*/
      do /*0x147842*/
      {
        while ( *v4 ) /*0x147830*/
          ; /*0x147832*/
      }
      while ( _InterlockedExchange(v4, 1) == 1 ); /*0x147842*/
      if ( !*(_DWORD *)(a2 + 12) ) /*0x147844*/
        goto LABEL_51; /*0x147844*/
      v5 = (unsigned __int64)v37 << 24; /*0x147857*/
      if ( *(_DWORD *)(a2 + 24) <= HIDWORD(v5) ) /*0x14785d*/
        goto LABEL_51; /*0x14785d*/
      v24 = (_DWORD *)(*(_DWORD *)(a2 + 20) + 16 * HIDWORD(v5)); /*0x147869*/
      if ( (*v24 & 0xFF010000) != ((unsigned int)v5 | 0x10000) ) /*0x14787d*/
        goto LABEL_51; /*0x14787d*/
      v6 = v24[1]; /*0x147886*/
      do /*0x14789e*/
      {
        while ( *(_DWORD *)v6 ) /*0x14788c*/
          ; /*0x14788e*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v6, 1) == 1 ); /*0x14789e*/
      _InterlockedExchange((volatile __int32 *)(a2 + 8), 0); /*0x1478a2*/
      if ( *(int *)(v6 + 8) < 0 ) /*0x1478a9*/
      {
        ++*(_DWORD *)(v6 + 28); /*0x1478b4*/
        ++*(_DWORD *)(v6 + 4); /*0x1478b7*/
        _InterlockedExchange((volatile __int32 *)v6, 0); /*0x1478bc*/
        v7 = v38 & 0xFFFF0000; /*0x1478c1*/
        LOBYTE(v7) = 17; /*0x1478c6*/
LABEL_49:
        *a1 = v7; /*0x147ab2*/
        a1[2] = v6; /*0x147ab7*/
        return 0; /*0x147abc*/
      }
      _InterlockedExchange((volatile __int32 *)v6, 0); /*0x1478ad*/
    }
    else if ( v3 > 0x13 ) /*0x1477ff*/
    {
      if ( v3 == 5395 ) /*0x147815*/
      {
        v8 = (volatile __int32 *)(a2 + 8); /*0x1478d0*/
        do /*0x1478e6*/
        {
          while ( *v8 ) /*0x1478d4*/
            ; /*0x1478d6*/
        }
        while ( _InterlockedExchange(v8, 1) == 1 ); /*0x1478e6*/
        if ( *(_DWORD *)(a2 + 12) ) /*0x1478e8*/
        {
          v35 = *(_DWORD *)(a2 + 24); /*0x1478f5*/
          v9 = (unsigned __int64)v37 << 24; /*0x147907*/
          if ( v35 > HIDWORD(v9) ) /*0x147910*/
          {
            v10 = (_DWORD *)(16 * HIDWORD(v9) + *(_DWORD *)(a2 + 20)); /*0x14791b*/
            if ( (*v10 & 0xFF010000) == ((unsigned int)v9 | 0x10000) ) /*0x14792e*/
            {
              v25 = v10[1]; /*0x147937*/
              v11 = (unsigned __int64)v36 << 24; /*0x147943*/
              if ( v35 > HIDWORD(v11) ) /*0x14794c*/
              {
                v12 = (_DWORD *)(16 * HIDWORD(v11) + *(_DWORD *)(a2 + 20)); /*0x147958*/
                if ( (*v12 & 0xFF020000) == ((unsigned int)v11 | 0x20000) ) /*0x14796b*/
                {
                  v13 = v12[1]; /*0x147971*/
                  do /*0x14798c*/
                  {
                    while ( *(_DWORD *)v25 ) /*0x147977*/
                      ; /*0x147979*/
                  }
                  while ( _InterlockedExchange((volatile __int32 *)v25, 1) == 1 ); /*0x14798c*/
                  if ( *(int *)(v25 + 8) < 0 && _InterlockedExchange((volatile __int32 *)v13, 1) != 1 ) /*0x14799b*/
                  {
                    _InterlockedExchange((volatile __int32 *)(a2 + 8), 0); /*0x1479b2*/
                    ++*(_DWORD *)(v25 + 28); /*0x1479b8*/
                    ++*(_DWORD *)(v25 + 4); /*0x1479bb*/
                    _InterlockedExchange((volatile __int32 *)v25, 0); /*0x1479c0*/
                    ++*(_DWORD *)(v13 + 32); /*0x1479c2*/
                    ++*(_DWORD *)(v13 + 4); /*0x1479c5*/
                    _InterlockedExchange((volatile __int32 *)v13, 0); /*0x1479ca*/
                    *a1 = v38 & 0xFFFF0000 | 0x1211; /*0x1479dc*/
                    a1[2] = v25; /*0x1479de*/
                    a1[3] = v13; /*0x1479e1*/
                    return 0; /*0x1479e6*/
                  }
                  _InterlockedExchange((volatile __int32 *)v25, 0); /*0x1479a7*/
                }
              }
            }
          }
        }
LABEL_51:
        _InterlockedExchange((volatile __int32 *)(a2 + 8), 0); /*0x147ac8*/
      }
    }
    else if ( v3 == 18 && !v36 ) /*0x1479f0*/
    {
      v15 = (volatile __int32 *)(a2 + 8); /*0x1479f6*/
      do /*0x147a0e*/
      {
        while ( *v15 ) /*0x1479fc*/
          ; /*0x1479fe*/
      }
      while ( _InterlockedExchange(v15, 1) == 1 ); /*0x147a0e*/
      if ( *(_DWORD *)(a2 + 12) ) /*0x147a10*/
      {
        v28 = *(_DWORD *)(a2 + 20); /*0x147a1d*/
        v16 = (unsigned __int64)v37 << 24; /*0x147a29*/
        if ( *(_DWORD *)(a2 + 24) > HIDWORD(v16) ) /*0x147a32*/
        {
          v26 = (_DWORD *)(*(_DWORD *)(a2 + 20) + 16 * HIDWORD(v16)); /*0x147a3f*/
          if ( (*v26 & 0xFF840000) == ((unsigned int)v16 | 0x40000) && !v26[2] ) /*0x147a58*/
          {
            v6 = v26[1]; /*0x147a5e*/
            do /*0x147a76*/
            {
              while ( *(_DWORD *)v6 ) /*0x147a64*/
                ; /*0x147a66*/
            }
            while ( _InterlockedExchange((volatile __int32 *)v6, 1) == 1 ); /*0x147a76*/
            if ( *(int *)(v6 + 8) < 0 ) /*0x147a7c*/
            {
              _InterlockedExchange((volatile __int32 *)v6, 0); /*0x147a80*/
              v26[2] = *(_DWORD *)(v28 + 8); /*0x147a8b*/
              *(_DWORD *)(v28 + 8) = HIDWORD(v16); /*0x147a91*/
              *v26 = v37 << 24; /*0x147a9a*/
              v26[1] = 0; /*0x147a9c*/
              _InterlockedExchange((volatile __int32 *)(a2 + 8), 0); /*0x147aa5*/
              v7 = v38 & 0xFFFF0000; /*0x147aab*/
              LOBYTE(v7) = 18; /*0x147ab0*/
              goto LABEL_49; /*0x147ab0*/
            }
            _InterlockedExchange((volatile __int32 *)v6, 0); /*0x147ac6*/
          }
        }
      }
      goto LABEL_51; /*0x147ac6*/
    }
  }
LABEL_52:
  v33 = (unsigned __int16)(v38 & 0xFF00) >> 8; /*0x147acd*/
  v32 = 0; /*0x147ae2*/
  if ( (unsigned int)(unsigned __int8)v38 - 17 > 4 ) /*0x147af1*/
    return 268435472; /*0x147af1*/
  if ( !v33 ) /*0x147af7*/
  {
    if ( !v36 ) /*0x147afd*/
      goto LABEL_58; /*0x147afd*/
    return 268435472; /*0x147b14*/
  }
  if ( (unsigned int)(v33 - 17) > 4 ) /*0x147b0d*/
    return 268435472; /*0x147b0d*/
LABEL_58:
  v17 = (volatile __int32 *)(a2 + 8); /*0x147b1c*/
  do /*0x147b32*/
  {
    while ( *v17 ) /*0x147b20*/
      ; /*0x147b22*/
  }
  while ( _InterlockedExchange(v17, 1) == 1 ); /*0x147b32*/
  if ( !*(_DWORD *)(a2 + 12) ) /*0x147b38*/
    goto LABEL_135; /*0x147b38*/
  if ( a3 ) /*0x147b42*/
  {
    v18 = ipc_entry_lookup((_DWORD *)a2, a3); /*0x147b49*/
    if ( !v18 || (*((_BYTE *)v18 + 2) & 2) == 0 ) /*0x147b59*/
    {
      _InterlockedExchange((volatile __int32 *)(a2 + 8), 0); /*0x147b5d*/
      return 268435467; /*0x147b65*/
    }
    v32 = v18[1]; /*0x147b6f*/
  }
  if ( v37 == v36 ) /*0x147b78*/
  {
    v19 = ipc_entry_lookup((_DWORD *)a2, v36); /*0x147b83*/
    v20 = v19; /*0x147b88*/
    if ( !v19 ) /*0x147b8f*/
      goto LABEL_135; /*0x147b8f*/
    if ( ipc_right_copyin_check(a2, v36, v19, v33) ) /*0x147b9f*/
    {
      if ( (unsigned __int8)v38 != 18 && v33 != 18 ) /*0x147bbc*/
      {
        if ( (unsigned int)(unsigned __int8)v38 - 20 > 1 && (unsigned int)(v33 - 20) > 1 ) /*0x147bd6*/
        {
          if ( (unsigned __int8)v38 == 19 && v33 == 19 ) /*0x147c2a*/
          {
            if ( !ipc_right_copyin(a2, v36, v20, 19, 0, &v43, &v42) ) /*0x147c3e*/
            {
              v41 = ipc_port_copy_send(v43); /*0x147c57*/
              v40 = 0; /*0x147c5a*/
LABEL_127:
              if ( a3 && v32 == v42 ) /*0x147f67*/
              {
                ipc_port_release_sonce(v42); /*0x147f6a*/
                v42 = 0; /*0x147f6f*/
              }
              _InterlockedExchange((volatile __int32 *)(a2 + 8), 0); /*0x147f7b*/
              if ( v42 ) /*0x147f83*/
                ipc_notify_port_deleted(v42, v37); /*0x147f8a*/
              if ( v40 ) /*0x147f97*/
                ipc_notify_port_deleted(v40, v36); /*0x147f9e*/
              v34 = ipc_object_copyin_type((unsigned __int8)v38); /*0x147faf*/
              *a1 = v34 | (ipc_object_copyin_type(v33) << 8) | v38 & 0xFFFF0000; /*0x147fd4*/
              a1[2] = v43; /*0x147fd9*/
              a1[3] = v41; /*0x147fdf*/
              return 0; /*0x147fe4*/
            }
          }
          else if ( (unsigned __int8)v38 == 17 && v33 == 17 ) /*0x147c72*/
          {
            if ( !ipc_right_copyin_two(a2, v36, v20, &v43, &v42) ) /*0x147c82*/
            {
              if ( (*((_BYTE *)v20 + 2) & 0x1F) == 0 ) /*0x147c96*/
                ipc_entry_dealloc((_DWORD *)a2, v36, v20); /*0x147c9b*/
              v41 = v43; /*0x147ca6*/
              v40 = 0; /*0x147ca9*/
              goto LABEL_127; /*0x147cb0*/
            }
          }
          else if ( !ipc_right_copyin(a2, v36, v20, 17, 0, &v43, &v39) ) /*0x147cca*/
          {
            if ( (*((_BYTE *)v20 + 2) & 0x1F) == 0 ) /*0x147cde*/
              ipc_entry_dealloc((_DWORD *)a2, v36, v20); /*0x147ce3*/
            v41 = ipc_port_copy_send(v43); /*0x147cf4*/
            if ( (unsigned __int8)v38 == 17 ) /*0x147cfe*/
            {
              v42 = v39; /*0x147d03*/
              v40 = 0; /*0x147d06*/
            }
            else
            {
              v42 = 0; /*0x147d14*/
              v40 = v39; /*0x147d1e*/
            }
            goto LABEL_127; /*0x147d0d*/
          }
        }
        else if ( !ipc_right_copyin(a2, v36, v20, (unsigned __int8)v38, 0, &v43, &v42) ) /*0x147bec*/
        {
          ipc_right_copyin(a2, v36, v20, v33, 1, &v41, &v40); /*0x147c10*/
          goto LABEL_127; /*0x147c18*/
        }
      }
LABEL_135:
      _InterlockedExchange((volatile __int32 *)(a2 + 8), 0); /*0x147fe8*/
      return 268435459; /*0x147ff2*/
    }
    goto LABEL_136; /*0x147ba9*/
  }
  if ( !v36 || v36 == -1 ) /*0x147d32*/
  {
    v21 = ipc_entry_lookup((_DWORD *)a2, v37); /*0x147d3e*/
    if ( v21 && !ipc_right_copyin(a2, v37, v21, (unsigned __int8)v38, 0, &v43, &v42) ) /*0x147d5c*/
    {
      if ( (*((_BYTE *)v21 + 2) & 0x1F) == 0 ) /*0x147d70*/
        ipc_entry_dealloc((_DWORD *)a2, v37, v21); /*0x147d75*/
      v41 = v36; /*0x147d80*/
      v40 = 0; /*0x147d83*/
      goto LABEL_127; /*0x147d8a*/
    }
    goto LABEL_135; /*0x147d66*/
  }
  v31 = ipc_entry_lookup((_DWORD *)a2, v37); /*0x147d9a*/
  if ( !v31 ) /*0x147da2*/
    goto LABEL_135; /*0x147da2*/
  v29 = ipc_entry_lookup((_DWORD *)a2, v36); /*0x147db2*/
  if ( !v29 || !ipc_right_copyin_check(a2, v36, v29, v33) ) /*0x147dcd*/
  {
LABEL_136:
    _InterlockedExchange((volatile __int32 *)(a2 + 8), 0); /*0x147ff4*/
    return 268435465; /*0x147ff9*/
  }
  if ( ipc_right_copyin(a2, v37, v31, (unsigned __int8)v38, 0, &v43, &v42) ) /*0x147df4*/
    goto LABEL_135; /*0x147dfe*/
  v22 = v29[1]; /*0x147e07*/
  if ( v22 ) /*0x147e0c*/
    ipc_object_reference(v29[1]); /*0x147e0f*/
  if ( ipc_right_copyin(a2, v36, v29, v33, 1, &v41, &v40) ) /*0x147e2e*/
  {
    v41 = -1; /*0x147e3a*/
    v40 = 0; /*0x147e41*/
LABEL_123:
    if ( (*((_BYTE *)v31 + 2) & 0x1F) == 0 ) /*0x147f3e*/
      ipc_entry_dealloc((_DWORD *)a2, v37, v31); /*0x147f46*/
    if ( v22 ) /*0x147f50*/
      ipc_object_release(v22); /*0x147f53*/
    goto LABEL_127; /*0x147f53*/
  }
  if ( !v22 || v41 != -1 ) /*0x147e5c*/
    goto LABEL_121; /*0x147e5c*/
  v23 = v43; /*0x147e62*/
  do /*0x147e7a*/
  {
    while ( *(_DWORD *)v22 ) /*0x147e68*/
      ; /*0x147e6a*/
  }
  while ( _InterlockedExchange((volatile __int32 *)v22, 1) == 1 ); /*0x147e7a*/
  v30 = *(_DWORD *)(v22 + 12); /*0x147e7f*/
  _InterlockedExchange((volatile __int32 *)v22, 0); /*0x147e84*/
  do /*0x147e9a*/
  {
    while ( *(_DWORD *)v23 ) /*0x147e88*/
      ; /*0x147e8a*/
  }
  while ( _InterlockedExchange((volatile __int32 *)v23, 1) == 1 ); /*0x147e9a*/
  v27 = 0; /*0x147e9c*/
  if ( *(int *)(v23 + 8) >= 0 ) /*0x147ea7*/
    v27 = *(_DWORD *)(v23 + 12) - v30 < 0; /*0x147eb1*/
  _InterlockedExchange((volatile __int32 *)v23, 0); /*0x147eb6*/
  if ( !v27 ) /*0x147ebc*/
  {
LABEL_121:
    if ( (*((_BYTE *)v29 + 2) & 0x1F) == 0 ) /*0x147f27*/
      ipc_entry_dealloc((_DWORD *)a2, v36, v29); /*0x147f2f*/
    goto LABEL_123; /*0x147f2f*/
  }
  ipc_right_copyin_undo(a2, v37, v31, (unsigned __int8)v38, v43, v42); /*0x147ed3*/
  ipc_right_copyin_undo(a2, v36, v29, v33, v41, v40); /*0x147eed*/
  _InterlockedExchange((volatile __int32 *)(a2 + 8), 0); /*0x147ef7*/
  if ( v42 ) /*0x147eff*/
    ipc_notify_dead_name(v42, v37); /*0x147f06*/
  ipc_object_release(v22); /*0x147f0f*/
  return 268435459; /*0x148001*/
}
