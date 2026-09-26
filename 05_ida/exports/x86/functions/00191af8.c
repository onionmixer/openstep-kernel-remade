/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x191af8. */
char *__cdecl gets(char *a1)
{
  char *v1; // ebx
  char *result; // eax
  char *v3; // [esp+14h] [ebp+Ch]

  v1 = v3; /*0x191b00*/
  while ( 1 ) /*0x191b09*/
  {
    result = (char *)(cngetc() & 0x7F); /*0x191b09*/
    if ( result == (char *)13 ) /*0x191b0f*/
      break; /*0x191b0f*/
    if ( (int)result > 13 ) /*0x191b11*/
    {
      if ( result == (char *)64 ) /*0x191b23*/
        goto LABEL_19; /*0x191b23*/
      if ( (int)result > 64 ) /*0x191b25*/
      {
        if ( result != (char *)127 ) /*0x191b33*/
          goto LABEL_20; /*0x191b33*/
        if ( v1 == a1 ) /*0x191b42*/
        {
LABEL_15:
          cnputc(8); /*0x191b44*/
        }
        else
        {
          cnputc(8); /*0x191b4a*/
          cnputc(8); /*0x191b51*/
LABEL_17:
          if ( v1 == a1 ) /*0x191b5b*/
            goto LABEL_15; /*0x191b5b*/
          cnputc(32); /*0x191b66*/
          cnputc(8); /*0x191b6d*/
          --v1; /*0x191b72*/
        }
      }
      else
      {
        if ( result != (char *)21 ) /*0x191b2a*/
          goto LABEL_20; /*0x191b2a*/
LABEL_19:
        v1 = a1; /*0x191b78*/
        cnputc(10); /*0x191b7c*/
      }
    }
    else
    {
      if ( result == (char *)8 ) /*0x191b16*/
        goto LABEL_17; /*0x191b16*/
      if ( result == (char *)10 ) /*0x191b1b*/
        break; /*0x191b1b*/
LABEL_20:
      *v1++ = (char)result; /*0x191b8c*/
    }
  }
  *v1 = 0; /*0x191b38*/
  return result; /*0x191b97*/
}
