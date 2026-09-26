/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a2b40. */
void __cdecl sub_1A2B40(int a1, int a2)
{
  int *v2; // eax
  int v3; // ecx
  unsigned int v4; // ebx
  int v5; // eax
  int v6; // esi
  unsigned __int16 v7; // ax
  int v8; // ecx
  int *v9; // eax
  int v10; // ebx
  unsigned int v11; // eax
  int v12; // edx
  int v13; // ebx
  int v14; // eax
  unsigned __int16 v15; // ax
  int v16; // ecx
  int *v17; // eax
  int v18; // ebx
  unsigned int v19; // eax
  int v20; // ebx
  unsigned __int16 *v21; // edi
  int v22; // esi
  int v23; // edx
  int v24; // eax
  int v25; // ebx
  unsigned __int16 v26; // ax
  int v27; // ecx
  int *v28; // eax
  int v29; // ebx
  unsigned int v30; // eax
  int v31; // ebx
  unsigned __int16 *v32; // edi
  int v33; // esi
  int v34; // edx
  int v35; // eax
  int v36; // ebx
  unsigned __int16 v37; // ax
  int v38; // ecx
  int *v39; // eax
  int v40; // ebx
  unsigned int v41; // eax
  int v42; // ebx
  unsigned __int16 *v43; // edi
  int v44; // esi
  int v45; // edx
  int v46; // eax
  int v47; // ebx
  unsigned __int16 v48; // [esp+12h] [ebp-26h]
  unsigned __int16 v49; // [esp+12h] [ebp-26h]
  unsigned __int16 v50; // [esp+12h] [ebp-26h]
  unsigned int v51; // [esp+14h] [ebp-24h]
  unsigned int v52; // [esp+14h] [ebp-24h]
  unsigned int v53; // [esp+14h] [ebp-24h]
  unsigned __int16 v54[10]; // [esp+18h] [ebp-20h] BYREF
  unsigned int v55; // [esp+2Ch] [ebp-Ch]
  unsigned int v56; // [esp+30h] [ebp-8h]
  unsigned int v57; // [esp+34h] [ebp-4h]

  v2 = *(int **)(*(_DWORD *)(a1 + 40) + 236); /*0x1a2b4f*/
  v3 = 0; /*0x1a2b55*/
  if ( v2 ) /*0x1a2b59*/
    v3 = *v2; /*0x1a2b5b*/
  if ( v3 ) /*0x1a2b5f*/
  {
    v4 = *(_DWORD *)(v3 + 132); /*0x1a2b61*/
    if ( v4 > 7 ) /*0x1a2b6a*/
      v5 = 0; /*0x1a2b7c*/
    else
      v5 = v3 + 132 * v4 + 136; /*0x1a2b73*/
    v6 = v5; /*0x1a2b7e*/
  }
  else
  {
    v6 = 0; /*0x1a2b84*/
  }
  v7 = *(_WORD *)(a2 + 60); /*0x1a2b89*/
  if ( (v7 & 4) != 0 ) /*0x1a2b8f*/
  {
    v8 = v7 >> 3; /*0x1a2b99*/
    v9 = *(int **)(*(_DWORD *)(a1 + 40) + 236); /*0x1a2ba2*/
    v10 = 0; /*0x1a2ba8*/
    if ( v9 ) /*0x1a2bac*/
      v10 = *v9; /*0x1a2bae*/
    if ( *(_DWORD *)(v10 + 60) > (unsigned int)(8 * v8) ) /*0x1a2bba*/
    {
      v11 = *(_DWORD *)(v10 + 56) + 8 * v8; /*0x1a2bc4*/
      *(_DWORD *)(a1 + 116) = &loc_1A2BF0; /*0x1a2bca*/
      v56 = __readfsdword(v11); /*0x1a2bd4*/
      v57 = __readfsdword(v11 + 4); /*0x1a2bdb*/
      *(_DWORD *)(a1 + 116) = 0; /*0x1a2be1*/
      v12 = a2; /*0x1a2c04*/
      v13 = *(_DWORD *)(a2 + 56); /*0x1a2c07*/
      LOBYTE(v12) = HIBYTE(v57); /*0x1a2c15*/
      v14 = ((unsigned __int8)v57 << 16) | HIWORD(v56) | (v12 << 24); /*0x1a2c1f*/
      if ( (v57 & 0x400000) == 0 ) /*0x1a2c25*/
        v13 = (unsigned __int16)*(_DWORD *)(a2 + 56); /*0x1a2c27*/
      *(_DWORD *)(a1 + 116) = &loc_1A2C4C; /*0x1a2c32*/
      v55 = __readfsdword(v13 + v14); /*0x1a2c3c*/
      *(_DWORD *)(a1 + 116) = 0; /*0x1a2c42*/
      if ( (_WORD)v55 == 0xC4C4 ) /*0x1a2c5a*/
      {
        switch ( BYTE2(v55) ) /*0x1a2c65*/
        {
          case 0xFE: /*0x1a2c65*/
            PCcancelTimers(v6); /*0x1a2c68*/
            *(_DWORD *)(v6 + 88) = 4; /*0x1a2c6d*/
LABEL_50:
            PCcallMonitor(a1, (__int16 *)a2); /*0x1a2faf*/
            return; /*0x1a2fb7*/
          case 0xFA: /*0x1a2c65*/
            v15 = *(_WORD *)(a2 + 72); /*0x1a2c87*/
            if ( (v15 & 4) != 0 ) /*0x1a2c8d*/
            {
              v16 = v15 >> 3; /*0x1a2c97*/
              v17 = *(int **)(*(_DWORD *)(a1 + 40) + 236); /*0x1a2ca0*/
              v18 = 0; /*0x1a2ca6*/
              if ( v17 ) /*0x1a2caa*/
                v18 = *v17; /*0x1a2cac*/
              if ( *(_DWORD *)(v18 + 60) > (unsigned int)(8 * v16) ) /*0x1a2cb8*/
              {
                v19 = *(_DWORD *)(v18 + 56) + 8 * v16; /*0x1a2cc4*/
                *(_DWORD *)(a1 + 116) = &loc_1A2CF0; /*0x1a2cca*/
                v48 = __readfsdword(v19) >> 16; /*0x1a2cd4*/
                v51 = __readfsdword(v19 + 4); /*0x1a2cdb*/
                *(_DWORD *)(a1 + 116) = 0; /*0x1a2ce1*/
                v23 = a2; /*0x1a2d04*/
                v20 = *(_DWORD *)(a2 + 68); /*0x1a2d07*/
                v21 = v54; /*0x1a2d0a*/
                v22 = 20; /*0x1a2d0d*/
                LOBYTE(v23) = HIBYTE(v51); /*0x1a2d1d*/
                v24 = 0xFFFF; /*0x1a2d27*/
                if ( (v51 & 0x400000) != 0 ) /*0x1a2d30*/
                  v24 = -1; /*0x1a2d32*/
                *(_DWORD *)(a1 + 116) = &loc_1A2D68; /*0x1a2d3a*/
                do /*0x1a2d57*/
                {
                  v25 = v24 & v20; /*0x1a2d44*/
                  *v21++ = __readfsword(v25 + ((v23 << 24) | ((unsigned __int8)v51 << 16) | v48)); /*0x1a2d4b*/
                  v20 = v25 + 2; /*0x1a2d51*/
                  v22 -= 2; /*0x1a2d54*/
                }
                while ( v22 ); /*0x1a2d57*/
                *(_DWORD *)(a1 + 116) = 0; /*0x1a2d5c*/
                PCbopFA(a1, a2, (int)v54); /*0x1a2d7c*/
              }
            }
            break;
          case 0xFC: /*0x1a2c65*/
            v26 = *(_WORD *)(a2 + 72); /*0x1a2d93*/
            if ( (v26 & 4) != 0 ) /*0x1a2d99*/
            {
              v27 = v26 >> 3; /*0x1a2da3*/
              v28 = *(int **)(*(_DWORD *)(a1 + 40) + 236); /*0x1a2dac*/
              v29 = 0; /*0x1a2db2*/
              if ( v28 ) /*0x1a2db6*/
                v29 = *v28; /*0x1a2db8*/
              if ( *(_DWORD *)(v29 + 60) > (unsigned int)(8 * v27) ) /*0x1a2dc4*/
              {
                v30 = *(_DWORD *)(v29 + 56) + 8 * v27; /*0x1a2dd0*/
                *(_DWORD *)(a1 + 116) = &loc_1A2DFC; /*0x1a2dd6*/
                v49 = __readfsdword(v30) >> 16; /*0x1a2de0*/
                v52 = __readfsdword(v30 + 4); /*0x1a2de7*/
                *(_DWORD *)(a1 + 116) = 0; /*0x1a2ded*/
                v34 = a2; /*0x1a2e10*/
                v31 = *(_DWORD *)(a2 + 68); /*0x1a2e13*/
                v32 = v54; /*0x1a2e16*/
                v33 = 10; /*0x1a2e19*/
                LOBYTE(v34) = HIBYTE(v52); /*0x1a2e29*/
                v35 = 0xFFFF; /*0x1a2e33*/
                if ( (v52 & 0x400000) != 0 ) /*0x1a2e3c*/
                  v35 = -1; /*0x1a2e3e*/
                *(_DWORD *)(a1 + 116) = &loc_1A2E74; /*0x1a2e46*/
                do /*0x1a2e63*/
                {
                  v36 = v35 & v31; /*0x1a2e50*/
                  *v32++ = __readfsword(v36 + ((v34 << 24) | ((unsigned __int8)v52 << 16) | v49)); /*0x1a2e57*/
                  v31 = v36 + 2; /*0x1a2e5d*/
                  v33 -= 2; /*0x1a2e60*/
                }
                while ( v33 ); /*0x1a2e63*/
                *(_DWORD *)(a1 + 116) = 0; /*0x1a2e68*/
                PCbopFC(a1, a2, v54); /*0x1a2e88*/
              }
            }
            break;
          case 0xFD: /*0x1a2c65*/
            v37 = *(_WORD *)(a2 + 72); /*0x1a2e9f*/
            if ( (v37 & 4) != 0 ) /*0x1a2ea5*/
            {
              v38 = v37 >> 3; /*0x1a2eaf*/
              v39 = *(int **)(*(_DWORD *)(a1 + 40) + 236); /*0x1a2eb8*/
              v40 = 0; /*0x1a2ebe*/
              if ( v39 ) /*0x1a2ec2*/
                v40 = *v39; /*0x1a2ec4*/
              if ( *(_DWORD *)(v40 + 60) > (unsigned int)(8 * v38) ) /*0x1a2ed0*/
              {
                v41 = *(_DWORD *)(v40 + 56) + 8 * v38; /*0x1a2edc*/
                *(_DWORD *)(a1 + 116) = &loc_1A2F08; /*0x1a2ee2*/
                v50 = __readfsdword(v41) >> 16; /*0x1a2eec*/
                v53 = __readfsdword(v41 + 4); /*0x1a2ef3*/
                *(_DWORD *)(a1 + 116) = 0; /*0x1a2ef9*/
                v45 = a2; /*0x1a2f18*/
                v42 = *(_DWORD *)(a2 + 68); /*0x1a2f1b*/
                v43 = v54; /*0x1a2f1e*/
                v44 = 20; /*0x1a2f21*/
                LOBYTE(v45) = HIBYTE(v53); /*0x1a2f31*/
                v46 = 0xFFFF; /*0x1a2f3b*/
                if ( (v53 & 0x400000) != 0 ) /*0x1a2f44*/
                  v46 = -1; /*0x1a2f46*/
                *(_DWORD *)(a1 + 116) = &loc_1A2F7C; /*0x1a2f4e*/
                do /*0x1a2f6b*/
                {
                  v47 = v46 & v42; /*0x1a2f58*/
                  *v43++ = __readfsword(v47 + ((v45 << 24) | ((unsigned __int8)v53 << 16) | v50)); /*0x1a2f5f*/
                  v42 = v47 + 2; /*0x1a2f65*/
                  v44 -= 2; /*0x1a2f68*/
                }
                while ( v44 ); /*0x1a2f6b*/
                *(_DWORD *)(a1 + 116) = 0; /*0x1a2f70*/
                PCbopFD(a1, a2, (int)v54); /*0x1a2f98*/
              }
            }
            break;
          default:
            *(_DWORD *)(v6 + 76) = BYTE2(v55); /*0x1a2fa5*/
            *(_DWORD *)(v6 + 88) = 3; /*0x1a2fa8*/
            goto LABEL_50; /*0x1a2fa8*/
        }
      }
    }
  }
}
