/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10c1c0. */
long double __cdecl log(long double __x)
{
  int v1; // esi
  long double result; // fst7

  v1 = splhigh(); /*0x10c1d1*/
  sub_10C248(LODWORD(__x)); /*0x10c1d4*/
  prf(DWORD1(__x), (char *)&__x + 8, 4, 0); /*0x10c1e2*/
  splx(v1); /*0x10c1e8*/
  if ( !log_open ) /*0x10c1f7*/
    prf(DWORD1(__x), (char *)&__x + 8, 1, 0); /*0x10c1ff*/
  logwakeup(); /*0x10c207*/
  splx(v1); /*0x10c20d*/
  return result; /*0x10c217*/
}
