/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a86a4. */
int __cdecl -[IODirectDevice startIOThreadWithPriority:](IODirectDevice *self, SEL a2, int a3)
{
  id v3; // ebx
  void *v4; // eax

  v3 = nullptr; /*0x1a86b0*/
  if ( !self->_ioThread ) /*0x1a86b2*/
  {
    v3 = -[IODirectDevice attachInterruptPort](self, sel_attachInterruptPort); /*0x1a86c8*/
    if ( !v3 ) /*0x1a86cf*/
    {
      v4 = (void *)IOForkThread(sub_1A82E8, self); /*0x1a86d7*/
      self->_ioThread = v4; /*0x1a86dc*/
      if ( a3 >= 0 ) /*0x1a86e7*/
        IOSetThreadPriority(v4, a3); /*0x1a86eb*/
    }
  }
  return (int)v3; /*0x1a86f5*/
}
