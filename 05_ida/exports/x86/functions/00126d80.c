/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x126d80. */
int *ip_srcroute()
{
  int *v0; // esi
  int v2; // eax
  int *v3; // ebx
  _DWORD *i; // eax

  if ( !ip_nhops ) /*0x126d8c*/
    return nullptr; /*0x126d8c*/
  v0 = m_get(0, 10); /*0x126d97*/
  if ( !v0 ) /*0x126d9e*/
    return nullptr; /*0x126da0*/
  v2 = ip_nhops; /*0x126daa*/
  *((_WORD *)v0 + 4) = 4 * ip_nhops + 4; /*0x126db7*/
  *(int *)((char *)v0 + v0[1]) = dword_1E5908[v2]; /*0x126dc4*/
  v3 = (int *)((char *)&unk_1E5904 + v2 * 4); /*0x126dc7*/
  LOBYTE(dword_1E5908[0]) = 1; /*0x126dcd*/
  bcopy(dword_1E5908, (char *)v0 + v0[1] + 4, 4u); /*0x126de4*/
  for ( i = (int *)((char *)v0 + v0[1] + 8); v3 >= dword_1E590C; ++i ) /*0x126df7*/
    *i = *v3--; /*0x126dfe*/
  return v0; /*0x126e13*/
}
