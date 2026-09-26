/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x135c84. */
int __cdecl clntkudp_destroy(int a1)
{
  int v1; // ebx

  v1 = *(_DWORD *)(a1 + 8); /*0x135c8b*/
  soclose(*(_DWORD *)(v1 + 20)); /*0x135c92*/
  kfree(*(_DWORD *)(v1 + 104), 0x2260u); /*0x135ca0*/
  return kfree(v1, 0x78u); /*0x135cad*/
}
