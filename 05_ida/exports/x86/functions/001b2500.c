/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b2500. */
void __cdecl -[EventDriver hideWaitCursor](EventDriver *self, SEL a2)
{
  *((_DWORD *)self->evg + 17) = 0; /*0x1b250d*/
  -[EventDriver changeCursor:](self, sel_changeCursor_, 0); /*0x1b251e*/
  self->waitFrameTime = 0; /*0x1b2523*/
  self->waitSusTime = 0; /*0x1b2537*/
}
