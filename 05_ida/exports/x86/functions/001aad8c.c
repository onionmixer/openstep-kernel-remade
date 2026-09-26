/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aad8c. */
int __cdecl en_send_pkt(int a1, int a2)
{
  int result; // eax

  result = dword_1E8700; /*0x1aad8f*/
  if ( dword_1E8700 ) /*0x1aad96*/
    return dword_1E870C(dword_1E8700, sel_sendPacket_length_, a1, a2); /*0x1aadad*/
  return result; /*0x1aadb1*/
}
