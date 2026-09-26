/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a8830. */
void __cdecl -[IODirectDevice receiveMsg](IODirectDevice *self, SEL a2)
{
  _DWORD v2[6]; // [esp+0h] [ebp-18h] BYREF

  if ( self->_interruptPort ) /*0x1a8839*/
  {
    v2[1] = 24; /*0x1a8842*/
    v2[3] = self->_interruptPort; /*0x1a884f*/
    msg_receive(v2, 0, 0); /*0x1a885a*/
  }
}
