/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14af44. */
int __cdecl ipc_notify_init_port_deleted(int a1)
{
  __int16 v2; // dx

  *(_DWORD *)a1 = 18; /*0x14af4a*/
  *(_DWORD *)(a1 + 4) = 32; /*0x14af50*/
  *(_DWORD *)(a1 + 16) = 1; /*0x14af57*/
  *(_DWORD *)(a1 + 12) = 0; /*0x14af5e*/
  *(_DWORD *)(a1 + 8) = 0; /*0x14af65*/
  *(_DWORD *)(a1 + 20) = 65; /*0x14af6c*/
  *(_BYTE *)(a1 + 24) = 15; /*0x14af73*/
  *(_BYTE *)(a1 + 25) = 32; /*0x14af77*/
  v2 = *(_WORD *)(a1 + 26) & 0xF000; /*0x14af7f*/
  LOBYTE(v2) = 1; /*0x14af84*/
  *(_WORD *)(a1 + 26) = v2; /*0x14af87*/
  *(_BYTE *)(a1 + 27) = *(_BYTE *)(a1 + 27) & 0xF | 0x10; /*0x14af94*/
  *(_DWORD *)(a1 + 28) = 0; /*0x14af97*/
  return a1; /*0x14afa0*/
}
