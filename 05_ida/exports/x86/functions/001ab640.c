/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ab640. */
char __cdecl -[IOTokenRing isRunning](IOTokenRing *self, SEL a2)
{
  return *(_BYTE *)&self->_flags & 1; /*0x1ab651*/
}
