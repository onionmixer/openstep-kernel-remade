/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17f9a8. */
KernBusMemoryRangeMapping *__cdecl -[KernBusMemoryRangeMapping initWithRange:subRange:inTarget:cache:](
        KernBusMemoryRangeMapping *self,
        SEL a2,
        id a3,
        $85CD2974BE96D4886BB301820D1C36C2 a4,
        task *a5,
        int a6)
{
  int v7; // edx
  id v8; // [esp+Ch] [ebp-10h]
  objc_super v9; // [esp+14h] [ebp-8h] BYREF

  if ( !a5 ) /*0x17f9b9*/
    return (KernBusMemoryRangeMapping *)-[KernBusMemoryRangeMapping free](self, sel_free); /*0x17f9c3*/
  v9.receiver = self; /*0x17f9df*/
  v9.super_class = (Class)stru_1F9ED4.ext; /*0x17f9e8*/
  if ( !-[KernBusRangeMapping initWithRange:subRange:](&v9, sel_initWithRange_subRange_, a3, a4.var0, a4.var1) ) /*0x17f9ef*/
    return nullptr; /*0x17f9fb*/
  v8 = -[KernBusRangeMapping mappedRange](self, sel_mappedRange); /*0x17fa0d*/
  if ( _KernBusMemoryCreateMapping((int)v8, v7, &self->_address, (int)a5, 1, a6) ) /*0x17fa26*/
    return (KernBusMemoryRangeMapping *)-[KernBusMemoryRangeMapping free](self, sel_free); /*0x17fa3a*/
  self->_task = a5; /*0x17fa44*/
  return self; /*0x17fa4c*/
}
