/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ab7cc. */
char __cdecl -[IOTokenRing earlyTokenEnabled](IOTokenRing *self, SEL a2)
{
  return (*(_BYTE *)&self->_flags & 2) != 0; /*0x1ab7df*/
}
