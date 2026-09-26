/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b2d54. */
id __cdecl -[EventDriver absolutePointerEvent:at:inProximity:](
        EventDriver *self,
        SEL a2,
        int a3,
        $9B414A52084CF78D000E95AF47DF0AD5 *a4,
        char a5)
{
  int lastPressure; // ebx
  int v7[2]; // [esp+10h] [ebp-8h] BYREF

  IOGetTimestamp(v7); /*0x1b2d6d*/
  objc_msgSend(self->driverLock, sel_lock); /*0x1b2d80*/
  lastPressure = self->lastPressure; /*0x1b2d85*/
  if ( self->eventsOpen ) /*0x1b2d8f*/
  {
    if ( (a3 & 4) != (*((_DWORD *)self->evg + 2) & 4) ) /*0x1b2dc3*/
    {
      lastPressure = 0; /*0x1b2dc5*/
      if ( (a3 & 4) != 0 ) /*0x1b2dc9*/
        lastPressure = 255; /*0x1b2dcb*/
    }
    objc_msgSend(self->driverLock, sel_unlock); /*0x1b2dde*/
    -[EventDriver absolutePointerEvent:at:inProximity:withPressure:withAngle:atTime:]( /*0x1b2e00*/
      self,
      sel_absolutePointerEvent_at_inProximity_withPressure_withAngle_atTime_,
      a3,
      a4,
      a5,
      lastPressure,
      90,
      v7[0],
      v7[1]);
  }
  else
  {
    objc_msgSend(self->driverLock, sel_unlock); /*0x1b2da6*/
  }
  return self; /*0x1b2e0a*/
}
