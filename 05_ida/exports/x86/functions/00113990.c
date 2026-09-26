/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x113990. */
__int16 *__cdecl pffindtype(int a1, int a2)
{
  _DWORD *v2; // eax
  __int16 *v4; // edx
  unsigned int v5; // eax

  v2 = (_DWORD *)domains; /*0x11399a*/
  if ( !domains ) /*0x1139a1*/
    return nullptr; /*0x1139a1*/
  while ( *v2 != a1 ) /*0x1139a6*/
  {
    v2 = (_DWORD *)v2[7]; /*0x1139a8*/
    if ( !v2 ) /*0x1139ad*/
      return nullptr; /*0x1139ad*/
  }
  v4 = (__int16 *)v2[5]; /*0x1139b8*/
  v5 = v2[6]; /*0x1139bb*/
  if ( (unsigned int)v4 >= v5 ) /*0x1139c0*/
    return nullptr; /*0x1139d8*/
  while ( !*v4 || *v4 != a2 ) /*0x1139cf*/
  {
    v4 += 24; /*0x1139d1*/
    if ( (unsigned int)v4 >= v5 ) /*0x1139d6*/
      return nullptr; /*0x1139d6*/
  }
  return v4; /*0x1139da*/
}
