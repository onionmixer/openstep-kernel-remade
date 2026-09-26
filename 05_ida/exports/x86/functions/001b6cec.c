/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b6cec. */
void __cdecl -[IOAudio _getSupportedParameters:count:forObject:](
        IOAudio *self,
        SEL a2,
        int *a3,
        unsigned int *a4,
        id a5)
{
  _DWORD *v5; // ebx
  id v6; // eax
  id v7; // eax
  id v8; // eax
  id v9; // eax
  unsigned int i; // eax

  v5 = nullptr; /*0x1b6cf8*/
  *a4 = 0; /*0x1b6cfa*/
  v6 = -[IOAudio _inputChannel](self, sel__inputChannel); /*0x1b6d0b*/
  if ( (unsigned __int8)objc_msgSend(a5, sel_isEqual_, v6) )
  {
    v5 = &unk_1D5E10; /*0x1b6d25*/
    *a4 = 7; /*0x1b6d2a*/
  }
  else
  {
    v7 = -[IOAudio _outputChannel](self, sel__outputChannel); /*0x1b6d43*/
    if ( (unsigned __int8)objc_msgSend(a5, sel_isEqual_, v7) )
    {
      v5 = &unk_1D5DD8; /*0x1b6d5d*/
      *a4 = 14; /*0x1b6d62*/
    }
    else
    {
      v8 = +[Object class](aInputstream, sel_class); /*0x1b6d7a*/
      if ( (unsigned __int8)objc_msgSend(a5, sel_isKindOf_, v8) )
      {
        v5 = &unk_1D5E54; /*0x1b6d94*/
        *a4 = 6; /*0x1b6d99*/
      }
      else
      {
        v9 = +[Object class](aOutputstream, sel_class); /*0x1b6db2*/
        if ( (unsigned __int8)objc_msgSend(a5, sel_isKindOf_, v9) )
        {
          v5 = &unk_1D5E2C; /*0x1b6dcc*/
          *a4 = 10; /*0x1b6dd1*/
        }
        else
        {
          IOLog((int)"Audio: unknown parameter object\n");
        }
      }
    }
  }
  for ( i = 0; *a4 > i; ++i ) /*0x1b6de8*/
    a3[i] = v5[i]; /*0x1b6df2*/
}
