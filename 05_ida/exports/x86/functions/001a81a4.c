/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a81a4. */
id __cdecl -[IODeviceDescription _initWithDelegate:](IODeviceDescription *self, SEL a2, id a3)
{
  void *v3; // eax

  v3 = (void *)IOMalloc(0x10u); /*0x1a81b1*/
  self->_private = v3; /*0x1a81b6*/
  bzero(v3, 0x10u); /*0x1a81bc*/
  self->_delegate = a3; /*0x1a81c1*/
  return self; /*0x1a81c9*/
}
