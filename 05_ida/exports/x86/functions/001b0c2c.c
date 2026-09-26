/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b0c2c. */
int __cdecl -[EventDriver evOpen:token:](EventDriver *self, SEL a2, int a3, int a4)
{
  int v4; // esi

  v4 = 0; /*0x1b0c34*/
  if ( a3 != self->ev_port ) /*0x1b0c3f*/
    return -706; /*0x1b0c41*/
  objc_msgSend(self->driverLock, sel_lock); /*0x1b0c56*/
  if ( self->evOpenCalled == 1 ) /*0x1b0c65*/
  {
    v4 = -725; /*0x1b0c67*/
  }
  else
  {
    self->evOpenCalled = 1; /*0x1b0c70*/
    if ( !self->evInitialized ) /*0x1b0c77*/
    {
      self->evInitialized = 1; /*0x1b0c80*/
      self->curBright = 64; /*0x1b0c87*/
      self->curVolume = 32; /*0x1b0c91*/
    }
    -[EventDriver setEventPort:](self, sel_setEventPort_, a4); /*0x1b0ca7*/
  }
  objc_msgSend(self->driverLock, sel_unlock); /*0x1b0cbd*/
  return v4; /*0x1b0cc7*/
}
