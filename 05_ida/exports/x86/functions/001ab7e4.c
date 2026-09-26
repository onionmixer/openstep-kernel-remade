/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ab7e4. */
char __cdecl -[IOTokenRing shouldAutoRecover](IOTokenRing *self, SEL a2)
{
  return (*(_BYTE *)&self->_flags & 4) != 0; /*0x1ab7f8*/
}
