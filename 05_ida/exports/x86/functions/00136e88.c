/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x136e88. */
int __cdecl sub_136E88(int a1, int a2, _DWORD *a3)
{
  __int64 v3; // rax

  v3 = (unsigned int)dword_1E5A1C; /*0x136e98*/
  if ( dword_1E5A1C ) /*0x136e9f*/
  {
    do /*0x136eb4*/
    {
      if ( *(_DWORD *)(v3 + 4) == a1 && *(_DWORD *)(v3 + 8) == a2 ) /*0x136eac*/
        break; /*0x136eac*/
      HIDWORD(v3) = v3; /*0x136eae*/
      LODWORD(v3) = *(_DWORD *)v3; /*0x136eb0*/
    }
    while ( (_DWORD)v3 ); /*0x136eb4*/
  }
  *a3 = HIDWORD(v3); /*0x136eb6*/
  return v3; /*0x136ebb*/
}
