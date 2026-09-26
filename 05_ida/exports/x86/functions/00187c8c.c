/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x187c8c. */
void __cdecl set_timer(int a1, __int64 a2)
{
  int v2; // eax

  if ( !a1 ) /*0x187c99*/
  {
    v2 = splusclock(); /*0x187d14*/
    qword_1E75DC = qword_1E75D0 + 10000000 * ((a2 + 9999999) / 0x989680uLL); /*0x187d2f*/
    splx(v2); /*0x187d36*/
  }
}
