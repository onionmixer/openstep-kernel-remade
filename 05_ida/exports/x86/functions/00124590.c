/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x124590. */
int __cdecl in_bootp_bptombuf(char *a1)
{
  int v1; // edi
  int v2; // ebx
  int *v3; // esi
  int *v4; // ebx
  size_t v5; // ebx
  int v6; // eax
  int v7; // ebx
  int v9; // [esp+Ch] [ebp-10h]
  int *v11; // [esp+14h] [ebp-8h]
  int v12; // [esp+18h] [ebp-4h] BYREF

  v11 = &v12; /*0x12459c*/
  v1 = 328; /*0x12459f*/
  do /*0x1246de*/
  {
    v2 = splimp(); /*0x1245b1*/
    v3 = (int *)mfree; /*0x1245b3*/
    if ( mfree ) /*0x1245bb*/
    {
      if ( *(_WORD *)(mfree + 10) ) /*0x1245bd*/
        panic(aMget_8); /*0x1245c9*/
      *(_WORD *)(mfree + 10) = 1; /*0x1245d1*/
      --word_1E917C[0]; /*0x1245d7*/
      ++word_1E917E; /*0x1245de*/
      mfree = *v3; /*0x1245e7*/
      *v3 = 0; /*0x1245ed*/
      v3[1] = 12; /*0x1245f3*/
    }
    else
    {
      v3 = m_more(1, 1); /*0x124605*/
    }
    splx(v2); /*0x12460b*/
    if ( v1 <= 511 ) /*0x124619*/
      goto LABEL_18; /*0x124619*/
    v9 = splimp(); /*0x124624*/
    if ( !mclfree ) /*0x12462e*/
      m_clalloc(1, 1); /*0x124636*/
    v4 = (int *)mclfree; /*0x12463e*/
    if ( mclfree ) /*0x124646*/
    {
      ++mclrefcnt[(mclfree - mbutl) >> 10]; /*0x124653*/
      --dword_1E916C; /*0x124659*/
      mclfree = *v4; /*0x124661*/
    }
    splx(v9); /*0x12466b*/
    if ( v4 ) /*0x124675*/
    {
      v3[1] = (char *)v4 - (char *)v3; /*0x124679*/
      *((_WORD *)v3 + 4) = 1024; /*0x12467c*/
      *((_WORD *)v3 + 6) = 1; /*0x124682*/
    }
    else
    {
      *((_WORD *)v3 + 4) = 112; /*0x12468c*/
    }
    if ( *((_WORD *)v3 + 4) == 1024 ) /*0x124698*/
    {
      v5 = 1024; /*0x12469a*/
      if ( v1 > 1024 ) /*0x1246a5*/
        goto LABEL_20; /*0x1246a5*/
    }
    else
    {
LABEL_18:
      v5 = 112; /*0x1246ac*/
      if ( v1 > 112 ) /*0x1246b4*/
        goto LABEL_20; /*0x1246b4*/
    }
    v5 = v1; /*0x1246b6*/
LABEL_20:
    bcopy(a1, (char *)v3 + v3[1], v5); /*0x1246b8*/
    v1 -= v5; /*0x1246c8*/
    a1 += v5; /*0x1246ca*/
    *((_WORD *)v3 + 4) = v5; /*0x1246cd*/
    *v11 = (int)v3; /*0x1246d4*/
    v11 = v3; /*0x1246d6*/
  }
  while ( v1 > 0 ); /*0x1246de*/
  v6 = v12; /*0x1246e4*/
  v7 = *(_DWORD *)(v12 + 4) + v12; /*0x1246e9*/
  *(_WORD *)(v7 + 10) = 0; /*0x1246ec*/
  *(_WORD *)(v7 + 10) = in_cksum(v6, 20); /*0x1246fa*/
  return v12; /*0x124704*/
}
