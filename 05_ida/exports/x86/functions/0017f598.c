/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17f598. */
id __cdecl +[KernBus deviceDescriptionFromConfigTable:](id a1, SEL a2, id a3)
{
  KernDeviceDescription *v3; // eax

  v3 = +[Object alloc](aKerndevicedesc, sel_alloc); /*0x17f5b4*/
  return -[KernDeviceDescription initFromConfigTable:](v3, sel_initFromConfigTable_); /*0x17f5c4*/
}
