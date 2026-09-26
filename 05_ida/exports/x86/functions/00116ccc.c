/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x116ccc. */
void __cdecl sbdroprecord(int a1)
{
  int v1; // ebx
  __int16 v2; // ax
  int v3; // edi
  int v4; // [esp+Ch] [ebp-4h]

  v1 = *(_DWORD *)(a1 + 12); /*0x116cd8*/
  if ( v1 ) /*0x116cdd*/
  {
    *(_DWORD *)(a1 + 12) = *(_DWORD *)(v1 + 124); /*0x116ce6*/
    do /*0x116da1*/
    {
      *(_WORD *)a1 -= *(_WORD *)(v1 + 8); /*0x116cf0*/
      v2 = *(_WORD *)(a1 + 4); /*0x116cf3*/
      *(_WORD *)(a1 + 4) = v2 - 128; /*0x116cfd*/
      if ( *(_DWORD *)(v1 + 4) > 0x7Cu ) /*0x116d05*/
        *(_WORD *)(a1 + 4) = v2 - 1152; /*0x116d0b*/
      v4 = splimp(); /*0x116d14*/
      if ( !*(_WORD *)(v1 + 10) ) /*0x116d17*/
        panic(aMfree_6); /*0x116d23*/
      --word_1E917C[*(__int16 *)(v1 + 10)]; /*0x116d2f*/
      ++word_1E917C[0]; /*0x116d37*/
      *(_WORD *)(v1 + 10) = 0; /*0x116d3e*/
      if ( *(_DWORD *)(v1 + 4) > 0x7Fu ) /*0x116d48*/
        mclput(v1); /*0x116d4b*/
      v3 = *(_DWORD *)v1; /*0x116d53*/
      *(_DWORD *)v1 = mfree; /*0x116d5b*/
      *(_DWORD *)(v1 + 4) = 0; /*0x116d5d*/
      *(_DWORD *)(v1 + 124) = 0; /*0x116d64*/
      mfree = v1; /*0x116d6b*/
      splx(v4); /*0x116d75*/
      if ( m_want ) /*0x116d84*/
      {
        m_want = 0; /*0x116d86*/
        wakeup((int)&mfree); /*0x116d95*/
      }
      v1 = v3; /*0x116d9d*/
    }
    while ( v3 ); /*0x116da1*/
  }
}
