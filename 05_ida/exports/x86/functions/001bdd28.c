/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bdd28. */
_DWORD *__cdecl audio_snd_reply_started(_DWORD *a1, int a2, int a3)
{
  a1[5] = 309; /*0x1bdd35*/
  a1[1] = 32; /*0x1bdd3c*/
  a1[4] = a2; /*0x1bdd43*/
  a1[6] = dword_1E53C8; /*0x1bdd4c*/
  a1[7] = a3; /*0x1bdd4f*/
  return a1; /*0x1bdd52*/
}
