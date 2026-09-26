/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17eb4c. */
id __cdecl -[KernBusItem initForResource:item:shareable:](KernBusItem *self, SEL a2, id a3, unsigned int a4, char a5)
{
  objc_super v6; // [esp+Ch] [ebp-8h] BYREF

  v6.receiver = self; /*0x17eb6b*/
  v6.super_class = (Class)stru_1F9E84.ext; /*0x17eb74*/
  if ( !a3 ) /*0x17eb62*/
    return -[Object free](&v6, sel_free); /*0x17eb7b*/
  -[Object init](&v6, sel_init); /*0x17eb9b*/
  self->_resource = a3; /*0x17eba0*/
  self->_item = a4; /*0x17eba6*/
  self->_useCount = 1; /*0x17eba9*/
  self->_shareable = a5; /*0x17ebb3*/
  return self; /*0x17ebbb*/
}
