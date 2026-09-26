/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16c1c4. */
void __noreturn kern_server_main()
{
  int v0; // eax
  int v1; // edx
  _DWORD *v2; // eax
  _DWORD *v3; // ecx
  int v4; // ebx
  _DWORD *v5; // edx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  _DWORD *v12; // eax
  volatile __int32 *v13; // edx
  _DWORD *i; // ecx
  int v15; // ebx
  _DWORD *v16; // edx
  volatile __int32 *v17; // eax
  volatile __int32 *v18; // edx
  _DWORD *v19; // ecx
  _DWORD *v20; // eax
  int v21; // eax
  unsigned int v22; // ebx
  int v23; // eax
  int (__cdecl *v24)(_DWORD); // eax
  void (__cdecl *v25)(_DWORD, int); // eax
  void (__cdecl *v26)(_DWORD, _DWORD); // eax
  _DWORD *v27; // ebx
  _DWORD *v28; // ecx
  void *v29; // eax
  int v30; // [esp-4h] [ebp-68h]
  _DWORD *v31; // [esp+Ch] [ebp-58h]
  int v32; // [esp+Ch] [ebp-58h]
  _DWORD *j; // [esp+Ch] [ebp-58h]
  int v34; // [esp+10h] [ebp-54h]
  _DWORD *v35; // [esp+10h] [ebp-54h]
  int v36; // [esp+18h] [ebp-4Ch]
  int v37; // [esp+20h] [ebp-44h]
  void *v38; // [esp+24h] [ebp-40h] BYREF
  _DWORD v39[15]; // [esp+28h] [ebp-3Ch] BYREF

  v38 = (void *)kalloc(0x4D4u); /*0x16c1d7*/
  qmemcpy(v39, &kern_serv_proto, sizeof(v39)); /*0x16c1ec*/
  v39[0] = &v38; /*0x16c1f1*/
  v0 = *(_DWORD *)(active_threads + 12); /*0x16c1f9*/
  if ( kernel_task != v0 ) /*0x16c205*/
    *(_DWORD *)(v0 + 80) = 1; /*0x16c207*/
  bzero(v38, 0x4D4u); /*0x16c217*/
  *((_DWORD *)v38 + 306) = -1; /*0x16c21f*/
  v1 = task_self(); /*0x16c22e*/
  v2 = v38; /*0x16c230*/
  *((_DWORD *)v38 + 2) = v1; /*0x16c233*/
  v2[3] = active_threads; /*0x16c23c*/
  *v2 = 0; /*0x16c242*/
  v2[14] = v2 + 13; /*0x16c24b*/
  v2[13] = v2 + 13; /*0x16c24e*/
  v3 = v2 + 15; /*0x16c251*/
  v2[16] = v2 + 15; /*0x16c254*/
  v2[15] = v2 + 15; /*0x16c257*/
  v2[305] = v2 + 304; /*0x16c260*/
  v2[304] = v2 + 304; /*0x16c266*/
  v34 = 19; /*0x16c26c*/
  v4 = 95; /*0x16c273*/
  v31 = v2 + 76; /*0x16c27e*/
  do /*0x16c2b5*/
  {
    v5 = (_DWORD *)v2[16]; /*0x16c284*/
    if ( v3 == v5 ) /*0x16c289*/
      v2[15] = &v2[v4]; /*0x16c28e*/
    else
      v5[2] = &v2[v4]; /*0x16c297*/
    v31[22] = v5; /*0x16c29d*/
    v31[21] = v3; /*0x16c2a0*/
    v2[16] = &v2[v4]; /*0x16c2a6*/
    v4 -= 4; /*0x16c2a9*/
    v31 -= 4; /*0x16c2af*/
    --v34; /*0x16c2b2*/
  }
  while ( v34 >= 0 ); /*0x16c2b5*/
  v6 = thread_self(2); /*0x16c2bd*/
  if ( thread_get_special_port_EXTERNAL(v6) || !v37 )
  {
    printf("k_server: can't find listener port..terminating\n");
    thread_terminate(active_threads); /*0x16c2e6*/
    thread_halt_self(); /*0x16c2eb*/
  }
  *((_DWORD *)v38 + 5) = v37; /*0x16c2f9*/
  v7 = task_self(); /*0x16c300*/
  if ( port_allocate_EXTERNAL(v7) )
  {
    printf("k_server: can't allocate reply port..terminating\n");
    thread_terminate(active_threads); /*0x16c323*/
    thread_halt_self(); /*0x16c328*/
  }
  v8 = thread_self(2); /*0x16c336*/
  if ( thread_set_special_port_EXTERNAL(v8) )
  {
    printf("k_server: can't set reply port..terminating\n");
    thread_terminate(active_threads); /*0x16c359*/
    thread_halt_self(); /*0x16c35e*/
  }
  v9 = task_self(); /*0x16c36a*/
  if ( port_set_allocate_EXTERNAL(v9) )
  {
    printf("k_server: can't allocate port set..terminating\n");
    thread_terminate(active_threads); /*0x16c38d*/
    thread_halt_self(); /*0x16c392*/
  }
  *((_DWORD *)v38 + 8) = v36; /*0x16c3a0*/
  v10 = task_self(); /*0x16c3ab*/
  if ( port_set_add_EXTERNAL(v10) )
  {
    printf("k_server: can't add listener port\n");
    thread_terminate(active_threads); /*0x16c3ce*/
    thread_halt_self(); /*0x16c3d3*/
  }
  if ( port_allocate_EXTERNAL(*((_DWORD *)v38 + 2)) ) /*0x16c3e6*/
    kern_serv_panic(*((_DWORD *)v38 + 4), aKServerCanTGet); /*0x16c418*/
  else
    port_set_add_EXTERNAL(*((_DWORD *)v38 + 2)); /*0x16c401*/
  if ( *(_DWORD *)(active_threads + 12) != kernel_task ) /*0x16c42e*/
  {
    v30 = *((_DWORD *)v38 + 7); /*0x16c436*/
    v11 = task_self(); /*0x16c439*/
    task_set_special_port_EXTERNAL(v11, 2, v30); /*0x16c43f*/
  }
  kern_serv_notify(&v38, *((_DWORD *)v38 + 7), *((_DWORD *)v38 + 4)); /*0x16c456*/
  *((_DWORD *)v38 + 307) = kern_serv_kernel_task_port(); /*0x16c465*/
  v35 = (_DWORD *)kalloc(0x30u); /*0x16c472*/
  v12 = v38; /*0x16c475*/
  *((_DWORD *)v38 + 17) = v35; /*0x16c47b*/
  v12[18] = 48; /*0x16c47e*/
  while ( 1 ) /*0x16c48d*/
  {
    v32 = splhigh(); /*0x16c48d*/
    v13 = (volatile __int32 *)v38; /*0x16c490*/
    do /*0x16c4a6*/
    {
      while ( *v13 ) /*0x16c494*/
        ; /*0x16c496*/
    }
    while ( _InterlockedExchange(v13, 1) == 1 ); /*0x16c4a6*/
    for ( i = v38; (_DWORD *)i[13] != i + 13; i = v20 ) /*0x16c4a8*/
    {
      v15 = i[13]; /*0x16c4b0*/
      v16 = *(_DWORD **)(v15 + 8); /*0x16c4b3*/
      if ( i + 13 == v16 ) /*0x16c4bb*/
        i[14] = v16; /*0x16c4bd*/
      else
        v16[3] = i + 13; /*0x16c4c4*/
      v17 = (volatile __int32 *)v38; /*0x16c4c7*/
      *((_DWORD *)v38 + 13) = v16; /*0x16c4ca*/
      _InterlockedExchange(v17, 0); /*0x16c4cf*/
      splx(v32); /*0x16c4d5*/
      (*(void (__cdecl **)(_DWORD))v15)(*(_DWORD *)(v15 + 4)); /*0x16c4e0*/
      v32 = splhigh(); /*0x16c4e7*/
      v18 = (volatile __int32 *)v38; /*0x16c4ea*/
      do /*0x16c502*/
      {
        while ( *v18 ) /*0x16c4f0*/
          ; /*0x16c4f2*/
      }
      while ( _InterlockedExchange(v18, 1) == 1 ); /*0x16c502*/
      v19 = *((_DWORD **)v38 + 16); /*0x16c507*/
      if ( (char *)v38 + 60 == (char *)v19 ) /*0x16c50f*/
        *((_DWORD *)v38 + 15) = v15; /*0x16c511*/
      else
        v19[2] = v15; /*0x16c518*/
      *(_DWORD *)(v15 + 12) = v19; /*0x16c51b*/
      v20 = v38; /*0x16c51e*/
      *(_DWORD *)(v15 + 8) = (char *)v38 + 60; /*0x16c524*/
      v20[16] = v15; /*0x16c527*/
    }
    _InterlockedExchange((volatile __int32 *)v38, 0); /*0x16c53d*/
    splx(v32); /*0x16c543*/
    while ( 1 ) /*0x16c551*/
    {
      v35[3] = v36; /*0x16c551*/
      v35[1] = *((_DWORD *)v38 + 18); /*0x16c55a*/
      v21 = msg_receive(v35, 0, 1000); /*0x16c568*/
      if ( v21 != -204 ) /*0x16c575*/
        break; /*0x16c575*/
      v22 = *(_DWORD *)(*((_DWORD *)v38 + 17) + 4); /*0x16c59e*/
      kfree(*((_DWORD *)v38 + 17), *((_DWORD *)v38 + 18)); /*0x16c5a6*/
      *((_DWORD *)v38 + 18) = v22; /*0x16c5ae*/
      v23 = kalloc(v22); /*0x16c5b2*/
      *((_DWORD *)v38 + 17) = v23; /*0x16c5bc*/
      v35 = (_DWORD *)v23; /*0x16c5bf*/
    }
    if ( v21 <= -204 ) /*0x16c577*/
      break; /*0x16c577*/
    if ( v21 != -203 ) /*0x16c589*/
    {
      if ( v21 ) /*0x16c591*/
LABEL_49:
        kern_serv_panic(*((_DWORD *)v38 + 4), aKernServerMain); /*0x16c5c8*/
LABEL_50:
      if ( v35[3] == *((_DWORD *)v38 + 7) ) /*0x16c5e8*/
      {
        if ( v35[5] == 65 ) /*0x16c5f3*/
        {
          v24 = *((int (__cdecl **)(_DWORD))v38 + 302); /*0x16c5f5*/
          if ( v24 ) /*0x16c5fd*/
          {
            if ( !v24(v35[7]) ) /*0x16c603*/
              goto LABEL_57; /*0x16c60a*/
          }
          else
          {
            v25 = *((void (__cdecl **)(_DWORD, int))v38 + 303); /*0x16c614*/
            if ( v25 ) /*0x16c61c*/
              v25(v35[7], 65); /*0x16c627*/
LABEL_57:
            kern_serv_port_gone((int *)&v38, v35[7]); /*0x16c62c*/
          }
        }
        else
        {
          v26 = *((void (__cdecl **)(_DWORD, _DWORD))v38 + 303); /*0x16c644*/
          if ( v26 ) /*0x16c64c*/
            v26(v35[7], v35[5]); /*0x16c65a*/
        }
      }
      else
      {
        if ( (unsigned int)(v35[5] - 64) <= 0xC ) /*0x16c670*/
        {
          for ( j = *((_DWORD **)v38 + 304); (char *)v38 + 1216 != (char *)j; j = (_DWORD *)j[2] ) /*0x16c68a*/
          {
            if ( j[1] == v35[7] ) /*0x16c69c*/
            {
              v35[4] = *j; /*0x16c6a3*/
              msg_send(v35, 0, 0); /*0x16c6ab*/
              v27 = (_DWORD *)j[2]; /*0x16c6b6*/
              v28 = (_DWORD *)j[3]; /*0x16c6b9*/
              if ( (char *)v38 + 1216 == (char *)v27 ) /*0x16c6c7*/
                *((_DWORD *)v38 + 305) = v28; /*0x16c6c9*/
              else
                v27[3] = v28; /*0x16c6d4*/
              if ( (char *)v38 + 1216 == (char *)v28 ) /*0x16c6e2*/
                *((_DWORD *)v38 + 304) = v27; /*0x16c6e4*/
              else
                v28[2] = v27; /*0x16c6ec*/
              kfree(j, 16); /*0x16c6f5*/
            }
          }
        }
        v29 = v38; /*0x16c716*/
        *((_DWORD *)v38 + 1) = v35[3]; /*0x16c71f*/
        if ( sub_16C758(v35, v29) == -303 && v35[3] == v37 ) /*0x16c740*/
          kern_serv_handler(v35, v39); /*0x16c74b*/
      }
    }
  }
  if ( v21 != -207 ) /*0x16c57e*/
    goto LABEL_49; /*0x16c57e*/
  goto LABEL_50; /*0x16c57e*/
}
