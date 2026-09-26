/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x120b2c. */
int __cdecl nb_shrink_top(int a1, int a2)
{
  *(_WORD *)(a1 + 8) -= a2; /*0x120b35*/
  *(_DWORD *)(a1 + 4) += a2; /*0x120b39*/
  return 0; /*0x120b40*/
}
