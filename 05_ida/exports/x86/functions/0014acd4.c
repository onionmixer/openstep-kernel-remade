/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14acd4. */
int __cdecl ipc_mqueue_receive(
        int a1,
        __int16 a2,
        unsigned int a3,
        int a4,
        int a5,
        int a6,
        unsigned int *a7,
        _DWORD *a8)
{
  _DWORD *v8; // ebx
  unsigned int v9; // eax
  _DWORD *v11; // edx
  _DWORD *v12; // eax
  int v13; // ebx
  int v14; // edx
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // edi
  _DWORD *v20; // [esp+Ch] [ebp-Ch]
  int v21; // [esp+10h] [ebp-8h]
  int v22; // [esp+14h] [ebp-4h]

  v21 = a1 + 4; /*0x14ace3*/
  v8 = (_DWORD *)active_threads; /*0x14ace6*/
  if ( a5 ) /*0x14acf0*/
    goto LABEL_20; /*0x14acf0*/
  while ( 1 ) /*0x14acfd*/
  {
    v20 = *(_DWORD **)v21; /*0x14acfd*/
    if ( *(_DWORD *)v21 ) /*0x14acfb*/
      break; /*0x14acfb*/
    if ( (a2 & 0x100) != 0 ) /*0x14ad5e*/
    {
      if ( !a4 ) /*0x14ad64*/
      {
        _InterlockedExchange((volatile __int32 *)a1, 0); /*0x14ad68*/
        return 268451843; /*0x14ad6f*/
      }
      thread_will_wait_with_timeout(v8, a4); /*0x14ad79*/
    }
    else
    {
      thread_will_wait(v8); /*0x14ad8d*/
    }
    v14 = *(_DWORD *)(a1 + 8); /*0x14ad95*/
    if ( v14 ) /*0x14ad9a*/
    {
      v15 = *(_DWORD *)(v14 + 148); /*0x14ad9c*/
      v8[36] = v14; /*0x14ada2*/
      v8[37] = v15; /*0x14ada8*/
      *(_DWORD *)(v14 + 148) = v8; /*0x14adae*/
      *(_DWORD *)(v15 + 144) = v8; /*0x14adb4*/
    }
    else
    {
      *(_DWORD *)(a1 + 8) = v8; /*0x14ad84*/
    }
    v8[38] = 268451841; /*0x14adba*/
    v8[39] = a3; /*0x14adc7*/
    _InterlockedExchange((volatile __int32 *)a1, 0); /*0x14adcf*/
    if ( a6 ) /*0x14add5*/
      thread_block_with_continuation(a6); /*0x14addb*/
    else
      thread_block_with_continuation(0); /*0x14ade2*/
    do /*0x14adfe*/
    {
LABEL_20:
      while ( *(_DWORD *)a1 ) /*0x14adec*/
        ; /*0x14adee*/
    }
    while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x14adfe*/
    v16 = v8[38]; /*0x14ae00*/
    if ( !v16 ) /*0x14ae08*/
    {
      v20 = (_DWORD *)v8[39]; /*0x14ae10*/
      v22 = v8[40]; /*0x14ae19*/
      v13 = v20[7]; /*0x14ae1c*/
      goto LABEL_39; /*0x14ae1f*/
    }
    if ( v16 == 268451844 ) /*0x14ae29*/
    {
      *a7 = v8[39]; /*0x14ae51*/
LABEL_32:
      _InterlockedExchange((volatile __int32 *)a1, 0); /*0x14ae53*/
      return v8[38]; /*0x14ae5d*/
    }
    if ( v16 > 268451844 ) /*0x14ae2b*/
    {
      if ( v16 != 268451846 && v16 != 268451849 ) /*0x14ae44*/
LABEL_38:
        panic(aIpcMqueueRecei); /*0x14aea4*/
      goto LABEL_32; /*0x14ae44*/
    }
    if ( v16 != 268451841 ) /*0x14ae32*/
      goto LABEL_38; /*0x14ae32*/
    ipc_thread_rmqueue(a1 + 8, v8); /*0x14ae69*/
    v17 = v8[17]; /*0x14ae71*/
    if ( v17 == 1 ) /*0x14ae77*/
    {
      a4 = 0; /*0x14ae98*/
    }
    else if ( v17 >= 1 && v17 <= 3 ) /*0x14ae82*/
    {
      _InterlockedExchange((volatile __int32 *)a1, 0); /*0x14ae8a*/
      return 268451845; /*0x14ae91*/
    }
  }
  v9 = *(_DWORD *)(*(_DWORD *)v21 + 24); /*0x14ad04*/
  if ( a3 < v9 ) /*0x14ad0a*/
  {
    *a7 = v9; /*0x14ad0f*/
    _InterlockedExchange((volatile __int32 *)a1, 0); /*0x14ad13*/
    return 268451844; /*0x14ad1a*/
  }
  v11 = (_DWORD *)*v20; /*0x14ad2f*/
  if ( (_DWORD *)*v20 == v20 ) /*0x14ad33*/
  {
    *(_DWORD *)v21 = 0; /*0x14ad23*/
  }
  else
  {
    v12 = (_DWORD *)v20[1]; /*0x14ad35*/
    *(_DWORD *)v21 = v11; /*0x14ad3b*/
    v11[1] = v12; /*0x14ad3d*/
    *v12 = v11; /*0x14ad40*/
  }
  v13 = v20[7]; /*0x14ad45*/
  v22 = *(_DWORD *)(v13 + 52); /*0x14ad4b*/
  *(_DWORD *)(v13 + 52) = v22 + 1; /*0x14ad4e*/
LABEL_39:
  _InterlockedExchange((volatile __int32 *)a1, 0); /*0x14aeb8*/
  if ( v20[3] ) /*0x14aebf*/
  {
    ipc_marequest_destroy(v20[3]); /*0x14aec7*/
    v20[3] = 0; /*0x14aecc*/
  }
  do /*0x14aeea*/
  {
    while ( *(_DWORD *)v13 ) /*0x14aed8*/
      ; /*0x14aeda*/
  }
  while ( _InterlockedExchange((volatile __int32 *)v13, 1) == 1 ); /*0x14aeea*/
  if ( *(int *)(v13 + 8) < 0 ) /*0x14aef0*/
  {
    v18 = *(_DWORD *)(v13 + 56); /*0x14aef2*/
    *(_DWORD *)(v13 + 56) = v18 - 1; /*0x14aef8*/
    v19 = *(_DWORD *)(v13 + 76); /*0x14aefe*/
    if ( v19 ) /*0x14af03*/
    {
      if ( *(_DWORD *)(v13 + 60) > (unsigned int)(v18 - 1) ) /*0x14af09*/
      {
        ipc_thread_rmqueue(v13 + 76, *(_DWORD *)(v13 + 76)); /*0x14af0d*/
        *(_DWORD *)(v19 + 152) = 0; /*0x14af12*/
        thread_go(v19); /*0x14af1d*/
      }
    }
  }
  _InterlockedExchange((volatile __int32 *)v13, 0); /*0x14af24*/
  *a7 = (unsigned int)v20; /*0x14af2c*/
  *a8 = v22; /*0x14af34*/
  return 0; /*0x14af3b*/
}
