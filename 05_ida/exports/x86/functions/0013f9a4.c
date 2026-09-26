/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13f9a4. */
int __cdecl sub_13F9A4(int a1, _DWORD *a2)
{
  volatile __int32 *v2; // edx
  int v3; // eax
  int v4; // eax
  _DWORD *v5; // edx
  _DWORD *v6; // eax
  int v7; // eax
  int v9; // eax
  _DWORD *v10; // edx
  _DWORD *v11; // eax
  int v12; // eax
  int v13; // edx
  int v14; // esi
  int v15; // eax
  _DWORD *v16; // esi
  int v17; // edx
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  int v21; // ecx
  int v22; // edx
  int v23; // esi
  int v24; // eax
  _DWORD *v25; // esi
  int v26; // edx
  int v27; // eax
  int v28; // ecx
  int v29; // eax
  int v30; // ecx
  int v31; // eax
  int v32; // eax
  int v33; // eax
  _DWORD *v34; // edx
  _DWORD *v35; // eax
  int v36; // ecx
  int v37; // eax
  int v38; // eax
  int v39; // edx
  int v40; // esi
  int v41; // eax
  int v42; // edx
  int v43; // eax
  int v44; // ecx
  int v45; // eax
  int v46; // ecx
  int v47; // eax
  _DWORD *v48; // edx
  _DWORD *v49; // eax
  int v50; // ecx
  _DWORD *v51; // eax
  int v52; // eax
  int v53; // edx
  int v54; // ecx
  int v55; // eax
  int v56; // edx
  int v57; // eax
  int v58; // edx
  _DWORD *v59; // [esp+Ch] [ebp-18h]
  _DWORD *v60; // [esp+Ch] [ebp-18h]
  int v61; // [esp+Ch] [ebp-18h]
  int v62; // [esp+Ch] [ebp-18h]
  int v63; // [esp+Ch] [ebp-18h]
  int v64; // [esp+10h] [ebp-14h]
  int v65; // [esp+10h] [ebp-14h]
  int v66; // [esp+10h] [ebp-14h]
  _DWORD *v67; // [esp+10h] [ebp-14h]
  int v68; // [esp+14h] [ebp-10h]
  int v69; // [esp+18h] [ebp-Ch]
  int v70; // [esp+1Ch] [ebp-8h]
  int v71; // [esp+20h] [ebp-4h]

  v71 = a2[15]; /*0x13f9b6*/
  v70 = splbio(); /*0x13f9be*/
  v2 = (volatile __int32 *)(a1 + 36); /*0x13f9c1*/
  do /*0x13f9d6*/
  {
    while ( *v2 ) /*0x13f9c4*/
      ; /*0x13f9c6*/
  }
  while ( _InterlockedExchange(v2, 1) == 1 ); /*0x13f9d6*/
  v3 = *(_DWORD *)(a1 + 16); /*0x13f9db*/
  if ( a1 + 16 != v3 ) /*0x13f9e0*/
  {
    v59 = *(_DWORD **)(a1 + 16); /*0x13fab0*/
    if ( (*(_BYTE *)(a1 + 12) & 8) != 0 ) /*0x13fab7*/
    {
      v59[2] = *(_DWORD *)(*(_DWORD *)v3 + 56); /*0x13fac5*/
      if ( v59[3] < v71 && *(int *)(a1 + 24) > 0 ) /*0x13fade*/
      {
        if ( v59[1] == *v59 ) /*0x13fae9*/
        {
          v59[3] = v71; /*0x13fbc6*/
        }
        else
        {
          v69 = *v59; /*0x13faef*/
          *v59 = *(_DWORD *)(*v59 + 12); /*0x13faf5*/
          v9 = *(_DWORD *)(a1 + 24); /*0x13fafa*/
          if ( v9 ) /*0x13faff*/
          {
            *(_DWORD *)(a1 + 24) = v9 - 1; /*0x13fb09*/
            v11 = (_DWORD *)kalloc(0x18u); /*0x13fb0e*/
            v11[3] = 0; /*0x13fb13*/
            v11[1] = 0; /*0x13fb1a*/
            *v11 = 0; /*0x13fb21*/
            v11[2] = 0; /*0x13fb27*/
            v10 = v11; /*0x13fb2e*/
          }
          else
          {
            v10 = nullptr; /*0x13fb01*/
          }
          v10[1] = v69; /*0x13fb36*/
          *v10 = v69; /*0x13fb39*/
          *(_DWORD *)(v69 + 12) = 0; /*0x13fb3b*/
          v12 = *(_DWORD *)(a1 + 16); /*0x13fb4a*/
          if ( a1 + 16 == v12 ) /*0x13fb50*/
            *(_DWORD *)(a1 + 20) = v10; /*0x13fb52*/
          else
            *(_DWORD *)(v12 + 20) = v10; /*0x13fb58*/
          v10[4] = v12; /*0x13fb5b*/
          v10[5] = a1 + 16; /*0x13fb61*/
          *(_DWORD *)(a1 + 16) = v10; /*0x13fb64*/
          v10[3] = v71; /*0x13fbac*/
          v10[2] = *(_DWORD *)(v69 + 56); /*0x13fbb5*/
          v59 = v10; /*0x13fbb8*/
        }
      }
    }
    for ( ; v59 != (_DWORD *)(a1 + 16); v59 = (_DWORD *)v59[4] ) /*0x13fbcf*/
    {
      if ( v59[3] <= v71 ) /*0x13fbdd*/
        break; /*0x13fbdd*/
    }
    if ( v59 == (_DWORD *)(a1 + 16) ) /*0x13fbef*/
    {
      if ( !*(_DWORD *)(a1 + 24) ) /*0x13fbf5*/
      {
        v60 = *(_DWORD **)(a1 + 20); /*0x13fc02*/
        v13 = a2[14]; /*0x13fc08*/
        v14 = v60[2]; /*0x13fc0b*/
        if ( v13 > v14 ) /*0x13fc13*/
        {
          v15 = *(_DWORD *)(*v60 + 56); /*0x13fc1a*/
          if ( v13 < v15 || v15 < v14 ) /*0x13fc23*/
          {
            v16 = a2; /*0x13fc25*/
            a2[3] = *v60; /*0x13fc28*/
LABEL_51:
            *v60 = v16; /*0x13fcbc*/
LABEL_162:
            _InterlockedExchange((volatile __int32 *)(a1 + 36), 0); /*0x14014e*/
            return splx(v70); /*0x140157*/
          }
        }
        v64 = a2[14]; /*0x13fc36*/
        v17 = *v60; /*0x13fc3c*/
        v18 = *(_DWORD *)(*v60 + 56); /*0x13fc3e*/
        if ( v18 >= v64 ) /*0x13fc43*/
        {
          if ( v60[2] > v18 ) /*0x13fc6e*/
          {
            if ( v64 < v18 ) /*0x13fc93*/
            {
LABEL_50:
              v16 = a2; /*0x13fcb1*/
              a2[3] = *v60; /*0x13fcb9*/
              goto LABEL_51; /*0x13fcb9*/
            }
          }
          else
          {
            if ( !*(_DWORD *)(v17 + 12) ) /*0x13fc74*/
              goto LABEL_49; /*0x13fc74*/
            do /*0x13fc85*/
            {
              v21 = *(_DWORD *)(v17 + 12); /*0x13fc78*/
              if ( *(_DWORD *)(v17 + 56) > *(_DWORD *)(v21 + 56) ) /*0x13fc81*/
                break; /*0x13fc81*/
              v17 = *(_DWORD *)(v17 + 12); /*0x13fc83*/
            }
            while ( *(_DWORD *)(v21 + 12) ); /*0x13fc85*/
          }
          while ( *(_DWORD *)(v17 + 12) && *(_DWORD *)(*(_DWORD *)(v17 + 12) + 56) <= v64 ) /*0x13fca1*/
            v17 = *(_DWORD *)(v17 + 12); /*0x13fca3*/
        }
        else if ( *(_DWORD *)(v17 + 12) ) /*0x13fc45*/
        {
          do /*0x13fc5e*/
          {
            v19 = *(_DWORD *)(v17 + 12); /*0x13fc4c*/
            v20 = *(_DWORD *)(v19 + 56); /*0x13fc4f*/
            if ( *(_DWORD *)(v17 + 56) > v20 ) /*0x13fc55*/
              break; /*0x13fc55*/
            if ( v64 < v20 ) /*0x13fc5a*/
              break; /*0x13fc5a*/
            v17 = *(_DWORD *)(v17 + 12); /*0x13fc5c*/
          }
          while ( *(_DWORD *)(v19 + 12) ); /*0x13fc5e*/
        }
LABEL_49:
        if ( v17 ) /*0x13fcaf*/
        {
          a2[3] = *(_DWORD *)(v17 + 12); /*0x13fcca*/
          *(_DWORD *)(v17 + 12) = a2; /*0x13fccd*/
          if ( v60[1] == v17 ) /*0x13fcd6*/
            v60[1] = a2; /*0x13fcdb*/
          goto LABEL_162; /*0x13fcdb*/
        }
        goto LABEL_50; /*0x13fcaf*/
      }
      goto LABEL_78; /*0x13fbf9*/
    }
    if ( *(_DWORD *)(a1 + 24) ) /*0x13fcec*/
    {
LABEL_78:
      if ( v59 == (_DWORD *)(a1 + 16) ) /*0x13fdba*/
        v59 = *(_DWORD **)(a1 + 20); /*0x13fdbf*/
      v32 = v59[3]; /*0x13fdc5*/
      if ( v71 > v32 ) /*0x13fdcb*/
      {
        v61 = v59[5]; /*0x13fdd4*/
        v33 = *(_DWORD *)(a1 + 24); /*0x13fdd7*/
        if ( v33 ) /*0x13fddc*/
        {
          *(_DWORD *)(a1 + 24) = v33 - 1; /*0x13fde5*/
          v35 = (_DWORD *)kalloc(0x18u); /*0x13fdea*/
          v35[3] = 0; /*0x13fdef*/
          v35[1] = 0; /*0x13fdf6*/
          *v35 = 0; /*0x13fdfd*/
          v35[2] = 0; /*0x13fe03*/
          v34 = v35; /*0x13fe0a*/
        }
        else
        {
          v34 = nullptr; /*0x13fdde*/
        }
        v34[1] = a2; /*0x13fe12*/
        *v34 = a2; /*0x13fe15*/
        a2[3] = 0; /*0x13fe17*/
        v36 = a1 + 16; /*0x13fe1e*/
        if ( v61 == a1 + 16 ) /*0x13fe24*/
        {
          v37 = *(_DWORD *)(a1 + 16); /*0x13fe26*/
          if ( v61 == v37 ) /*0x13fe2c*/
            *(_DWORD *)(a1 + 20) = v34; /*0x13fe2e*/
          else
            *(_DWORD *)(v37 + 20) = v34; /*0x13fe34*/
          v34[4] = v37; /*0x13fe37*/
          v34[5] = a1 + 16; /*0x13fe3d*/
          *(_DWORD *)(a1 + 16) = v34; /*0x13fe40*/
        }
        else if ( *(_DWORD *)(v61 + 16) == v36 ) /*0x13fe4e*/
        {
          v38 = *(_DWORD *)(a1 + 20); /*0x13fe50*/
          if ( v36 == v38 ) /*0x13fe55*/
            *(_DWORD *)(a1 + 16) = v34; /*0x13fe57*/
          else
            *(_DWORD *)(v38 + 16) = v34; /*0x13fe5c*/
          v34[5] = v38; /*0x13fe5f*/
          v34[4] = a1 + 16; /*0x13fe65*/
          *(_DWORD *)(a1 + 20) = v34; /*0x13fe68*/
        }
        else
        {
          v34[5] = v61; /*0x13fe73*/
          v34[4] = *(_DWORD *)(v61 + 16); /*0x13fe79*/
          *(_DWORD *)(v61 + 16) = v34; /*0x13fe7c*/
          *(_DWORD *)(v34[4] + 20) = v34; /*0x13fe82*/
        }
        v34[3] = v71; /*0x13fe88*/
        v62 = v34[5]; /*0x13fe8e*/
        if ( a1 + 16 == v62 ) /*0x13fe96*/
          v34[2] = *(_DWORD *)(a1 + 28); /*0x13fe9b*/
        else
          v34[2] = *(_DWORD *)(*(_DWORD *)(v62 + 4) + 56); /*0x13fea9*/
        v59 = v34; /*0x13feac*/
        goto LABEL_140; /*0x13feaf*/
      }
      if ( v71 != v32 ) /*0x13feb7*/
      {
        v47 = *(_DWORD *)(a1 + 24); /*0x13ffa8*/
        if ( v47 ) /*0x13ffad*/
        {
          *(_DWORD *)(a1 + 24) = v47 - 1; /*0x13ffb5*/
          v49 = (_DWORD *)kalloc(0x18u); /*0x13ffba*/
          v49[3] = 0; /*0x13ffbf*/
          v49[1] = 0; /*0x13ffc6*/
          *v49 = 0; /*0x13ffcd*/
          v49[2] = 0; /*0x13ffd3*/
          v48 = v49; /*0x13ffda*/
        }
        else
        {
          v48 = nullptr; /*0x13ffaf*/
        }
        v48[1] = a2; /*0x13ffe2*/
        *v48 = a2; /*0x13ffe5*/
        a2[3] = 0; /*0x13ffe7*/
        v50 = a1 + 16; /*0x13ffee*/
        if ( v59 == (_DWORD *)(a1 + 16) ) /*0x13fff4*/
        {
          v51 = *(_DWORD **)(a1 + 16); /*0x13fff6*/
          if ( v59 == v51 ) /*0x13fffc*/
            *(_DWORD *)(a1 + 20) = v48; /*0x13fffe*/
          else
            v51[5] = v48; /*0x140004*/
          v48[4] = v51; /*0x140007*/
          v48[5] = a1 + 16; /*0x14000d*/
          *(_DWORD *)(a1 + 16) = v48; /*0x140010*/
        }
        else if ( v59[4] == v50 ) /*0x14001e*/
        {
          v52 = *(_DWORD *)(a1 + 20); /*0x140020*/
          if ( v50 == v52 ) /*0x140025*/
            *(_DWORD *)(a1 + 16) = v48; /*0x140027*/
          else
            *(_DWORD *)(v52 + 16) = v48; /*0x14002c*/
          v48[5] = v52; /*0x14002f*/
          v48[4] = a1 + 16; /*0x140035*/
          *(_DWORD *)(a1 + 20) = v48; /*0x140038*/
        }
        else
        {
          v48[5] = v59; /*0x140043*/
          v48[4] = v59[4]; /*0x140049*/
          v59[4] = v48; /*0x14004c*/
          *(_DWORD *)(v48[4] + 20) = v48; /*0x140052*/
        }
        v48[3] = v71; /*0x140058*/
        v48[2] = *(_DWORD *)(v59[1] + 56); /*0x140064*/
        goto LABEL_140; /*0x140064*/
      }
      v39 = a2[14]; /*0x13fec0*/
      v40 = v59[2]; /*0x13fec6*/
      if ( v39 > v40 ) /*0x13fece*/
      {
        v41 = *(_DWORD *)(*v59 + 56); /*0x13fed5*/
        if ( v39 < v41 || v41 < v40 ) /*0x13fede*/
        {
          v25 = a2; /*0x13fee0*/
          a2[3] = *v59; /*0x13fee3*/
          goto LABEL_122; /*0x13fee6*/
        }
      }
      v66 = a2[14]; /*0x13fef2*/
      v42 = *v59; /*0x13fef8*/
      v43 = *(_DWORD *)(*v59 + 56); /*0x13fefa*/
      if ( v43 < v66 ) /*0x13feff*/
      {
        if ( *(_DWORD *)(v42 + 12) ) /*0x13ff01*/
        {
          do /*0x13ff1a*/
          {
            v44 = *(_DWORD *)(v42 + 12); /*0x13ff08*/
            v45 = *(_DWORD *)(v44 + 56); /*0x13ff0b*/
            if ( *(_DWORD *)(v42 + 56) > v45 ) /*0x13ff11*/
              break; /*0x13ff11*/
            if ( v66 < v45 ) /*0x13ff16*/
              break; /*0x13ff16*/
            v42 = *(_DWORD *)(v42 + 12); /*0x13ff18*/
          }
          while ( *(_DWORD *)(v44 + 12) ); /*0x13ff1a*/
        }
LABEL_120:
        v31 = v42; /*0x13ff67*/
        if ( !v42 ) /*0x13ff6b*/
          goto LABEL_121; /*0x13ff6b*/
        goto LABEL_123; /*0x13ff6b*/
      }
      if ( v59[2] <= v43 ) /*0x13ff2a*/
      {
        if ( !*(_DWORD *)(v42 + 12) ) /*0x13ff30*/
          goto LABEL_120; /*0x13ff30*/
        do /*0x13ff41*/
        {
          v46 = *(_DWORD *)(v42 + 12); /*0x13ff34*/
          if ( *(_DWORD *)(v42 + 56) > *(_DWORD *)(v46 + 56) ) /*0x13ff3d*/
            break; /*0x13ff3d*/
          v42 = *(_DWORD *)(v42 + 12); /*0x13ff3f*/
        }
        while ( *(_DWORD *)(v46 + 12) ); /*0x13ff41*/
        goto LABEL_119; /*0x13ff45*/
      }
      if ( v66 >= v43 ) /*0x13ff4f*/
      {
LABEL_119:
        while ( *(_DWORD *)(v42 + 12) && *(_DWORD *)(*(_DWORD *)(v42 + 12) + 56) <= v66 ) /*0x13ff5d*/
          v42 = *(_DWORD *)(v42 + 12); /*0x13ff5f*/
        goto LABEL_120; /*0x13ff5d*/
      }
LABEL_121:
      v25 = a2; /*0x13ff6d*/
      a2[3] = *v59; /*0x13ff75*/
      goto LABEL_122; /*0x13ff75*/
    }
    v22 = a2[14]; /*0x13fcf9*/
    v23 = v59[2]; /*0x13fcff*/
    if ( v22 > v23 ) /*0x13fd07*/
    {
      v24 = *(_DWORD *)(*v59 + 56); /*0x13fd0e*/
      if ( v22 < v24 || v24 < v23 ) /*0x13fd17*/
      {
        v25 = a2; /*0x13fd19*/
        a2[3] = *v59; /*0x13fd1c*/
LABEL_122:
        *v59 = v25; /*0x13ff78*/
        goto LABEL_140; /*0x13ff7d*/
      }
    }
    v65 = a2[14]; /*0x13fd2a*/
    v26 = *v59; /*0x13fd30*/
    v27 = *(_DWORD *)(*v59 + 56); /*0x13fd32*/
    if ( v27 >= v65 ) /*0x13fd37*/
    {
      if ( v59[2] > v27 ) /*0x13fd62*/
      {
        if ( v65 < v27 ) /*0x13fd87*/
          goto LABEL_121; /*0x13fd87*/
      }
      else
      {
        if ( !*(_DWORD *)(v26 + 12) ) /*0x13fd68*/
          goto LABEL_76; /*0x13fd68*/
        do /*0x13fd79*/
        {
          v30 = *(_DWORD *)(v26 + 12); /*0x13fd6c*/
          if ( *(_DWORD *)(v26 + 56) > *(_DWORD *)(v30 + 56) ) /*0x13fd75*/
            break; /*0x13fd75*/
          v26 = *(_DWORD *)(v26 + 12); /*0x13fd77*/
        }
        while ( *(_DWORD *)(v30 + 12) ); /*0x13fd79*/
      }
      while ( *(_DWORD *)(v26 + 12) && *(_DWORD *)(*(_DWORD *)(v26 + 12) + 56) <= v65 ) /*0x13fd99*/
        v26 = *(_DWORD *)(v26 + 12); /*0x13fd9b*/
    }
    else if ( *(_DWORD *)(v26 + 12) ) /*0x13fd39*/
    {
      do /*0x13fd52*/
      {
        v28 = *(_DWORD *)(v26 + 12); /*0x13fd40*/
        v29 = *(_DWORD *)(v28 + 56); /*0x13fd43*/
        if ( *(_DWORD *)(v26 + 56) > v29 ) /*0x13fd49*/
          break; /*0x13fd49*/
        if ( v65 < v29 ) /*0x13fd4e*/
          break; /*0x13fd4e*/
        v26 = *(_DWORD *)(v26 + 12); /*0x13fd50*/
      }
      while ( *(_DWORD *)(v28 + 12) ); /*0x13fd52*/
    }
LABEL_76:
    v31 = v26; /*0x13fda3*/
    if ( v26 ) /*0x13fda7*/
    {
LABEL_123:
      a2[3] = *(_DWORD *)(v31 + 12); /*0x13ff84*/
      *(_DWORD *)(v31 + 12) = a2; /*0x13ff8d*/
      if ( v59[1] == v31 ) /*0x13ff96*/
        v59[1] = a2; /*0x13ff9f*/
LABEL_140:
      if ( v59 == (_DWORD *)(a1 + 16) ) /*0x14006d*/
        goto LABEL_162; /*0x14006d*/
      v67 = (_DWORD *)v59[4]; /*0x140079*/
      if ( (_DWORD *)(a1 + 16) == v67 ) /*0x14007e*/
        goto LABEL_162; /*0x14007e*/
      while ( 1 ) /*0x14008d*/
      {
        v68 = *(_DWORD *)(v59[1] + 56); /*0x14008d*/
        v53 = *v67; /*0x140093*/
        v63 = v68 - 1; /*0x140098*/
        v54 = *v67; /*0x14009b*/
        v55 = *(_DWORD *)(*v67 + 56); /*0x14009d*/
        if ( v55 < v68 - 1 ) /*0x1400a2*/
          break; /*0x1400a2*/
        if ( v67[2] <= v55 ) /*0x1400ce*/
        {
          if ( *(_DWORD *)(v53 + 12) ) /*0x1400d0*/
          {
            do /*0x1400e5*/
            {
              v58 = *(_DWORD *)(v54 + 12); /*0x1400d8*/
              if ( *(_DWORD *)(v54 + 56) > *(_DWORD *)(v58 + 56) ) /*0x1400e1*/
                break; /*0x1400e1*/
              v54 = *(_DWORD *)(v54 + 12); /*0x1400e3*/
            }
            while ( *(_DWORD *)(v58 + 12) ); /*0x1400e5*/
LABEL_157:
            while ( *(_DWORD *)(v54 + 12) && *(_DWORD *)(*(_DWORD *)(v54 + 12) + 56) <= v63 ) /*0x140101*/
              v54 = *(_DWORD *)(v54 + 12); /*0x140103*/
          }
LABEL_158:
          if ( v54 && *(_DWORD *)(v54 + 12) ) /*0x140111*/
          {
            *(_DWORD *)(v67[1] + 12) = *v67; /*0x14011f*/
            v67[1] = v54; /*0x140122*/
            *v67 = *(_DWORD *)(v54 + 12); /*0x140128*/
            *(_DWORD *)(v54 + 12) = 0; /*0x14012a*/
          }
          goto LABEL_161; /*0x14012a*/
        }
        if ( v63 >= v55 ) /*0x1400f3*/
          goto LABEL_157; /*0x1400f3*/
LABEL_161:
        v67[2] = v68; /*0x140131*/
        v59 = v67; /*0x14013a*/
        v67 = (_DWORD *)v67[4]; /*0x140140*/
        if ( (_DWORD *)(a1 + 16) == v67 ) /*0x140148*/
          goto LABEL_162; /*0x140148*/
      }
      if ( *(_DWORD *)(v53 + 12) ) /*0x1400a4*/
      {
        do /*0x1400be*/
        {
          v56 = *(_DWORD *)(v54 + 12); /*0x1400ac*/
          v57 = *(_DWORD *)(v56 + 56); /*0x1400af*/
          if ( *(_DWORD *)(v54 + 56) > v57 ) /*0x1400b5*/
            break; /*0x1400b5*/
          if ( v63 < v57 ) /*0x1400ba*/
            break; /*0x1400ba*/
          v54 = *(_DWORD *)(v54 + 12); /*0x1400bc*/
        }
        while ( *(_DWORD *)(v56 + 12) ); /*0x1400be*/
      }
      goto LABEL_158; /*0x1400c2*/
    }
    goto LABEL_121; /*0x13fda7*/
  }
  v4 = *(_DWORD *)(a1 + 24); /*0x13f9e9*/
  if ( v4 ) /*0x13f9ee*/
  {
    *(_DWORD *)(a1 + 24) = v4 - 1; /*0x13f9f5*/
    v6 = (_DWORD *)kalloc(0x18u); /*0x13f9fa*/
    v6[3] = 0; /*0x13f9ff*/
    v6[1] = 0; /*0x13fa06*/
    *v6 = 0; /*0x13fa0d*/
    v6[2] = 0; /*0x13fa13*/
    v5 = v6; /*0x13fa1a*/
  }
  else
  {
    v5 = nullptr; /*0x13f9f0*/
  }
  v5[1] = a2; /*0x13fa22*/
  *v5 = a2; /*0x13fa25*/
  a2[3] = 0; /*0x13fa27*/
  v7 = *(_DWORD *)(a1 + 16); /*0x13fa36*/
  if ( a1 + 16 == v7 ) /*0x13fa3c*/
    *(_DWORD *)(a1 + 20) = v5; /*0x13fa3e*/
  else
    *(_DWORD *)(v7 + 20) = v5; /*0x13fa44*/
  v5[4] = v7; /*0x13fa47*/
  v5[5] = a1 + 16; /*0x13fa4d*/
  *(_DWORD *)(a1 + 16) = v5; /*0x13fa50*/
  v5[3] = v71; /*0x13fa98*/
  v5[2] = *(_DWORD *)(a1 + 28); /*0x13fa9e*/
  _InterlockedExchange((volatile __int32 *)(a1 + 36), 0); /*0x13faa3*/
  return splx(v70); /*0x14015f*/
}
