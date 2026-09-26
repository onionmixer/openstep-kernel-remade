/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17f8a0. */
id __cdecl -[KernBusMemoryRange mapInTarget:cache:](KernBusMemoryRange *self, SEL a2, task *a3, int a4)
{
  KernBusMemoryRangeMapping *v4; // eax

  -[KernBusRange range](self, sel_range); /*0x17f8b7*/
  v4 = +[Object alloc](aKernbusmemoryr, sel_alloc); /*0x17f8d8*/
  return -[KernBusMemoryRangeMapping initWithRange:subRange:inTarget:cache:]( /*0x17f8e9*/
           v4,
           sel_initWithRange_subRange_inTarget_cache_);
}
