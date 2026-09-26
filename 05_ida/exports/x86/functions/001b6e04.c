/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b6e04. */
char __cdecl -[IOAudio _getValues:count:forParameter:forObject:](
        IOAudio *self,
        SEL a2,
        int *a3,
        unsigned int *a4,
        int a5,
        id a6)
{
  id v6; // eax
  id v7; // eax
  id v8; // eax
  id v9; // eax
  char v11; // [esp+Ch] [ebp-4h]

  v11 = 1; /*0x1b6e16*/
  *a4 = 0; /*0x1b6e1a*/
  v6 = -[IOAudio _inputChannel](self, sel__inputChannel); /*0x1b6e2b*/
  if ( !(unsigned __int8)objc_msgSend(a6, sel_isEqual_, v6) )
  {
    v7 = -[IOAudio _outputChannel](self, sel__outputChannel); /*0x1b6e7b*/
    if ( (unsigned __int8)objc_msgSend(a6, sel_isEqual_, v7) ) /*0x1b6e89*/
      return 0; /*0x1b6e93*/
    v8 = +[Object class](aInputstream, sel_class); /*0x1b6ea7*/
    if ( (unsigned __int8)objc_msgSend(a6, sel_isKindOf_, v8) )
    {
      if ( a5 != 400 ) /*0x1b6ec8*/
      {
        if ( a5 == 405 ) /*0x1b6ed1*/
        {
          *a4 = 1; /*0x1b6ed7*/
          *a3 = 605; /*0x1b6edd*/
          return v11; /*0x1b6ee3*/
        }
        return 0; /*0x1b6f62*/
      }
    }
    else
    {
      v9 = +[Object class](aOutputstream, sel_class); /*0x1b6ef6*/
      if ( !(unsigned __int8)objc_msgSend(a6, sel_isKindOf_, v9) )
      {
        IOLog((int)"Audio: unknown parameter object\n");
        return 0; /*0x1b6f5d*/
      }
      if ( a5 != 400 ) /*0x1b6f17*/
      {
        if ( a5 == 406 ) /*0x1b6f20*/
        {
          *a4 = 1; /*0x1b6f48*/
          *a3 = 607; /*0x1b6f4e*/
          return v11; /*0x1b6f54*/
        }
        return 0; /*0x1b6f20*/
      }
    }
    *a4 = 4; /*0x1b6f24*/
    *a3 = 600; /*0x1b6f2a*/
    a3[1] = 601; /*0x1b6f30*/
    a3[2] = 602; /*0x1b6f37*/
    a3[3] = 603; /*0x1b6f3e*/
    return v11; /*0x1b6f45*/
  }
  if ( a5 != 14 ) /*0x1b6e49*/
    return -46; /*0x1b6e64*/
  *a4 = 2; /*0x1b6e4b*/
  *a3 = 200; /*0x1b6e51*/
  a3[1] = 201; /*0x1b6e57*/
  return v11; /*0x1b6f6d*/
}
