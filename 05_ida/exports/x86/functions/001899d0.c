/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1899d0. */
void __cdecl __noreturn dbf_handler(int a1)
{
  int v1; // ebx

  v1 = **(_DWORD **)(active_threads + 40); /*0x1899e6*/
  while ( 1 ) /*0x1899e8*/
  {
    *(_DWORD *)&dbf_state[24] = 8; /*0x1899e8*/
    *(_DWORD *)&dbf_state[26] = a1; /*0x1899ef*/
    *(_DWORD *)&dbf_state[28] = *(_DWORD *)(v1 + 32); /*0x1899f5*/
    dbf_state[30] = *(_WORD *)(v1 + 76); /*0x1899fc*/
    *(_DWORD *)&dbf_state[32] = *(_DWORD *)(v1 + 36); /*0x189a03*/
    *(_DWORD *)&dbf_state[22] = *(_DWORD *)(v1 + 40); /*0x189a09*/
    *(_DWORD *)&dbf_state[20] = *(_DWORD *)(v1 + 44); /*0x189a0f*/
    *(_DWORD *)&dbf_state[18] = *(_DWORD *)(v1 + 48); /*0x189a15*/
    *(_DWORD *)&dbf_state[16] = *(_DWORD *)(v1 + 52); /*0x189a1b*/
    *(_DWORD *)&dbf_state[12] = *(_DWORD *)(v1 + 60); /*0x189a21*/
    *(_DWORD *)&dbf_state[10] = *(_DWORD *)(v1 + 64); /*0x189a27*/
    *(_DWORD *)&dbf_state[8] = *(_DWORD *)(v1 + 68); /*0x189a2d*/
    dbf_state[6] = *(_WORD *)(v1 + 84); /*0x189a34*/
    dbf_state[4] = *(_WORD *)(v1 + 72); /*0x189a3c*/
    dbf_state[2] = *(_WORD *)(v1 + 88); /*0x189a44*/
    dbf_state[0] = *(_WORD *)(v1 + 92); /*0x189a4c*/
    kernel_trap(dbf_state); /*0x189a50*/
  }
}
