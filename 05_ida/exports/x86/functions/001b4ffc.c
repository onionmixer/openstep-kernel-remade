/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b4ffc. */
int __cdecl -[IOAudio _intValueForParameter:forObject:](IOAudio *self, SEL a2, int a3, id a4)
{
  int v4; // ebx
  id v5; // eax
  const char *v6; // ecx
  id v7; // eax
  id v8; // ebx
  id v9; // eax
  id v10; // eax
  id v12; // ebx
  id v13; // eax
  id v14; // eax

  v4 = 0; /*0x1b5008*/
  v5 = -[IOAudio _inputChannel](self, sel__inputChannel); /*0x1b5012*/
  if ( (unsigned __int8)objc_msgSend(a4, sel_isEqual_, v5) )
  {
    switch ( a3 ) /*0x1b503d*/
    {
      case 0: /*0x1b503d*/
        v6 = sel_descriptorSize; /*0x1b50d0*/
        goto LABEL_51; /*0x1b50d6*/
      case 1: /*0x1b503d*/
        v6 = sel_dmaCount; /*0x1b50dc*/
        goto LABEL_51; /*0x1b50e2*/
      case 2: /*0x1b503d*/
        return (char)objc_msgSend(a4, sel_isDetectingPeaks);
      case 14: /*0x1b503d*/
        v7 = -[IOAudio _analogInputSource](self, sel__analogInputSource); /*0x1b50f0*/
        goto LABEL_52; /*0x1b50f0*/
      case 16: /*0x1b503d*/
        v8 = -[IOAudio inputGainLeft](self, sel_inputGainLeft); /*0x1b5105*/
        v9 = -[IOAudio inputGainRight](self, sel_inputGainRight); /*0x1b510f*/
        return ((unsigned int)v9 + (unsigned int)v8) >> 1; /*0x1b510f*/
      case 17: /*0x1b503d*/
        v7 = -[IOAudio inputGainLeft](self, sel_inputGainLeft); /*0x1b511c*/
        goto LABEL_52; /*0x1b511c*/
      case 18: /*0x1b503d*/
        v7 = -[IOAudio inputGainRight](self, sel_inputGainRight); /*0x1b512c*/
        goto LABEL_52; /*0x1b512c*/
      case 30: /*0x1b503d*/
        v4 = *((char *)self->_audioPrivate + 16); /*0x1b513a*/
        break; /*0x1b513e*/
      case 31: /*0x1b503d*/
        v4 = *((char *)self->_audioPrivate + 17); /*0x1b514a*/
        break; /*0x1b514e*/
      case 32: /*0x1b503d*/
        v4 = *((char *)self->_audioPrivate + 18); /*0x1b515a*/
        break; /*0x1b515e*/
      case 33: /*0x1b503d*/
        v4 = *((char *)self->_audioPrivate + 19); /*0x1b516a*/
        break; /*0x1b516e*/
      case 34: /*0x1b503d*/
        v4 = *((char *)self->_audioPrivate + 20); /*0x1b517a*/
        break; /*0x1b517e*/
      default:
        return v4;
    }
  }
  else
  {
    v10 = -[IOAudio _outputChannel](self, sel__outputChannel); /*0x1b518c*/
    if ( (unsigned __int8)objc_msgSend(a4, sel_isEqual_, v10) )
    {
      switch ( a3 ) /*0x1b51b7*/
      {
        case 0: /*0x1b51b7*/
          v6 = sel_descriptorSize; /*0x1b5238*/
          goto LABEL_51; /*0x1b523e*/
        case 1: /*0x1b51b7*/
          v6 = sel_dmaCount; /*0x1b5244*/
          goto LABEL_51; /*0x1b524a*/
        case 2: /*0x1b51b7*/
          return (char)objc_msgSend(a4, sel_isDetectingPeaks);
        case 3: /*0x1b51b7*/
        case 4: /*0x1b51b7*/
        case 5: /*0x1b51b7*/
        case 6: /*0x1b51b7*/
          v4 = 0; /*0x1b5250*/
          break; /*0x1b5252*/
        case 7: /*0x1b51b7*/
        case 8: /*0x1b51b7*/
        case 9: /*0x1b51b7*/
          return -[IOAudio isOutputMuted](self, sel_isOutputMuted); /*0x1b5260*/
        case 10: /*0x1b51b7*/
          return -[IOAudio isLoudnessEnhanced](self, sel_isLoudnessEnhanced); /*0x1b5270*/
        case 11: /*0x1b51b7*/
          v12 = -[IOAudio outputAttenuationLeft](self, sel_outputAttenuationLeft); /*0x1b5285*/
          v4 = (-[IOAudio outputAttenuationRight](self, sel_outputAttenuationRight) + (int)v12) / 2; /*0x1b529f*/
          break; /*0x1b52a1*/
        case 12: /*0x1b51b7*/
          v7 = -[IOAudio outputAttenuationLeft](self, sel_outputAttenuationLeft); /*0x1b52b0*/
          goto LABEL_52; /*0x1b52b0*/
        case 13: /*0x1b51b7*/
          v7 = -[IOAudio outputAttenuationRight](self, sel_outputAttenuationRight); /*0x1b52c0*/
          goto LABEL_52; /*0x1b52c0*/
        case 25: /*0x1b51b7*/
          v4 = *((char *)self->_audioPrivate + 22); /*0x1b52de*/
          break; /*0x1b52e2*/
        case 26: /*0x1b51b7*/
          v4 = *((char *)self->_audioPrivate + 21); /*0x1b52ce*/
          break; /*0x1b52d2*/
        case 27: /*0x1b51b7*/
          v4 = *((char *)self->_audioPrivate + 23); /*0x1b52ee*/
          break; /*0x1b52f2*/
        case 28: /*0x1b51b7*/
          v4 = *((char *)self->_audioPrivate + 24); /*0x1b52fe*/
          break; /*0x1b5302*/
        case 29: /*0x1b51b7*/
          v4 = *((char *)self->_audioPrivate + 25); /*0x1b530e*/
          break; /*0x1b5312*/
        default:
          return v4;
      }
    }
    else
    {
      v13 = +[Object class](aInputstream, sel_class); /*0x1b5326*/
      if ( (unsigned __int8)objc_msgSend(a4, sel_isKindOf_, v13) )
      {
        switch ( a3 ) /*0x1b5351*/
        {
          case 400: /*0x1b5351*/
            v6 = sel_dataEncoding; /*0x1b5370*/
            goto LABEL_51; /*0x1b5376*/
          case 401: /*0x1b5351*/
            v6 = sel_samplingRate; /*0x1b537c*/
            goto LABEL_51; /*0x1b5382*/
          case 402: /*0x1b5351*/
            v6 = sel_channelCount; /*0x1b5388*/
            goto LABEL_51; /*0x1b538e*/
          case 403: /*0x1b5351*/
            v6 = sel_highWaterMark; /*0x1b5394*/
            goto LABEL_51; /*0x1b539a*/
          case 404: /*0x1b5351*/
            v6 = sel_lowWaterMark; /*0x1b53a0*/
            goto LABEL_51; /*0x1b53a6*/
          case 405: /*0x1b5351*/
            v4 = 605; /*0x1b53ac*/
            break; /*0x1b53b1*/
          default:
            return v4;
        }
      }
      else
      {
        v14 = +[Object class](aOutputstream, sel_class); /*0x1b53c6*/
        if ( !(unsigned __int8)objc_msgSend(a4, sel_isKindOf_, v14) )
        {
          IOLog((int)"Audio: unknown parameter object\n");
          return 0; /*0x1b54b8*/
        }
        switch ( a3 ) /*0x1b53f5*/
        {
          case 400: /*0x1b53f5*/
            v6 = sel_dataEncoding; /*0x1b5428*/
            goto LABEL_51; /*0x1b542e*/
          case 401: /*0x1b53f5*/
            v6 = sel_samplingRate; /*0x1b5430*/
            goto LABEL_51; /*0x1b5436*/
          case 402: /*0x1b53f5*/
            v6 = sel_channelCount; /*0x1b5438*/
            goto LABEL_51; /*0x1b543e*/
          case 403: /*0x1b53f5*/
            v6 = sel_highWaterMark; /*0x1b5440*/
            goto LABEL_51; /*0x1b5446*/
          case 404: /*0x1b53f5*/
            v6 = sel_lowWaterMark; /*0x1b5448*/
            goto LABEL_51; /*0x1b544e*/
          case 406: /*0x1b53f5*/
            return 607; /*0x1b5455*/
          case 407: /*0x1b53f5*/
            return (char)objc_msgSend(a4, sel_isDetectingPeaks); /*0x1b5468*/
          case 408: /*0x1b53f5*/
            v8 = objc_msgSend(a4, sel_gainLeft); /*0x1b5479*/
            v9 = objc_msgSend(a4, sel_gainRight); /*0x1b5483*/
            return ((unsigned int)v9 + (unsigned int)v8) >> 1; /*0x1b548e*/
          case 409: /*0x1b53f5*/
            v6 = sel_gainLeft; /*0x1b5490*/
            goto LABEL_51; /*0x1b5496*/
          case 410: /*0x1b53f5*/
            v6 = sel_gainRight; /*0x1b5498*/
LABEL_51:
            v7 = objc_msgSend(a4, v6); /*0x1b549e*/
LABEL_52:
            v4 = (int)v7; /*0x1b54a5*/
            break; /*0x1b54a7*/
          default:
            return v4;
        }
      }
    }
  }
  return v4; /*0x1b54c1*/
}
