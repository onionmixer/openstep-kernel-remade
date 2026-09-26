/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x116ab8. */
void __cdecl sbdrop(int a1, int a2)
{
  int v2; // ebx
  __int16 v3; // ax
  __int16 v4; // ax
  int v5; // esi
  __int16 v6; // ax
  int v7; // esi
  int v8; // [esp+Ch] [ebp-Ch]
  int v9; // [esp+10h] [ebp-8h]
  int v10; // [esp+14h] [ebp-4h]

  v2 = *(_DWORD *)(a1 + 12); /*0x116ac4*/
  v10 = 0; /*0x116ac7*/
  if ( v2 ) /*0x116ad0*/
LABEL_2:
    v10 = *(_DWORD *)(v2 + 124); /*0x116ad6*/
  while ( a2 > 0 ) /*0x116bc6*/
  {
    if ( !v2 ) /*0x116ae6*/
    {
      if ( !v10 ) /*0x116aec*/
        panic(aSbdrop); /*0x116af3*/
      v2 = v10; /*0x116afb*/
      goto LABEL_2; /*0x116afe*/
    }
    v3 = *(_WORD *)(v2 + 8); /*0x116b00*/
    if ( a2 < v3 ) /*0x116b0a*/
    {
      *(_WORD *)(v2 + 8) = v3 - a2; /*0x116ca8*/
      *(_DWORD *)(v2 + 4) += a2; /*0x116caf*/
      *(_WORD *)a1 -= a2; /*0x116cb6*/
      break; /*0x116cb9*/
    }
    a2 -= v3; /*0x116b10*/
    *(_WORD *)a1 -= v3; /*0x116b13*/
    v4 = *(_WORD *)(a1 + 4); /*0x116b16*/
    *(_WORD *)(a1 + 4) = v4 - 128; /*0x116b20*/
    if ( *(_DWORD *)(v2 + 4) > 0x7Cu ) /*0x116b28*/
      *(_WORD *)(a1 + 4) = v4 - 1152; /*0x116b2e*/
    v9 = splimp(); /*0x116b37*/
    if ( !*(_WORD *)(v2 + 10) ) /*0x116b3a*/
      panic(aMfree_4); /*0x116b46*/
    --word_1E917C[*(__int16 *)(v2 + 10)]; /*0x116b52*/
    ++word_1E917C[0]; /*0x116b5a*/
    *(_WORD *)(v2 + 10) = 0; /*0x116b61*/
    if ( *(_DWORD *)(v2 + 4) > 0x7Fu ) /*0x116b6b*/
      mclput(v2); /*0x116b6e*/
    v5 = *(_DWORD *)v2; /*0x116b76*/
    *(_DWORD *)v2 = mfree; /*0x116b7e*/
    *(_DWORD *)(v2 + 4) = 0; /*0x116b80*/
    *(_DWORD *)(v2 + 124) = 0; /*0x116b87*/
    mfree = v2; /*0x116b8e*/
    splx(v9); /*0x116b98*/
    if ( m_want ) /*0x116ba7*/
    {
      m_want = 0; /*0x116ba9*/
      wakeup((int)&mfree); /*0x116bb8*/
    }
    v2 = v5; /*0x116bc0*/
  }
  while ( v2 ) /*0x116c85*/
  {
    if ( *(_WORD *)(v2 + 8) ) /*0x116c87*/
    {
      *(_DWORD *)(a1 + 12) = v2; /*0x116c98*/
      *(_DWORD *)(v2 + 124) = v10; /*0x116c9e*/
      return; /*0x116ca1*/
    }
    *(_WORD *)a1 = *(_WORD *)a1; /*0x116bd4*/
    v6 = *(_WORD *)(a1 + 4); /*0x116bd7*/
    *(_WORD *)(a1 + 4) = v6 - 128; /*0x116be1*/
    if ( *(_DWORD *)(v2 + 4) > 0x7Cu ) /*0x116be9*/
      *(_WORD *)(a1 + 4) = v6 - 1152; /*0x116bef*/
    v8 = splimp(); /*0x116bf8*/
    if ( !*(_WORD *)(v2 + 10) ) /*0x116bfb*/
      panic(aMfree_5); /*0x116c07*/
    --word_1E917C[*(__int16 *)(v2 + 10)]; /*0x116c13*/
    ++word_1E917C[0]; /*0x116c1b*/
    *(_WORD *)(v2 + 10) = 0; /*0x116c22*/
    if ( *(_DWORD *)(v2 + 4) > 0x7Fu ) /*0x116c2c*/
      mclput(v2); /*0x116c2f*/
    v7 = *(_DWORD *)v2; /*0x116c37*/
    *(_DWORD *)v2 = mfree; /*0x116c3f*/
    *(_DWORD *)(v2 + 4) = 0; /*0x116c41*/
    *(_DWORD *)(v2 + 124) = 0; /*0x116c48*/
    mfree = v2; /*0x116c4f*/
    splx(v8); /*0x116c59*/
    if ( m_want ) /*0x116c68*/
    {
      m_want = 0; /*0x116c6a*/
      wakeup((int)&mfree); /*0x116c79*/
    }
    v2 = v7; /*0x116c81*/
  }
  *(_DWORD *)(a1 + 12) = v10; /*0x116cbf*/
}
