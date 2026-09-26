/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18b514. */
int intr_disbl()
{
  unsigned int v0; // kr00_4

  v0 = __readeflags(); /*0x18b517*/
  _disable(); /*0x18b519*/
  return (v0 >> 9) & 1; /*0x18b522*/
}
