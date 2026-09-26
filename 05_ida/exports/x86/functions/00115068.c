/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x115068. */
int __cdecl sosend(int a1, int a2, int a3, char a4, int a5)
{
  __int16 i; // ax
  int v7; // ebx
  __int16 v8; // dx
  int v9; // edi
  unsigned __int16 v10; // si
  __int16 v11; // ax
  int v12; // edi
  int v13; // ebx
  int *v14; // esi
  int *v15; // ebx
  int v16; // ebx
  int v17; // eax
  int v18; // ebx
  int v19; // eax
  __int16 v20; // ax
  int v21; // [esp+Ch] [ebp-28h]
  int v22; // [esp+1Ch] [ebp-18h]
  _BOOL4 v23; // [esp+20h] [ebp-14h]
  int v24; // [esp+24h] [ebp-10h]
  int v25; // [esp+28h] [ebp-Ch]
  int *v26; // [esp+2Ch] [ebp-8h]
  int v27; // [esp+30h] [ebp-4h] BYREF

  v27 = 0; /*0x115071*/
  v25 = 0; /*0x115078*/
  v24 = 0; /*0x11507f*/
  v22 = 1; /*0x115086*/
  if ( (*(_BYTE *)(*(_DWORD *)(a1 + 12) + 10) & 1) != 0 && *(_DWORD *)(a3 + 20) > (int)*(unsigned __int16 *)(a1 + 62) ) /*0x1150a3*/
    return 40; /*0x1150aa*/
  v23 = 0; /*0x1150ec*/
  if ( (a4 & 4) != 0 && (*(_BYTE *)(a1 + 2) & 0x10) == 0 ) /*0x115102*/
    v23 = (*(_BYTE *)(*(_DWORD *)(a1 + 12) + 10) & 1) != 0; /*0x11510d*/
  ++*(_DWORD *)(active_u + 420); /*0x115115*/
  if ( a5 ) /*0x11511f*/
    v25 = *(__int16 *)(a5 + 8); /*0x115128*/
  while ( 2 ) /*0x115134*/
  {
    for ( i = *(_WORD *)(a1 + 80); (i & 1) != 0; i = *(_WORD *)(a1 + 80) ) /*0x115134*/
    {
      LOBYTE(i) = i | 2; /*0x11513c*/
      *(_WORD *)(a1 + 80) = i; /*0x115141*/
      sleep(a1 + 80); /*0x115148*/
    }
    *(_BYTE *)(a1 + 80) |= 1u; /*0x11515e*/
    while ( 1 ) /*0x115169*/
    {
      v7 = splnet(); /*0x115169*/
      v8 = *(_WORD *)(a1 + 6); /*0x11516e*/
      if ( (v8 & 0x10) != 0 ) /*0x115179*/
      {
        v24 = 32; /*0x1150b0*/
        goto LABEL_37; /*0x1150b7*/
      }
      if ( *(_WORD *)(a1 + 86) ) /*0x115182*/
      {
        v24 = *(unsigned __int16 *)(a1 + 86); /*0x1150c1*/
        *(_WORD *)(a1 + 86) = 0; /*0x1150c7*/
        goto LABEL_37; /*0x1150cd*/
      }
      if ( (v8 & 2) == 0 ) /*0x115192*/
      {
        if ( (*(_BYTE *)(*(_DWORD *)(a1 + 12) + 10) & 4) != 0 ) /*0x11519b*/
        {
          v24 = 57; /*0x1150d4*/
          goto LABEL_37; /*0x1150db*/
        }
        if ( !a2 ) /*0x1151a5*/
        {
          v24 = 39; /*0x1150e0*/
          goto LABEL_37; /*0x1150e7*/
        }
      }
      if ( (a4 & 1) == 0 ) /*0x1151af*/
        break; /*0x1151af*/
      v9 = 1024; /*0x1151b1*/
LABEL_41:
      splx(v7); /*0x1152c0*/
      v26 = &v27; /*0x1152c9*/
      v12 = v9 - v25; /*0x1152cc*/
      if ( v12 > 0 ) /*0x1152d4*/
      {
        do /*0x1152e1*/
        {
          v13 = splimp(); /*0x1152e1*/
          v14 = (int *)mfree; /*0x1152e3*/
          if ( mfree ) /*0x1152eb*/
          {
            if ( *(_WORD *)(mfree + 10) ) /*0x1152ed*/
              panic(aMget_5); /*0x1152f9*/
            *(_WORD *)(mfree + 10) = 1; /*0x115301*/
            --word_1E917C[0]; /*0x115307*/
            ++word_1E917E; /*0x11530e*/
            mfree = *v14; /*0x115317*/
            *v14 = 0; /*0x11531d*/
            v14[1] = 12; /*0x115323*/
          }
          else
          {
            v14 = m_more(1, 1); /*0x115335*/
          }
          splx(v13); /*0x11533b*/
          if ( *(int *)(a3 + 20) > 511 && v12 > 1023 ) /*0x115359*/
          {
            v21 = splimp(); /*0x115364*/
            if ( !mclfree ) /*0x11536e*/
              m_clalloc(1, 1); /*0x115376*/
            v15 = (int *)mclfree; /*0x11537e*/
            if ( mclfree ) /*0x115386*/
            {
              ++mclrefcnt[(mclfree - mbutl) >> 10]; /*0x115393*/
              --dword_1E916C; /*0x115399*/
              mclfree = *v15; /*0x1153a1*/
            }
            splx(v21); /*0x1153ab*/
            if ( v15 ) /*0x1153b5*/
            {
              v14[1] = (char *)v15 - (char *)v14; /*0x1153b9*/
              *((_WORD *)v14 + 4) = 1024; /*0x1153bc*/
              *((_WORD *)v14 + 6) = 1; /*0x1153c2*/
            }
            else
            {
              *((_WORD *)v14 + 4) = 112; /*0x1153cc*/
            }
            if ( *((_WORD *)v14 + 4) == 1024 ) /*0x1153d8*/
            {
              v16 = 1024; /*0x1153e0*/
              if ( *(int *)(a3 + 20) <= 1024 ) /*0x1153ea*/
                v16 = *(_DWORD *)(a3 + 20); /*0x1153ec*/
              v12 -= 1024; /*0x1153ee*/
              goto LABEL_68; /*0x1153f4*/
            }
          }
          v17 = *(_DWORD *)(a3 + 20); /*0x1153fb*/
          if ( v17 > 112 ) /*0x115401*/
          {
            if ( v12 > 112 ) /*0x11540f*/
            {
LABEL_64:
              v16 = 112; /*0x115411*/
              if ( *(int *)(a3 + 20) <= 112 ) /*0x11541f*/
                v16 = *(_DWORD *)(a3 + 20); /*0x115421*/
              goto LABEL_67; /*0x115423*/
            }
          }
          else if ( v17 < v12 ) /*0x115405*/
          {
            goto LABEL_64; /*0x115405*/
          }
          v16 = v12; /*0x115428*/
LABEL_67:
          v12 -= v16; /*0x11542a*/
LABEL_68:
          v24 = uiomove((int)v14 + v14[1], v16, 1, (_DWORD *)a3); /*0x11542c*/
          *((_WORD *)v14 + 4) = v16; /*0x115441*/
          *v26 = (int)v14; /*0x115448*/
          if ( v24 ) /*0x115451*/
            goto LABEL_79; /*0x115451*/
          v26 = v14; /*0x115457*/
        }
        while ( *(int *)(a3 + 20) > 0 && v12 > 0 ); /*0x1152e1*/
      }
      if ( v23 ) /*0x11546f*/
        *(_BYTE *)(a1 + 2) |= 0x10u; /*0x115474*/
      v18 = splnet(); /*0x11547d*/
      v19 = 9; /*0x115491*/
      if ( (a4 & 1) != 0 ) /*0x11549a*/
        v19 = 14; /*0x11549c*/
      v24 = (*(int (__cdecl **)(int, int, int, int, int))(*(_DWORD *)(a1 + 12) + 28))(a1, v19, v27, a2, a5); /*0x1154ab*/
      splx(v18); /*0x1154af*/
      if ( v23 ) /*0x1154bb*/
        *(_BYTE *)(a1 + 2) &= ~0x10u; /*0x1154c0*/
      a5 = 0; /*0x1154c4*/
      v25 = 0; /*0x1154cb*/
      v27 = 0; /*0x1154d2*/
      v22 = 0; /*0x1154d9*/
      if ( v24 || !*(_DWORD *)(a3 + 20) ) /*0x1154e9*/
        goto LABEL_79; /*0x1154ed*/
    }
    v10 = *(_WORD *)(a1 + 60); /*0x1151d3*/
    v9 = *(unsigned __int16 *)(a1 + 62) - v10; /*0x1151dc*/
    if ( *(unsigned __int16 *)(a1 + 66) - *(unsigned __int16 *)(a1 + 64) < v9 ) /*0x1151e1*/
      v9 = *(unsigned __int16 *)(a1 + 66) - *(unsigned __int16 *)(a1 + 64); /*0x1151e3*/
    if ( v25 < v9 /*0x115232*/
      && ((*(_BYTE *)(*(_DWORD *)(a1 + 12) + 10) & 1) == 0 || v9 >= *(_DWORD *)(a3 + 20) + v25)
      && (*(int *)(a3 + 20) <= 1023 || v9 > 1023 || v10 <= 0x3FFu || (*(_WORD *)(a1 + 6) & 0x100) != 0) )
    {
      goto LABEL_41; /*0x115232*/
    }
    if ( (*(_BYTE *)(a1 + 7) & 1) == 0 ) /*0x11523f*/
    {
      v11 = *(_WORD *)(a1 + 80); /*0x11527f*/
      *(_WORD *)(a1 + 80) = v11 & 0xFFFE; /*0x115288*/
      if ( (v11 & 2) != 0 ) /*0x11528e*/
      {
        LOBYTE(v11) = v11 & 0xFC; /*0x115290*/
        *(_WORD *)(a1 + 80) = v11; /*0x115292*/
        wakeup(a1 + 80); /*0x11529d*/
      }
      sbwait(a1 + 60); /*0x1152ac*/
      splx(v7); /*0x1152b2*/
      continue; /*0x1152ba*/
    }
    break;
  }
  if ( v22 ) /*0x115245*/
  {
    v24 = 35; /*0x11524e*/
    if ( (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) != 0 && (*(_BYTE *)(a3 + 17) & 0x20) != 0 ) /*0x115262*/
      v24 = 11; /*0x115264*/
  }
LABEL_37:
  splx(v7); /*0x11526b*/
LABEL_79:
  v20 = *(_WORD *)(a1 + 80); /*0x1154f3*/
  *(_WORD *)(a1 + 80) = v20 & 0xFFFE; /*0x1154ff*/
  if ( (v20 & 2) != 0 ) /*0x115505*/
  {
    LOBYTE(v20) = v20 & 0xFC; /*0x115507*/
    *(_WORD *)(a1 + 80) = v20; /*0x115509*/
    wakeup(a1 + 80); /*0x115514*/
  }
  if ( v27 ) /*0x115521*/
    m_freem(v27); /*0x115524*/
  if ( v24 == 32 ) /*0x115530*/
    exception_from_kernel(5, (exception_data_t)0x10001, 0); /*0x11553b*/
  return v24; /*0x115546*/
}
