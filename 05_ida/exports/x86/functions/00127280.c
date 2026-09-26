/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x127280. */
int __cdecl ip_output(int a1, int a2, int *a3, char a4, int a5)
{
  _DWORD *v5; // esi
  int v6; // ebx
  __int16 v7; // ax
  int v8; // edx
  __int16 v9; // ax
  int v10; // eax
  int v11; // edi
  _DWORD *v12; // eax
  int v13; // edi
  _DWORD *v14; // esi
  __int16 v15; // ax
  int v16; // eax
  __int16 v17; // ax
  int v18; // eax
  __int16 v19; // dx
  __int16 v20; // ax
  int v21; // edx
  __int16 v22; // dx
  int v24; // [esp+Ch] [ebp-58h]
  int v25; // [esp+10h] [ebp-54h]
  int v26; // [esp+14h] [ebp-50h]
  char *v27; // [esp+18h] [ebp-4Ch]
  char *v28; // [esp+18h] [ebp-4Ch]
  int v29; // [esp+1Ch] [ebp-48h]
  int v30; // [esp+1Ch] [ebp-48h]
  int v31; // [esp+20h] [ebp-44h]
  signed int v32; // [esp+24h] [ebp-40h]
  int v33; // [esp+28h] [ebp-3Ch]
  int v34; // [esp+2Ch] [ebp-38h]
  int v35; // [esp+34h] [ebp-30h]
  int v36; // [esp+38h] [ebp-2Ch] BYREF
  _WORD v37[10]; // [esp+3Ch] [ebp-28h] BYREF
  int v38[5]; // [esp+50h] [ebp-14h] BYREF

  v35 = 20; /*0x12728c*/
  v5 = nullptr; /*0x127293*/
  v33 = a1; /*0x127298*/
  v24 = 0; /*0x12729b*/
  if ( a2 ) /*0x1272a4*/
  {
    v33 = ip_insertoptions(a1, a2, &v36); /*0x1272b1*/
    v35 = v36; /*0x1272b7*/
  }
  v6 = *(_DWORD *)(v33 + 4) + v33; /*0x1272c0*/
  if ( (a4 & 1) != 0 ) /*0x1272c9*/
  {
    v35 = 4 * (*(_BYTE *)v6 & 0xF); /*0x12730c*/
  }
  else
  {
    *(_BYTE *)v6 = *(_BYTE *)v6 & 0xF | 0x40; /*0x1272d1*/
    *(_WORD *)(v6 + 6) &= 0x4000u; /*0x1272d3*/
    v7 = ip_id++; /*0x1272d9*/
    *(_WORD *)(v6 + 4) = __ROR2__(v7, 8); /*0x1272ea*/
    *(_BYTE *)v6 = (v35 >> 2) & 0xF | *(_BYTE *)v6 & 0xF0; /*0x1272ff*/
  }
  if ( !a3 ) /*0x127313*/
  {
    a3 = v38; /*0x127318*/
    bzero(v38, 0x14u); /*0x12731e*/
  }
  v31 = (int)(a3 + 1); /*0x12732c*/
  v8 = *a3; /*0x127332*/
  if ( !*a3 ) /*0x127332*/
    goto LABEL_16; /*0x127332*/
  if ( (*(_BYTE *)(v8 + 36) & 1) == 0 || a3[2] != *(_DWORD *)(v6 + 16) ) /*0x127344*/
  {
    v9 = *(_WORD *)(v8 + 38); /*0x127346*/
    if ( v9 == 1 ) /*0x12734e*/
      rtfree(*a3); /*0x127351*/
    else
      *(_WORD *)(v8 + 38) = v9 - 1; /*0x12735e*/
    *a3 = 0; /*0x127365*/
  }
  if ( !*a3 ) /*0x12736e*/
  {
LABEL_16:
    *(_WORD *)v31 = 2; /*0x127376*/
    a3[2] = *(_DWORD *)(v6 + 16); /*0x12737e*/
  }
  if ( (a4 & 0x10) != 0 ) /*0x127387*/
  {
    v5 = (_DWORD *)ifa_ifwithdstaddr((_WORD *)v31); /*0x127392*/
    if ( !v5 ) /*0x127399*/
    {
      v10 = in_netof(*(_DWORD *)(v6 + 16)); /*0x12739f*/
      v5 = (_DWORD *)in_iaonnetof(v10); /*0x1273aa*/
      if ( !v5 ) /*0x1273b1*/
      {
        v24 = 51; /*0x1273b3*/
        goto LABEL_84; /*0x1273ba*/
      }
    }
    v34 = v5[8]; /*0x1273c3*/
  }
  else
  {
    if ( !*a3 && (rtalloc(a3), !*a3) || (v34 = *(_DWORD *)(*a3 + 44)) == 0 ) /*0x1273ee*/
    {
      v24 = 51; /*0x1273fc*/
      if ( in_localaddr(*(_DWORD *)(v6 + 16)) ) /*0x1273f4*/
        v24 = 65; /*0x12740b*/
      goto LABEL_84; /*0x127412*/
    }
    ++*(_DWORD *)(*a3 + 40); /*0x127418*/
    if ( (*(_BYTE *)(*a3 + 36) & 2) != 0 ) /*0x127424*/
      v31 = *a3 + 20; /*0x127429*/
  }
  if ( (_byteswap_ulong(*(_DWORD *)(v6 + 16)) & 0xF0000000) == 0xE0000000 ) /*0x12743b*/
  {
    v31 = (int)(a3 + 1); /*0x127447*/
    if ( (a4 & 2) != 0 && a5 ) /*0x127456*/
    {
      v11 = *(_DWORD *)(a5 + 4) + a5; /*0x12745b*/
      v25 = v11; /*0x12745e*/
      *(_BYTE *)(v6 + 8) = *(_BYTE *)(v11 + 4); /*0x127464*/
      if ( *(_DWORD *)v11 ) /*0x127467*/
        v34 = *(_DWORD *)v11; /*0x12746d*/
    }
    else
    {
      v25 = 0; /*0x12747c*/
      *(_BYTE *)(v6 + 8) = 1; /*0x127483*/
    }
    if ( !*(_DWORD *)(v6 + 12) ) /*0x127487*/
    {
      v5 = (_DWORD *)in_ifaddr; /*0x12748d*/
      if ( !in_ifaddr ) /*0x127495*/
        goto LABEL_48; /*0x127495*/
      while ( v5[8] != v34 ) /*0x12749e*/
      {
        v5 = (_DWORD *)v5[16]; /*0x1274a0*/
        if ( !v5 ) /*0x1274a5*/
          goto LABEL_40; /*0x1274a5*/
      }
      *(_DWORD *)(v6 + 12) = v5[1]; /*0x127477*/
    }
LABEL_40:
    if ( v5 ) /*0x1274a9*/
    {
      v12 = (_DWORD *)v5[17]; /*0x1274ab*/
      if ( v12 ) /*0x1274b0*/
      {
        do /*0x1274c1*/
        {
          if ( *v12 == *(_DWORD *)(v6 + 16) ) /*0x1274ba*/
            break; /*0x1274ba*/
          v12 = (_DWORD *)v12[5]; /*0x1274bc*/
        }
        while ( v12 ); /*0x1274c1*/
        if ( v12 && (!v25 || *(_BYTE *)(v25 + 5)) ) /*0x1274d0*/
        {
          ip_mloopback(v34, v33, v31); /*0x1274e2*/
LABEL_52:
          if ( !*(_BYTE *)(v6 + 8) || loifp == v34 ) /*0x12752b*/
          {
            v13 = v33; /*0x127531*/
            goto LABEL_85; /*0x127534*/
          }
          goto LABEL_67; /*0x12752b*/
        }
      }
    }
LABEL_48:
    if ( ip_mrouter && (a4 & 1) == 0 && ip_mforward(v6, v34) ) /*0x127505*/
    {
      v13 = v33; /*0x127511*/
LABEL_85:
      m_freem(v13); /*0x12785c*/
      goto LABEL_86; /*0x12785d*/
    }
    goto LABEL_52; /*0x12750f*/
  }
  if ( !*(_DWORD *)(v6 + 12) ) /*0x127544*/
  {
    v14 = (_DWORD *)in_ifaddr; /*0x12754a*/
    if ( in_ifaddr ) /*0x127552*/
    {
      while ( v14[8] != v34 ) /*0x12755a*/
      {
        v14 = (_DWORD *)v14[16]; /*0x12755c*/
        if ( !v14 ) /*0x127561*/
          goto LABEL_60; /*0x127561*/
      }
      *(_DWORD *)(v6 + 12) = v14[1]; /*0x12753f*/
    }
  }
LABEL_60:
  if ( !in_broadcast(*(_DWORD *)(v31 + 4)) ) /*0x127574*/
  {
LABEL_67:
    v15 = *(_WORD *)(v34 + 10); /*0x1275c0*/
    if ( *(__int16 *)(v6 + 2) <= v15 ) /*0x1275cb*/
      goto LABEL_68; /*0x1275cb*/
    if ( (*(_BYTE *)(v6 + 7) & 0x40) == 0 ) /*0x12761c*/
    {
      v16 = v15 - v35; /*0x12761f*/
      LOBYTE(v16) = v16 & 0xF8; /*0x127622*/
      v36 = v16; /*0x127624*/
      if ( v16 > 7 ) /*0x12762a*/
      {
        v29 = (*(int (__cdecl **)(int))(v34 + 64))(v34); /*0x127635*/
        if ( v29 ) /*0x12763d*/
        {
          v27 = (char *)nb_map(v29); /*0x12764c*/
          mbuf_read(v33, v27, 0, v36 + v35); /*0x127660*/
          qmemcpy(v37, (const void *)v6, sizeof(v37)); /*0x127672*/
          v37[1] = __ROR2__(v36 + v35, 8); /*0x127683*/
          v17 = *(_WORD *)(v6 + 6); /*0x127687*/
          HIBYTE(v17) |= 0x20u; /*0x12768b*/
          v37[3] = __ROR2__(v17, 8); /*0x127692*/
          v37[5] = 0; /*0x127696*/
          bcopy(v37, v27, 0x14u); /*0x1276a6*/
          v37[5] = in_cksum(v29, v35); /*0x1276b8*/
          *((_WORD *)v27 + 5) = v37[5]; /*0x1276c2*/
          v24 = (*(int (__cdecl **)(int, int, int))(v34 + 52))(v34, v29, v31); /*0x1276dc*/
          if ( v24 ) /*0x1276e4*/
            goto LABEL_84; /*0x1276e4*/
          v26 = 20; /*0x1276ea*/
          v32 = v36 + v35; /*0x1276f7*/
          if ( v36 + v35 >= *(__int16 *)(v6 + 2) ) /*0x127700*/
            goto LABEL_84; /*0x127700*/
          while ( 1 ) /*0x12770f*/
          {
            v18 = (*(int (__cdecl **)(int))(v34 + 64))(v34); /*0x12770f*/
            v30 = v18; /*0x127711*/
            if ( !v18 ) /*0x127719*/
              break; /*0x127719*/
            v28 = (char *)nb_map(v18); /*0x127725*/
            qmemcpy(v37, (const void *)v6, sizeof(v37)); /*0x127738*/
            if ( (unsigned int)v35 > 0x14 ) /*0x127741*/
            {
              v26 = ip_optcopy(v6, v28) + 20; /*0x127750*/
              LOBYTE(v37[0]) = (v26 >> 2) & 0xF | v37[0] & 0xF0; /*0x127762*/
            }
            v19 = *(_WORD *)(v6 + 6); /*0x127771*/
            HIBYTE(v19) &= ~0x20u; /*0x127775*/
            v20 = v19 + ((v32 - v35) >> 3); /*0x127778*/
            v37[3] = v20; /*0x12777b*/
            if ( (*(_BYTE *)(v6 + 7) & 0x20) != 0 ) /*0x127783*/
            {
              HIBYTE(v20) |= 0x20u; /*0x127785*/
              v37[3] = v20; /*0x127788*/
            }
            v21 = *(__int16 *)(v6 + 2); /*0x127792*/
            if ( v36 + v32 < v21 ) /*0x127798*/
            {
              v37[3] |= 0x2000u; /*0x1277b8*/
            }
            else
            {
              nb_shrink_bot(v30, v36 + v32 - v21); /*0x1277a1*/
              v36 = *(__int16 *)(v6 + 2) - v32; /*0x1277ad*/
            }
            v37[1] = __ROR2__(v36 + v26, 8); /*0x1277cc*/
            mbuf_read(v33, &v28[v26], v32, v36); /*0x1277e0*/
            v37[3] = __ROR2__(v37[3], 8); /*0x1277f0*/
            v37[5] = 0; /*0x1277f4*/
            bcopy(v37, v28, 0x14u); /*0x127804*/
            v37[5] = in_cksum(v30, v26); /*0x127816*/
            *((_WORD *)v28 + 5) = v37[5]; /*0x127823*/
            v24 = (*(int (__cdecl **)(int, int, int))(v34 + 52))(v34, v30, v31); /*0x12783c*/
            if ( !v24 ) /*0x127844*/
            {
              v32 += v36; /*0x127849*/
              if ( v32 < *(__int16 *)(v6 + 2) ) /*0x127853*/
                continue; /*0x127853*/
            }
            goto LABEL_84; /*0x127853*/
          }
        }
        v24 = 55; /*0x12789c*/
LABEL_84:
        v13 = a1; /*0x127859*/
        goto LABEL_85; /*0x127859*/
      }
    }
LABEL_66:
    v24 = 40; /*0x1275b1*/
    goto LABEL_84; /*0x1275b8*/
  }
  if ( (*(_BYTE *)(v34 + 12) & 2) == 0 ) /*0x12757d*/
  {
    v24 = 49; /*0x12757f*/
    goto LABEL_84; /*0x127586*/
  }
  if ( (a4 & 0x20) == 0 ) /*0x127595*/
  {
    v24 = 13; /*0x127597*/
    goto LABEL_84; /*0x12759e*/
  }
  if ( *(_WORD *)(v6 + 2) > *(_WORD *)(v34 + 10) ) /*0x1275af*/
    goto LABEL_66; /*0x1275af*/
LABEL_68:
  *(_WORD *)(v6 + 2) = __ROR2__(*(_WORD *)(v6 + 2), 8); /*0x1275cd*/
  *(_WORD *)(v6 + 6) = __ROR2__(*(_WORD *)(v6 + 6), 8); /*0x1275e1*/
  *(_WORD *)(v6 + 10) = 0; /*0x1275e5*/
  *(_WORD *)(v6 + 10) = in_cksum(v33, v35); /*0x1275f8*/
  v24 = if_output_mbuf(v34, v33, v31); /*0x12760a*/
LABEL_86:
  if ( a3 == v38 && (a4 & 0x10) == 0 && v38[0] ) /*0x12787a*/
  {
    v22 = *(_WORD *)(v38[0] + 38); /*0x12787c*/
    if ( v22 == 1 ) /*0x127884*/
      rtfree(v38[0]); /*0x127887*/
    else
      *(_WORD *)(v38[0] + 38) = v22 - 1; /*0x127892*/
  }
  return v24; /*0x1278ab*/
}
