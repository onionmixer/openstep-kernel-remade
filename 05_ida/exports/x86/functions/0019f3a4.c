/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19f3a4. */
id __cdecl -[EventSrcPCKeyboard keyboardEvent:flags:keyCode:charCode:charSet:originalCharCode:originalCharSet:](
        EventSrcPCKeyboard *self,
        SEL a2,
        int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        unsigned int a7,
        unsigned int a8,
        unsigned int a9)
{
  id v9; // eax

  v9 = -[IOEventSource owner](self, sel_owner); /*0x19f3f4*/
  objc_msgSend(v9, sel_keyboardEvent_flags_keyCode_charCode_charSet_originalCharCode_originalCharSet_repeat_atTime_); /*0x19f3fd*/
  return -[EventSrcPCKeyboard setRepeat:forCode:](self, sel_setRepeat_forCode_, a3, a5); /*0x19f417*/
}
