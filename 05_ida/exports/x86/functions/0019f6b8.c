/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19f6b8. */
int __cdecl -[EventSrcPCKeyboard canBecomeOwner:](EventSrcPCKeyboard *self, SEL a2, id a3)
{
  int result; // eax

  result = (int)objc_msgSend(a3, sel_becomeOwner_, self); /*0x19f6cc*/
  if ( result ) /*0x19f6d6*/
  {
    -[IODevice stringFromReturn:](self, sel_stringFromReturn_, result); /*0x19f6e1*/
    objc_msgSend(a3, sel_name); /*0x19f6ef*/
    -[IODevice name](self, sel_name); /*0x19f700*/
    return IOLog(aSBecomeownerOf_1); /*0x19f70e*/
  }
  else
  {
    self->ownDevice = 1; /*0x19f718*/
  }
  return result; /*0x19f722*/
}
