/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b108c. */
id __cdecl -[EventDriver _resetMouseParameters](EventDriver *self, SEL a2)
{
  queue_entry *next; // ebx
  void *v3; // eax
  _BYTE v5[4]; // [esp+10h] [ebp-4h] BYREF

  objc_msgSend(self->driverLock, sel_lock); /*0x1b10a6*/
  if ( self->eventsOpen ) /*0x1b10ae*/
  {
    self->clickTimeThresh = 30; /*0x1b10cc*/
    self->clickSpaceThresh.y = 3; /*0x1b10d6*/
    self->clickSpaceThresh.x = 3; /*0x1b10df*/
    self->clickTime = -30; /*0x1b10e8*/
    self->clickLoc.y = -3; /*0x1b10f2*/
    self->clickLoc.x = -3; /*0x1b10fb*/
    self->clickState = 1; /*0x1b1104*/
    self->autoDimTime = *((_DWORD *)self->evg + 4) + 18600; /*0x1b111c*/
    self->autoDimPeriod = 18600; /*0x1b1122*/
    self->dimmedBrightness = 16; /*0x1b112c*/
    objc_msgSend(self->driverLock, sel_unlock); /*0x1b1144*/
    objc_msgSend(self->eventSrcListLock, sel_lock); /*0x1b1157*/
    next = self->eventSrcList.next; /*0x1b115c*/
    while ( &self->eventSrcList != ($BAB6C68F9D34F0972F921D3DB17D7446 *)next ) /*0x1b116d*/
    {
      v3 = *(void **)next; /*0x1b1178*/
      next = *((queue_entry **)next + 1); /*0x1b117a*/
      objc_msgSend(v3, sel_setIntValues_forParameter_count_, v5, "Evs_ResetMouse", 1); /*0x1b1190*/
    }
    objc_msgSend(self->eventSrcListLock, sel_unlock); /*0x1b11aa*/
  }
  else
  {
    objc_msgSend(self->driverLock, sel_unlock); /*0x1b10c4*/
  }
  return self; /*0x1b11b4*/
}
