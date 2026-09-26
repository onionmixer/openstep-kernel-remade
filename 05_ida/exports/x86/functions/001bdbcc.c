/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bdbcc. */
char __cdecl audio_snd_reply_illegal_msg(int a1, int a2, int a3, int a4, int a5)
{
  __int16 v5; // ax

  *(_DWORD *)(a1 + 20) = 314; /*0x1bdbe1*/
  *(_DWORD *)(a1 + 4) = 36; /*0x1bdbe8*/
  *(_DWORD *)(a1 + 12) = a2; /*0x1bdbef*/
  *(_DWORD *)(a1 + 16) = a3; /*0x1bdbf2*/
  *(_DWORD *)(a1 + 24) = dword_1E53C8; /*0x1bdbfb*/
  v5 = *(_WORD *)(a1 + 26) & 0xF000; /*0x1bdc02*/
  LOBYTE(v5) = 2; /*0x1bdc06*/
  *(_WORD *)(a1 + 26) = v5; /*0x1bdc08*/
  *(_DWORD *)(a1 + 28) = a4; /*0x1bdc0c*/
  *(_DWORD *)(a1 + 32) = a5; /*0x1bdc0f*/
  return v5; /*0x1bdc15*/
}
