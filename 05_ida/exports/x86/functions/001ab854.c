/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ab854. */
int __cdecl -[IOTokenRing finishInitialization](IOTokenRing *self, SEL a2)
{
  int result; // eax

  result = 0; /*0x1ab85a*/
  if ( (*(_BYTE *)&self->_flags & 1) == 0 ) /*0x1ab863*/
    return (int)objc_msgSend(self->_driverCmd, sel_send_, 1); /*0x1ab875*/
  return result; /*0x1ab87c*/
}
