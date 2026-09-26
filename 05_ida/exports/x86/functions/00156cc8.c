/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x156cc8. */
kern_return_t __cdecl exception_raise(
        mach_port_t exception_port,
        mach_port_t thread,
        mach_port_t task,
        exception_type_t exception,
        exception_data_t code,
        mach_msg_type_number_t codeCnt)
{
  _DWORD *v6; // esi
  int v7; // eax
  volatile __int32 *v8; // edx
  volatile __int32 *v9; // edx
  int v10; // eax
  int v11; // edi
  int (*v12)(); // eax
  int v13; // edx
  int v14; // eax
  int v15; // edx
  int v16; // eax
  int v17; // ebx
  volatile __int32 *v18; // edx
  int v19; // edx
  int v20; // ebx
  _DWORD *v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // ebx
  int v25; // eax
  int (*v27)(); // eax
  mach_port_t v28; // [esp+Ch] [ebp-24h]
  int v29; // [esp+Ch] [ebp-24h]
  int v30; // [esp+Ch] [ebp-24h]
  __int64 v31; // [esp+Ch] [ebp-24h]
  int v32; // [esp+Ch] [ebp-24h]
  int v33; // [esp+Ch] [ebp-24h]
  int v34; // [esp+Ch] [ebp-24h]
  int v35; // [esp+Ch] [ebp-24h]
  int v36; // [esp+14h] [ebp-1Ch]
  unsigned int *v37; // [esp+18h] [ebp-18h]
  volatile __int32 *v38; // [esp+1Ch] [ebp-14h]
  volatile __int32 *v39; // [esp+20h] [ebp-10h]
  thread_act_t v40; // [esp+24h] [ebp-Ch]
  int v41; // [esp+28h] [ebp-8h] BYREF
  unsigned int v42; // [esp+2Ch] [ebp-4h] BYREF

  v40 = active_threads; /*0x156cd7*/
  v6 = (_DWORD *)ipc_kmsg_cache; /*0x156cda*/
  if ( ipc_kmsg_cache ) /*0x156ce2*/
  {
    ipc_kmsg_cache = 0; /*0x156ce4*/
  }
  else
  {
    v7 = kalloc(0x100u); /*0x156cf5*/
    v6 = (_DWORD *)v7; /*0x156cfa*/
    if ( !v7 ) /*0x156d01*/
      panic(aExceptionRaise); /*0x156d08*/
    *(_DWORD *)(v7 + 8) = 256; /*0x156d10*/
    *(_DWORD *)(v7 + 12) = 0; /*0x156d17*/
  }
  v6[4] = 0; /*0x156d1e*/
  v8 = (volatile __int32 *)(v40 + 168); /*0x156d28*/
  do /*0x156d42*/
  {
    while ( *v8 ) /*0x156d30*/
      ; /*0x156d32*/
  }
  while ( _InterlockedExchange(v8, 1) == 1 ); /*0x156d42*/
  v39 = *(volatile __int32 **)(v40 + 192); /*0x156d4d*/
  if ( !v39 ) /*0x156d52*/
  {
    _InterlockedExchange((volatile __int32 *)(v40 + 168), 0); /*0x156d65*/
    v39 = ipc_port_alloc_special(ipc_space_reply); /*0x156d77*/
    v9 = (volatile __int32 *)(v40 + 168); /*0x156d7a*/
    do /*0x156d92*/
    {
      while ( *v9 ) /*0x156d80*/
        ; /*0x156d82*/
    }
    while ( _InterlockedExchange(v9, 1) == 1 ); /*0x156d92*/
    if ( !v39 || *(_DWORD *)(v40 + 192) ) /*0x156d9d*/
      panic(aExceptionRaise_0); /*0x156dab*/
    *(_DWORD *)(v40 + 192) = v39; /*0x156db9*/
  }
  do /*0x156dd8*/
  {
    while ( *v39 ) /*0x156dc3*/
      ; /*0x156dc5*/
  }
  while ( _InterlockedExchange(v39, 1) == 1 ); /*0x156dd8*/
  _InterlockedExchange((volatile __int32 *)(v40 + 168), 0); /*0x156ddf*/
  ++*((_DWORD *)v39 + 8); /*0x156de5*/
  *((_DWORD *)v39 + 1) += 2; /*0x156de8*/
  *(_DWORD *)(v40 + 196) = v39; /*0x156dec*/
  v38 = v39 + 16; /*0x156df5*/
  do /*0x156e10*/
  {
    while ( *v38 ) /*0x156dfb*/
      ; /*0x156dfd*/
  }
  while ( _InterlockedExchange(v38, 1) == 1 ); /*0x156e10*/
  _InterlockedExchange(v39, 0); /*0x156e17*/
  if ( _InterlockedExchange((volatile __int32 *)exception_port, 1) != 1 )
  {
    if ( *(int *)(exception_port + 8) < 0
      && *(_DWORD *)(exception_port + 12) != ipc_space_kernel
      && ((v10 = *(_DWORD *)(exception_port + 48)) != 0 ? (v28 = v10 + 16) : (v28 = exception_port + 64),
          _InterlockedExchange((volatile __int32 *)v28, 1) ^ 1) )
    {
      _InterlockedExchange((volatile __int32 *)exception_port, 0); /*0x156e91*/
      v11 = *(_DWORD *)(v28 + 8); /*0x156e96*/
      if ( v11 /*0x156ed3*/
        && *(_DWORD *)(v40 + 56)
        && ((v12 = *(int (**)())(v11 + 52), v12 == mach_msg_continue)
         || v12 == mach_msg_receive_continue && *(_DWORD *)(v11 + 156) > 0x3Fu && (*(_BYTE *)(v11 + 201) & 2) == 0)
        && thread_handoff(v40, exception_raise_continue, *(_DWORD *)(v28 + 8)) )
      {
        v13 = *((_DWORD *)v39 + 18); /*0x156f0f*/
        if ( v13 ) /*0x156f14*/
        {
          v14 = *(_DWORD *)(v13 + 148); /*0x156f16*/
          *(_DWORD *)(v40 + 144) = v13; /*0x156f1f*/
          *(_DWORD *)(v40 + 148) = v14; /*0x156f25*/
          *(_DWORD *)(v13 + 148) = v40; /*0x156f2b*/
          *(_DWORD *)(v14 + 144) = v40; /*0x156f31*/
        }
        else
        {
          *((_DWORD *)v39 + 18) = v40; /*0x156efa*/
        }
        *(_DWORD *)(v40 + 152) = 268451841; /*0x156f3a*/
        *(_DWORD *)(v40 + 156) = -1; /*0x156f44*/
        _InterlockedExchange(v38, 0); /*0x156f53*/
        v15 = *(_DWORD *)(v11 + 144); /*0x156f55*/
        if ( v15 == v11 ) /*0x156f5d*/
        {
          *(_DWORD *)(v28 + 8) = 0; /*0x156f03*/
        }
        else
        {
          v16 = *(_DWORD *)(v11 + 148); /*0x156f5f*/
          *(_DWORD *)(v28 + 8) = v15; /*0x156f68*/
          *(_DWORD *)(v15 + 148) = v16; /*0x156f6b*/
          *(_DWORD *)(v16 + 144) = v15; /*0x156f71*/
          *(_DWORD *)(v11 + 144) = v11; /*0x156f77*/
          *(_DWORD *)(v11 + 148) = v11; /*0x156f7d*/
        }
        _InterlockedExchange((volatile __int32 *)v28, 0); /*0x156f88*/
        v29 = *(_DWORD *)(v11 + 216); /*0x156f90*/
        do /*0x156fac*/
        {
          while ( *(_DWORD *)v29 ) /*0x156f97*/
            ; /*0x156f99*/
        }
        while ( _InterlockedExchange((volatile __int32 *)v29, 1) == 1 ); /*0x156fac*/
        v17 = *(_DWORD *)(v29 + 4) - 1; /*0x156fb1*/
        *(_DWORD *)(v29 + 4) = v17; /*0x156fb4*/
        _InterlockedExchange((volatile __int32 *)v29, 0); /*0x156fba*/
        if ( !v17 ) /*0x156fbe*/
          zfree(ipc_object_zones[*(_WORD *)(v29 + 10) & 0x7FFF], v29); /*0x156fd2*/
        v37 = v6 + 5; /*0x156fdd*/
        v36 = *(_DWORD *)(*(_DWORD *)(v11 + 12) + 136); /*0x156fe9*/
        v6[5] = -2147479278; /*0x156fec*/
        v6[6] = 64; /*0x156ff3*/
        v6[9] = 0; /*0x156ffa*/
        v6[10] = 2400; /*0x157001*/
        v6[11] = exc_port_proto; /*0x15700e*/
        v6[13] = exc_port_proto; /*0x157017*/
        v6[15] = exc_code_proto; /*0x157020*/
        v6[16] = exception; /*0x157026*/
        v6[17] = exc_code_proto; /*0x15702f*/
        v6[18] = code; /*0x157035*/
        v6[19] = exc_code_proto; /*0x15703e*/
        v6[20] = codeCnt; /*0x157044*/
        if ( *(_DWORD *)(v11 + 204) <= 0x3Fu ) /*0x15704e*/
        {
          v6[5] = -2147479023; /*0x157050*/
          v6[7] = exception_port; /*0x15705a*/
          v6[8] = v39; /*0x157060*/
          v6[12] = thread; /*0x157066*/
          v6[14] = task; /*0x15706c*/
          ipc_kmsg_destroy(v6); /*0x157070*/
          thread_syscall_return(268451844); /*0x15707a*/
        }
        v18 = (volatile __int32 *)(v36 + 8); /*0x157085*/
        do /*0x15709a*/
        {
          while ( *v18 ) /*0x157088*/
            ; /*0x15708a*/
        }
        while ( _InterlockedExchange(v18, 1) == 1 ); /*0x15709a*/
        do /*0x1570b4*/
        {
          while ( *(_DWORD *)exception_port ) /*0x15709f*/
            ; /*0x1570a1*/
        }
        while ( _InterlockedExchange((volatile __int32 *)exception_port, 1) == 1 ); /*0x1570b4*/
        if ( *(int *)(exception_port + 8) < 0 && _InterlockedExchange(v39, 1) != 1 ) /*0x1570c6*/
          goto LABEL_61; /*0x1570cb*/
        while ( 1 ) /*0x1570d2*/
        {
          _InterlockedExchange((volatile __int32 *)exception_port, 0); /*0x1570d2*/
          _InterlockedExchange((volatile __int32 *)(v36 + 8), 0); /*0x1570d9*/
          *v37 = -2147479023; /*0x1570df*/
          v6[7] = exception_port; /*0x1570e8*/
          v6[8] = v39; /*0x1570ee*/
          v30 = ipc_kmsg_copyout_header(v37, v36, 0); /*0x157100*/
          if ( !v30 ) /*0x157108*/
            break; /*0x157108*/
          v6[12] = thread; /*0x157111*/
          v6[14] = task; /*0x157117*/
          ipc_kmsg_copyout_dest(v6, v36); /*0x15711f*/
          ipc_kmsg_put(*(_DWORD *)(v11 + 196), (int)v6, 24); /*0x15712e*/
          thread_syscall_return(v30); /*0x157137*/
LABEL_61:
          if ( *((int *)v39 + 2) < 0 ) /*0x157146*/
          {
            _InterlockedExchange(v39, 0); /*0x157159*/
            v19 = *(_DWORD *)(v36 + 20); /*0x15715e*/
            v20 = *(_DWORD *)(v19 + 8); /*0x157161*/
            HIDWORD(v31) = v20; /*0x157164*/
            if ( v20 ) /*0x157169*/
            {
              v21 = (_DWORD *)(v19 + 16 * v20); /*0x157174*/
              *(_DWORD *)(v19 + 8) = v21[2]; /*0x157179*/
              v21[2] = 0; /*0x15717c*/
              LODWORD(v31) = *v21 + 0x1000000; /*0x15718b*/
              v6[7] = v31 >> 24; /*0x15719e*/
              *v21 = v31 | 0x40001; /*0x1571aa*/
              v21[1] = v39; /*0x1571af*/
              _InterlockedExchange((volatile __int32 *)(v36 + 8), 0); /*0x1571b7*/
              --*(_DWORD *)(exception_port + 4); /*0x1571bd*/
              v22 = 0; /*0x1571c0*/
              if ( *(_DWORD *)(exception_port + 12) == v36 ) /*0x1571c5*/
                v22 = *(_DWORD *)(exception_port + 16); /*0x1571c7*/
              v6[8] = v22; /*0x1571cd*/
              v23 = *(_DWORD *)(exception_port + 28); /*0x1571d3*/
              *(_DWORD *)(exception_port + 28) = v23 - 1; /*0x1571d9*/
              if ( v23 == 1 && (v24 = *(_DWORD *)(exception_port + 36)) != 0 ) /*0x1571e9*/
              {
                v25 = *(_DWORD *)(exception_port + 24); /*0x1571ee*/
                *(_DWORD *)(exception_port + 36) = 0; /*0x1571f1*/
                _InterlockedExchange((volatile __int32 *)exception_port, 0); /*0x1571fa*/
                ipc_notify_no_senders(v24, v25); /*0x1571fe*/
              }
              else
              {
                _InterlockedExchange((volatile __int32 *)exception_port, 0); /*0x15720d*/
              }
              break; /*0x157206*/
            }
          }
          else
          {
            _InterlockedExchange(v39, 0); /*0x15714a*/
          }
        }
        v32 = ipc_kmsg_copyout_object(v36, thread, 17, v6 + 12); /*0x15720f*/
        v33 = v32 | ipc_kmsg_copyout_object(v36, task, 17, v6 + 14); /*0x15723e*/
        if ( v33 ) /*0x157246*/
        {
          ipc_kmsg_put(*(_DWORD *)(v11 + 196), (int)v6, v6[6]); /*0x157254*/
          thread_syscall_return(v33 | 0x1000400C); /*0x157262*/
        }
        v6[4] = 0; /*0x15726a*/
        if ( copyoutmsg(v6 + 5, *(_DWORD *)(v11 + 196), 64) || ipc_kmsg_cache ) /*0x157291*/
        {
          v34 = ipc_kmsg_put(*(_DWORD *)(v11 + 196), (int)v6, v6[6]); /*0x1572a4*/
          thread_syscall_return(v34); /*0x1572a8*/
        }
        ipc_kmsg_cache = (int)v6; /*0x1572b0*/
        thread_syscall_return(0); /*0x1572b8*/
      }
      else
      {
        _InterlockedExchange(v38, 0); /*0x156ee4*/
        _InterlockedExchange((volatile __int32 *)v28, 0); /*0x156eeb*/
      }
    }
    else
    {
      _InterlockedExchange(v38, 0); /*0x156e7c*/
      _InterlockedExchange((volatile __int32 *)exception_port, 0); /*0x156e83*/
    }
  }
  else
  {
    _InterlockedExchange(v38, 0); /*0x156e2f*/
  }
  ++exception_raise_misses; /*0x1572c0*/
  v6[5] = -2147479023; /*0x1572c6*/
  v6[6] = 64; /*0x1572cd*/
  v6[7] = exception_port; /*0x1572d7*/
  v6[8] = v39; /*0x1572dd*/
  v6[9] = 0; /*0x1572e0*/
  v6[10] = 2400; /*0x1572e7*/
  v6[11] = exc_port_proto; /*0x1572f4*/
  v6[12] = thread; /*0x1572fa*/
  v6[13] = exc_port_proto; /*0x157303*/
  v6[14] = task; /*0x157309*/
  v6[15] = exc_code_proto; /*0x157312*/
  v6[16] = exception; /*0x157318*/
  v6[17] = exc_code_proto; /*0x157321*/
  v6[18] = code; /*0x157327*/
  v6[19] = exc_code_proto; /*0x157330*/
  v6[20] = codeCnt; /*0x157336*/
  ipc_mqueue_send((int)v6, 0x10000, 0, 0); /*0x157343*/
  do /*0x157367*/
  {
    while ( *v39 ) /*0x15734f*/
      ; /*0x157354*/
  }
  while ( _InterlockedExchange(v39, 1) == 1 ); /*0x157367*/
  if ( *((int *)v39 + 2) < 0 ) /*0x15736d*/
  {
    do /*0x157398*/
    {
      while ( *v38 ) /*0x157383*/
        ; /*0x157385*/
    }
    while ( _InterlockedExchange(v38, 1) == 1 ); /*0x157398*/
    _InterlockedExchange(v39, 0); /*0x15739f*/
    v27 = nullptr; /*0x1573a9*/
    if ( *(_DWORD *)(v40 + 56) ) /*0x1573ae*/
      v27 = exception_raise_continue; /*0x1573b4*/
    v35 = ipc_mqueue_receive((int)v38, 0, 0xFFFFFFFF, 0, 0, (int)v27, &v42, &v41); /*0x1573cb*/
    return exception_raise_continue_slow(v35, v42, v41); /*0x1573dd*/
  }
  else
  {
    _InterlockedExchange(v39, 0); /*0x157371*/
    return exception_raise_continue_slow(268451849, 0, 0); /*0x15737c*/
  }
}
