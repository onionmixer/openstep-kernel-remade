/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bde94. */
char __cdecl audio_snd_reply_ret_formats(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  __int16 v7; // ax

  *(_DWORD *)(a1 + 20) = 320; /*0x1bdea9*/
  *(_DWORD *)(a1 + 4) = 48; /*0x1bdeb0*/
  *(_DWORD *)(a1 + 16) = a2; /*0x1bdeb7*/
  *(_DWORD *)(a1 + 24) = dword_1E53C8; /*0x1bdec0*/
  v7 = *(_WORD *)(a1 + 26) & 0xF000; /*0x1bdec7*/
  LOBYTE(v7) = 5; /*0x1bdecb*/
  *(_WORD *)(a1 + 26) = v7; /*0x1bdecd*/
  *(_DWORD *)(a1 + 28) = a3; /*0x1bded4*/
  *(_DWORD *)(a1 + 32) = a4; /*0x1bded7*/
  *(_DWORD *)(a1 + 36) = a5; /*0x1bdeda*/
  *(_DWORD *)(a1 + 40) = a6; /*0x1bdedd*/
  *(_DWORD *)(a1 + 44) = a7; /*0x1bdee3*/
  return v7; /*0x1bdee9*/
}
