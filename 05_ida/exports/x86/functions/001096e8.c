/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1096e8. */
int __cdecl killpg(pid_t a1, int a2)
{
  int result; // eax
  char *v3; // ecx
  char v4; // dl

  result = *(_DWORD *)(dword_1E875C + 36); /*0x1096f1*/
  v3 = *(char **)(result + 4); /*0x1096f4*/
  if ( (unsigned int)v3 <= 0x20 ) /*0x1096fa*/
  {
    v4 = killpg1(v3, *(_DWORD *)result, 0); /*0x10970f*/
    result = dword_1E875C; /*0x109711*/
    *(_BYTE *)(dword_1E875C + 104) = v4; /*0x109716*/
  }
  else
  {
    *(_BYTE *)(dword_1E875C + 104) = 22; /*0x1096fc*/
  }
  return result; /*0x109702*/
}
