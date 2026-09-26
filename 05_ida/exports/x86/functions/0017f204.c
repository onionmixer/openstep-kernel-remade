/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17f204. */
KernBusRangeMapping *__cdecl -[KernBusRangeMapping initWithRange:subRange:](
        KernBusRangeMapping *self,
        SEL a2,
        id a3,
        $85CD2974BE96D4886BB301820D1C36C2 a4)
{
  char *v6; // eax
  int v7; // edx
  char *v8; // edx
  unsigned int v9; // eax
  int v10; // [esp+14h] [ebp-Ch]
  objc_super v11; // [esp+18h] [ebp-8h] BYREF

  if ( !a3 ) /*0x17f217*/
    return (KernBusRangeMapping *)-[KernBusRangeMapping free](self, sel_free); /*0x17f224*/
  v11.receiver = self; /*0x17f23a*/
  v11.super_class = (Class)stru_1F9E34.super_class; /*0x17f243*/
  -[Object init](&v11, sel_init); /*0x17f24a*/
  if ( a4.var1 + a4.var0 && a4.var1 + a4.var0 <= a4.var0 ) /*0x17f25b*/
    return (KernBusRangeMapping *)-[KernBusRangeMapping free](self, sel_free); /*0x17f26b*/
  v6 = (char *)objc_msgSend(a3, sel_range); /*0x17f28b*/
  v10 = v7; /*0x17f293*/
  v8 = v6; /*0x17f296*/
  v9 = (unsigned int)&v6[v10]; /*0x17f29c*/
  if ( &v8[a4.var0] < v8 || v9 && (unsigned int)&v8[a4.var0 + a4.var1] > v9 ) /*0x17f2b7*/
    return (KernBusRangeMapping *)-[KernBusRangeMapping free](self, sel_free); /*0x17f278*/
  self->_range = a3; /*0x17f2d2*/
  self->_mappedRange.base = (unsigned int)&v8[a4.var0]; /*0x17f2d8*/
  self->_mappedRange.length = a4.var1; /*0x17f2db*/
  objc_msgSend(a3, sel__addMapping); /*0x17f2e9*/
  return self; /*0x17f2f4*/
}
