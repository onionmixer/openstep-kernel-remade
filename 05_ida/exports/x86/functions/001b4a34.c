/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b4a34. */
void __cdecl -[IOAudio _commandOccurred](IOAudio *self, SEL a2)
{
  id v2; // eax
  id v3; // eax
  id v4; // eax
  id v5; // eax

  v2 = -[IOAudio _audioCommand](self, sel__audioCommand); /*0x1b4a4b*/
  switch ( (unsigned int)objc_msgSend(v2, sel_command) ) /*0x1b4a6a*/
  {
    case 0u: /*0x1b4a6a*/
      -[IOAudio updateInputGainLeft](self, sel_updateInputGainLeft); /*0x1b4aec*/
      break; /*0x1b4af2*/
    case 1u: /*0x1b4a6a*/
      -[IOAudio updateInputGainRight](self, sel_updateInputGainRight); /*0x1b4b00*/
      break; /*0x1b4b06*/
    case 2u: /*0x1b4a6a*/
      -[IOAudio updateOutputMute](self, sel_updateOutputMute); /*0x1b4b14*/
      break; /*0x1b4b1a*/
    case 3u: /*0x1b4a6a*/
      -[IOAudio updateOutputAttenuationLeft](self, sel_updateOutputAttenuationLeft); /*0x1b4b28*/
      break; /*0x1b4b2e*/
    case 4u: /*0x1b4a6a*/
      -[IOAudio updateOutputAttenuationRight](self, sel_updateOutputAttenuationRight); /*0x1b4b3c*/
      break; /*0x1b4b42*/
    case 5u: /*0x1b4a6a*/
      -[IOAudio updateLoudnessEnhanced](self, sel_updateLoudnessEnhanced); /*0x1b4b50*/
      break; /*0x1b4b56*/
    case 6u: /*0x1b4a6a*/
      if ( -[IOAudio isInputActive](self, sel_isInputActive) ) /*0x1b4b64*/
      {
        v3 = -[IOAudio _inputChannel](self, sel__inputChannel); /*0x1b4b78*/
        -[IOAudio _stopDMAForChannel:](self, sel__stopDMAForChannel_, v3); /*0x1b4b86*/
      }
      break; /*0x1b4b86*/
    case 7u: /*0x1b4a6a*/
      if ( -[IOAudio isOutputActive](self, sel_isOutputActive) ) /*0x1b4b9c*/
      {
        v4 = -[IOAudio _outputChannel](self, sel__outputChannel); /*0x1b4bb0*/
        -[IOAudio _stopDMAForChannel:](self, sel__stopDMAForChannel_, v4); /*0x1b4bbe*/
      }
      break; /*0x1b4bbe*/
    case 8u: /*0x1b4a6a*/
      -[IOAudio setInput:enable:](self, sel_setInput_enable_, 30, 1); /*0x1b4bd8*/
      break; /*0x1b4bde*/
    case 9u: /*0x1b4a6a*/
      -[IOAudio setInput:enable:](self, sel_setInput_enable_, 30, 0); /*0x1b4bf0*/
      break; /*0x1b4bf6*/
    case 0xAu: /*0x1b4a6a*/
      -[IOAudio setInput:enable:](self, sel_setInput_enable_, 31, 1); /*0x1b4c08*/
      break; /*0x1b4c0e*/
    case 0xBu: /*0x1b4a6a*/
      -[IOAudio setInput:enable:](self, sel_setInput_enable_, 31, 0); /*0x1b4c20*/
      break; /*0x1b4c26*/
    case 0xCu: /*0x1b4a6a*/
      -[IOAudio setInput:enable:](self, sel_setInput_enable_, 32, 1); /*0x1b4c38*/
      break; /*0x1b4c3e*/
    case 0xDu: /*0x1b4a6a*/
      -[IOAudio setInput:enable:](self, sel_setInput_enable_, 32, 0); /*0x1b4c50*/
      break; /*0x1b4c56*/
    case 0xEu: /*0x1b4a6a*/
      -[IOAudio setInput:enable:](self, sel_setInput_enable_, 33, 1); /*0x1b4c68*/
      break; /*0x1b4c6e*/
    case 0xFu: /*0x1b4a6a*/
      -[IOAudio setInput:enable:](self, sel_setInput_enable_, 33, 0); /*0x1b4c80*/
      break; /*0x1b4c86*/
    case 0x10u: /*0x1b4a6a*/
      -[IOAudio setInput:enable:](self, sel_setInput_enable_, 34, 1); /*0x1b4c98*/
      break; /*0x1b4c9e*/
    case 0x11u: /*0x1b4a6a*/
      -[IOAudio setInput:enable:](self, sel_setInput_enable_, 34, 0); /*0x1b4cb0*/
      break; /*0x1b4cb6*/
    case 0x12u: /*0x1b4a6a*/
      -[IOAudio setOutput:enable:](self, sel_setOutput_enable_, 25, 1); /*0x1b4cc8*/
      break; /*0x1b4cce*/
    case 0x13u: /*0x1b4a6a*/
      -[IOAudio setOutput:enable:](self, sel_setOutput_enable_, 25, 0); /*0x1b4ce0*/
      break; /*0x1b4ce6*/
    case 0x14u: /*0x1b4a6a*/
      -[IOAudio setOutput:enable:](self, sel_setOutput_enable_, 26, 1); /*0x1b4cf8*/
      break; /*0x1b4cfe*/
    case 0x15u: /*0x1b4a6a*/
      -[IOAudio setOutput:enable:](self, sel_setOutput_enable_, 26, 0); /*0x1b4d10*/
      break; /*0x1b4d16*/
    case 0x16u: /*0x1b4a6a*/
      -[IOAudio setOutput:enable:](self, sel_setOutput_enable_, 27, 1); /*0x1b4d24*/
      break; /*0x1b4d2a*/
    case 0x17u: /*0x1b4a6a*/
      -[IOAudio setOutput:enable:](self, sel_setOutput_enable_, 27, 0); /*0x1b4d38*/
      break; /*0x1b4d3e*/
    case 0x18u: /*0x1b4a6a*/
      -[IOAudio setOutput:enable:](self, sel_setOutput_enable_, 28, 1); /*0x1b4d4c*/
      break; /*0x1b4d52*/
    case 0x19u: /*0x1b4a6a*/
      -[IOAudio setOutput:enable:](self, sel_setOutput_enable_, 28, 0); /*0x1b4d60*/
      break; /*0x1b4d66*/
    case 0x1Au: /*0x1b4a6a*/
      -[IOAudio setOutput:enable:](self, sel_setOutput_enable_, 29, 1); /*0x1b4d74*/
      break; /*0x1b4d7a*/
    case 0x1Bu: /*0x1b4a6a*/
      -[IOAudio setOutput:enable:](self, sel_setOutput_enable_, 29, 0); /*0x1b4d88*/
      break; /*0x1b4d88*/
    default:
      break;
  }
  v5 = -[IOAudio _audioCommand](self, sel__audioCommand); /*0x1b4d92*/
  objc_msgSend(v5, sel_done_); /*0x1b4daa*/
}
