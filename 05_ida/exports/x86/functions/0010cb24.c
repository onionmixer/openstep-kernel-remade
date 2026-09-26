/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10cb24. */
long double __cdecl tablefull(const char *a1)
{
  long double v2; // [esp-14h] [ebp-18h]

  printf("%s: table is full\n", a1);
  DWORD2(v2) = a1; /*0x10cb36*/
  DWORD1(v2) = aSTableIsFull_0; /*0x10cb37*/
  LODWORD(v2) = 3; /*0x10cb3c*/
  return log(v2); /*0x10cb43*/
}
