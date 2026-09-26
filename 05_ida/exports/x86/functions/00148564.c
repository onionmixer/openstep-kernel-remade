/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x148564. */
int __cdecl ipc_kmsg_copyout_header(unsigned int *a1, int a2, unsigned int a3)
{
  unsigned int v3; // ecx
  unsigned int v4; // esi
  unsigned int v5; // ebx
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  unsigned int v9; // eax
  int v10; // ecx
  volatile __int32 *v11; // edx
  int v12; // edx
  int *v13; // eax
  unsigned int v14; // ebx
  int v15; // eax
  int v16; // ecx
  int v17; // eax
  unsigned int *v18; // edi
  unsigned int v19; // ecx
  unsigned int v20; // edx
  unsigned int v21; // eax
  int v22; // ebx
  volatile __int32 *v23; // edx
  int v25; // ecx
  int v26; // eax
  volatile __int32 *v27; // edx
  volatile __int32 *v28; // edx
  int *v29; // eax
  volatile __int32 *v30; // edx
  int *v31; // eax
  int v32; // edi
  int v33; // [esp+Ch] [ebp-28h]
  int v34; // [esp+Ch] [ebp-28h]
  int v35; // [esp+10h] [ebp-24h]
  int v36; // [esp+14h] [ebp-20h]
  unsigned int v37; // [esp+1Ch] [ebp-18h]
  unsigned int v38; // [esp+20h] [ebp-14h]
  int v39; // [esp+24h] [ebp-10h] BYREF
  int v40; // [esp+28h] [ebp-Ch] BYREF
  int *v41; // [esp+2Ch] [ebp-8h] BYREF
  unsigned int v42; // [esp+30h] [ebp-4h] BYREF

  v3 = *a1; /*0x148570*/
  v38 = *a1; /*0x148572*/
  v4 = a1[2]; /*0x148578*/
  if ( a3 ) /*0x14857f*/
    goto LABEL_49; /*0x14857f*/
  if ( (unsigned __int16)v3 == 18 ) /*0x14858b*/
  {
    do /*0x14878a*/
    {
      while ( *(_DWORD *)v4 ) /*0x148778*/
        ; /*0x14877a*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v4, 1) == 1 ); /*0x14878a*/
    if ( *(int *)(v4 + 8) < 0 ) /*0x148790*/
    {
      if ( *(_DWORD *)(v4 + 12) == a2 ) /*0x14879e*/
      {
        --*(_DWORD *)(v4 + 4); /*0x1487a0*/
        --*(_DWORD *)(v4 + 32); /*0x1487a3*/
        v20 = *(_DWORD *)(v4 + 16); /*0x1487a6*/
        _InterlockedExchange((volatile __int32 *)v4, 0); /*0x1487ab*/
      }
      else
      {
        _InterlockedExchange((volatile __int32 *)v4, 0); /*0x1487b2*/
        ipc_notify_send_once(v4); /*0x1487b5*/
        v20 = 0; /*0x1487ba*/
      }
      v21 = v38 & 0xFFFF0000; /*0x1487bf*/
      BYTE1(v21) = 18; /*0x1487c4*/
      *a1 = v21; /*0x1487ca*/
      a1[3] = v20; /*0x1487cc*/
      a1[2] = 0; /*0x1487cf*/
      return 0; /*0x1487d6*/
    }
    goto LABEL_43; /*0x148790*/
  }
  if ( (unsigned __int16)v3 <= 0x12u ) /*0x148591*/
  {
    if ( (unsigned __int16)v3 != 17 ) /*0x148596*/
    {
LABEL_49:
      v36 = (unsigned __int16)(v38 & 0xFF00) >> 8; /*0x1487e8*/
      v22 = a1[3]; /*0x148800*/
      if ( !v22 || v22 == -1 ) /*0x14880e*/
      {
        v30 = (volatile __int32 *)(a2 + 8); /*0x148aa3*/
        do /*0x148aba*/
        {
          while ( *v30 ) /*0x148aa8*/
            ; /*0x148aaa*/
        }
        while ( _InterlockedExchange(v30, 1) == 1 ); /*0x148aba*/
        if ( !*(_DWORD *)(a2 + 12) ) /*0x148abf*/
        {
          _InterlockedExchange((volatile __int32 *)(a2 + 8), 0); /*0x148ac7*/
          return 268460043; /*0x148acf*/
        }
        if ( a3 ) /*0x148ad8*/
        {
          v31 = ipc_entry_lookup((_DWORD *)a2, a3); /*0x148ae2*/
          if ( !v31 || (*((_BYTE *)v31 + 2) & 2) == 0 ) /*0x148af2*/
          {
            _InterlockedExchange((volatile __int32 *)(a2 + 8), 0); /*0x148af9*/
            return 268451847; /*0x148b01*/
          }
        }
        do /*0x148b1a*/
        {
          while ( *(_DWORD *)v4 ) /*0x148b08*/
            ; /*0x148b0a*/
        }
        while ( _InterlockedExchange((volatile __int32 *)v4, 1) == 1 ); /*0x148b1a*/
        _InterlockedExchange((volatile __int32 *)(a2 + 8), 0); /*0x148b21*/
        v42 = v22; /*0x148b24*/
      }
      else
      {
        v23 = (volatile __int32 *)(a2 + 8); /*0x148817*/
        do /*0x14882e*/
        {
          while ( *v23 ) /*0x14881c*/
            ; /*0x14881e*/
        }
        while ( _InterlockedExchange(v23, 1) == 1 ); /*0x14882e*/
        while ( 1 ) /*0x148830*/
        {
          if ( !*(_DWORD *)(a2 + 12) ) /*0x148837*/
          {
            _InterlockedExchange((volatile __int32 *)(a2 + 8), 0); /*0x148bc5*/
            return 268460043; /*0x148bcd*/
          }
          if ( a3 ) /*0x148841*/
          {
            v33 = ipc_port_lookup_notify(a2, a3); /*0x14884d*/
            if ( !v33 ) /*0x148855*/
            {
              _InterlockedExchange((volatile __int32 *)(a2 + 8), 0); /*0x148859*/
              return 268451847; /*0x148861*/
            }
          }
          else
          {
            v33 = 0; /*0x148868*/
          }
          if ( v36 != 18 && ipc_right_reverse(a2, v22, &v42, &v41) ) /*0x148882*/
            break; /*0x148882*/
          do /*0x1488a6*/
          {
            while ( *(_DWORD *)v22 ) /*0x148894*/
              ; /*0x148896*/
          }
          while ( _InterlockedExchange((volatile __int32 *)v22, 1) == 1 ); /*0x1488a6*/
          if ( *(int *)(v22 + 8) >= 0 ) /*0x1488ac*/
          {
            v25 = *(_DWORD *)(v22 + 4) - 1; /*0x1488b1*/
            *(_DWORD *)(v22 + 4) = v25; /*0x1488b4*/
            _InterlockedExchange((volatile __int32 *)v22, 0); /*0x1488ba*/
            if ( !v25 ) /*0x1488be*/
              zfree(ipc_object_zones[*(_WORD *)(v22 + 10) & 0x7FFF], v22); /*0x1488d2*/
            if ( v33 ) /*0x1488de*/
              ipc_port_release_sonce(v33); /*0x1488e4*/
            do /*0x1488fe*/
            {
              while ( *(_DWORD *)v4 ) /*0x1488ec*/
                ; /*0x1488ee*/
            }
            while ( _InterlockedExchange((volatile __int32 *)v4, 1) == 1 ); /*0x1488fe*/
            _InterlockedExchange((volatile __int32 *)(a2 + 8), 0); /*0x148905*/
            v22 = -1; /*0x148908*/
            v42 = -1; /*0x14890d*/
            goto LABEL_110; /*0x148914*/
          }
          if ( ipc_entry_get(a2, &v42, &v41) ) /*0x148928*/
          {
            _InterlockedExchange((volatile __int32 *)v22, 0); /*0x148936*/
            if ( v33 ) /*0x14893c*/
              ipc_port_release_sonce(v33); /*0x148942*/
            v26 = ipc_entry_grow_table(a2); /*0x14894e*/
            if ( v26 ) /*0x148958*/
            {
              if ( v26 != 6 ) /*0x148961*/
                return 268460043; /*0x14896c*/
              return 268453899; /*0x148bd5*/
            }
          }
          else
          {
            if ( !v33 ) /*0x148978*/
            {
              v41[1] = v22; /*0x1487df*/
              break; /*0x1487e2*/
            }
            if ( !ipc_port_dnrequest(v22, v42, v33, &v40) ) /*0x148995*/
            {
              v33 = 0; /*0x148a38*/
              v29 = v41; /*0x148a3f*/
              v41[1] = v22; /*0x148a42*/
              v29[2] = v40; /*0x148a48*/
              break; /*0x148a48*/
            }
            _InterlockedExchange((volatile __int32 *)v22, 0); /*0x14899d*/
            ipc_port_release_sonce(v33); /*0x1489a3*/
            ipc_entry_dealloc((_DWORD *)a2, v42, v41); /*0x1489b4*/
            _InterlockedExchange((volatile __int32 *)(a2 + 8), 0); /*0x1489be*/
            do /*0x1489d6*/
            {
              while ( *(_DWORD *)v22 ) /*0x1489c4*/
                ; /*0x1489c6*/
            }
            while ( _InterlockedExchange((volatile __int32 *)v22, 1) == 1 ); /*0x1489d6*/
            if ( *(int *)(v22 + 8) < 0 ) /*0x1489dc*/
            {
              if ( ipc_port_dngrow(v22) ) /*0x148a05*/
                return 268453899; /*0x148a0f*/
              v28 = (volatile __int32 *)(a2 + 8); /*0x148a18*/
              do /*0x148a2e*/
              {
                while ( *v28 ) /*0x148a1c*/
                  ; /*0x148a1e*/
              }
              while ( _InterlockedExchange(v28, 1) == 1 ); /*0x148a2e*/
            }
            else
            {
              _InterlockedExchange((volatile __int32 *)v22, 0); /*0x1489e0*/
              v27 = (volatile __int32 *)(a2 + 8); /*0x1489e5*/
              do /*0x1489fa*/
              {
                while ( *v27 ) /*0x1489e8*/
                  ; /*0x1489ea*/
              }
              while ( _InterlockedExchange(v27, 1) == 1 ); /*0x1489fa*/
            }
          }
        }
        ++*(_DWORD *)(v22 + 4); /*0x148a4b*/
        ipc_right_copyout(a2, v42, v41, v36, 1, v22); /*0x148a61*/
        if ( v33 ) /*0x148a6d*/
          ipc_port_release_sonce(v33); /*0x148a73*/
        do /*0x148a8e*/
        {
          while ( *(_DWORD *)v4 ) /*0x148a7c*/
            ; /*0x148a7e*/
        }
        while ( _InterlockedExchange((volatile __int32 *)v4, 1) == 1 ); /*0x148a8e*/
        _InterlockedExchange((volatile __int32 *)(a2 + 8), 0); /*0x148a95*/
      }
LABEL_110:
      if ( *(int *)(v4 + 8) >= 0 ) /*0x148b2b*/
      {
        v34 = *(_DWORD *)(v4 + 12); /*0x148b4b*/
        v32 = *(_DWORD *)(v4 + 4) - 1; /*0x148b51*/
        *(_DWORD *)(v4 + 4) = v32; /*0x148b54*/
        _InterlockedExchange((volatile __int32 *)v4, 0); /*0x148b5a*/
        if ( !v32 ) /*0x148b5e*/
          zfree(ipc_object_zones[*(_WORD *)(v4 + 10) & 0x7FFF], v4); /*0x148b72*/
        if ( !v22 || v22 == -1 ) /*0x148b81*/
        {
          v39 = -1; /*0x148bd8*/
        }
        else
        {
          do /*0x148b96*/
          {
            while ( *(_DWORD *)v22 ) /*0x148b84*/
              ; /*0x148b86*/
          }
          while ( _InterlockedExchange((volatile __int32 *)v22, 1) == 1 ); /*0x148b96*/
          if ( *(int *)(v22 + 8) >= 0 && v34 - *(_DWORD *)(v22 + 12) >= 0 ) /*0x148ba4*/
            v39 = 0; /*0x148bb0*/
          else
            v39 = -1; /*0x148ba6*/
          _InterlockedExchange((volatile __int32 *)v22, 0); /*0x148bb9*/
        }
      }
      else
      {
        ipc_object_copyout_dest(a2, v4, (unsigned __int8)v38, &v39); /*0x148b3a*/
      }
      if ( v22 ) /*0x148be1*/
      {
        if ( v22 != -1 ) /*0x148be6*/
          ipc_object_release(v22); /*0x148be9*/
      }
      v18 = a1; /*0x148c01*/
      *a1 = v36 | ((unsigned __int8)v38 << 8) | v38 & 0xFFFF0000; /*0x148c04*/
      a1[3] = v39; /*0x148c09*/
      v19 = v42; /*0x148c0c*/
      goto LABEL_130; /*0x148c0c*/
    }
    do /*0x1485c2*/
    {
      while ( *(_DWORD *)v4 ) /*0x1485b0*/
        ; /*0x1485b2*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v4, 1) == 1 ); /*0x1485c2*/
    if ( *(int *)(v4 + 8) < 0 ) /*0x1485c8*/
    {
      --*(_DWORD *)(v4 + 4); /*0x1485ce*/
      v5 = 0; /*0x1485d1*/
      if ( *(_DWORD *)(v4 + 12) == a2 ) /*0x1485d9*/
        v5 = *(_DWORD *)(v4 + 16); /*0x1485db*/
      v6 = *(_DWORD *)(v4 + 28); /*0x1485de*/
      *(_DWORD *)(v4 + 28) = v6 - 1; /*0x1485e4*/
      if ( v6 == 1 && (v7 = *(_DWORD *)(v4 + 36)) != 0 ) /*0x1485f4*/
      {
        *(_DWORD *)(v4 + 36) = 0; /*0x1485f6*/
        v8 = *(_DWORD *)(v4 + 24); /*0x1485fd*/
        _InterlockedExchange((volatile __int32 *)v4, 0); /*0x148602*/
        ipc_notify_no_senders(v7, v8); /*0x148606*/
      }
      else
      {
        _InterlockedExchange((volatile __int32 *)v4, 0); /*0x148612*/
      }
      v9 = v38 & 0xFFFF0000; /*0x148617*/
      BYTE1(v9) = 17; /*0x14861c*/
      *a1 = v9; /*0x148622*/
      a1[3] = v5; /*0x148624*/
      a1[2] = 0; /*0x148627*/
      return 0; /*0x14862e*/
    }
LABEL_43:
    _InterlockedExchange((volatile __int32 *)v4, 0); /*0x148792*/
    goto LABEL_49; /*0x148796*/
  }
  if ( (unsigned __int16)v3 != 4625 ) /*0x1485a5*/
    goto LABEL_49; /*0x1485a5*/
  v10 = a1[3]; /*0x148637*/
  if ( !v10 || v10 == -1 ) /*0x148648*/
    goto LABEL_49; /*0x148648*/
  v11 = (volatile __int32 *)(a2 + 8); /*0x148651*/
  do /*0x148666*/
  {
    while ( *v11 ) /*0x148654*/
      ; /*0x148656*/
  }
  while ( _InterlockedExchange(v11, 1) == 1 ); /*0x148666*/
  if ( !*(_DWORD *)(a2 + 12) || (v12 = *(_DWORD *)(a2 + 20), (v35 = *(_DWORD *)(v12 + 8)) == 0) ) /*0x14867c*/
  {
LABEL_32:
    _InterlockedExchange((volatile __int32 *)(a2 + 8), 0); /*0x1486bc*/
    goto LABEL_49; /*0x1486c4*/
  }
  do /*0x148692*/
  {
    while ( *(_DWORD *)v4 ) /*0x148680*/
      ; /*0x148682*/
  }
  while ( _InterlockedExchange((volatile __int32 *)v4, 1) == 1 ); /*0x148692*/
  if ( *(int *)(v4 + 8) >= 0 || _InterlockedExchange((volatile __int32 *)v10, 1) == 1 ) /*0x1486a4*/
  {
LABEL_31:
    _InterlockedExchange((volatile __int32 *)v4, 0); /*0x1486b8*/
    goto LABEL_32; /*0x1486ba*/
  }
  if ( *(int *)(v10 + 8) >= 0 ) /*0x1486b2*/
  {
    _InterlockedExchange((volatile __int32 *)v10, 0); /*0x1486b6*/
    goto LABEL_31; /*0x1486b6*/
  }
  _InterlockedExchange((volatile __int32 *)v10, 0); /*0x1486d1*/
  v13 = (int *)(v12 + 16 * v35); /*0x1486d9*/
  *(_DWORD *)(v12 + 8) = v13[2]; /*0x1486de*/
  v13[2] = 0; /*0x1486e1*/
  v37 = (v35 << 8) | ((unsigned int)(*v13 + 0x1000000) >> 24); /*0x1486fd*/
  *v13 = (*v13 + 0x1000000) | 0x40001; /*0x148706*/
  v13[1] = v10; /*0x14870b*/
  _InterlockedExchange((volatile __int32 *)(a2 + 8), 0); /*0x148713*/
  --*(_DWORD *)(v4 + 4); /*0x148716*/
  v14 = 0; /*0x148719*/
  if ( *(_DWORD *)(v4 + 12) == a2 ) /*0x14871e*/
    v14 = *(_DWORD *)(v4 + 16); /*0x148720*/
  v15 = *(_DWORD *)(v4 + 28); /*0x148723*/
  *(_DWORD *)(v4 + 28) = v15 - 1; /*0x148729*/
  if ( v15 == 1 && (v16 = *(_DWORD *)(v4 + 36)) != 0 ) /*0x148739*/
  {
    *(_DWORD *)(v4 + 36) = 0; /*0x14873b*/
    v17 = *(_DWORD *)(v4 + 24); /*0x148742*/
    _InterlockedExchange((volatile __int32 *)v4, 0); /*0x148747*/
    ipc_notify_no_senders(v16, v17); /*0x14874b*/
  }
  else
  {
    _InterlockedExchange((volatile __int32 *)v4, 0); /*0x148756*/
  }
  v18 = a1; /*0x148765*/
  *a1 = v38 & 0xFFFF0000 | 0x1112; /*0x148768*/
  a1[3] = v14; /*0x14876a*/
  v19 = v37; /*0x14876d*/
LABEL_130:
  v18[2] = v19; /*0x148c0f*/
  return 0; /*0x148c17*/
}
