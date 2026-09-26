/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17f198. */
id __cdecl -[KernBusRange share](KernBusRange *self, SEL a2)
{
  id result; // eax

  result = self; /*0x17f19b*/
  if ( !self->_shareable ) /*0x17f19e*/
    return nullptr; /*0x17f1ac*/
  ++self->_useCount; /*0x17f1a4*/
  return result; /*0x17f1a9*/
}
