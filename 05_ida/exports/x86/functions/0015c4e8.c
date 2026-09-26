/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15c4e8. */
_DWORD *__cdecl nextsegfromheader(int a1, int a2)
{
  int v2; // eax
  unsigned int v3; // edx
  unsigned int v4; // ecx
  unsigned int v5; // ecx
  _DWORD *result; // eax

  v2 = a1 + 28; /*0x15c4f3*/
  v3 = 0; /*0x15c4f6*/
  v4 = *(_DWORD *)(a1 + 16); /*0x15c4f8*/
  if ( v4 ) /*0x15c4fd*/
  {
    do /*0x15c50a*/
    {
      if ( v2 == a2 ) /*0x15c502*/
        break; /*0x15c502*/
      v2 += *(_DWORD *)(v2 + 4); /*0x15c504*/
      ++v3; /*0x15c507*/
    }
    while ( v3 < v4 ); /*0x15c50a*/
  }
  v5 = *(_DWORD *)(a1 + 16); /*0x15c50c*/
  if ( v3 == v5 ) /*0x15c511*/
    return nullptr; /*0x15c511*/
  result = (_DWORD *)(*(_DWORD *)(v2 + 4) + v2); /*0x15c513*/
  if ( v3 >= v5 ) /*0x15c518*/
    return nullptr; /*0x15c529*/
  while ( *result != 1 ) /*0x15c51f*/
  {
    result = (_DWORD *)((char *)result + result[1]); /*0x15c521*/
    if ( ++v3 >= v5 ) /*0x15c527*/
      return nullptr; /*0x15c527*/
  }
  return result; /*0x15c52e*/
}
