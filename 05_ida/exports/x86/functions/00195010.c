/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x195010. */
int __cdecl dectohexdec(int a1)
{
  return (char)((a1 % 10) & 0xF | (16 * (a1 / 10))); /*0x19502b*/
}
