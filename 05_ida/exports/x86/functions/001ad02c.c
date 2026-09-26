/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ad02c. */
id __cdecl -[SCSIDisk free](SCSIDisk *self, SEL a2)
{
  $BB0ECD142E749ABD0946980FC80D177E *v2; // esi
  int i; // ebx
  objc_super v5; // [esp+Ch] [ebp-8h] BYREF

  v2 = -[SCSIDisk allocSdBuf:](self, sel_allocSdBuf_, 0); /*0x1ad047*/
  v2->var0 = 7; /*0x1ad049*/
  *((_BYTE *)v2 + 32) &= ~1u; /*0x1ad04f*/
  for ( i = 0; self->_numThreads > i; ++i ) /*0x1ad05e*/
    -[SCSIDisk enqueueSdBuf:](self, sel_enqueueSdBuf_, v2); /*0x1ad069*/
  -[SCSIDisk freeSdBuf:](self, sel_freeSdBuf_, v2); /*0x1ad083*/
  if ( (*((_BYTE *)self + 394) & 1) != 0 ) /*0x1ad092*/
    objc_msgSend(self->_controller, sel_releaseTarget_lun_forOwner_, self->_target, self->_lun, self); /*0x1ad0b3*/
  objc_msgSend(self->_ioQLock, sel_free); /*0x1ad0c9*/
  v5.receiver = self; /*0x1ad0d5*/
  v5.super_class = objc_getOrigClass("IODisk"); /*0x1ad0e5*/
  return -[IODevice free](&v5, sel_free); /*0x1ad0f4*/
}
