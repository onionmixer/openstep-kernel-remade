/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17ed34. */
id __cdecl -[KernBusRangeResource free](KernBusRangeResource *self, SEL a2)
{
  id result; // eax
  objc_super v3; // [esp+0h] [ebp-8h] BYREF

  result = self; /*0x17ed3a*/
  if ( self->_rangeCount <= 0 ) /*0x17ed41*/
  {
    v3.receiver = self; /*0x17ed4a*/
    v3.super_class = (Class)stru_1F9E84.super_class; /*0x17ed53*/
    return -[Object free](&v3, sel_free); /*0x17ed5a*/
  }
  return result; /*0x17ed5f*/
}
