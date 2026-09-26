/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bdc1c. */
int __cdecl audio_snd_reply_recorded_data(int a1, int a2, int a3, int a4, int a5)
{
  *(_BYTE *)(a1 + 3) = 0; /*0x1bdc31*/
  *(_DWORD *)(a1 + 4) = 48; /*0x1bdc35*/
  *(_DWORD *)(a1 + 8) = 0; /*0x1bdc3c*/
  *(_DWORD *)(a1 + 16) = a2; /*0x1bdc43*/
  *(_DWORD *)(a1 + 12) = 0; /*0x1bdc46*/
  *(_DWORD *)(a1 + 20) = 300; /*0x1bdc4d*/
  *(_DWORD *)(a1 + 24) = dword_1E53C8; /*0x1bdc5a*/
  *(_DWORD *)(a1 + 28) = a3; /*0x1bdc5d*/
  *(_DWORD *)(a1 + 32) = dword_1E53BC; /*0x1bdc66*/
  *(_DWORD *)(a1 + 36) = dword_1E53C0; /*0x1bdc6f*/
  *(_DWORD *)(a1 + 40) = a5; /*0x1bdc72*/
  *(_DWORD *)(a1 + 44) = a4; /*0x1bdc75*/
  return a1; /*0x1bdc7b*/
}
