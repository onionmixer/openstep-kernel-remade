/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x126534. */
int __cdecl ip_reass(int a1, int a2)
{
  int v2; // edi
  int v3; // ecx
  int v4; // eax
  int *v5; // eax
  int i; // ebx
  int *v7; // eax
  int v8; // edx
  int *v9; // eax
  int v10; // edx
  int v11; // eax
  __int16 v12; // dx
  int v13; // eax
  int v14; // ebx
  int *v16; // ebx
  int *v17; // ecx
  int v18; // eax
  int v19; // ebx
  int v20; // eax
  int v21; // eax
  int v22; // ecx
  int v23; // [esp+Ch] [ebp-Ch]
  int v24; // [esp+Ch] [ebp-Ch]
  int v25; // [esp+Ch] [ebp-Ch]
  int v26; // [esp+10h] [ebp-8h]
  int *v27; // [esp+10h] [ebp-8h]
  int v28; // [esp+20h] [ebp+8h]

  v2 = a2; /*0x12653d*/
  v3 = a1; /*0x126540*/
  LOBYTE(v3) = a1 & 0x80; /*0x126543*/
  v26 = v3; /*0x126546*/
  v4 = 4 * (*(_BYTE *)a1 & 0xF); /*0x126551*/
  *(_DWORD *)(v3 + 4) += v4; /*0x126559*/
  *(_WORD *)(v3 + 8) -= v4; /*0x126563*/
  if ( !a2 ) /*0x126569*/
  {
    v5 = m_get(0, 11); /*0x126573*/
    if ( v5 ) /*0x12657d*/
    {
      v2 = (int)v5 + v5[1]; /*0x126585*/
      *(_DWORD *)v2 = ipq; /*0x12658e*/
      *(_DWORD *)(v2 + 4) = &ipq; /*0x126590*/
      *(_DWORD *)(ipq + 4) = v2; /*0x12659c*/
      ipq = v2; /*0x12659f*/
      *(_BYTE *)(v2 + 8) = 60; /*0x1265a5*/
      *(_BYTE *)(v2 + 9) = *(_BYTE *)(a1 + 9); /*0x1265ac*/
      *(_WORD *)(v2 + 10) = *(_WORD *)(a1 + 4); /*0x1265b3*/
      *(_DWORD *)(v2 + 16) = v2; /*0x1265b7*/
      *(_DWORD *)(v2 + 12) = v2; /*0x1265ba*/
      *(_DWORD *)(v2 + 20) = *(_DWORD *)(a1 + 12); /*0x1265c3*/
      *(_DWORD *)(v2 + 24) = *(_DWORD *)(a1 + 16); /*0x1265cc*/
      i = v2; /*0x1265cf*/
      goto LABEL_16; /*0x1265d1*/
    }
LABEL_25:
    ++dword_1EAACC; /*0x1267a8*/
    m_freem(v26); /*0x1267b2*/
    return 0; /*0x1267b7*/
  }
  for ( i = *(_DWORD *)(a2 + 12); i != a2; i = *(_DWORD *)(i + 12) ) /*0x126605*/
  {
    if ( *(_WORD *)(i + 6) > *(_WORD *)(a1 + 6) ) /*0x126614*/
      break; /*0x126614*/
  }
  v8 = *(_DWORD *)(i + 16); /*0x12661d*/
  if ( v8 != a2 ) /*0x126622*/
  {
    v23 = *(__int16 *)(v8 + 2) + *(__int16 *)(v8 + 6) - *(__int16 *)(a1 + 6); /*0x12663b*/
    if ( v23 > 0 ) /*0x126640*/
    {
      if ( v23 < *(__int16 *)(a1 + 2) ) /*0x126649*/
      {
        v9 = (int *)a1; /*0x126653*/
        LOBYTE(v9) = a1 & 0x80; /*0x126656*/
        m_adj(v9, v23); /*0x126659*/
        *(_WORD *)(a1 + 6) += v23; /*0x126662*/
        *(_WORD *)(a1 + 2) -= v23; /*0x12666a*/
        goto LABEL_15; /*0x12666e*/
      }
      goto LABEL_25; /*0x126649*/
    }
  }
LABEL_15:
  while ( i != a2 ) /*0x1266b6*/
  {
    v10 = *(__int16 *)(a1 + 2) + *(__int16 *)(a1 + 6); /*0x12667b*/
    v11 = *(__int16 *)(i + 6); /*0x12667d*/
    if ( v10 <= v11 ) /*0x126683*/
      break; /*0x126683*/
    v24 = v10 - v11; /*0x126687*/
    v12 = *(_WORD *)(i + 2); /*0x12668a*/
    if ( v24 < v12 ) /*0x126694*/
    {
      *(_WORD *)(i + 2) = v12 - v24; /*0x1265dc*/
      *(_WORD *)(i + 6) += v24; /*0x1265e4*/
      v7 = (int *)i; /*0x1265ec*/
      LOBYTE(v7) = i & 0x80; /*0x1265ee*/
      m_adj(v7, v24); /*0x1265f1*/
      break; /*0x1265f9*/
    }
    i = *(_DWORD *)(i + 12); /*0x12669a*/
    v13 = *(_DWORD *)(i + 16); /*0x12669d*/
    LOBYTE(v13) = v13 & 0x80; /*0x1266a0*/
    m_freem(v13); /*0x1266a3*/
    ip_deq(*(_DWORD *)(i + 16)); /*0x1266ac*/
  }
LABEL_16:
  ip_enq(a1, *(_DWORD *)(i + 16)); /*0x1266b8*/
  v25 = 0; /*0x1266c5*/
  v14 = *(_DWORD *)(v2 + 12); /*0x1266cc*/
  if ( v14 != v2 ) /*0x1266d4*/
  {
    while ( v25 == *(__int16 *)(v14 + 6) ) /*0x1266df*/
    {
      v25 += *(__int16 *)(v14 + 2); /*0x1266e9*/
      v14 = *(_DWORD *)(v14 + 12); /*0x1266ec*/
      if ( v14 == v2 ) /*0x1266f1*/
        goto LABEL_19; /*0x1266f1*/
    }
    return 0; /*0x1266df*/
  }
LABEL_19:
  if ( *(_BYTE *)(*(_DWORD *)(v14 + 16) + 1) ) /*0x1266f6*/
    return 0; /*0x1266fc*/
  v16 = *(int **)(v2 + 12); /*0x126704*/
  v17 = v16; /*0x126707*/
  LOBYTE(v17) = (unsigned __int8)v16 & 0x80; /*0x126709*/
  v27 = v17; /*0x12670c*/
  v18 = *v17; /*0x12670f*/
  *v17 = 0; /*0x126711*/
  m_cat(v17, v18); /*0x126719*/
  v19 = v16[3]; /*0x12671e*/
  while ( v19 != v2 ) /*0x12673a*/
  {
    v20 = v19; /*0x126724*/
    LOBYTE(v20) = v19 & 0x80; /*0x126726*/
    v19 = *(_DWORD *)(v19 + 12); /*0x126728*/
    m_cat(v27, v20); /*0x126730*/
  }
  v28 = *(_DWORD *)(v2 + 12); /*0x12673f*/
  *(_WORD *)(v28 + 2) = v25; /*0x126746*/
  *(_DWORD *)(v28 + 12) = *(_DWORD *)(v2 + 20); /*0x12674d*/
  *(_DWORD *)(v28 + 16) = *(_DWORD *)(v2 + 24); /*0x126753*/
  *(_DWORD *)(*(_DWORD *)v2 + 4) = *(_DWORD *)(v2 + 4); /*0x12675b*/
  **(_DWORD **)(v2 + 4) = *(_DWORD *)v2; /*0x126763*/
  v21 = v2; /*0x126765*/
  LOBYTE(v21) = v2 & 0x80; /*0x126767*/
  m_free(v21); /*0x12676a*/
  v22 = v28; /*0x12676f*/
  LOBYTE(v22) = v28 & 0x80; /*0x126772*/
  *(_WORD *)(v22 + 8) += 4 * (*(_BYTE *)v28 & 0xF); /*0x12678c*/
  *(_DWORD *)(v22 + 4) -= 4 * (*(_BYTE *)v28 & 0xF); /*0x12679d*/
  return v28; /*0x1267bc*/
}
