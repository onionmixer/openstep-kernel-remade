/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x154594. */
int __cdecl msg_rpc_trap(int a1, int a2, int a3, unsigned int a4, int a5, int a6)
{
  int v6; // eax
  unsigned int v7; // ebx
  int v9; // eax
  int v10; // ebx
  int v11; // esi
  int v12; // ebx
  volatile __int32 *v13; // edx
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // ecx
  int v18; // ebx
  int v19; // eax
  volatile __int32 *v20; // edx
  _DWORD *v21; // eax
  unsigned int v22; // eax
  int v23; // ebx
  int v24; // eax
  int v25; // edx
  int v26; // eax
  int v27; // [esp-8h] [ebp-28h]
  int v28; // [esp-8h] [ebp-28h]
  vm_map_t target_task; // [esp+Ch] [ebp-14h]
  int v30; // [esp+10h] [ebp-10h]
  int v31; // [esp+14h] [ebp-Ch] BYREF
  int v32; // [esp+18h] [ebp-8h] BYREF
  int v33; // [esp+1Ch] [ebp-4h] BYREF

  v6 = *(_DWORD *)(active_threads + 12); /*0x1545a8*/
  v30 = *(_DWORD *)(v6 + 136); /*0x1545b1*/
  target_task = *(_DWORD *)(v6 + 12); /*0x1545b7*/
  v7 = a3 + 3; /*0x1545bf*/
  LOBYTE(v7) = (a3 + 3) & 0xFC; /*0x1545c1*/
  if ( v7 > 0x2000 ) /*0x1545cc*/
    return -109; /*0x1545d3*/
  v9 = ipc_kmsg_get(a1, v7, a3 - v7, (unsigned int **)&v33); /*0x1545e2*/
  if ( v9 ) /*0x1545ee*/
    return msg_return_translate(v9); /*0x1545f6*/
  v10 = ipc_kmsg_copyin_compat((_DWORD *)v33, v30, target_task); /*0x154619*/
  if ( v10 ) /*0x154620*/
  {
    if ( *(int *)(v33 + 8) > 0 ) /*0x15462a*/
      kfree(v33, *(_DWORD *)(v33 + 8)); /*0x1545fe*/
    else
      ipc_kmsg_free(v33); /*0x15462d*/
    return msg_return_translate(v10); /*0x15463b*/
  }
  v11 = *(_DWORD *)(v33 + 32); /*0x154643*/
  if ( v11 && v11 != -1 ) /*0x154651*/
  {
    v12 = *(_DWORD *)(v33 + 28); /*0x154657*/
    ipc_object_reference(*(_DWORD *)(v33 + 32)); /*0x15465b*/
    do /*0x154676*/
    {
      while ( *(_DWORD *)v12 ) /*0x154664*/
        ; /*0x154666*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v12, 1) == 1 ); /*0x154676*/
    if ( *(_DWORD *)(v12 + 12) == ipc_space_kernel ) /*0x154680*/
    {
      _InterlockedExchange((volatile __int32 *)v12, 0); /*0x154688*/
      v33 = ipc_kobject_server(v33); /*0x154693*/
      if ( v33 ) /*0x15469b*/
      {
        do /*0x1546b6*/
        {
          while ( *(_DWORD *)v11 ) /*0x1546a4*/
            ; /*0x1546a6*/
        }
        while ( _InterlockedExchange((volatile __int32 *)v11, 1) == 1 ); /*0x1546b6*/
        if ( *(int *)(v11 + 8) < 0 /*0x1546da*/
          && *(_DWORD *)(v11 + 12) == v30
          && !*(_DWORD *)(v11 + 48)
          && a4 >= *(_DWORD *)(v33 + 16) + *(_DWORD *)(v33 + 24) )
        {
          v13 = (volatile __int32 *)(v11 + 64); /*0x1546dc*/
          do /*0x1546f2*/
          {
            while ( *v13 ) /*0x1546e0*/
              ; /*0x1546e2*/
          }
          while ( _InterlockedExchange(v13, 1) == 1 ); /*0x1546f2*/
          if ( !*(_DWORD *)(v11 + 72) && !*(_DWORD *)(v11 + 68) ) /*0x1546fe*/
          {
            ++*(_DWORD *)(v11 + 52); /*0x154724*/
            _InterlockedExchange(v13, 0); /*0x154729*/
            --*(_DWORD *)(v11 + 4); /*0x15472b*/
            _InterlockedExchange((volatile __int32 *)v11, 0); /*0x154730*/
            goto LABEL_80; /*0x154732*/
          }
          _InterlockedExchange(v13, 0); /*0x154702*/
        }
        _InterlockedExchange((volatile __int32 *)v11, 0); /*0x154706*/
        ipc_mqueue_send(v33, 0x10000, 0, 0); /*0x154715*/
      }
LABEL_54:
      if ( !v11 || v11 == -1 ) /*0x154853*/
        return -202; /*0x154853*/
      do /*0x15486a*/
      {
        while ( *(_DWORD *)v11 ) /*0x154858*/
          ; /*0x15485a*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v11, 1) == 1 ); /*0x15486a*/
      if ( *(_DWORD *)(v11 + 12) != v30 ) /*0x154872*/
      {
        v17 = *(_DWORD *)(v11 + 4) - 1; /*0x154877*/
        *(_DWORD *)(v11 + 4) = v17; /*0x15487a*/
        _InterlockedExchange((volatile __int32 *)v11, 0); /*0x154880*/
        if ( !v17 ) /*0x154884*/
          zfree(ipc_object_zones[*(_WORD *)(v11 + 10) & 0x7FFF], v11); /*0x154898*/
        return -202; /*0x15489d*/
      }
      v18 = *(_DWORD *)(v11 + 48); /*0x1548a0*/
      if ( v18 ) /*0x1548a5*/
      {
        do /*0x1548ba*/
        {
          while ( *(_DWORD *)v18 ) /*0x1548a8*/
            ; /*0x1548aa*/
        }
        while ( _InterlockedExchange((volatile __int32 *)v18, 1) == 1 ); /*0x1548ba*/
        if ( *(int *)(v18 + 8) < 0 ) /*0x1548c0*/
        {
          _InterlockedExchange((volatile __int32 *)v18, 0); /*0x1548c4*/
          --*(_DWORD *)(v11 + 4); /*0x1548c6*/
          _InterlockedExchange((volatile __int32 *)v11, 0); /*0x1548cb*/
          return -202; /*0x1548d2*/
        }
        ipc_pset_remove(v18, v11); /*0x1548da*/
        v19 = *(_DWORD *)(v18 + 4); /*0x1548e2*/
        _InterlockedExchange((volatile __int32 *)v18, 0); /*0x1548e7*/
        if ( !v19 ) /*0x1548eb*/
          zfree(ipc_object_zones[*(_WORD *)(v18 + 10) & 0x7FFF], v18); /*0x1548ff*/
      }
      v20 = (volatile __int32 *)(v11 + 64); /*0x154907*/
      do /*0x15491e*/
      {
        while ( *v20 ) /*0x15490c*/
          ; /*0x15490e*/
      }
      while ( _InterlockedExchange(v20, 1) == 1 ); /*0x15491e*/
      _InterlockedExchange((volatile __int32 *)v11, 0); /*0x154922*/
      v21 = (_DWORD *)active_threads; /*0x154924*/
      *(_DWORD *)(active_threads + 196) = a1; /*0x15492c*/
      v21[50] = a2; /*0x154932*/
      v21[51] = a4; /*0x15493b*/
      v21[52] = a6; /*0x154944*/
      v21[54] = v11; /*0x15494a*/
      v21[55] = v20; /*0x154950*/
      v22 = -1; /*0x154966*/
      if ( (a2 & 0x1000) != 0 ) /*0x154971*/
        v22 = a4; /*0x154973*/
      v23 = ipc_mqueue_receive(v11 + 64, a2 & 0x100, v22, a6, 0, (int)msg_receive_continue, (unsigned int *)&v33, &v32); /*0x154985*/
      ipc_object_release(v11); /*0x15498b*/
      if ( v23 ) /*0x154995*/
      {
        if ( v23 == 268451844 ) /*0x15499d*/
        {
          v31 = v33; /*0x1549a2*/
          copyout(&v31, a1 + 4, 4); /*0x1549b2*/
        }
        return msg_return_translate(v23); /*0x1549c0*/
      }
      if ( *(_DWORD *)(v33 + 24) > a4 ) /*0x1549cd*/
      {
        ipc_kmsg_destroy((_DWORD *)v33); /*0x1549d0*/
        return -204; /*0x1549da*/
      }
LABEL_80:
      ipc_kmsg_copyout_compat((_DWORD *)v33, v30, target_task); /*0x1549dc*/
      v24 = v33; /*0x1549ed*/
      v25 = *(_DWORD *)(v33 + 16) + *(_DWORD *)(v33 + 24); /*0x1549f3*/
      *(_DWORD *)(v33 + 24) = v25; /*0x1549f6*/
      v26 = ipc_kmsg_put(a1, v24, v25); /*0x1549ff*/
      return msg_return_translate(v26); /*0x154a07*/
    }
    _InterlockedExchange((volatile __int32 *)v12, 0); /*0x15473a*/
  }
  if ( (a2 & 2) == 0 ) /*0x154742*/
  {
    if ( (a2 & 0x20) != 0 ) /*0x1547da*/
    {
      v28 = a5; /*0x1547e1*/
      v16 = 0x20000; /*0x1547e2*/
      if ( (a2 & 1) != 0 ) /*0x1547ed*/
        v16 = 131088; /*0x1547ef*/
    }
    else
    {
      v28 = a5; /*0x1547fd*/
      v16 = 0; /*0x1547fe*/
      if ( (a2 & 1) != 0 ) /*0x154806*/
        v16 = 16; /*0x154808*/
    }
    v10 = ipc_mqueue_send(v33, v16, v28, 0); /*0x154817*/
LABEL_49:
    if ( !v10 ) /*0x15481e*/
      goto LABEL_54; /*0x15481e*/
LABEL_50:
    ipc_kmsg_destroy((_DWORD *)v33); /*0x154820*/
    if ( v11 && v11 != -1 ) /*0x154833*/
      ipc_object_release(v11); /*0x154836*/
    return msg_return_translate(v10); /*0x154836*/
  }
  v14 = 0; /*0x15474a*/
  if ( (a2 & 1) != 0 ) /*0x154752*/
    v14 = a5; /*0x154754*/
  v27 = v14; /*0x154757*/
  v15 = 16; /*0x154758*/
  if ( (a2 & 0x20) != 0 ) /*0x154763*/
    v15 = 131088; /*0x154765*/
  v10 = ipc_mqueue_send(v33, v15, v27, 0); /*0x154774*/
  if ( v10 != 268435460 ) /*0x15477f*/
    goto LABEL_49; /*0x15477f*/
  v10 = ipc_marequest_create(v30, *(volatile __int32 **)(v33 + 28), 0, (unsigned int **)(v33 + 12)); /*0x15479b*/
  if ( v10 ) /*0x1547a2*/
    goto LABEL_50; /*0x1547a2*/
  ipc_mqueue_send(v33, 0x10000, 0, 0); /*0x1547b1*/
  if ( v11 && v11 != -1 ) /*0x1547c0*/
    ipc_object_release(v11); /*0x1547c3*/
  return -105; /*0x154a0f*/
}
