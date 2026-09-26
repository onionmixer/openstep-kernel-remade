/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19f420. */
id __cdecl -[EventSrcPCKeyboard keyboardSpecialEvent:flags:keyCode:specialty:](
        EventSrcPCKeyboard *self,
        SEL a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6)
{
  id v6; // eax
  id result; // eax

  v6 = -[IOEventSource owner](self, sel_owner); /*0x19f45c*/
  result = objc_msgSend(v6, sel_keyboardSpecialEvent_flags_keyCode_specialty_atTime_); /*0x19f465*/
  if ( a6 != 4 ) /*0x19f470*/
    return -[EventSrcPCKeyboard setRepeat:forCode:](self, sel_setRepeat_forCode_, a3, a5); /*0x19f47f*/
  return result; /*0x19f487*/
}
