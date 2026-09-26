/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x113ed0. */
int __cdecl m_free(int a1)
{
  int v1; // edi
  int v2; // esi

  v1 = splimp(); /*0x113ede*/
  if ( !*(_WORD *)(a1 + 10) ) /*0x113ee0*/
    panic(aMfree); /*0x113eec*/
  --word_1E917C[*(__int16 *)(a1 + 10)]; /*0x113ef8*/
  ++word_1E917C[0]; /*0x113f00*/
  *(_WORD *)(a1 + 10) = 0; /*0x113f07*/
  if ( *(_DWORD *)(a1 + 4) > 0x7Fu ) /*0x113f11*/
    mclput(a1); /*0x113f14*/
  v2 = *(_DWORD *)a1; /*0x113f1c*/
  *(_DWORD *)a1 = mfree; /*0x113f24*/
  *(_DWORD *)(a1 + 4) = 0; /*0x113f26*/
  *(_DWORD *)(a1 + 124) = 0; /*0x113f2d*/
  mfree = a1; /*0x113f34*/
  splx(v1); /*0x113f3b*/
  if ( m_want ) /*0x113f4a*/
  {
    m_want = 0; /*0x113f4c*/
    wakeup((int)&mfree); /*0x113f5b*/
  }
  return v2; /*0x113f65*/
}
