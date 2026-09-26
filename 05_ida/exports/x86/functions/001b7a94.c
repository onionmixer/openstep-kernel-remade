/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b7a94. */
unsigned int __cdecl -[AudioChannel setDescriptorSize:](AudioChannel *self, SEL a2, unsigned int a3)
{
  unsigned int v3; // ebx
  unsigned int v4; // eax

  v3 = a3; /*0x1b7a9c*/
  v4 = -[AudioChannel dmaSize](self, sel_dmaSize) / a3; /*0x1b7aae*/
  self->dmaCount = v4; /*0x1b7ab0*/
  if ( v4 - 4 > 0xC ) /*0x1b7abc*/
  {
    self->dmaCount = 8; /*0x1b7abe*/
    v3 = -[AudioChannel dmaSize](self, sel_dmaSize) / self->dmaCount; /*0x1b7ad7*/
  }
  self->descriptorSize = v3; /*0x1b7ad9*/
  return v3; /*0x1b7ae1*/
}
