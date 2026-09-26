/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ae6f8. */
void __cdecl -[SCSIDisk sdIoComplete:](SCSIDisk *self, SEL a2, $BB0ECD142E749ABD0946980FC80D177E *a3)
{
  void *var6; // eax

  var6 = a3->var6; /*0x1ae703*/
  if ( var6 ) /*0x1ae708*/
  {
    -[SCSIDisk completeTransfer:withStatus:actualLength:]( /*0x1ae71b*/
      self,
      sel_completeTransfer_withStatus_actualLength_,
      var6,
      a3->var11,
      a3->var10);
    -[SCSIDisk freeSdBuf:](self, sel_freeSdBuf_, a3); /*0x1ae729*/
  }
  else
  {
    objc_msgSend(a3->var7, sel_unlockWith_, 1); /*0x1ae73d*/
  }
}
