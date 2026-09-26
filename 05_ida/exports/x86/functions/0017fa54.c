/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17fa54. */
id __cdecl -[KernBusMemoryRangeMapping free](KernBusMemoryRangeMapping *self, SEL a2)
{
  vm_size_t v2; // edx
  task *task; // ecx
  objc_super v5; // [esp+8h] [ebp-8h] BYREF

  -[KernBusRangeMapping mappedRange](self, sel_mappedRange); /*0x17fa67*/
  task = self->_task; /*0x17fa6f*/
  if ( task ) /*0x17fa74*/
    vm_deallocate((vm_map_t)task->var3, self->_address, v2); /*0x17fa7f*/
  v5.receiver = self; /*0x17fa8e*/
  v5.super_class = (Class)stru_1F9ED4.ext; /*0x17fa97*/
  return -[KernBusRangeMapping free](&v5, sel_free); /*0x17faa6*/
}
