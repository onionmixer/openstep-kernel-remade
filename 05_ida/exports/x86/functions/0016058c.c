/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16058c. */
int __cdecl ns_time_to_timeval(unsigned int a1, unsigned int a2, _DWORD *a3)
{
  int result; // eax

  a3[1] = __PAIR64__(a2 % 0x3B9ACA00, a1) % 0x3B9ACA00; /*0x1605bf*/
  *a3 = __PAIR64__(a2 % 0x3B9ACA00, a1) / 0x3B9ACA00; /*0x1605c5*/
  result = a3[1] / 1000; /*0x1605d2*/
  a3[1] = result; /*0x1605d6*/
  return result; /*0x1605dc*/
}
