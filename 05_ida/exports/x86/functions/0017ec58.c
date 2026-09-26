/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17ec58. */
id __cdecl -[KernBusItem share](KernBusItem *self, SEL a2)
{
  id result; // eax

  result = self; /*0x17ec5b*/
  if ( !self->_shareable ) /*0x17ec5e*/
    return nullptr; /*0x17ec6c*/
  ++self->_useCount; /*0x17ec64*/
  return result; /*0x17ec69*/
}
