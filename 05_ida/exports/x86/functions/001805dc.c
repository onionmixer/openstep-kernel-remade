/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1805dc. */
id __cdecl -[KernDevice interrupt:](KernDevice *self, SEL a2, int a3)
{
  return objc_msgSend(self->_interrupts, sel_objectAt_, a3); /*0x1805f8*/
}
