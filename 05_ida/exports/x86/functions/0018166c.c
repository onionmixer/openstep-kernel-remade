/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18166c. */
$2825F4736939C4A6D3AD43837233062D __cdecl -[KernDeviceDescription initResourcesState](
        KernDeviceDescription *self,
        SEL a2)
{
  $2825F4736939C4A6D3AD43837233062D result; // rax

  result.var0 = (int)objc_msgSend(self->_resourceTable, sel_initState); /*0x18167d*/
  return result; /*0x181684*/
}
