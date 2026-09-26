/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1615ac. */
_DWORD *__cdecl pset_remove_thread(_DWORD *a1, _DWORD *a2)
{
  _DWORD *v2; // ecx
  _DWORD *v3; // edx
  _DWORD *result; // eax

  v2 = (_DWORD *)a2[6]; /*0x1615b7*/
  v3 = (_DWORD *)a2[7]; /*0x1615ba*/
  if ( a1 + 78 == v2 ) /*0x1615c5*/
    a1[79] = v3; /*0x1615c7*/
  else
    v2[7] = v3; /*0x1615d0*/
  result = a1 + 78; /*0x1615d3*/
  if ( a1 + 78 == v3 ) /*0x1615db*/
    a1[78] = v2; /*0x1615dd*/
  else
    v3[6] = v2; /*0x1615e8*/
  a2[96] = 0; /*0x1615eb*/
  --a1[80]; /*0x1615f5*/
  return result; /*0x1615fe*/
}
