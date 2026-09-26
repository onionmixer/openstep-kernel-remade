/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x161654. */
_DWORD *__cdecl thread_change_psets(_DWORD *a1, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // edx
  _DWORD *v4; // edx
  _DWORD *result; // eax
  _DWORD *v6; // [esp+Ch] [ebp-4h]

  v6 = (_DWORD *)a1[6]; /*0x161669*/
  v3 = (_DWORD *)a1[7]; /*0x16166c*/
  if ( a2 + 78 == v6 ) /*0x161677*/
    a2[79] = v3; /*0x161679*/
  else
    v6[7] = v3; /*0x161687*/
  if ( a2 + 78 == v3 ) /*0x161692*/
    a2[78] = v6; /*0x161697*/
  else
    v3[6] = v6; /*0x1616a3*/
  --a2[80]; /*0x1616a6*/
  v4 = (_DWORD *)a3[79]; /*0x1616ac*/
  result = a3 + 78; /*0x1616b2*/
  if ( a3 + 78 == v4 ) /*0x1616ba*/
    a3[78] = a1; /*0x1616bc*/
  else
    v4[6] = a1; /*0x1616c4*/
  a1[7] = v4; /*0x1616c7*/
  a1[6] = a3 + 78; /*0x1616d0*/
  a3[79] = a1; /*0x1616d3*/
  a1[96] = a3; /*0x1616d9*/
  ++a3[80]; /*0x1616df*/
  return result; /*0x1616e8*/
}
