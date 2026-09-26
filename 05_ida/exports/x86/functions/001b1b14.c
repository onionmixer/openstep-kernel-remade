/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b1b14. */
id __cdecl -[EventDriver _performKickEventConsumer:](EventDriver *self, SEL a2, id a3)
{
  int v3; // eax
  const char *v4; // eax
  int v6; // [esp-4h] [ebp-8h]

  objc_msgSend(self->kickConsumerLock, sel_lock); /*0x1b1b29*/
  self->needToKickEventConsumer = 0; /*0x1b1b2e*/
  objc_msgSend(self->kickConsumerLock, sel_unlock); /*0x1b1b43*/
  v3 = msg_send((_DWORD *)self->eventMsg, 1, 0); /*0x1b1b53*/
  if ( v3 != -103 && v3 )
  {
    v6 = v3; /*0x1b1b64*/
    v4 = -[IODevice name](self, sel_name); /*0x1b1b6d*/
    IOLog((int)"%s: _performKickEventConsumer msg_send returned %d\n", v4, v6);
  }
  return self; /*0x1b1b82*/
}
