/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11807c. */
int __cdecl sockargs(int *a1, int a2, int a3, int a4)
{
  int *v5; // eax
  int v6; // ebx
  int v7; // esi

  if ( a3 > 112 ) /*0x11808b*/
    return 22; /*0x11808d*/
  v5 = m_get(1, a4); /*0x11809a*/
  v6 = (int)v5; /*0x11809f*/
  if ( !v5 ) /*0x1180a6*/
    return 55; /*0x1180a8*/
  *((_WORD *)v5 + 4) = a3; /*0x1180b0*/
  v7 = copyin(a2, (char *)v5 + v5[1], a3); /*0x1180c4*/
  if ( v7 ) /*0x1180cb*/
    m_free(v6); /*0x1180ce*/
  else
    *a1 = v6; /*0x1180d8*/
  return v7; /*0x1180df*/
}
