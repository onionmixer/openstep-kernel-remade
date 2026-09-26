/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17ec84. */
KernBusRangeResource *__cdecl -[KernBusRangeResource initWithExtent:kind:owner:](
        KernBusRangeResource *self,
        SEL a2,
        $85CD2974BE96D4886BB301820D1C36C2 a3,
        id a4,
        id a5)
{
  unsigned int v7; // [esp+Ch] [ebp-Ch]
  objc_super v8; // [esp+10h] [ebp-8h] BYREF

  v7 = a3.var1 + a3.var0; /*0x17ec99*/
  v8.receiver = self; /*0x17eca3*/
  v8.super_class = (Class)stru_1F9E84.super_class; /*0x17ecac*/
  -[Object init](&v8, sel_init); /*0x17ecb3*/
  if ( a3.var1 + a3.var0 && v7 <= a3.var0 ) /*0x17ecc4*/
    return (KernBusRangeResource *)-[KernBusRangeResource free](self, sel_free); /*0x17ecdd*/
  self->_owner = a5; /*0x17ece7*/
  if ( a4 ) /*0x17ecee*/
    self->_kind = a4; /*0x17ecf3*/
  else
    self->_kind = objc_msgSend(&aKernbusrange, sel_class); /*0x17ed0b*/
  self->_rangeCount = 0; /*0x17ed0e*/
  self->_ranges = nullptr; /*0x17ed15*/
  self->_end = v7; /*0x17ed1f*/
  self->_base = a3.var0; /*0x17ed22*/
  return self; /*0x17ed2a*/
}
