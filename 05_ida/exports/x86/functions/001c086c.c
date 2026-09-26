/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c086c. */
int __cdecl _NXAudioReplyRecordedData(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  _DWORD v8[18]; // [esp+Ch] [ebp-48h] BYREF

  v8[6] = 268509190; /*0x1c088a*/
  v8[7] = a2; /*0x1c088d*/
  v8[8] = 268509190; /*0x1c0896*/
  v8[9] = a3; /*0x1c089c*/
  v8[10] = 268509186; /*0x1c08a5*/
  v8[11] = a4; /*0x1c08a8*/
  v8[12] = 268509186; /*0x1c08b1*/
  v8[13] = a5; /*0x1c08b4*/
  v8[14] = 1610612736; /*0x1c08bd*/
  v8[15] = 524297; /*0x1c08c6*/
  v8[17] = a6; /*0x1c08d2*/
  v8[16] = a7; /*0x1c08d8*/
  HIBYTE(v8[0]) = 0; /*0x1c08db*/
  v8[1] = 72; /*0x1c08df*/
  v8[2] = 0; /*0x1c08e6*/
  v8[4] = a1; /*0x1c08f0*/
  v8[3] = 0; /*0x1c08f3*/
  v8[5] = 1701; /*0x1c08fa*/
  return msg_send(v8, 33, 1000); /*0x1c0911*/
}
