/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x108474. */
pid_t setsid(void)
{
  int v0; // ebx
  pid_t result; // eax

  v0 = *(_DWORD *)active_u; /*0x10847d*/
  if ( *(_DWORD *)(get_posix_proc(*(__int16 *)(*(_DWORD *)active_u + 48))[4] + 12) == *(__int16 *)(v0 + 48) /*0x108499*/
    || pgfind(*(__int16 *)(v0 + 48)) )
  {
    result = dword_1E875C; /*0x1084a5*/
    *(_BYTE *)(dword_1E875C + 104) = 1; /*0x1084aa*/
  }
  else
  {
    enterpgrp(v0, *(__int16 *)(v0 + 48), 1); /*0x1084b8*/
    result = dword_1E875C; /*0x1084bd*/
    *(_DWORD *)(dword_1E875C + 96) = *(__int16 *)(v0 + 48); /*0x1084c6*/
  }
  return result; /*0x1084c9*/
}
