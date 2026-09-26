/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b1a9c. */
id __cdecl -[EventDriver kickEventConsumer](EventDriver *self, SEL a2)
{
  objc_msgSend(self->kickConsumerLock, sel_lock); /*0x1b1ab1*/
  if ( self->needToKickEventConsumer == 1 ) /*0x1b1ac0*/
  {
    objc_msgSend(self->kickConsumerLock, sel_unlock); /*0x1b1ad0*/
  }
  else
  {
    self->needToKickEventConsumer = 1; /*0x1b1ad8*/
    objc_msgSend(self->kickConsumerLock, sel_unlock); /*0x1b1aed*/
    -[EventDriver sendIOThreadAsyncMsg:to:with:]( /*0x1b1b04*/
      self,
      sel_sendIOThreadAsyncMsg_to_with_,
      sel__performKickEventConsumer_,
      self,
      0);
  }
  return self; /*0x1b1b0b*/
}
