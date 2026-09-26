/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17f84c. */
id __cdecl -[KernBusMemoryRange mapToAddress:inTarget:cache:](
        KernBusMemoryRange *self,
        SEL a2,
        unsigned int a3,
        task *a4,
        int a5)
{
  KernBusMemoryRangeMapping *v5; // eax

  -[KernBusRange range](self, sel_range); /*0x17f863*/
  v5 = +[Object alloc](aKernbusmemoryr, sel_alloc); /*0x17f888*/
  return -[KernBusMemoryRangeMapping initWithRange:subRange:atAddress:inTarget:cache:]( /*0x17f899*/
           v5,
           sel_initWithRange_subRange_atAddress_inTarget_cache_);
}
