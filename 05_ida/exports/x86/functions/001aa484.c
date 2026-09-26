/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aa484. */
void __cdecl -[IOEthernet setRelativeTimeout:](IOEthernet *self, SEL a2, unsigned int a3)
{
  unsigned __int64 v3; // [esp+Ch] [ebp-Ch]

  if ( LODWORD(self->_absTimeout) || HIDWORD(self->_absTimeout) ) /*0x1aa49c*/
    ns_untimeout((int)sub_1A9F1C, (int)self); /*0x1aa4ab*/
  IOGetTimestamp((int *)&self->_absTimeout); /*0x1aa4ba*/
  v3 = 1000000LL * a3 + self->_absTimeout; /*0x1aa4da*/
  self->_absTimeout = v3; /*0x1aa4e3*/
  ns_abstimeout((int)sub_1A9F1C, (int)self, v3, SHIDWORD(v3)); /*0x1aa500*/
}
