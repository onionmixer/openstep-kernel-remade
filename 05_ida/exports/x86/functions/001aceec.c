/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aceec. */
_BYTE *__cdecl sub_1ACEEC(_BYTE *a1, _BYTE *a2, int a3, int a4)
{
  _BYTE *v5; // ebx
  int v8; // esi

  v5 = a2; /*0x1acef8*/
  v8 = 0; /*0x1acf01*/
  while ( a3 && a4 ) /*0x1acf0c*/
  {
    if ( !*a1 ) /*0x1acf15*/
      goto LABEL_7; /*0x1acf15*/
    if ( *a1 == 32 ) /*0x1acf1a*/
    {
      if ( !v8 ) /*0x1acf1e*/
      {
        v8 = 1; /*0x1acf24*/
        goto LABEL_10; /*0x1acf29*/
      }
LABEL_7:
      ++a1; /*0x1acf20*/
      --a3; /*0x1acf21*/
    }
    else
    {
      v8 = 0; /*0x1acf2c*/
LABEL_10:
      *v5++ = *a1++; /*0x1acf2e*/
      --a3; /*0x1acf34*/
      --a4; /*0x1acf35*/
    }
  }
  return (_BYTE *)(v5 - a2); /*0x1acf40*/
}
