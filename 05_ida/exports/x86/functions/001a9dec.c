/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a9dec. */
int __cdecl IORemoveFromCdevsw(int a1)
{
  qmemcpy(&cdevsw + 11 * a1, &unk_1E5100, 0x2Cu); /*0x1a9e0c*/
  return a1; /*0x1a9e11*/
}
