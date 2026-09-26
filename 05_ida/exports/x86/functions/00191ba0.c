/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x191ba0. */
int __cdecl getfsname(const char *a1, _BYTE *a2)
{
  int result; // eax
  _BYTE *v3; // ebx

  result = (int)a1; /*0x191ba5*/
  if ( (boothowto & 1) != 0 )
  {
    printf("%s key [%s]: ", a1, a1);
    v3 = a2; /*0x191bc4*/
    while ( 1 ) /*0x191beb*/
    {
      while ( 1 ) /*0x191bd9*/
      {
        while ( 1 ) /*0x191bd1*/
        {
          result = cngetc() & 0x7F; /*0x191bd1*/
          if ( result == 13 ) /*0x191bd7*/
          {
LABEL_14:
            *v3 = 0; /*0x191c00*/
            return result; /*0x191c03*/
          }
          if ( result > 13 ) /*0x191bd9*/
            break; /*0x191bd9*/
          if ( result == 8 ) /*0x191bde*/
            goto LABEL_18; /*0x191bde*/
          if ( result == 10 ) /*0x191be3*/
            goto LABEL_14; /*0x191be3*/
LABEL_21:
          *v3++ = result; /*0x191c54*/
        }
        if ( result != 64 ) /*0x191beb*/
          break; /*0x191beb*/
LABEL_20:
        v3 = a2; /*0x191c40*/
        cnputc(10); /*0x191c44*/
      }
      if ( result <= 64 ) /*0x191bed*/
      {
        if ( result != 21 ) /*0x191bf2*/
          goto LABEL_21; /*0x191bf2*/
        goto LABEL_20; /*0x191bf2*/
      }
      if ( result != 127 ) /*0x191bfb*/
        goto LABEL_21; /*0x191bfb*/
      if ( v3 == a2 ) /*0x191c0a*/
      {
LABEL_16:
        cnputc(8); /*0x191c0c*/
      }
      else
      {
        cnputc(8); /*0x191c12*/
        cnputc(8); /*0x191c19*/
LABEL_18:
        if ( v3 == a2 ) /*0x191c23*/
          goto LABEL_16; /*0x191c23*/
        cnputc(32); /*0x191c2e*/
        cnputc(8); /*0x191c35*/
        --v3; /*0x191c3a*/
      }
    }
  }
  return result; /*0x191c5f*/
}
