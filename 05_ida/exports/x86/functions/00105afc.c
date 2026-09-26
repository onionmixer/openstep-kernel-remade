/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x105afc. */
int __cdecl do_exit(int a1, int a2)
{
  volatile __int32 *v2; // edx
  volatile __int32 *v3; // ebx
  int v4; // edx
  int result; // eax
  int v6; // eax
  int i; // esi
  int j; // esi
  int v9; // eax
  int v10; // ebx
  int v11; // edx
  int v12; // eax
  int v13; // esi
  int v14; // edx
  _DWORD *v15; // esi
  _DWORD *v16; // ebx
  _DWORD *k; // edx
  void *v18; // eax
  unsigned int v19; // eax
  int v20; // eax
  int v21; // ebx
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  unsigned int v26; // ebx
  unsigned int v27; // esi
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // eax
  unsigned int v32; // eax
  int v33; // eax
  int v34; // ebx
  const char *v35; // [esp+0h] [ebp-34h]
  _DWORD *v36; // [esp+Ch] [ebp-28h]
  _DWORD *v37; // [esp+Ch] [ebp-28h]
  int posix_proc; // [esp+10h] [ebp-24h]
  int v39; // [esp+14h] [ebp-20h]
  _DWORD *v40; // [esp+18h] [ebp-1Ch]
  task_t target_task; // [esp+1Ch] [ebp-18h]
  _DWORD *v42; // [esp+20h] [ebp-14h]
  _DWORD v43[2]; // [esp+24h] [ebp-10h] BYREF
  _DWORD v44[2]; // [esp+2Ch] [ebp-8h] BYREF

  posix_proc = get_posix_proc(*(__int16 *)(a1 + 48)); /*0x105b12*/
  if ( active_threads != *(_DWORD *)(a1 + 120) ) /*0x105b24*/
  {
    v2 = (volatile __int32 *)(a1 + 112); /*0x105b2c*/
    do /*0x105b42*/
    {
      while ( *v2 ) /*0x105b30*/
        ; /*0x105b32*/
    }
    while ( _InterlockedExchange(v2, 1) == 1 ); /*0x105b42*/
    while ( *(_DWORD *)(a1 + 116) || *(_DWORD *)(a1 + 120) ) /*0x105bad*/
    {
      v3 = (volatile __int32 *)(a1 + 112); /*0x105b4b*/
      _InterlockedExchange((volatile __int32 *)(a1 + 112), 0); /*0x105b53*/
      v4 = *(_DWORD *)(a1 + 120); /*0x105b56*/
      if ( v4 ) /*0x105b5b*/
      {
        result = active_threads; /*0x105b5d*/
        if ( active_threads == v4 ) /*0x105b64*/
          return result; /*0x105b64*/
        thread_hold(active_threads); /*0x105b6b*/
      }
      thread_block(); /*0x105b73*/
      result = active_threads; /*0x105b78*/
      if ( (*(_BYTE *)(active_threads + 380) & 3) != 0 ) /*0x105b84*/
        return result; /*0x105b84*/
      do /*0x105b9e*/
      {
        while ( *v3 ) /*0x105b8c*/
          ; /*0x105b8e*/
      }
      while ( _InterlockedExchange(v3, 1) == 1 ); /*0x105b9e*/
    }
    *(_DWORD *)(a1 + 120) = active_threads; /*0x105bb8*/
    _InterlockedExchange((volatile __int32 *)(a1 + 112), 0); /*0x105bbd*/
    task_hold(*(_DWORD *)(active_threads + 12)); /*0x105bc9*/
    task_dowait(*(_DWORD *)(active_threads + 12), 0); /*0x105bd9*/
  }
  target_task = *(_DWORD *)(a1 + 104); /*0x105be7*/
  task_halt(target_task); /*0x105beb*/
  v42 = *(_DWORD **)(target_task + 56); /*0x105bf3*/
  v6 = *(_DWORD *)(a1 + 40); /*0x105bf9*/
  LOBYTE(v6) = v6 & 0xAF; /*0x105bfc*/
  BYTE1(v6) |= 4u; /*0x105bfe*/
  *(_DWORD *)(a1 + 40) = v6; /*0x105c01*/
  *(_DWORD *)(a1 + 32) = -1; /*0x105c04*/
  for ( i = 31; i >= 0; --i ) /*0x105c0e*/
    v42[i + 12] = 1; /*0x105c17*/
  untimeout((int)realitexpire, a1); /*0x105c2b*/
  for ( j = 0; v42[86] >= j; ++j ) /*0x105c3e*/
  {
    v9 = v42[84]; /*0x105c43*/
    v10 = *(_DWORD *)(v9 + 4 * j); /*0x105c49*/
    if ( v10 && v10 != -65536 ) /*0x105c56*/
    {
      vno_lockrelease(*(_DWORD *)(v9 + 4 * j)); /*0x105c59*/
      *(_DWORD *)(v42[84] + 4 * j) = 0; /*0x105c64*/
      closef(v10); /*0x105c6c*/
    }
    *(_BYTE *)(j + v42[85]) = 0; /*0x105c7d*/
  }
  if ( v42[88] ) /*0x105c8d*/
    vn_rele(v42[88]); /*0x105c98*/
  if ( v42[89] ) /*0x105ca3*/
    vn_rele(v42[89]); /*0x105cae*/
  v42[155] = 0x7FFFFFFF; /*0x105cb9*/
  acct(v35); /*0x105cc3*/
  crfree(v42[7]); /*0x105ccc*/
  v11 = *(_DWORD *)(a1 + 8); /*0x105cd7*/
  **(_DWORD **)(a1 + 12) = v11; /*0x105cda*/
  if ( v11 ) /*0x105ce1*/
    *(_DWORD *)(*(_DWORD *)(a1 + 8) + 12) = *(_DWORD *)(a1 + 12); /*0x105ce9*/
  v12 = zombproc; /*0x105cec*/
  *(_DWORD *)(a1 + 8) = zombproc; /*0x105cf4*/
  if ( v12 ) /*0x105cf9*/
    *(_DWORD *)(v12 + 12) = a1 + 8; /*0x105cfe*/
  *(_DWORD *)(a1 + 12) = &zombproc; /*0x105d04*/
  zombproc = a1; /*0x105d0b*/
  *(_BYTE *)(a1 + 19) = 5; /*0x105d11*/
  v13 = *(_WORD *)(a1 + 48) & 0x3F; /*0x105d19*/
  v14 = pidhash[v13]; /*0x105d1c*/
  if ( a1 == v14 ) /*0x105d25*/
  {
    pidhash[v13] = *(_DWORD *)(a1 + 64); /*0x105d2a*/
    if ( *(_WORD *)(a1 + 48) == 1 ) /*0x105d63*/
    {
      printf("init exited with %d\n", a2 >> 8); /*0x105d71*/
      while ( 1 ) /*0x105d78*/
        ; /*0x105d78*/
    }
  }
  else
  {
    while ( 1 ) /*0x105d4a*/
    {
      if ( !v14 ) /*0x105d4c*/
        panic(aExit); /*0x105d53*/
      if ( a1 == *(_DWORD *)(v14 + 64) ) /*0x105d46*/
        break; /*0x105d46*/
      v14 = *(_DWORD *)(v14 + 64); /*0x105d48*/
    }
    *(_DWORD *)(v14 + 64) = *(_DWORD *)(a1 + 64); /*0x105d3a*/
  }
  *(_WORD *)(a1 + 52) = a2; /*0x105d83*/
  v15 = v42 + 92; /*0x105d8a*/
  v42[92] = 0; /*0x105d93*/
  v42[93] = 0; /*0x105d9d*/
  v42[94] = 0; /*0x105db0*/
  v42[95] = 0; /*0x105dba*/
  v40 = (_DWORD *)(target_task + 28); /*0x105dca*/
  do /*0x105de8*/
  {
    while ( *(_DWORD *)target_task ) /*0x105dd3*/
      ; /*0x105dd5*/
  }
  while ( _InterlockedExchange((volatile __int32 *)target_task, 1) == 1 ); /*0x105de8*/
  v16 = (_DWORD *)*v40; /*0x105ded*/
  v39 = splsched(); /*0x105df7*/
  for ( k = v42 + 94; v40 != v16; v16 = (_DWORD *)v16[4] ) /*0x105e00*/
  {
    v36 = k; /*0x105e0d*/
    thread_read_times(v16, v44, v43); /*0x105e10*/
    *v15 += v44[0]; /*0x105e18*/
    v42[93] += v44[1]; /*0x105e1d*/
    k = v36; /*0x105e20*/
    *v36 += v43[0]; /*0x105e26*/
    v36[1] += v43[1]; /*0x105e2b*/
  }
  v37 = k; /*0x105e3d*/
  splx(v39); /*0x105e40*/
  *v15 += *(_DWORD *)(target_task + 84); /*0x105e4b*/
  v42[93] += *(_DWORD *)(target_task + 88); /*0x105e53*/
  *v37 += *(_DWORD *)(target_task + 92); /*0x105e5f*/
  v37[1] += *(_DWORD *)(target_task + 96); /*0x105e67*/
  _InterlockedExchange((volatile __int32 *)target_task, 0); /*0x105e72*/
  v18 = (void *)kalloc(0x48u); /*0x105e76*/
  *(_DWORD *)(a1 + 56) = v18; /*0x105e7e*/
  qmemcpy(v18, (const void *)(active_u + 368), 0x48u); /*0x105e95*/
  ruadd(*(_DWORD *)(a1 + 56), v42 + 110); /*0x105ea7*/
  if ( *(_DWORD *)(a1 + 72) ) /*0x105eb2*/
    wakeup(init_proc); /*0x105ebf*/
  v19 = *(_DWORD *)(a1 + 128); /*0x105eca*/
  if ( v19 ) /*0x105ed2*/
  {
    *(_DWORD *)(v19 + 124) = 0; /*0x105ed6*/
    *(_DWORD *)(v19 + 40) &= ~0x10u; /*0x105edd*/
    psignal(v19, (const char *)9); /*0x105ee4*/
    *(_DWORD *)(a1 + 128) = 0; /*0x105ee9*/
  }
  if ( (*(_BYTE *)(a1 + 22) & 2) != 0 ) /*0x105efd*/
  {
    v20 = *(_DWORD *)(*(_DWORD *)(posix_proc + 16) + 8); /*0x105f05*/
    if ( *(_DWORD *)(v20 + 4) == a1 ) /*0x105f0b*/
    {
      v21 = *(_DWORD *)(*(_DWORD *)(posix_proc + 16) + 8); /*0x105f0d*/
      v22 = *(_DWORD *)(v20 + 8); /*0x105f0f*/
      if ( v22 ) /*0x105f14*/
      {
        v23 = ttynty(v22); /*0x105f17*/
        if ( *(_DWORD *)(v23 + 8) == v21 ) /*0x105f22*/
        {
          v24 = *(_DWORD *)(v23 + 12); /*0x105f24*/
          if ( v24 ) /*0x105f29*/
            pgsignal(v24, (char *)1, 1); /*0x105f30*/
          ttywait(*(_DWORD *)(v21 + 8)); /*0x105f3c*/
        }
      }
      *(_DWORD *)(v21 + 4) = 0; /*0x105f44*/
    }
    if ( (*(_BYTE *)(a1 + 22) & 2) != 0 ) /*0x105f52*/
    {
      v25 = get_posix_proc(*(__int16 *)(a1 + 48)); /*0x105f5b*/
      fixjobc(a1, *(_DWORD *)(v25 + 16), 0); /*0x105f68*/
    }
  }
  v26 = *(_DWORD *)(a1 + 72); /*0x105f73*/
  if ( v26 ) /*0x105f78*/
  {
    do /*0x106009*/
    {
      v27 = *(_DWORD *)(v26 + 76); /*0x105f80*/
      if ( v27 ) /*0x105f85*/
        *(_DWORD *)(v27 + 80) = 0; /*0x105f87*/
      v28 = *(_DWORD *)(init_proc + 72); /*0x105f93*/
      if ( v28 ) /*0x105f98*/
        *(_DWORD *)(v28 + 80) = v26; /*0x105f9a*/
      v29 = init_proc; /*0x105f9d*/
      *(_DWORD *)(v26 + 76) = *(_DWORD *)(init_proc + 72); /*0x105fa5*/
      *(_DWORD *)(v26 + 80) = 0; /*0x105fa8*/
      *(_DWORD *)(v29 + 72) = v26; /*0x105faf*/
      *(_DWORD *)(v26 + 68) = v29; /*0x105fb2*/
      *(_WORD *)(v26 + 50) = 1; /*0x105fb5*/
      v30 = *(_DWORD *)(v26 + 40); /*0x105fbb*/
      if ( (v30 & 0x10) != 0 ) /*0x105fc0*/
      {
        LOBYTE(v30) = v30 & 0xEF; /*0x105fc2*/
        *(_DWORD *)(v26 + 40) = v30; /*0x105fc4*/
        *(_DWORD *)(v26 + 124) = 0; /*0x105fc7*/
        psignal(v26, (const char *)9); /*0x105fd1*/
      }
      else
      {
        v31 = *(_DWORD *)(v26 + 104); /*0x105fdc*/
        if ( v31 && *(int *)(v31 + 68) > 0 ) /*0x105fe7*/
        {
          psignal(v26, (const char *)1); /*0x105fec*/
          psignal(v26, (const char *)0x13); /*0x105ff4*/
        }
      }
      spgrp(v26); /*0x105ffd*/
      v26 = v27; /*0x106005*/
    }
    while ( v27 ); /*0x106009*/
  }
  *(_DWORD *)(a1 + 72) = 0; /*0x106012*/
  v32 = *(_DWORD *)(a1 + 124); /*0x106019*/
  if ( v32 ) /*0x10601e*/
  {
    psignal(v32, (const char *)0x14); /*0x106023*/
    wakeup(*(_DWORD *)(a1 + 124)); /*0x10602f*/
    *(_DWORD *)(*(_DWORD *)(a1 + 124) + 128) = 0; /*0x10603a*/
  }
  if ( *(_DWORD *)(active_u + 584) ) /*0x10604c*/
  {
    *(_DWORD *)(active_u + 604) = 0; /*0x106055*/
    simple_lock_free(*(_DWORD *)(active_u + 584)); /*0x10606b*/
  }
  v33 = *(_DWORD *)(active_u + 588); /*0x106078*/
  if ( v33 ) /*0x106080*/
  {
    do /*0x106096*/
    {
      v34 = *(_DWORD *)(v33 + 4); /*0x106084*/
      kfree(v33, 0x18u); /*0x10608a*/
      v33 = v34; /*0x106092*/
    }
    while ( v34 ); /*0x106096*/
  }
  psignal(*(_DWORD *)(a1 + 68), (const char *)0x14); /*0x1060a1*/
  wakeup(*(_DWORD *)(a1 + 68)); /*0x1060ad*/
  *(_DWORD *)(a1 + 104) = 0; /*0x1060b5*/
  *(_DWORD *)(a1 + 108) = 0; /*0x1060bc*/
  task_terminate(target_task); /*0x1060c7*/
  result = active_threads; /*0x1060cc*/
  if ( *(_DWORD *)(active_threads + 12) == target_task ) /*0x1060da*/
    return thread_halt_self(); /*0x1060dc*/
  return result; /*0x1060e4*/
}
