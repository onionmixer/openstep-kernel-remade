/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x122250. */
int __cdecl arpresolve(int a1, void *a2, int a3, int a4, _DWORD *a5, _BYTE *a6, _DWORD *a7)
{
  int v8; // edi
  char *v9; // ebx
  int i; // eax
  int v11; // eax
  int *v12; // eax
  int v13; // edi
  int v14; // ebx
  _WORD *v15; // ebx
  int *v16; // eax
  int v17; // edi
  int v18; // ebx
  _WORD *v19; // ebx
  int v20; // [esp+14h] [ebp-34h]
  __int16 v21; // [esp+18h] [ebp-30h] BYREF
  _BYTE v22[6]; // [esp+1Ah] [ebp-2Eh] BYREF
  int v23; // [esp+20h] [ebp-28h] BYREF
  __int16 v24; // [esp+28h] [ebp-20h] BYREF
  _BYTE v25[6]; // [esp+2Ah] [ebp-1Eh] BYREF
  int v26; // [esp+30h] [ebp-18h] BYREF
  __int16 v27; // [esp+38h] [ebp-10h] BYREF
  int v28; // [esp+3Ch] [ebp-Ch]

  *a7 = 0; /*0x12225c*/
  if ( (_byteswap_ulong(*a5) & 0xF0000000) == 0xE0000000 ) /*0x122275*/
  {
    *a6 = 1; /*0x12227a*/
    a6[1] = 0; /*0x12227d*/
    a6[2] = 94; /*0x122281*/
    a6[3] = *((_BYTE *)a5 + 1) & 0x7F; /*0x122291*/
    a6[4] = *((_BYTE *)a5 + 2); /*0x12229a*/
    a6[5] = *((_BYTE *)a5 + 3); /*0x1222a3*/
    return 1; /*0x1222a6*/
  }
  else if ( in_broadcast(*a5) ) /*0x1222b1*/
  {
    bcopy((char *)&unk_1DB96C + HIBYTE(word_1DB968) + (unsigned __int8)word_1DB968, a6, (unsigned __int8)word_1DB968); /*0x1222d8*/
    return 1; /*0x1222dd*/
  }
  else
  {
    v8 = in_lnaof(*a5); /*0x1222f3*/
    if ( *a5 == a3 ) /*0x122300*/
    {
      if ( useloopback ) /*0x122309*/
      {
        v27 = 2; /*0x12230b*/
        v28 = *a5; /*0x122313*/
        looutput(loifp, a4, &v27); /*0x122325*/
        return 0; /*0x12232a*/
      }
      else
      {
        bcopy(a2, a6, 4u); /*0x12233e*/
        return 1; /*0x122343*/
      }
    }
    else
    {
      v20 = splimp(); /*0x122355*/
      v9 = (char *)&arptab + 180 * (*a5 % 0x13u); /*0x122374*/
      for ( i = 0; i <= 8; ++i ) /*0x12237b*/
      {
        if ( *(_DWORD *)v9 == *a5 && (!a1 || *((_DWORD *)v9 + 4) == a1) ) /*0x122390*/
          break; /*0x122390*/
        v9 += 20; /*0x122393*/
      }
      if ( i > 8 ) /*0x12239e*/
        v9 = nullptr; /*0x1223a0*/
      if ( v9 ) /*0x1223a4*/
      {
        v9[10] = 0; /*0x122548*/
        if ( (v9[11] & 2) != 0 ) /*0x122550*/
        {
          bcopy(v9 + 4, a6, 6u); /*0x12255c*/
          if ( (v9[11] & 0x10) != 0 ) /*0x122568*/
            *a7 = 1; /*0x12256d*/
          splx(v20); /*0x122577*/
          return 1; /*0x12257c*/
        }
        else
        {
          if ( *((_DWORD *)v9 + 3) ) /*0x122588*/
            m_freem(*((_DWORD *)v9 + 3)); /*0x122590*/
          *((_DWORD *)v9 + 3) = a4; /*0x12259b*/
          v23 = a3; /*0x1225a1*/
          v16 = m_get(0, 1); /*0x1225a8*/
          v17 = (int)v16; /*0x1225ad*/
          if ( v16 ) /*0x1225b4*/
          {
            *((_WORD *)v16 + 4) = 28; /*0x1225ba*/
            v24 = 2054; /*0x1225c0*/
            *((_WORD *)v16 + 4) = 28; /*0x1225c6*/
            bcopy(&v24, &v25[2 * (unsigned __int8)word_1DB968], 2u); /*0x1225e1*/
            bcopy( /*0x122601*/
              (char *)&unk_1DB96C + HIBYTE(word_1DB968) + (unsigned __int8)word_1DB968,
              v25,
              (unsigned __int8)word_1DB968);
            v18 = 124 - *(__int16 *)(v17 + 8); /*0x12260f*/
            *(_DWORD *)(v17 + 4) = v18; /*0x122611*/
            v19 = (_WORD *)(v17 + v18); /*0x122614*/
            bcopy(&arpethertempl, v19, *(__int16 *)(v17 + 8)); /*0x122621*/
            bcopy(a2, v19 + 4, (unsigned __int8)word_1DB968); /*0x122639*/
            bcopy(&v23, (char *)v19 + (unsigned __int8)word_1DB968 + 8, HIBYTE(word_1DB968)); /*0x122656*/
            bcopy(a5, (char *)&v19[(unsigned __int8)word_1DB968 + 4] + HIBYTE(word_1DB968), HIBYTE(word_1DB968)); /*0x122675*/
            *v19 = __ROR2__(*v19, 8); /*0x122684*/
            v19[1] = __ROR2__(v19[1], 8); /*0x12268f*/
            v19[3] = __ROR2__(v19[3], 8); /*0x12269b*/
            v24 = 0; /*0x12269f*/
            if_output_mbuf(a1, v17, (int)&v24); /*0x1226ae*/
          }
          splx(v20); /*0x1226ba*/
          return 0; /*0x1226bf*/
        }
      }
      else if ( *(char *)(a1 + 12) >= 0 ) /*0x1223b1*/
      {
        v11 = arptnew(a1, a5); /*0x1223fc*/
        if ( !v11 ) /*0x122408*/
          panic(aArpresolveNoFr); /*0x12240f*/
        *(_DWORD *)(v11 + 12) = a4; /*0x12241a*/
        v26 = a3; /*0x122420*/
        v12 = m_get(0, 1); /*0x122427*/
        v13 = (int)v12; /*0x12242c*/
        if ( v12 ) /*0x122433*/
        {
          *((_WORD *)v12 + 4) = 28; /*0x122439*/
          v21 = 2054; /*0x12243f*/
          *((_WORD *)v12 + 4) = 28; /*0x122445*/
          bcopy(&v21, &v22[2 * (unsigned __int8)word_1DB968], 2u); /*0x122460*/
          bcopy( /*0x122480*/
            (char *)&unk_1DB96C + HIBYTE(word_1DB968) + (unsigned __int8)word_1DB968,
            v22,
            (unsigned __int8)word_1DB968);
          v14 = 124 - *(__int16 *)(v13 + 8); /*0x12248e*/
          *(_DWORD *)(v13 + 4) = v14; /*0x122490*/
          v15 = (_WORD *)(v13 + v14); /*0x122493*/
          bcopy(&arpethertempl, v15, *(__int16 *)(v13 + 8)); /*0x1224a0*/
          bcopy(a2, v15 + 4, (unsigned __int8)word_1DB968); /*0x1224b8*/
          bcopy(&v26, (char *)v15 + (unsigned __int8)word_1DB968 + 8, HIBYTE(word_1DB968)); /*0x1224d5*/
          bcopy(a5, (char *)&v15[(unsigned __int8)word_1DB968 + 4] + HIBYTE(word_1DB968), HIBYTE(word_1DB968)); /*0x1224f4*/
          *v15 = __ROR2__(*v15, 8); /*0x122503*/
          v15[1] = __ROR2__(v15[1], 8); /*0x12250e*/
          v15[3] = __ROR2__(v15[3], 8); /*0x12251a*/
          v21 = 0; /*0x12251e*/
          if_output_mbuf(a1, v13, (int)&v21); /*0x12252d*/
        }
        splx(v20); /*0x122539*/
        return 0; /*0x12253e*/
      }
      else
      {
        bcopy(a2, a6, 3u); /*0x1223bd*/
        a6[3] = BYTE2(v8) & 0x7F; /*0x1223cc*/
        a6[4] = BYTE1(v8); /*0x1223d4*/
        a6[5] = v8; /*0x1223dc*/
        splx(v20); /*0x1223e3*/
        return 1; /*0x1223e8*/
      }
    }
  }
}
