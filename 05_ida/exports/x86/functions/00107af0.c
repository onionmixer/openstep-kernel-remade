/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x107af0. */
pid_t getpgrp(void)
{
  int *v0; // edx
  int v1; // edx
  pid_t result; // eax

  v0 = *(int **)(dword_1E875C + 36); /*0x107af8*/
  if ( !*v0 ) /*0x107afb*/
    *v0 = *(__int16 *)(*(_DWORD *)active_u + 48); /*0x107b0b*/
  v1 = pfind(*v0); /*0x107b15*/
  result = dword_1E875C; /*0x107b1b*/
  if ( v1 ) /*0x107b19*/
    *(_DWORD *)(dword_1E875C + 96) = *(__int16 *)(v1 + 46); /*0x107b31*/
  else
    *(_BYTE *)(dword_1E875C + 104) = 3; /*0x107b20*/
  return result; /*0x107b26*/
}
