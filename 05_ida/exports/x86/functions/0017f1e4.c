/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17f1e4. */
id __cdecl -[KernBusRange _destroyMapping:](KernBusRange *self, SEL a2, id a3)
{
  --self->_mappingCount; /*0x17f1ea*/
  return objc_msgSend(a3, sel_free); /*0x17f1ff*/
}
