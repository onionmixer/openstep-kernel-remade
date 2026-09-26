/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12a434. */
void tcp_init()
{
  tcp_iss = 1; /*0x12a437*/
  dword_1EAD14 = (int)&tcb; /*0x12a441*/
  tcb = (int)&tcb; /*0x12a44b*/
}
