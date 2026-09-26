/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1635e8. */
int __cdecl thread_invoke(int a1, int a2, int a3)
{
  volatile __int32 *v3; // ebx
  int result; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // ebx
  int *v10; // edi
  int v11; // ebx
  int v12; // eax
  int v13; // edx
  int v14; // eax
  int v15; // eax
  int v16; // eax
  volatile __int32 *v17; // [esp+Ch] [ebp-14h]
  volatile __int32 *v18; // [esp+Ch] [ebp-14h]
  volatile __int32 *v19; // [esp+Ch] [ebp-14h]
  int v20; // [esp+Ch] [ebp-14h]
  int *v21; // [esp+10h] [ebp-10h]
  int v22; // [esp+14h] [ebp-Ch]
  int *v23; // [esp+18h] [ebp-8h]

  if ( a1 != a3 ) /*0x1635fc*/
  {
    v17 = (volatile __int32 *)(a3 + 32); /*0x16363f*/
    do /*0x16365c*/
    {
      while ( *v17 ) /*0x163647*/
        ; /*0x163649*/
    }
    while ( _InterlockedExchange(v17, 1) == 1 ); /*0x16365c*/
    if ( *(_DWORD *)(a1 + 48) == active_stacks || !a2 ) /*0x16366e*/
    {
      v15 = *(_DWORD *)(a3 + 76); /*0x163964*/
      if ( (v15 & 0x100) == 0 || (v15 & 0x200) == 0 && stack_alloc_try(a3, (int)thread_continue) ) /*0x163977*/
        goto LABEL_65; /*0x163981*/
      goto LABEL_64; /*0x163981*/
    }
    v5 = *(_DWORD *)(a3 + 76) & 0x300; /*0x16367c*/
    if ( v5 != 256 ) /*0x163686*/
    {
      if ( v5 != 512 ) /*0x163688*/
      {
LABEL_65:
        *(_DWORD *)(a3 + 76) &= 0xFFFFFEF7; /*0x163998*/
        _InterlockedExchange((volatile __int32 *)(a3 + 32), 0); /*0x1639a1*/
        need_ast[0] = *(_DWORD *)(a3 + 380) | need_ast[0] & 0xBFFFFFFC; /*0x1639b4*/
        switch_unix_context(a3); /*0x1639bf*/
        ++c_thread_invoke_csw; /*0x1639c4*/
        v16 = switch_context(a1, a2, a3); /*0x1639cd*/
        thread_dispatch(v16); /*0x1639d5*/
        return 1; /*0x1639da*/
      }
LABEL_64:
      thread_swapin(a3); /*0x163983*/
      _InterlockedExchange((volatile __int32 *)(a3 + 32), 0); /*0x16398b*/
      ++c_thread_invoke_misses; /*0x16398e*/
      return 0; /*0x163996*/
    }
    *(_DWORD *)(a3 + 76) &= 0xFFFFFEF7; /*0x1636a9*/
    _InterlockedExchange((volatile __int32 *)(a3 + 32), 0); /*0x1636ae*/
    need_ast[0] = *(_DWORD *)(a3 + 380) | need_ast[0] & 0xBFFFFFFC; /*0x1636c1*/
    switch_unix_context(a3); /*0x1636cc*/
    stack_handoff(a1, a3); /*0x1636d3*/
    v18 = (volatile __int32 *)(a1 + 32); /*0x1636db*/
    do /*0x1636fc*/
    {
      while ( *v18 ) /*0x1636e7*/
        ; /*0x1636e9*/
    }
    while ( _InterlockedExchange(v18, 1) == 1 ); /*0x1636fc*/
    *(_DWORD *)(a1 + 52) = a2; /*0x1636fe*/
    v6 = *(_DWORD *)(a1 + 76); /*0x163701*/
    if ( v6 != 12 ) /*0x163707*/
    {
      if ( v6 <= 12 ) /*0x16370d*/
      {
        if ( v6 != 5 ) /*0x163712*/
        {
          if ( v6 <= 5 ) /*0x163718*/
          {
            if ( v6 != 4 ) /*0x16371d*/
              goto LABEL_58; /*0x16371d*/
            goto LABEL_55; /*0x16371d*/
          }
          if ( v6 > 7 ) /*0x16372b*/
            goto LABEL_58; /*0x16372b*/
LABEL_34:
          v7 = *(_DWORD *)(a1 + 76); /*0x163770*/
          LOBYTE(v7) = v7 & 0xFB; /*0x163773*/
          BYTE1(v7) |= 1u; /*0x163775*/
          *(_DWORD *)(a1 + 76) = v7; /*0x163778*/
          if ( *(_DWORD *)(a1 + 72) ) /*0x16377b*/
          {
            *(_DWORD *)(a1 + 72) = 0; /*0x163785*/
            _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x16378e*/
            if ( a1 + 72 < 0 ) /*0x163797*/
              v8 = ~(a1 + 72); /*0x1637a3*/
            else
              v8 = a1 + 72; /*0x163799*/
            v9 = v8 % 59; /*0x1637ad*/
            v23 = &wait_queue[2 * (v8 % 59)]; /*0x1637b6*/
            v22 = splsched(); /*0x1637be*/
            v10 = &wait_lock[v9]; /*0x1637c1*/
            do /*0x1637da*/
            {
              while ( *v10 ) /*0x1637c8*/
                ; /*0x1637ca*/
            }
            while ( _InterlockedExchange(v10, 1) == 1 ); /*0x1637da*/
            v11 = *v23; /*0x1637df*/
            if ( v23 != (int *)*v23 ) /*0x1637e3*/
            {
              do /*0x1638ec*/
              {
                v21 = *(int **)v11; /*0x1637ee*/
                if ( *(_DWORD *)(v11 + 60) == a1 + 72 ) /*0x1637f7*/
                {
                  v19 = (volatile __int32 *)(v11 + 32); /*0x163800*/
                  do /*0x16381c*/
                  {
                    while ( *v19 ) /*0x163807*/
                      ; /*0x163809*/
                  }
                  while ( _InterlockedExchange(v19, 1) == 1 ); /*0x16381c*/
                  *(_DWORD *)(*(_DWORD *)v11 + 4) = *(_DWORD *)(v11 + 4); /*0x163823*/
                  **(_DWORD **)(v11 + 4) = *(_DWORD *)v11; /*0x16382b*/
                  *(_DWORD *)(v11 + 60) = 0; /*0x16382d*/
                  if ( *(_DWORD *)(v11 + 324) ) /*0x163834*/
                    reset_timeout(v11 + 280); /*0x163844*/
                  v20 = *(_DWORD *)(v11 + 76); /*0x16384f*/
                  switch ( v20 & 0xF ) /*0x16385d*/
                  {
                    case 1: /*0x16385d*/
                    case 9: /*0x16385d*/
                    case 0xB: /*0x16385d*/
                      v12 = *(_DWORD *)(v11 + 76); /*0x1638a0*/
                      LOBYTE(v12) = v20 & 0xFA | 4; /*0x1638a5*/
                      *(_DWORD *)(v11 + 76) = v12; /*0x1638a7*/
                      *(_DWORD *)(v11 + 68) = 0; /*0x1638aa*/
                      thread_setrun(v11, 1); /*0x1638b4*/
                      break; /*0x1638bc*/
                    case 3: /*0x16385d*/
                    case 5: /*0x16385d*/
                    case 7: /*0x16385d*/
                    case 0xD: /*0x16385d*/
                    case 0xF: /*0x16385d*/
                      v13 = *(_DWORD *)(v11 + 76); /*0x1638c0*/
                      LOBYTE(v13) = v20 & 0xFE; /*0x1638c3*/
                      *(_DWORD *)(v11 + 76) = v13; /*0x1638c6*/
                      *(_DWORD *)(v11 + 68) = 0; /*0x1638c9*/
                      break; /*0x1638d0*/
                    default:
                      panic(aThreadWakeup); /*0x1638d9*/
                      return result; /*0x1638d9*/
                  }
                  _InterlockedExchange((volatile __int32 *)(v11 + 32), 0); /*0x1638e3*/
                }
                v11 = (int)v21; /*0x1638e6*/
              }
              while ( v23 != v21 ); /*0x1638ec*/
            }
            _InterlockedExchange(v10, 0); /*0x1638f4*/
            splx(v22); /*0x1638fa*/
            goto LABEL_60; /*0x163902*/
          }
LABEL_59:
          _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x163941*/
LABEL_60:
          ++c_thread_invoke_hits; /*0x163946*/
          spl0(); /*0x16394c*/
          call_continuation(*(_DWORD *)(a3 + 52)); /*0x163955*/
          return 1; /*0x16395f*/
        }
        goto LABEL_56; /*0x163712*/
      }
      if ( v6 == 15 ) /*0x163737*/
        goto LABEL_56; /*0x163737*/
      if ( v6 > 15 ) /*0x16373d*/
      {
        if ( v6 != 22 ) /*0x16375b*/
        {
          if ( v6 != 132 ) /*0x163762*/
LABEL_58:
            panic(aThreadInvoke); /*0x163934*/
          *(_DWORD *)(a1 + 76) = 388; /*0x163928*/
          goto LABEL_59; /*0x16392f*/
        }
        goto LABEL_34; /*0x16375b*/
      }
      if ( v6 == 13 ) /*0x163742*/
      {
LABEL_56:
        v14 = *(_DWORD *)(a1 + 76); /*0x163918*/
        LOBYTE(v14) = v14 & 0xFB; /*0x16391b*/
        BYTE1(v14) |= 1u; /*0x16391d*/
        *(_DWORD *)(a1 + 76) = v14; /*0x163920*/
        goto LABEL_59; /*0x163923*/
      }
    }
LABEL_55:
    *(_DWORD *)(a1 + 76) |= 0x100u; /*0x163904*/
    thread_setrun(a1, 0); /*0x16390e*/
    goto LABEL_59; /*0x163916*/
  }
  v3 = (volatile __int32 *)(a1 + 32); /*0x1635fe*/
  do /*0x163616*/
  {
    while ( *v3 ) /*0x163604*/
      ; /*0x163606*/
  }
  while ( _InterlockedExchange(v3, 1) == 1 ); /*0x163616*/
  *(_DWORD *)(a3 + 76) &= ~8u; /*0x163618*/
  _InterlockedExchange((volatile __int32 *)(a3 + 32), 0); /*0x16361e*/
  if ( a2 ) /*0x163623*/
  {
    spl0(); /*0x163625*/
    call_continuation(a2); /*0x16362b*/
  }
  return 1; /*0x1639e2*/
}
