/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1140e0. */
void __cdecl m_freem(int a1)
{
  int v1; // ebx
  int v2; // edi
  int v3; // esi
  int v4; // [esp+Ch] [ebp-4h]

  v1 = a1; /*0x1140e9*/
  if ( a1 ) /*0x1140ee*/
  {
    v4 = splimp(); /*0x1140f9*/
    do /*0x11418a*/
    {
      v2 = splimp(); /*0x114101*/
      if ( !*(_WORD *)(v1 + 10) ) /*0x114103*/
        panic(aMfree_0); /*0x11410f*/
      --word_1E917C[*(__int16 *)(v1 + 10)]; /*0x11411b*/
      ++word_1E917C[0]; /*0x114123*/
      *(_WORD *)(v1 + 10) = 0; /*0x11412a*/
      if ( *(_DWORD *)(v1 + 4) > 0x7Fu ) /*0x114134*/
        mclput(v1); /*0x114137*/
      v3 = *(_DWORD *)v1; /*0x11413f*/
      *(_DWORD *)v1 = mfree; /*0x114147*/
      *(_DWORD *)(v1 + 4) = 0; /*0x114149*/
      *(_DWORD *)(v1 + 124) = 0; /*0x114150*/
      mfree = v1; /*0x114157*/
      splx(v2); /*0x11415e*/
      if ( m_want ) /*0x11416d*/
      {
        m_want = 0; /*0x11416f*/
        wakeup((int)&mfree); /*0x11417e*/
      }
      v1 = v3; /*0x114186*/
    }
    while ( v3 ); /*0x11418a*/
    splx(v4); /*0x114194*/
  }
}
