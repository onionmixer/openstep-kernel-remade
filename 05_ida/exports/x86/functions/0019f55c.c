/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19f55c. */
void __cdecl -[EventSrcPCKeyboard dispatchKeyboardEvent:](
        EventSrcPCKeyboard *self,
        SEL a2,
        $88DEA2CADEC1641AD84155FE76C340B7 *a3)
{
  int var0_high; // ecx
  unsigned int var1; // edx
  int v5; // edx

  var0_high = HIDWORD(a3->var0); /*0x19f569*/
  LODWORD(self->lastEventTime) = a3->var0; /*0x19f56c*/
  HIDWORD(self->lastEventTime) = var0_high; /*0x19f572*/
  var1 = a3->var1; /*0x19f578*/
  if ( var1 == 127 ) /*0x19f57e*/
    return; /*0x19f57e*/
  if ( var1 == 54 ) /*0x19f587*/
  {
    v5 = 4; /*0x19f5b8*/
    goto LABEL_19; /*0x19f5bd*/
  }
  if ( var1 > 0x36 ) /*0x19f589*/
  {
    if ( var1 != 96 ) /*0x19f59b*/
    {
      if ( var1 > 0x60 ) /*0x19f59d*/
      {
        if ( var1 != 97 ) /*0x19f5ab*/
          goto LABEL_18; /*0x19f5ab*/
        v5 = 64; /*0x19f5c8*/
      }
      else
      {
        if ( var1 != 56 ) /*0x19f5a2*/
          goto LABEL_18; /*0x19f5a2*/
        v5 = 32; /*0x19f5c0*/
      }
      goto LABEL_19; /*0x19f5c5*/
    }
LABEL_17:
    v5 = 1; /*0x19f5d0*/
    goto LABEL_19; /*0x19f5d5*/
  }
  if ( var1 == 29 ) /*0x19f58e*/
    goto LABEL_17; /*0x19f58e*/
  if ( var1 != 42 ) /*0x19f593*/
  {
LABEL_18:
    v5 = 0; /*0x19f5d8*/
    goto LABEL_19; /*0x19f5d8*/
  }
  v5 = 2; /*0x19f5b0*/
LABEL_19:
  if ( a3->var2 ) /*0x19f5da*/
    self->deviceDependentFlags |= v5; /*0x19f5e0*/
  else
    self->deviceDependentFlags &= ~v5; /*0x19f5ea*/
  objc_msgSend(self->deviceLock, sel_lock); /*0x19f5fe*/
  objc_msgSend(self->keyMap, sel_doKeyboardEvent_direction_keyBits_, a3->var1, a3->var2, self->keyState); /*0x19f621*/
  objc_msgSend(self->deviceLock, sel_unlock); /*0x19f634*/
}
