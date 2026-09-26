/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19f1e0. */
id __cdecl -[EventSrcPCKeyboard autoRepeat](EventSrcPCKeyboard *self, SEL a2)
{
  int v2; // ecx
  int keyRepeat; // edx
  bool v4; // cf
  unsigned __int64 v6; // [esp+8h] [ebp-8h] BYREF

  IOGetTimestamp(&v6); /*0x19f1ef*/
  objc_msgSend(self->deviceLock, sel_lock); /*0x19f202*/
  if ( self->calloutPending ) /*0x19f20a*/
  {
    self->calloutPending = 0; /*0x19f217*/
    self->isRepeat = 1; /*0x19f21e*/
    if ( (LODWORD(self->downRepeatTime) || HIDWORD(self->downRepeatTime)) && v6 >= self->downRepeatTime ) /*0x19f24a*/
    {
      v2 = HIDWORD(v6); /*0x19f24f*/
      LODWORD(self->lastEventTime) = v6; /*0x19f252*/
      HIDWORD(self->lastEventTime) = v2; /*0x19f258*/
      objc_msgSend(self->keyMap, sel_doKeyboardEvent_direction_keyBits_, self->codeToRepeat, 1, self->keyState); /*0x19f27c*/
      keyRepeat = self->keyRepeat; /*0x19f281*/
      v4 = __CFADD__(keyRepeat, self->downRepeatTime); /*0x19f287*/
      LODWORD(self->downRepeatTime) += keyRepeat; /*0x19f287*/
      HIDWORD(self->downRepeatTime) += HIDWORD(self->keyRepeat) + v4; /*0x19f293*/
    }
    self->isRepeat = 0; /*0x19f29c*/
    -[EventSrcPCKeyboard scheduleAutoRepeat](self, sel_scheduleAutoRepeat); /*0x19f2ab*/
  }
  objc_msgSend(self->deviceLock, sel_unlock); /*0x19f2be*/
  return self; /*0x19f2c8*/
}
