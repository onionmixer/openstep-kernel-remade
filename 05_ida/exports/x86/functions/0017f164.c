/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17f164. */
id __cdecl -[KernBusRange dealloc](KernBusRange *self, SEL a2)
{
  id result; // eax
  objc_super v3; // [esp+0h] [ebp-8h] BYREF

  result = self; /*0x17f16a*/
  if ( self->_useCount <= 0 ) /*0x17f171*/
  {
    v3.receiver = self; /*0x17f17a*/
    v3.super_class = (Class)stru_1F9E34.ext; /*0x17f183*/
    return -[Object free](&v3, sel_free); /*0x17f18a*/
  }
  return result; /*0x17f18f*/
}
