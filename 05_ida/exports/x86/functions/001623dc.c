/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1623dc. */
int __cdecl sub_1623DC(int a1, _DWORD *a2, _WORD *a3)
{
  if ( *a2 <= 0xFu ) /*0x1623f1*/
    return 0; /*0x162438*/
  *(_DWORD *)(a1 + 8) = kdp_machine_write_regs(*(_DWORD *)(a1 + 8), *(_DWORD *)(a1 + 12), a1 + 16); /*0x162412*/
  *(_BYTE *)a1 |= 0x80u; /*0x162415*/
  *(_WORD *)(a1 + 2) = 12; /*0x162418*/
  *a3 = kdp; /*0x162425*/
  *a2 = *(unsigned __int16 *)(a1 + 2); /*0x16242c*/
  return 1; /*0x16243d*/
}
