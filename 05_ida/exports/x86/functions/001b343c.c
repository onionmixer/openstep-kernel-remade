/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b343c. */
id __cdecl -[EventDriver setCursorPosition:](EventDriver *self, SEL a2, $9B414A52084CF78D000E95AF47DF0AD5 *a3)
{
  int v3; // edx
  id result; // eax
  unsigned __int64 v5; // [esp+Ch] [ebp-8h] BYREF

  if ( self->eventsOpen == 1 ) /*0x1b3452*/
  {
    self->pointerLoc = ($2F2A3E9C94EF4159E4A60D0C79A55791)*a3; /*0x1b3456*/
    if ( !self->needSetCursorPosition ) /*0x1b345c*/
    {
      IOGetTimestamp((int *)&v5); /*0x1b3469*/
      v3 = v5 >> 24; /*0x1b3474*/
      if ( !v3 ) /*0x1b3480*/
        v3 = 1; /*0x1b3482*/
      return -[EventDriver _setCursorPosition:atTime:](self, sel__setCursorPosition_atTime_, a3, v3); /*0x1b3491*/
    }
  }
  return result; /*0x1b3499*/
}
