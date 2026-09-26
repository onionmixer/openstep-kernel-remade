/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12f844. */
_DWORD *__cdecl rfree(_DWORD *a1)
{
  _DWORD *result; // eax
  _DWORD *v2; // edx

  --*(_DWORD *)(*(_DWORD *)(a1[12] + 296) + 24); /*0x12f854*/
  result = (_DWORD *)a1[28]; /*0x12f857*/
  if ( result ) /*0x12f85c*/
  {
    result = (_DWORD *)crfree((_WORD *)a1[28]); /*0x12f85f*/
    a1[28] = 0; /*0x12f864*/
  }
  if ( !*a1 ) /*0x12f86b*/
  {
    v2 = rpfreelist; /*0x12f870*/
    if ( rpfreelist ) /*0x12f878*/
    {
      *a1 = rpfreelist; /*0x12f884*/
      a1[1] = v2[1]; /*0x12f889*/
      result = (_DWORD *)v2[1]; /*0x12f88c*/
      *result = a1; /*0x12f88f*/
      v2[1] = a1; /*0x12f891*/
    }
    else
    {
      *a1 = a1; /*0x12f87a*/
      a1[1] = a1; /*0x12f87c*/
    }
    rpfreelist = a1; /*0x12f894*/
    ++rnfree; /*0x12f89a*/
  }
  return result; /*0x12f8a0*/
}
