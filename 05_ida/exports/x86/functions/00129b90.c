/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x129b90. */
int __cdecl tcp_xmit_timer(_WORD *a1)
{
  __int16 v1; // dx
  __int16 v2; // cx
  __int16 v3; // ax
  __int16 v4; // cx
  unsigned __int16 v5; // si
  int result; // eax

  ++dword_1EED8C; /*0x129b99*/
  v1 = a1[48]; /*0x129b9f*/
  if ( v1 ) /*0x129ba6*/
  {
    v2 = a1[45] - ((v1 >> 3) + 1); /*0x129bb4*/
    a1[48] = v2 + v1; /*0x129bbc*/
    if ( (__int16)(v2 + v1) <= 0 ) /*0x129bc3*/
      a1[48] = 1; /*0x129bc5*/
    if ( v2 < 0 ) /*0x129bce*/
      v2 = -v2; /*0x129bd0*/
    v3 = v2 - ((__int16)a1[49] >> 2) + a1[49]; /*0x129be0*/
    a1[49] = v3; /*0x129be3*/
    if ( v3 <= 0 ) /*0x129bea*/
      a1[49] = 1; /*0x129bec*/
  }
  else
  {
    a1[48] = 8 * a1[45]; /*0x129bfc*/
    a1[49] = 2 * a1[45]; /*0x129c07*/
  }
  a1[45] = 0; /*0x129c0b*/
  a1[9] = 0; /*0x129c11*/
  v4 = a1[49] + ((__int16)a1[48] >> 3); /*0x129c21*/
  a1[10] = v4; /*0x129c25*/
  v5 = a1[50]; /*0x129c2c*/
  result = v5; /*0x129c30*/
  if ( v4 >= (int)v5 ) /*0x129c35*/
  {
    if ( v4 > 128 ) /*0x129c45*/
      a1[10] = 128; /*0x129c47*/
  }
  else
  {
    a1[10] = v5; /*0x129c37*/
  }
  a1[53] = 0; /*0x129c4d*/
  return result; /*0x129c56*/
}
