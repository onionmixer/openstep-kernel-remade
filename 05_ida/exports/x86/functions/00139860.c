/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x139860. */
int __cdecl sub_139860(int a1)
{
  int result; // eax

  *(_DWORD *)a1 = stable[(*(_BYTE *)(a1 + 66) + *(_BYTE *)(a1 + 67)) & 0xF]; /*0x13987a*/
  result = (*(_BYTE *)(a1 + 66) + *(_BYTE *)(a1 + 67)) & 0xF; /*0x139886*/
  stable[result] = a1; /*0x139889*/
  return result; /*0x139892*/
}
