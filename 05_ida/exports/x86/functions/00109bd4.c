/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x109bd4. */
int __cdecl issig(int a1)
{
  unsigned int v1; // edi
  volatile __int32 *v2; // edx
  int v3; // edx
  volatile __int32 *v4; // edx
  char v5; // al
  unsigned int v6; // edx
  int v8; // eax
  thread_act_t v9; // ebx
  int v10; // esi
  int v11; // edx
  int v12; // eax
  volatile __int32 *v13; // edx
  int v14; // edx
  int v15; // ebx
  int v16; // eax
  volatile __int32 *v17; // edx
  int v19; // [esp+Ch] [ebp-44h]
  int v20; // [esp+Ch] [ebp-44h]
  int v21; // [esp+10h] [ebp-40h]
  int v22; // [esp+14h] [ebp-3Ch]
  _BYTE v23[56]; // [esp+18h] [ebp-38h] BYREF

  v1 = *(_DWORD *)active_u; /*0x109be2*/
  if ( master_cpu ) /*0x109beb*/
    panic(aIssigNotOnMast); /*0x109bf2*/
  v2 = (volatile __int32 *)(v1 + 112); /*0x109bfa*/
  do /*0x109c12*/
  {
    while ( *v2 ) /*0x109c00*/
      ; /*0x109c02*/
  }
  while ( _InterlockedExchange(v2, 1) == 1 ); /*0x109c12*/
  while ( *(_DWORD *)(v1 + 116) || *(_DWORD *)(v1 + 120) ) /*0x109c72*/
  {
    _InterlockedExchange((volatile __int32 *)(v1 + 112), 0); /*0x109c1a*/
    v3 = *(_DWORD *)(v1 + 120); /*0x109c1d*/
    if ( v3 ) /*0x109c22*/
    {
      if ( active_threads == v3 ) /*0x109c2b*/
        return 0; /*0x10a048*/
      thread_hold(active_threads); /*0x109c32*/
    }
    thread_block(); /*0x109c3a*/
    if ( (*(_BYTE *)(active_threads + 380) & 3) != 0 ) /*0x109c4b*/
      return 1; /*0x10a056*/
    v4 = (volatile __int32 *)(v1 + 112); /*0x109c51*/
    do /*0x109c66*/
    {
      while ( *v4 ) /*0x109c54*/
        ; /*0x109c56*/
    }
    while ( _InterlockedExchange(v4, 1) == 1 ); /*0x109c66*/
  }
  while ( 1 ) /*0x109f07*/
  {
    while ( 1 ) /*0x109d39*/
    {
      while ( 1 ) /*0x109c7a*/
      {
LABEL_16:
        v5 = *(_BYTE *)(dword_1E875C + 120); /*0x109c74*/
        if ( v5 ) /*0x109c7f*/
        {
          *(_DWORD *)(dword_1E875C + 124) |= 1 << (v5 - 1); /*0x109c8e*/
          *(_BYTE *)(dword_1E875C + 120) = 0; /*0x109c96*/
        }
        v6 = ~*(_DWORD *)(v1 + 28) & (*(_DWORD *)(v1 + 24) | *(_DWORD *)(dword_1E875C + 124)); /*0x109cab*/
        v21 = *(_DWORD *)(v1 + 40); /*0x109cb0*/
        if ( (v21 & 0x10) == 0 ) /*0x109cb9*/
          v6 &= ~*(_DWORD *)(v1 + 32); /*0x109cc0*/
        if ( (v21 & 0x1000) != 0 ) /*0x109cc8*/
          v6 &= 0xFFCCFFFF; /*0x109cca*/
        if ( !v6 ) /*0x109cd2*/
        {
          *(_BYTE *)(v1 + 23) = 0; /*0x10a034*/
          *(_BYTE *)(dword_1E875C + 120) = 0; /*0x10a03d*/
          _InterlockedExchange((volatile __int32 *)(v1 + 112), 0); /*0x10a043*/
          return 0; /*0x10a043*/
        }
        if ( a1 && (v21 & 0x10) != 0 ) /*0x109ce2*/
          goto LABEL_74; /*0x109ce2*/
        if ( !_BitScanForward((unsigned int *)&v8, v6) ) /*0x109ce8*/
          v8 = -1; /*0x109ced*/
        v19 = v8 + 1; /*0x109cf5*/
        v22 = 1 << v8; /*0x109d01*/
        if ( ((1 << v8) & 0x1EF8) != 0 ) /*0x109d0a*/
        {
          *(_BYTE *)(dword_1E875C + 120) = v19; /*0x109d0f*/
          *(_DWORD *)(dword_1E875C + 124) &= ~v22; /*0x109d1d*/
        }
        *(_DWORD *)(v1 + 24) &= ~v22; /*0x109d25*/
        *(_BYTE *)(v1 + 23) = v19; /*0x109d2b*/
        if ( (*(_DWORD *)(v1 + 40) & 0x1010) != 0x10 ) /*0x109d39*/
          break; /*0x109d39*/
        psignal(*(_DWORD *)(v1 + 68), (const char *)0x14); /*0x109d45*/
        v9 = active_threads; /*0x109d4a*/
        *(_DWORD *)(v1 + 108) = active_threads; /*0x109d50*/
        pcb_synch(v9); /*0x109d54*/
        v10 = *(_DWORD *)(v1 + 104); /*0x109d59*/
        v11 = 0; /*0x109d5c*/
        do /*0x109d76*/
        {
          while ( *(_DWORD *)v10 ) /*0x109d64*/
            ; /*0x109d66*/
        }
        while ( _InterlockedExchange((volatile __int32 *)v10, 1) == 1 ); /*0x109d76*/
        v12 = *(_DWORD *)(v10 + 68); /*0x109d78*/
        *(_DWORD *)(v10 + 68) = v12 + 1; /*0x109d7e*/
        if ( !v12 ) /*0x109d83*/
          v11 = 1; /*0x109d85*/
        _InterlockedExchange((volatile __int32 *)v10, 0); /*0x109d8c*/
        if ( v11 ) /*0x109d90*/
        {
          task_hold(v10); /*0x109d93*/
          *(_DWORD *)(v1 + 116) = 1; /*0x109d9b*/
          _InterlockedExchange((volatile __int32 *)(v1 + 112), 0); /*0x109da4*/
          task_dowait(v10, 1); /*0x109daa*/
          thread_hold(active_threads); /*0x109db6*/
        }
        else
        {
          *(_DWORD *)(v1 + 116) = 1; /*0x109dc0*/
          _InterlockedExchange((volatile __int32 *)(v1 + 112), 0); /*0x109dc9*/
        }
        *(_BYTE *)(v1 + 19) = 6; /*0x109dcc*/
        *(_DWORD *)(v1 + 40) &= ~0x20u; /*0x109dd0*/
        wakeup(*(_DWORD *)(v1 + 68)); /*0x109dd8*/
        thread_block(); /*0x109ddd*/
        v13 = (volatile __int32 *)(v1 + 112); /*0x109de5*/
        do /*0x109dfa*/
        {
          while ( *v13 ) /*0x109de8*/
            ; /*0x109dea*/
        }
        while ( _InterlockedExchange(v13, 1) == 1 ); /*0x109dfa*/
        *(_DWORD *)(v1 + 116) = 0; /*0x109dfc*/
        LOBYTE(v14) = *(_BYTE *)(v1 + 23); /*0x109e03*/
        if ( (char)v14 > 32 ) /*0x109e09*/
        {
          v20 = (char)v14 - 32; /*0x109e11*/
          clear_wait(active_threads, 2, 0); /*0x109e1f*/
          *(_DWORD *)(v1 + 120) = active_threads; /*0x109e2d*/
          _InterlockedExchange((volatile __int32 *)(v1 + 112), 0); /*0x109e32*/
          task_hold(*(_DWORD *)(active_threads + 12)); /*0x109e3e*/
          task_dowait(*(_DWORD *)(active_threads + 12), 0); /*0x109e4e*/
          qmemcpy(v23, (const void *)(dword_1E875C + 40), sizeof(v23)); /*0x109e68*/
          exit(v20); /*0x109e6e*/
        }
        if ( (*(_BYTE *)(active_threads + 380) & 3) != 0 ) /*0x109e80*/
        {
LABEL_74:
          _InterlockedExchange((volatile __int32 *)(v1 + 112), 0); /*0x10a04c*/
          return 1; /*0x10a04e*/
        }
        if ( (*(_BYTE *)(v1 + 40) & 0x10) != 0 ) /*0x109e8a*/
        {
          v14 = (char)v14; /*0x109eb4*/
          v19 = v14; /*0x109eb7*/
          if ( (_BYTE)v14 ) /*0x109ebc*/
          {
            v15 = 1 << (v14 - 1); /*0x109ecc*/
            v22 = v15; /*0x109ece*/
            if ( (v15 & *(_DWORD *)(v1 + 28)) == 0 ) /*0x109ed4*/
              break; /*0x109ed4*/
            if ( (v15 & 0x1EF8) != 0 ) /*0x109edc*/
              *(_DWORD *)(dword_1E875C + 124) |= v15; /*0x109ee3*/
            else
              *(_DWORD *)(v1 + 24) |= v15; /*0x109eef*/
          }
        }
        else if ( (v22 & 0x1EF8) != 0 ) /*0x109e93*/
        {
          *(_DWORD *)(dword_1E875C + 124) |= v22; /*0x109e9d*/
        }
        else
        {
          *(_DWORD *)(v1 + 24) |= v22; /*0x109eab*/
        }
      }
      v16 = *(_DWORD *)(active_u + 4 * v19 + 48); /*0x109f00*/
      if ( v16 != 1 ) /*0x109f07*/
        break; /*0x109f07*/
LABEL_70:
      if ( (*(_BYTE *)(v1 + 40) & 0x10) == 0 ) /*0x10a01c*/
        printf("issig\n"); /*0x10a027*/
    }
    if ( v16 > 1 ) /*0x109f0d*/
      break; /*0x109f0d*/
    if ( v16 ) /*0x109f11*/
      goto LABEL_76; /*0x109f11*/
    if ( *(_WORD *)(v1 + 50) ) /*0x109f28*/
    {
      switch ( v19 ) /*0x109f5b*/
      {
        case 16: /*0x109f5b*/
        case 19: /*0x109f5b*/
        case 20: /*0x109f5b*/
        case 23: /*0x109f5b*/
        case 28: /*0x109f5b*/
          goto LABEL_16;
        case 17: /*0x109f5b*/
          goto LABEL_64;
        case 18: /*0x109f5b*/
        case 21: /*0x109f5b*/
        case 22: /*0x109f5b*/
          if ( *(_DWORD *)(v1 + 68) == init_proc ) /*0x109fa0*/
          {
            psignal(v1, (const char *)9); /*0x109fa5*/
          }
          else
          {
LABEL_64:
            if ( (*(_BYTE *)(v1 + 40) & 0x10) == 0 ) /*0x109fb8*/
            {
              psignal(*(_DWORD *)(v1 + 68), (const char *)0x14); /*0x109fc4*/
              stop(v1); /*0x109fca*/
              *(_DWORD *)(v1 + 116) = 1; /*0x109fd2*/
              _InterlockedExchange((volatile __int32 *)(v1 + 112), 0); /*0x109fdb*/
              thread_block(); /*0x109fde*/
              v17 = (volatile __int32 *)(v1 + 112); /*0x109fe3*/
              do /*0x109ffa*/
              {
                while ( *v17 ) /*0x109fe8*/
                  ; /*0x109fea*/
              }
              while ( _InterlockedExchange(v17, 1) == 1 ); /*0x109ffa*/
              *(_DWORD *)(v1 + 116) = 0; /*0x109ffc*/
              if ( (*(_BYTE *)(active_threads + 380) & 3) != 0 ) /*0x10a00f*/
                goto LABEL_74; /*0x10a00f*/
            }
          }
          break; /*0x109fad*/
        default:
          goto LABEL_76;
      }
    }
    else
    {
      *(_BYTE *)(dword_1E875C + 120) = 0; /*0x109f34*/
      *(_DWORD *)(dword_1E875C + 124) &= ~v22; /*0x109f43*/
    }
  }
  if ( v16 == 3 ) /*0x109f1b*/
    goto LABEL_70; /*0x109f1b*/
LABEL_76:
  _InterlockedExchange((volatile __int32 *)(v1 + 112), 0); /*0x10a058*/
  return v19; /*0x10a063*/
}
