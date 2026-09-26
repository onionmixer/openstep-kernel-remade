/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17ec24. */
id __cdecl -[KernBusItem dealloc](KernBusItem *self, SEL a2)
{
  id result; // eax
  objc_super v3; // [esp+0h] [ebp-8h] BYREF

  result = self; /*0x17ec2a*/
  if ( self->_useCount <= 0 ) /*0x17ec31*/
  {
    v3.receiver = self; /*0x17ec3a*/
    v3.super_class = (Class)stru_1F9E84.ext; /*0x17ec43*/
    return -[Object free](&v3, sel_free); /*0x17ec4a*/
  }
  return result; /*0x17ec4f*/
}
