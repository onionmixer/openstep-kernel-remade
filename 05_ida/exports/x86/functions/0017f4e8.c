/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17f4e8. */
KernBus *__cdecl -[KernBus init](KernBus *self, SEL a2)
{
  HashTable *v2; // eax
  objc_super v4; // [esp+4h] [ebp-8h] BYREF

  v4.receiver = self; /*0x17f4f9*/
  v4.super_class = (Class)stru_1F9DE4.ext; /*0x17f502*/
  -[Object init](&v4, sel_init); /*0x17f509*/
  if ( !self->_resources ) /*0x17f511*/
  {
    v2 = +[Object alloc](aHashtable, sel_alloc); /*0x17f531*/
    self->_resources = -[HashTable initKeyDesc:](v2, sel_initKeyDesc_); /*0x17f53f*/
  }
  return self; /*0x17f544*/
}
