/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b277c. */
id __cdecl -[EventDriver forceAutoDimState:](EventDriver *self, SEL a2, char a3)
{
  if ( a3 == 1 ) /*0x1b2787*/
  {
    if ( !self->autoDimmed ) /*0x1b2789*/
    {
      if ( self->eventsOpen == 1 ) /*0x1b2799*/
        self->autoDimTime = *((_DWORD *)self->evg + 4); /*0x1b27a4*/
      -[EventDriver doAutoDim](self, sel_doAutoDim); /*0x1b27b0*/
    }
  }
  else if ( self->autoDimmed == 1 ) /*0x1b27bb*/
  {
    if ( self->eventsOpen == 1 ) /*0x1b27c4*/
      self->autoDimTime = self->autoDimPeriod + *((_DWORD *)self->evg + 4); /*0x1b27d5*/
    -[EventDriver undoAutoDim](self, sel_undoAutoDim); /*0x1b27e3*/
  }
  return self; /*0x1b27ea*/
}
