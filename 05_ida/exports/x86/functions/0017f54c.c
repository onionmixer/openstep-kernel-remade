/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17f54c. */
id __cdecl -[KernBus free](KernBus *self, SEL a2)
{
  id result; // eax
  objc_super v3; // [esp+0h] [ebp-8h] BYREF

  result = self; /*0x17f552*/
  if ( self->_activeResourceCount <= 0 ) /*0x17f559*/
  {
    v3.receiver = self; /*0x17f562*/
    v3.super_class = (Class)stru_1F9DE4.ext; /*0x17f56b*/
    return -[Object free](&v3, sel_free); /*0x17f572*/
  }
  return result; /*0x17f577*/
}
