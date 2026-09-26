/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b22d4. */
id __cdecl -[EventDriver scheduleNextPeriodicEvent](EventDriver *self, SEL a2)
{
  unsigned __int64 waitFrameTime; // rcx
  unsigned __int64 v4; // [esp+Ch] [ebp-8h] BYREF

  IOGetTimestamp((int *)&v4); /*0x1b22e4*/
  waitFrameTime = v4 + 167772160; /*0x1b22f5*/
  if ( self->waitFrameTime > v4 && self->waitFrameTime < waitFrameTime ) /*0x1b2321*/
    waitFrameTime = self->waitFrameTime; /*0x1b2323*/
  if ( !self->periodicRunPending /*0x1b2364*/
    || self->nextPeriodicRun > waitFrameTime
    || self->nextPeriodicRun <= self->thisPeriodicRun )
  {
    self->nextPeriodicRun = waitFrameTime; /*0x1b2366*/
    -[EventDriver runPeriodicEvent:](self, sel_runPeriodicEvent_, waitFrameTime); /*0x1b237c*/
  }
  return self; /*0x1b2386*/
}
