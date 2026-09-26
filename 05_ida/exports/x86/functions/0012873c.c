/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12873c. */
void __cdecl tcp_input(int *a1)
{
  _BYTE *v1; // eax
  signed int v2; // ebx
  __int16 v3; // ax
  unsigned int v4; // edi
  int *v5; // eax
  char *v6; // ebx
  __int16 v7; // ax
  int *v8; // eax
  int v9; // eax
  __int16 v10; // cx
  char *v11; // eax
  unsigned __int16 v12; // cx
  int v13; // ebx
  __int16 v14; // di
  int v15; // edi
  int v16; // ebx
  int v17; // esi
  int v18; // edi
  int v19; // edi
  int v20; // ebx
  __int16 v21; // cx
  __int16 v22; // cx
  int *v23; // eax
  int v24; // ebx
  char *v25; // eax
  int v26; // edi
  int v27; // eax
  int v28; // esi
  int v29; // eax
  int v30; // ecx
  int v31; // esi
  int v32; // ebx
  int v33; // ecx
  int v34; // ebx
  int v35; // ecx
  int v36; // ebx
  unsigned int v37; // eax
  unsigned __int16 v38; // cx
  int v39; // ecx
  unsigned int v40; // edx
  unsigned __int16 v41; // cx
  int v42; // ebx
  int v43; // ecx
  int v44; // ecx
  int v45; // edx
  int v46; // eax
  __int16 v47; // cx
  int v48; // ecx
  int v49; // ecx
  int v50; // ebx
  unsigned int v51; // eax
  unsigned int v52; // edi
  unsigned __int16 v53; // cx
  int v54; // edi
  unsigned int v55; // ecx
  unsigned __int16 v56; // cx
  int v57; // ebx
  int v58; // ecx
  __int16 v59; // cx
  int v60; // ebx
  int v61; // ebx
  unsigned __int16 v62; // cx
  int v63; // ecx
  int v64; // ecx
  __int16 v65; // dx
  __int16 v66; // cx
  int v67; // eax
  int v68; // [esp+80h] [ebp-30h]
  int v69; // [esp+84h] [ebp-2Ch]
  unsigned int v70; // [esp+84h] [ebp-2Ch]
  unsigned int v71; // [esp+84h] [ebp-2Ch]
  __int16 v72; // [esp+88h] [ebp-28h]
  int v73; // [esp+8Ch] [ebp-24h]
  int v74; // [esp+90h] [ebp-20h]
  __int16 v75; // [esp+94h] [ebp-1Ch]
  int v76; // [esp+98h] [ebp-18h]
  int v77; // [esp+9Ch] [ebp-14h]
  unsigned int v78; // [esp+A0h] [ebp-10h]
  char v79; // [esp+A0h] [ebp-10h]
  int v80; // [esp+A4h] [ebp-Ch]
  int *v81; // [esp+A8h] [ebp-8h]
  int v82; // [esp+ACh] [ebp-4h]

  v80 = 0; /*0x128748*/
  v68 = 0; /*0x12874f*/
  v76 = 0; /*0x128756*/
  v74 = 0; /*0x12875d*/
  v73 = 0; /*0x128764*/
  ++dword_1EEDD4; /*0x12876b*/
  v1 = (char *)a1 + a1[1]; /*0x128774*/
  v82 = (int)v1; /*0x128777*/
  if ( (*v1 & 0xFu) > 5 ) /*0x128782*/
    ip_stripoptions((unsigned int)v1, 0); /*0x128787*/
  if ( *((_WORD *)a1 + 4) <= 0x27u ) /*0x128797*/
  {
    a1 = m_pullup((int)a1, 40); /*0x1287a1*/
    if ( !a1 ) /*0x1287a9*/
    {
LABEL_14:
      ++dword_1EEDE8; /*0x12886d*/
      return; /*0x128873*/
    }
    v82 = (int)a1 + a1[1]; /*0x1287b5*/
  }
  v2 = *(__int16 *)(v82 + 2); /*0x1287bb*/
  *(_DWORD *)(v82 + 4) = 0; /*0x1287c2*/
  *(_DWORD *)v82 = 0; /*0x1287c9*/
  *(_BYTE *)(v82 + 8) = 0; /*0x1287cf*/
  *(_WORD *)(v82 + 10) = v2; /*0x1287d3*/
  *(_WORD *)(v82 + 10) = __ROR2__(*(_WORD *)(v82 + 10), 8); /*0x1287df*/
  v3 = in_cksum(a1, v2 + 20); /*0x1287e8*/
  *(_WORD *)(v82 + 36) = v3; /*0x1287f6*/
  if ( v3 ) /*0x128802*/
  {
    ++dword_1EEDE0; /*0x128804*/
    goto LABEL_275; /*0x12880a*/
  }
  v4 = 4 * (*(_BYTE *)(v82 + 32) >> 4); /*0x12881c*/
  if ( v4 <= 0x13 || (int)v4 > v2 ) /*0x12882a*/
  {
    ++dword_1EEDE4; /*0x12882c*/
    goto LABEL_275; /*0x128832*/
  }
  *(_WORD *)(v82 + 10) = v2 - v4; /*0x12883e*/
  if ( v4 > 0x14 ) /*0x128845*/
  {
    if ( *((__int16 *)a1 + 4) < v4 + 20 ) /*0x128857*/
    {
      a1 = m_pullup((int)a1, v4 + 20); /*0x128863*/
      if ( !a1 ) /*0x12886b*/
        goto LABEL_14; /*0x12886b*/
      v82 = (int)a1 + a1[1]; /*0x12887e*/
    }
    v5 = m_get(0, 1); /*0x128885*/
    v80 = (int)v5; /*0x12888a*/
    if ( !v5 ) /*0x128892*/
      goto LABEL_277; /*0x128892*/
    *((_WORD *)v5 + 4) = v4 - 20; /*0x1288a0*/
    v6 = (char *)a1 + a1[1] + 40; /*0x1288aa*/
    bcopy(v6, (char *)v5 + v5[1], (__int16)(v4 - 20)); /*0x1288ba*/
    v7 = *((_WORD *)a1 + 4) - *(_WORD *)(v80 + 8); /*0x1288c9*/
    *((_WORD *)a1 + 4) = v7; /*0x1288d0*/
    bcopy(&v6[*(__int16 *)(v80 + 8)], v6, v7 - 40); /*0x1288e6*/
  }
  v78 = *(unsigned __int8 *)(v82 + 33); /*0x1288f5*/
  *(_DWORD *)(v82 + 24) = _byteswap_ulong(*(_DWORD *)(v82 + 24)); /*0x128903*/
  *(_DWORD *)(v82 + 28) = _byteswap_ulong(*(_DWORD *)(v82 + 28)); /*0x12890b*/
  *(_WORD *)(v82 + 34) = __ROR2__(*(_WORD *)(v82 + 34), 8); /*0x128916*/
  *(_WORD *)(v82 + 38) = __ROR2__(*(_WORD *)(v82 + 38), 8); /*0x128925*/
  while ( 1 ) /*0x12892f*/
  {
    v81 = tcp_last_inpcb; /*0x12892f*/
    if ( *((_WORD *)tcp_last_inpcb + 12) != *(_WORD *)(v82 + 22) /*0x128963*/
      || *((_WORD *)tcp_last_inpcb + 8) != *(_WORD *)(v82 + 20)
      || tcp_last_inpcb[3] != *(_DWORD *)(v82 + 12)
      || tcp_last_inpcb[5] != *(_DWORD *)(v82 + 16) )
    {
      v8 = in_pcblookup( /*0x12898a*/
             &tcb,
             *(_DWORD *)(v82 + 12),
             *(_WORD *)(v82 + 20),
             *(_DWORD *)(v82 + 16),
             *(_WORD *)(v82 + 22),
             1);
      v81 = v8; /*0x12898f*/
      if ( v8 ) /*0x128997*/
        tcp_last_inpcb = v8; /*0x128999*/
      ++tcppcbcachemiss; /*0x12899e*/
    }
    if ( !v81 ) /*0x1289a8*/
      goto LABEL_264; /*0x1289a8*/
    v9 = v81[8]; /*0x1289b1*/
    v68 = v9; /*0x1289b4*/
    if ( !v9 ) /*0x1289b9*/
      goto LABEL_264; /*0x1289b9*/
    if ( !*(_WORD *)(v9 + 8) ) /*0x1289c6*/
      goto LABEL_275; /*0x1289c6*/
    v77 = v81[7]; /*0x1289d2*/
    v10 = *(_WORD *)(v77 + 2); /*0x1289d5*/
    if ( (v10 & 3) != 0 ) /*0x1289dc*/
    {
      if ( (v10 & 1) != 0 ) /*0x1289e1*/
      {
        v75 = *(_WORD *)(v9 + 8); /*0x1289e3*/
        qmemcpy(&tcp_saveti, (const void *)v82, 0x28u); /*0x1289f7*/
      }
      if ( (*(_BYTE *)(v77 + 2) & 2) != 0 ) /*0x128a00*/
      {
        v11 = sonewconn(v77); /*0x128a05*/
        v77 = (int)v11; /*0x128a0a*/
        if ( !v11 ) /*0x128a12*/
          goto LABEL_275; /*0x128a12*/
        ++v74; /*0x128a18*/
        v81 = *((int **)v11 + 2); /*0x128a1e*/
        v81[5] = *(_DWORD *)(v82 + 16); /*0x128a27*/
        *((_WORD *)v81 + 12) = *(_WORD *)(v82 + 22); /*0x128a31*/
        v81[14] = (int)ip_srcroute(); /*0x128a3f*/
        v68 = v81[8]; /*0x128a45*/
        *(_WORD *)(v68 + 8) = 1; /*0x128a48*/
      }
    }
    *(_WORD *)(v68 + 88) = 0; /*0x128a51*/
    *(_WORD *)(v68 + 14) = tcp_keepidle; /*0x128a5e*/
    if ( v80 && *(_WORD *)(v68 + 8) != 1 ) /*0x128a6d*/
    {
      tcp_dooptions(v68, v80, v82); /*0x128a7b*/
      v80 = 0; /*0x128a80*/
    }
    if ( *(_WORD *)(v68 + 8) == 4 && (v78 & 0x37) == 0x10 && *(_DWORD *)(v82 + 24) == *(_DWORD *)(v68 + 64) ) /*0x128ab0*/
    {
      v12 = *(_WORD *)(v82 + 34); /*0x128ab6*/
      if ( v12 ) /*0x128abd*/
      {
        if ( *(_WORD *)(v68 + 60) == v12 ) /*0x128ac7*/
        {
          v13 = *(_DWORD *)(v68 + 40); /*0x128acd*/
          if ( *(_DWORD *)(v68 + 80) == v13 ) /*0x128ad3*/
          {
            v14 = *(_WORD *)(v82 + 10); /*0x128ad9*/
            if ( v14 ) /*0x128ae0*/
            {
              if ( *(_DWORD *)(v82 + 28) == *(_DWORD *)(v68 + 36) && *(_DWORD *)v68 == v68 ) /*0x128bea*/
              {
                v16 = v14; /*0x128bf0*/
                v17 = *(unsigned __int16 *)(v77 + 40); /*0x128bfd*/
                v18 = *(unsigned __int16 *)(v77 + 38) - *(unsigned __int16 *)(v77 + 36); /*0x128c15*/
                if ( v18 > *(unsigned __int16 *)(v77 + 42) - v17 ) /*0x128c19*/
                  v18 = *(unsigned __int16 *)(v77 + 42) - v17; /*0x128c1b*/
                if ( v16 <= v18 ) /*0x128c1f*/
                {
                  ++tcppreddat; /*0x128c21*/
                  *(_DWORD *)(v68 + 64) += *(__int16 *)(v82 + 10); /*0x128c31*/
                  ++dword_1EEDD8; /*0x128c34*/
                  dword_1EEDDC += *(__int16 *)(v82 + 10); /*0x128c41*/
                  a1[1] += 40; /*0x128c4a*/
                  *((_WORD *)a1 + 4) -= 40; /*0x128c4e*/
                  sbappend(v77 + 36, (int)a1); /*0x128c5b*/
                  sowakeup(v77, v77 + 36); /*0x128c65*/
                  *(_BYTE *)(v68 + 27) |= 2u; /*0x128c6d*/
                  return; /*0x128c71*/
                }
              }
            }
            else if ( *(_DWORD *)(v82 + 28) - *(_DWORD *)(v68 + 36) > 0 /*0x128b06*/
                   && *(_DWORD *)(v82 + 28) - v13 <= 0
                   && *(_WORD *)(v68 + 84) >= v12 )
            {
              ++tcppredack; /*0x128b0c*/
              if ( *(_WORD *)(v68 + 90) && *(_DWORD *)(v82 + 28) - *(_DWORD *)(v68 + 92) > 0 ) /*0x128b21*/
                tcp_xmit_timer(v68); /*0x128b24*/
              v15 = *(_DWORD *)(v82 + 28) - *(_DWORD *)(v68 + 36); /*0x128b35*/
              ++dword_1EEE1C; /*0x128b38*/
              dword_1EEE20 += v15; /*0x128b3e*/
              sbdrop(v77 + 60, v15); /*0x128b4c*/
              *(_DWORD *)(v68 + 36) = *(_DWORD *)(v82 + 28); /*0x128b57*/
              m_freem((int)a1); /*0x128b5e*/
              if ( *(_DWORD *)(v68 + 36) == *(_DWORD *)(v68 + 80) ) /*0x128b72*/
              {
                *(_WORD *)(v68 + 10) = 0; /*0x128b74*/
              }
              else if ( !*(_WORD *)(v68 + 12) ) /*0x128b7f*/
              {
                *(_WORD *)(v68 + 10) = *(_WORD *)(v68 + 20); /*0x128b8d*/
              }
              if ( (*(_BYTE *)(v77 + 80) & 4) != 0 || *(_DWORD *)(v77 + 76) ) /*0x128b9a*/
                sowakeup(v77, v77 + 60); /*0x128bab*/
              if ( *(_WORD *)(v77 + 60) ) /*0x128bb6*/
                tcp_output(v68); /*0x128bc5*/
              return; /*0x128bca*/
            }
          }
        }
      }
    }
    a1[1] += 40; /*0x128c7b*/
    *((_WORD *)a1 + 4) -= 40; /*0x128c7f*/
    v69 = *(unsigned __int16 *)(v77 + 38) - *(unsigned __int16 *)(v77 + 36); /*0x128ca6*/
    if ( v69 > *(unsigned __int16 *)(v77 + 42) - *(unsigned __int16 *)(v77 + 40) ) /*0x128cab*/
      v69 = *(unsigned __int16 *)(v77 + 42) - *(unsigned __int16 *)(v77 + 40); /*0x128cad*/
    if ( v69 < 0 ) /*0x128cb4*/
      v69 = 0; /*0x128cb6*/
    v19 = *(_DWORD *)(v68 + 76); /*0x128cc0*/
    v20 = *(_DWORD *)(v68 + 64); /*0x128cc3*/
    v21 = v69; /*0x128cca*/
    if ( v69 <= v19 - v20 ) /*0x128cd1*/
      v21 = v19 - v20; /*0x128cd5*/
    *(_WORD *)(v68 + 62) = v21; /*0x128cdb*/
    v22 = *(_WORD *)(v68 + 8); /*0x128cdf*/
    if ( v22 == 1 ) /*0x128ce7*/
    {
      if ( (v78 & 4) != 0 ) /*0x128d06*/
        goto LABEL_275; /*0x128d06*/
      if ( (v78 & 0x10) == 0 ) /*0x128d0f*/
      {
        if ( (v78 & 2) == 0 ) /*0x128d18*/
          goto LABEL_275; /*0x128d18*/
        if ( in_broadcast(*(_DWORD *)(v82 + 16)) ) /*0x128d25*/
          goto LABEL_275; /*0x128d25*/
        v23 = m_get(0, 8); /*0x128d3b*/
        v24 = (int)v23; /*0x128d40*/
        if ( !v23 ) /*0x128d47*/
          goto LABEL_275; /*0x128d47*/
        *((_WORD *)v23 + 4) = 16; /*0x128d4d*/
        v25 = (char *)v23 + v23[1]; /*0x128d53*/
        *(_WORD *)v25 = 2; /*0x128d56*/
        *((_DWORD *)v25 + 1) = *(_DWORD *)(v82 + 12); /*0x128d61*/
        *((_WORD *)v25 + 1) = *(_WORD *)(v82 + 20); /*0x128d6b*/
        v26 = v81[5]; /*0x128d72*/
        if ( !v26 ) /*0x128d77*/
          v81[5] = *(_DWORD *)(v82 + 16); /*0x128d7f*/
        if ( in_pcbconnect((int)v81, v24) ) /*0x128d87*/
        {
          v81[5] = v26; /*0x128d95*/
          m_free(v24); /*0x128d99*/
          goto LABEL_275; /*0x128da1*/
        }
        m_free(v24); /*0x128da9*/
        v27 = tcp_template(v68); /*0x128db2*/
        *(_DWORD *)(v68 + 28) = v27; /*0x128dbc*/
        if ( !v27 ) /*0x128dc4*/
        {
          v68 = tcp_drop(v68, 55); /*0x128dce*/
          v74 = 0; /*0x128dd1*/
          goto LABEL_275; /*0x128ddb*/
        }
        if ( v80 ) /*0x128de4*/
          tcp_dooptions(v68, v80, v82); /*0x128df2*/
        if ( v73 ) /*0x128dfe*/
          *(_DWORD *)(v68 + 56) = v73; /*0x128e06*/
        else
          *(_DWORD *)(v68 + 56) = tcp_iss; /*0x128e15*/
        tcp_iss += 64000; /*0x128e18*/
        *(_DWORD *)(v68 + 72) = *(_DWORD *)(v82 + 24); /*0x128e2b*/
        v28 = *(_DWORD *)(v68 + 56); /*0x128e2e*/
        *(_DWORD *)(v68 + 44) = v28; /*0x128e31*/
        *(_DWORD *)(v68 + 80) = v28; /*0x128e34*/
        *(_DWORD *)(v68 + 40) = v28; /*0x128e37*/
        *(_DWORD *)(v68 + 36) = v28; /*0x128e3a*/
        v29 = *(_DWORD *)(v68 + 72) + 1; /*0x128e40*/
        *(_DWORD *)(v68 + 64) = v29; /*0x128e44*/
        *(_DWORD *)(v68 + 76) = v29; /*0x128e47*/
        *(_BYTE *)(v68 + 27) |= 1u; /*0x128e4a*/
        *(_WORD *)(v68 + 8) = 3; /*0x128e4e*/
        *(_WORD *)(v68 + 14) = 150; /*0x128e54*/
        ++dword_1EED74; /*0x128e5a*/
LABEL_109:
        ++*(_DWORD *)(v82 + 24); /*0x128f71*/
        v32 = *(__int16 *)(v82 + 10); /*0x128f77*/
        v33 = *(unsigned __int16 *)(v68 + 62); /*0x128f7e*/
        if ( v32 > v33 ) /*0x128f84*/
        {
          v34 = v32 - v33; /*0x128f86*/
          m_adj(a1, -v34); /*0x128f91*/
          *(_WORD *)(v82 + 10) = *(_WORD *)(v68 + 62); /*0x128f9d*/
          LOBYTE(v78) = v78 & 0xFE; /*0x128fa1*/
          ++dword_1EEE04; /*0x128fa5*/
          dword_1EEE08 += v34; /*0x128fab*/
        }
        *(_DWORD *)(v68 + 48) = *(_DWORD *)(v82 + 24) - 1; /*0x128fbe*/
        *(_DWORD *)(v68 + 68) = *(_DWORD *)(v82 + 24); /*0x128fc7*/
        goto LABEL_212; /*0x128fca*/
      }
      goto LABEL_264; /*0x128d0f*/
    }
    if ( v22 >= 1 && v22 <= 3 ) /*0x128cf3*/
    {
      if ( (v78 & 0x10) != 0 /*0x128e8e*/
        && (*(_DWORD *)(v82 + 28) - *(_DWORD *)(v68 + 56) <= 0 || *(_DWORD *)(v82 + 28) - *(_DWORD *)(v68 + 80) > 0) )
      {
        goto LABEL_264; /*0x128e8e*/
      }
      if ( (v78 & 4) != 0 ) /*0x128e9d*/
      {
        if ( (v78 & 0x10) != 0 ) /*0x128ea1*/
          v68 = tcp_drop(v68, 61); /*0x128eb2*/
        goto LABEL_275; /*0x128eb8*/
      }
      if ( *(_WORD *)(v68 + 8) != 3 ) /*0x128ec8*/
      {
        if ( (v78 & 2) == 0 ) /*0x128ed7*/
          goto LABEL_275; /*0x128ed7*/
        if ( (v78 & 0x10) != 0 ) /*0x128edf*/
        {
          *(_DWORD *)(v68 + 36) = *(_DWORD *)(v82 + 28); /*0x128ee7*/
          v30 = *(_DWORD *)(v68 + 36); /*0x128eea*/
          if ( *(_DWORD *)(v68 + 40) - v30 < 0 ) /*0x128ef2*/
            *(_DWORD *)(v68 + 40) = v30; /*0x128ef7*/
        }
        *(_WORD *)(v68 + 10) = 0; /*0x128efd*/
        *(_DWORD *)(v68 + 72) = *(_DWORD *)(v82 + 24); /*0x128f09*/
        v31 = *(_DWORD *)(v68 + 72) + 1; /*0x128f0f*/
        *(_DWORD *)(v68 + 64) = v31; /*0x128f10*/
        *(_DWORD *)(v68 + 76) = v31; /*0x128f13*/
        *(_BYTE *)(v68 + 27) |= 1u; /*0x128f16*/
        if ( (v78 & 0x10) != 0 && *(_DWORD *)(v68 + 36) - *(_DWORD *)(v68 + 56) > 0 ) /*0x128f2c*/
        {
          ++dword_1EED78; /*0x128f2e*/
          soisconnected(v77); /*0x128f38*/
          *(_WORD *)(v68 + 8) = 4; /*0x128f40*/
          tcp_reass((int **)v68, 0, nullptr); /*0x128f4b*/
          if ( *(_WORD *)(v68 + 90) ) /*0x128f56*/
            tcp_xmit_timer(v68); /*0x128f5e*/
        }
        else
        {
          *(_WORD *)(v68 + 8) = 3; /*0x128f6b*/
        }
        goto LABEL_109; /*0x128f66*/
      }
    }
    v35 = *(_DWORD *)(v82 + 24); /*0x128fd3*/
    v36 = *(_DWORD *)(v68 + 64) - v35; /*0x128fdc*/
    if ( v36 > 0 ) /*0x128fe0*/
    {
      v37 = v78; /*0x128fe6*/
      if ( (v78 & 2) != 0 ) /*0x128feb*/
      {
        LOBYTE(v37) = v78 & 0xFD; /*0x128fed*/
        v78 = v37; /*0x128fef*/
        *(_DWORD *)(v82 + 24) = v35 + 1; /*0x128ff3*/
        v38 = *(_WORD *)(v82 + 38); /*0x128ff6*/
        if ( v38 <= 1u ) /*0x128ffe*/
          v78 = v37 & 0xFFFFFFDF; /*0x129008*/
        else
          *(_WORD *)(v82 + 38) = v38 - 1; /*0x129002*/
        --v36; /*0x12900c*/
      }
      v39 = *(__int16 *)(v82 + 10); /*0x129010*/
      if ( v36 <= v39 && (v36 != v39 || (v78 & 1) != 0) ) /*0x129023*/
      {
        ++dword_1EEDF4; /*0x129068*/
        dword_1EEDF8 += v36; /*0x12906e*/
      }
      else
      {
        ++dword_1EEDEC; /*0x129025*/
        dword_1EEDF0 += *(__int16 *)(v82 + 10); /*0x129032*/
        v40 = v78; /*0x129038*/
        if ( (v78 & 1) == 0 || v36 != *(__int16 *)(v82 + 10) + 1 ) /*0x129050*/
          goto LABEL_261; /*0x129050*/
        v36 = *(__int16 *)(v82 + 10); /*0x129056*/
        LOBYTE(v40) = v78 & 0xFE; /*0x129058*/
        v78 = v40; /*0x12905b*/
        *(_BYTE *)(v68 + 27) |= 1u; /*0x129061*/
      }
      m_adj(a1, v36); /*0x129079*/
      *(_DWORD *)(v82 + 24) += v36; /*0x129081*/
      *(_WORD *)(v82 + 10) -= v36; /*0x129084*/
      v41 = *(_WORD *)(v82 + 38); /*0x129088*/
      if ( v41 <= v36 ) /*0x129094*/
      {
        v78 &= ~0x20u; /*0x1290a0*/
        *(_WORD *)(v82 + 38) = 0; /*0x1290a7*/
      }
      else
      {
        *(_WORD *)(v82 + 38) = v41 - v36; /*0x129099*/
      }
    }
    if ( (*(_BYTE *)(v77 + 6) & 1) != 0 && *(__int16 *)(v68 + 8) > 5 && *(_WORD *)(v82 + 10) ) /*0x1290c3*/
    {
      v68 = tcp_close(v68); /*0x1290d0*/
      ++dword_1EEE0C; /*0x1290d3*/
      goto LABEL_264; /*0x1290dc*/
    }
    v42 = *(_DWORD *)(v82 + 24) + *(__int16 *)(v82 + 10) - (*(_DWORD *)(v68 + 64) + *(unsigned __int16 *)(v68 + 62)); /*0x129104*/
    if ( v42 <= 0 ) /*0x129108*/
      goto LABEL_143; /*0x129108*/
    ++dword_1EEE04; /*0x12910e*/
    v43 = *(__int16 *)(v82 + 10); /*0x129114*/
    if ( v42 < v43 ) /*0x12911a*/
    {
      dword_1EEE08 += v42; /*0x129188*/
      goto LABEL_142; /*0x129188*/
    }
    dword_1EEE08 += v43; /*0x12911c*/
    if ( (v78 & 2) == 0 ) /*0x129128*/
      break; /*0x129128*/
    if ( *(_WORD *)(v68 + 8) != 10 ) /*0x12912f*/
      break; /*0x12912f*/
    v44 = *(_DWORD *)(v68 + 64); /*0x129131*/
    if ( *(_DWORD *)(v82 + 24) - v44 <= 0 ) /*0x12913e*/
      break; /*0x12913e*/
    v73 = v44 + 128000; /*0x129146*/
    v68 = tcp_close(v68); /*0x12914f*/
  }
  if ( *(_WORD *)(v68 + 62) || *(_DWORD *)(v82 + 24) != *(_DWORD *)(v68 + 64) ) /*0x129173*/
    goto LABEL_261; /*0x129173*/
  *(_BYTE *)(v68 + 27) |= 1u; /*0x129179*/
  ++dword_1EEE10; /*0x12917d*/
LABEL_142:
  m_adj(a1, -v42); /*0x12918e*/
  *(_WORD *)(v82 + 10) -= v42; /*0x12919f*/
  LOBYTE(v78) = v78 & 0xF6; /*0x1291a3*/
LABEL_143:
  if ( (v78 & 4) == 0 ) /*0x1291af*/
  {
LABEL_149:
    if ( (v78 & 2) != 0 ) /*0x129229*/
    {
      v68 = tcp_drop(v68, 54); /*0x129236*/
      goto LABEL_264; /*0x12923c*/
    }
    if ( (v78 & 0x10) == 0 ) /*0x12924d*/
      goto LABEL_275; /*0x12924d*/
    v47 = *(_WORD *)(v68 + 8); /*0x129256*/
    if ( v47 != 3 ) /*0x12925e*/
    {
      if ( v47 < 3 || v47 > 10 ) /*0x12926a*/
        goto LABEL_212; /*0x12926a*/
      goto LABEL_159; /*0x12926a*/
    }
    v48 = *(_DWORD *)(v82 + 28); /*0x129277*/
    if ( *(_DWORD *)(v68 + 36) - v48 <= 0 && v48 - *(_DWORD *)(v68 + 80) <= 0 ) /*0x129295*/
    {
      ++dword_1EED78; /*0x12929b*/
      soisconnected(v77); /*0x1292a5*/
      *(_WORD *)(v68 + 8) = 4; /*0x1292ad*/
      tcp_reass((int **)v68, 0, nullptr); /*0x1292b8*/
      *(_DWORD *)(v68 + 48) = *(_DWORD *)(v82 + 24) - 1; /*0x1292c4*/
LABEL_159:
      if ( *(_DWORD *)(v82 + 28) - *(_DWORD *)(v68 + 36) <= 0 ) /*0x1292d8*/
      {
        if ( !*(_WORD *)(v82 + 10) /*0x129317*/
          && *(_WORD *)(v82 + 34) == *(_WORD *)(v68 + 60)
          && (++dword_1EEE14, *(_WORD *)(v68 + 10))
          && *(_DWORD *)(v82 + 28) == *(_DWORD *)(v68 + 36) )
        {
          v72 = *(_WORD *)(v68 + 22); /*0x129324*/
          *(_WORD *)(v68 + 22) = v72 + 1; /*0x12932d*/
          v49 = (__int16)(v72 + 1); /*0x129337*/
          if ( v49 == tcprexmtthresh ) /*0x129342*/
          {
            v50 = *(_DWORD *)(v68 + 40); /*0x129348*/
            v51 = min(*(unsigned __int16 *)(v68 + 60), *(unsigned __int16 *)(v68 + 84)); /*0x129355*/
            v70 = *(unsigned __int16 *)(v68 + 24); /*0x129365*/
            v52 = (v51 >> 1) / v70; /*0x12936e*/
            if ( v52 <= 1 ) /*0x129376*/
              LOWORD(v52) = 2; /*0x129378*/
            *(_WORD *)(v68 + 86) = v52 * v70; /*0x129388*/
            *(_WORD *)(v68 + 10) = 0; /*0x12938c*/
            *(_WORD *)(v68 + 90) = 0; /*0x129392*/
            *(_DWORD *)(v68 + 40) = *(_DWORD *)(v82 + 28); /*0x12939e*/
            *(_WORD *)(v68 + 84) = *(_WORD *)(v68 + 24); /*0x1293a8*/
            tcp_output(v68); /*0x1293ad*/
            *(_WORD *)(v68 + 84) = *(_WORD *)(v68 + 86) + *(_WORD *)(v68 + 22) * *(_WORD *)(v68 + 24); /*0x1293cb*/
            if ( v50 - *(_DWORD *)(v68 + 40) > 0 ) /*0x1293d9*/
              *(_DWORD *)(v68 + 40) = v50; /*0x1293df*/
            goto LABEL_275; /*0x1293e2*/
          }
          if ( v49 > tcprexmtthresh ) /*0x1293ea*/
          {
            *(_WORD *)(v68 + 84) += *(_WORD *)(v68 + 24); /*0x1293f7*/
            tcp_output(v68); /*0x1293fc*/
            goto LABEL_275; /*0x129404*/
          }
        }
        else
        {
          *(_WORD *)(v68 + 22) = 0; /*0x12940f*/
        }
        goto LABEL_212; /*0x1293ea*/
      }
      if ( tcprexmtthresh < *(__int16 *)(v68 + 22) ) /*0x129429*/
      {
        v53 = *(_WORD *)(v68 + 86); /*0x12942e*/
        if ( *(_WORD *)(v68 + 84) > v53 ) /*0x129436*/
          *(_WORD *)(v68 + 84) = v53; /*0x129438*/
      }
      *(_WORD *)(v68 + 22) = 0; /*0x12943f*/
      if ( *(_DWORD *)(v82 + 28) - *(_DWORD *)(v68 + 80) > 0 ) /*0x129452*/
      {
        ++dword_1EEE18; /*0x129454*/
LABEL_261:
        if ( (v78 & 4) != 0 ) /*0x129962*/
          goto LABEL_275; /*0x129962*/
        m_freem((int)a1); /*0x12996c*/
        v67 = v68; /*0x129971*/
        *(_BYTE *)(v68 + 27) |= 1u; /*0x129974*/
        goto LABEL_263; /*0x129974*/
      }
      v54 = *(_DWORD *)(v82 + 28) - *(_DWORD *)(v68 + 36); /*0x129465*/
      ++dword_1EEE1C; /*0x129468*/
      dword_1EEE20 += v54; /*0x12946e*/
      if ( *(_WORD *)(v68 + 90) && *(_DWORD *)(v82 + 28) - *(_DWORD *)(v68 + 92) > 0 ) /*0x129486*/
        tcp_xmit_timer(v68); /*0x129489*/
      if ( *(_DWORD *)(v82 + 28) == *(_DWORD *)(v68 + 80) ) /*0x12949d*/
      {
        *(_WORD *)(v68 + 10) = 0; /*0x1294a2*/
        v76 = 1; /*0x1294a8*/
      }
      else if ( !*(_WORD *)(v68 + 12) ) /*0x1294b7*/
      {
        *(_WORD *)(v68 + 10) = *(_WORD *)(v68 + 20); /*0x1294c5*/
      }
      v55 = *(unsigned __int16 *)(v68 + 84); /*0x1294cc*/
      v71 = *(unsigned __int16 *)(v68 + 24); /*0x1294d4*/
      if ( v55 > *(unsigned __int16 *)(v68 + 86) ) /*0x1294dd*/
        v71 = (v71 >> 3) + *(unsigned __int16 *)(v68 + 24) * (unsigned int)*(unsigned __int16 *)(v68 + 24) / v55; /*0x1294f4*/
      *(_WORD *)(v68 + 84) = min(v71 + v55, 0xFFFFu); /*0x12950d*/
      v56 = *(_WORD *)(v77 + 60); /*0x129514*/
      if ( v54 <= v56 ) /*0x129520*/
      {
        sbdrop(v77 + 60, v54); /*0x129544*/
        *(_WORD *)(v68 + 60) -= v54; /*0x12954c*/
        v57 = 0; /*0x129550*/
      }
      else
      {
        *(_WORD *)(v68 + 60) -= v56; /*0x129522*/
        sbdrop(v77 + 60, *(unsigned __int16 *)(v77 + 60)); /*0x12952f*/
        v57 = 1; /*0x129534*/
      }
      if ( (*(_BYTE *)(v77 + 80) & 4) != 0 || *(_DWORD *)(v77 + 76) ) /*0x12955e*/
        sowakeup(v77, v77 + 60); /*0x12956f*/
      *(_DWORD *)(v68 + 36) = *(_DWORD *)(v82 + 28); /*0x129580*/
      v58 = *(_DWORD *)(v68 + 36); /*0x129583*/
      if ( *(_DWORD *)(v68 + 40) - v58 < 0 ) /*0x12958b*/
        *(_DWORD *)(v68 + 40) = v58; /*0x12958d*/
      v59 = *(_WORD *)(v68 + 8); /*0x129593*/
      if ( v59 == 7 ) /*0x12959b*/
      {
        if ( v57 ) /*0x1295f2*/
        {
          *(_WORD *)(v68 + 8) = 10; /*0x1295f7*/
          tcp_canceltimers(v68); /*0x1295fe*/
          *(_WORD *)(v68 + 16) = 120; /*0x129603*/
          soisdisconnected(v77); /*0x12960d*/
        }
      }
      else if ( v59 > 7 ) /*0x12959d*/
      {
        if ( v59 == 8 ) /*0x1295b0*/
        {
          if ( v57 ) /*0x12961a*/
          {
            v45 = v68; /*0x12961c*/
            goto LABEL_209; /*0x12961c*/
          }
        }
        else if ( v59 == 10 ) /*0x1295b6*/
        {
          *(_WORD *)(v68 + 16) = 120; /*0x129633*/
          goto LABEL_261; /*0x129639*/
        }
      }
      else if ( v59 == 6 && v57 ) /*0x1295c2*/
      {
        if ( (*(_BYTE *)(v77 + 6) & 0x20) != 0 ) /*0x1295cb*/
        {
          soisdisconnected(v77); /*0x1295ce*/
          *(_WORD *)(v68 + 16) = tcp_maxidle; /*0x1295dc*/
        }
        *(_WORD *)(v68 + 8) = 9; /*0x1295e6*/
      }
LABEL_212:
      if ( (v78 & 0x10) != 0 ) /*0x129645*/
      {
        v60 = *(_DWORD *)(v82 + 24); /*0x129654*/
        if ( *(_DWORD *)(v68 + 48) - v60 < 0 /*0x129683*/
          || *(_DWORD *)(v68 + 48) == v60
          && ((v61 = *(_DWORD *)(v82 + 28), *(_DWORD *)(v68 + 52) - v61 < 0)
           || *(_DWORD *)(v68 + 52) == v61 && *(_WORD *)(v82 + 34) > *(_WORD *)(v68 + 60)) )
        {
          if ( !*(_WORD *)(v82 + 10) /*0x1296a5*/
            && *(_DWORD *)(v68 + 52) == *(_DWORD *)(v82 + 28)
            && *(_WORD *)(v82 + 34) > *(_WORD *)(v68 + 60) )
          {
            ++dword_1EEE24; /*0x1296a7*/
          }
          *(_WORD *)(v68 + 60) = *(_WORD *)(v82 + 34); /*0x1296b7*/
          *(_DWORD *)(v68 + 48) = *(_DWORD *)(v82 + 24); /*0x1296c1*/
          *(_DWORD *)(v68 + 52) = *(_DWORD *)(v82 + 28); /*0x1296cd*/
          v62 = *(_WORD *)(v68 + 60); /*0x1296d0*/
          if ( *(_WORD *)(v68 + 102) < v62 ) /*0x1296d8*/
            *(_WORD *)(v68 + 102) = v62; /*0x1296da*/
          v76 = 1; /*0x1296de*/
        }
      }
      if ( (v78 & 0x20) != 0 && *(_WORD *)(v82 + 38) && *(__int16 *)(v68 + 8) <= 9 ) /*0x12970c*/
      {
        v63 = *(unsigned __int16 *)(v82 + 38); /*0x129712*/
        if ( v63 + *(unsigned __int16 *)(v77 + 36) <= 0xFFFF ) /*0x129727*/
        {
          v64 = *(_DWORD *)(v82 + 24) + v63; /*0x12973b*/
          if ( v64 - *(_DWORD *)(v68 + 68) > 0 ) /*0x129748*/
          {
            *(_DWORD *)(v68 + 68) = v64; /*0x12974a*/
            v65 = *(_WORD *)(v77 + 36) + v64 - *(_WORD *)(v68 + 64) - 1; /*0x12975a*/
            *(_WORD *)(v77 + 88) = v65; /*0x12975c*/
            if ( !v65 ) /*0x129760*/
              *(_BYTE *)(v77 + 6) |= 0x40u; /*0x129762*/
            sohasoutofband(v77); /*0x12976a*/
            *(_BYTE *)(v68 + 104) &= 0xFCu; /*0x129772*/
          }
          if ( *(unsigned __int16 *)(v82 + 38) <= *(__int16 *)(v82 + 10) && (*(_BYTE *)(v77 + 3) & 1) == 0 ) /*0x129792*/
            tcp_pulloutofband(v77, v82, a1); /*0x12979d*/
        }
        else
        {
          *(_WORD *)(v82 + 38) = 0; /*0x129729*/
          LOBYTE(v78) = v78 & 0xDF; /*0x12972f*/
        }
      }
      else if ( *(_DWORD *)(v68 + 64) - *(_DWORD *)(v68 + 68) > 0 ) /*0x1297b5*/
      {
        *(_DWORD *)(v68 + 68) = *(_DWORD *)(v68 + 64); /*0x1297b7*/
      }
      if ( (*(_WORD *)(v82 + 10) || (v78 & 1) != 0) && (v66 = *(_WORD *)(v68 + 8), v66 <= 9) ) /*0x1297da*/
      {
        if ( *(_DWORD *)(v82 + 24) == *(_DWORD *)(v68 + 64) && *(_DWORD *)v68 == v68 && v66 == 4 ) /*0x1297f6*/
        {
          *(_BYTE *)(v68 + 27) |= 2u; /*0x1297f8*/
          *(_DWORD *)(v68 + 64) += *(__int16 *)(v82 + 10); /*0x129800*/
          v79 = *(_BYTE *)(v82 + 33) & 1; /*0x12980c*/
          ++dword_1EEDD8; /*0x12980f*/
          dword_1EEDDC += *(__int16 *)(v82 + 10); /*0x12981c*/
          sbappend(v77 + 36, (int)a1); /*0x12982d*/
          sowakeup(v77, v77 + 36); /*0x129837*/
        }
        else
        {
          v79 = tcp_reass((int **)v68, v82, a1); /*0x129855*/
          *(_BYTE *)(v68 + 27) |= 1u; /*0x12985b*/
        }
      }
      else
      {
        m_freem((int)a1); /*0x129868*/
        v79 = v78 & 0xFE; /*0x12986d*/
      }
      if ( (v79 & 1) != 0 ) /*0x12987a*/
      {
        if ( *(__int16 *)(v68 + 8) <= 9 ) /*0x129888*/
        {
          socantrcvmore(v77); /*0x12988e*/
          *(_BYTE *)(v68 + 27) |= 1u; /*0x129893*/
          ++*(_DWORD *)(v68 + 64); /*0x129897*/
        }
        switch ( *(_WORD *)(v68 + 8) ) /*0x1298b0*/
        {
          case 3: /*0x1298b0*/
          case 4: /*0x1298b0*/
            *(_WORD *)(v68 + 8) = 5; /*0x1298db*/
            break; /*0x1298e1*/
          case 6: /*0x1298b0*/
            *(_WORD *)(v68 + 8) = 7; /*0x1298e7*/
            break; /*0x1298ed*/
          case 9: /*0x1298b0*/
            *(_WORD *)(v68 + 8) = 10; /*0x1298f3*/
            tcp_canceltimers(v68); /*0x1298fa*/
            *(_WORD *)(v68 + 16) = 120; /*0x129902*/
            soisdisconnected(v77); /*0x12990c*/
            break; /*0x129914*/
          case 0xA: /*0x1298b0*/
            *(_WORD *)(v68 + 16) = 120; /*0x12991b*/
            break; /*0x12991b*/
          default:
            break;
        }
      }
      if ( (*(_BYTE *)(v77 + 2) & 1) != 0 ) /*0x129928*/
        tcp_trace(0, v75, (const void *)v68, &tcp_saveti, 0); /*0x12993c*/
      if ( !v76 && (*(_BYTE *)(v68 + 27) & 1) == 0 ) /*0x129951*/
        return; /*0x129951*/
      v67 = v68; /*0x129957*/
LABEL_263:
      tcp_output(v67); /*0x129978*/
      return; /*0x12997e*/
    }
LABEL_264:
    if ( v80 ) /*0x129988*/
    {
      m_free(v80); /*0x12998e*/
      v80 = 0; /*0x129993*/
    }
    if ( (v78 & 4) != 0 || in_broadcast(*(_DWORD *)(v82 + 16)) ) /*0x1299af*/
      goto LABEL_275; /*0x1299bb*/
    if ( (v78 & 0x10) != 0 ) /*0x1299c3*/
    {
      tcp_respond(v68, v82, a1, 0, *(_DWORD *)(v82 + 28), 4); /*0x1299d8*/
    }
    else
    {
      if ( (v78 & 2) != 0 ) /*0x1299e5*/
        ++*(_WORD *)(v82 + 10); /*0x1299ea*/
      tcp_respond(v68, v82, a1, *(_DWORD *)(v82 + 24) + *(__int16 *)(v82 + 10), 0, 20); /*0x129a09*/
    }
    if ( v74 ) /*0x129a15*/
      goto LABEL_281; /*0x129a15*/
    return; /*0x129a15*/
  }
  switch ( *(_WORD *)(v68 + 8) ) /*0x1291c4*/
  {
    case 3: /*0x1291c4*/
      *(_WORD *)(v77 + 86) = 61; /*0x1291ef*/
      break; /*0x1291f5*/
    case 4: /*0x1291c4*/
    case 5: /*0x1291c4*/
    case 6: /*0x1291c4*/
    case 9: /*0x1291c4*/
      *(_WORD *)(v77 + 86) = 54; /*0x1291fb*/
      break; /*0x1291fb*/
    case 7: /*0x1291c4*/
    case 8: /*0x1291c4*/
    case 0xA: /*0x1291c4*/
      v46 = tcp_close(v68); /*0x12921c*/
      goto LABEL_210; /*0x12921c*/
    default:
      goto LABEL_149;
  }
  v45 = v68; /*0x129201*/
  *(_WORD *)(v68 + 8) = 0; /*0x129204*/
  ++dword_1EED7C; /*0x12920a*/
LABEL_209:
  v46 = tcp_close(v45); /*0x12961f*/
LABEL_210:
  v68 = v46; /*0x129625*/
LABEL_275:
  if ( v80 ) /*0x129a24*/
    m_free(v80); /*0x129a2a*/
LABEL_277:
  if ( v68 ) /*0x129a36*/
  {
    if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(v68 + 32) + 28) + 2) & 1) != 0 ) /*0x129a45*/
      tcp_trace(4, v75, (const void *)v68, &tcp_saveti, 0); /*0x129a59*/
  }
  m_freem((int)a1); /*0x129a65*/
  if ( v74 ) /*0x129a71*/
LABEL_281:
    soabort(v77); /*0x129a73*/
}
