/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ab678. */
unsigned int __cdecl -[IOTokenRing relativeTimeout](IOTokenRing *self, SEL a2)
{
  __int64 v2; // rax
  unsigned __int64 v4; // [esp+4h] [ebp-8h] BYREF

  if ( LODWORD(self->_absTimeout) || HIDWORD(self->_absTimeout) ) /*0x1ab68b*/
  {
    IOGetTimestamp((int *)&v4); /*0x1ab69c*/
    if ( self->_absTimeout > v4 ) /*0x1ab6bc*/
    {
      return (self->_absTimeout - v4) / 0xF4240; /*0x1ab6f3*/
    }
    else
    {
      self->_absTimeout = 0; /*0x1ab6be*/
      LODWORD(v2) = 0; /*0x1ab6d2*/
    }
  }
  else
  {
    LODWORD(v2) = 0; /*0x1ab694*/
  }
  return v2; /*0x1ab6f8*/
}
