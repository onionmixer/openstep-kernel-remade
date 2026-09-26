/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19f504. */
id __cdecl -[EventSrcPCKeyboard setAlphaLock:](EventSrcPCKeyboard *self, SEL a2, char a3)
{
  self->alphaLock = a3; /*0x19f50e*/
  objc_msgSend(self->kbdDevice, aSetalphalockfe, a3); /*0x19f526*/
  return self; /*0x19f52d*/
}
