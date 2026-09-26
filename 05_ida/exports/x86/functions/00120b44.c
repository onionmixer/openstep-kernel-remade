/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x120b44. */
int __cdecl nb_grow_top(int a1, int a2)
{
  *(_WORD *)(a1 + 8) += a2; /*0x120b4d*/
  *(_DWORD *)(a1 + 4) -= a2; /*0x120b51*/
  return 0; /*0x120b58*/
}
