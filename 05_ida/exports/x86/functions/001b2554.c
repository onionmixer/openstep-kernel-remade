/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b2554. */
void __cdecl -[EventDriver animateWaitCursor](EventDriver *self, SEL a2)
{
  int waitFrameRate; // edx
  bool v3; // cf

  -[EventDriver changeCursor:](self, sel_changeCursor_, *((_DWORD *)self->evg + 7) + 1); /*0x1b256e*/
  waitFrameRate = self->waitFrameRate; /*0x1b2573*/
  v3 = __CFADD__(self->thisPeriodicRun, waitFrameRate); /*0x1b2579*/
  LODWORD(self->waitFrameTime) = LODWORD(self->thisPeriodicRun) + waitFrameRate; /*0x1b257f*/
  HIDWORD(self->waitFrameTime) = HIDWORD(self->thisPeriodicRun) + v3 + HIDWORD(self->waitFrameRate); /*0x1b2591*/
}
