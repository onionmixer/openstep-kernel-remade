/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ab700. */
void __cdecl -[IOTokenRing setRelativeTimeout:](IOTokenRing *self, SEL a2, unsigned int a3)
{
  unsigned __int64 v3; // [esp+Ch] [ebp-Ch]

  if ( LODWORD(self->_absTimeout) || HIDWORD(self->_absTimeout) ) /*0x1ab718*/
    ns_untimeout((int)sub_1AAEA0, (int)self); /*0x1ab727*/
  IOGetTimestamp((int *)&self->_absTimeout); /*0x1ab736*/
  v3 = 1000000LL * a3 + self->_absTimeout; /*0x1ab756*/
  self->_absTimeout = v3; /*0x1ab75f*/
  ns_abstimeout((int)sub_1AAEA0, (int)self, v3, SHIDWORD(v3)); /*0x1ab77c*/
}
