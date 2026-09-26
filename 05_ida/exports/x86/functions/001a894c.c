/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a894c. */
int __cdecl -[IODirectDevice enableInterrupt:](IODirectDevice *self, SEL a2, unsigned int a3)
{
  if ( -[IODirectDevice attachInterruptPort](self, sel_attachInterruptPort) ) /*0x1a895b*/
    return -729; /*0x1a897c*/
  else
    return -[IODirectDevice _changeInterrupt:to:](self, sel__changeInterrupt_to_, a3, 1); /*0x1a8975*/
}
