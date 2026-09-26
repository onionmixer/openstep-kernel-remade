/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14b064. */
int __cdecl ipc_notify_init_no_senders(int a1)
{
  __int16 v2; // dx

  *(_DWORD *)a1 = 18; /*0x14b06a*/
  *(_DWORD *)(a1 + 4) = 32; /*0x14b070*/
  *(_DWORD *)(a1 + 16) = 1; /*0x14b077*/
  *(_DWORD *)(a1 + 12) = 0; /*0x14b07e*/
  *(_DWORD *)(a1 + 8) = 0; /*0x14b085*/
  *(_DWORD *)(a1 + 20) = 70; /*0x14b08c*/
  *(_BYTE *)(a1 + 24) = 2; /*0x14b093*/
  *(_BYTE *)(a1 + 25) = 32; /*0x14b097*/
  v2 = *(_WORD *)(a1 + 26) & 0xF000; /*0x14b09f*/
  LOBYTE(v2) = 1; /*0x14b0a4*/
  *(_WORD *)(a1 + 26) = v2; /*0x14b0a7*/
  *(_BYTE *)(a1 + 27) = *(_BYTE *)(a1 + 27) & 0xF | 0x10; /*0x14b0b4*/
  *(_DWORD *)(a1 + 28) = 0; /*0x14b0b7*/
  return a1; /*0x14b0c0*/
}
