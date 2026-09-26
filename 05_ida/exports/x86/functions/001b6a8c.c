/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b6a8c. */
void __cdecl -[IOAudio _setOutputFor:to:](IOAudio *self, SEL a2, int a3, char a4)
{
  id v4; // eax

  switch ( a3 )
  {
    case 25:
      *((_BYTE *)self->_audioPrivate + 22) = a4; /*0x1b6ae6*/
      goto LABEL_7; /*0x1b6af7*/
    case 26:
      *((_BYTE *)self->_audioPrivate + 21) = a4; /*0x1b6aca*/
      goto LABEL_7; /*0x1b6adb*/
    case 27:
      *((_BYTE *)self->_audioPrivate + 23) = a4; /*0x1b6b02*/
      goto LABEL_7; /*0x1b6b13*/
    case 28:
      *((_BYTE *)self->_audioPrivate + 24) = a4; /*0x1b6b1e*/
      goto LABEL_7; /*0x1b6b2f*/
    case 29:
      *((_BYTE *)self->_audioPrivate + 25) = a4; /*0x1b6b3a*/
LABEL_7:
      v4 = -[IOAudio _audioCommand](self, sel__audioCommand); /*0x1b6b4b*/
      objc_msgSend(v4, sel_send_); /*0x1b6b64*/
      break; /*0x1b6b69*/
    default:
      IOLog((int)"Audio: unknown output source: %d\n", a3);
      break; /*0x1b6b72*/
  }
}
