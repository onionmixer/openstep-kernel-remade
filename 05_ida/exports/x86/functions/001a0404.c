/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a0404. */
id __cdecl -[EventSrcPCPointer resetPointer](EventSrcPCPointer *self, SEL a2)
{
  objc_msgSend(self->deviceLock, sel_lock); /*0x1a0419*/
  self->buttonMode = 0; /*0x1a041e*/
  objc_msgSend(self->deviceLock, sel_unlock); /*0x1a0436*/
  -[EventSrcPCPointer setPointerScaling:data:](self, sel_setPointerScaling_data_, 5, &unk_1D58BC); /*0x1a044a*/
  return self; /*0x1a0451*/
}
