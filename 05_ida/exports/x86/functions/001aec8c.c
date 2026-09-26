/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aec8c. */
int __cdecl -[SCSIGeneric disableAutoSense](SCSIGeneric *self, SEL a2)
{
  *((_BYTE *)self + 284) &= ~1u; /*0x1aec92*/
  return 0; /*0x1aec9d*/
}
