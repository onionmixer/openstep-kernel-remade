/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13d810. */
long double __cdecl fserr(int a1, int a2)
{
  long double v3; // [esp-10h] [ebp-10h]

  HIDWORD(v3) = a2; /*0x13d816*/
  DWORD2(v3) = a1 + 212; /*0x13d81f*/
  DWORD1(v3) = aSS_2; /*0x13d820*/
  LODWORD(v3) = 3; /*0x13d825*/
  return log(v3); /*0x13d82e*/
}
