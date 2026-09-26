/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x160798. */
int __cdecl get_calendar_time_value(_DWORD *a1)
{
  __int64 v1; // rax
  unsigned __int64 v2; // rtt
  int result; // eax

  v1 = clock_value(0); /*0x1607a6*/
  LODWORD(v2) = v1; /*0x1607c9*/
  HIDWORD(v2) = HIDWORD(v1) % 0x3B9ACA00; /*0x1607c9*/
  a1[1] = v2 % 0x3B9ACA00; /*0x1607cb*/
  *a1 = v2 / 0x3B9ACA00; /*0x1607d1*/
  result = a1[1] / 1000; /*0x1607de*/
  a1[1] = result; /*0x1607e2*/
  return result; /*0x1607e8*/
}
