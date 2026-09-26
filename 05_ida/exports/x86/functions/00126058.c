/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x126058. */
int ipintr()
{
  int *v0; // ebx
  int v1; // eax
  int v2; // esi
  int result; // eax
  int v4; // esi
  int *v5; // eax
  __int16 v6; // ax
  __int16 v7; // ax
  int v8; // edx
  int i; // edx
  __int16 v10; // cx
  int *v11; // ebx
  char *v12; // edx
  _DWORD *v13; // edx
  unsigned int v14; // ecx
  unsigned __int32 v15; // eax
  unsigned int v16; // edx
  int v17; // eax
  _DWORD *v18; // eax
  _DWORD *v19; // eax
  int v20; // edx
  __int16 v21; // ax
  int *v22; // eax
  int v23; // [esp+Ch] [ebp-10h]
  int v24; // [esp+Ch] [ebp-10h]
  int v25; // [esp+10h] [ebp-Ch]
  int v26; // [esp+14h] [ebp-8h]
  int *v27; // [esp+18h] [ebp-4h] BYREF

  v26 = 0; /*0x126061*/
  while ( 1 ) /*0x12606d*/
  {
    v25 = splimp(); /*0x12606d*/
    v0 = (int *)ipintrq; /*0x126070*/
    if ( ipintrq ) /*0x126078*/
    {
      ipintrq = *(_DWORD *)(ipintrq + 124); /*0x126081*/
      if ( !ipintrq ) /*0x126088*/
        dword_1EAA74 = 0; /*0x12608a*/
      v0[31] = 0; /*0x126094*/
      --dword_1EAA78; /*0x12609b*/
      v1 = v0[1]; /*0x1260a1*/
      v26 = *(int *)((char *)v0 + v1); /*0x1260a7*/
      v0[1] = v1 + 4; /*0x1260ad*/
      LOWORD(v1) = *((_WORD *)v0 + 4); /*0x1260b0*/
      *((_WORD *)v0 + 4) = v1 - 4; /*0x1260b8*/
      if ( (_WORD)v1 == 4 ) /*0x1260bc*/
      {
        v23 = splimp(); /*0x1260c7*/
        if ( !*((_WORD *)v0 + 5) ) /*0x1260ca*/
          panic(aMfree_8); /*0x1260d6*/
        --word_1E917C[*((__int16 *)v0 + 5)]; /*0x1260e2*/
        ++word_1E917C[0]; /*0x1260ea*/
        *((_WORD *)v0 + 5) = 0; /*0x1260f1*/
        if ( (unsigned int)v0[1] > 0x7F ) /*0x1260fb*/
          mclput((int)v0); /*0x1260fe*/
        v2 = *v0; /*0x126106*/
        *v0 = mfree; /*0x12610e*/
        v0[1] = 0; /*0x126110*/
        v0[31] = 0; /*0x126117*/
        mfree = (int)v0; /*0x12611e*/
        splx(v23); /*0x126128*/
        if ( m_want ) /*0x126137*/
        {
          m_want = 0; /*0x126139*/
          wakeup((int)&mfree); /*0x126148*/
        }
        v0 = (int *)v2; /*0x126150*/
      }
    }
    result = splx(v25); /*0x126156*/
    if ( !v0 ) /*0x126160*/
      return result; /*0x12652b*/
    if ( !in_ifaddr ) /*0x12616d*/
      goto LABEL_91; /*0x12616d*/
    ++ipstat; /*0x126173*/
    if ( (unsigned int)v0[1] <= 0x7C && *((_WORD *)v0 + 4) > 0x13u || (v0 = m_pullup((int)v0, 20)) != nullptr ) /*0x126195*/
    {
      v4 = (int)v0 + v0[1]; /*0x1261a6*/
      v24 = 4 * (*(_BYTE *)v4 & 0xF); /*0x1261b1*/
      if ( (unsigned int)v24 <= 0x13 ) /*0x1261b7*/
      {
        ++dword_1EAAC0; /*0x1261b9*/
        goto LABEL_91; /*0x1261bf*/
      }
      if ( v24 <= *((__int16 *)v0 + 4) ) /*0x1261cb*/
      {
LABEL_25:
        if ( ipcksum ) /*0x1261f8*/
        {
          v6 = in_cksum(v0, v24); /*0x1261ff*/
          *(_WORD *)(v4 + 10) = v6; /*0x126204*/
          if ( v6 ) /*0x12620e*/
          {
            ++dword_1EAAB4; /*0x126210*/
            goto LABEL_91; /*0x126216*/
          }
        }
        v7 = __ROR2__(*(_WORD *)(v4 + 2), 8); /*0x126220*/
        *(_WORD *)(v4 + 2) = v7; /*0x126224*/
        if ( v24 > v7 ) /*0x12622c*/
        {
          ++dword_1EAAC4; /*0x12622e*/
          goto LABEL_91; /*0x126234*/
        }
        *(_WORD *)(v4 + 4) = __ROR2__(*(_WORD *)(v4 + 4), 8); /*0x126244*/
        *(_WORD *)(v4 + 6) = __ROR2__(*(_WORD *)(v4 + 6), 8); /*0x126250*/
        v8 = *(unsigned __int16 *)(v4 + 2); /*0x126254*/
        v27 = v0; /*0x126258*/
        for ( i = *((__int16 *)v0 + 4) - v8; *v0; i += *((__int16 *)v0 + 4) ) /*0x126263*/
          v0 = (int *)*v0; /*0x126268*/
        if ( !i ) /*0x126277*/
          goto LABEL_38; /*0x126277*/
        if ( i >= 0 ) /*0x126279*/
        {
          v10 = *((_WORD *)v0 + 4); /*0x12628c*/
          if ( i > v10 ) /*0x126295*/
            m_adj(v27, -i); /*0x1262a9*/
          else
            *((_WORD *)v0 + 4) = v10 - i; /*0x12629a*/
LABEL_38:
          v11 = v27; /*0x1262b1*/
          ip_nhops = 0; /*0x1262b4*/
          if ( (unsigned int)v24 <= 0x14 || !ip_dooptions((void *)v4, v26) ) /*0x1262c9*/
          {
            if ( (*(_BYTE *)(v26 + 13) & 0x40) != 0 /*0x1262fe*/
              && ((unsigned int)v11[1] <= 0x7C && *((_WORD *)v11 + 4) > 0x1Bu
               || (v11 = m_pullup((int)v11, 28)) != nullptr) )
            {
              v12 = (char *)v11 + v11[1]; /*0x126302*/
              if ( v12[9] == 17 && *((_WORD *)v12 + 11) == __ROR2__(68, 8) ) /*0x126318*/
                goto LABEL_72; /*0x126318*/
            }
            v13 = (_DWORD *)in_ifaddr; /*0x12631e*/
            if ( in_ifaddr ) /*0x126326*/
            {
              v14 = *(_DWORD *)(v4 + 16); /*0x126328*/
              while ( v13[1] != v14 ) /*0x12632c*/
              {
                if ( (*(_BYTE *)(v13[8] + 12) & 2) != 0 ) /*0x12633c*/
                {
                  if ( v13[5] == v14 ) /*0x126341*/
                    break; /*0x126341*/
                  if ( v13[14] == v14 ) /*0x12634a*/
                    break; /*0x12634a*/
                  v15 = _byteswap_ulong(v14); /*0x126352*/
                  if ( v13[12] == v15 || v13[10] == v15 ) /*0x126360*/
                    break; /*0x126360*/
                }
                v13 = (_DWORD *)v13[16]; /*0x126366*/
                if ( !v13 ) /*0x12636b*/
                  goto LABEL_55; /*0x12636b*/
              }
              goto LABEL_72; /*0x126360*/
            }
LABEL_55:
            v16 = *(_DWORD *)(v4 + 16); /*0x12636d*/
            if ( (_byteswap_ulong(v16) & 0xF0000000) == 0xE0000000 ) /*0x12637e*/
            {
              if ( ip_mrouter ) /*0x12638b*/
              {
                *(_WORD *)(v4 + 4) = __ROR2__(*(_WORD *)(v4 + 4), 8); /*0x126395*/
                if ( ip_mforward(v4, v26) ) /*0x12639e*/
                  goto LABEL_58; /*0x1263a8*/
                *(_WORD *)(v4 + 4) = __ROR2__(*(_WORD *)(v4 + 4), 8); /*0x1263bc*/
                if ( *(_BYTE *)(v4 + 9) == 2 ) /*0x1263c4*/
                  goto LABEL_72; /*0x1263c4*/
              }
              v18 = (_DWORD *)in_ifaddr; /*0x1263c6*/
              if ( !in_ifaddr ) /*0x1263cd*/
                goto LABEL_58; /*0x1263cd*/
              do /*0x1263dd*/
              {
                if ( v18[8] == v26 ) /*0x1263d6*/
                  break; /*0x1263d6*/
                v18 = (_DWORD *)v18[16]; /*0x1263d8*/
              }
              while ( v18 ); /*0x1263dd*/
              if ( !v18 ) /*0x1263e1*/
                goto LABEL_58; /*0x1263e1*/
              v19 = (_DWORD *)v18[17]; /*0x1263e3*/
              if ( !v19 ) /*0x1263e8*/
                goto LABEL_58; /*0x1263e8*/
              do /*0x1263f9*/
              {
                if ( *v19 == *(_DWORD *)(v4 + 16) ) /*0x1263f2*/
                  break; /*0x1263f2*/
                v19 = (_DWORD *)v19[5]; /*0x1263f4*/
              }
              while ( v19 ); /*0x1263f9*/
              if ( v19 ) /*0x1263fd*/
              {
LABEL_72:
                if ( (*(_WORD *)(v4 + 6) & 0xBFFF) == 0 ) /*0x12642e*/
                {
                  *(_WORD *)(v4 + 2) -= v24; /*0x1264d4*/
                  goto LABEL_89; /*0x1264d4*/
                }
                v20 = ipq; /*0x126434*/
                if ( (int *)ipq == &ipq ) /*0x126440*/
                {
LABEL_79:
                  v20 = 0; /*0x126470*/
                }
                else
                {
                  while ( *(_WORD *)(v20 + 10) != *(_WORD *)(v4 + 4) /*0x126464*/
                       || *(_DWORD *)(v4 + 12) != *(_DWORD *)(v20 + 20)
                       || *(_DWORD *)(v4 + 16) != *(_DWORD *)(v20 + 24)
                       || *(_BYTE *)(v4 + 9) != *(_BYTE *)(v20 + 9) )
                  {
                    v20 = *(_DWORD *)v20; /*0x126466*/
                    if ( (int *)v20 == &ipq ) /*0x12646e*/
                      goto LABEL_79; /*0x12646e*/
                  }
                }
                *(_WORD *)(v4 + 2) -= v24; /*0x126476*/
                *(_BYTE *)(v4 + 1) = 0; /*0x12647a*/
                if ( (*(_BYTE *)(v4 + 7) & 0x20) != 0 ) /*0x126482*/
                  *(_BYTE *)(v4 + 1) = 1; /*0x126484*/
                v21 = 8 * *(_WORD *)(v4 + 6); /*0x12648c*/
                *(_WORD *)(v4 + 6) = v21; /*0x126490*/
                if ( *(_BYTE *)(v4 + 1) || v21 ) /*0x12649d*/
                {
                  ++dword_1EAAC8; /*0x12649f*/
                  v22 = (int *)ip_reass(v4, v20); /*0x1264a7*/
                  v4 = (int)v22; /*0x1264ac*/
                  if ( v22 ) /*0x1264b3*/
                  {
                    v11 = v22; /*0x1264b9*/
                    LOBYTE(v11) = (unsigned __int8)v22 & 0x80; /*0x1264bb*/
                    goto LABEL_89; /*0x1264be*/
                  }
                }
                else
                {
                  if ( v20 ) /*0x1264c2*/
                    ip_freef(v20); /*0x1264c5*/
LABEL_89:
                  v27 = v11; /*0x1264d8*/
                  if ( !receive_ip_datagram(&v27) ) /*0x1264df*/
                    ((void (__cdecl *)(int *, int))dword_1DBB70[12 /*0x12650e*/
                                                              * (unsigned __int8)ip_protox[*(unsigned __int8 *)(v4 + 9)]])(
                      v27,
                      v26);
                }
              }
              else
              {
LABEL_58:
                v17 = v4; /*0x1263aa*/
                LOBYTE(v17) = v4 & 0x80; /*0x1263ac*/
                m_freem(v17); /*0x1263af*/
              }
            }
            else
            {
              if ( v16 == -1 || !v16 ) /*0x126413*/
                goto LABEL_72; /*0x126413*/
              ip_forward((void *)v4, v26); /*0x12641a*/
            }
          }
        }
        else
        {
          ++dword_1EAAB8; /*0x12627b*/
          v0 = v27; /*0x126281*/
LABEL_91:
          m_freem((int)v0); /*0x126518*/
        }
      }
      else
      {
        v5 = m_pullup((int)v0, v24); /*0x1261d2*/
        v0 = v5; /*0x1261d7*/
        if ( v5 ) /*0x1261de*/
        {
          v4 = (int)v5 + v5[1]; /*0x1261ee*/
          goto LABEL_25; /*0x1261ee*/
        }
        ++dword_1EAAC0; /*0x1261e0*/
      }
    }
    else
    {
      ++dword_1EAABC; /*0x126197*/
    }
  }
}
