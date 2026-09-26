/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17f664. */
id __cdecl -[KernBus _deleteResourceWithKey:](KernBus *self, SEL a2, const char *a3)
{
  void *resources; // esi
  id v4; // ebx

  resources = self->_resources; /*0x17f670*/
  v4 = objc_msgSend(resources, sel_valueForKey_, a3); /*0x17f681*/
  if ( !v4 ) /*0x17f688*/
    return nullptr; /*0x17f69c*/
  objc_msgSend(resources, sel_removeKey_, a3); /*0x17f693*/
  return v4; /*0x17f6a1*/
}
