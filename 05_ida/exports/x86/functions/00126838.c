/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x126838. */
int __cdecl ip_deq(int a1)
{
  int result; // eax

  *(_DWORD *)(*(_DWORD *)(a1 + 16) + 12) = *(_DWORD *)(a1 + 12); /*0x126844*/
  result = *(_DWORD *)(a1 + 16); /*0x12684a*/
  *(_DWORD *)(*(_DWORD *)(a1 + 12) + 16) = result; /*0x12684d*/
  return result; /*0x126852*/
}
