/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x164d80. */
int do_thread_scan()
{
  _DWORD **v0; // ebx
  _DWORD *v1; // edx
  _DWORD *v2; // esi
  int v3; // esi
  volatile __int32 *v4; // edx
  _DWORD **v5; // ebx
  _DWORD *v6; // edx
  int v7; // esi
  volatile __int32 *v8; // edx
  int v9; // ebx
  int *v10; // edx
  int *v11; // eax
  char *v12; // ebx
  int v13; // eax
  unsigned int v14; // ecx
  volatile __int32 *v15; // edx
  char *v16; // edx
  int v17; // eax
  int result; // eax
  int v19; // [esp+Ch] [ebp-18h]
  int v20; // [esp+Ch] [ebp-18h]
  unsigned int v21; // [esp+Ch] [ebp-18h]
  int v22; // [esp+10h] [ebp-14h]
  int v23; // [esp+10h] [ebp-14h]
  _DWORD *v24; // [esp+10h] [ebp-14h]
  int v25; // [esp+14h] [ebp-10h]
  int v26; // [esp+18h] [ebp-Ch]
  int v27; // [esp+1Ch] [ebp-8h]
  int v28; // [esp+20h] [ebp-4h]

  do
  {
    v27 = splsched(); /*0x164d91*/
    do /*0x164dad*/
    {
      while ( dword_1E9710 ) /*0x164d9b*/
        ; /*0x164d99*/
    }
    while ( _InterlockedExchange(&dword_1E9710, 1) == 1 ); /*0x164dad*/
    v22 = dword_1E9718; /*0x164db5*/
    if ( dword_1E9718 > 0 )
    {
      v0 = (_DWORD **)((char *)&default_pset + 8 * dword_1E9714); /*0x164dcd*/
      do
      {
        v1 = *v0; /*0x164dd4*/
        if ( v0 != *v0 )
        {
          do
          {
            v2 = (_DWORD *)*v1; /*0x164de0*/
            if ( (v1[19] & 0xF) == 4 && (unsigned int)(sched_tick - v1[28]) > 1 )
            {
              v19 = stuck_count; /*0x164e00*/
              if ( stuck_count == 128 ) /*0x164e09*/
              {
                _InterlockedExchange(&dword_1E9710, 0); /*0x164e0d*/
                splx(v27); /*0x164e17*/
                v23 = 1; /*0x164e1c*/
                goto LABEL_16; /*0x164e23*/
              }
              v2[1] = v1[1]; /*0x164e2b*/
              *(_DWORD *)v1[1] = *v1; /*0x164e33*/
              --dword_1E9718; /*0x164e35*/
              v1[2] = 0; /*0x164e3b*/
              stuck_threads[v19] = (int)v1; /*0x164e45*/
              ++stuck_count; /*0x164e4c*/
              if ( do_thread_scan_debug )
                printf("do_runq_scan: adding thread %#x\n", v1);
            }
            --v22; /*0x164e69*/
            v1 = v2; /*0x164e6c*/
          }
          while ( v0 != v2 );
        }
        v0 -= 2; /*0x164e76*/
      }
      while ( v22 > 0 );
    }
    _InterlockedExchange(&dword_1E9710, 0); /*0x164e85*/
    splx(v27); /*0x164e8f*/
    v23 = 0; /*0x164e94*/
LABEL_16:
    if ( v23 ) /*0x164ea2*/
      goto LABEL_60; /*0x164ea2*/
    v3 = master_processor; /*0x164ea8*/
    v26 = splsched(); /*0x164eb3*/
    v4 = (volatile __int32 *)(v3 + 256); /*0x164eb6*/
    do /*0x164ece*/
    {
      while ( *v4 ) /*0x164ebc*/
        ; /*0x164ebe*/
    }
    while ( _InterlockedExchange(v4, 1) == 1 ); /*0x164ece*/
    v25 = *(_DWORD *)(v3 + 264); /*0x164ed6*/
    if ( v25 > 0 )
    {
      v5 = (_DWORD **)(8 * *(_DWORD *)(v3 + 260) + v3); /*0x164eee*/
      do
      {
        v6 = *v5; /*0x164ef4*/
        if ( v5 != *v5 )
        {
          do
          {
            v24 = (_DWORD *)*v6; /*0x164f02*/
            if ( (v6[19] & 0xF) == 4 && (unsigned int)(sched_tick - v6[28]) > 1 )
            {
              v20 = stuck_count; /*0x164f27*/
              if ( stuck_count == 128 ) /*0x164f30*/
              {
                _InterlockedExchange((volatile __int32 *)(v3 + 256), 0); /*0x164f34*/
                splx(v26); /*0x164f3e*/
                v23 = 1; /*0x164f43*/
                goto LABEL_60; /*0x164f4a*/
              }
              v24[1] = v6[1]; /*0x164f56*/
              *(_DWORD *)v6[1] = *v6; /*0x164f5e*/
              --*(_DWORD *)(v3 + 264); /*0x164f60*/
              v6[2] = 0; /*0x164f66*/
              stuck_threads[v20] = (int)v6; /*0x164f70*/
              ++stuck_count; /*0x164f77*/
              if ( do_thread_scan_debug )
                printf("do_runq_scan: adding thread %#x\n", v6);
            }
            --v25; /*0x164f94*/
            v6 = v24; /*0x164f97*/
          }
          while ( v5 != v24 );
        }
        v5 -= 2; /*0x164fa2*/
      }
      while ( v25 > 0 );
    }
    _InterlockedExchange((volatile __int32 *)(v3 + 256), 0); /*0x164fb1*/
    splx(v26); /*0x164fbb*/
    v23 = 0; /*0x164fc0*/
LABEL_60:
    while ( 1 )
    {
      result = stuck_count; /*0x16517c*/
      if ( stuck_count <= 0 ) /*0x165183*/
        break; /*0x165183*/
      v7 = stuck_threads[--stuck_count]; /*0x164fd7*/
      stuck_threads[stuck_count] = 0; /*0x164fde*/
      v28 = splsched(); /*0x164fee*/
      v8 = (volatile __int32 *)(v7 + 32); /*0x164ff1*/
      do /*0x165006*/
      {
        while ( *v8 ) /*0x164ff4*/
          ; /*0x164ff6*/
      }
      while ( _InterlockedExchange(v8, 1) == 1 ); /*0x165006*/
      if ( (*(_DWORD *)(v7 + 76) & 0xF) == 4 )
      {
        update_priority((_DWORD *)v7); /*0x165018*/
        if ( *(_DWORD *)(v7 + 112) != sched_tick ) /*0x165028*/
          update_priority((_DWORD *)v7); /*0x16502b*/
        if ( dword_1E9724 <= 0 )
        {
          if ( *(_DWORD *)(v7 + 388) ) /*0x165098*/
          {
            v12 = (char *)master_processor; /*0x1650a8*/
            v13 = need_ast[0]; /*0x1650ae*/
            LOBYTE(v13) = LOBYTE(need_ast[0]) | 4; /*0x1650b3*/
            need_ast[0] = v13; /*0x1650b5*/
          }
          else
          {
            v12 = (char *)&default_pset; /*0x1650a1*/
          }
          v14 = *(_DWORD *)(v7 + 88); /*0x1650bf*/
          v21 = v14; /*0x1650c2*/
          if ( v14 > 0x1F )
          {
            printf("run_queue_enqueue: pri too high (%d)\n", v14);
            v21 = 31; /*0x1650d5*/
          }
          v15 = (volatile __int32 *)(v12 + 256); /*0x1650df*/
          do /*0x1650fa*/
          {
            while ( *v15 ) /*0x1650e8*/
              ; /*0x1650ea*/
          }
          while ( _InterlockedExchange(v15, 1) == 1 ); /*0x1650fa*/
          v16 = &v12[8 * v21]; /*0x1650ff*/
          *(_DWORD *)v7 = v16; /*0x165102*/
          *(_DWORD *)(v7 + 4) = *((_DWORD *)v16 + 1); /*0x165107*/
          **(_DWORD **)(v7 + 4) = v7; /*0x16510d*/
          *((_DWORD *)v16 + 1) = v7; /*0x16510f*/
          if ( *((_DWORD *)v12 + 65) < v21 || !*((_DWORD *)v12 + 66) ) /*0x16511a*/
            *((_DWORD *)v12 + 65) = v21; /*0x165126*/
          ++*((_DWORD *)v12 + 66); /*0x16512c*/
          *(_DWORD *)(v7 + 8) = v12; /*0x165132*/
          _InterlockedExchange((volatile __int32 *)v12 + 64, 0); /*0x165137*/
          if ( *(_DWORD *)(active_threads + 88) < *(_DWORD *)(v7 + 88) ) /*0x165149*/
          {
            *(_DWORD *)(processor_ptr[0] + 292) = 0; /*0x165150*/
            v17 = need_ast[0]; /*0x16515a*/
            LOBYTE(v17) = LOBYTE(need_ast[0]) | 4; /*0x16515f*/
            need_ast[0] = v17; /*0x165161*/
          }
        }
        else
        {
          v9 = dword_1E971C; /*0x16503c*/
          v10 = *(int **)(dword_1E971C + 268); /*0x165042*/
          v11 = *(int **)(dword_1E971C + 272); /*0x165048*/
          if ( v10 == &dword_1E971C ) /*0x165054*/
            dword_1E9720 = *(_DWORD *)(dword_1E971C + 272); /*0x165056*/
          else
            v10[68] = (int)v11; /*0x165060*/
          if ( v11 == &dword_1E971C ) /*0x16506b*/
            dword_1E971C = (int)v10; /*0x165090*/
          else
            v11[67] = (int)v10; /*0x16506d*/
          --dword_1E9724; /*0x165073*/
          *(_DWORD *)(v9 + 280) = v7; /*0x165079*/
          *(_DWORD *)(v9 + 276) = 3; /*0x16507f*/
        }
      }
      _InterlockedExchange((volatile __int32 *)(v7 + 32), 0); /*0x16516d*/
      splx(v28); /*0x165174*/
    }
  }
  while ( v23 );
  return result; /*0x165196*/
}
