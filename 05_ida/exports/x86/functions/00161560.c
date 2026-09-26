/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x161560. */
_DWORD *__cdecl pset_add_task(_DWORD *a1, _DWORD *a2)
{
  _DWORD *v2; // edx
  _DWORD *result; // eax

  v2 = (_DWORD *)a1[76]; /*0x16156b*/
  result = a1 + 75; /*0x161571*/
  if ( a1 + 75 == v2 ) /*0x161579*/
    a1[75] = a2; /*0x16157b*/
  else
    v2[4] = a2; /*0x161584*/
  a2[5] = v2; /*0x161587*/
  a2[4] = a1 + 75; /*0x161590*/
  a1[76] = a2; /*0x161593*/
  a2[11] = a1; /*0x161599*/
  ++a1[77]; /*0x16159c*/
  return result; /*0x1615a5*/
}
