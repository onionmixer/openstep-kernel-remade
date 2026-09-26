/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1be284. */
_BYTE *__cdecl audio_resample44To22(_BYTE *a1, _WORD *a2, unsigned int a3, int a4)
{
  _BYTE *result; // eax
  int v6; // edx
  int v7; // edx

  result = a1; /*0x1be289*/
  if ( a4 == 1 ) /*0x1be29a*/
  {
LABEL_10:
    v7 = (a3 >> 1) - 1; /*0x1be2c8*/
    if ( a3 >> 1 ) /*0x1be295*/
    {
      do /*0x1be2dc*/
      {
        *(_BYTE *)a2 = *result; /*0x1be2d2*/
        a2 = (_WORD *)((char *)a2 + 1); /*0x1be2d4*/
        result += 2; /*0x1be2d5*/
        --v7; /*0x1be2d8*/
      }
      while ( v7 != -1 ); /*0x1be2dc*/
    }
    return result; /*0x1be2dc*/
  }
  if ( a4 > 1 )
  {
    if ( a4 != 3 )
      return (_BYTE *)IOLog((int)"Audio: unrecognized format %d in resample\n", a4);
    goto LABEL_10; /*0x1be2a7*/
  }
  if ( a4 )
    return (_BYTE *)IOLog((int)"Audio: unrecognized format %d in resample\n", a4);
  v6 = (a3 >> 2) - 1; /*0x1be2ae*/
  if ( a3 >> 2 ) /*0x1be2ac*/
  {
    do /*0x1be2c4*/
    {
      *a2++ = *(_WORD *)result; /*0x1be2b7*/
      result += 4; /*0x1be2bd*/
      --v6; /*0x1be2c0*/
    }
    while ( v6 != -1 ); /*0x1be2c4*/
  }
  return result; /*0x1be2ee*/
}
