/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c0ea8. */
unsigned int __cdecl -[IODirectDevice currentCountForChannel:](IODirectDevice *self, SEL a2, unsigned int a3)
{
  id v3; // eax

  if ( a3 >= (unsigned int)-[IODeviceDescription numChannels](self->_deviceDescription, sel_numChannels) ) /*0x1c0ecb*/
    return 0; /*0x1c0ee4*/
  v3 = -[IODirectDevice _localToChannel:](self, sel__localToChannel_, a3); /*0x1c0ed6*/
  return get_dma_count((int)v3); /*0x1c0ee9*/
}
