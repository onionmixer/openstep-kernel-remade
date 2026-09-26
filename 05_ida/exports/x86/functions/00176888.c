/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x176888. */
int __cdecl vm_map_copy(int a1, int a2, unsigned int a3, int a4, unsigned int a5, int a6, int a7)
{
  int v8; // edi
  unsigned int v9; // ebx
  volatile __int32 *v10; // edx
  _DWORD *v11; // ecx
  _DWORD *v12; // eax
  volatile __int32 *v13; // edx
  volatile __int32 *v14; // edx
  _DWORD *v15; // eax
  _DWORD *v16; // ecx
  int v17; // edx
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // ebx
  int v22; // eax
  unsigned int v23; // ebx
  volatile __int32 *v24; // edx
  _DWORD *v25; // ecx
  _DWORD *v26; // eax
  volatile __int32 *v27; // edx
  volatile __int32 *v28; // edx
  _DWORD *v29; // eax
  volatile __int32 *v30; // edx
  _DWORD *v31; // ecx
  _DWORD *v32; // eax
  volatile __int32 *v33; // edx
  volatile __int32 *v34; // edx
  int v35; // eax
  int v36; // edx
  int v37; // edx
  volatile __int32 *v38; // ecx
  volatile __int32 *v39; // edx
  _DWORD *v40; // ecx
  _DWORD *v41; // eax
  volatile __int32 *v42; // edx
  volatile __int32 *v43; // edx
  int v44; // eax
  int v45; // edx
  int v46; // edx
  volatile __int32 *v47; // ecx
  volatile __int32 *v48; // edx
  _DWORD *v49; // ecx
  _DWORD *v50; // eax
  volatile __int32 *v51; // edx
  volatile __int32 *v52; // edx
  int v53; // eax
  int *v54; // eax
  int v55; // edx
  int v56; // edx
  volatile __int32 *v57; // ecx
  int v58; // eax
  int *v59; // eax
  int v60; // edx
  int v61; // edx
  volatile __int32 *v62; // ecx
  unsigned int v63; // ebx
  int v64; // eax
  int v65; // edx
  int v66; // edx
  volatile __int32 *v67; // ecx
  unsigned int v68; // ebx
  int v69; // eax
  int v70; // edx
  int v71; // edx
  volatile __int32 *v72; // ecx
  char v73; // dl
  char v74; // al
  volatile __int32 *v75; // edx
  _BOOL4 v76; // edx
  int v77; // eax
  int v78; // ebx
  _DWORD *v79; // ebx
  unsigned int v80; // edi
  _DWORD *v81; // ecx
  _DWORD *v82; // eax
  int v83; // eax
  int v84; // eax
  int v85; // eax
  _DWORD *v86; // [esp+Ch] [ebp-5Ch]
  _DWORD *v87; // [esp+Ch] [ebp-5Ch]
  _DWORD *v88; // [esp+Ch] [ebp-5Ch]
  _DWORD *v89; // [esp+Ch] [ebp-5Ch]
  int v90; // [esp+10h] [ebp-58h]
  unsigned int v91; // [esp+1Ch] [ebp-4Ch]
  int v92; // [esp+20h] [ebp-48h]
  _DWORD *v93; // [esp+24h] [ebp-44h]
  int v94; // [esp+28h] [ebp-40h]
  unsigned int v95; // [esp+2Ch] [ebp-3Ch]
  int *v96; // [esp+30h] [ebp-38h]
  int *v97; // [esp+34h] [ebp-34h]
  int *v98; // [esp+38h] [ebp-30h]
  int *v99; // [esp+3Ch] [ebp-2Ch]
  int v100; // [esp+44h] [ebp-24h]
  unsigned int v101; // [esp+48h] [ebp-20h]
  unsigned int v102; // [esp+50h] [ebp-18h]
  unsigned int v103; // [esp+54h] [ebp-14h]
  int v104; // [esp+58h] [ebp-10h]
  int v105; // [esp+5Ch] [ebp-Ch]
  _DWORD *v106; // [esp+60h] [ebp-8h]
  _DWORD *v107; // [esp+60h] [ebp-8h]
  _DWORD *v108; // [esp+60h] [ebp-8h]
  _DWORD *v109; // [esp+64h] [ebp-4h] BYREF

  v102 = a4 + a5; /*0x1768a0*/
  v101 = a4 + a3; /*0x1768ae*/
  if ( a4 + a3 < a3 || v102 < a5 ) /*0x1768bb*/
    return 3; /*0x1768c2*/
  v8 = a1; /*0x1768c8*/
  if ( a2 == a1 ) /*0x1768ce*/
    goto LABEL_8; /*0x1768ce*/
  if ( a2 >= a1 ) /*0x1768d6*/
  {
    lock_write(a1); /*0x1768f8*/
    ++*(_DWORD *)(a1 + 76); /*0x1768fd*/
    v8 = a2; /*0x176903*/
LABEL_8:
    lock_write(v8); /*0x176906*/
    ++*(_DWORD *)(v8 + 76); /*0x17690c*/
    goto LABEL_9; /*0x17690c*/
  }
  lock_write(a2); /*0x1768dc*/
  ++*(_DWORD *)(a2 + 76); /*0x1768e1*/
  lock_write(a1); /*0x1768e8*/
  ++*(_DWORD *)(a1 + 76); /*0x1768ed*/
LABEL_9:
  v100 = 0; /*0x17690f*/
  if ( !*(_DWORD *)(a2 + 44) || !*(_DWORD *)(a1 + 44) ) /*0x176929*/
    goto LABEL_96; /*0x17692d*/
  v9 = a5; /*0x176933*/
  v10 = (volatile __int32 *)(a2 + 60); /*0x176938*/
  do /*0x17694e*/
  {
    while ( *v10 ) /*0x17693c*/
      ; /*0x17693e*/
  }
  while ( _InterlockedExchange(v10, 1) == 1 ); /*0x17694e*/
  v11 = *(_DWORD **)(a2 + 56); /*0x176953*/
  _InterlockedExchange((volatile __int32 *)(a2 + 60), 0); /*0x176958*/
  v12 = (_DWORD *)(a2 + 12); /*0x17695d*/
  if ( v11 == (_DWORD *)(a2 + 12) ) /*0x176962*/
    v11 = *(_DWORD **)(a2 + 16); /*0x176964*/
  if ( v11[2] > a5 ) /*0x17696a*/
  {
    v12 = (_DWORD *)v11[1]; /*0x176980*/
    v11 = *(_DWORD **)(a2 + 16); /*0x176986*/
LABEL_28:
    while ( v11 != v12 ) /*0x1769c9*/
    {
      if ( v11[3] > a5 ) /*0x17698f*/
      {
        if ( v11[2] > a5 ) /*0x176994*/
          goto LABEL_29; /*0x176994*/
        v109 = v11; /*0x176996*/
        v13 = (volatile __int32 *)(a2 + 60); /*0x17699c*/
        do /*0x1769b2*/
        {
          while ( *v13 ) /*0x1769a0*/
            ; /*0x1769a2*/
        }
        while ( _InterlockedExchange(v13, 1) == 1 ); /*0x1769b2*/
        *(_DWORD *)(a2 + 56) = v11; /*0x1769b7*/
        _InterlockedExchange((volatile __int32 *)(a2 + 60), 0); /*0x1769bc*/
        goto LABEL_33; /*0x1769bf*/
      }
      v11 = (_DWORD *)v11[1]; /*0x1769c4*/
    }
    goto LABEL_29; /*0x1769c9*/
  }
  if ( v11 == v12 ) /*0x17696e*/
  {
LABEL_29:
    v109 = (_DWORD *)*v11; /*0x1769cb*/
    v14 = (volatile __int32 *)(a2 + 60); /*0x1769d3*/
    do /*0x1769ea*/
    {
      while ( *v14 ) /*0x1769d8*/
        ; /*0x1769da*/
    }
    while ( _InterlockedExchange(v14, 1) == 1 ); /*0x1769ea*/
    *(_DWORD *)(a2 + 56) = v109; /*0x1769f2*/
    _InterlockedExchange((volatile __int32 *)(a2 + 60), 0); /*0x1769f7*/
    goto LABEL_95; /*0x1769fa*/
  }
  if ( v11[3] <= a5 ) /*0x176973*/
    goto LABEL_28; /*0x176973*/
  v109 = v11; /*0x176975*/
LABEL_33:
  v15 = v109; /*0x176a00*/
  if ( v102 > a5 ) /*0x176a06*/
  {
    while ( v15 != (_DWORD *)(a2 + 12) && v15[2] <= v9 && (v15[7] & 1) != 0 ) /*0x176a25*/
    {
      v9 = v15[3]; /*0x176a2b*/
      v15 = (_DWORD *)v15[1]; /*0x176a2e*/
      if ( v102 <= v9 ) /*0x176a34*/
        goto LABEL_38; /*0x176a34*/
    }
    goto LABEL_95; /*0x176a25*/
  }
LABEL_38:
  if ( !a6 ) /*0x176a3a*/
  {
    v23 = a3; /*0x176be0*/
    v24 = (volatile __int32 *)(a1 + 60); /*0x176be6*/
    do /*0x176bfe*/
    {
      while ( *v24 ) /*0x176bec*/
        ; /*0x176bee*/
    }
    while ( _InterlockedExchange(v24, 1) == 1 ); /*0x176bfe*/
    v25 = *(_DWORD **)(a1 + 56); /*0x176c03*/
    _InterlockedExchange((volatile __int32 *)(a1 + 60), 0); /*0x176c08*/
    v26 = (_DWORD *)(a1 + 12); /*0x176c0d*/
    if ( v25 == (_DWORD *)(a1 + 12) ) /*0x176c12*/
      v25 = *(_DWORD **)(a1 + 16); /*0x176c14*/
    if ( v25[2] > a3 ) /*0x176c1a*/
    {
      v26 = (_DWORD *)v25[1]; /*0x176c2c*/
      v25 = *(_DWORD **)(a1 + 16); /*0x176c32*/
LABEL_84:
      while ( v25 != v26 ) /*0x176c75*/
      {
        if ( v25[3] > a3 ) /*0x176c3b*/
        {
          if ( v25[2] > a3 ) /*0x176c40*/
            break; /*0x176c40*/
          v109 = v25; /*0x176c42*/
          v27 = (volatile __int32 *)(a1 + 60); /*0x176c48*/
          do /*0x176c5e*/
          {
            while ( *v27 ) /*0x176c4c*/
              ; /*0x176c4e*/
          }
          while ( _InterlockedExchange(v27, 1) == 1 ); /*0x176c5e*/
          *(_DWORD *)(a1 + 56) = v25; /*0x176c63*/
          _InterlockedExchange((volatile __int32 *)(a1 + 60), 0); /*0x176c68*/
          goto LABEL_89; /*0x176c6b*/
        }
        v25 = (_DWORD *)v25[1]; /*0x176c70*/
      }
    }
    else if ( v25 != v26 ) /*0x176c1e*/
    {
      if ( v25[3] <= a3 ) /*0x176c23*/
        goto LABEL_84; /*0x176c23*/
      v109 = v25; /*0x176c25*/
LABEL_89:
      v29 = v109; /*0x176ca8*/
      if ( v101 <= a3 ) /*0x176cae*/
        goto LABEL_96; /*0x176cae*/
      while ( v29 != (_DWORD *)(a1 + 12) && v29[2] <= v23 && (v29[7] & 2) != 0 ) /*0x176cc5*/
      {
        v23 = v29[3]; /*0x176cc7*/
        v29 = (_DWORD *)v29[1]; /*0x176cca*/
        if ( v101 <= v23 ) /*0x176cd0*/
          goto LABEL_96; /*0x176cd0*/
      }
LABEL_95:
      v100 = 2; /*0x176cd4*/
      goto LABEL_303; /*0x176cdb*/
    }
    v109 = (_DWORD *)*v25; /*0x176c77*/
    v28 = (volatile __int32 *)(a1 + 60); /*0x176c7f*/
    do /*0x176c96*/
    {
      while ( *v28 ) /*0x176c84*/
        ; /*0x176c86*/
    }
    while ( _InterlockedExchange(v28, 1) == 1 ); /*0x176c96*/
    *(_DWORD *)(a1 + 56) = v109; /*0x176c9e*/
    _InterlockedExchange((volatile __int32 *)(a1 + 60), 0); /*0x176ca3*/
    goto LABEL_95; /*0x176ca6*/
  }
  if ( *(_DWORD *)(a1 + 20) <= a3 && *(_DWORD *)(a1 + 24) >= v101 && a3 < v101 ) /*0x176a56*/
  {
    if ( vm_map_lookup_entry(a1, a3, &v109) /*0x176a92*/
      || (v16 = v109, v17 = v109[1], v17 != a1 + 12) && *(_DWORD *)(v17 + 8) < v101 )
    {
      v100 = 3; /*0x176a94*/
      goto LABEL_303; /*0x176a9b*/
    }
    if ( v109 != (_DWORD *)(a1 + 12) /*0x176afa*/
      && v109[3] == a3
      && (v109[6] & 5) == 0
      && v109[9] == 1
      && v109[7] == 3
      && v109[8] == 7
      && !*((_WORD *)v109 + 20)
      && (v86 = v109, v18 = vm_object_coalesce(v109[4], 0, v109[5], 0, a3 - v109[2], a4), v16 = v86, v18) )
    {
      *(_DWORD *)(a1 + 40) += v101 - v86[3]; /*0x176b05*/
      v86[3] = v101; /*0x176b0b*/
    }
    else
    {
      if ( *(_DWORD *)(a1 + 32) ) /*0x176b1f*/
        v19 = vm_map_entry_zone; /*0x176b25*/
      else
        v19 = vm_map_kentry_zone; /*0x176b2c*/
      v87 = v16; /*0x176b32*/
      v20 = zalloc(v19); /*0x176b35*/
      v21 = v20; /*0x176b3a*/
      if ( !v20 ) /*0x176b44*/
        panic(aVmMapEntryCrea); /*0x176b4e*/
      *(_DWORD *)(v20 + 8) = a3; /*0x176b5e*/
      *(_DWORD *)(v20 + 12) = v101; /*0x176b64*/
      *(_BYTE *)(v20 + 24) &= 0xFAu; /*0x176b67*/
      *(_DWORD *)(v20 + 16) = 0; /*0x176b6b*/
      *(_DWORD *)(v20 + 20) = 0; /*0x176b72*/
      *(_BYTE *)(v20 + 24) &= 0xB7u; /*0x176b79*/
      if ( *(_DWORD *)(a1 + 44) ) /*0x176b80*/
      {
        *(_DWORD *)(v20 + 36) = 1; /*0x176b86*/
        *(_DWORD *)(v20 + 28) = 3; /*0x176b8d*/
        *(_DWORD *)(v20 + 32) = 7; /*0x176b94*/
        *(_WORD *)(v20 + 40) = 0; /*0x176b9b*/
      }
      ++*(_DWORD *)(a1 + 28); /*0x176ba4*/
      *(_DWORD *)v20 = v87; /*0x176ba7*/
      *(_DWORD *)(v20 + 4) = v87[1]; /*0x176bac*/
      v22 = *(_DWORD *)v20; /*0x176baf*/
      **(_DWORD **)(v21 + 4) = v21; /*0x176bb4*/
      *(_DWORD *)(v22 + 4) = v21; /*0x176bb6*/
      *(_DWORD *)(a1 + 40) += *(_DWORD *)(v21 + 12) - *(_DWORD *)(v21 + 8); /*0x176bbf*/
      if ( *(_DWORD **)(a1 + 64) == v87 && v87[3] >= *(_DWORD *)(v21 + 8) ) /*0x176bd1*/
        *(_DWORD *)(a1 + 64) = v21; /*0x176bd7*/
    }
    v100 = 0; /*0x176b0e*/
LABEL_96:
    v30 = (volatile __int32 *)(a2 + 60); /*0x176ce0*/
    do /*0x176cfa*/
    {
      while ( *v30 ) /*0x176ce8*/
        ; /*0x176cea*/
    }
    while ( _InterlockedExchange(v30, 1) == 1 ); /*0x176cfa*/
    v31 = *(_DWORD **)(a2 + 56); /*0x176cff*/
    _InterlockedExchange((volatile __int32 *)(a2 + 60), 0); /*0x176d04*/
    v32 = (_DWORD *)(a2 + 12); /*0x176d09*/
    if ( v31 == (_DWORD *)(a2 + 12) ) /*0x176d0e*/
      v31 = *(_DWORD **)(a2 + 16); /*0x176d10*/
    if ( v31[2] > a5 ) /*0x176d19*/
    {
      v32 = (_DWORD *)v31[1]; /*0x176d2c*/
      v31 = *(_DWORD **)(a2 + 16); /*0x176d32*/
LABEL_113:
      while ( v31 != v32 ) /*0x176d79*/
      {
        if ( v31[3] > a5 ) /*0x176d3e*/
        {
          if ( v31[2] > a5 ) /*0x176d43*/
            break; /*0x176d43*/
          v106 = v31; /*0x176d45*/
          v33 = (volatile __int32 *)(a2 + 60); /*0x176d4b*/
          do /*0x176d62*/
          {
            while ( *v33 ) /*0x176d50*/
              ; /*0x176d52*/
          }
          while ( _InterlockedExchange(v33, 1) == 1 ); /*0x176d62*/
          *(_DWORD *)(a2 + 56) = v31; /*0x176d67*/
          _InterlockedExchange((volatile __int32 *)(a2 + 60), 0); /*0x176d6c*/
          goto LABEL_118; /*0x176d6f*/
        }
        v31 = (_DWORD *)v31[1]; /*0x176d74*/
      }
    }
    else if ( v31 != v32 ) /*0x176d1d*/
    {
      if ( v31[3] <= a5 ) /*0x176d22*/
        goto LABEL_113; /*0x176d22*/
      v106 = v31; /*0x176d24*/
LABEL_118:
      v105 = (int)v106; /*0x176daa*/
      if ( v106[2] < a5 ) /*0x176db6*/
      {
        if ( *(_DWORD *)(a2 + 32) ) /*0x176dc5*/
          v35 = vm_map_entry_zone; /*0x176dcb*/
        else
          v35 = vm_map_kentry_zone; /*0x176dd4*/
        v99 = (int *)zalloc(v35); /*0x176ddf*/
        if ( !v99 ) /*0x176de7*/
          panic(aVmMapEntryCrea); /*0x176dee*/
        qmemcpy(v99, v106, 0x2Cu); /*0x176e0c*/
        v99[3] = a5; /*0x176e11*/
        v106[5] += a5 - v106[2]; /*0x176e1d*/
        v106[2] = a5; /*0x176e20*/
        ++*(_DWORD *)(a2 + 28); /*0x176e23*/
        *v99 = *v106; /*0x176e2b*/
        v99[1] = *(_DWORD *)(*v106 + 4); /*0x176e38*/
        v36 = *v99; /*0x176e3b*/
        *(_DWORD *)v99[1] = v99; /*0x176e40*/
        *(_DWORD *)(v36 + 4) = v99; /*0x176e42*/
        if ( (v106[6] & 5) != 0 ) /*0x176e49*/
        {
          v37 = v99[4]; /*0x176e4b*/
          if ( v37 ) /*0x176e50*/
          {
            v38 = (volatile __int32 *)(v37 + 52); /*0x176e52*/
            do /*0x176e6a*/
            {
              while ( *v38 ) /*0x176e58*/
                ; /*0x176e5a*/
            }
            while ( _InterlockedExchange(v38, 1) == 1 ); /*0x176e6a*/
            ++*(_DWORD *)(v37 + 48); /*0x176e6c*/
            _InterlockedExchange((volatile __int32 *)(v37 + 52), 0); /*0x176e71*/
          }
        }
        else
        {
          vm_object_reference(v99[4]); /*0x176e7f*/
        }
      }
      v39 = (volatile __int32 *)(a1 + 60); /*0x176e8a*/
      do /*0x176ea2*/
      {
        while ( *v39 ) /*0x176e90*/
          ; /*0x176e92*/
      }
      while ( _InterlockedExchange(v39, 1) == 1 ); /*0x176ea2*/
      v40 = *(_DWORD **)(a1 + 56); /*0x176ea7*/
      _InterlockedExchange((volatile __int32 *)(a1 + 60), 0); /*0x176eac*/
      v41 = (_DWORD *)(a1 + 12); /*0x176eb1*/
      if ( v40 == (_DWORD *)(a1 + 12) ) /*0x176eb6*/
        v40 = *(_DWORD **)(a1 + 16); /*0x176eb8*/
      if ( v40[2] > a3 ) /*0x176ec1*/
      {
        v41 = (_DWORD *)v40[1]; /*0x176ed4*/
        v40 = *(_DWORD **)(a1 + 16); /*0x176eda*/
LABEL_148:
        while ( v40 != v41 ) /*0x176f21*/
        {
          if ( v40[3] > a3 ) /*0x176ee6*/
          {
            if ( v40[2] > a3 ) /*0x176eeb*/
              break; /*0x176eeb*/
            v107 = v40; /*0x176eed*/
            v42 = (volatile __int32 *)(a1 + 60); /*0x176ef3*/
            do /*0x176f0a*/
            {
              while ( *v42 ) /*0x176ef8*/
                ; /*0x176efa*/
            }
            while ( _InterlockedExchange(v42, 1) == 1 ); /*0x176f0a*/
            *(_DWORD *)(a1 + 56) = v40; /*0x176f0f*/
            _InterlockedExchange((volatile __int32 *)(a1 + 60), 0); /*0x176f14*/
            goto LABEL_153; /*0x176f17*/
          }
          v40 = (_DWORD *)v40[1]; /*0x176f1c*/
        }
      }
      else if ( v40 != v41 ) /*0x176ec5*/
      {
        if ( v40[3] <= a3 ) /*0x176eca*/
          goto LABEL_148; /*0x176eca*/
        v107 = v40; /*0x176ecc*/
LABEL_153:
        v104 = (int)v107; /*0x176f52*/
        if ( v107[2] < a3 ) /*0x176f5e*/
        {
          if ( *(_DWORD *)(a1 + 32) ) /*0x176f6d*/
            v44 = vm_map_entry_zone; /*0x176f73*/
          else
            v44 = vm_map_kentry_zone; /*0x176f7c*/
          v98 = (int *)zalloc(v44); /*0x176f87*/
          if ( !v98 ) /*0x176f8f*/
            panic(aVmMapEntryCrea); /*0x176f96*/
          qmemcpy(v98, v107, 0x2Cu); /*0x176fb4*/
          v98[3] = a3; /*0x176fb9*/
          v107[5] += a3 - v107[2]; /*0x176fc5*/
          v107[2] = a3; /*0x176fc8*/
          ++*(_DWORD *)(a1 + 28); /*0x176fcb*/
          *v98 = *v107; /*0x176fd3*/
          v98[1] = *(_DWORD *)(*v107 + 4); /*0x176fe0*/
          v45 = *v98; /*0x176fe3*/
          *(_DWORD *)v98[1] = v98; /*0x176fe8*/
          *(_DWORD *)(v45 + 4) = v98; /*0x176fea*/
          if ( (v107[6] & 5) != 0 ) /*0x176ff1*/
          {
            v46 = v98[4]; /*0x176ff3*/
            if ( v46 ) /*0x176ff8*/
            {
              v47 = (volatile __int32 *)(v46 + 52); /*0x176ffa*/
              do /*0x177012*/
              {
                while ( *v47 ) /*0x177000*/
                  ; /*0x177002*/
              }
              while ( _InterlockedExchange(v47, 1) == 1 ); /*0x177012*/
              ++*(_DWORD *)(v46 + 48); /*0x177014*/
              _InterlockedExchange((volatile __int32 *)(v46 + 52), 0); /*0x177019*/
            }
          }
          else
          {
            vm_object_reference(v98[4]); /*0x177027*/
          }
        }
        if ( (_DWORD *)v105 != v107 ) /*0x177035*/
          goto LABEL_190; /*0x177035*/
        v48 = (volatile __int32 *)(a2 + 60); /*0x17703e*/
        do /*0x177056*/
        {
          while ( *v48 ) /*0x177044*/
            ; /*0x177046*/
        }
        while ( _InterlockedExchange(v48, 1) == 1 ); /*0x177056*/
        v49 = *(_DWORD **)(a2 + 56); /*0x17705b*/
        _InterlockedExchange((volatile __int32 *)(a2 + 60), 0); /*0x177060*/
        v50 = (_DWORD *)(a2 + 12); /*0x177065*/
        if ( v49 == (_DWORD *)(a2 + 12) ) /*0x17706a*/
          v49 = *(_DWORD **)(a2 + 16); /*0x17706c*/
        if ( v49[2] > a5 ) /*0x177075*/
        {
          v50 = (_DWORD *)v49[1]; /*0x177088*/
          v49 = *(_DWORD **)(a2 + 16); /*0x17708e*/
LABEL_184:
          while ( v49 != v50 ) /*0x1770d5*/
          {
            if ( v49[3] > a5 ) /*0x17709a*/
            {
              if ( v49[2] > a5 ) /*0x17709f*/
                break; /*0x17709f*/
              v108 = v49; /*0x1770a1*/
              v51 = (volatile __int32 *)(a2 + 60); /*0x1770a7*/
              do /*0x1770be*/
              {
                while ( *v51 ) /*0x1770ac*/
                  ; /*0x1770ae*/
              }
              while ( _InterlockedExchange(v51, 1) == 1 ); /*0x1770be*/
              *(_DWORD *)(a2 + 56) = v49; /*0x1770c3*/
              _InterlockedExchange((volatile __int32 *)(a2 + 60), 0); /*0x1770c8*/
              goto LABEL_189; /*0x1770cb*/
            }
            v49 = (_DWORD *)v49[1]; /*0x1770d0*/
          }
        }
        else if ( v49 != v50 ) /*0x177079*/
        {
          if ( v49[3] <= a5 ) /*0x17707e*/
            goto LABEL_184; /*0x17707e*/
          v108 = v49; /*0x177080*/
LABEL_189:
          v105 = (int)v108; /*0x177106*/
          if ( v108 == (_DWORD *)v104 ) /*0x177111*/
            goto LABEL_303; /*0x177111*/
LABEL_190:
          if ( a5 < v102 ) /*0x17711d*/
          {
            do /*0x1779f9*/
            {
              if ( *(_DWORD *)(v105 + 12) > v102 ) /*0x17712d*/
              {
                if ( *(_DWORD *)(a2 + 32) ) /*0x17713c*/
                  v53 = vm_map_entry_zone; /*0x177142*/
                else
                  v53 = vm_map_kentry_zone; /*0x17714c*/
                v54 = (int *)zalloc(v53); /*0x177155*/
                if ( !v54 ) /*0x177164*/
                  panic(aVmMapEntryCrea); /*0x17716e*/
                qmemcpy(v54, (const void *)v105, 0x2Cu); /*0x177190*/
                *(_DWORD *)(v105 + 12) = v102; /*0x177198*/
                v54[2] = v102; /*0x17719e*/
                v54[5] += v102 - *(_DWORD *)(v105 + 8); /*0x1771aa*/
                ++*(_DWORD *)(a2 + 28); /*0x1771ad*/
                *v54 = v105; /*0x1771b0*/
                v54[1] = *(_DWORD *)(v105 + 4); /*0x1771b5*/
                v55 = *v54; /*0x1771b8*/
                *(_DWORD *)v54[1] = v54; /*0x1771bd*/
                *(_DWORD *)(v55 + 4) = v54; /*0x1771bf*/
                if ( (*(_BYTE *)(v105 + 24) & 5) != 0 ) /*0x1771c9*/
                {
                  v56 = v54[4]; /*0x1771ce*/
                  if ( v56 ) /*0x1771d3*/
                  {
                    v57 = (volatile __int32 *)(v56 + 52); /*0x1771d5*/
                    do /*0x1771ea*/
                    {
                      while ( *v57 ) /*0x1771d8*/
                        ; /*0x1771da*/
                    }
                    while ( _InterlockedExchange(v57, 1) == 1 ); /*0x1771ea*/
                    ++*(_DWORD *)(v56 + 48); /*0x1771ec*/
                    _InterlockedExchange((volatile __int32 *)(v56 + 52), 0); /*0x1771f1*/
                  }
                }
                else
                {
                  vm_object_reference(v54[4]); /*0x1771fc*/
                }
              }
              if ( *(_DWORD *)(v104 + 12) > v101 ) /*0x17720d*/
              {
                if ( *(_DWORD *)(a1 + 32) ) /*0x17721c*/
                  v58 = vm_map_entry_zone; /*0x177222*/
                else
                  v58 = vm_map_kentry_zone; /*0x17722c*/
                v59 = (int *)zalloc(v58); /*0x177235*/
                if ( !v59 ) /*0x177244*/
                  panic(aVmMapEntryCrea); /*0x17724e*/
                qmemcpy(v59, (const void *)v104, 0x2Cu); /*0x177270*/
                *(_DWORD *)(v104 + 12) = v101; /*0x177278*/
                v59[2] = v101; /*0x17727e*/
                v59[5] += v101 - *(_DWORD *)(v104 + 8); /*0x17728a*/
                ++*(_DWORD *)(a1 + 28); /*0x17728d*/
                *v59 = v104; /*0x177290*/
                v59[1] = *(_DWORD *)(v104 + 4); /*0x177295*/
                v60 = *v59; /*0x177298*/
                *(_DWORD *)v59[1] = v59; /*0x17729d*/
                *(_DWORD *)(v60 + 4) = v59; /*0x17729f*/
                if ( (*(_BYTE *)(v104 + 24) & 5) != 0 ) /*0x1772a9*/
                {
                  v61 = v59[4]; /*0x1772ae*/
                  if ( v61 ) /*0x1772b3*/
                  {
                    v62 = (volatile __int32 *)(v61 + 52); /*0x1772b5*/
                    do /*0x1772ca*/
                    {
                      while ( *v62 ) /*0x1772b8*/
                        ; /*0x1772ba*/
                    }
                    while ( _InterlockedExchange(v62, 1) == 1 ); /*0x1772ca*/
                    ++*(_DWORD *)(v61 + 48); /*0x1772cc*/
                    _InterlockedExchange((volatile __int32 *)(v61 + 52), 0); /*0x1772d1*/
                  }
                }
                else
                {
                  vm_object_reference(v59[4]); /*0x1772dc*/
                }
              }
              v63 = *(_DWORD *)(v104 + 12) - *(_DWORD *)(v104 + 8) + *(_DWORD *)(v105 + 8); /*0x1772f3*/
              if ( *(_DWORD *)(v105 + 12) > v63 ) /*0x1772f8*/
              {
                if ( *(_DWORD *)(a2 + 32) ) /*0x177307*/
                  v64 = vm_map_entry_zone; /*0x17730d*/
                else
                  v64 = vm_map_kentry_zone; /*0x177314*/
                v97 = (int *)zalloc(v64); /*0x177322*/
                if ( !v97 ) /*0x17732d*/
                  panic(aVmMapEntryCrea); /*0x177337*/
                qmemcpy(v97, (const void *)v105, 0x2Cu); /*0x177359*/
                *(_DWORD *)(v105 + 12) = v63; /*0x17735e*/
                v97[2] = v63; /*0x177364*/
                v97[5] += v63 - *(_DWORD *)(v105 + 8); /*0x17736c*/
                ++*(_DWORD *)(a2 + 28); /*0x17736f*/
                *v97 = v105; /*0x177372*/
                v97[1] = *(_DWORD *)(v105 + 4); /*0x177377*/
                v65 = *v97; /*0x17737a*/
                *(_DWORD *)v97[1] = v97; /*0x17737f*/
                *(_DWORD *)(v65 + 4) = v97; /*0x177381*/
                if ( (*(_BYTE *)(v105 + 24) & 5) != 0 ) /*0x17738b*/
                {
                  v66 = v97[4]; /*0x177390*/
                  if ( v66 ) /*0x177395*/
                  {
                    v67 = (volatile __int32 *)(v66 + 52); /*0x177397*/
                    do /*0x1773ae*/
                    {
                      while ( *v67 ) /*0x17739c*/
                        ; /*0x17739e*/
                    }
                    while ( _InterlockedExchange(v67, 1) == 1 ); /*0x1773ae*/
                    ++*(_DWORD *)(v66 + 48); /*0x1773b0*/
                    _InterlockedExchange((volatile __int32 *)(v66 + 52), 0); /*0x1773b5*/
                  }
                }
                else
                {
                  vm_object_reference(v97[4]); /*0x1773c3*/
                }
              }
              v68 = *(_DWORD *)(v105 + 12) - *(_DWORD *)(v105 + 8) + *(_DWORD *)(v104 + 8); /*0x1773da*/
              if ( *(_DWORD *)(v104 + 12) > v68 ) /*0x1773df*/
              {
                if ( *(_DWORD *)(a1 + 32) ) /*0x1773ee*/
                  v69 = vm_map_entry_zone; /*0x1773f4*/
                else
                  v69 = vm_map_kentry_zone; /*0x1773fc*/
                v96 = (int *)zalloc(v69); /*0x17740a*/
                if ( !v96 ) /*0x177415*/
                  panic(aVmMapEntryCrea); /*0x17741f*/
                qmemcpy(v96, (const void *)v104, 0x2Cu); /*0x177441*/
                *(_DWORD *)(v104 + 12) = v68; /*0x177446*/
                v96[2] = v68; /*0x17744c*/
                v96[5] += v68 - *(_DWORD *)(v104 + 8); /*0x177454*/
                ++*(_DWORD *)(a1 + 28); /*0x177457*/
                *v96 = v104; /*0x17745a*/
                v96[1] = *(_DWORD *)(v104 + 4); /*0x17745f*/
                v70 = *v96; /*0x177462*/
                *(_DWORD *)v96[1] = v96; /*0x177467*/
                *(_DWORD *)(v70 + 4) = v96; /*0x177469*/
                if ( (*(_BYTE *)(v104 + 24) & 5) != 0 ) /*0x177473*/
                {
                  v71 = v96[4]; /*0x177478*/
                  if ( v71 ) /*0x17747d*/
                  {
                    v72 = (volatile __int32 *)(v71 + 52); /*0x17747f*/
                    do /*0x177496*/
                    {
                      while ( *v72 ) /*0x177484*/
                        ; /*0x177486*/
                    }
                    while ( _InterlockedExchange(v72, 1) == 1 ); /*0x177496*/
                    ++*(_DWORD *)(v71 + 48); /*0x177498*/
                    _InterlockedExchange((volatile __int32 *)(v71 + 52), 0); /*0x17749d*/
                  }
                }
                else
                {
                  vm_object_reference(v96[4]); /*0x1774ab*/
                }
              }
              v73 = *(_BYTE *)(v105 + 24); /*0x1774b6*/
              if ( (v73 & 1) != 0 || (v74 = *(_BYTE *)(v104 + 24), (v74 & 1) != 0) ) /*0x1774ca*/
              {
                v94 = *(_DWORD *)(v104 + 12) - *(_DWORD *)(v104 + 8); /*0x177695*/
                if ( (*(_BYTE *)(v105 + 24) & 1) != 0 ) /*0x17769f*/
                {
                  v93 = *(_DWORD **)(v105 + 16); /*0x1776a4*/
                  v92 = *(_DWORD *)(v105 + 20); /*0x1776aa*/
                }
                else
                {
                  v93 = (_DWORD *)a2; /*0x1776b3*/
                  v92 = *(_DWORD *)(v105 + 8); /*0x1776bc*/
                  lock_set_recursive(a2); /*0x1776c0*/
                }
                if ( (*(_BYTE *)(v104 + 24) & 1) != 0 ) /*0x1776cf*/
                {
                  v79 = *(_DWORD **)(v104 + 16); /*0x1776d5*/
                  v95 = *(_DWORD *)(v104 + 20); /*0x1776db*/
                  v80 = v94 + v95; /*0x1776de*/
                  v91 = v94 + v95; /*0x1776e1*/
                  if ( v93 != v79 ) /*0x1776e7*/
                  {
                    lock_write((int)v79); /*0x1776ee*/
                    ++v79[19]; /*0x1776f3*/
                    vm_map_delete((int)v79, v95, v80); /*0x1776ff*/
                    if ( v79[5] <= v95 && v79[6] >= v80 && v95 < v80 && !vm_map_lookup_entry((int)v79, v95, &v109) ) /*0x177727*/
                    {
                      v81 = v109; /*0x177737*/
                      v82 = (_DWORD *)v109[1]; /*0x17773d*/
                      if ( v82 == v79 + 3 || v82[2] >= v80 ) /*0x177747*/
                      {
                        if ( v109 != v79 + 3 /*0x1777a1*/
                          && v109[3] == v95
                          && (v109[6] & 5) == 0
                          && v109[9] == 1
                          && v109[7] == 3
                          && v109[8] == 7
                          && !*((_WORD *)v109 + 20)
                          && (v88 = v109,
                              v83 = vm_object_coalesce(v109[4], 0, v109[5], 0, v95 - v109[2], v94),
                              v81 = v88,
                              v83) )
                        {
                          v79[10] += v91 - v88[3]; /*0x1777a9*/
                          v88[3] = v91; /*0x1777af*/
                        }
                        else
                        {
                          if ( v79[8] ) /*0x1777b8*/
                            v84 = vm_map_entry_zone; /*0x1777be*/
                          else
                            v84 = vm_map_kentry_zone; /*0x1777c8*/
                          v89 = v81; /*0x1777ce*/
                          v90 = zalloc(v84); /*0x1777d6*/
                          if ( !v90 ) /*0x1777e1*/
                            panic(aVmMapEntryCrea); /*0x1777eb*/
                          *(_DWORD *)(v90 + 8) = v95; /*0x1777fc*/
                          *(_DWORD *)(v90 + 12) = v91; /*0x177802*/
                          *(_BYTE *)(v90 + 24) &= 0xFAu; /*0x177805*/
                          *(_DWORD *)(v90 + 16) = 0; /*0x177809*/
                          *(_DWORD *)(v90 + 20) = 0; /*0x177810*/
                          *(_BYTE *)(v90 + 24) &= 0xB7u; /*0x177817*/
                          if ( v79[11] ) /*0x17781b*/
                          {
                            *(_DWORD *)(v90 + 36) = 1; /*0x177821*/
                            *(_DWORD *)(v90 + 28) = 3; /*0x177828*/
                            *(_DWORD *)(v90 + 32) = 7; /*0x17782f*/
                            *(_WORD *)(v90 + 40) = 0; /*0x177836*/
                          }
                          ++v79[7]; /*0x17783c*/
                          *(_DWORD *)v90 = v89; /*0x177842*/
                          *(_DWORD *)(v90 + 4) = v89[1]; /*0x177847*/
                          v85 = *(_DWORD *)v90; /*0x17784a*/
                          **(_DWORD **)(v90 + 4) = v90; /*0x17784f*/
                          *(_DWORD *)(v85 + 4) = v90; /*0x177851*/
                          v79[10] += *(_DWORD *)(v90 + 12) - *(_DWORD *)(v90 + 8); /*0x17785a*/
                          if ( (_DWORD *)v79[16] == v89 && v89[3] >= *(_DWORD *)(v90 + 8) ) /*0x17786b*/
                            v79[16] = v90; /*0x17786d*/
                        }
                      }
                    }
                    lock_done((int)v79); /*0x177871*/
                  }
                }
                else
                {
                  v79 = (_DWORD *)a1; /*0x177878*/
                  v95 = *(_DWORD *)(v104 + 8); /*0x177881*/
                  lock_set_recursive(a1); /*0x177885*/
                }
                vm_map_copy(v79, v93, v95, v94, v92, 0, 0); /*0x1778a2*/
                if ( (_DWORD *)a1 == v79 ) /*0x1778ad*/
                  lock_clear_recursive(a1); /*0x1778b3*/
                if ( (_DWORD *)a2 == v93 ) /*0x1778c1*/
                  lock_clear_recursive(a2); /*0x1778c7*/
              }
              else if ( (v73 & 4) == 0 && (v74 & 4) == 0 ) /*0x1774db*/
              {
                if ( *(_WORD *)(v104 + 40) ) /*0x1774e1*/
                {
                  vm_fault_unwire(a1, v104); /*0x1774ed*/
                  *(_WORD *)(v104 + 40) = 0; /*0x1774f2*/
                }
                if ( !*(_DWORD *)(a1 + 44) ) /*0x1774fe*/
                  vm_object_pmap_remove( /*0x17751b*/
                    *(_DWORD *)(v104 + 16),
                    *(_DWORD *)(v104 + 20),
                    *(_DWORD *)(v104 + 20) + *(_DWORD *)(v104 + 12) - *(_DWORD *)(v104 + 8));
                pmap_remove(*(_DWORD *)(a1 + 36), *(_DWORD *)(v104 + 8), *(_DWORD *)(v104 + 12)); /*0x177538*/
                if ( *(_WORD *)(v105 + 40) ) /*0x177543*/
                {
                  vm_fault_copy_entry(a1, a2, (_DWORD *)v104, v105); /*0x17767c*/
                }
                else
                {
                  if ( (*(_BYTE *)(v105 + 24) & 0x40) == 0 ) /*0x177552*/
                  {
                    if ( *(_DWORD *)(a2 + 44) ) /*0x177557*/
                      goto LABEL_258; /*0x177557*/
                    v75 = (volatile __int32 *)(a2 + 52); /*0x17755f*/
                    do /*0x177576*/
                    {
                      while ( *v75 ) /*0x177564*/
                        ; /*0x177566*/
                    }
                    while ( _InterlockedExchange(v75, 1) == 1 ); /*0x177576*/
                    v76 = *(_DWORD *)(a2 + 48) == 1; /*0x177582*/
                    _InterlockedExchange((volatile __int32 *)(a2 + 52), 0); /*0x177587*/
                    if ( v76 ) /*0x17758c*/
                    {
LABEL_258:
                      v77 = *(_DWORD *)(v105 + 28); /*0x177591*/
                      LOBYTE(v77) = v77 & 0xFD; /*0x177594*/
                      pmap_protect(*(_DWORD *)(a2 + 36), *(_DWORD *)(v105 + 8), *(_DWORD *)(v105 + 12), v77); /*0x1775a6*/
                    }
                    else
                    {
                      vm_object_pmap_copy( /*0x1775c7*/
                        *(_DWORD *)(v105 + 16),
                        *(_DWORD *)(v105 + 20),
                        *(_DWORD *)(v105 + 20) + *(_DWORD *)(v105 + 12) - *(_DWORD *)(v105 + 8));
                    }
                  }
                  v78 = *(_DWORD *)(v104 + 16); /*0x1775d2*/
                  vm_object_copy( /*0x1775ff*/
                    *(_DWORD *)(v105 + 16),
                    *(_DWORD *)(v105 + 20),
                    *(_DWORD *)(v105 + 12) - *(_DWORD *)(v105 + 8),
                    v104 + 16,
                    v104 + 20,
                    &v109);
                  if ( v109 ) /*0x17760b*/
                    *(_BYTE *)(v105 + 24) |= 0x40u; /*0x177610*/
                  *(_BYTE *)(v104 + 24) |= 0x40u; /*0x177617*/
                  *(_BYTE *)(v105 + 24) |= 8u; /*0x17761e*/
                  *(_BYTE *)(v104 + 24) |= 8u; /*0x177622*/
                  if ( (*(_BYTE *)(v105 + 28) & 4) != 0 ) /*0x17762a*/
                    *(_DWORD *)(v104 + 28) |= *(_DWORD *)(v104 + 32) & 4; /*0x177632*/
                  vm_object_deallocate(v78); /*0x177636*/
                  pmap_copy( /*0x17765d*/
                    *(_DWORD *)(a1 + 36),
                    *(_DWORD *)(a2 + 36),
                    *(_DWORD *)(v104 + 8),
                    *(_DWORD *)(v104 + 12) - *(_DWORD *)(v104 + 8),
                    *(_DWORD *)(v105 + 8));
                }
              }
              v103 = *(_DWORD *)(v105 + 12); /*0x1778d5*/
              v105 = *(_DWORD *)(v105 + 4); /*0x1778de*/
              v104 = *(_DWORD *)(v104 + 4); /*0x1778e7*/
            }
            while ( v103 < v102 ); /*0x1779f9*/
          }
          goto LABEL_303; /*0x1779f9*/
        }
        v108 = (_DWORD *)*v49; /*0x1770d7*/
        v52 = (volatile __int32 *)(a2 + 60); /*0x1770df*/
        do /*0x1770f6*/
        {
          while ( *v52 ) /*0x1770e4*/
            ; /*0x1770e6*/
        }
        while ( _InterlockedExchange(v52, 1) == 1 ); /*0x1770f6*/
        *(_DWORD *)(a2 + 56) = v108; /*0x1770fe*/
        _InterlockedExchange((volatile __int32 *)(a2 + 60), 0); /*0x177103*/
        goto LABEL_189; /*0x177103*/
      }
      v107 = (_DWORD *)*v40; /*0x176f23*/
      v43 = (volatile __int32 *)(a1 + 60); /*0x176f2b*/
      do /*0x176f42*/
      {
        while ( *v43 ) /*0x176f30*/
          ; /*0x176f32*/
      }
      while ( _InterlockedExchange(v43, 1) == 1 ); /*0x176f42*/
      *(_DWORD *)(a1 + 56) = v107; /*0x176f4a*/
      _InterlockedExchange((volatile __int32 *)(a1 + 60), 0); /*0x176f4f*/
      goto LABEL_153; /*0x176f4f*/
    }
    v106 = (_DWORD *)*v31; /*0x176d7b*/
    v34 = (volatile __int32 *)(a2 + 60); /*0x176d83*/
    do /*0x176d9a*/
    {
      while ( *v34 ) /*0x176d88*/
        ; /*0x176d8a*/
    }
    while ( _InterlockedExchange(v34, 1) == 1 ); /*0x176d9a*/
    *(_DWORD *)(a2 + 56) = v106; /*0x176da2*/
    _InterlockedExchange((volatile __int32 *)(a2 + 60), 0); /*0x176da7*/
    goto LABEL_118; /*0x176da7*/
  }
  v100 = 1; /*0x176a58*/
LABEL_303:
  if ( a7 ) /*0x177a35*/
    vm_map_delete(a2, a5, a4 + a5); /*0x177a46*/
  lock_done(a2); /*0x177a52*/
  if ( a2 != a1 ) /*0x177a5f*/
    lock_done(a1); /*0x177a62*/
  return v100; /*0x177a6d*/
}
