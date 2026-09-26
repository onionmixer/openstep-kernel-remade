/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1be2f4. */
_BYTE *__cdecl audio_convertMonoToStereo(_BYTE *a1, _BYTE *a2, unsigned int a3, int a4)
{
  _BYTE *result; // eax
  int v6; // edx
  _WORD *v7; // eax
  unsigned int v8; // edx
  _BYTE *v9; // eax

  result = a2; /*0x1be2fc*/
  if ( a4 == 1 ) /*0x1be308*/
  {
LABEL_10:
    v8 = a3 - 1; /*0x1be344*/
    if ( a3 ) /*0x1be348*/
    {
      do /*0x1be35b*/
      {
        *result = *a1; /*0x1be34e*/
        v9 = result + 1; /*0x1be350*/
        *v9 = *a1++; /*0x1be353*/
        result = v9 + 1; /*0x1be356*/
        --v8; /*0x1be357*/
      }
      while ( v8 != -1 ); /*0x1be35b*/
    }
    return result; /*0x1be35b*/
  }
  if ( a4 > 1 )
  {
    if ( a4 != 3 )
      return (_BYTE *)IOLog((int)"Audio: unrecognized format %d in convMono\n", a4);
    goto LABEL_10; /*0x1be317*/
  }
  if ( a4 )
    return (_BYTE *)IOLog((int)"Audio: unrecognized format %d in convMono\n", a4);
  v6 = (a3 >> 1) - 1; /*0x1be31e*/
  if ( a3 >> 1 ) /*0x1be31c*/
  {
    do /*0x1be33d*/
    {
      *(_WORD *)result = *(_WORD *)a1; /*0x1be327*/
      v7 = result + 2; /*0x1be32a*/
      *v7 = *(_WORD *)a1; /*0x1be330*/
      a1 += 2; /*0x1be333*/
      result = v7 + 1; /*0x1be336*/
      --v6; /*0x1be339*/
    }
    while ( v6 != -1 ); /*0x1be33d*/
  }
  return result; /*0x1be36e*/
}
