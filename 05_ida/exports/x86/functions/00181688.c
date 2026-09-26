/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x181688. */
char __cdecl -[KernDeviceDescription nextResourcesState:key:value:](
        KernDeviceDescription *self,
        SEL a2,
        $2825F4736939C4A6D3AD43837233062D *a3,
        const char **a4,
        id *a5)
{
  return (unsigned __int8)objc_msgSend(self->_resourceTable, sel_nextState_key_value_, a3, a4, a5); /*0x1816af*/
}
