/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aad58. */
int __cdecl en_recv_pkt(int a1, _DWORD *a2, int a3)
{
  int result; // eax

  *a2 = 0; /*0x1aad5e*/
  result = dword_1E8700; /*0x1aad64*/
  if ( dword_1E8700 ) /*0x1aad6b*/
    return dword_1E8708(dword_1E8700, sel_receivePacket_length_timeout_, a1, a2, a3); /*0x1aad83*/
  return result; /*0x1aad87*/
}
