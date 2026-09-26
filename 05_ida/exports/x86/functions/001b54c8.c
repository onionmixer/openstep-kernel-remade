/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b54c8. */
char __cdecl -[IOAudio _setParameter:toInt:forObject:](IOAudio *self, SEL a2, int a3, int a4, id a5)
{
  id v5; // eax
  id v6; // eax
  id v7; // eax
  id v8; // eax
  int v10; // [esp-10h] [ebp-20h]
  int v11; // [esp-10h] [ebp-20h]
  int v12; // [esp-4h] [ebp-14h]
  char v13; // [esp+Ch] [ebp-4h]

  v13 = 1; /*0x1b54da*/
  v5 = -[IOAudio _inputChannel](self, sel__inputChannel); /*0x1b54e6*/
  if ( (unsigned __int8)objc_msgSend(a5, sel_isEqual_, v5) )
  {
    switch ( a3 ) /*0x1b5511*/
    {
      case 0: /*0x1b5511*/
      case 1: /*0x1b5511*/
        return v13;
      case 2: /*0x1b5511*/
        goto LABEL_3;
      case 14: /*0x1b5511*/
        -[IOAudio _setAnalogInputSource:](self, sel__setAnalogInputSource_, v10); /*0x1b55ef*/
        break; /*0x1b55ef*/
      case 16: /*0x1b5511*/
        -[IOAudio _setInputGainLeft:](self, sel__setInputGainLeft_, a4); /*0x1b55bd*/
        -[IOAudio _setInputGainRight:](self, sel__setInputGainRight_, a4); /*0x1b55c9*/
        break; /*0x1b55c9*/
      case 17: /*0x1b5511*/
        -[IOAudio _setInputGainLeft:](self, sel__setInputGainLeft_, v10); /*0x1b55d7*/
        break; /*0x1b55d7*/
      case 18: /*0x1b5511*/
        -[IOAudio _setInputGainRight:](self, sel__setInputGainRight_, v10); /*0x1b55e3*/
        break; /*0x1b55e3*/
      case 30: /*0x1b5511*/
      case 31: /*0x1b5511*/
      case 32: /*0x1b5511*/
      case 33: /*0x1b5511*/
      case 34: /*0x1b5511*/
        -[IOAudio _setInputFor:to:](self, sel__setInputFor_to_, a3, (char)a4); /*0x1b5602*/
        break; /*0x1b5602*/
      default:
        return 0;
    }
  }
  else
  {
    v6 = -[IOAudio _outputChannel](self, sel__outputChannel); /*0x1b5610*/
    if ( (unsigned __int8)objc_msgSend(a5, sel_isEqual_, v6) )
    {
      switch ( a3 ) /*0x1b563b*/
      {
        case 0: /*0x1b563b*/
        case 1: /*0x1b563b*/
        case 3: /*0x1b563b*/
        case 4: /*0x1b563b*/
        case 5: /*0x1b563b*/
        case 6: /*0x1b563b*/
          return v13;
        case 2: /*0x1b563b*/
LABEL_3:
          objc_msgSend(a5, sel_setDetectPeaks_, (char)a4); /*0x1b55a4*/
          return v13; /*0x1b55ae*/
        case 7: /*0x1b563b*/
        case 8: /*0x1b563b*/
        case 9: /*0x1b563b*/
          -[IOAudio _setOutputMute:](self, sel__setOutputMute_, v11); /*0x1b56d6*/
          return v13; /*0x1b56d6*/
        case 10: /*0x1b563b*/
          -[IOAudio _setLoudnessEnhanced:](self, sel__setLoudnessEnhanced_, v11); /*0x1b56e2*/
          return v13; /*0x1b56e2*/
        case 11: /*0x1b563b*/
          -[IOAudio _setOutputAttenuationLeft:](self, sel__setOutputAttenuationLeft_, a4); /*0x1b56ed*/
          goto LABEL_15; /*0x1b56f2*/
        case 12: /*0x1b563b*/
          -[IOAudio _setOutputAttenuationLeft:](self, sel__setOutputAttenuationLeft_, v11); /*0x1b56fb*/
          return v13; /*0x1b56fb*/
        case 13: /*0x1b563b*/
LABEL_15:
          -[IOAudio _setOutputAttenuationRight:](self, sel__setOutputAttenuationRight_, a4); /*0x1b5700*/
          break; /*0x1b5709*/
        case 25: /*0x1b563b*/
        case 26: /*0x1b563b*/
        case 27: /*0x1b563b*/
        case 28: /*0x1b563b*/
        case 29: /*0x1b563b*/
          -[IOAudio _setOutputFor:to:](self, sel__setOutputFor_to_, a3, (char)a4); /*0x1b5724*/
          break; /*0x1b5724*/
        default:
          return 0;
      }
    }
    else
    {
      v7 = +[Object class](aInputstream, sel_class); /*0x1b573e*/
      if ( (unsigned __int8)objc_msgSend(a5, sel_isKindOf_, v7) )
      {
        switch ( a3 ) /*0x1b576d*/
        {
          case 400: /*0x1b576d*/
            goto LABEL_21;
          case 401: /*0x1b576d*/
            goto LABEL_22;
          case 402: /*0x1b576d*/
            goto LABEL_23;
          case 403: /*0x1b576d*/
            goto LABEL_24;
          case 404: /*0x1b576d*/
            goto LABEL_25;
          case 405: /*0x1b576d*/
            if ( a4 != 605 ) /*0x1b57ce*/
              return 0; /*0x1b57ce*/
            break; /*0x1b57ce*/
          default:
            return 0;
        }
      }
      else
      {
        v8 = +[Object class](aOutputstream, sel_class); /*0x1b57ea*/
        if ( (unsigned __int8)objc_msgSend(a5, sel_isKindOf_, v8) )
        {
          switch ( a3 ) /*0x1b5819*/
          {
            case 400: /*0x1b5819*/
LABEL_21:
              objc_msgSend(a5, sel_setDataEncoding_, a4); /*0x1b578c*/
              return v13; /*0x1b5793*/
            case 401: /*0x1b5819*/
LABEL_22:
              objc_msgSend(a5, sel_setSamplingRate_, a4); /*0x1b5798*/
              return v13; /*0x1b579f*/
            case 402: /*0x1b5819*/
LABEL_23:
              objc_msgSend(a5, sel_setChannelCount_, a4); /*0x1b57a4*/
              return v13; /*0x1b57ab*/
            case 403: /*0x1b5819*/
LABEL_24:
              objc_msgSend(a5, sel_setHighWaterMark_, a4); /*0x1b57b0*/
              return v13; /*0x1b57b7*/
            case 404: /*0x1b5819*/
LABEL_25:
              objc_msgSend(a5, sel_setLowWaterMark_, a4); /*0x1b57bc*/
              return v13; /*0x1b57c3*/
            case 406: /*0x1b5819*/
              if ( a4 != 607 ) /*0x1b588e*/
                return 0; /*0x1b588e*/
              return v13; /*0x1b588e*/
            case 407: /*0x1b5819*/
              objc_msgSend(a5, sel_setDetectPeaks_, (char)a4); /*0x1b589e*/
              return v13; /*0x1b589e*/
            case 408: /*0x1b5819*/
              objc_msgSend(a5, sel_setGainLeft_, a4); /*0x1b58a9*/
              goto LABEL_35; /*0x1b58ae*/
            case 409: /*0x1b5819*/
              objc_msgSend(a5, sel_setGainLeft_, a4); /*0x1b58b7*/
              return v13; /*0x1b58b7*/
            case 410: /*0x1b5819*/
LABEL_35:
              objc_msgSend(a5, sel_setGainRight_, v12); /*0x1b58bc*/
              break; /*0x1b58c5*/
            default:
              return 0;
          }
        }
        else
        {
          IOLog("Audio: unknown parameter object\n");
          return 0; /*0x1b58d6*/
        }
      }
    }
  }
  return v13; /*0x1b58e1*/
}
