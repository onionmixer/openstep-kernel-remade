/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b2c6c. */
id __cdecl -[EventDriver relativePointerEvent:deltaX:deltaY:atTime:](
        EventDriver *self,
        SEL a2,
        int a3,
        int a4,
        int a5,
        unsigned __int64 a6)
{
  int v7; // [esp+Ch] [ebp-4h]

  v7 = a6 >> 24; /*0x1b2c88*/
  objc_msgSend(self->driverLock, sel_lock); /*0x1b2c99*/
  if ( self->eventsOpen ) /*0x1b2ca1*/
  {
    if ( (a3 & 4) != (*((_DWORD *)self->evg + 2) & 4) ) /*0x1b2cc1*/
    {
      if ( (a3 & 4) != 0 ) /*0x1b2cc5*/
        self->lastPressure = -1; /*0x1b2cc7*/
      else
        self->lastPressure = 0; /*0x1b2cd0*/
    }
    -[EventDriver _setButtonState:atTime:](self, sel__setButtonState_atTime_, a3, v7); /*0x1b2ce4*/
    if ( a4 || a5 ) /*0x1b2cf6*/
    {
      self->pointerLoc.x += a4; /*0x1b2cfc*/
      self->pointerLoc.y += a5; /*0x1b2d07*/
      if ( !self->needSetCursorPosition ) /*0x1b2d0e*/
        -[EventDriver _setCursorPosition:atTime:](self, sel__setCursorPosition_atTime_, &self->pointerLoc, v7); /*0x1b2d2a*/
    }
  }
  objc_msgSend(self->driverLock, sel_unlock); /*0x1b2d40*/
  return self; /*0x1b2d4a*/
}
