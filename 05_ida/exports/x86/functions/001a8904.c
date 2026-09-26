/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a8904. */
void __cdecl -[IODirectDevice disableAllInterrupts](IODirectDevice *self, SEL a2)
{
  id v2; // esi
  unsigned int v3; // ebx

  v2 = -[IODeviceDescription numInterrupts](self->_deviceDescription, sel_numInterrupts); /*0x1a8920*/
  v3 = 0; /*0x1a8922*/
  if ( v2 ) /*0x1a8929*/
  {
    do /*0x1a8940*/
      -[IODirectDevice disableInterrupt:](self, sel_disableInterrupt_, v3++); /*0x1a8935*/
    while ( v3 < (unsigned int)v2 ); /*0x1a8940*/
  }
}
