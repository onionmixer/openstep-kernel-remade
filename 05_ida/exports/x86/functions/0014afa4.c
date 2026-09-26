/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14afa4. */
int __cdecl ipc_notify_init_msg_accepted(int a1)
{
  __int16 v2; // dx

  *(_DWORD *)a1 = 18; /*0x14afaa*/
  *(_DWORD *)(a1 + 4) = 32; /*0x14afb0*/
  *(_DWORD *)(a1 + 16) = 1; /*0x14afb7*/
  *(_DWORD *)(a1 + 12) = 0; /*0x14afbe*/
  *(_DWORD *)(a1 + 8) = 0; /*0x14afc5*/
  *(_DWORD *)(a1 + 20) = 66; /*0x14afcc*/
  *(_BYTE *)(a1 + 24) = 15; /*0x14afd3*/
  *(_BYTE *)(a1 + 25) = 32; /*0x14afd7*/
  v2 = *(_WORD *)(a1 + 26) & 0xF000; /*0x14afdf*/
  LOBYTE(v2) = 1; /*0x14afe4*/
  *(_WORD *)(a1 + 26) = v2; /*0x14afe7*/
  *(_BYTE *)(a1 + 27) = *(_BYTE *)(a1 + 27) & 0xF | 0x10; /*0x14aff4*/
  *(_DWORD *)(a1 + 28) = 0; /*0x14aff7*/
  return a1; /*0x14b000*/
}
