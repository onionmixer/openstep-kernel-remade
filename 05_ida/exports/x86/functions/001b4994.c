/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b4994. */
void __cdecl -[KeyMap _doModCalc:keyBits:](KeyMap *self, SEL a2, int a3, unsigned int *a4)
{
  char v4; // bl
  id v5; // eax
  id v6; // eax

  v4 = self->curMapping.keyBits[a3]; /*0x1b49a0*/
  if ( (v4 & 0x10) != 0 ) /*0x1b49a8*/
  {
    -[KeyMap _calcModBit:keyBits:](self, sel__calcModBit_keyBits_, v4 & 0xF, a4); /*0x1b49bc*/
    if ( (v4 & 0x20) != 0 ) /*0x1b49c7*/
    {
      v6 = objc_msgSend(self->delegate, sel_eventFlags); /*0x1b4a0e*/
      objc_msgSend(self->delegate, sel_updateEventFlags_, v6); /*0x1b4a22*/
    }
    else
    {
      v5 = objc_msgSend(self->delegate, sel_eventFlags); /*0x1b49e0*/
      objc_msgSend( /*0x1b49f9*/
        self->delegate,
        sel_keyboardEvent_flags_keyCode_charCode_charSet_originalCharCode_originalCharSet_,
        12,
        v5);
    }
  }
}
