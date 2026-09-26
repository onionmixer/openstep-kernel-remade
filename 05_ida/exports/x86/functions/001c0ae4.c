/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c0ae4. */
unsigned int __cdecl -[IODirectDevice _localToChannel:](IODirectDevice *self, SEL a2, unsigned int a3)
{
  return *((_DWORD *)-[IODeviceDescription channelList](self->_deviceDescription, sel_channelList) + a3); /*0x1c0b04*/
}
