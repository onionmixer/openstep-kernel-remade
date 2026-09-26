/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12b63c. */
void __cdecl udp_notify(int a1)
{
  sowakeup(*(_DWORD *)(a1 + 28), *(_DWORD *)(a1 + 28) + 36); /*0x12b64b*/
  sowakeup(*(_DWORD *)(a1 + 28), *(_DWORD *)(a1 + 28) + 60); /*0x12b658*/
}
