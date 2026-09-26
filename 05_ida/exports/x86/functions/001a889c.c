/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a889c. */
int __cdecl -[IODirectDevice enableAllInterrupts](IODirectDevice *self, SEL a2)
{
  id v2; // esi
  int v3; // ebx

  v2 = -[IODeviceDescription numInterrupts](self->_deviceDescription, sel_numInterrupts); /*0x1a88b8*/
  v3 = 0; /*0x1a88ba*/
  if ( !v2 ) /*0x1a88c1*/
    return 0; /*0x1a88f5*/
  while ( !-[IODirectDevice enableInterrupt:](self, sel_enableInterrupt_, v3) ) /*0x1a88d7*/
  {
    if ( ++v3 >= (unsigned int)v2 ) /*0x1a88f3*/
      return 0; /*0x1a88f3*/
  }
  -[IODirectDevice disableAllInterrupts](self, sel_disableAllInterrupts); /*0x1a88e1*/
  return -729; /*0x1a88fa*/
}
