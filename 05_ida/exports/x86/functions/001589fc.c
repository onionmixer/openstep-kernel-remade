/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1589fc. */
int __cdecl msg_rpc(_DWORD *a1, __int16 a2, unsigned int a3, int a4, int a5)
{
  int v5; // eax
  int v6; // ebx
  unsigned int v7; // edx
  int v8; // ebx
  int v10; // eax
  int v11; // esi
  int v12; // ebx
  volatile __int32 *v13; // edx
  int v14; // eax
  int v15; // ecx
  int v16; // ebx
  int v17; // eax
  volatile __int32 *v18; // edx
  unsigned int v19; // eax
  int v20; // eax
  int v21; // ebx
  unsigned int v22; // eax
  int v23; // eax
  size_t v24; // edx
  int v25; // eax
  size_t v26; // edx
  int v27; // [esp-8h] [ebp-40h]
  int v28; // [esp+Ch] [ebp-2Ch]
  int v29; // [esp+Ch] [ebp-2Ch]
  int v30; // [esp+Ch] [ebp-2Ch]
  int v31; // [esp+Ch] [ebp-2Ch]
  unsigned int v32; // [esp+10h] [ebp-28h]
  vm_map_t v33; // [esp+14h] [ebp-24h]
  vm_map_t target_task; // [esp+18h] [ebp-20h]
  int v35; // [esp+1Ch] [ebp-1Ch]
  int v36; // [esp+20h] [ebp-18h] BYREF
  int v37; // [esp+24h] [ebp-14h] BYREF
  int v38; // [esp+28h] [ebp-10h] BYREF
  volatile __int32 *v39; // [esp+2Ch] [ebp-Ch] BYREF
  int v40; // [esp+30h] [ebp-8h] BYREF
  int v41; // [esp+34h] [ebp-4h] BYREF

  v5 = *(_DWORD *)(active_threads + 12); /*0x158a0a*/
  v35 = *(_DWORD *)(v5 + 136); /*0x158a13*/
  target_task = *(_DWORD *)(v5 + 12); /*0x158a19*/
  v6 = a1[1]; /*0x158a22*/
  v7 = v6 + 3; /*0x158a27*/
  LOBYTE(v7) = (v6 + 3) & 0xFC; /*0x158a29*/
  v8 = v6 - v7; /*0x158a2c*/
  if ( v7 > 0x2000 ) /*0x158a34*/
    return -109; /*0x158a3b*/
  v10 = ipc_kmsg_get_from_kernel(a1, v7, v8, &v41); /*0x158a4a*/
  if ( v10 ) /*0x158a57*/
    return msg_return_translate(v10); /*0x158a5f*/
  v28 = ipc_kmsg_copyin_compat((_DWORD *)v41, v35, target_task); /*0x158a81*/
  if ( v28 ) /*0x158a89*/
  {
    if ( *(int *)(v41 + 8) > 0 ) /*0x158a93*/
      kfree(v41, *(_DWORD *)(v41 + 8)); /*0x158a66*/
    else
      ipc_kmsg_free(v41); /*0x158a96*/
    return msg_return_translate(v28); /*0x158aa7*/
  }
  v11 = *(_DWORD *)(v41 + 32); /*0x158aaf*/
  if ( !v11 || v11 == -1 ) /*0x158abd*/
    goto LABEL_32; /*0x158abd*/
  v12 = *(_DWORD *)(v41 + 28); /*0x158ac3*/
  ipc_object_reference(*(_DWORD *)(v41 + 32)); /*0x158ac7*/
  do /*0x158ae2*/
  {
    while ( *(_DWORD *)v12 ) /*0x158ad0*/
      ; /*0x158ad2*/
  }
  while ( _InterlockedExchange((volatile __int32 *)v12, 1) == 1 ); /*0x158ae2*/
  if ( *(_DWORD *)(v12 + 12) != ipc_space_kernel ) /*0x158aec*/
  {
    _InterlockedExchange((volatile __int32 *)v12, 0); /*0x158bba*/
LABEL_32:
    if ( (a2 & 2) != 0 ) /*0x158bc2*/
      panic(aMsgRpcNotify); /*0x158bc9*/
    do /*0x158c40*/
    {
      if ( (a2 & 0x20) != 0 ) /*0x158bd8*/
      {
        v27 = a4; /*0x158bdf*/
        v14 = 0x20000; /*0x158be0*/
        if ( (a2 & 1) != 0 ) /*0x158be9*/
          v14 = 131088; /*0x158beb*/
      }
      else
      {
        v27 = a4; /*0x158bf9*/
        v14 = 0; /*0x158bfa*/
        if ( (a2 & 1) != 0 ) /*0x158c00*/
          v14 = 16; /*0x158c02*/
      }
      v28 = ipc_mqueue_send(v41, v14, v27, 0); /*0x158c11*/
      if ( v28 != 268435463 ) /*0x158c1e*/
        break; /*0x158c1e*/
      while ( (*(_BYTE *)(active_threads + 380) & 3) != 0 ) /*0x158c3a*/
        thread_halt_self_with_continuation(0); /*0x158c26*/
    }
    while ( (a2 & 4) == 0 ); /*0x158c40*/
    if ( v28 ) /*0x158c4f*/
    {
      ipc_kmsg_destroy((_DWORD *)v41); /*0x158c55*/
      if ( v11 && v11 != -1 ) /*0x158c64*/
        ipc_object_release(v11); /*0x158c67*/
      return msg_return_translate(v28); /*0x158c67*/
    }
    goto LABEL_49; /*0x158c4f*/
  }
  _InterlockedExchange((volatile __int32 *)v12, 0); /*0x158af4*/
  v41 = (int)ipc_kobject_server(v41); /*0x158aff*/
  if ( v41 ) /*0x158b07*/
  {
    do /*0x158b22*/
    {
      while ( *(_DWORD *)v11 ) /*0x158b10*/
        ; /*0x158b12*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v11, 1) == 1 ); /*0x158b22*/
    if ( *(int *)(v11 + 8) < 0 /*0x158b46*/
      && *(_DWORD *)(v11 + 12) == v35
      && !*(_DWORD *)(v11 + 48)
      && a3 >= *(_DWORD *)(v41 + 16) + *(_DWORD *)(v41 + 24) )
    {
      v13 = (volatile __int32 *)(v11 + 64); /*0x158b5c*/
      do /*0x158b72*/
      {
        while ( *v13 ) /*0x158b60*/
          ; /*0x158b62*/
      }
      while ( _InterlockedExchange(v13, 1) == 1 ); /*0x158b72*/
      if ( !*(_DWORD *)(v11 + 72) && !*(_DWORD *)(v11 + 68) ) /*0x158b7e*/
      {
        ++*(_DWORD *)(v11 + 52); /*0x158ba4*/
        _InterlockedExchange(v13, 0); /*0x158ba9*/
        --*(_DWORD *)(v11 + 4); /*0x158bab*/
        _InterlockedExchange((volatile __int32 *)v11, 0); /*0x158bb0*/
LABEL_96:
        v31 = ipc_kmsg_copyout_compat((_DWORD *)v41, v35, target_task); /*0x158f48*/
        v25 = v41; /*0x158f5c*/
        v26 = *(_DWORD *)(v41 + 16) + *(_DWORD *)(v41 + 24); /*0x158f62*/
        *(_DWORD *)(v41 + 24) = v26; /*0x158f65*/
        ipc_kmsg_put_to_kernel(a1, v25, v26); /*0x158f6e*/
        return msg_return_translate(v31); /*0x158f77*/
      }
      _InterlockedExchange(v13, 0); /*0x158b82*/
      _InterlockedExchange((volatile __int32 *)v11, 0); /*0x158b86*/
      ipc_mqueue_send(v41, 0x10000, 0, 0); /*0x158b95*/
    }
    else
    {
      _InterlockedExchange((volatile __int32 *)v11, 0); /*0x158b4a*/
      ipc_mqueue_send(v41, 0x10000, 0, 0); /*0x158b59*/
    }
  }
LABEL_49:
  if ( !v11 || v11 == -1 ) /*0x158c87*/
    return -202; /*0x158c87*/
  do /*0x158c9e*/
  {
    while ( *(_DWORD *)v11 ) /*0x158c8c*/
      ; /*0x158c8e*/
  }
  while ( _InterlockedExchange((volatile __int32 *)v11, 1) == 1 ); /*0x158c9e*/
  if ( *(_DWORD *)(v11 + 12) != v35 ) /*0x158ca6*/
  {
    v15 = *(_DWORD *)(v11 + 4) - 1; /*0x158cab*/
    *(_DWORD *)(v11 + 4) = v15; /*0x158cae*/
    _InterlockedExchange((volatile __int32 *)v11, 0); /*0x158cb4*/
    if ( !v15 ) /*0x158cb8*/
      zfree(ipc_object_zones[*(_WORD *)(v11 + 10) & 0x7FFF], v11); /*0x158ccc*/
    return -202; /*0x158cd1*/
  }
  v16 = *(_DWORD *)(v11 + 48); /*0x158cd4*/
  if ( v16 ) /*0x158cd9*/
  {
    do /*0x158cee*/
    {
      while ( *(_DWORD *)v16 ) /*0x158cdc*/
        ; /*0x158cde*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v16, 1) == 1 ); /*0x158cee*/
    if ( *(int *)(v16 + 8) < 0 ) /*0x158cf4*/
    {
      _InterlockedExchange((volatile __int32 *)v16, 0); /*0x158cf8*/
      --*(_DWORD *)(v11 + 4); /*0x158cfa*/
      _InterlockedExchange((volatile __int32 *)v11, 0); /*0x158cff*/
      return -202; /*0x158d06*/
    }
    ipc_pset_remove(v16, v11); /*0x158d0e*/
    v17 = *(_DWORD *)(v16 + 4); /*0x158d16*/
    _InterlockedExchange((volatile __int32 *)v16, 0); /*0x158d1b*/
    if ( !v17 ) /*0x158d1f*/
      zfree(ipc_object_zones[*(_WORD *)(v16 + 10) & 0x7FFF], v16); /*0x158d33*/
  }
  v18 = (volatile __int32 *)(v11 + 64); /*0x158d3b*/
  do /*0x158d52*/
  {
    while ( *v18 ) /*0x158d40*/
      ; /*0x158d42*/
  }
  while ( _InterlockedExchange(v18, 1) == 1 ); /*0x158d52*/
  _InterlockedExchange((volatile __int32 *)v11, 0); /*0x158d56*/
  v19 = -1; /*0x158d68*/
  if ( (a2 & 0x1000) != 0 ) /*0x158d73*/
    v19 = a3; /*0x158d75*/
  v29 = ipc_mqueue_receive(v11 + 64, a2 & 0x100, v19, a5, 0, 0, (unsigned int *)&v41, &v40); /*0x158d88*/
  ipc_object_release(v11); /*0x158d8f*/
  if ( !v29 ) /*0x158d9b*/
  {
    if ( *(_DWORD *)(v41 + 24) > a3 ) /*0x158f31*/
    {
      ipc_kmsg_destroy((_DWORD *)v41); /*0x158f34*/
      return msg_return_translate(268451844); /*0x158f43*/
    }
    goto LABEL_96; /*0x158f31*/
  }
  if ( v29 != 268451845 ) /*0x158da8*/
  {
    if ( v29 == 268451844 ) /*0x158f0f*/
      a1[1] = v41; /*0x158f17*/
    return msg_return_translate(v29); /*0x158f17*/
  }
  while ( (*(_BYTE *)(active_threads + 380) & 3) != 0 ) /*0x158dc6*/
    thread_halt_self_with_continuation(0); /*0x158db2*/
  a1[1] = a3; /*0x158dce*/
  if ( (a2 & 0x400) != 0 ) /*0x158dda*/
    return msg_return_translate(v29); /*0x158f23*/
  v20 = *(_DWORD *)(active_threads + 12); /*0x158de5*/
  v30 = *(_DWORD *)(v20 + 136); /*0x158dee*/
  v33 = *(_DWORD *)(v20 + 12); /*0x158df4*/
  v32 = a1[3]; /*0x158dfd*/
  while ( 1 ) /*0x158e19*/
  {
    v21 = ipc_mqueue_copyin(v30, v32, &v39, &v38); /*0x158e19*/
    if ( v21 ) /*0x158e20*/
      break; /*0x158e20*/
    v22 = -1; /*0x158e36*/
    if ( (a2 & 0x1000) != 0 ) /*0x158e3f*/
      v22 = a3; /*0x158e41*/
    v21 = ipc_mqueue_receive((int)v39, a2 & 0x100, v22, a5, 0, 0, (unsigned int *)&v37, &v36); /*0x158e56*/
    ipc_object_release(v38); /*0x158e5f*/
    if ( v21 == 268451845 ) /*0x158e6d*/
    {
      while ( (*(_BYTE *)(active_threads + 380) & 3) != 0 ) /*0x158e8a*/
        thread_halt_self_with_continuation(0); /*0x158e76*/
      if ( (a2 & 0x400) == 0 ) /*0x158e90*/
        continue; /*0x158e90*/
    }
    if ( v21 ) /*0x158ea0*/
    {
      if ( v21 == 268451844 ) /*0x158ea8*/
        a1[1] = v37; /*0x158eb0*/
    }
    else
    {
      if ( *(_DWORD *)(v37 + 24) > a3 ) /*0x158ebe*/
      {
        ipc_kmsg_destroy((_DWORD *)v37); /*0x158ec1*/
        return msg_return_translate(268451844); /*0x158ed0*/
      }
      v21 = ipc_kmsg_copyout_compat((_DWORD *)v37, v30, v33); /*0x158ee6*/
      v23 = v37; /*0x158ee8*/
      v24 = *(_DWORD *)(v37 + 16) + *(_DWORD *)(v37 + 24); /*0x158eee*/
      *(_DWORD *)(v37 + 24) = v24; /*0x158ef1*/
      ipc_kmsg_put_to_kernel(a1, v23, v24); /*0x158efa*/
    }
    return msg_return_translate(v21); /*0x158eb3*/
  }
  return msg_return_translate(v21); /*0x158f7f*/
}
