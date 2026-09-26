/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b0cd0. */
int __cdecl -[EventDriver evClose:token:](EventDriver *self, SEL a2, int a3, int a4)
{
  void *evScreen; // eax

  objc_msgSend(self->driverLock, sel_lock); /*0x1b0ce9*/
  if ( self->evOpenCalled && self->eventPort == a4 ) /*0x1b0d00*/
  {
    -[EventDriver forceAutoDimState:](self, sel_forceAutoDimState_, 0); /*0x1b0d2a*/
    -[EventDriver hideCursor](self, sel_hideCursor); /*0x1b0d37*/
    objc_msgSend(self->driverLock, sel_unlock); /*0x1b0d4a*/
    -[EventDriver detachEventSources](self, sel_detachEventSources); /*0x1b0d57*/
    if ( self->eventsOpen == 1 ) /*0x1b0d66*/
      -[EventDriver unmapEventShmem:](self, sel_unmapEventShmem_, self->eventPort); /*0x1b0d77*/
    objc_msgSend(self->driverLock, sel_lock); /*0x1b0d8d*/
    evScreen = self->evScreen; /*0x1b0d95*/
    if ( evScreen ) /*0x1b0d9d*/
    {
      IOFree((int)evScreen, self->evScreenSize); /*0x1b0da7*/
      self->evScreen = nullptr; /*0x1b0dac*/
      self->evScreenSize = 0; /*0x1b0db6*/
      self->screens = 0; /*0x1b0dc0*/
      self->lastShmemPtr = nullptr; /*0x1b0dca*/
    }
    -[EventDriver setEventPort:](self, sel_setEventPort_, 0); /*0x1b0de1*/
    self->evOpenCalled = 0; /*0x1b0de6*/
    objc_msgSend(self->driverLock, sel_unlock); /*0x1b0dfb*/
    return 0; /*0x1b0e00*/
  }
  else
  {
    objc_msgSend(self->driverLock, sel_unlock); /*0x1b0d10*/
    return -706; /*0x1b0d15*/
  }
}
