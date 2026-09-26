/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b17a0. */
id __cdecl -[EventDriver setEventPort:](EventDriver *self, SEL a2, int a3)
{
  int v3; // eax

  if ( a3 ) /*0x1b17ad*/
  {
    if ( self->eventPort != a3 ) /*0x1b17c5*/
    {
      v3 = IOGetKernPort(a3); /*0x1b17c8*/
      self->event_kern_port = v3; /*0x1b17cd*/
      port_request_notification(v3, self->notify_kern_port); /*0x1b17db*/
    }
  }
  else
  {
    self->event_kern_port = 0; /*0x1b17af*/
  }
  if ( !self->eventMsg ) /*0x1b17e3*/
    self->eventMsg = (void *)IOMalloc(0x1Cu); /*0x1b17f3*/
  self->eventPort = a3; /*0x1b17fc*/
  qmemcpy(self->eventMsg, &unk_1E5364, 0x1Cu); /*0x1b1813*/
  *((_DWORD *)self->eventMsg + 4) = a3; /*0x1b181b*/
  return self; /*0x1b1823*/
}
