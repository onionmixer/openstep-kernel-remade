/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19f17c. */
id __cdecl -[EventSrcPCKeyboard scheduleAutoRepeat](EventSrcPCKeyboard *self, SEL a2)
{
  if ( self->calloutPending == 1 ) /*0x19f18a*/
  {
    ns_untimeout((int)sub_19F0A0, (int)self); /*0x19f192*/
    self->calloutPending = 0; /*0x19f197*/
  }
  if ( LODWORD(self->downRepeatTime) || HIDWORD(self->downRepeatTime) ) /*0x19f1aa*/
  {
    ns_abstimeout((int)sub_19F0A0, (int)self, self->downRepeatTime, HIDWORD(self->downRepeatTime)); /*0x19f1c9*/
    self->calloutPending = 1; /*0x19f1ce*/
  }
  return self; /*0x19f1d7*/
}
