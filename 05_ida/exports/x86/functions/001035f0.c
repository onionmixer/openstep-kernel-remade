/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1035f0. */
_DWORD *__cdecl gatherstats(int a1, __int16 a2)
{
  int v2; // edx
  signed int v3; // edx
  int v4; // ecx
  _DWORD *result; // eax

  if ( (a2 & 3) == 3 ) /*0x1035fe*/
  {
    v2 = *(_BYTE *)(*(_DWORD *)active_u + 21) > 0; /*0x10360f*/
  }
  else
  {
    v2 = 2; /*0x103614*/
    if ( *(char *)(active_threads + 76) < 0 && !HIBYTE(a2) ) /*0x103627*/
      v2 = 3; /*0x103629*/
  }
  ++cp_time[v2]; /*0x10362e*/
  v3 = 0; /*0x103635*/
  v4 = dk_busy; /*0x103637*/
  result = &dk_time; /*0x10363d*/
  do /*0x103652*/
  {
    if ( _bittest(&v4, v3) ) /*0x103644*/
      ++*result; /*0x103649*/
    ++result; /*0x10364b*/
    ++v3; /*0x10364e*/
  }
  while ( v3 <= 3 ); /*0x103652*/
  return result; /*0x103656*/
}
