/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a9c44. */
int __cdecl IORemoveFromBdevsw(int a1)
{
  qmemcpy(&bdevsw[6 * a1], &unk_1E512C, 0x18u); /*0x1a9c61*/
  return 3 * a1; /*0x1a9c66*/
}
