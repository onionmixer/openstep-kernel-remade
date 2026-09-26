/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19f0b8. */
id __cdecl -[EventSrcPCKeyboard resetKeyboard](EventSrcPCKeyboard *self, SEL a2)
{
  id keyMap; // eax
  KeyMap *v3; // eax
  id v4; // eax

  objc_msgSend(self->deviceLock, sel_lock); /*0x19f0cd*/
  keyMap = self->keyMap; /*0x19f0d5*/
  if ( keyMap ) /*0x19f0dd*/
    objc_msgSend(keyMap, sel_free); /*0x19f0e7*/
  v3 = +[Object alloc](aKeymap, sel_alloc); /*0x19f110*/
  v4 = -[KeyMap initFromKeyMapping:length:canFree:](v3, sel_initFromKeyMapping_length_canFree_); /*0x19f119*/
  self->keyMap = v4; /*0x19f11e*/
  objc_msgSend(v4, sel_setDelegate_, self); /*0x19f12d*/
  self->keyRepeat = 125000000; /*0x19f132*/
  self->initialKeyRepeat = 500000000; /*0x19f146*/
  objc_msgSend(self->deviceLock, sel_unlock); /*0x19f16b*/
  return self; /*0x19f172*/
}
