/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17f070. */
id __cdecl -[KernBusRange initForResource:range:shareable:](
        KernBusRange *self,
        SEL a2,
        id a3,
        $85CD2974BE96D4886BB301820D1C36C2 a4,
        char a5)
{
  objc_super v6; // [esp+10h] [ebp-8h] BYREF

  v6.receiver = self; /*0x17f095*/
  v6.super_class = (Class)stru_1F9E34.ext; /*0x17f09e*/
  if ( !a3 ) /*0x17f08c*/
    return -[Object free](&v6, sel_free); /*0x17f0a5*/
  -[Object init](&v6, sel_init); /*0x17f0c3*/
  self->_resource = a3; /*0x17f0cb*/
  self->_base = a4.var0; /*0x17f0ce*/
  self->_end = a4.var1 + a4.var0; /*0x17f0d5*/
  self->_useCount = 1; /*0x17f0d8*/
  self->_shareable = a5; /*0x17f0e2*/
  self->_mappingCount = 0; /*0x17f0e5*/
  return self; /*0x17f0f1*/
}
