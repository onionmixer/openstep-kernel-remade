/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x114b8c. */
int __cdecl piconnect(int a1, int a2)
{
  *(_DWORD *)(*(_DWORD *)(a1 + 8) + 12) = *(_DWORD *)(a2 + 8); /*0x114b9c*/
  *(_DWORD *)(*(_DWORD *)(a2 + 8) + 12) = *(_DWORD *)(a1 + 8); /*0x114ba5*/
  *(_WORD *)(a1 + 62) = 4096; /*0x114ba8*/
  *(_WORD *)(a1 + 66) = 0x2000; /*0x114bae*/
  *(_BYTE *)(a1 + 6) |= 0x22u; /*0x114bb4*/
  *(_WORD *)(a2 + 38) = 0; /*0x114bb8*/
  *(_WORD *)(a2 + 42) = 0; /*0x114bbe*/
  *(_BYTE *)(a2 + 6) |= 0x12u; /*0x114bc4*/
  return 1; /*0x114bcd*/
}
