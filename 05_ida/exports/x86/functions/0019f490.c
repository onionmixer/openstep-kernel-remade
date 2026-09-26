/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19f490. */
id __cdecl -[EventSrcPCKeyboard updateEventFlags:](EventSrcPCKeyboard *self, SEL a2, unsigned int a3)
{
  id v3; // eax

  v3 = -[IOEventSource owner](self, sel_owner); /*0x19f4a9*/
  return objc_msgSend(v3, sel_updateEventFlags_); /*0x19f4b9*/
}
