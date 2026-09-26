/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a86fc. */
int __cdecl -[IODirectDevice startIOThreadWithFixedPriority:](IODirectDevice *self, SEL a2, int a3)
{
  id v3; // ebx

  v3 = nullptr; /*0x1a8704*/
  if ( !self->_ioThread ) /*0x1a8706*/
  {
    v3 = -[IODirectDevice startIOThreadWithPriority:](self, sel_startIOThreadWithPriority_, a3); /*0x1a8720*/
    if ( !v3 ) /*0x1a8727*/
      IOSetThreadPolicy(self->_ioThread, 2); /*0x1a8732*/
  }
  return (int)v3; /*0x1a873c*/
}
