/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1143e0. */
void __cdecl m_cat(int *a1, int a2)
{
  int *i; // edi
  unsigned int v4; // ecx
  int v5; // esi
  int v6; // esi
  size_t v7; // [esp+Ch] [ebp-8h]
  int v8; // [esp+10h] [ebp-4h]

  for ( i = a1; *i; i = (int *)*i ) /*0x1143ef*/
    ; /*0x1143f8*/
  while ( a2 ) /*0x1144da*/
  {
    v4 = i[1]; /*0x114404*/
    if ( v4 > 0x7B || (v5 = *((__int16 *)i + 4), v7 = *(__int16 *)(a2 + 8), v7 + v5 + v4 > 0x7C) ) /*0x11441f*/
    {
      *i = a2; /*0x114421*/
      return; /*0x114423*/
    }
    bcopy((const void *)(*(_DWORD *)(a2 + 4) + a2), (char *)i + v4 + v5, v7); /*0x114438*/
    *((_WORD *)i + 4) += *(_WORD *)(a2 + 8); /*0x114441*/
    v8 = splimp(); /*0x11444d*/
    if ( !*(_WORD *)(a2 + 10) ) /*0x114450*/
      panic(aMfree); /*0x11445c*/
    --word_1E917C[*(__int16 *)(a2 + 10)]; /*0x114468*/
    ++word_1E917C[0]; /*0x114470*/
    *(_WORD *)(a2 + 10) = 0; /*0x114477*/
    if ( *(_DWORD *)(a2 + 4) > 0x7Fu ) /*0x114481*/
      mclput(a2); /*0x114484*/
    v6 = *(_DWORD *)a2; /*0x11448c*/
    *(_DWORD *)a2 = mfree; /*0x114494*/
    *(_DWORD *)(a2 + 4) = 0; /*0x114496*/
    *(_DWORD *)(a2 + 124) = 0; /*0x11449d*/
    mfree = a2; /*0x1144a4*/
    splx(v8); /*0x1144ae*/
    if ( m_want ) /*0x1144bd*/
    {
      m_want = 0; /*0x1144bf*/
      wakeup((int)&mfree); /*0x1144ce*/
    }
    a2 = v6; /*0x1144d6*/
  }
}
