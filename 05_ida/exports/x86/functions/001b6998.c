/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b6998. */
void __cdecl -[IOAudio _setInputFor:to:](IOAudio *self, SEL a2, int a3, char a4)
{
  id v4; // eax

  switch ( a3 )
  {
    case 30:
      *((_BYTE *)self->_audioPrivate + 16) = a4; /*0x1b69d6*/
      goto LABEL_7; /*0x1b69e7*/
    case 31:
      *((_BYTE *)self->_audioPrivate + 17) = a4; /*0x1b69f2*/
      goto LABEL_7; /*0x1b6a03*/
    case 32:
      *((_BYTE *)self->_audioPrivate + 18) = a4; /*0x1b6a0e*/
      goto LABEL_7; /*0x1b6a1f*/
    case 33:
      *((_BYTE *)self->_audioPrivate + 19) = a4; /*0x1b6a2a*/
      goto LABEL_7; /*0x1b6a3b*/
    case 34:
      *((_BYTE *)self->_audioPrivate + 20) = a4; /*0x1b6a46*/
LABEL_7:
      v4 = -[IOAudio _audioCommand](self, sel__audioCommand); /*0x1b6a57*/
      objc_msgSend(v4, sel_send_); /*0x1b6a70*/
      break; /*0x1b6a75*/
    default:
      IOLog((int)"Audio: unknown input source: %d\n", a3);
      break; /*0x1b6a7e*/
  }
}
