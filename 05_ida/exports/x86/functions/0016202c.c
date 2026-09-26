/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16202c. */
int __cdecl sub_16202C(int a1)
{
  safe_prf( /*0x16204b*/
    "kdp_unknown request %x len %d seq %x key %x\n",
    *(_BYTE *)a1 & 0x7F,
    *(unsigned __int16 *)(a1 + 2),
    *(unsigned __int8 *)(a1 + 1),
    *(_DWORD *)(a1 + 4));
  return 0; /*0x162054*/
}
