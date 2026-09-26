/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x172038. */
int __cdecl vm_fault(int a1, int a2, int a3, int a4, _DWORD *a5)
{
  volatile __int32 *v6; // edx
  int v7; // eax
  int v8; // edi
  int v9; // eax
  int v10; // esi
  char v11; // al
  volatile __int32 *v12; // edx
  char v13; // al
  int v14; // eax
  volatile __int32 *v15; // ebx
  int v16; // esi
  volatile __int32 *v17; // edx
  char v18; // al
  volatile __int32 *v19; // edx
  char v20; // al
  int v21; // eax
  volatile __int32 *v22; // edx
  char v23; // al
  volatile __int32 *v24; // edx
  volatile __int32 *v25; // edx
  char v26; // al
  int v27; // eax
  int *v28; // edx
  int *v29; // eax
  int v30; // edx
  int *v31; // eax
  int v32; // edx
  int *v33; // eax
  volatile __int32 *v34; // edx
  char v35; // al
  int v36; // eax
  int v37; // eax
  char v38; // al
  volatile __int32 *v39; // edx
  char v40; // al
  int v41; // eax
  char v42; // al
  int v43; // edx
  volatile __int32 *v44; // edx
  volatile __int32 *v45; // edx
  char v46; // al
  char v47; // al
  volatile __int32 *v48; // edx
  volatile __int32 *v49; // edx
  char v50; // al
  char v51; // al
  volatile __int32 *v52; // edx
  char v53; // al
  int v54; // eax
  char v55; // al
  volatile __int32 *v56; // edx
  char v57; // al
  int v58; // eax
  char v59; // al
  volatile __int32 *v60; // edx
  volatile __int32 *v61; // edx
  char v62; // al
  char v63; // al
  int v64; // eax
  volatile __int32 *v65; // edx
  char v66; // al
  volatile __int32 *v67; // edx
  char v68; // al
  int v69; // eax
  char v70; // al
  volatile __int32 *v71; // edx
  char v72; // al
  int v73; // eax
  char v74; // al
  volatile __int32 *v75; // edx
  char v76; // al
  int v77; // eax
  volatile __int32 *v78; // edx
  char v79; // al
  volatile __int32 *v80; // edx
  char v81; // al
  int v82; // eax
  int v83; // [esp+Ch] [ebp-4Ch]
  volatile __int32 *v84; // [esp+Ch] [ebp-4Ch]
  int v85; // [esp+Ch] [ebp-4Ch]
  int v86; // [esp+Ch] [ebp-4Ch]
  int v87; // [esp+Ch] [ebp-4Ch]
  volatile __int32 *v88; // [esp+10h] [ebp-48h]
  int v89; // [esp+14h] [ebp-44h]
  int v90; // [esp+18h] [ebp-40h]
  int v91; // [esp+1Ch] [ebp-3Ch]
  int has_page; // [esp+20h] [ebp-38h]
  int v93; // [esp+24h] [ebp-34h]
  int v94; // [esp+28h] [ebp-30h]
  int v95; // [esp+28h] [ebp-30h]
  int v96; // [esp+2Ch] [ebp-2Ch]
  int v97; // [esp+30h] [ebp-28h]
  int v98; // [esp+34h] [ebp-24h] BYREF
  int v99; // [esp+38h] [ebp-20h] BYREF
  int v100; // [esp+3Ch] [ebp-1Ch] BYREF
  int v101; // [esp+40h] [ebp-18h] BYREF
  int v102; // [esp+44h] [ebp-14h] BYREF
  int v103; // [esp+48h] [ebp-10h] BYREF
  int v104; // [esp+4Ch] [ebp-Ch] BYREF
  int v105; // [esp+50h] [ebp-8h] BYREF
  int v106; // [esp+54h] [ebp-4h] BYREF

  ++dword_1F6514; /*0x172041*/
LABEL_2:
  while ( 1 ) /*0x172070*/
  {
    v94 = vm_map_lookup(&a1, a2, a3, &v106, &v105, &v104, &v103, &v102, &v101); /*0x172070*/
    if ( v94 ) /*0x172078*/
      return v94; /*0x173583*/
    v93 = 1; /*0x172084*/
    if ( v102 ) /*0x17208f*/
      a3 = v103; /*0x172094*/
    v96 = 0; /*0x172097*/
    v6 = (volatile __int32 *)(v105 + 16); /*0x1720a1*/
    do /*0x1720b6*/
    {
      while ( *v6 ) /*0x1720a4*/
        ; /*0x1720a6*/
    }
    while ( _InterlockedExchange(v6, 1) == 1 ); /*0x1720b6*/
    v7 = v105; /*0x1720b8*/
    ++*(_WORD *)(v105 + 24); /*0x1720bb*/
    ++*(_WORD *)(v7 + 68); /*0x1720bf*/
    v8 = v7; /*0x1720c3*/
    v97 = v104; /*0x1720c8*/
    while ( 1 ) /*0x1720d1*/
    {
      v9 = vm_page_lookup(v8, v97); /*0x1720d1*/
      v10 = v9; /*0x1720d6*/
      if ( !v9 ) /*0x1720dd*/
        break; /*0x1720dd*/
      v11 = *(_BYTE *)(v9 + 32); /*0x1720e3*/
      if ( (v11 & 0x40) != 0 ) /*0x1720e8*/
      {
        *(_BYTE *)(v10 + 32) = v11 & 0xFE; /*0x1720f3*/
        if ( (v11 & 2) != 0 ) /*0x1720f8*/
        {
          *(_BYTE *)(v10 + 32) = v11 & 0xFC; /*0x1720fc*/
          thread_wakeup_prim(v10, 0, 0); /*0x172104*/
        }
        do /*0x172125*/
        {
          while ( vm_page_queue_lock ) /*0x172113*/
            ; /*0x172111*/
        }
        while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x172125*/
        vm_page_free(v10); /*0x172128*/
        _InterlockedExchange(&vm_page_queue_lock, 0); /*0x172132*/
        --*(_WORD *)(v8 + 68); /*0x172138*/
        _InterlockedExchange((volatile __int32 *)(v8 + 16), 0); /*0x17213e*/
        if ( v8 != v105 ) /*0x172146*/
        {
          v12 = (volatile __int32 *)(v105 + 16); /*0x172148*/
          do /*0x17215e*/
          {
            while ( *v12 ) /*0x17214c*/
              ; /*0x17214e*/
          }
          while ( _InterlockedExchange(v12, 1) == 1 ); /*0x17215e*/
          v13 = *(_BYTE *)(v96 + 32); /*0x172163*/
          *(_BYTE *)(v96 + 32) = v13 & 0xFE; /*0x17216b*/
          if ( (v13 & 2) != 0 ) /*0x172170*/
          {
            *(_BYTE *)(v96 + 32) = v13 & 0xFC; /*0x172174*/
            thread_wakeup_prim(v96, 0, 0); /*0x17217c*/
          }
          do /*0x17219d*/
          {
            while ( vm_page_queue_lock ) /*0x17218b*/
              ; /*0x172189*/
          }
          while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x17219d*/
          vm_page_free(v96); /*0x1721a3*/
          _InterlockedExchange(&vm_page_queue_lock, 0); /*0x1721ad*/
          v14 = v105; /*0x1721b3*/
          --*(_WORD *)(v105 + 68); /*0x1721b6*/
          _InterlockedExchange((volatile __int32 *)(v14 + 16), 0); /*0x1721bc*/
        }
        if ( v93 ) /*0x1721c3*/
          vm_map_lookup_done(a1, v106); /*0x1721cd*/
LABEL_162:
        vm_object_deallocate(v105); /*0x172919*/
        return 10; /*0x172927*/
      }
      if ( (v11 & 1) != 0 ) /*0x1721ea*/
      {
        *(_BYTE *)(v10 + 32) = v11 | 2; /*0x1721f2*/
        assert_wait(v10, a4 == 0); /*0x172203*/
        if ( v93 ) /*0x17220f*/
        {
          vm_map_lookup_done(a1, v106); /*0x172219*/
          v93 = 0; /*0x17221e*/
        }
        v15 = (volatile __int32 *)(v8 + 16); /*0x172228*/
        _InterlockedExchange((volatile __int32 *)(v8 + 16), 0); /*0x17222d*/
        thread_block(); /*0x172230*/
        v16 = *(_DWORD *)(active_threads + 68); /*0x17223a*/
        do /*0x172252*/
        {
          while ( *v15 ) /*0x172240*/
            ; /*0x172242*/
        }
        while ( _InterlockedExchange(v15, 1) == 1 ); /*0x172252*/
        if ( v16 == 4 ) /*0x172257*/
        {
          --*(_WORD *)(v8 + 68); /*0x172259*/
          _InterlockedExchange((volatile __int32 *)(v8 + 16), 0); /*0x17225f*/
          if ( v8 != v105 ) /*0x172267*/
          {
            v17 = (volatile __int32 *)(v105 + 16); /*0x17226d*/
            do /*0x172282*/
            {
              while ( *v17 ) /*0x172270*/
                ; /*0x172272*/
            }
            while ( _InterlockedExchange(v17, 1) == 1 ); /*0x172282*/
            v18 = *(_BYTE *)(v96 + 32); /*0x172287*/
            *(_BYTE *)(v96 + 32) = v18 & 0xFE; /*0x17228f*/
            if ( (v18 & 2) != 0 ) /*0x172294*/
            {
              *(_BYTE *)(v96 + 32) = v18 & 0xFC; /*0x172298*/
              thread_wakeup_prim(v96, 0, 0); /*0x1722a0*/
            }
            do /*0x1722c1*/
            {
              while ( vm_page_queue_lock ) /*0x1722af*/
                ; /*0x1722ad*/
            }
            while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x1722c1*/
LABEL_337:
            vm_page_free(v96); /*0x1733bf*/
            _InterlockedExchange(&vm_page_queue_lock, 0); /*0x1733cd*/
            v77 = v105; /*0x1733d3*/
            --*(_WORD *)(v105 + 68); /*0x1733d6*/
            _InterlockedExchange((volatile __int32 *)(v77 + 16), 0); /*0x1733dc*/
          }
          goto LABEL_338; /*0x1733dc*/
        }
        if ( v16 ) /*0x1722ca*/
        {
          --*(_WORD *)(v8 + 68); /*0x1722d0*/
          _InterlockedExchange((volatile __int32 *)(v8 + 16), 0); /*0x1722d6*/
          if ( v8 != v105 ) /*0x1722de*/
          {
            v19 = (volatile __int32 *)(v105 + 16); /*0x1722e0*/
            do /*0x1722f6*/
            {
              while ( *v19 ) /*0x1722e4*/
                ; /*0x1722e6*/
            }
            while ( _InterlockedExchange(v19, 1) == 1 ); /*0x1722f6*/
            v20 = *(_BYTE *)(v96 + 32); /*0x1722fb*/
            *(_BYTE *)(v96 + 32) = v20 & 0xFE; /*0x172303*/
            if ( (v20 & 2) != 0 ) /*0x172308*/
            {
              *(_BYTE *)(v96 + 32) = v20 & 0xFC; /*0x17230c*/
              thread_wakeup_prim(v96, 0, 0); /*0x172314*/
            }
            do /*0x172335*/
            {
              while ( vm_page_queue_lock ) /*0x172323*/
                ; /*0x172321*/
            }
            while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x172335*/
            vm_page_free(v96); /*0x17233b*/
            _InterlockedExchange(&vm_page_queue_lock, 0); /*0x172345*/
            v21 = v105; /*0x17234b*/
            --*(_WORD *)(v105 + 68); /*0x17234e*/
            _InterlockedExchange((volatile __int32 *)(v21 + 16), 0); /*0x172354*/
          }
LABEL_367:
          vm_object_deallocate(v105); /*0x173575*/
          return 0; /*0x17357e*/
        }
      }
      else
      {
        if ( (v11 & 0x20) == 0 ) /*0x172382*/
          goto LABEL_77; /*0x172382*/
        v97 += *(_DWORD *)(v8 + 36); /*0x17238b*/
        v83 = *(_DWORD *)(v8 + 32); /*0x172391*/
        if ( !v83 ) /*0x172396*/
        {
          if ( v105 != v8 ) /*0x17239f*/
          {
            *(_BYTE *)(v10 + 32) = v11 & 0xDE; /*0x1723a6*/
            *(_BYTE *)(v10 + 32) = v11 & 0xDE; /*0x1723ab*/
            if ( (v11 & 2) != 0 ) /*0x1723b0*/
            {
              *(_BYTE *)(v10 + 32) = v11 & 0xDC; /*0x1723b4*/
              thread_wakeup_prim(v10, 0, 0); /*0x1723bc*/
            }
            do /*0x1723dd*/
            {
              while ( vm_page_queue_lock ) /*0x1723cb*/
                ; /*0x1723c9*/
            }
            while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x1723dd*/
            vm_page_free(v10); /*0x1723e0*/
            _InterlockedExchange(&vm_page_queue_lock, 0); /*0x1723ea*/
            --*(_WORD *)(v8 + 68); /*0x1723f0*/
            _InterlockedExchange((volatile __int32 *)(v8 + 16), 0); /*0x1723f6*/
            v8 = v105; /*0x1723f9*/
            v10 = v96; /*0x1723fc*/
            v22 = (volatile __int32 *)(v105 + 16); /*0x1723ff*/
            do /*0x172416*/
            {
              while ( *v22 ) /*0x172404*/
                ; /*0x172406*/
            }
            while ( _InterlockedExchange(v22, 1) == 1 ); /*0x172416*/
          }
          v96 = 0; /*0x172418*/
          vm_page_zero_fill(v10); /*0x172420*/
          ++dword_1F6504; /*0x172425*/
          *(_BYTE *)(v10 + 32) &= ~0x20u; /*0x17242b*/
LABEL_77:
          if ( (a3 & *(_DWORD *)(v10 + 40)) != 0 ) /*0x1724c6*/
          {
            --*(_WORD *)(v8 + 68); /*0x1724cc*/
            _InterlockedExchange((volatile __int32 *)(v8 + 16), 0); /*0x1724d2*/
            if ( v8 != v105 ) /*0x1724da*/
            {
              v25 = (volatile __int32 *)(v105 + 16); /*0x1724dc*/
              do /*0x1724f2*/
              {
                while ( *v25 ) /*0x1724e0*/
                  ; /*0x1724e2*/
              }
              while ( _InterlockedExchange(v25, 1) == 1 ); /*0x1724f2*/
              v26 = *(_BYTE *)(v96 + 32); /*0x1724f7*/
              *(_BYTE *)(v96 + 32) = v26 & 0xFE; /*0x1724ff*/
              if ( (v26 & 2) != 0 ) /*0x172504*/
              {
                *(_BYTE *)(v96 + 32) = v26 & 0xFC; /*0x172508*/
                thread_wakeup_prim(v96, 0, 0); /*0x172510*/
              }
              do /*0x172531*/
              {
                while ( vm_page_queue_lock ) /*0x17251f*/
                  ; /*0x17251d*/
              }
              while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x172531*/
              vm_page_free(v96); /*0x172537*/
              _InterlockedExchange(&vm_page_queue_lock, 0); /*0x172541*/
              v27 = v105; /*0x172547*/
              --*(_WORD *)(v105 + 68); /*0x17254a*/
              _InterlockedExchange((volatile __int32 *)(v27 + 16), 0); /*0x172550*/
            }
            if ( v93 ) /*0x172557*/
              vm_map_lookup_done(a1, v106); /*0x172561*/
            goto LABEL_162; /*0x172561*/
          }
          do /*0x1725b5*/
          {
            while ( vm_page_queue_lock ) /*0x1725a3*/
              ; /*0x1725a1*/
          }
          while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x1725b5*/
          if ( (*(_BYTE *)(v10 + 30) & 1) != 0 ) /*0x1725bb*/
          {
            v28 = *(int **)v10; /*0x1725bd*/
            v29 = *(int **)(v10 + 4); /*0x1725bf*/
            if ( *(int **)v10 == &vm_page_queue_inactive ) /*0x1725c8*/
              dword_1F64E4 = *(_DWORD *)(v10 + 4); /*0x1725ca*/
            else
              v28[1] = (int)v29; /*0x1725d4*/
            if ( v29 == &vm_page_queue_inactive ) /*0x1725dc*/
              vm_page_queue_inactive = (int)v28; /*0x17257c*/
            else
              *v29 = (int)v28; /*0x1725de*/
            *(_BYTE *)(v10 + 30) &= ~1u; /*0x1725e0*/
            --vm_page_inactive_count; /*0x1725e4*/
            ++dword_1F6508; /*0x1725ea*/
          }
          if ( (*(_BYTE *)(v10 + 30) & 2) != 0 ) /*0x1725f4*/
          {
            v30 = *(_DWORD *)v10; /*0x1725f6*/
            v31 = *(int **)(v10 + 4); /*0x1725f8*/
            if ( *(int **)v10 == &vm_page_queue_active ) /*0x172601*/
              dword_1F6E44 = *(_DWORD *)(v10 + 4); /*0x172603*/
            else
              *(_DWORD *)(v30 + 4) = v31; /*0x17260c*/
            if ( v31 == &vm_page_queue_active ) /*0x172614*/
              vm_page_queue_active = v30; /*0x172584*/
            else
              *v31 = v30; /*0x17261a*/
            *(_BYTE *)(v10 + 30) &= ~2u; /*0x17261c*/
            --vm_page_active_count; /*0x172620*/
          }
          if ( (*(_BYTE *)(v10 + 30) & 8) != 0 ) /*0x17262a*/
          {
            v32 = *(_DWORD *)v10; /*0x17262c*/
            v33 = *(int **)(v10 + 4); /*0x17262e*/
            if ( *(int **)v10 == &vm_page_queue_free ) /*0x172637*/
              dword_1F6E4C = *(_DWORD *)(v10 + 4); /*0x172639*/
            else
              *(_DWORD *)(v32 + 4) = v33; /*0x172640*/
            if ( v33 == &vm_page_queue_free ) /*0x172648*/
              vm_page_queue_free = v32; /*0x172590*/
            else
              *v33 = v32; /*0x17264e*/
            *(_BYTE *)(v10 + 30) &= ~8u; /*0x172650*/
            --vm_page_free_count; /*0x172654*/
            ++dword_1F6508; /*0x17265a*/
          }
          _InterlockedExchange(&vm_page_queue_lock, 0); /*0x172662*/
          *(_BYTE *)(v10 + 32) = *(_BYTE *)(v10 + 32) & 0xDE | 1; /*0x17266f*/
LABEL_185:
          v46 = *(_BYTE *)(v10 + 32); /*0x172a30*/
          if ( (v46 & 0x20) != 0 || (*(_BYTE *)(v10 + 30) & 3) != 0 || (v46 & 1) == 0 ) /*0x172a3f*/
            panic(aVmFaultAbsentO); /*0x172a46*/
          v91 = v10; /*0x172a4e*/
          if ( v105 != v8 ) /*0x172a54*/
          {
            if ( (a3 & 2) != 0 ) /*0x172a60*/
            {
              vm_page_copy(v10, v96); /*0x172a6b*/
              *(_BYTE *)(v96 + 32) &= ~0x20u; /*0x172a73*/
              do /*0x172a95*/
              {
                while ( vm_page_queue_lock ) /*0x172a83*/
                  ; /*0x172a81*/
              }
              while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x172a95*/
              vm_page_activate(v10); /*0x172a98*/
              vm_page_deactivate(v10); /*0x172a9e*/
              if ( !v101 ) /*0x172aaa*/
                pmap_remove_all(*(_DWORD *)(v10 + 36)); /*0x172ab0*/
              _InterlockedExchange(&vm_page_queue_lock, 0); /*0x172aba*/
              v47 = *(_BYTE *)(v10 + 32); /*0x172ac0*/
              *(_BYTE *)(v10 + 32) = v47 & 0xFE; /*0x172ac8*/
              if ( (v47 & 2) != 0 ) /*0x172acd*/
              {
                *(_BYTE *)(v10 + 32) = v47 & 0xFC; /*0x172ad1*/
                thread_wakeup_prim(v10, 0, 0); /*0x172ad9*/
              }
              --*(_WORD *)(v8 + 68); /*0x172ae1*/
              _InterlockedExchange((volatile __int32 *)(v8 + 16), 0); /*0x172ae7*/
              ++dword_1F6518; /*0x172aea*/
              v10 = v96; /*0x172af0*/
              v8 = v105; /*0x172af3*/
              v48 = (volatile __int32 *)(v105 + 16); /*0x172af6*/
              do /*0x172b0e*/
              {
                while ( *v48 ) /*0x172afc*/
                  ; /*0x172afe*/
              }
              while ( _InterlockedExchange(v48, 1) == 1 ); /*0x172b0e*/
              --*(_WORD *)(v8 + 68); /*0x172b10*/
              vm_object_collapse(v8); /*0x172b15*/
              ++*(_WORD *)(v8 + 68); /*0x172b1a*/
            }
            else
            {
              v103 &= ~2u; /*0x172b24*/
              *(_BYTE *)(v10 + 33) |= 4u; /*0x172b28*/
            }
          }
          if ( (*(_BYTE *)(v10 + 30) & 3) != 0 ) /*0x172b30*/
            panic(aVmFaultActiveO); /*0x172b37*/
          while ( 1 ) /*0x172b78*/
          {
            while ( 1 ) /*0x172b3f*/
            {
              if ( !*(_DWORD *)(v105 + 28) ) /*0x172b47*/
                goto LABEL_285; /*0x172b47*/
              v90 = *(_DWORD *)(v105 + 28); /*0x172b4d*/
              if ( (a3 & 2) == 0 ) /*0x172b56*/
              {
                v103 &= ~2u; /*0x172b58*/
                *(_BYTE *)(v10 + 33) |= 4u; /*0x172b5c*/
                goto LABEL_285; /*0x172b60*/
              }
              if ( _InterlockedExchange((volatile __int32 *)(v90 + 16), 1) != 1 ) /*0x172b73*/
                break; /*0x172b73*/
              _InterlockedExchange((volatile __int32 *)(v8 + 16), 0); /*0x172b7f*/
              v49 = (volatile __int32 *)(v8 + 16); /*0x172b82*/
              do /*0x172b96*/
              {
                while ( *v49 ) /*0x172b84*/
                  ; /*0x172b86*/
              }
              while ( _InterlockedExchange(v49, 1) == 1 ); /*0x172b96*/
            }
            ++*(_WORD *)(v90 + 24); /*0x172b9f*/
            v89 = v104 - *(_DWORD *)(v90 + 36); /*0x172ba9*/
            v85 = vm_page_lookup(v90, v89); /*0x172bb3*/
            has_page = v85 != 0; /*0x172bc3*/
            if ( v85 ) /*0x172bc8*/
            {
              v50 = *(_BYTE *)(v85 + 32); /*0x172bd1*/
              if ( (v50 & 1) == 0 ) /*0x172bd6*/
                goto LABEL_284; /*0x172bd6*/
              *(_BYTE *)(v85 + 32) = v50 | 2; /*0x172bde*/
              assert_wait(v85, a4 == 0); /*0x172bef*/
              v51 = *(_BYTE *)(v10 + 32); /*0x172bf4*/
              *(_BYTE *)(v10 + 32) = v51 & 0xFE; /*0x172bfc*/
              if ( (v51 & 2) != 0 ) /*0x172c04*/
              {
                *(_BYTE *)(v10 + 32) = v51 & 0xFC; /*0x172c08*/
                thread_wakeup_prim(v10, 0, 0); /*0x172c10*/
              }
              do /*0x172c31*/
              {
                while ( vm_page_queue_lock ) /*0x172c1f*/
                  ; /*0x172c1d*/
              }
              while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x172c31*/
              vm_page_activate(v10); /*0x172c34*/
              _InterlockedExchange(&vm_page_queue_lock, 0); /*0x172c3e*/
              --*(_WORD *)(v90 + 24); /*0x172c47*/
              _InterlockedExchange((volatile __int32 *)(v90 + 16), 0); /*0x172c4d*/
              --*(_WORD *)(v8 + 68); /*0x172c50*/
              _InterlockedExchange((volatile __int32 *)(v8 + 16), 0); /*0x172c56*/
              if ( v8 != v105 ) /*0x172c5e*/
              {
                v52 = (volatile __int32 *)(v105 + 16); /*0x172c60*/
                do /*0x172c76*/
                {
                  while ( *v52 ) /*0x172c64*/
                    ; /*0x172c66*/
                }
                while ( _InterlockedExchange(v52, 1) == 1 ); /*0x172c76*/
                v53 = *(_BYTE *)(v96 + 32); /*0x172c7b*/
                *(_BYTE *)(v96 + 32) = v53 & 0xFE; /*0x172c83*/
                if ( (v53 & 2) != 0 ) /*0x172c88*/
                {
                  *(_BYTE *)(v96 + 32) = v53 & 0xFC; /*0x172c8c*/
                  thread_wakeup_prim(v96, 0, 0); /*0x172c94*/
                }
                do /*0x172cb5*/
                {
                  while ( vm_page_queue_lock ) /*0x172ca3*/
                    ; /*0x172ca1*/
                }
                while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x172cb5*/
                vm_page_free(v96); /*0x172cbb*/
                _InterlockedExchange(&vm_page_queue_lock, 0); /*0x172cc5*/
                v54 = v105; /*0x172ccb*/
                --*(_WORD *)(v105 + 68); /*0x172cce*/
                _InterlockedExchange((volatile __int32 *)(v54 + 16), 0); /*0x172cd4*/
              }
              if ( v93 ) /*0x172cdb*/
                vm_map_lookup_done(a1, v106); /*0x172ce5*/
              thread_block(); /*0x172ced*/
              v86 = *(_DWORD *)(active_threads + 68); /*0x172cfa*/
              vm_object_deallocate(v105); /*0x172d01*/
              if ( v86 ) /*0x172d0d*/
                return 0; /*0x172d15*/
              goto LABEL_2; /*0x172d0d*/
            }
            v87 = vm_page_alloc_sequential(v90, v89, 1); /*0x172d35*/
            if ( !v87 ) /*0x172d3d*/
            {
              v55 = *(_BYTE *)(v10 + 32); /*0x172d43*/
              *(_BYTE *)(v10 + 32) = v55 & 0xFE; /*0x172d4b*/
              if ( (v55 & 2) != 0 ) /*0x172d50*/
              {
                *(_BYTE *)(v10 + 32) = v55 & 0xFC; /*0x172d54*/
                thread_wakeup_prim(v10, 0, 0); /*0x172d5c*/
              }
              do /*0x172d7d*/
              {
                while ( vm_page_queue_lock ) /*0x172d6b*/
                  ; /*0x172d69*/
              }
              while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x172d7d*/
              vm_page_activate(v10); /*0x172d80*/
              _InterlockedExchange(&vm_page_queue_lock, 0); /*0x172d8a*/
              --*(_WORD *)(v90 + 24); /*0x172d93*/
              _InterlockedExchange((volatile __int32 *)(v90 + 16), 0); /*0x172d99*/
              --*(_WORD *)(v8 + 68); /*0x172d9c*/
              _InterlockedExchange((volatile __int32 *)(v8 + 16), 0); /*0x172da2*/
              if ( v8 != v105 ) /*0x172daa*/
              {
                v56 = (volatile __int32 *)(v105 + 16); /*0x172dac*/
                do /*0x172dc2*/
                {
                  while ( *v56 ) /*0x172db0*/
                    ; /*0x172db2*/
                }
                while ( _InterlockedExchange(v56, 1) == 1 ); /*0x172dc2*/
                v57 = *(_BYTE *)(v96 + 32); /*0x172dc7*/
                *(_BYTE *)(v96 + 32) = v57 & 0xFE; /*0x172dcf*/
                if ( (v57 & 2) != 0 ) /*0x172dd4*/
                {
                  *(_BYTE *)(v96 + 32) = v57 & 0xFC; /*0x172dd8*/
                  thread_wakeup_prim(v96, 0, 0); /*0x172de0*/
                }
                do /*0x172e01*/
                {
                  while ( vm_page_queue_lock ) /*0x172def*/
                    ; /*0x172ded*/
                }
                while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x172e01*/
                vm_page_free(v96); /*0x172e07*/
                _InterlockedExchange(&vm_page_queue_lock, 0); /*0x172e11*/
                v58 = v105; /*0x172e17*/
                --*(_WORD *)(v105 + 68); /*0x172e1a*/
                _InterlockedExchange((volatile __int32 *)(v58 + 16), 0); /*0x172e20*/
              }
              if ( v93 ) /*0x172e27*/
                vm_map_lookup_done(a1, v106); /*0x172e31*/
              vm_object_deallocate(v105); /*0x172e3d*/
              do /*0x172e61*/
              {
                while ( vm_pages_needed_lock ) /*0x172e4f*/
                  ; /*0x172e4d*/
              }
              while ( _InterlockedExchange(&vm_pages_needed_lock, 1) == 1 ); /*0x172e61*/
              goto LABEL_252; /*0x172e61*/
            }
            if ( !*(_DWORD *)(v90 + 40) ) /*0x172e93*/
              goto LABEL_278; /*0x172e93*/
            _InterlockedExchange((volatile __int32 *)(v8 + 16), 0); /*0x172e9b*/
            v88 = (volatile __int32 *)(v90 + 16); /*0x172ea1*/
            _InterlockedExchange((volatile __int32 *)(v90 + 16), 0); /*0x172ea9*/
            if ( v93 ) /*0x172eb0*/
            {
              vm_map_lookup_done(a1, v106); /*0x172eba*/
              v93 = 0; /*0x172ebf*/
            }
            has_page = vm_pager_has_page(*(_DWORD *)(v90 + 40), *(_DWORD *)(v90 + 44) + v89); /*0x172edc*/
            do /*0x172efa*/
            {
              while ( *v88 ) /*0x172ee8*/
                ; /*0x172eea*/
            }
            while ( _InterlockedExchange(v88, 1) == 1 ); /*0x172efa*/
            if ( *(_DWORD *)(v90 + 32) == v8 && *(_WORD *)(v90 + 24) != 1 ) /*0x172f09*/
              break; /*0x172f09*/
            v59 = *(_BYTE *)(v87 + 32); /*0x172f12*/
            *(_BYTE *)(v87 + 32) = v59 & 0xFE; /*0x172f1a*/
            if ( (v59 & 2) != 0 ) /*0x172f1f*/
            {
              *(_BYTE *)(v87 + 32) = v59 & 0xFC; /*0x172f23*/
              thread_wakeup_prim(v87, 0, 0); /*0x172f2b*/
            }
            do /*0x172f4d*/
            {
              while ( vm_page_queue_lock ) /*0x172f3b*/
                ; /*0x172f39*/
            }
            while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x172f4d*/
            vm_page_free(v87); /*0x172f53*/
            _InterlockedExchange(&vm_page_queue_lock, 0); /*0x172f5d*/
            _InterlockedExchange((volatile __int32 *)(v90 + 16), 0); /*0x172f68*/
            vm_object_deallocate(v90); /*0x172f6c*/
            v60 = (volatile __int32 *)(v8 + 16); /*0x172f71*/
            do /*0x172f8a*/
            {
              while ( *v60 ) /*0x172f78*/
                ; /*0x172f7a*/
            }
            while ( _InterlockedExchange(v60, 1) == 1 ); /*0x172f8a*/
          }
          v61 = (volatile __int32 *)(v8 + 16); /*0x172f94*/
          do /*0x172faa*/
          {
            while ( *v61 ) /*0x172f98*/
              ; /*0x172f9a*/
          }
          while ( _InterlockedExchange(v61, 1) == 1 ); /*0x172faa*/
          if ( !has_page ) /*0x172fb0*/
            goto LABEL_279; /*0x172fb0*/
          v62 = *(_BYTE *)(v87 + 32); /*0x172fb5*/
          *(_BYTE *)(v87 + 32) = v62 & 0xFE; /*0x172fbd*/
          if ( (v62 & 2) != 0 ) /*0x172fc2*/
          {
            *(_BYTE *)(v87 + 32) = v62 & 0xFC; /*0x172fc6*/
            thread_wakeup_prim(v87, 0, 0); /*0x172fce*/
          }
          do /*0x172ff1*/
          {
            while ( vm_page_queue_lock ) /*0x172fdf*/
              ; /*0x172fdd*/
          }
          while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x172ff1*/
          vm_page_free(v87); /*0x172ff7*/
          _InterlockedExchange(&vm_page_queue_lock, 0); /*0x173001*/
LABEL_278:
          if ( !has_page ) /*0x17300b*/
          {
LABEL_279:
            vm_page_copy(v10, v87); /*0x173012*/
            *(_BYTE *)(v87 + 32) &= ~0x20u; /*0x173017*/
            do /*0x173039*/
            {
              while ( vm_page_queue_lock ) /*0x173027*/
                ; /*0x173025*/
            }
            while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x173039*/
            pmap_remove_all(*(_DWORD *)(v91 + 36)); /*0x173042*/
            *(_BYTE *)(v87 + 30) &= ~0x20u; /*0x17304a*/
            vm_page_activate(v87); /*0x17304f*/
            _InterlockedExchange(&vm_page_queue_lock, 0); /*0x173059*/
            v63 = *(_BYTE *)(v87 + 32); /*0x17305f*/
            *(_BYTE *)(v87 + 32) = v63 & 0xFE; /*0x173067*/
            if ( (v63 & 2) != 0 ) /*0x17306c*/
            {
              *(_BYTE *)(v87 + 32) = v63 & 0xFC; /*0x173070*/
              thread_wakeup_prim(v87, 0, 0); /*0x173078*/
            }
          }
LABEL_284:
          --*(_WORD *)(v90 + 24); /*0x173080*/
          _InterlockedExchange((volatile __int32 *)(v90 + 16), 0); /*0x173089*/
          *(_BYTE *)(v10 + 33) &= ~4u; /*0x17308c*/
LABEL_285:
          if ( (*(_BYTE *)(v10 + 30) & 3) != 0 ) /*0x173094*/
            panic(aVmFaultActiveO_0); /*0x17309b*/
          if ( v93 ) /*0x1730a7*/
            goto LABEL_341; /*0x1730a7*/
          _InterlockedExchange((volatile __int32 *)(v8 + 16), 0); /*0x1730b5*/
          v64 = a3; /*0x1730d0*/
          LOBYTE(v64) = a3 & 0xFD; /*0x1730d3*/
          v95 = vm_map_lookup(&a1, a2, v64, &v106, &v100, &v99, &v98, &v102, &v101); /*0x1730e3*/
          v65 = (volatile __int32 *)(v8 + 16); /*0x1730e6*/
          do /*0x1730fe*/
          {
            while ( *v65 ) /*0x1730ec*/
              ; /*0x1730ee*/
          }
          while ( _InterlockedExchange(v65, 1) == 1 ); /*0x1730fe*/
          if ( v95 ) /*0x173104*/
          {
            v66 = *(_BYTE *)(v10 + 32); /*0x17310a*/
            *(_BYTE *)(v10 + 32) = v66 & 0xFE; /*0x173112*/
            if ( (v66 & 2) != 0 ) /*0x173117*/
            {
              *(_BYTE *)(v10 + 32) = v66 & 0xFC; /*0x17311b*/
              thread_wakeup_prim(v10, 0, 0); /*0x173123*/
            }
            do /*0x173145*/
            {
              while ( vm_page_queue_lock ) /*0x173133*/
                ; /*0x173131*/
            }
            while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x173145*/
            vm_page_activate(v10); /*0x173148*/
            _InterlockedExchange(&vm_page_queue_lock, 0); /*0x173152*/
            --*(_WORD *)(v8 + 68); /*0x173158*/
            _InterlockedExchange((volatile __int32 *)(v8 + 16), 0); /*0x17315e*/
            if ( v8 != v105 ) /*0x173166*/
            {
              v67 = (volatile __int32 *)(v105 + 16); /*0x173168*/
              do /*0x17317e*/
              {
                while ( *v67 ) /*0x17316c*/
                  ; /*0x17316e*/
              }
              while ( _InterlockedExchange(v67, 1) == 1 ); /*0x17317e*/
              v68 = *(_BYTE *)(v96 + 32); /*0x173183*/
              *(_BYTE *)(v96 + 32) = v68 & 0xFE; /*0x17318b*/
              if ( (v68 & 2) != 0 ) /*0x173190*/
              {
                *(_BYTE *)(v96 + 32) = v68 & 0xFC; /*0x173194*/
                thread_wakeup_prim(v96, 0, 0); /*0x17319c*/
              }
              do /*0x1731bd*/
              {
                while ( vm_page_queue_lock ) /*0x1731ab*/
                  ; /*0x1731a9*/
              }
              while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x1731bd*/
              vm_page_free(v96); /*0x1731c3*/
              _InterlockedExchange(&vm_page_queue_lock, 0); /*0x1731cd*/
              v69 = v105; /*0x1731d3*/
              --*(_WORD *)(v105 + 68); /*0x1731d6*/
              _InterlockedExchange((volatile __int32 *)(v69 + 16), 0); /*0x1731dc*/
            }
            vm_object_deallocate(v105); /*0x1731f9*/
            return v95; /*0x173201*/
          }
          v93 = 1; /*0x173208*/
          if ( v100 != v105 || v99 != v104 ) /*0x17321d*/
          {
            v70 = *(_BYTE *)(v10 + 32); /*0x173223*/
            *(_BYTE *)(v10 + 32) = v70 & 0xFE; /*0x17322b*/
            if ( (v70 & 2) != 0 ) /*0x173230*/
            {
              *(_BYTE *)(v10 + 32) = v70 & 0xFC; /*0x173234*/
              thread_wakeup_prim(v10, 0, 0); /*0x17323c*/
            }
            do /*0x17325d*/
            {
              while ( vm_page_queue_lock ) /*0x17324b*/
                ; /*0x173249*/
            }
            while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x17325d*/
            vm_page_activate(v10); /*0x173260*/
            _InterlockedExchange(&vm_page_queue_lock, 0); /*0x17326a*/
            --*(_WORD *)(v8 + 68); /*0x173270*/
            _InterlockedExchange((volatile __int32 *)(v8 + 16), 0); /*0x173276*/
            if ( v8 != v105 ) /*0x17327e*/
            {
              v71 = (volatile __int32 *)(v105 + 16); /*0x173284*/
              do /*0x17329a*/
              {
                while ( *v71 ) /*0x173288*/
                  ; /*0x17328a*/
              }
              while ( _InterlockedExchange(v71, 1) == 1 ); /*0x17329a*/
              v72 = *(_BYTE *)(v96 + 32); /*0x17329f*/
              *(_BYTE *)(v96 + 32) = v72 & 0xFE; /*0x1732a7*/
              if ( (v72 & 2) != 0 ) /*0x1732ac*/
              {
                *(_BYTE *)(v96 + 32) = v72 & 0xFC; /*0x1732b0*/
                thread_wakeup_prim(v96, 0, 0); /*0x1732b8*/
              }
              do /*0x1732d9*/
              {
                while ( vm_page_queue_lock ) /*0x1732c7*/
                  ; /*0x1732c5*/
              }
              while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x1732d9*/
              goto LABEL_337; /*0x1732d9*/
            }
            goto LABEL_338; /*0x17327e*/
          }
          v73 = v98 & v103; /*0x1732e3*/
          v103 &= v98; /*0x1732e6*/
          if ( (*(_BYTE *)(v10 + 33) & 4) != 0 ) /*0x1732ed*/
          {
            LOBYTE(v73) = v73 & 0xFD; /*0x1732ef*/
            v103 = v73; /*0x1732f1*/
          }
          if ( !v102 || v103 == a3 ) /*0x173304*/
          {
LABEL_341:
            if ( (v103 & 2) != 0 ) /*0x17340c*/
              *(_BYTE *)(v10 + 33) &= ~4u; /*0x17340e*/
            if ( (*(_BYTE *)(v10 + 30) & 3) != 0 ) /*0x173416*/
              panic(aVmFaultActiveO_1); /*0x17341d*/
            _InterlockedExchange((volatile __int32 *)(v8 + 16), 0); /*0x17342d*/
            pmap_enter(*(_DWORD *)(a1 + 36), a2, *(_DWORD *)(v10 + 36), v103 & ~*(_DWORD *)(v10 + 40), v102); /*0x17344c*/
            v78 = (volatile __int32 *)(v8 + 16); /*0x173451*/
            do /*0x17346a*/
            {
              while ( *v78 ) /*0x173458*/
                ; /*0x17345a*/
            }
            while ( _InterlockedExchange(v78, 1) == 1 ); /*0x17346a*/
            do /*0x173485*/
            {
              while ( vm_page_queue_lock ) /*0x173473*/
                ; /*0x173471*/
            }
            while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x173485*/
            if ( a4 ) /*0x17348b*/
            {
              if ( v102 ) /*0x173491*/
                vm_page_wire(v10); /*0x173494*/
              else
                vm_page_unwire(v10); /*0x17349d*/
            }
            else
            {
              vm_page_activate(v10); /*0x1734a5*/
            }
            _InterlockedExchange(&vm_page_queue_lock, 0); /*0x1734af*/
            v79 = *(_BYTE *)(v10 + 32); /*0x1734b5*/
            *(_BYTE *)(v10 + 32) = v79 & 0xFE; /*0x1734bd*/
            if ( (v79 & 2) != 0 ) /*0x1734c2*/
            {
              *(_BYTE *)(v10 + 32) = v79 & 0xFC; /*0x1734c6*/
              thread_wakeup_prim(v10, 0, 0); /*0x1734ce*/
            }
            --*(_WORD *)(v8 + 68); /*0x1734d6*/
            _InterlockedExchange((volatile __int32 *)(v8 + 16), 0); /*0x1734dc*/
            if ( v8 != v105 ) /*0x1734e4*/
            {
              v80 = (volatile __int32 *)(v105 + 16); /*0x1734e6*/
              do /*0x1734fe*/
              {
                while ( *v80 ) /*0x1734ec*/
                  ; /*0x1734ee*/
              }
              while ( _InterlockedExchange(v80, 1) == 1 ); /*0x1734fe*/
              v81 = *(_BYTE *)(v96 + 32); /*0x173503*/
              *(_BYTE *)(v96 + 32) = v81 & 0xFE; /*0x17350b*/
              if ( (v81 & 2) != 0 ) /*0x173510*/
              {
                *(_BYTE *)(v96 + 32) = v81 & 0xFC; /*0x173514*/
                thread_wakeup_prim(v96, 0, 0); /*0x17351c*/
              }
              do /*0x17353d*/
              {
                while ( vm_page_queue_lock ) /*0x17352b*/
                  ; /*0x173529*/
              }
              while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x17353d*/
              vm_page_free(v96); /*0x173543*/
              _InterlockedExchange(&vm_page_queue_lock, 0); /*0x17354d*/
              v82 = v105; /*0x173553*/
              --*(_WORD *)(v105 + 68); /*0x173556*/
              _InterlockedExchange((volatile __int32 *)(v82 + 16), 0); /*0x17355c*/
            }
            vm_map_lookup_done(a1, v106); /*0x17356d*/
            goto LABEL_367; /*0x17356d*/
          }
          v74 = *(_BYTE *)(v10 + 32); /*0x17330a*/
          *(_BYTE *)(v10 + 32) = v74 & 0xFE; /*0x173312*/
          if ( (v74 & 2) != 0 ) /*0x173317*/
          {
            *(_BYTE *)(v10 + 32) = v74 & 0xFC; /*0x17331b*/
            thread_wakeup_prim(v10, 0, 0); /*0x173323*/
          }
          do /*0x173345*/
          {
            while ( vm_page_queue_lock ) /*0x173333*/
              ; /*0x173331*/
          }
          while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x173345*/
          vm_page_activate(v10); /*0x173348*/
          _InterlockedExchange(&vm_page_queue_lock, 0); /*0x173352*/
          --*(_WORD *)(v8 + 68); /*0x173358*/
          _InterlockedExchange((volatile __int32 *)(v8 + 16), 0); /*0x17335e*/
          if ( v8 != v105 ) /*0x173366*/
          {
            v75 = (volatile __int32 *)(v105 + 16); /*0x173368*/
            do /*0x17337e*/
            {
              while ( *v75 ) /*0x17336c*/
                ; /*0x17336e*/
            }
            while ( _InterlockedExchange(v75, 1) == 1 ); /*0x17337e*/
            v76 = *(_BYTE *)(v96 + 32); /*0x173383*/
            *(_BYTE *)(v96 + 32) = v76 & 0xFE; /*0x17338b*/
            if ( (v76 & 2) != 0 ) /*0x173390*/
            {
              *(_BYTE *)(v96 + 32) = v76 & 0xFC; /*0x173394*/
              thread_wakeup_prim(v96, 0, 0); /*0x17339c*/
            }
            do /*0x1733bd*/
            {
              while ( vm_page_queue_lock ) /*0x1733ab*/
                ; /*0x1733a9*/
            }
            while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x1733bd*/
            goto LABEL_337; /*0x1733bd*/
          }
LABEL_338:
          if ( v93 ) /*0x1733e3*/
            vm_map_lookup_done(a1, v106); /*0x1733ed*/
          vm_object_deallocate(v105); /*0x1733f9*/
          goto LABEL_2; /*0x173401*/
        }
        if ( v105 == v8 ) /*0x17243b*/
        {
          v96 = v10; /*0x172494*/
          *(_BYTE *)(v10 + 32) = v11 & 0xDF; /*0x172499*/
        }
        else
        {
          --*(_WORD *)(v8 + 68); /*0x17243d*/
          v23 = *(_BYTE *)(v10 + 32); /*0x172441*/
          *(_BYTE *)(v10 + 32) = v23 & 0xFE; /*0x172449*/
          if ( (v23 & 2) != 0 ) /*0x17244e*/
          {
            *(_BYTE *)(v10 + 32) = v23 & 0xFC; /*0x172452*/
            thread_wakeup_prim(v10, 0, 0); /*0x17245a*/
          }
          do /*0x17247d*/
          {
            while ( vm_page_queue_lock ) /*0x17246b*/
              ; /*0x172469*/
          }
          while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x17247d*/
          vm_page_free(v10); /*0x172480*/
          _InterlockedExchange(&vm_page_queue_lock, 0); /*0x17248a*/
        }
        v24 = (volatile __int32 *)(v83 + 16); /*0x17249f*/
        do /*0x1724b6*/
        {
          while ( *v24 ) /*0x1724a4*/
            ; /*0x1724a6*/
        }
        while ( _InterlockedExchange(v24, 1) == 1 ); /*0x1724b6*/
LABEL_184:
        _InterlockedExchange((volatile __int32 *)(v8 + 16), 0); /*0x172a1d*/
        v8 = v83; /*0x172a22*/
        ++*(_WORD *)(v83 + 68); /*0x172a25*/
      }
    }
    if ( (!*(_DWORD *)(v8 + 40) || a4 && !v102) && v105 != v8 || (v10 = vm_page_alloc_sequential(v8, v97, 1)) != 0 ) /*0x1726a6*/
    {
      if ( !*(_DWORD *)(v8 + 40) || a4 && !v102 ) /*0x17278c*/
        goto LABEL_171; /*0x17278c*/
      v84 = (volatile __int32 *)(v8 + 16); /*0x172795*/
      _InterlockedExchange((volatile __int32 *)(v8 + 16), 0); /*0x17279a*/
      if ( v93 ) /*0x1727a1*/
      {
        vm_map_lookup_done(a1, v106); /*0x1727ab*/
        v93 = 0; /*0x1727b0*/
      }
      v37 = vm_pager_get(*(_DWORD **)(v8 + 40), v10, a5); /*0x1727c3*/
      if ( !v37 ) /*0x1727cd*/
      {
        do /*0x1727e6*/
        {
          while ( *v84 ) /*0x1727d4*/
            ; /*0x1727d6*/
        }
        while ( _InterlockedExchange(v84, 1) == 1 ); /*0x1727e6*/
        v10 = vm_page_lookup(v8, v97); /*0x1727f2*/
        ++dword_1F650C; /*0x1727f4*/
        pmap_clear_modify(*(_DWORD *)(v10 + 36)); /*0x1727fe*/
        goto LABEL_185; /*0x172806*/
      }
      if ( v37 == 2 ) /*0x17280f*/
      {
        do /*0x17282a*/
        {
          while ( *v84 ) /*0x172818*/
            ; /*0x17281a*/
        }
        while ( _InterlockedExchange(v84, 1) == 1 ); /*0x17282a*/
        v38 = *(_BYTE *)(v10 + 32); /*0x17282c*/
        *(_BYTE *)(v10 + 32) = v38 & 0xFE; /*0x172834*/
        if ( (v38 & 2) != 0 ) /*0x172839*/
        {
          *(_BYTE *)(v10 + 32) = v38 & 0xFC; /*0x17283d*/
          thread_wakeup_prim(v10, 0, 0); /*0x172845*/
        }
        do /*0x172869*/
        {
          while ( vm_page_queue_lock ) /*0x172857*/
            ; /*0x172855*/
        }
        while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x172869*/
        vm_page_free(v10); /*0x17286c*/
        _InterlockedExchange(&vm_page_queue_lock, 0); /*0x172876*/
        --*(_WORD *)(v8 + 68); /*0x17287c*/
        _InterlockedExchange((volatile __int32 *)(v8 + 16), 0); /*0x172882*/
        if ( v8 != v105 ) /*0x17288a*/
        {
          v39 = (volatile __int32 *)(v105 + 16); /*0x17288c*/
          do /*0x1728a2*/
          {
            while ( *v39 ) /*0x172890*/
              ; /*0x172892*/
          }
          while ( _InterlockedExchange(v39, 1) == 1 ); /*0x1728a2*/
          v40 = *(_BYTE *)(v96 + 32); /*0x1728a7*/
          *(_BYTE *)(v96 + 32) = v40 & 0xFE; /*0x1728af*/
          if ( (v40 & 2) != 0 ) /*0x1728b4*/
          {
            *(_BYTE *)(v96 + 32) = v40 & 0xFC; /*0x1728b8*/
            thread_wakeup_prim(v96, 0, 0); /*0x1728c0*/
          }
          do /*0x1728e1*/
          {
            while ( vm_page_queue_lock ) /*0x1728cf*/
              ; /*0x1728cd*/
          }
          while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x1728e1*/
          vm_page_free(v96); /*0x1728e7*/
          _InterlockedExchange(&vm_page_queue_lock, 0); /*0x1728f1*/
          v41 = v105; /*0x1728f7*/
          --*(_WORD *)(v105 + 68); /*0x1728fa*/
          _InterlockedExchange((volatile __int32 *)(v41 + 16), 0); /*0x172900*/
        }
        goto LABEL_162; /*0x172900*/
      }
      do /*0x172942*/
      {
        while ( *v84 ) /*0x172930*/
          ; /*0x172932*/
      }
      while ( _InterlockedExchange(v84, 1) == 1 ); /*0x172942*/
      if ( v105 == v8 ) /*0x172947*/
        goto LABEL_172; /*0x172947*/
      v42 = *(_BYTE *)(v10 + 32); /*0x172949*/
      *(_BYTE *)(v10 + 32) = v42 & 0xFE; /*0x172951*/
      if ( (v42 & 2) != 0 ) /*0x172956*/
      {
        *(_BYTE *)(v10 + 32) = v42 & 0xFC; /*0x17295a*/
        thread_wakeup_prim(v10, 0, 0); /*0x172962*/
      }
      do /*0x172985*/
      {
        while ( vm_page_queue_lock ) /*0x172973*/
          ; /*0x172971*/
      }
      while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x172985*/
      vm_page_free(v10); /*0x172988*/
      _InterlockedExchange(&vm_page_queue_lock, 0); /*0x172992*/
LABEL_171:
      if ( v105 == v8 ) /*0x17299b*/
LABEL_172:
        v96 = v10; /*0x17299d*/
      v97 += *(_DWORD *)(v8 + 36); /*0x1729a3*/
      v83 = *(_DWORD *)(v8 + 32); /*0x1729a9*/
      if ( !v83 ) /*0x1729ae*/
      {
        v43 = v105; /*0x1729b0*/
        if ( v8 != v105 ) /*0x1729b5*/
        {
          --*(_WORD *)(v8 + 68); /*0x1729b7*/
          _InterlockedExchange((volatile __int32 *)(v8 + 16), 0); /*0x1729bd*/
          v8 = v43; /*0x1729c0*/
          v10 = v96; /*0x1729c2*/
          v44 = (volatile __int32 *)(v43 + 16); /*0x1729c5*/
          do /*0x1729da*/
          {
            while ( *v44 ) /*0x1729c8*/
              ; /*0x1729ca*/
          }
          while ( _InterlockedExchange(v44, 1) == 1 ); /*0x1729da*/
        }
        v96 = 0; /*0x1729dc*/
        vm_page_zero_fill(v10); /*0x1729e4*/
        ++dword_1F6504; /*0x1729e9*/
        *(_BYTE *)(v10 + 32) &= ~0x20u; /*0x1729ef*/
        goto LABEL_185; /*0x1729f6*/
      }
      v45 = (volatile __int32 *)(v83 + 16); /*0x1729fb*/
      do /*0x172a12*/
      {
        while ( *v45 ) /*0x172a00*/
          ; /*0x172a02*/
      }
      while ( _InterlockedExchange(v45, 1) == 1 ); /*0x172a12*/
      if ( v105 != v8 ) /*0x172a17*/
        --*(_WORD *)(v8 + 68); /*0x172a19*/
      goto LABEL_184; /*0x172a19*/
    }
    --*(_WORD *)(v8 + 68); /*0x1726ac*/
    _InterlockedExchange((volatile __int32 *)(v8 + 16), 0); /*0x1726b2*/
    if ( v8 != v105 ) /*0x1726ba*/
    {
      v34 = (volatile __int32 *)(v105 + 16); /*0x1726bc*/
      do /*0x1726d2*/
      {
        while ( *v34 ) /*0x1726c0*/
          ; /*0x1726c2*/
      }
      while ( _InterlockedExchange(v34, 1) == 1 ); /*0x1726d2*/
      v35 = *(_BYTE *)(v96 + 32); /*0x1726d7*/
      *(_BYTE *)(v96 + 32) = v35 & 0xFE; /*0x1726df*/
      if ( (v35 & 2) != 0 ) /*0x1726e4*/
      {
        *(_BYTE *)(v96 + 32) = v35 & 0xFC; /*0x1726e8*/
        thread_wakeup_prim(v96, 0, 0); /*0x1726f0*/
      }
      do /*0x172711*/
      {
        while ( vm_page_queue_lock ) /*0x1726ff*/
          ; /*0x1726fd*/
      }
      while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x172711*/
      vm_page_free(v96); /*0x172717*/
      _InterlockedExchange(&vm_page_queue_lock, 0); /*0x172721*/
      v36 = v105; /*0x172727*/
      --*(_WORD *)(v105 + 68); /*0x17272a*/
      _InterlockedExchange((volatile __int32 *)(v36 + 16), 0); /*0x172730*/
    }
    if ( v93 ) /*0x172737*/
      vm_map_lookup_done(a1, v106); /*0x172741*/
    vm_object_deallocate(v105); /*0x17274d*/
    do /*0x172771*/
    {
      while ( vm_pages_needed_lock ) /*0x17275f*/
        ; /*0x17275d*/
    }
    while ( _InterlockedExchange(&vm_pages_needed_lock, 1) == 1 ); /*0x172771*/
LABEL_252:
    thread_wakeup_prim((int)&vm_pages_needed, 0, 0); /*0x172e63*/
    thread_sleep((int)&vm_page_free_count, &vm_pages_needed_lock, 0); /*0x172e7d*/
  }
}
