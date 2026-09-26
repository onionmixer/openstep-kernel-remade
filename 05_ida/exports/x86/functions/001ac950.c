/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ac950. */
void __cdecl -[SCSIDisk abortRequest](SCSIDisk *self, SEL a2)
{
  $BB0ECD142E749ABD0946980FC80D177E *v2; // esi

  v2 = -[SCSIDisk allocSdBuf:](self, sel_allocSdBuf_, 0); /*0x1ac967*/
  v2->var0 = 5; /*0x1ac969*/
  *((_BYTE *)v2 + 32) &= ~1u; /*0x1ac96f*/
  -[SCSIDisk enqueueSdBuf:](self, sel_enqueueSdBuf_, v2); /*0x1ac97c*/
  -[SCSIDisk freeSdBuf:](self, sel_freeSdBuf_, v2); /*0x1ac98a*/
}
