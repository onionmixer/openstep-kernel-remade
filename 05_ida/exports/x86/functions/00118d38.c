/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x118d38. */
void __cdecl unp_discard(int a1)
{
  --*(_WORD *)(a1 + 16); /*0x118d3e*/
  --unp_rights; /*0x118d42*/
  closef(a1); /*0x118d49*/
}
