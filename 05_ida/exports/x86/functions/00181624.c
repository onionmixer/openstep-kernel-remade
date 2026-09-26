/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x181624. */
$2825F4736939C4A6D3AD43837233062D __cdecl -[KernDeviceDescription initStringState](KernDeviceDescription *self, SEL a2)
{
  $2825F4736939C4A6D3AD43837233062D result; // rax

  result.var0 = (int)objc_msgSend(self->_stringTable, sel_initState); /*0x181635*/
  return result; /*0x18163c*/
}
