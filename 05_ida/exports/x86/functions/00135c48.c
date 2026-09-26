/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x135c48. */
int __cdecl clntkudp_freeres(int a1, int (__stdcall *a2)(int, int), int a3)
{
  int v3; // eax

  v3 = *(_DWORD *)(a1 + 8); /*0x135c55*/
  *(_DWORD *)(v3 + 52) = 2; /*0x135c5b*/
  return a2(v3 + 52, a3); /*0x135c66*/
}
