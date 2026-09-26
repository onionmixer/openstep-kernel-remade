/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c07d8. */
int __cdecl _NXAudioReplyStreamStatus(int a1, int a2, int a3, int a4, int a5, int a6)
{
  _DWORD v7[16]; // [esp+Ch] [ebp-40h] BYREF

  v7[6] = 268509190; /*0x1c07f6*/
  v7[7] = a2; /*0x1c07f9*/
  v7[8] = 268509190; /*0x1c0802*/
  v7[9] = a3; /*0x1c0808*/
  v7[10] = 268509186; /*0x1c0811*/
  v7[11] = a4; /*0x1c0814*/
  v7[12] = 268509186; /*0x1c081d*/
  v7[13] = a5; /*0x1c0820*/
  v7[14] = 268509186; /*0x1c0829*/
  v7[15] = a6; /*0x1c082c*/
  HIBYTE(v7[0]) = 0; /*0x1c082f*/
  v7[1] = 64; /*0x1c0833*/
  v7[2] = 0; /*0x1c083a*/
  v7[4] = a1; /*0x1c0844*/
  v7[3] = 0; /*0x1c0847*/
  v7[5] = 1700; /*0x1c084e*/
  return msg_send(v7, 33, 1000); /*0x1c0865*/
}
