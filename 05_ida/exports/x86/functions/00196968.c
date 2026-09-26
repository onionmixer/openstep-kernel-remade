/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x196968. */
int __cdecl -[kmDevice dumpMsgBuf](kmDevice *self, SEL a2)
{
  int fbMode; // eax
  char *v3; // ebx

  fbMode = self->fbMode; /*0x196970*/
  if ( (fbMode == 1 || fbMode == 3) && *(_DWORD *)pmsgbuf == 405601 ) /*0x19698c*/
  {
    v3 = (char *)(*(_DWORD *)(pmsgbuf + 4) + 12 + pmsgbuf); /*0x196994*/
    do /*0x1969e6*/
    {
      if ( *v3 ) /*0x196998*/
      {
        if ( *v3 == 10 ) /*0x1969a0*/
          -[kmDevice kmPutc:](self, sel_kmPutc_, 13); /*0x1969ac*/
        -[kmDevice kmPutc:](self, sel_kmPutc_, *v3); /*0x1969c0*/
      }
      if ( (unsigned int)++v3 >= pmsgbuf + 4096 ) /*0x1969d7*/
        v3 = (char *)(pmsgbuf + 12); /*0x1969d9*/
    }
    while ( v3 != (char *)(pmsgbuf + *(_DWORD *)(pmsgbuf + 4) + 12) ); /*0x1969e6*/
  }
  return 0; /*0x1969ed*/
}
