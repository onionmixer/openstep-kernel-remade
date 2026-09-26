/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a036c. */
id __cdecl -[EventSrcPCPointer initPointer](EventSrcPCPointer *self, SEL a2)
{
  id v2; // eax

  v2 = +[PCPointer activePointerDevice](aPcpointer, sel_activePointerDevice); /*0x1a0381*/
  self->pointerDevice = v2; /*0x1a0386*/
  if ( v2 ) /*0x1a0391*/
  {
    if ( (unsigned __int8)objc_msgSend(v2, sel_respondsTo_, sel_setEventTarget_) ) /*0x1a03b3*/
    {
      objc_msgSend(self->pointerDevice, sel_setEventTarget_, self); /*0x1a03df*/
      objc_msgSend(self->pointerDevice, sel_setEventTarget_, self); /*0x1a03f6*/
      return self; /*0x1a03fb*/
    }
    else
    {
      IOLog(aInitpointerPcp); /*0x1a03c4*/
      return nullptr; /*0x1a03c9*/
    }
  }
  else
  {
    IOLog(aInitpointerCan); /*0x1a0398*/
    return nullptr; /*0x1a039d*/
  }
}
