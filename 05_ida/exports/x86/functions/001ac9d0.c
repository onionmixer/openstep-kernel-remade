/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ac9d0. */
int __cdecl -[SCSIDisk isDiskReady:](SCSIDisk *self, SEL a2, char a3)
{
  $BB0ECD142E749ABD0946980FC80D177E *v4; // ebx
  id v5; // esi

  if ( !-[IODisk lastReadyState](self, sel_lastReadyState) ) /*0x1ac9e4*/
    return 0; /*0x1ac9f0*/
  if ( !a3 ) /*0x1ac9f6*/
    return -1102; /*0x1aca38*/
  v4 = -[SCSIDisk allocSdBuf:](self, sel_allocSdBuf_, 0); /*0x1aca07*/
  v4->var0 = 6; /*0x1aca09*/
  *((_BYTE *)v4 + 32) |= 1u; /*0x1aca0f*/
  v5 = -[SCSIDisk enqueueSdBuf:](self, sel_enqueueSdBuf_, v4); /*0x1aca21*/
  -[SCSIDisk freeSdBuf:](self, sel_freeSdBuf_, v4); /*0x1aca2c*/
  return (int)v5; /*0x1aca40*/
}
