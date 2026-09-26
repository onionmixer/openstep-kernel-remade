/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1601d0. */
int __cdecl miniMonLoop(int a1, int a2, int a3)
{
  int v3; // eax
  char *v4; // ebx
  int v5; // esi
  int v6; // eax
  int result; // eax

  miniMonState = a3; /*0x1601dc*/
  if ( a2 ) /*0x1601e4*/
  {
    safe_prf(aSystemPanic_0); /*0x1601eb*/
    safe_prf(aS_3); /*0x1601fc*/
    safe_prf(aTypeRToRebootO); /*0x160209*/
    do /*0x16023b*/
    {
      while ( 1 ) /*0x160214*/
      {
        v3 = miniMonTryGetchar(); /*0x160214*/
        if ( v3 != 114 ) /*0x16021c*/
          break; /*0x16021c*/
        safe_prf(aRebooting); /*0x160223*/
        miniMonReboot(&unk_1DF173); /*0x16022d*/
      }
    }
    while ( v3 != 109 ); /*0x16023b*/
    safe_prf(asc_1DF174); /*0x160242*/
  }
  safe_prf(aNextstepMiniMo); /*0x16024f*/
  do /*0x16030f*/
  {
    safe_prf(aS_4); /*0x160265*/
    v4 = byte_1E5DC4; /*0x16026a*/
    v5 = 127; /*0x160272*/
    while ( 1 ) /*0x160278*/
    {
      v6 = miniMonGetchar(); /*0x160278*/
      if ( v6 == 10 ) /*0x160280*/
        break; /*0x160280*/
      if ( v6 > 10 ) /*0x160282*/
      {
        if ( v6 == 13 ) /*0x16028f*/
        {
          miniMonPutchar(10); /*0x16029a*/
          break; /*0x16029a*/
        }
        if ( v6 == 21 ) /*0x160294*/
        {
          v4 = byte_1E5DC4; /*0x1602c4*/
          miniMonPutchar(10); /*0x1602c8*/
        }
        else
        {
LABEL_21:
          if ( v5 ) /*0x1602d6*/
          {
            *v4++ = v6; /*0x1602d8*/
            --v5; /*0x1602db*/
          }
          else
          {
            miniMonPutchar(8); /*0x1602e2*/
            miniMonPutchar(32); /*0x1602e9*/
            miniMonPutchar(8); /*0x1602f0*/
          }
        }
      }
      else
      {
        if ( v6 != 8 ) /*0x160287*/
          goto LABEL_21; /*0x160287*/
        miniMonPutchar(32); /*0x1602aa*/
        if ( v4 != byte_1E5DC4 ) /*0x1602b4*/
        {
          miniMonPutchar(8); /*0x1602b8*/
          --v4; /*0x1602bd*/
          ++v5; /*0x1602be*/
        }
      }
    }
    *v4 = 0; /*0x1602a2*/
    result = sub_1600CC(byte_1E5DC4); /*0x160305*/
  }
  while ( result ); /*0x16030f*/
  return result; /*0x160318*/
}
