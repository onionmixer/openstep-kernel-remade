/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x107cfc. */
pid_t setpgrp(void)
{
  int *v0; // esi
  int v1; // ebx
  pid_t result; // eax
  __int16 v3; // ax

  v0 = *(int **)(dword_1E875C + 36); /*0x107d06*/
  if ( !*v0 ) /*0x107d09*/
    *v0 = *(__int16 *)(*(_DWORD *)active_u + 48); /*0x107d19*/
  v1 = pfind(*v0); /*0x107d23*/
  if ( v1 ) /*0x107d2a*/
  {
    v3 = *(_WORD *)(*(_DWORD *)(active_u + 28) + 2); /*0x107d40*/
    if ( *(_WORD *)(v1 + 44) == v3 || !v3 || inferior(v1) ) /*0x107d50*/
    {
      LOWORD(result) = enterpgrp(v1, v0[1], 0); /*0x107d6f*/
    }
    else
    {
      result = dword_1E875C; /*0x107d5c*/
      *(_BYTE *)(dword_1E875C + 104) = 1; /*0x107d61*/
    }
  }
  else
  {
    result = dword_1E875C; /*0x107d2c*/
    *(_BYTE *)(dword_1E875C + 104) = 3; /*0x107d31*/
  }
  return result; /*0x107d77*/
}
