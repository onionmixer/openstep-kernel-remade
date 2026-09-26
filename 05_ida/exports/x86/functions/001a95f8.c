/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a95f8. */
int __cdecl sub_1A95F8(int a1, int a2, int a3)
{
  void *v3; // eax

  v3 = (void *)if_private(a1); /*0x1a95ff*/
  if ( v3 ) /*0x1a9609*/
    return (int)objc_msgSend(v3, sel_outputPacket_address_, a2, a3); /*0x1a961b*/
  else
    return -1; /*0x1a9624*/
}
