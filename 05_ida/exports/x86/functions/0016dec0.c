/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16dec0. */
int __cdecl kern_serv_log_data(int a1, int a2, int a3)
{
  _DWORD v4[10]; // [esp+8h] [ebp-28h] BYREF

  v4[6] = 1610612736; /*0x16deda*/
  v4[7] = a62i; /*0x16dee3*/
  v4[9] = a2; /*0x16deef*/
  v4[8] = 8 * a3; /*0x16def5*/
  HIBYTE(v4[0]) = 0; /*0x16def8*/
  v4[1] = 40; /*0x16defc*/
  v4[2] = 0; /*0x16df03*/
  v4[4] = a1; /*0x16df0a*/
  v4[3] = 0; /*0x16df0d*/
  v4[5] = 202; /*0x16df14*/
  return msg_send(v4, 0, 0); /*0x16df28*/
}
