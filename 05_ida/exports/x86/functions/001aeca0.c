/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aeca0. */
int __cdecl -[SCSIGeneric autoSense](SCSIGeneric *self, SEL a2)
{
  return *((_BYTE *)self + 284) & 1; /*0x1aecb1*/
}
