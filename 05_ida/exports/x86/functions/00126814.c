/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x126814. */
int __cdecl ip_enq(int a1, int a2)
{
  *(_DWORD *)(a1 + 16) = a2; /*0x12681e*/
  *(_DWORD *)(a1 + 12) = *(_DWORD *)(a2 + 12); /*0x126824*/
  *(_DWORD *)(*(_DWORD *)(a2 + 12) + 16) = a1; /*0x12682a*/
  *(_DWORD *)(a2 + 12) = a1; /*0x12682d*/
  return a1; /*0x126830*/
}
