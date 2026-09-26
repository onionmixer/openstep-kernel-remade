/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a0a7c. */
void __cdecl -[EventSrcPCPointer setResolution:](EventSrcPCPointer *self, SEL a2, unsigned int a3)
{
  self->resolution = a3; /*0x1a0a86*/
  if ( !a3 ) /*0x1a0a8e*/
    self->resolution = 72; /*0x1a0a90*/
  self->resScaling = 0x4800 / self->resolution; /*0x1a0aa7*/
}
