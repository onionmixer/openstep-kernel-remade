/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19f2d0. */
id __cdecl -[EventSrcPCKeyboard setRepeat:forCode:](EventSrcPCKeyboard *self, SEL a2, unsigned int a3, unsigned int a4)
{
  int initialKeyRepeat; // edx
  bool v5; // cf

  if ( !self->isRepeat ) /*0x19f2de*/
  {
    if ( a3 == 10 ) /*0x19f2ea*/
    {
      initialKeyRepeat = self->initialKeyRepeat; /*0x19f2ec*/
      v5 = __CFADD__(self->lastEventTime, initialKeyRepeat); /*0x19f2f2*/
      LODWORD(self->downRepeatTime) = LODWORD(self->lastEventTime) + initialKeyRepeat; /*0x19f2f8*/
      HIDWORD(self->downRepeatTime) = HIDWORD(self->lastEventTime) + v5 + HIDWORD(self->initialKeyRepeat); /*0x19f30a*/
      self->codeToRepeat = a4; /*0x19f310*/
LABEL_7:
      -[EventSrcPCKeyboard scheduleAutoRepeat](self, sel_scheduleAutoRepeat); /*0x19f343*/
      return self; /*0x19f34b*/
    }
    if ( a3 == 11 && self->codeToRepeat == a4 ) /*0x19f323*/
    {
      self->downRepeatTime = 0; /*0x19f325*/
      self->codeToRepeat = -1; /*0x19f339*/
      goto LABEL_7; /*0x19f339*/
    }
  }
  return self; /*0x19f355*/
}
