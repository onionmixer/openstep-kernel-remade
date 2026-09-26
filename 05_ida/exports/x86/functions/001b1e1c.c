/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b1e1c. */
void __cdecl -[EventDriver periodicEvents](EventDriver *self, SEL a2)
{
  __int16 *evg; // ebx
  int v3; // edx

  objc_msgSend(self->driverLock, sel_lock); /*0x1b1e33*/
  if ( self->eventsOpen ) /*0x1b1e3b*/
  {
    evg = (__int16 *)self->evg; /*0x1b1e48*/
    IOGetTimestamp((int *)&self->thisPeriodicRun); /*0x1b1e55*/
    v3 = self->thisPeriodicRun >> 24; /*0x1b1e66*/
    if ( !v3 ) /*0x1b1e72*/
      v3 = 1; /*0x1b1e74*/
    *((_DWORD *)evg + 4) = v3; /*0x1b1e79*/
    if ( self->needSetCursorPosition == 1 ) /*0x1b1e83*/
      -[EventDriver _setCursorPosition:atTime:](self, sel__setCursorPosition_atTime_, &self->pointerLoc, v3); /*0x1b1e95*/
    if ( ev_try_lock((volatile signed __int32 *)evg + 16) ) /*0x1b1ea1*/
    {
      if ( ev_try_lock((volatile signed __int32 *)evg + 5) ) /*0x1b1eb5*/
      {
        if ( *((_DWORD *)evg + 14) != *((_DWORD *)evg + 15) && *((_DWORD *)evg + 4) - *((_DWORD *)evg + 14) > evg[38] ) /*0x1b1ee0*/
          *((_BYTE *)evg + 72) = 1; /*0x1b1ee2*/
        if ( *((_BYTE *)evg + 73) && *((_BYTE *)evg + 74) && *((_BYTE *)evg + 72) ) /*0x1b1ef4*/
        {
          if ( !*((_DWORD *)evg + 17) ) /*0x1b1efb*/
            -[EventDriver showWaitCursor](self, sel_showWaitCursor); /*0x1b1f08*/
        }
        else if ( *((_DWORD *)evg + 17) && self->waitSusTime <= self->thisPeriodicRun ) /*0x1b1f31*/
        {
          -[EventDriver hideWaitCursor](self, sel_hideWaitCursor); /*0x1b1f3b*/
        }
        if ( *((_DWORD *)evg + 17) && self->waitFrameTime <= self->thisPeriodicRun ) /*0x1b1f68*/
          -[EventDriver animateWaitCursor](self, sel_animateWaitCursor); /*0x1b1f72*/
        ev_unlock((_DWORD *)evg + 5); /*0x1b1f7e*/
        if ( self->autoDimTime < *((_DWORD *)evg + 4) && !self->autoDimmed ) /*0x1b1f91*/
          -[EventDriver doAutoDim](self, sel_doAutoDim); /*0x1b1fa2*/
      }
      ev_unlock((_DWORD *)evg + 16); /*0x1b1fae*/
    }
    -[EventDriver scheduleNextPeriodicEvent](self, sel_scheduleNextPeriodicEvent); /*0x1b1fbe*/
  }
  objc_msgSend(self->driverLock, sel_unlock); /*0x1b1fd1*/
}
