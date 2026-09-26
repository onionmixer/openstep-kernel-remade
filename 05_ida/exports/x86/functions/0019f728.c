/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19f728. */
EventSrcPCKeyboard *__cdecl -[EventSrcPCKeyboard init](EventSrcPCKeyboard *self, SEL a2)
{
  id keyMap; // eax
  KeyMap *v3; // eax
  id v4; // eax
  objc_super v6; // [esp+4h] [ebp-8h] BYREF

  objc_msgSend(self->deviceLock, sel_lock); /*0x19f740*/
  v6.receiver = self; /*0x19f74c*/
  v6.super_class = (Class)stru_1FA014.ext; /*0x19f755*/
  -[IOEventSource init](&v6, sel_init); /*0x19f75c*/
  keyMap = self->keyMap; /*0x19f764*/
  if ( keyMap ) /*0x19f76c*/
    objc_msgSend(keyMap, sel_free); /*0x19f776*/
  v3 = +[Object alloc](aKeymap, sel_alloc); /*0x19f79f*/
  v4 = -[KeyMap initFromKeyMapping:length:canFree:](v3, sel_initFromKeyMapping_length_canFree_); /*0x19f7a8*/
  self->keyMap = v4; /*0x19f7ad*/
  objc_msgSend(v4, sel_setDelegate_, self); /*0x19f7bc*/
  -[EventSrcPCKeyboard initKeyboard](self, sel_initKeyboard); /*0x19f7cc*/
  self->keyRepeat = 125000000; /*0x19f7d1*/
  self->initialKeyRepeat = 500000000; /*0x19f7e5*/
  objc_msgSend(self->deviceLock, sel_unlock); /*0x19f807*/
  return self; /*0x19f80e*/
}
