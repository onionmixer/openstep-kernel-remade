/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bdcf4. */
_DWORD *__cdecl audio_snd_reply_overflow(_DWORD *a1, int a2, int a3)
{
  a1[5] = 307; /*0x1bdd01*/
  a1[1] = 32; /*0x1bdd08*/
  a1[4] = a2; /*0x1bdd0f*/
  a1[6] = dword_1E53C8; /*0x1bdd18*/
  a1[7] = a3; /*0x1bdd1b*/
  return a1; /*0x1bdd1e*/
}
