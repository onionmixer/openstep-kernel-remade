/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17ebf0. */
id __cdecl -[KernBusItem free](KernBusItem *self, SEL a2)
{
  int v2; // ecx

  v2 = self->_useCount - 1; /*0x17ebf9*/
  self->_useCount = v2; /*0x17ebfc*/
  if ( v2 > 0 ) /*0x17ec02*/
    return nullptr; /*0x17ec1c*/
  else
    return objc_msgSend(self->_resource, sel__destroyItem_, self); /*0x17ec10*/
}
