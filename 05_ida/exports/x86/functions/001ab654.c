/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ab654. */
void __cdecl -[IOTokenRing setRunning:](IOTokenRing *self, SEL a2, char a3)
{
  *(_BYTE *)&self->_flags = a3 & 1 | *(_BYTE *)&self->_flags & 0xFE; /*0x1ab66b*/
}
