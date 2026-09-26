/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x160844. */
int __cdecl microtime(_DWORD *a1)
{
  unsigned __int64 v1; // kr00_8
  unsigned __int64 v2; // rtt
  int result; // eax
  int v4; // [esp+20h] [ebp-10h]

  v4 = splusclock(); /*0x160855*/
  v1 = clock_value(0); /*0x160861*/
  if ( qword_1DF21C > v1 && qword_1DF21C - v1 <= 0x3B9AC9FF ) /*0x1608ad*/
    v1 = qword_1DF21C; /*0x1608b2*/
  qword_1DF21C = v1; /*0x1608b5*/
  splx(v4); /*0x1608c5*/
  LODWORD(v2) = v1; /*0x1608e4*/
  HIDWORD(v2) = HIDWORD(v1) % 0x3B9ACA00; /*0x1608e4*/
  a1[1] = v2 % 0x3B9ACA00; /*0x1608e6*/
  *a1 = v2 / 0x3B9ACA00; /*0x1608ec*/
  result = a1[1] / 1000; /*0x1608f9*/
  a1[1] = result; /*0x1608fd*/
  return result; /*0x160903*/
}
