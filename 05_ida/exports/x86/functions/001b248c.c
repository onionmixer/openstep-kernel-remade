/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b248c. */
void __cdecl -[EventDriver showWaitCursor](EventDriver *self, SEL a2)
{
  int waitFrameRate; // edx
  bool v3; // cf
  int waitSustain; // edx

  *((_DWORD *)self->evg + 17) = 1; /*0x1b2499*/
  -[EventDriver changeCursor:](self, sel_changeCursor_, 1); /*0x1b24aa*/
  waitFrameRate = self->waitFrameRate; /*0x1b24af*/
  v3 = __CFADD__(self->thisPeriodicRun, waitFrameRate); /*0x1b24b5*/
  LODWORD(self->waitFrameTime) = LODWORD(self->thisPeriodicRun) + waitFrameRate; /*0x1b24bb*/
  HIDWORD(self->waitFrameTime) = HIDWORD(self->thisPeriodicRun) + v3 + HIDWORD(self->waitFrameRate); /*0x1b24cd*/
  waitSustain = self->waitSustain; /*0x1b24d3*/
  v3 = __CFADD__(self->thisPeriodicRun, waitSustain); /*0x1b24d9*/
  LODWORD(self->waitSusTime) = LODWORD(self->thisPeriodicRun) + waitSustain; /*0x1b24df*/
  HIDWORD(self->waitSusTime) = HIDWORD(self->thisPeriodicRun) + v3 + HIDWORD(self->waitSustain); /*0x1b24f1*/
}
