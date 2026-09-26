/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x113dc0. */
int *__cdecl m_get(int a1, int a2)
{
  int v2; // edi
  int *v3; // ebx

  v2 = splimp(); /*0x113dce*/
  v3 = (int *)mfree; /*0x113dd0*/
  if ( mfree ) /*0x113dd8*/
  {
    if ( *(_WORD *)(mfree + 10) ) /*0x113dda*/
      panic(aMget); /*0x113de6*/
    *(_WORD *)(mfree + 10) = a2; /*0x113dee*/
    --word_1E917C[0]; /*0x113df2*/
    ++word_1E917C[a2]; /*0x113df9*/
    mfree = *v3; /*0x113e03*/
    *v3 = 0; /*0x113e09*/
    v3[1] = 12; /*0x113e0f*/
  }
  else
  {
    v3 = (int *)m_more(a1, a2); /*0x113e22*/
  }
  splx(v2); /*0x113e28*/
  return v3; /*0x113e32*/
}
