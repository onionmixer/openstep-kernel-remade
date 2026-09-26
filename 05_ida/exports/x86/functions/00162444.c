/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x162444. */
int __cdecl sub_162444(int a1, _DWORD *a2, _WORD *a3)
{
  __int16 v4; // [esp+Ch] [ebp-4h] BYREF

  if ( *a2 <= 0xFu ) /*0x162459*/
    return 0; /*0x16249c*/
  *(_BYTE *)a1 |= 0x80u; /*0x16245b*/
  *(_WORD *)(a1 + 2) = 12; /*0x16245e*/
  *(_DWORD *)(a1 + 8) = kdp_machine_read_regs(*(_DWORD *)(a1 + 8), *(_DWORD *)(a1 + 12), a1 + 12, &v4); /*0x162479*/
  *(_WORD *)(a1 + 2) += v4; /*0x162480*/
  *a3 = kdp; /*0x16248b*/
  *a2 = *(unsigned __int16 *)(a1 + 2); /*0x162492*/
  return 1; /*0x1624a1*/
}
