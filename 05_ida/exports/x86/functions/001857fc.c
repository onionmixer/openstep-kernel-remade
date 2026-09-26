/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1857fc. */
_UNKNOWN **__cdecl sub_1857FC(void *a1)
{
  _UNKNOWN **result; // eax
  _DWORD *v2; // ecx
  _UNKNOWN **v3; // edx

  result = (_UNKNOWN **)off_1E1404; /*0x185802*/
  if ( off_1E1404 == (_UNKNOWN *)&off_1E1404 ) /*0x18580c*/
    return nullptr; /*0x185855*/
  while ( result[2] != a1 ) /*0x185813*/
  {
    result = (_UNKNOWN **)*result; /*0x18584c*/
    if ( result == &off_1E1404 ) /*0x185853*/
      return nullptr; /*0x185853*/
  }
  v2 = *result; /*0x185815*/
  v3 = (_UNKNOWN **)result[1]; /*0x185817*/
  if ( *result == (_UNKNOWN *)&off_1E1404 ) /*0x185820*/
    off_1E1408 = (_UNKNOWN **)result[1]; /*0x185822*/
  else
    v2[1] = v3; /*0x18582c*/
  if ( v3 == &off_1E1404 ) /*0x185835*/
    off_1E1404 = v2; /*0x185840*/
  else
    *v3 = v2; /*0x185837*/
  return result; /*0x18583b*/
}
