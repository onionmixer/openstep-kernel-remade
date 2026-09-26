/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a0458. */
void __cdecl -[EventSrcPCPointer dispatchPointerEvent:](
        EventSrcPCPointer *self,
        SEL a2,
        $BD0D23F12DDF06FC72601C9E27B504E8 *a3)
{
  unsigned __int64 v3; // kr00_8
  int v4; // eax
  id v5; // eax
  int v6; // [esp+14h] [ebp-8h] BYREF
  int v7; // [esp+18h] [ebp-4h] BYREF

  objc_msgSend(self->deviceLock, sel_lock); /*0x1a0475*/
  if ( self->inverted ) /*0x1a0494*/
  {
    v7 = -*((char *)a3 + 9); /*0x1a04a3*/
    v6 = *((char *)a3 + 10); /*0x1a04aa*/
  }
  else
  {
    v7 = *((char *)a3 + 9); /*0x1a04b4*/
    v6 = -*((char *)a3 + 10); /*0x1a04bd*/
  }
  v3 = *(_QWORD *)a3 - self->lastTimestamp; /*0x1a04cb*/
  if ( v3 >> 16 <= 0xFFFF ) /*0x1a04ed*/
    v4 = v3 >> 16; /*0x1a04f8*/
  else
    v4 = 0xFFFF; /*0x1a04ef*/
  self->lastTimestamp = *(_QWORD *)a3; /*0x1a04fd*/
  -[EventSrcPCPointer scalePointerInX:andY:over:atRes:]( /*0x1a0524*/
    self,
    sel_scalePointerInX_andY_over_atRes_,
    &v7,
    &v6,
    v4,
    self->resolution);
  objc_msgSend(self->deviceLock, sel_unlock); /*0x1a0569*/
  v5 = -[IOEventSource owner](self, sel_owner); /*0x1a058d*/
  objc_msgSend(v5, sel_relativePointerEvent_deltaX_deltaY_atTime_); /*0x1a0596*/
}
