/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17f8f0. */
KernBusMemoryRangeMapping *__cdecl -[KernBusMemoryRangeMapping initWithRange:subRange:atAddress:inTarget:cache:](
        KernBusMemoryRangeMapping *self,
        SEL a2,
        id a3,
        $85CD2974BE96D4886BB301820D1C36C2 a4,
        unsigned int a5,
        task *a6,
        int a7)
{
  task *v7; // edi
  int v9; // edx
  id v10; // [esp+Ch] [ebp-10h]
  objc_super v11; // [esp+14h] [ebp-8h] BYREF

  v7 = a6; /*0x17f8fc*/
  if ( !a6 ) /*0x17f901*/
    return (KernBusMemoryRangeMapping *)-[KernBusMemoryRangeMapping free](self, sel_free); /*0x17f90b*/
  v11.receiver = self; /*0x17f92b*/
  v11.super_class = (Class)stru_1F9ED4.ext; /*0x17f934*/
  if ( !-[KernBusRangeMapping initWithRange:subRange:](&v11, sel_initWithRange_subRange_, a3, a4.var0, a4.var1) ) /*0x17f93b*/
    return nullptr; /*0x17f947*/
  v10 = -[KernBusRangeMapping mappedRange](self, sel_mappedRange); /*0x17f959*/
  if ( _KernBusMemoryCreateMapping((int)v10, v9, &a5, (int)v7, 0, a7) ) /*0x17f972*/
    return (KernBusMemoryRangeMapping *)-[KernBusMemoryRangeMapping free](self, sel_free); /*0x17f986*/
  self->_task = v7; /*0x17f990*/
  self->_address = a5; /*0x17f996*/
  return self; /*0x17f99e*/
}
