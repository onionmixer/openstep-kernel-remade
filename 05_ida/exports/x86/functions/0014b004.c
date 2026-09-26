/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14b004. */
int __cdecl ipc_notify_init_port_destroyed(int a1)
{
  __int16 v2; // dx

  *(_DWORD *)a1 = -2147483630; /*0x14b00a*/
  *(_DWORD *)(a1 + 4) = 32; /*0x14b010*/
  *(_DWORD *)(a1 + 16) = 1; /*0x14b017*/
  *(_DWORD *)(a1 + 12) = 0; /*0x14b01e*/
  *(_DWORD *)(a1 + 8) = 0; /*0x14b025*/
  *(_DWORD *)(a1 + 20) = 69; /*0x14b02c*/
  *(_BYTE *)(a1 + 24) = 16; /*0x14b033*/
  *(_BYTE *)(a1 + 25) = 32; /*0x14b037*/
  v2 = *(_WORD *)(a1 + 26) & 0xF000; /*0x14b03f*/
  LOBYTE(v2) = 1; /*0x14b044*/
  *(_WORD *)(a1 + 26) = v2; /*0x14b047*/
  *(_BYTE *)(a1 + 27) = *(_BYTE *)(a1 + 27) & 0xF | 0x10; /*0x14b054*/
  *(_DWORD *)(a1 + 28) = 0; /*0x14b057*/
  return a1; /*0x14b060*/
}
