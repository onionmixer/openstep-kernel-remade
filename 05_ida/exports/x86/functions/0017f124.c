/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17f124. */
id __cdecl -[KernBusRange free](KernBusRange *self, SEL a2)
{
  int v3; // ecx

  if ( self->_mappingCount > 0 ) /*0x17f12e*/
    return self; /*0x17f130*/
  v3 = self->_useCount - 1; /*0x17f13b*/
  self->_useCount = v3; /*0x17f13e*/
  if ( v3 > 0 ) /*0x17f144*/
    return nullptr; /*0x17f15c*/
  else
    return objc_msgSend(self->_resource, sel__destroyRange_, self); /*0x17f152*/
}
