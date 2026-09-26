/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b2e60. */
id __cdecl -[EventDriver absolutePointerEvent:at:inProximity:withPressure:withAngle:atTime:](
        EventDriver *self,
        SEL a2,
        int a3,
        $9B414A52084CF78D000E95AF47DF0AD5 *a4,
        char a5,
        int a6,
        int a7,
        unsigned __int64 a8)
{
  int v8; // edi
  _DWORD *evg; // ecx
  int v10; // edx
  _DWORD *v11; // ecx
  int v12; // edx
  _BYTE v14[12]; // [esp+1Ch] [ebp-Ch] BYREF

  v8 = a8 >> 24; /*0x1b2e85*/
  objc_msgSend(self->driverLock, sel_lock); /*0x1b2e96*/
  if ( !self->eventsOpen ) /*0x1b2e9e*/
  {
    objc_msgSend(self->driverLock, sel_unlock); /*0x1b2eb5*/
    return self; /*0x1b2eb5*/
  }
  self->lastPressure = a6; /*0x1b2ebf*/
  if ( a4->var0 != self->pointerLoc.x || a4->var1 != self->pointerLoc.y ) /*0x1b2edf*/
  {
    self->pointerLoc = ($2F2A3E9C94EF4159E4A60D0C79A55791)*a4; /*0x1b2ee6*/
    if ( !self->needSetCursorPosition ) /*0x1b2eec*/
      -[EventDriver _setCursorPosition:atTime:](self, sel__setCursorPosition_atTime_, &self->pointerLoc, v8); /*0x1b2f05*/
  }
  if ( self->lastProximity == a5 ) /*0x1b2f16*/
    goto LABEL_10; /*0x1b2f16*/
  if ( a5 == 1 ) /*0x1b2f1b*/
  {
    evg = self->evg; /*0x1b2f1d*/
    v10 = evg[3]; /*0x1b2f23*/
    LOBYTE(v10) = v10 | 0x80; /*0x1b2f26*/
    evg[3] = v10; /*0x1b2f29*/
    bzero(v14, 0xCu); /*0x1b2f32*/
    -[EventDriver postEvent:at:atTime:withData:]( /*0x1b2f4a*/
      self,
      sel_postEvent_at_atTime_withData_,
      12,
      &self->pointerLoc,
      v8,
      v14);
LABEL_10:
    if ( a5 == 1 ) /*0x1b2f56*/
      -[EventDriver _setButtonState:atTime:](self, sel__setButtonState_atTime_, a3, v8); /*0x1b2f65*/
  }
  if ( self->lastProximity != a5 && !a5 ) /*0x1b2f7a*/
  {
    v11 = self->evg; /*0x1b2f7c*/
    v12 = v11[3]; /*0x1b2f82*/
    LOBYTE(v12) = v12 & 0x7F; /*0x1b2f85*/
    v11[3] = v12; /*0x1b2f88*/
    bzero(v14, 0xCu); /*0x1b2f91*/
    -[EventDriver postEvent:at:atTime:withData:]( /*0x1b2fa9*/
      self,
      sel_postEvent_at_atTime_withData_,
      12,
      &self->pointerLoc,
      v8,
      v14);
  }
  self->lastProximity = a5; /*0x1b2fb4*/
  objc_msgSend(self->driverLock, sel_unlock); /*0x1b2fc8*/
  return self; /*0x1b2fd2*/
}
