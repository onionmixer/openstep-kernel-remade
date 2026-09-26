/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x161504. */
_DWORD *__cdecl pset_remove_task(_DWORD *a1, _DWORD *a2)
{
  _DWORD *v2; // ecx
  _DWORD *v3; // edx
  _DWORD *result; // eax

  if ( (_DWORD *)a2[11] == a1 ) /*0x161512*/
  {
    v2 = (_DWORD *)a2[4]; /*0x161514*/
    v3 = (_DWORD *)a2[5]; /*0x161517*/
    if ( a1 + 75 == v2 ) /*0x161522*/
      a1[76] = v3; /*0x161524*/
    else
      v2[5] = v3; /*0x16152c*/
    result = a1 + 75; /*0x16152f*/
    if ( a1 + 75 == v3 ) /*0x161537*/
      a1[75] = v2; /*0x161539*/
    else
      v3[4] = v2; /*0x161544*/
    a2[11] = 0; /*0x161547*/
    --a1[77]; /*0x16154e*/
  }
  return result; /*0x161557*/
}
