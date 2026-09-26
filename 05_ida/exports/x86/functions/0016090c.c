/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16090c. */
int __cdecl microboot(_DWORD *a1)
{
  __int64 v1; // rax
  unsigned __int64 v2; // rtt
  int result; // eax

  v1 = clock_value(1); /*0x16091a*/
  LODWORD(v2) = v1; /*0x16093d*/
  HIDWORD(v2) = HIDWORD(v1) % 0x3B9ACA00; /*0x16093d*/
  a1[1] = v2 % 0x3B9ACA00; /*0x16093f*/
  *a1 = v2 / 0x3B9ACA00; /*0x160945*/
  result = a1[1] / 1000; /*0x160952*/
  a1[1] = result; /*0x160956*/
  return result; /*0x16095c*/
}
