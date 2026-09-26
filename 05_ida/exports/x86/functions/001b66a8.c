/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b66a8. */
void __cdecl -[IOAudio _keyOccurred:event:flags:](IOAudio *self, SEL a2, int a3, int a4, int a5)
{
  char v5; // cl
  int v6; // ebx
  int v7; // ebx
  _BOOL4 v8; // [esp-4h] [ebp-1Ch]
  int v9; // [esp-4h] [ebp-1Ch]
  int v10; // [esp-4h] [ebp-1Ch]
  char v11; // [esp+10h] [ebp-8h]
  bool v12; // [esp+14h] [ebp-4h]

  v12 = 0; /*0x1b66ba*/
  v11 = 0; /*0x1b66be*/
  v5 = 0; /*0x1b66c2*/
  if ( a4 == 10 ) /*0x1b66c8*/
  {
    if ( a3 ) /*0x1b66d0*/
    {
      if ( a3 == 1 ) /*0x1b66e3*/
      {
        if ( (a5 & 0x100000) != 0 ) /*0x1b66ea*/
          v5 = 1; /*0x1b66ec*/
        else
          v11 = 1; /*0x1b66f0*/
      }
    }
    else
    {
      v12 = (a5 & 0x100000) == 0; /*0x1b66d9*/
    }
    if ( (a5 & 0x20000) != 0 ) /*0x1b66f9*/
    {
      v7 = -[IOAudio inputGainLeft](self, sel_inputGainLeft); /*0x1b67ad*/
      -[IOAudio inputGainRight](self, sel_inputGainRight); /*0x1b67b7*/
      if ( v12 ) /*0x1b67c3*/
      {
        v7 += 1638; /*0x1b67c5*/
        if ( v7 > 0x7FFF ) /*0x1b67d1*/
          v7 = 0x8000; /*0x1b67d3*/
      }
      else if ( v11 ) /*0x1b67f0*/
      {
        v7 -= 1638; /*0x1b67f2*/
        if ( v7 <= 0 ) /*0x1b67fa*/
          v7 = 0; /*0x1b67fc*/
      }
      -[IOAudio _setInputGainLeft:](self, sel__setInputGainLeft_, v7); /*0x1b6815*/
      -[IOAudio _setInputGainRight:](self, sel__setInputGainRight_, v10); /*0x1b6826*/
    }
    else if ( v5 ) /*0x1b6701*/
    {
      v8 = -[IOAudio isOutputMuted](self, sel_isOutputMuted) == 0; /*0x1b671d*/
      -[IOAudio _setOutputMute:](self, sel__setOutputMute_, v8); /*0x1b6724*/
    }
    else
    {
      v6 = -[IOAudio outputAttenuationLeft](self, sel_outputAttenuationLeft); /*0x1b6739*/
      -[IOAudio outputAttenuationRight](self, sel_outputAttenuationRight); /*0x1b6743*/
      if ( v12 ) /*0x1b674f*/
      {
        if ( ++v6 > 0 ) /*0x1b6754*/
          v6 = 0; /*0x1b6756*/
      }
      else if ( v11 ) /*0x1b6768*/
      {
        if ( --v6 < -84 ) /*0x1b676e*/
          v6 = -84; /*0x1b6770*/
      }
      -[IOAudio _setOutputAttenuationLeft:](self, sel__setOutputAttenuationLeft_, v6); /*0x1b678c*/
      -[IOAudio _setOutputAttenuationRight:](self, sel__setOutputAttenuationRight_, v9); /*0x1b679b*/
    }
  }
}
