/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ad880. */
void __cdecl -[SCSIDisk freeSdBuf:](SCSIDisk *self, SEL a2, $BB0ECD142E749ABD0946980FC80D177E *a3)
{
  if ( !a3->var6 ) /*0x1ad887*/
    objc_msgSend(a3->var7, sel_free); /*0x1ad898*/
  IOFree((int)a3, 68); /*0x1ad8a3*/
}
