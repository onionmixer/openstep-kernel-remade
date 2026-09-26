/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x152aec. */
int __cdecl mach_msg_trap(int a1, int a2, unsigned int a3, unsigned int a4, unsigned int a5, int a6, unsigned int a7)
{
  int v7; // ecx
  unsigned int v8; // eax
  unsigned __int64 v9; // kr00_8
  volatile __int32 *v10; // edx
  unsigned int v11; // ebx
  int v12; // edi
  unsigned __int64 v13; // rax
  _DWORD *v14; // ebx
  int v15; // edi
  volatile __int32 *v16; // edx
  unsigned __int64 v17; // kr08_8
  unsigned __int64 v18; // kr10_8
  int v19; // edx
  volatile __int32 *v20; // edx
  volatile __int32 *v21; // ecx
  vm_map_t v22; // edx
  int v23; // eax
  int v24; // ebx
  int v25; // edx
  int v26; // eax
  int v27; // edx
  int v28; // eax
  int v29; // edx
  int v30; // eax
  int v31; // edx
  int v32; // eax
  int result; // eax
  int v34; // edx
  int v35; // eax
  int v36; // edx
  int v37; // eax
  int v38; // ecx
  unsigned int v39; // eax
  vm_map_t v40; // esi
  volatile __int32 *v41; // edx
  int v42; // edx
  int v43; // esi
  int *v44; // eax
  unsigned int v45; // ebx
  int v46; // eax
  int v47; // ecx
  int v48; // eax
  unsigned int v49; // edx
  unsigned int v50; // edx
  int v51; // ebx
  int v52; // eax
  int v53; // ebx
  vm_map_t v54; // edx
  int v55; // eax
  int v56; // edx
  int v57; // eax
  int v58; // ebx
  int v59; // ebx
  int v60; // eax
  int v61; // ebx
  unsigned int *v62; // esi
  int v63; // eax
  int v64; // ebx
  int v65; // eax
  int v66; // eax
  int v67; // edi
  int v68; // ebx
  int v69; // eax
  int v70; // edi
  unsigned int *v71; // eax
  int v72; // eax
  int v73; // eax
  vm_map_t v74; // edi
  int v75; // eax
  int v76; // eax
  _DWORD *v77; // ebx
  int v78; // eax
  int v79; // edi
  _DWORD *v80; // eax
  int v81; // eax
  vm_map_t v82; // eax
  int v83; // [esp-18h] [ebp-98h]
  int v84; // [esp-14h] [ebp-94h]
  int v85; // [esp-10h] [ebp-90h]
  int v86; // [esp-8h] [ebp-88h]
  int v87; // [esp-4h] [ebp-84h]
  _DWORD *v88; // [esp+Ch] [ebp-74h]
  vm_map_t target_task; // [esp+10h] [ebp-70h]
  vm_map_t target_taska; // [esp+10h] [ebp-70h]
  int *target_taskb; // [esp+10h] [ebp-70h]
  vm_map_t target_taskc; // [esp+10h] [ebp-70h]
  vm_map_t target_taskd; // [esp+10h] [ebp-70h]
  vm_map_t target_taskh; // [esp+10h] [ebp-70h]
  vm_map_t target_taske; // [esp+10h] [ebp-70h]
  vm_map_t target_taskf; // [esp+10h] [ebp-70h]
  vm_map_t target_taskg; // [esp+10h] [ebp-70h]
  _DWORD *v98; // [esp+14h] [ebp-6Ch]
  vm_map_t v99; // [esp+14h] [ebp-6Ch]
  volatile __int32 *v100; // [esp+14h] [ebp-6Ch]
  unsigned int *v101; // [esp+14h] [ebp-6Ch]
  volatile __int32 *v102; // [esp+14h] [ebp-6Ch]
  volatile __int32 *v103; // [esp+14h] [ebp-6Ch]
  vm_map_t v104; // [esp+1Ch] [ebp-64h]
  vm_map_t v105; // [esp+20h] [ebp-60h]
  unsigned int v106; // [esp+24h] [ebp-5Ch]
  int v107; // [esp+28h] [ebp-58h]
  unsigned int v108; // [esp+2Ch] [ebp-54h]
  unsigned int v109; // [esp+30h] [ebp-50h]
  unsigned int v110; // [esp+34h] [ebp-4Ch]
  unsigned int *v111; // [esp+38h] [ebp-48h]
  int v112; // [esp+3Ch] [ebp-44h]
  _DWORD *v113; // [esp+40h] [ebp-40h]
  int v114; // [esp+44h] [ebp-3Ch] BYREF
  int v115; // [esp+48h] [ebp-38h] BYREF
  int v116; // [esp+4Ch] [ebp-34h] BYREF
  int v117; // [esp+50h] [ebp-30h] BYREF
  volatile __int32 *v118; // [esp+54h] [ebp-2Ch] BYREF
  int v119; // [esp+58h] [ebp-28h] BYREF
  int v120; // [esp+5Ch] [ebp-24h] BYREF
  int v121; // [esp+60h] [ebp-20h] BYREF
  int v122; // [esp+64h] [ebp-1Ch] BYREF
  volatile __int32 *v123; // [esp+68h] [ebp-18h] BYREF
  int v124; // [esp+6Ch] [ebp-14h] BYREF
  unsigned int v125; // [esp+70h] [ebp-10h] BYREF
  vm_map_t v126; // [esp+74h] [ebp-Ch] BYREF
  volatile __int32 *v127; // [esp+78h] [ebp-8h] BYREF
  unsigned int *v128; // [esp+7Ch] [ebp-4h] BYREF

  if ( a2 != 3 ) /*0x152af9*/
  {
    if ( a2 == 1 ) /*0x1539b0*/
    {
      v66 = *(_DWORD *)(active_threads + 12); /*0x1539bb*/
      v67 = *(_DWORD *)(v66 + 136); /*0x1539be*/
      target_taske = *(_DWORD *)(v66 + 12); /*0x1539c7*/
      result = ipc_kmsg_get(a1, a3, 0, (unsigned int **)&v124); /*0x1539d8*/
      if ( result ) /*0x1539e4*/
        return result; /*0x1539e4*/
      v68 = ipc_kmsg_copyin((_DWORD *)v124, v67, target_taske, 0); /*0x153a08*/
      if ( v68 ) /*0x153a0f*/
      {
        if ( *(int *)(v124 + 8) > 0 ) /*0x153a19*/
          kfree(v124, *(_DWORD *)(v124 + 8)); /*0x1539ee*/
        else
          ipc_kmsg_free(v124); /*0x153a1c*/
        return v68; /*0x153a21*/
      }
      v68 = ipc_mqueue_send(v124, 0, 0, 0); /*0x153a37*/
      if ( !v68 ) /*0x153a3e*/
        return v68; /*0x153b7f*/
      v68 |= ipc_kmsg_copyout_pseudo((_DWORD *)v124, v67, target_taske); /*0x153a52*/
      v85 = *(_DWORD *)(v124 + 16) + *(_DWORD *)(v124 + 24); /*0x153a5d*/
      v84 = v124; /*0x153a5e*/
    }
    else
    {
      if ( a2 != 2 ) /*0x153a68*/
      {
        if ( !a2 ) /*0x153ba4*/
          thread_syscall_return(0); /*0x153ba8*/
        goto LABEL_237; /*0x153ba8*/
      }
      v69 = *(_DWORD *)(active_threads + 12); /*0x153a74*/
      v70 = *(_DWORD *)(v69 + 136); /*0x153a77*/
      v105 = *(_DWORD *)(v69 + 12); /*0x153a80*/
      v88 = (_DWORD *)active_threads; /*0x153a90*/
      result = ipc_mqueue_copyin(v70, a5, &v123, &v122); /*0x153a93*/
      if ( result ) /*0x153aa2*/
        return result; /*0x153aa2*/
      v88[49] = a1; /*0x153aab*/
      v88[51] = a4; /*0x153ab4*/
      v88[54] = v122; /*0x153abd*/
      v88[55] = v123; /*0x153ac6*/
      v68 = ipc_mqueue_receive((int)v123, 0, 0xFFFFFFFF, 0, 0, (int)mach_msg_continue, (unsigned int *)&v121, &v120); /*0x153aea*/
      ipc_object_release(v122); /*0x153af3*/
      if ( v68 ) /*0x153afd*/
        return v68; /*0x153afd*/
      v71 = (unsigned int *)v121; /*0x153aff*/
      *(_DWORD *)(v121 + 36) = v120; /*0x153b05*/
      if ( v71[6] > a4 ) /*0x153b0e*/
      {
        ipc_kmsg_copyout_dest(v71, v70); /*0x153b12*/
        ipc_kmsg_put(a1, v121, 24); /*0x153b21*/
        return 268451844; /*0x153b2b*/
      }
      v72 = ipc_kmsg_copyout(v71, v70, v105, 0); /*0x153b38*/
      v68 = v72; /*0x153b3d*/
      if ( !v72 ) /*0x153b44*/
        return ipc_kmsg_put(a1, v121, *(_DWORD *)(v121 + 16) + *(_DWORD *)(v121 + 24)); /*0x153b98*/
      BYTE1(v72) &= 0xC3u; /*0x153b46*/
      if ( v72 == 268451852 ) /*0x153b4e*/
      {
LABEL_232:
        ipc_kmsg_put(v83, v84, v85); /*0x153b78*/
        return v68; /*0x153b78*/
      }
      ipc_kmsg_copyout_dest((_DWORD *)v121, v70); /*0x153b69*/
      v85 = v121; /*0x153b73*/
    }
    v83 = a1; /*0x153b77*/
    goto LABEL_232; /*0x153b77*/
  }
  v113 = (_DWORD *)active_threads; /*0x152b05*/
  v112 = *(_DWORD *)(*(_DWORD *)(active_threads + 12) + 136); /*0x152b11*/
  if ( a3 - 24 <= 0xD4 && (a3 & 3) == 0 ) /*0x152b2e*/
  {
    v7 = ipc_kmsg_cache; /*0x152b34*/
    v111 = (unsigned int *)ipc_kmsg_cache; /*0x152b3a*/
    if ( ipc_kmsg_cache ) /*0x152b3f*/
    {
      ipc_kmsg_cache = 0; /*0x152b45*/
      *(_DWORD *)(v7 + 16) = 0; /*0x152b4f*/
      if ( !copyinmsg(a1, v111 + 5, a3) ) /*0x152b6c*/
      {
        v111[4] = 0; /*0x152b8f*/
        v111[6] = a3; /*0x152b99*/
        goto LABEL_9; /*0x152b99*/
      }
      if ( (int)v111[2] > 0 ) /*0x152b76*/
        kfree((int)v111, v111[2]); /*0x1535a1*/
      else
        ipc_kmsg_free((int)v111); /*0x152b7d*/
    }
  }
  v52 = ipc_kmsg_get(a1, a3, 0, &v128); /*0x1535b7*/
  if ( v52 ) /*0x1535c3*/
    thread_syscall_return(v52); /*0x1535c6*/
  v111 = v128; /*0x1535d1*/
LABEL_9:
  v8 = v111[5]; /*0x152b9c*/
  if ( v8 == 18 ) /*0x152ba5*/
  {
    if ( v111[8] ) /*0x152d2b*/
      goto LABEL_156; /*0x152d2f*/
    v16 = (volatile __int32 *)(v112 + 8); /*0x152d38*/
    do /*0x152d4e*/
    {
      while ( *v16 ) /*0x152d3c*/
        ; /*0x152d3e*/
    }
    while ( _InterlockedExchange(v16, 1) == 1 ); /*0x152d4e*/
    v109 = *(_DWORD *)(v112 + 24); /*0x152d56*/
    target_taska = *(_DWORD *)(v112 + 20); /*0x152d5f*/
    v17 = (unsigned __int64)v111[7] << 24; /*0x152d6d*/
    v108 = v111[7] << 24; /*0x152d70*/
    if ( v109 <= HIDWORD(v17) ) /*0x152d76*/
      goto LABEL_61; /*0x152d76*/
    v101 = (unsigned int *)(*(_DWORD *)(v112 + 20) + 16 * HIDWORD(v17)); /*0x152d83*/
    if ( (*v101 & 0xFF840000) != (v108 | 0x40000) || v101[2] ) /*0x152da1*/
      goto LABEL_61; /*0x152da5*/
    v15 = v101[1]; /*0x152dab*/
    do /*0x152dc2*/
    {
      while ( *(_DWORD *)v15 ) /*0x152db0*/
        ; /*0x152db2*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v15, 1) == 1 ); /*0x152dc2*/
    if ( *(int *)(v15 + 8) >= 0 ) /*0x152dc8*/
      goto LABEL_44; /*0x152dc8*/
    v101[2] = *(_DWORD *)(target_taska + 8); /*0x152ddd*/
    *(_DWORD *)(target_taska + 8) = HIDWORD(v17); /*0x152de3*/
    *v101 = v108; /*0x152dec*/
    v101[1] = 0; /*0x152dee*/
    v111[5] = 18; /*0x152df8*/
    v111[7] = v15; /*0x152dff*/
    v18 = (unsigned __int64)a5 << 24; /*0x152e0b*/
    if ( v109 > HIDWORD(v18) ) /*0x152e11*/
    {
      target_taskb = (int *)(target_taska + 16 * HIDWORD(v18)); /*0x152e1d*/
      v19 = *target_taskb; /*0x152e20*/
      if ( (*target_taskb & 0xFF000000) == (_DWORD)v18 ) /*0x152e2b*/
      {
        if ( (v19 & 0x80000) != 0 ) /*0x152e37*/
        {
          v20 = (volatile __int32 *)target_taskb[1]; /*0x152e3c*/
          do /*0x152e52*/
          {
            while ( *v20 ) /*0x152e40*/
              ; /*0x152e42*/
          }
          while ( _InterlockedExchange(v20, 1) == 1 ); /*0x152e52*/
          target_task = (vm_map_t)v20; /*0x152e54*/
          v21 = v20 + 4; /*0x152e59*/
          goto LABEL_57; /*0x152e5c*/
        }
        if ( (v19 & 0x20000) != 0 ) /*0x152e66*/
        {
          v22 = target_taskb[1]; /*0x152e6b*/
          if ( _InterlockedExchange((volatile __int32 *)v22, 1) != 1 ) /*0x152e75*/
          {
            if ( !*(_DWORD *)(v22 + 48) ) /*0x152e80*/
            {
              target_task = v22; /*0x152e88*/
              v21 = (volatile __int32 *)(v22 + 64); /*0x152e8d*/
LABEL_57:
              v100 = v21; /*0x152e90*/
              _InterlockedExchange((volatile __int32 *)(v112 + 8), 0); /*0x152e98*/
              ++*(_DWORD *)(target_task + 4); /*0x152e9e*/
              do /*0x152ebf*/
              {
                while ( *v21 ) /*0x152ea7*/
                  ; /*0x152eac*/
              }
              while ( _InterlockedExchange(v21, 1) == 1 ); /*0x152ebf*/
              goto LABEL_179; /*0x152ebf*/
            }
            _InterlockedExchange((volatile __int32 *)v22, 0); /*0x152e84*/
          }
        }
      }
    }
    _InterlockedExchange((volatile __int32 *)v15, 0); /*0x152ede*/
    _InterlockedExchange((volatile __int32 *)(v112 + 8), 0); /*0x152ee5*/
    goto LABEL_199; /*0x152ee8*/
  }
  if ( v8 == 5395 && v111[8] == a5 ) /*0x152bbc*/
  {
    v9 = (unsigned __int64)a5 << 24; /*0x152bcb*/
    v10 = (volatile __int32 *)(v112 + 8); /*0x152bd4*/
    do /*0x152bea*/
    {
      while ( *v10 ) /*0x152bd8*/
        ; /*0x152bda*/
    }
    while ( _InterlockedExchange(v10, 1) == 1 ); /*0x152bea*/
    v11 = *(_DWORD *)(v112 + 24); /*0x152bef*/
    v12 = *(_DWORD *)(v112 + 20); /*0x152bf2*/
    if ( HIDWORD(v9) >= v11 ) /*0x152bf8*/
      goto LABEL_61; /*0x152bf8*/
    v98 = (_DWORD *)(v12 + 16 * HIDWORD(v9)); /*0x152c06*/
    if ( (*v98 & 0xFF020000) != ((a5 << 24) | 0x20000) ) /*0x152c1b*/
      goto LABEL_61; /*0x152c1b*/
    v99 = v98[1]; /*0x152c27*/
    v13 = (unsigned __int64)v111[7] << 24; /*0x152c35*/
    if ( HIDWORD(v13) >= v11 ) /*0x152c3d*/
      goto LABEL_61; /*0x152c3d*/
    v14 = (_DWORD *)(16 * HIDWORD(v13) + v12); /*0x152c48*/
    if ( (*v14 & 0xFF010000) != ((v111[7] << 24) | 0x10000) ) /*0x152c5d*/
      goto LABEL_61; /*0x152c5d*/
    v15 = v14[1]; /*0x152c63*/
    do /*0x152c7a*/
    {
      while ( *(_DWORD *)v15 ) /*0x152c68*/
        ; /*0x152c6a*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v15, 1) == 1 ); /*0x152c7a*/
    if ( *(int *)(v15 + 8) < 0 && _InterlockedExchange((volatile __int32 *)v99, 1) != 1 ) /*0x152c90*/
    {
      _InterlockedExchange((volatile __int32 *)(v112 + 8), 0); /*0x152ca0*/
      ++*(_DWORD *)(v15 + 28); /*0x152ca3*/
      ++*(_DWORD *)(v15 + 4); /*0x152ca6*/
      ++*(_DWORD *)(v99 + 32); /*0x152cac*/
      ++*(_DWORD *)(v99 + 4); /*0x152caf*/
      v111[5] = 4625; /*0x152cb5*/
      v111[7] = v15; /*0x152cbc*/
      v111[8] = v99; /*0x152cbf*/
      if ( *(_DWORD *)(v15 + 12) == ipc_space_kernel ) /*0x152cca*/
      {
        _InterlockedExchange((volatile __int32 *)v99, 0); /*0x152cce*/
LABEL_165:
        _InterlockedExchange((volatile __int32 *)v15, 0); /*0x15365a*/
        v55 = ipc_kobject_server(v111); /*0x153704*/
        v111 = (unsigned int *)v55; /*0x153709*/
        if ( !v55 ) /*0x153711*/
          goto LABEL_201; /*0x153711*/
        v56 = *(_DWORD *)(v55 + 28); /*0x153717*/
        do /*0x15372e*/
        {
          while ( *(_DWORD *)v56 ) /*0x15371c*/
            ; /*0x15371e*/
        }
        while ( _InterlockedExchange((volatile __int32 *)v56, 1) == 1 ); /*0x15372e*/
        if ( *(int *)(v56 + 8) >= 0 /*0x153746*/
          || *(_DWORD *)(v56 + 12) != v112
          || *(_DWORD *)(v56 + 16) != a5
          || *(_DWORD *)(v56 + 48) )
        {
          _InterlockedExchange((volatile __int32 *)v56, 0); /*0x15374e*/
          ipc_mqueue_send(v55, 0x10000, 0, 0); /*0x15375d*/
LABEL_201:
          v60 = ipc_mqueue_copyin(v112, a5, &v127, (int *)&v126); /*0x15382d*/
          if ( v60 ) /*0x153849*/
            thread_syscall_return(v60); /*0x15384c*/
          v103 = v127; /*0x153857*/
          target_taskh = v126; /*0x15385d*/
          v113[49] = a1; /*0x153866*/
          v113[51] = a4; /*0x15386f*/
          v113[54] = target_taskh; /*0x153878*/
          v113[55] = v103; /*0x153881*/
          v61 = ipc_mqueue_receive((int)v103, 0, 0xFFFFFFFF, 0, 0, (int)mach_msg_continue, (unsigned int *)&v128, &v125); /*0x1538a2*/
          ipc_object_release(target_taskh); /*0x1538ab*/
          if ( v61 ) /*0x1538b5*/
            thread_syscall_return(v61); /*0x1538b8*/
          v62 = v128; /*0x1538c0*/
          v111 = v128; /*0x1538c3*/
          v128[9] = v125; /*0x1538c9*/
          v15 = v62[7]; /*0x1538cc*/
          goto LABEL_105; /*0x1538cf*/
        }
        v102 = (volatile __int32 *)(v56 + 64); /*0x153763*/
        do /*0x153780*/
        {
          while ( *v102 ) /*0x15376b*/
            ; /*0x15376d*/
        }
        while ( _InterlockedExchange(v102, 1) == 1 ); /*0x153780*/
        if ( *(_DWORD *)(v56 + 72) || *(_DWORD *)(v56 + 68) ) /*0x153788*/
        {
          _InterlockedExchange(v102, 0); /*0x153793*/
          _InterlockedExchange((volatile __int32 *)v56, 0); /*0x153797*/
          ipc_mqueue_send(v55, 0x10000, 0, 0); /*0x1537a6*/
          goto LABEL_201; /*0x1537ae*/
        }
        v15 = v56; /*0x1537b0*/
        *(_DWORD *)(v55 + 36) = (*(_DWORD *)(v56 + 52))++; /*0x1537b8*/
        _InterlockedExchange(v102, 0); /*0x1537c3*/
        v57 = *(_DWORD *)(v56 + 4); /*0x1537c5*/
        _InterlockedExchange((volatile __int32 *)v56, 0); /*0x1537ca*/
        if ( !v57 ) /*0x1537ce*/
          zfree(ipc_object_zones[*(_WORD *)(v56 + 10) & 0x7FFF], v56); /*0x1537d9*/
LABEL_105:
        v110 = v111[4] + v111[6]; /*0x1532b2*/
        if ( a4 >= v110 ) /*0x1532c1*/
        {
          v39 = v111[5]; /*0x1532c7*/
          if ( v39 == 4625 ) /*0x1532cf*/
          {
            v40 = v111[8]; /*0x1532f7*/
            target_taskd = v40; /*0x1532fa*/
            if ( v40 && v40 != -1 ) /*0x153308*/
            {
              v41 = (volatile __int32 *)(v112 + 8); /*0x153311*/
              do /*0x153326*/
              {
                while ( *v41 ) /*0x153314*/
                  ; /*0x153316*/
              }
              while ( _InterlockedExchange(v41, 1) == 1 ); /*0x153326*/
              do /*0x15333a*/
              {
                while ( *(_DWORD *)v15 ) /*0x153328*/
                  ; /*0x15332a*/
              }
              while ( _InterlockedExchange((volatile __int32 *)v15, 1) == 1 ); /*0x15333a*/
              if ( *(int *)(v15 + 8) < 0 && _InterlockedExchange((volatile __int32 *)v40, 1) != 1 ) /*0x153350*/
              {
                if ( *(int *)(v40 + 8) < 0 ) /*0x15335f*/
                {
                  _InterlockedExchange((volatile __int32 *)v40, 0); /*0x153371*/
                  v42 = *(_DWORD *)(v112 + 20); /*0x153376*/
                  v43 = *(_DWORD *)(v42 + 8); /*0x153379*/
                  if ( v43 ) /*0x153381*/
                  {
                    v44 = (int *)(v42 + 16 * v43); /*0x15338c*/
                    *(_DWORD *)(v42 + 8) = v44[2]; /*0x153391*/
                    v44[2] = 0; /*0x153394*/
                    v106 = (v43 << 8) | ((unsigned int)(*v44 + 0x1000000) >> 24); /*0x1533ad*/
                    *v44 = (*v44 + 0x1000000) | 0x40001; /*0x1533b6*/
                    v44[1] = target_taskd; /*0x1533bb*/
                    _InterlockedExchange((volatile __int32 *)(v112 + 8), 0); /*0x1533c3*/
                    --*(_DWORD *)(v15 + 4); /*0x1533c6*/
                    v45 = 0; /*0x1533c9*/
                    if ( *(_DWORD *)(v15 + 12) == v112 ) /*0x1533ce*/
                      v45 = *(_DWORD *)(v15 + 16); /*0x1533d0*/
                    v46 = *(_DWORD *)(v15 + 28); /*0x1533d3*/
                    *(_DWORD *)(v15 + 28) = v46 - 1; /*0x1533d9*/
                    if ( v46 == 1 && (v47 = *(_DWORD *)(v15 + 36)) != 0 ) /*0x1533e9*/
                    {
                      v48 = *(_DWORD *)(v15 + 24); /*0x1533eb*/
                      *(_DWORD *)(v15 + 36) = 0; /*0x1533ee*/
                      _InterlockedExchange((volatile __int32 *)v15, 0); /*0x1533f7*/
                      ipc_notify_no_senders(v47, v48); /*0x1533fb*/
                    }
                    else
                    {
                      _InterlockedExchange((volatile __int32 *)v15, 0); /*0x15340a*/
                    }
                    v111[5] = 4370; /*0x15340f*/
                    v111[7] = v106; /*0x153419*/
                    v111[8] = v45; /*0x15341c*/
                    goto LABEL_147; /*0x15341f*/
                  }
                }
                else
                {
                  _InterlockedExchange((volatile __int32 *)v40, 0); /*0x153363*/
                }
              }
              _InterlockedExchange((volatile __int32 *)v15, 0); /*0x153426*/
              _InterlockedExchange((volatile __int32 *)(v112 + 8), 0); /*0x15342d*/
            }
          }
          else if ( v39 > 0x1211 ) /*0x1532d1*/
          {
            if ( v39 == -2147483630 ) /*0x1532e9*/
            {
              do /*0x1534aa*/
              {
                while ( *(_DWORD *)v15 ) /*0x153498*/
                  ; /*0x15349a*/
              }
              while ( _InterlockedExchange((volatile __int32 *)v15, 1) == 1 ); /*0x1534aa*/
              if ( *(int *)(v15 + 8) < 0 ) /*0x1534b0*/
              {
                if ( *(_DWORD *)(v15 + 12) == v112 ) /*0x1534bc*/
                {
                  --*(_DWORD *)(v15 + 4); /*0x1534be*/
                  --*(_DWORD *)(v15 + 32); /*0x1534c1*/
                  v50 = *(_DWORD *)(v15 + 16); /*0x1534c4*/
                  _InterlockedExchange((volatile __int32 *)v15, 0); /*0x1534c9*/
                }
                else
                {
                  _InterlockedExchange((volatile __int32 *)v15, 0); /*0x1534d2*/
                  ipc_notify_send_once(v15); /*0x1534d5*/
                  v50 = 0; /*0x1534da*/
                }
                v111[5] = -2147479040; /*0x1534e2*/
                v111[7] = 0; /*0x1534e9*/
                v111[8] = v50; /*0x1534f0*/
                v51 = ipc_kmsg_copyout_body( /*0x153518*/
                        v111 + 11,
                        (unsigned int)v111 + v111[6] + 20,
                        v112,
                        *(_DWORD *)(*(_DWORD *)(active_threads + 12) + 12));
                if ( v51 ) /*0x15351f*/
                {
                  ipc_kmsg_put(a1, (int)v111, v111[4] + v111[6]); /*0x153530*/
                  return v51 | 0x1000400C; /*0x15353c*/
                }
                goto LABEL_147; /*0x15351f*/
              }
            }
          }
          else if ( v39 == 18 ) /*0x1532d6*/
          {
            do /*0x15344a*/
            {
              while ( *(_DWORD *)v15 ) /*0x153438*/
                ; /*0x15343a*/
            }
            while ( _InterlockedExchange((volatile __int32 *)v15, 1) == 1 ); /*0x15344a*/
            if ( *(int *)(v15 + 8) < 0 ) /*0x153450*/
            {
              if ( *(_DWORD *)(v15 + 12) == v112 ) /*0x15345c*/
              {
                --*(_DWORD *)(v15 + 4); /*0x15345e*/
                --*(_DWORD *)(v15 + 32); /*0x153461*/
                v49 = *(_DWORD *)(v15 + 16); /*0x153464*/
                _InterlockedExchange((volatile __int32 *)v15, 0); /*0x153469*/
              }
              else
              {
                _InterlockedExchange((volatile __int32 *)v15, 0); /*0x153472*/
                ipc_notify_send_once(v15); /*0x153475*/
                v49 = 0; /*0x15347a*/
              }
              v111[5] = 4608; /*0x153482*/
              v111[7] = 0; /*0x153489*/
              v111[8] = v49; /*0x153490*/
LABEL_147:
              v111[4] = 0; /*0x153544*/
              if ( v111[2] == 256 && !copyoutmsg(v111 + 5, a1, v110) && !ipc_kmsg_cache ) /*0x153581*/
              {
                ipc_kmsg_cache = (int)v111; /*0x15358a*/
                thread_syscall_return(0); /*0x153592*/
                return 0; /*0x153f26*/
              }
              v65 = ipc_kmsg_put(a1, (int)v111, v110); /*0x153994*/
              thread_syscall_return(v65); /*0x15399c*/
LABEL_237:
              if ( (a2 & 1) == 0 ) /*0x153bb6*/
                goto LABEL_260; /*0x153bb6*/
              v73 = *(_DWORD *)(active_threads + 12); /*0x153bc1*/
              target_taskf = *(_DWORD *)(v73 + 136); /*0x153bca*/
              v74 = *(_DWORD *)(v73 + 12); /*0x153bcd*/
              v68 = ipc_kmsg_get(a1, a3, 0, (unsigned int **)&v119); /*0x153be3*/
              if ( v68 ) /*0x153bea*/
              {
LABEL_259:
                if ( v68 ) /*0x153d10*/
                  return v68; /*0x153d10*/
LABEL_260:
                if ( (a2 & 2) == 0 ) /*0x153d1c*/
                  return 0; /*0x153d1c*/
                v77 = (_DWORD *)active_threads; /*0x153d22*/
                v78 = *(_DWORD *)(active_threads + 12); /*0x153d28*/
                v79 = *(_DWORD *)(v78 + 136); /*0x153d2b*/
                v104 = *(_DWORD *)(v78 + 12); /*0x153d34*/
                target_taskg = ipc_mqueue_copyin(v79, a5, &v118, &v117); /*0x153d49*/
                if ( target_taskg ) /*0x153d51*/
                  goto LABEL_279; /*0x153d51*/
                v77[49] = a1; /*0x153d5a*/
                v77[50] = a2; /*0x153d63*/
                v77[51] = a4; /*0x153d6c*/
                v77[52] = a6; /*0x153d75*/
                v77[53] = a7; /*0x153d7e*/
                v77[54] = v117; /*0x153d87*/
                v77[55] = v118; /*0x153d90*/
                if ( (a2 & 0x800) != 0 ) /*0x153d9c*/
                {
                  target_taskg = ipc_mqueue_receive( /*0x153dc7*/
                                   (int)v118,
                                   a2 & 0x100,
                                   a4,
                                   a6,
                                   0,
                                   (int)mach_msg_receive_continue,
                                   (unsigned int *)&v116,
                                   &v115);
                  ipc_object_release(v117); /*0x153dd1*/
                  if ( target_taskg ) /*0x153ddd*/
                  {
                    if ( target_taskg == 268451844 ) /*0x153de6*/
                    {
                      v114 = v116; /*0x153def*/
                      copyout(&v114, a1 + 4, 4); /*0x153dff*/
                    }
                    goto LABEL_279; /*0x153e04*/
                  }
                  *(_DWORD *)(v116 + 36) = v115; /*0x153e12*/
                }
                else
                {
                  target_taskg = ipc_mqueue_receive( /*0x153e3f*/
                                   (int)v118,
                                   a2 & 0x100,
                                   0xFFFFFFFF,
                                   a6,
                                   0,
                                   (int)mach_msg_receive_continue,
                                   (unsigned int *)&v116,
                                   &v115);
                  ipc_object_release(v117); /*0x153e49*/
                  if ( target_taskg ) /*0x153e55*/
                  {
LABEL_279:
                    v68 = target_taskg; /*0x153f01*/
                    goto LABEL_281; /*0x153f04*/
                  }
                  v80 = (_DWORD *)v116; /*0x153e5b*/
                  *(_DWORD *)(v116 + 36) = v115; /*0x153e61*/
                  if ( v80[6] > a4 ) /*0x153e6a*/
                  {
                    ipc_kmsg_copyout_dest(v80, v79); /*0x153e6e*/
                    ipc_kmsg_put(a1, v116, 24); /*0x153e7d*/
                    return 268451844; /*0x153e87*/
                  }
                }
                if ( (a2 & 0x200) != 0 ) /*0x153e92*/
                {
                  if ( !a7 ) /*0x153e98*/
                  {
                    target_taskg = 268451847; /*0x153e9a*/
LABEL_276:
                    v82 = target_taskg; /*0x153ec8*/
                    BYTE1(v82) = BYTE1(target_taskg) & 0xC3; /*0x153ecb*/
                    if ( v82 == 268451852 ) /*0x153ed3*/
                    {
                      ipc_kmsg_put(a1, v116, *(_DWORD *)(v116 + 16) + *(_DWORD *)(v116 + 24)); /*0x153ee4*/
                    }
                    else
                    {
                      ipc_kmsg_copyout_dest((_DWORD *)v116, v79); /*0x153eed*/
                      ipc_kmsg_put(24, v86, v87); /*0x153efc*/
                    }
                    goto LABEL_279; /*0x153ee4*/
                  }
                  v81 = ipc_kmsg_copyout((unsigned int *)v116, v79, v104, a7); /*0x153ea8*/
                }
                else
                {
                  v81 = ipc_kmsg_copyout((unsigned int *)v116, v79, v104, 0); /*0x153eb7*/
                }
                target_taskg = v81; /*0x153ebc*/
                if ( !v81 ) /*0x153ec6*/
                {
                  v68 = ipc_kmsg_put(a1, v116, *(_DWORD *)(v116 + 16) + *(_DWORD *)(v116 + 24)); /*0x153f1c*/
LABEL_281:
                  if ( !v68 ) /*0x153f20*/
                    return 0; /*0x153f20*/
                  return v68; /*0x153f20*/
                }
                goto LABEL_276; /*0x153ec6*/
              }
              if ( (a2 & 0x80u) == 0 ) /*0x153bf4*/
              {
                v75 = ipc_kmsg_copyin((_DWORD *)v119, target_taskf, v74, 0); /*0x153c27*/
              }
              else
              {
                if ( !a7 ) /*0x153bfa*/
                {
                  v68 = 268435467; /*0x153bfc*/
                  goto LABEL_246; /*0x153c01*/
                }
                v75 = ipc_kmsg_copyin((_DWORD *)v119, target_taskf, v74, a7); /*0x153c08*/
              }
              v68 = v75; /*0x153c2c*/
              if ( v75 ) /*0x153c33*/
              {
LABEL_246:
                if ( *(int *)(v119 + 8) > 0 ) /*0x153c3d*/
                  kfree(v119, *(_DWORD *)(v119 + 8)); /*0x153c0e*/
                else
                  ipc_kmsg_free(v119); /*0x153c40*/
                goto LABEL_259; /*0x153c48*/
              }
              if ( (a2 & 0x20) != 0 ) /*0x153c56*/
              {
                v76 = 0; /*0x153c5a*/
                if ( (a2 & 0x10) != 0 ) /*0x153c5f*/
                  v76 = a6; /*0x153c61*/
                v68 = ipc_mqueue_send(v119, 16, v76, 0); /*0x153c70*/
                if ( v68 == 268435460 ) /*0x153c7b*/
                {
                  if ( a7 ) /*0x153c87*/
                  {
                    v68 = ipc_marequest_create( /*0x153c9b*/
                            target_taskf,
                            *(volatile __int32 **)(v119 + 28),
                            a7,
                            (unsigned int **)(v119 + 12));
                    if ( !v68 ) /*0x153ca2*/
                    {
                      ipc_mqueue_send(v119, 0x10000, 0, 0); /*0x153cb1*/
                      return 268435461; /*0x153cbb*/
                    }
                  }
                  else
                  {
                    v68 = 268435467; /*0x153cc0*/
                  }
LABEL_258:
                  v68 |= ipc_kmsg_copyout_pseudo((_DWORD *)v119, target_taskf, v74); /*0x153ce7*/
                  ipc_kmsg_put(a1, v119, *(_DWORD *)(v119 + 16) + *(_DWORD *)(v119 + 24)); /*0x153d06*/
                  goto LABEL_259; /*0x153d06*/
                }
              }
              else
              {
                v68 = ipc_mqueue_send(v119, a2 & 0x10, a6, 0); /*0x153cde*/
              }
              if ( !v68 ) /*0x153ce5*/
                goto LABEL_259; /*0x153ce5*/
              goto LABEL_258; /*0x153ce5*/
            }
          }
        }
        v110 = v111[4] + v111[6]; /*0x1538dd*/
        if ( a4 < v110 ) /*0x1538e3*/
        {
          ipc_kmsg_copyout_dest(v111, v112); /*0x1538ed*/
          ipc_kmsg_put(a1, (int)v111, 24); /*0x1538fc*/
          thread_syscall_return(268451844); /*0x153906*/
        }
        v63 = ipc_kmsg_copyout(v111, v112, *(_DWORD *)(*(_DWORD *)(active_threads + 12) + 12), 0); /*0x153924*/
        v64 = v63; /*0x153929*/
        if ( v63 ) /*0x153930*/
        {
          BYTE1(v63) &= 0xC3u; /*0x153936*/
          if ( v63 == 268451852 ) /*0x15393e*/
          {
            ipc_kmsg_put(a1, (int)v111, v111[4] + v111[6]); /*0x153952*/
          }
          else
          {
            ipc_kmsg_copyout_dest(v111, v112); /*0x153964*/
            ipc_kmsg_put(a1, (int)v111, 24); /*0x153970*/
          }
          thread_syscall_return(v64); /*0x153979*/
        }
        goto LABEL_147; /*0x153981*/
      }
      if ( *(_DWORD *)(v15 + 56) >= *(_DWORD *)(v15 + 60) || *(_DWORD *)(v99 + 48) ) /*0x152ce3*/
      {
        _InterlockedExchange((volatile __int32 *)v15, 0); /*0x152d1a*/
        _InterlockedExchange((volatile __int32 *)v99, 0); /*0x152d21*/
        goto LABEL_199; /*0x152d23*/
      }
      target_task = v99; /*0x152ce9*/
      ++*(_DWORD *)(v99 + 4); /*0x152cec*/
      v100 = (volatile __int32 *)(v99 + 64); /*0x152cf5*/
      do /*0x152d10*/
      {
        while ( *v100 ) /*0x152cfb*/
          ; /*0x152cfd*/
      }
      while ( _InterlockedExchange(v100, 1) == 1 ); /*0x152d10*/
      goto LABEL_179; /*0x152d10*/
    }
LABEL_44:
    _InterlockedExchange((volatile __int32 *)v15, 0); /*0x152dca*/
LABEL_61:
    _InterlockedExchange((volatile __int32 *)(v112 + 8), 0); /*0x152ecc*/
  }
LABEL_156:
  v53 = ipc_kmsg_copyin(v111, v112, *(_DWORD *)(*(_DWORD *)(active_threads + 12) + 12), 0); /*0x1535ec*/
  if ( v53 ) /*0x15360e*/
  {
    if ( (int)v111[2] > 0 ) /*0x153618*/
      kfree((int)v111, v111[2]); /*0x1535e1*/
    else
      ipc_kmsg_free((int)v111); /*0x15361b*/
    thread_syscall_return(v53); /*0x153624*/
  }
  if ( (*((_BYTE *)v111 + 23) & 0x40) != 0 ) /*0x153633*/
    goto LABEL_199; /*0x153633*/
  v15 = v111[7]; /*0x153639*/
  do /*0x15364e*/
  {
    while ( *(_DWORD *)v15 ) /*0x15363c*/
      ; /*0x15363e*/
  }
  while ( _InterlockedExchange((volatile __int32 *)v15, 1) == 1 ); /*0x15364e*/
  if ( *(_DWORD *)(v15 + 12) == ipc_space_kernel ) /*0x153658*/
    goto LABEL_165; /*0x153658*/
  if ( *(int *)(v15 + 8) >= 0 || *(_DWORD *)(v15 + 56) >= *(_DWORD *)(v15 + 60) && *((_BYTE *)v111 + 20) != 18 ) /*0x15367d*/
    goto LABEL_181; /*0x15367d*/
  v54 = v111[8]; /*0x153682*/
  if ( !v54 || v54 == -1 || _InterlockedExchange((volatile __int32 *)v54, 1) == 1 ) /*0x153695*/
    goto LABEL_181; /*0x15369a*/
  if ( *(int *)(v54 + 8) >= 0 || *(_DWORD *)(v54 + 12) != v112 || *(_DWORD *)(v54 + 16) != a5 || *(_DWORD *)(v54 + 48) ) /*0x1536b2*/
  {
    _InterlockedExchange((volatile __int32 *)v54, 0); /*0x1536f2*/
LABEL_181:
    _InterlockedExchange((volatile __int32 *)v15, 0); /*0x1536f4*/
LABEL_199:
    v58 = ipc_mqueue_send((int)v111, 0, 0, 0); /*0x1537e0*/
    if ( v58 ) /*0x1537f6*/
    {
      v59 = ipc_kmsg_copyout_pseudo(v111, v112, *(_DWORD *)(*(_DWORD *)(active_threads + 12) + 12)) | v58; /*0x15380e*/
      ipc_kmsg_put(a1, (int)v111, v111[4] + v111[6]); /*0x15381f*/
      thread_syscall_return(v59); /*0x153825*/
    }
    goto LABEL_201; /*0x153825*/
  }
  target_task = v54; /*0x1536b8*/
  ++*(_DWORD *)(v54 + 4); /*0x1536bb*/
  v100 = (volatile __int32 *)(v54 + 64); /*0x1536c4*/
  do /*0x1536e0*/
  {
    while ( *v100 ) /*0x1536cb*/
      ; /*0x1536cd*/
  }
  while ( _InterlockedExchange(v100, 1) == 1 ); /*0x1536e0*/
LABEL_179:
  _InterlockedExchange((volatile __int32 *)target_task, 0); /*0x1536e2*/
  v23 = *(_DWORD *)(v15 + 48); /*0x152ef0*/
  if ( v23 ) /*0x152ef5*/
    v107 = v23 + 16; /*0x152f03*/
  else
    v107 = v15 + 64; /*0x152efa*/
  if ( _InterlockedExchange((volatile __int32 *)v107, 1) == 1 ) /*0x152f10*/
    goto LABEL_67; /*0x152f15*/
  v24 = *(_DWORD *)(v107 + 8); /*0x152f37*/
  if ( !v24 || *((_DWORD *)v100 + 1) ) /*0x152f41*/
  {
LABEL_70:
    _InterlockedExchange((volatile __int32 *)v107, 0); /*0x152f47*/
LABEL_67:
    _InterlockedExchange((volatile __int32 *)v15, 0); /*0x152f17*/
    _InterlockedExchange(v100, 0); /*0x152f20*/
    ipc_object_release(target_task); /*0x152f26*/
    goto LABEL_199; /*0x152f2e*/
  }
  v113[49] = a1; /*0x152f76*/
  v113[51] = a4; /*0x152f7f*/
  v113[54] = target_task; /*0x152f88*/
  v113[55] = v100; /*0x152f91*/
  if ( *(int (**)())(v24 + 52) == mach_msg_continue && thread_handoff(v113, mach_msg_continue, v24) ) /*0x152fa7*/
    goto LABEL_96; /*0x152fa7*/
  if ( *(int (**)())(v24 + 52) == exception_raise_continue && thread_handoff(v113, mach_msg_continue, v24) ) /*0x152fce*/
  {
    v25 = *((_DWORD *)v100 + 2); /*0x152fe1*/
    if ( v25 ) /*0x152fe6*/
    {
      v26 = *(_DWORD *)(v25 + 148); /*0x152fec*/
      v113[36] = v25; /*0x152ff5*/
      v113[37] = v26; /*0x152ffb*/
      *(_DWORD *)(v25 + 148) = v113; /*0x153001*/
      *(_DWORD *)(v26 + 144) = v113; /*0x153007*/
    }
    else
    {
      *((_DWORD *)v100 + 2) = v113; /*0x152f56*/
    }
    v113[38] = 268451841; /*0x153010*/
    v113[39] = -1; /*0x15301a*/
    _InterlockedExchange(v100, 0); /*0x153029*/
    v27 = *(_DWORD *)(v24 + 144); /*0x15302b*/
    if ( v27 == v24 ) /*0x153033*/
    {
      *(_DWORD *)(v107 + 8) = 0; /*0x152f63*/
    }
    else
    {
      v28 = *(_DWORD *)(v24 + 148); /*0x153039*/
      *(_DWORD *)(v107 + 8) = v27; /*0x153042*/
      *(_DWORD *)(v27 + 148) = v28; /*0x153045*/
      *(_DWORD *)(v28 + 144) = v27; /*0x15304b*/
      *(_DWORD *)(v24 + 144) = v24; /*0x153051*/
      *(_DWORD *)(v24 + 148) = v24; /*0x153057*/
    }
    _InterlockedExchange((volatile __int32 *)v107, 0); /*0x153062*/
    exception_raise_continue_fast(v15, v111); /*0x153069*/
    return 0; /*0x15306e*/
  }
  if ( *(_DWORD *)(v24 + 156) < a3 || !thread_handoff(v113, mach_msg_continue, v24) ) /*0x1530ad*/
    goto LABEL_70; /*0x1530b7*/
  if ( *(int (**)())(v24 + 52) == mach_msg_receive_continue && (*(_BYTE *)(v24 + 201) & 2) == 0 ) /*0x1530cd*/
  {
LABEL_96:
    _InterlockedExchange((volatile __int32 *)v15, 0); /*0x1531b6*/
    v34 = *((_DWORD *)v100 + 2); /*0x1531bb*/
    if ( v34 ) /*0x1531c0*/
    {
      v35 = *(_DWORD *)(v34 + 148); /*0x1531c2*/
      v113[36] = v34; /*0x1531cb*/
      v113[37] = v35; /*0x1531d1*/
      *(_DWORD *)(v34 + 148) = v113; /*0x1531d7*/
      *(_DWORD *)(v35 + 144) = v113; /*0x1531dd*/
    }
    else
    {
      *((_DWORD *)v100 + 2) = v113; /*0x1531a2*/
    }
    v113[38] = 268451841; /*0x1531e6*/
    v113[39] = -1; /*0x1531f0*/
    _InterlockedExchange(v100, 0); /*0x1531ff*/
    v36 = *(_DWORD *)(v24 + 144); /*0x153201*/
    if ( v36 == v24 ) /*0x153209*/
    {
      *(_DWORD *)(v107 + 8) = 0; /*0x1531ab*/
    }
    else
    {
      v37 = *(_DWORD *)(v24 + 148); /*0x15320b*/
      *(_DWORD *)(v107 + 8) = v36; /*0x153214*/
      *(_DWORD *)(v36 + 148) = v37; /*0x153217*/
      *(_DWORD *)(v37 + 144) = v36; /*0x15321d*/
      *(_DWORD *)(v24 + 144) = v24; /*0x153223*/
      *(_DWORD *)(v24 + 148) = v24; /*0x153229*/
    }
    v111[9] = (*(_DWORD *)(v15 + 52))++; /*0x153235*/
    _InterlockedExchange((volatile __int32 *)v107, 0); /*0x153240*/
    v112 = *(_DWORD *)(*(_DWORD *)(v24 + 12) + 136); /*0x15324e*/
    a1 = *(_DWORD *)(v24 + 196); /*0x153257*/
    a4 = *(_DWORD *)(v24 + 204); /*0x153260*/
    target_taskc = *(_DWORD *)(v24 + 216); /*0x153269*/
    do /*0x153284*/
    {
      while ( *(_DWORD *)target_taskc ) /*0x15326f*/
        ; /*0x153271*/
    }
    while ( _InterlockedExchange((volatile __int32 *)target_taskc, 1) == 1 ); /*0x153284*/
    v38 = *(_DWORD *)(target_taskc + 4) - 1; /*0x153289*/
    *(_DWORD *)(target_taskc + 4) = v38; /*0x15328c*/
    _InterlockedExchange((volatile __int32 *)target_taskc, 0); /*0x153292*/
    if ( !v38 ) /*0x153296*/
      zfree(ipc_object_zones[*(_WORD *)(target_taskc + 10) & 0x7FFF], target_taskc); /*0x1532aa*/
    goto LABEL_105; /*0x1532aa*/
  }
  ++*(_DWORD *)(v15 + 56); /*0x1530d3*/
  _InterlockedExchange((volatile __int32 *)v15, 0); /*0x1530d8*/
  v29 = *((_DWORD *)v100 + 2); /*0x1530dd*/
  if ( v29 ) /*0x1530e2*/
  {
    v30 = *(_DWORD *)(v29 + 148); /*0x1530e4*/
    v113[36] = v29; /*0x1530ed*/
    v113[37] = v30; /*0x1530f3*/
    *(_DWORD *)(v29 + 148) = v113; /*0x1530f9*/
    *(_DWORD *)(v30 + 144) = v113; /*0x1530ff*/
  }
  else
  {
    *((_DWORD *)v100 + 2) = v113; /*0x15307a*/
  }
  v113[38] = 268451841; /*0x153108*/
  v113[39] = -1; /*0x153112*/
  _InterlockedExchange(v100, 0); /*0x153121*/
  v31 = *(_DWORD *)(v24 + 144); /*0x153123*/
  if ( v31 == v24 ) /*0x15312b*/
  {
    *(_DWORD *)(v107 + 8) = 0; /*0x153087*/
  }
  else
  {
    v32 = *(_DWORD *)(v24 + 148); /*0x153131*/
    *(_DWORD *)(v107 + 8) = v31; /*0x15313a*/
    *(_DWORD *)(v31 + 148) = v32; /*0x15313d*/
    *(_DWORD *)(v32 + 144) = v31; /*0x153143*/
    *(_DWORD *)(v24 + 144) = v24; /*0x153149*/
    *(_DWORD *)(v24 + 148) = v24; /*0x15314f*/
  }
  *(_DWORD *)(v24 + 152) = 0; /*0x153155*/
  *(_DWORD *)(v24 + 156) = v111; /*0x153162*/
  *(_DWORD *)(v24 + 160) = (*(_DWORD *)(v15 + 52))++; /*0x15316b*/
  _InterlockedExchange((volatile __int32 *)v107, 0); /*0x153179*/
  *(_DWORD *)(v24 + 68) = 0; /*0x15317b*/
  (*(void (**)(void))(v24 + 52))(); /*0x153185*/
  return 0; /*0x153f2b*/
}
