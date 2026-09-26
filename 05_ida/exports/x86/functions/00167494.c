/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x167494. */
int __cdecl thread_halt(unsigned int a1, int a2)
{
  thread_act_t v2; // esi
  int v3; // edi
  volatile __int32 *v4; // edx
  volatile __int32 *v5; // edx
  volatile __int32 *v6; // edx
  volatile __int32 *v7; // edx
  volatile __int32 *v9; // edx
  int v10; // eax
  volatile __int32 *v11; // esi
  int v12; // esi
  int v13; // edi
  volatile __int32 *v14; // edx
  int (*v15)(); // eax
  int (*v16)(void); // eax
  int v17; // edi
  volatile __int32 *v18; // edx
  volatile __int32 *v19; // edx

  v2 = active_threads; /*0x16749d*/
  if ( a1 == active_threads ) /*0x1674a5*/
    panic(aThreadHaltTryi); /*0x1674ac*/
  if ( a2 ) /*0x1674b8*/
  {
    v3 = splsched(); /*0x16758d*/
    v9 = (volatile __int32 *)(a1 + 32); /*0x16758f*/
    do /*0x1675a6*/
    {
      while ( *v9 ) /*0x167594*/
        ; /*0x167596*/
    }
    while ( _InterlockedExchange(v9, 1) == 1 ); /*0x1675a6*/
    if ( (*(_BYTE *)(a1 + 76) & 0x10) != 0 ) /*0x1675ac*/
    {
      ++*(_DWORD *)(a1 + 64); /*0x1675ae*/
      _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x1675b3*/
      splx(v3); /*0x1675b7*/
      return 0; /*0x1675be*/
    }
  }
  else
  {
    v3 = splsched(); /*0x1674c3*/
    if ( a1 >= v2 ) /*0x1674c7*/
    {
      v6 = (volatile __int32 *)(v2 + 32); /*0x1674fc*/
      do /*0x167512*/
      {
        while ( *v6 ) /*0x167500*/
          ; /*0x167502*/
      }
      while ( _InterlockedExchange(v6, 1) == 1 ); /*0x167512*/
      v7 = (volatile __int32 *)(a1 + 32); /*0x167514*/
      do /*0x16752a*/
      {
        while ( *v7 ) /*0x167518*/
          ; /*0x16751a*/
      }
      while ( _InterlockedExchange(v7, 1) == 1 ); /*0x16752a*/
    }
    else
    {
      v4 = (volatile __int32 *)(a1 + 32); /*0x1674c9*/
      do /*0x1674de*/
      {
        while ( *v4 ) /*0x1674cc*/
          ; /*0x1674ce*/
      }
      while ( _InterlockedExchange(v4, 1) == 1 ); /*0x1674de*/
      v5 = (volatile __int32 *)(v2 + 32); /*0x1674e0*/
      do /*0x1674f6*/
      {
        while ( *v5 ) /*0x1674e4*/
          ; /*0x1674e6*/
      }
      while ( _InterlockedExchange(v5, 1) == 1 ); /*0x1674f6*/
    }
    if ( (*(_BYTE *)(a1 + 76) & 0x10) != 0 ) /*0x167530*/
    {
      ++*(_DWORD *)(a1 + 64); /*0x167532*/
      _InterlockedExchange((volatile __int32 *)(v2 + 32), 0); /*0x167537*/
      _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x16753c*/
      splx(v3); /*0x167540*/
      return 0; /*0x167547*/
    }
    if ( (*(_BYTE *)(v2 + 380) & 1) != 0 ) /*0x167553*/
    {
      thread_wakeup_prim(v2 + 72, 0, 2); /*0x16755d*/
      _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x167567*/
      _InterlockedExchange((volatile __int32 *)(v2 + 32), 0); /*0x16756c*/
      splx(v3); /*0x167570*/
      return 5; /*0x16757a*/
    }
    _InterlockedExchange((volatile __int32 *)(v2 + 32), 0); /*0x167582*/
  }
  ++*(_DWORD *)(a1 + 64); /*0x1675ec*/
  v10 = *(_DWORD *)(a1 + 76); /*0x1675ef*/
  LOBYTE(v10) = v10 | 2; /*0x1675f2*/
  *(_DWORD *)(a1 + 76) = v10; /*0x1675f4*/
  if ( (*(_BYTE *)(a1 + 380) & 1) == 0 || (v10 & 0x10) != 0 ) /*0x167602*/
  {
LABEL_39:
    *(_BYTE *)(a1 + 380) |= 1u; /*0x16765b*/
    while ( 1 ) /*0x167666*/
    {
      _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x167666*/
      splx(v3); /*0x16766a*/
      v12 = thread_dowait(a1, a2); /*0x167679*/
      if ( v12 ) /*0x167680*/
      {
        v13 = splsched(); /*0x167687*/
        v14 = (volatile __int32 *)(a1 + 32); /*0x167689*/
        do /*0x16769e*/
        {
          while ( *v14 ) /*0x16768c*/
            ; /*0x16768e*/
        }
        while ( _InterlockedExchange(v14, 1) == 1 ); /*0x16769e*/
        *(_DWORD *)(a1 + 380) &= ~1u; /*0x1676a0*/
        thread_wakeup_prim(a1 + 72, 0, 2); /*0x1676af*/
        _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x1676b9*/
        splx(v13); /*0x1676bd*/
        thread_release(a1); /*0x1676c3*/
        return v12; /*0x1676ca*/
      }
      clear_wait(a1, 2, 1); /*0x1676d5*/
      if ( (*(_BYTE *)(a1 + 76) & 0x10) != 0 ) /*0x1676e1*/
        return 0; /*0x1676e5*/
      v15 = *(int (**)())(a1 + 52); /*0x1676ec*/
      if ( v15 == mach_msg_continue || v15 == mach_msg_receive_continue ) /*0x1676fb*/
      {
        if ( mach_msg_interrupt((_DWORD *)a1) ) /*0x1676fe*/
          break; /*0x1676fe*/
      }
      v16 = *(int (**)(void))(a1 + 52); /*0x16770a*/
      if ( v16 == thread_exception_return || v16 == thread_bootstrap_return ) /*0x167719*/
        break; /*0x167719*/
      v3 = splsched(); /*0x16775d*/
      v19 = (volatile __int32 *)(a1 + 32); /*0x16775f*/
      do /*0x167776*/
      {
        while ( *v19 ) /*0x167764*/
          ; /*0x167766*/
      }
      while ( _InterlockedExchange(v19, 1) == 1 ); /*0x167776*/
      if ( (*(_DWORD *)(a1 + 76) & 0xF) != 2 ) /*0x167781*/
        panic(aThreadHalt); /*0x167788*/
      *(_BYTE *)(a1 + 76) |= 0xCu; /*0x167790*/
      thread_setrun((char **)a1, 0); /*0x167797*/
    }
    v17 = splsched(); /*0x167720*/
    v18 = (volatile __int32 *)(a1 + 32); /*0x167722*/
    do /*0x16773a*/
    {
      while ( *v18 ) /*0x167728*/
        ; /*0x16772a*/
    }
    while ( _InterlockedExchange(v18, 1) == 1 ); /*0x16773a*/
    *(_BYTE *)(a1 + 76) |= 0x10u; /*0x16773c*/
    *(_DWORD *)(a1 + 380) &= ~1u; /*0x167740*/
    _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x167749*/
    splx(v17); /*0x16774d*/
    return 0; /*0x167752*/
  }
  else
  {
    while ( 1 ) /*0x167604*/
    {
      *(_DWORD *)(a1 + 72) = 1; /*0x167604*/
      v11 = (volatile __int32 *)(a1 + 32); /*0x16760d*/
      thread_sleep(a1 + 72, (volatile __int32 *)(a1 + 32), 1); /*0x167615*/
      if ( (*(_BYTE *)(a1 + 76) & 0x10) != 0 ) /*0x167621*/
      {
        splx(v3); /*0x1675c5*/
        return 0; /*0x1675cc*/
      }
      if ( *(_DWORD *)(active_threads + 68) && !a2 ) /*0x167632*/
        break; /*0x167632*/
      do /*0x16764a*/
      {
        while ( *v11 ) /*0x167638*/
          ; /*0x16763a*/
      }
      while ( _InterlockedExchange(v11, 1) == 1 ); /*0x16764a*/
      if ( (*(_BYTE *)(a1 + 380) & 1) == 0 || (*(_BYTE *)(a1 + 76) & 0x10) != 0 ) /*0x167659*/
        goto LABEL_39; /*0x167659*/
    }
    splx(v3); /*0x1675d5*/
    thread_release(a1); /*0x1675db*/
    return 5; /*0x1675e0*/
  }
}
