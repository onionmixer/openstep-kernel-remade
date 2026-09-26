/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x124d1c. */
int __cdecl sub_124D1C(_BYTE *a1, _BYTE *a2, int a3)
{
  char v4; // al
  int result; // eax

  while ( 1 )
  {
    v4 = a3 ? kmgetc_silent(0) : kmgetc(0);
    result = v4 & 0x7F; /*0x124d43*/
    if ( result == 13 ) /*0x124d4c*/
      break; /*0x124d4c*/
    if ( result > 13 ) /*0x124d4e*/
    {
      if ( result == 64 ) /*0x124d5f*/
        goto LABEL_21; /*0x124d5f*/
      if ( result > 64 ) /*0x124d61*/
      {
        if ( result != 127 ) /*0x124d6f*/
          goto LABEL_22; /*0x124d6f*/
        if ( a2 == a1 ) /*0x124d7e*/
        {
LABEL_17:
          cnputc(8); /*0x124d80*/
        }
        else
        {
          cnputc(8); /*0x124d86*/
          cnputc(8); /*0x124d8d*/
LABEL_19:
          if ( a2 == a1 ) /*0x124d97*/
            goto LABEL_17; /*0x124d97*/
          cnputc(32); /*0x124da2*/
          cnputc(8); /*0x124da9*/
          --a2; /*0x124dae*/
        }
      }
      else
      {
        if ( result != 21 ) /*0x124d66*/
          goto LABEL_22; /*0x124d66*/
LABEL_21:
        a2 = a1; /*0x124db8*/
        cnputc(10); /*0x124dbc*/
      }
    }
    else
    {
      if ( result == 8 ) /*0x124d53*/
        goto LABEL_19; /*0x124d53*/
      if ( result == 10 ) /*0x124d58*/
        break; /*0x124d58*/
LABEL_22:
      *a2++ = result; /*0x124dcc*/
    }
  }
  *a2 = 0; /*0x124d74*/
  return result; /*0x124dd7*/
}
