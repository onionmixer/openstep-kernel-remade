/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aa3fc. */
unsigned int __cdecl -[IOEthernet relativeTimeout](IOEthernet *self, SEL a2)
{
  __int64 v2; // rax
  unsigned __int64 v4; // [esp+4h] [ebp-8h] BYREF

  if ( LODWORD(self->_absTimeout) || HIDWORD(self->_absTimeout) ) /*0x1aa40f*/
  {
    IOGetTimestamp((int *)&v4); /*0x1aa420*/
    if ( self->_absTimeout > v4 ) /*0x1aa440*/
    {
      return (self->_absTimeout - v4) / 0xF4240; /*0x1aa477*/
    }
    else
    {
      self->_absTimeout = 0; /*0x1aa442*/
      LODWORD(v2) = 0; /*0x1aa456*/
    }
  }
  else
  {
    LODWORD(v2) = 0; /*0x1aa418*/
  }
  return v2; /*0x1aa47c*/
}
