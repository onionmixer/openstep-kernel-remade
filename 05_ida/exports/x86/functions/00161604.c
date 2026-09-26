/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x161604. */
_DWORD *__cdecl pset_add_thread(_DWORD *a1, _DWORD *a2)
{
  _DWORD *v2; // edx
  _DWORD *result; // eax

  v2 = (_DWORD *)a1[79]; /*0x16160f*/
  result = a1 + 78; /*0x161615*/
  if ( a1 + 78 == v2 ) /*0x16161d*/
    a1[78] = a2; /*0x16161f*/
  else
    v2[6] = a2; /*0x161628*/
  a2[7] = v2; /*0x16162b*/
  a2[6] = a1 + 78; /*0x161634*/
  a1[79] = a2; /*0x161637*/
  a2[96] = a1; /*0x16163d*/
  ++a1[80]; /*0x161643*/
  return result; /*0x16164c*/
}
