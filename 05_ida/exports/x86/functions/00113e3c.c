/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x113e3c. */
int *__cdecl m_getclr(int a1, int a2)
{
  int v2; // edi
  int *v3; // ebx

  v2 = splimp(); /*0x113e4a*/
  v3 = (int *)mfree; /*0x113e4c*/
  if ( mfree ) /*0x113e54*/
  {
    if ( *(_WORD *)(mfree + 10) ) /*0x113e56*/
      panic(aMget_0); /*0x113e62*/
    *(_WORD *)(mfree + 10) = a2; /*0x113e6a*/
    --word_1E917C[0]; /*0x113e6e*/
    ++word_1E917C[a2]; /*0x113e75*/
    mfree = *v3; /*0x113e7f*/
    *v3 = 0; /*0x113e85*/
    v3[1] = 12; /*0x113e8b*/
  }
  else
  {
    v3 = (int *)m_more(a1, a2); /*0x113e9e*/
  }
  splx(v2); /*0x113ea4*/
  if ( !v3 ) /*0x113eae*/
    return nullptr; /*0x113ec4*/
  bzero((char *)v3 + v3[1], 0x70u); /*0x113eb8*/
  return v3; /*0x113ec9*/
}
