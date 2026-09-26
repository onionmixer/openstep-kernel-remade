/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17f2fc. */
id __cdecl -[KernBusRangeMapping free](KernBusRangeMapping *self, SEL a2)
{
  id range; // edx
  objc_super v4; // [esp+0h] [ebp-8h] BYREF

  range = self->_range; /*0x17f305*/
  if ( range ) /*0x17f30a*/
  {
    self->_range = nullptr; /*0x17f32c*/
    return objc_msgSend(range, sel__destroyMapping_, self); /*0x17f33c*/
  }
  else
  {
    v4.receiver = self; /*0x17f313*/
    v4.super_class = (Class)stru_1F9E34.super_class; /*0x17f31c*/
    return -[Object free](&v4, sel_free); /*0x17f323*/
  }
}
