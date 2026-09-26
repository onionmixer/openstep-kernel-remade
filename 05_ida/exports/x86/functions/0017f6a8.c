/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17f6a8. */
id __cdecl -[KernBus _lookupResourceWithKey:](KernBus *self, SEL a2, const char *a3)
{
  return objc_msgSend(self->_resources, sel_valueForKey_, a3); /*0x17f6c4*/
}
