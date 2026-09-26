/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x164624. */
void __noreturn idle_thread_continue()
{
  int v0; // eax
  _DWORD *v1; // ecx
  int v2; // eax
  char **v3; // esi
  int v4; // edi
  thread_act_t v5; // ebx
  int *v6; // esi
  int v7; // ebx
  volatile __int32 *v8; // edx
  int v9; // esi
  int v10; // edx
  int v11; // esi
  int *v12; // ebx
  int v13; // eax
  thread_act_t v14; // eax
  char **v15; // esi
  int v16; // ebx
  int *v17; // edx
  int *v18; // eax
  char *v19; // ebx
  int v20; // eax
  unsigned int v21; // ecx
  volatile __int32 *v22; // edx
  char *v23; // edx
  int v24; // esi
  int *v25; // ebx
  int v26; // eax
  thread_act_t v27; // eax
  unsigned int v28; // [esp+Ch] [ebp-1Ch]
  int v29; // [esp+10h] [ebp-18h]
  int v30; // [esp+10h] [ebp-18h]
  int v31; // [esp+14h] [ebp-14h]
  int v32; // [esp+18h] [ebp-10h]
  _DWORD *v33; // [esp+1Ch] [ebp-Ch]
  char ***v34; // [esp+20h] [ebp-8h]
  _DWORD *v35; // [esp+24h] [ebp-4h]

  v35 = (_DWORD *)processor_ptr[0]; /*0x164633*/
  v34 = (char ***)(processor_ptr[0] + 280); /*0x16463c*/
  v33 = (_DWORD *)(processor_ptr[0] + 264); /*0x164648*/
  while ( 1 )
  {
    PMSetCpuState(0); /*0x16464e*/
    while ( !*v34 && !dword_1E9718 && !*v33 ) /*0x16469d*/
    {
      if ( (need_ast[0] & 0xFFFFFFF8) != 0 ) /*0x164666*/
      {
        splsched(); /*0x164668*/
        v0 = need_ast[0]; /*0x16466f*/
        LOBYTE(v0) = need_ast[0] & 0xF8; /*0x164676*/
        need_ast[0] = v0; /*0x164678*/
        spl0(); /*0x16467f*/
      }
    }
    PMSetCpuState(1); /*0x1646a1*/
    v32 = splsched(); /*0x1646ab*/
    while ( 1 ) /*0x1646b1*/
    {
      v1 = v35; /*0x1646b1*/
      v2 = v35[69]; /*0x1646b4*/
      if ( v2 == 3 ) /*0x1646bd*/
      {
        v3 = *v34; /*0x1646c6*/
        *v34 = nullptr; /*0x1646c8*/
        v35[69] = 1; /*0x1646ce*/
        if ( v3[24] == (char *)2 ) /*0x1646dc*/
        {
          v4 = (int)v3[23]; /*0x1646e8*/
          v1 = v35; /*0x1646eb*/
        }
        else
        {
          v4 = dword_1E977C; /*0x1646de*/
        }
        v1[72] = v4; /*0x1646ee*/
        v35[73] = 1; /*0x1646f7*/
        v5 = (thread_act_t)v3; /*0x164701*/
        v29 = active_threads; /*0x164709*/
        v6 = (int *)processor_ptr[0]; /*0x16470c*/
        v31 = splsched(); /*0x164717*/
        while ( !thread_invoke(v29, (int)idle_thread_continue, v5) ) /*0x164730*/
          v5 = thread_select(v6); /*0x164738*/
        splx(v31); /*0x164744*/
        goto LABEL_59; /*0x164744*/
      }
      if ( v2 != 2 ) /*0x16474f*/
        break; /*0x16474f*/
      v7 = v35[75]; /*0x164758*/
      v8 = (volatile __int32 *)(v7 + 280); /*0x16475e*/
      do /*0x164776*/
      {
        while ( *v8 ) /*0x164764*/
          ; /*0x164766*/
      }
      while ( _InterlockedExchange(v8, 1) == 1 ); /*0x164776*/
      if ( v35[69] == 2 ) /*0x164782*/
      {
        ++no_dispatch_count; /*0x16479c*/
        --*(_DWORD *)(v7 + 276); /*0x1647a2*/
        v9 = v35[67]; /*0x1647ab*/
        v10 = v35[68]; /*0x1647b1*/
        if ( v7 + 268 == v9 ) /*0x1647bf*/
          *(_DWORD *)(v7 + 272) = v10; /*0x1647c1*/
        else
          *(_DWORD *)(v9 + 272) = v10; /*0x1647cc*/
        if ( v7 + 268 == v10 ) /*0x1647da*/
          *(_DWORD *)(v7 + 268) = v9; /*0x164794*/
        else
          *(_DWORD *)(v10 + 268) = v9; /*0x1647dc*/
        v35[69] = 1; /*0x1647e5*/
        _InterlockedExchange((volatile __int32 *)(v7 + 280), 0); /*0x1647f1*/
        v11 = active_threads; /*0x1647f7*/
        v12 = (int *)processor_ptr[0]; /*0x1647fd*/
        v30 = splsched(); /*0x164808*/
        v13 = need_ast[0]; /*0x16480b*/
        LOBYTE(v13) = need_ast[0] & 0xFB; /*0x164810*/
        need_ast[0] = v13; /*0x164812*/
        do /*0x164836*/
          v14 = thread_select(v12); /*0x16481d*/
        while ( !thread_invoke(v11, (int)idle_thread_continue, v14) ); /*0x164836*/
        goto LABEL_58; /*0x164836*/
      }
      _InterlockedExchange((volatile __int32 *)(v7 + 280), 0); /*0x164786*/
    }
    if ( (unsigned int)(v2 - 4) > 1 ) /*0x16484e*/
    {
      printf(" Bad processor state %d (Cpu %d)\n", *(_DWORD *)(processor_ptr[0] + 276), 0); /*0x1649e7*/
      panic(aIdleThread); /*0x1649f1*/
    }
    v15 = *v34; /*0x164857*/
    if ( *v34 )
    {
      *v34 = nullptr; /*0x164861*/
      if ( v15[28] != (char *)sched_tick ) /*0x16486f*/
        update_priority(v15); /*0x164872*/
      if ( dword_1E9724 <= 0 )
      {
        if ( v15[97] ) /*0x1648d4*/
        {
          v19 = (char *)master_processor; /*0x1648e4*/
          v20 = need_ast[0]; /*0x1648ea*/
          LOBYTE(v20) = LOBYTE(need_ast[0]) | 4; /*0x1648ef*/
          need_ast[0] = v20; /*0x1648f1*/
        }
        else
        {
          v19 = (char *)&default_pset; /*0x1648dd*/
        }
        v21 = (unsigned int)v15[22]; /*0x1648fb*/
        v28 = v21; /*0x1648fe*/
        if ( v21 > 0x1F )
        {
          printf("run_queue_enqueue: pri too high (%d)\n", v21);
          v28 = 31; /*0x164911*/
        }
        v22 = (volatile __int32 *)(v19 + 256); /*0x16491b*/
        do /*0x164936*/
        {
          while ( *v22 ) /*0x164924*/
            ; /*0x164926*/
        }
        while ( _InterlockedExchange(v22, 1) == 1 ); /*0x164936*/
        v23 = &v19[8 * v28]; /*0x16493b*/
        *v15 = v23; /*0x16493e*/
        v15[1] = *((char **)v23 + 1); /*0x164943*/
        *(_DWORD *)v15[1] = v15; /*0x164949*/
        *((_DWORD *)v23 + 1) = v15; /*0x16494b*/
        if ( *((_DWORD *)v19 + 65) < v28 || !*((_DWORD *)v19 + 66) ) /*0x164956*/
          *((_DWORD *)v19 + 65) = v28; /*0x164962*/
        ++*((_DWORD *)v19 + 66); /*0x164968*/
        v15[2] = v19; /*0x16496e*/
        _InterlockedExchange((volatile __int32 *)v19 + 64, 0); /*0x164973*/
      }
      else
      {
        v16 = dword_1E971C; /*0x164883*/
        v17 = *(int **)(dword_1E971C + 268); /*0x164889*/
        v18 = *(int **)(dword_1E971C + 272); /*0x16488f*/
        if ( v17 == &dword_1E971C ) /*0x16489b*/
          dword_1E9720 = *(_DWORD *)(dword_1E971C + 272); /*0x16489d*/
        else
          v17[68] = (int)v18; /*0x1648a4*/
        if ( v18 == &dword_1E971C ) /*0x1648af*/
          dword_1E971C = (int)v17; /*0x164840*/
        else
          v18[67] = (int)v17; /*0x1648b1*/
        --dword_1E9724; /*0x1648b7*/
        *(_DWORD *)(v16 + 280) = v15; /*0x1648bd*/
        *(_DWORD *)(v16 + 276) = 3; /*0x1648c3*/
      }
    }
    v24 = active_threads; /*0x16497c*/
    v25 = (int *)processor_ptr[0]; /*0x164982*/
    v30 = splsched(); /*0x16498d*/
    v26 = need_ast[0]; /*0x164990*/
    LOBYTE(v26) = need_ast[0] & 0xFB; /*0x164995*/
    need_ast[0] = v26; /*0x164997*/
    do /*0x1649be*/
      v27 = thread_select(v25); /*0x1649a5*/
    while ( !thread_invoke(v24, (int)idle_thread_continue, v27) ); /*0x1649be*/
LABEL_58:
    splx(v30); /*0x1649c0*/
LABEL_59:
    splx(v32); /*0x1649c9*/
  }
}
