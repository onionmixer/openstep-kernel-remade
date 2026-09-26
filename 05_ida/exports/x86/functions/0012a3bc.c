/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12a3bc. */
__int16 __cdecl tcp_setpersist(_WORD *a1)
{
  __int16 v1; // ax
  __int16 result; // ax

  if ( a1[5] ) /*0x12a3d7*/
    panic(aTcpOutputRexmt); /*0x12a3e3*/
  a1[6] = tcp_backoff[2 * (__int16)a1[9]] * (((__int16)a1[49] + ((__int16)a1[48] >> 2)) >> 1); /*0x12a3f5*/
  v1 = a1[6]; /*0x12a3f9*/
  if ( v1 > 9 ) /*0x12a401*/
  {
    if ( v1 > 120 ) /*0x12a410*/
      a1[6] = 120; /*0x12a412*/
  }
  else
  {
    a1[6] = 10; /*0x12a403*/
  }
  result = a1[9]; /*0x12a418*/
  if ( result <= 11 ) /*0x12a420*/
    a1[9] = ++result; /*0x12a424*/
  return result; /*0x12a42b*/
}
