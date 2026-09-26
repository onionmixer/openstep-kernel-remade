/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x160e84. */
int __cdecl thread_quantum_update(int a1, int a2, int a3, int a4)
{
  int result; // eax
  int v5; // edi
  int v6; // eax
  volatile __int32 *v7; // edx
  int v8; // edx
  int v9; // ebx
  int v10; // edx
  int v11; // ebx
  int v12; // eax
  volatile __int32 *v13; // edx
  int v14; // edx
  int v15; // ebx
  int v16; // edx
  int v17; // ebx
  unsigned int v18; // eax
  int v19; // [esp+Ch] [ebp-8h]
  int v20; // [esp+Ch] [ebp-8h]
  int v21; // [esp+10h] [ebp-4h]

  result = a1; /*0x160e8d*/
  v5 = processor_ptr[a1]; /*0x160e93*/
  v21 = min_quantum; /*0x160ea0*/
  dword_1E977C = min_quantum; /*0x160ea3*/
  if ( a4 != 2 ) /*0x160ead*/
  {
    v6 = *(_DWORD *)(v5 + 288) - a3; /*0x160eb9*/
    *(_DWORD *)(v5 + 288) = v6; /*0x160ebc*/
    if ( v6 > 0 ) /*0x160ec4*/
    {
      v20 = splsched(); /*0x161011*/
      v13 = (volatile __int32 *)(a2 + 32); /*0x161014*/
      do /*0x16102a*/
      {
        while ( *v13 ) /*0x161018*/
          ; /*0x16101a*/
      }
      while ( _InterlockedExchange(v13, 1) == 1 ); /*0x16102a*/
      if ( *(_DWORD *)(a2 + 112) == sched_tick ) /*0x161034*/
      {
        if ( *(_DWORD *)(a2 + 96) != 2 && *(int *)(a2 + 100) < 0 ) /*0x161052*/
        {
          v14 = *(_DWORD *)(a2 + 240); /*0x161058*/
          if ( *(_DWORD *)(a2 + 268) == *(_DWORD *)(a2 + 248) ) /*0x16106a*/
          {
            v15 = v14 - *(_DWORD *)(a2 + 264); /*0x16108a*/
            *(_DWORD *)(a2 + 264) = v14; /*0x161090*/
          }
          else
          {
            v15 = timer_delta(a2 + 240, a2 + 264); /*0x16107f*/
          }
          v16 = *(_DWORD *)(a2 + 224); /*0x161096*/
          if ( *(_DWORD *)(a2 + 260) == *(_DWORD *)(a2 + 232) ) /*0x1610a8*/
          {
            v17 = v16 - *(_DWORD *)(a2 + 256) + v15; /*0x1610cc*/
            *(_DWORD *)(a2 + 256) = v16; /*0x1610ce*/
          }
          else
          {
            v17 = timer_delta(a2 + 224, a2 + 256) + v15; /*0x1610bd*/
          }
          *(_DWORD *)(a2 + 272) += v17; /*0x1610d4*/
          v18 = *(_DWORD *)(a2 + 276) + *(_DWORD *)(*(_DWORD *)(a2 + 384) + 376) * v17; /*0x1610e9*/
          *(_DWORD *)(a2 + 276) = v18; /*0x1610ef*/
          if ( v18 > 0x7FFFFFF ) /*0x1610fa*/
          {
            *(_DWORD *)(a2 + 108) += v18; /*0x1610fc*/
            *(_DWORD *)(a2 + 276) = 0; /*0x1610ff*/
            compute_my_priority(a2); /*0x16110a*/
          }
        }
      }
      else
      {
        update_priority(a2); /*0x161037*/
      }
      _InterlockedExchange((volatile __int32 *)(a2 + 32), 0); /*0x161114*/
      splx(v20); /*0x16111b*/
    }
    else
    {
      v19 = splsched(); /*0x160ecf*/
      v7 = (volatile __int32 *)(a2 + 32); /*0x160ed2*/
      do /*0x160eea*/
      {
        while ( *v7 ) /*0x160ed8*/
          ; /*0x160eda*/
      }
      while ( _InterlockedExchange(v7, 1) == 1 ); /*0x160eea*/
      if ( *(_DWORD *)(a2 + 112) == sched_tick ) /*0x160ef4*/
      {
        if ( *(_DWORD *)(a2 + 96) != 2 && *(int *)(a2 + 100) < 0 ) /*0x160f12*/
        {
          v8 = *(_DWORD *)(a2 + 240); /*0x160f18*/
          if ( *(_DWORD *)(a2 + 268) == *(_DWORD *)(a2 + 248) ) /*0x160f2a*/
          {
            v9 = v8 - *(_DWORD *)(a2 + 264); /*0x160f4a*/
            *(_DWORD *)(a2 + 264) = v8; /*0x160f50*/
          }
          else
          {
            v9 = timer_delta(a2 + 240, a2 + 264); /*0x160f3f*/
          }
          v10 = *(_DWORD *)(a2 + 224); /*0x160f56*/
          if ( *(_DWORD *)(a2 + 260) == *(_DWORD *)(a2 + 232) ) /*0x160f68*/
          {
            v11 = v10 - *(_DWORD *)(a2 + 256) + v9; /*0x160f8c*/
            *(_DWORD *)(a2 + 256) = v10; /*0x160f8e*/
          }
          else
          {
            v11 = timer_delta(a2 + 224, a2 + 256) + v9; /*0x160f7d*/
          }
          *(_DWORD *)(a2 + 272) += v11; /*0x160f94*/
          v12 = *(_DWORD *)(a2 + 276) + *(_DWORD *)(*(_DWORD *)(a2 + 384) + 376) * v11; /*0x160fa9*/
          *(_DWORD *)(a2 + 276) = v12; /*0x160faf*/
          *(_DWORD *)(a2 + 108) += v12; /*0x160fb5*/
          *(_DWORD *)(a2 + 276) = 0; /*0x160fb8*/
          compute_my_priority(a2); /*0x160fc3*/
        }
      }
      else
      {
        update_priority(a2); /*0x160ef7*/
      }
      _InterlockedExchange((volatile __int32 *)(a2 + 32), 0); /*0x160fcd*/
      splx(v19); /*0x160fd4*/
      *(_DWORD *)(v5 + 292) = 0; /*0x160fd9*/
      if ( *(_DWORD *)(a2 + 96) == 2 ) /*0x160fea*/
        *(_DWORD *)(v5 + 288) += *(_DWORD *)(a2 + 92); /*0x160fff*/
      else
        *(_DWORD *)(v5 + 288) += v21; /*0x160fef*/
    }
    return ast_check(); /*0x161123*/
  }
  return result; /*0x16112b*/
}
