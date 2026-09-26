/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x102150. */
int table()
{
  _DWORD *v0; // eax
  int result; // eax
  int v2; // edx
  int v3; // eax
  __int16 *v4; // esi
  size_t v5; // ebx
  int v6; // eax
  int v7; // esi
  int v8; // ebx
  int v9; // eax
  int v10; // esi
  int v11; // eax
  size_t v12; // ebx
  __int16 *v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // ebx
  int v17; // eax
  int v18; // edx
  int v19; // edx
  int i; // eax
  int v21; // eax
  int v22; // esi
  unsigned int v23; // eax
  size_t v24; // [esp+10h] [ebp-D4h]
  char *v25; // [esp+18h] [ebp-CCh]
  __int16 *v26; // [esp+1Ch] [ebp-C8h]
  int v27; // [esp+20h] [ebp-C4h]
  __int16 *v28; // [esp+24h] [ebp-C0h]
  int v29; // [esp+28h] [ebp-BCh]
  int v30; // [esp+2Ch] [ebp-B8h]
  _DWORD *v31; // [esp+30h] [ebp-B4h]
  _BYTE v32[6]; // [esp+34h] [ebp-B0h] BYREF
  __int16 v33; // [esp+3Ah] [ebp-AAh] BYREF
  _DWORD v34[5]; // [esp+3Ch] [ebp-A8h] BYREF
  char __dst[8]; // [esp+50h] [ebp-94h] BYREF
  _DWORD v36[5]; // [esp+58h] [ebp-8Ch] BYREF
  _DWORD v37[6]; // [esp+6Ch] [ebp-78h] BYREF
  char v38[16]; // [esp+84h] [ebp-60h] BYREF
  _DWORD v39[4]; // [esp+94h] [ebp-50h] BYREF
  int v40; // [esp+A4h] [ebp-40h]
  int v41; // [esp+A8h] [ebp-3Ch]
  int v42; // [esp+ACh] [ebp-38h]
  _BYTE v43[20]; // [esp+B0h] [ebp-34h] BYREF
  _BYTE v44[12]; // [esp+C4h] [ebp-20h] BYREF
  int v45; // [esp+D0h] [ebp-14h]
  _BYTE v46[16]; // [esp+D4h] [ebp-10h] BYREF

  v0 = *(_DWORD **)(dword_1E875C + 36); /*0x102161*/
  v31 = v0; /*0x102164*/
  v30 = 0; /*0x10216a*/
  v29 = 0; /*0x102174*/
  if ( (int)v0[3] < 0 ) /*0x102182*/
  {
    if ( machine_table_setokay(*v0) != 1 ) /*0x102191*/
    {
      result = dword_1E875C; /*0x10219a*/
      *(_BYTE *)(dword_1E875C + 104) = 22; /*0x10219f*/
      return result; /*0x1021a3*/
    }
    v29 = 1; /*0x1021d0*/
    v31[3] = -v31[3]; /*0x1021dc*/
  }
  *(_DWORD *)(dword_1E875C + 96) = 0; /*0x1021e4*/
  if ( *v31 == 1 ) /*0x1021f4*/
  {
    if ( (v2 = v31[1], v2 != *(__int16 *)(*(_DWORD *)active_u + 48)) && v2 || v31[3] != 1 ) /*0x10221e*/
    {
LABEL_72:
      result = dword_1E875C; /*0x10281c*/
      if ( !*(_DWORD *)(dword_1E875C + 96) ) /*0x102821*/
        *(_BYTE *)(dword_1E875C + 104) = 22; /*0x10282b*/
      return result; /*0x10282f*/
    }
  }
  while ( 2 ) /*0x1028f9*/
  {
    result = v31[3]; /*0x1028f9*/
    if ( result <= 0 ) /*0x102904*/
      return result; /*0x102904*/
    v26 = nullptr; /*0x10222c*/
    v25 = nullptr; /*0x102236*/
    v3 = machine_table(*v31, v31[1], v31[2], result, v31[4], v29); /*0x10226f*/
    if ( v3 ) /*0x102279*/
    {
      if ( v3 != 1 ) /*0x10227b*/
        goto LABEL_72; /*0x10227b*/
      goto LABEL_84; /*0x10227b*/
    }
    switch ( *v31 ) /*0x1022a2*/
    {
      case 1: /*0x1022a2*/
        if ( *(_DWORD *)(active_u + 360) ) /*0x1022ed*/
        {
          v4 = (__int16 *)(active_u + 364); /*0x1022f6*/
        }
        else
        {
          v33 = -1; /*0x102300*/
          v4 = &v33; /*0x102309*/
        }
        v5 = 2; /*0x10230f*/
        goto LABEL_74; /*0x102314*/
      case 2: /*0x1022a2*/
        v6 = pfind(v31[1]); /*0x10237e*/
        if ( !v6 ) /*0x10238a*/
          goto LABEL_5; /*0x10238a*/
        v7 = *(_DWORD *)(v6 + 104); /*0x102390*/
        do /*0x1023a6*/
        {
          while ( *(_DWORD *)v7 ) /*0x102394*/
            ; /*0x102396*/
        }
        while ( _InterlockedExchange((volatile __int32 *)v7, 1) == 1 ); /*0x1023a6*/
        if ( *(int *)(v7 + 36) > 0 ) /*0x1023ac*/
        {
          v8 = *(_DWORD *)(v7 + 28); /*0x1023b2*/
          thread_reference(v8); /*0x1023b6*/
          _InterlockedExchange((volatile __int32 *)v7, 0); /*0x1023c0*/
          v4 = (__int16 *)kmem_alloc_wait(kernel_pageable_map, ~page_mask & (page_mask + 2048)); /*0x1023de*/
          fake_u(v4, v8); /*0x1023e2*/
          thread_deallocate(v8); /*0x1023e8*/
          v5 = 2048; /*0x1023ed*/
          v26 = v4; /*0x1023f2*/
          v25 = (char *)v4 + (~page_mask & (page_mask + 2048)); /*0x102409*/
LABEL_74:
          if ( v5 > v31[4] ) /*0x10283f*/
            v5 = v31[4]; /*0x102841*/
          if ( v5 ) /*0x102845*/
          {
            if ( v29 ) /*0x10284e*/
            {
              v30 = copyin(v31[2], v32, v5); /*0x10286d*/
              if ( !v30 ) /*0x10287e*/
                bcopy(v32, v4, v5); /*0x102883*/
            }
            else
            {
              v30 = copyout(v4, v31[2], v5); /*0x10289d*/
            }
          }
          if ( v26 ) /*0x1028ad*/
            kmem_free_wakeup(kernel_pageable_map, v26, v25 - (char *)v26); /*0x1028ca*/
          if ( v30 ) /*0x1028d9*/
          {
            result = dword_1E875C; /*0x1021bc*/
            *(_BYTE *)(dword_1E875C + 104) = v30; /*0x1021c7*/
            return result; /*0x1021ca*/
          }
LABEL_84:
          v31[2] += v31[4]; /*0x1028df*/
          --v31[3]; /*0x1028eb*/
          ++v31[1]; /*0x1028ee*/
          ++*(_DWORD *)(dword_1E875C + 96); /*0x1028f6*/
          continue; /*0x1028f6*/
        }
        _InterlockedExchange((volatile __int32 *)v7, 0); /*0x1021aa*/
LABEL_5:
        result = dword_1E875C; /*0x1021ac*/
        *(_BYTE *)(dword_1E875C + 104) = 3; /*0x1021b1*/
        return result;
      case 3: /*0x1022a2*/
        if ( v31[1] || v31[3] != 1 ) /*0x102330*/
          goto LABEL_72; /*0x102330*/
        bcopy(&avenrun, v44, 0xCu); /*0x102341*/
        goto LABEL_58; /*0x102341*/
      case 5: /*0x1022a2*/
        if ( !table_fsparam(v31[1], v46) ) /*0x102360*/
          goto LABEL_72; /*0x102360*/
        v4 = (__int16 *)v46; /*0x102366*/
        v5 = 16; /*0x102368*/
        goto LABEL_74; /*0x10236d*/
      case 6: /*0x1022a2*/
        v9 = pfind(v31[1]); /*0x102422*/
        if ( !v9 ) /*0x10242e*/
          goto LABEL_5; /*0x10242e*/
        v10 = *(_DWORD *)(*(_DWORD *)(v9 + 104) + 12); /*0x102437*/
        v24 = v31[4]; /*0x102443*/
        if ( !v24 ) /*0x10244b*/
          goto LABEL_72; /*0x10244b*/
        v11 = *(_DWORD *)(v9 + 132); /*0x102451*/
        if ( !v11 ) /*0x102459*/
          goto LABEL_72; /*0x102459*/
        v12 = v11 - v24; /*0x102461*/
        vm_map_reference(v10); /*0x102468*/
        v28 = (__int16 *)kmem_alloc_wait(kernel_pageable_map, ~page_mask & (page_mask + v24)); /*0x10248b*/
        v27 = ~page_mask & ((unsigned int)v28 + v24 + page_mask); /*0x1024a6*/
        if ( vm_map_copy(kernel_pageable_map, v10, v28, ~page_mask & (v24 + page_mask), ~page_mask & v12, 0, 0) ) /*0x1024cb*/
        {
          kmem_free_wakeup(kernel_pageable_map, v28, ~page_mask & (page_mask + v24)); /*0x1024f1*/
          vm_map_deallocate(v10); /*0x1024f7*/
          goto LABEL_72; /*0x1024fc*/
        }
        vm_map_deallocate(v10); /*0x102505*/
        v4 = (__int16 *)(v27 - v24); /*0x102510*/
        v5 = v24; /*0x102516*/
        v13 = (__int16 *)(v27 - 12); /*0x102525*/
        if ( *(_DWORD *)(v27 - 12) ) /*0x10252e*/
        {
          do /*0x10253b*/
          {
            if ( v13 == v4 ) /*0x102536*/
              break; /*0x102536*/
            v13 -= 2; /*0x102538*/
          }
          while ( *(_DWORD *)v13 ); /*0x10253b*/
        }
        bzero((void *)(v27 - v24), (char *)v13 - (char *)v4); /*0x102544*/
        v26 = v28; /*0x10254f*/
        v25 = (char *)v27; /*0x10255b*/
        goto LABEL_74; /*0x102564*/
      case 0xA: /*0x1022a2*/
        v14 = v31[1]; /*0x102572*/
        if ( v14 < 0 ) /*0x102577*/
          v31[1] = -v14; /*0x10257b*/
        v15 = pfind(v31[1]); /*0x102588*/
        v16 = v15; /*0x10258d*/
        if ( !v15 ) /*0x102594*/
          goto LABEL_5; /*0x102594*/
        if ( *(_BYTE *)(v15 + 19) ) /*0x10259a*/
        {
          v39[0] = *(__int16 *)(v15 + 44); /*0x1025c0*/
          v39[1] = *(__int16 *)(v15 + 48); /*0x1025c7*/
          v39[2] = *(__int16 *)(v15 + 50); /*0x1025ce*/
          v39[3] = *(__int16 *)(v15 + 46); /*0x1025d5*/
          v42 = *(_DWORD *)(v15 + 40); /*0x1025db*/
          v17 = *(_DWORD *)(v15 + 104); /*0x1025de*/
          if ( v17 ) /*0x1025e3*/
          {
            v18 = *(_DWORD *)(v17 + 56); /*0x1025f0*/
            if ( *(_DWORD *)(v18 + 360) ) /*0x1025f3*/
              v40 = *(__int16 *)(v18 + 364); /*0x10260f*/
            else
              v40 = -1; /*0x1025fc*/
            bcopy((const void *)(v18 + 8), v43, 0x10u); /*0x10261c*/
            v43[16] = 0; /*0x102621*/
            if ( (*(_BYTE *)(v16 + 41) & 4) != 0 ) /*0x10262c*/
              v41 = 2; /*0x10262e*/
            else
              v41 = 1; /*0x102638*/
          }
          else
          {
            v41 = 3; /*0x1025e5*/
          }
        }
        else
        {
          bzero(v39, 0x30u); /*0x1025a6*/
          v41 = 0; /*0x1025ab*/
        }
        v4 = (__int16 *)v39; /*0x10263f*/
        v5 = 48; /*0x102642*/
        goto LABEL_74; /*0x102647*/
      case 0xB: /*0x1022a2*/
        if ( v31[1] || v31[3] != 1 ) /*0x102660*/
          goto LABEL_72; /*0x102660*/
        bcopy(&mach_factor, v44, 0xCu); /*0x102671*/
LABEL_58:
        v45 = 1000; /*0x102676*/
        v4 = (__int16 *)v44; /*0x10267d*/
        v5 = 16; /*0x10267f*/
        goto LABEL_74; /*0x102687*/
      case 0xC: /*0x1022a2*/
        if ( v31[1] || v31[3] != 1 ) /*0x1026a0*/
          goto LABEL_72; /*0x1026a0*/
        v37[0] = cnt; /*0x1026ac*/
        v37[1] = dword_1E894C; /*0x1026b5*/
        v37[2] = dword_1E8948; /*0x1026be*/
        v37[3] = dword_1E8944; /*0x1026c7*/
        v37[4] = hz; /*0x1026d0*/
        v37[5] = 0; /*0x1026d3*/
        bcopy(&cp_time, v38, 0x10u); /*0x1026e8*/
        v4 = (__int16 *)v37; /*0x1026ed*/
        v5 = 40; /*0x1026ef*/
        goto LABEL_74; /*0x1026f7*/
      case 0xD: /*0x1022a2*/
        if ( v31[1] || v31[3] != 1 ) /*0x102710*/
          goto LABEL_72; /*0x102710*/
        v36[0] = tk_nin; /*0x10271c*/
        v36[1] = tk_nout; /*0x102728*/
        v36[2] = dk_busy; /*0x102734*/
        v36[3] = dk_ndrive; /*0x102740*/
        v19 = 0; /*0x102743*/
        for ( i = ifnet; i; i = *(_DWORD *)(i + 92) ) /*0x10274c*/
          ++v19; /*0x102750*/
        v36[4] = v19; /*0x102758*/
        v4 = (__int16 *)v36; /*0x10275b*/
        v5 = 20; /*0x102761*/
        goto LABEL_74; /*0x102766*/
      case 0xF: /*0x1022a2*/
        v21 = v31[1]; /*0x102772*/
        v22 = ifnet; /*0x102775*/
        if ( !ifnet ) /*0x10277d*/
          goto LABEL_72; /*0x10277d*/
        do /*0x10278e*/
        {
          if ( !v21 ) /*0x102786*/
            break; /*0x102786*/
          v22 = *(_DWORD *)(v22 + 92); /*0x102788*/
          --v21; /*0x10278b*/
        }
        while ( v22 ); /*0x10278e*/
        if ( !v22 ) /*0x102792*/
          goto LABEL_72; /*0x102792*/
        v34[0] = *(_DWORD *)(v22 + 68); /*0x10279b*/
        v34[1] = *(_DWORD *)(v22 + 72); /*0x1027a4*/
        v34[2] = *(_DWORD *)(v22 + 76); /*0x1027ad*/
        v34[3] = *(_DWORD *)(v22 + 80); /*0x1027b6*/
        v34[4] = *(_DWORD *)(v22 + 84); /*0x1027bf*/
        strncpy(__dst, *(const char **)v22, 6u); /*0x1027dd*/
        v23 = strlen(__dst); /*0x1027f8*/
        __dst[v23] = *(_BYTE *)(v22 + 8) + 48; /*0x1027ff*/
        __dst[v23 + 1] = 0; /*0x102806*/
        v4 = (__int16 *)v34; /*0x10280e*/
        v5 = 28; /*0x102810*/
        goto LABEL_74; /*0x102818*/
      default:
        goto LABEL_72;
    }
  }
}
