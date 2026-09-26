/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x137594. */
int __cdecl svckudp_destroy(int a1)
{
  int v1; // ebx

  v1 = *(_DWORD *)(a1 + 48); /*0x13759c*/
  if ( *(_DWORD *)(v1 + 8) ) /*0x13759f*/
    m_freem(*(_DWORD *)(v1 + 8)); /*0x1375a7*/
  kfree(v1, 0x1CCu); /*0x1375b5*/
  kfree(*(_DWORD *)(a1 + 44), 0x2260u); /*0x1375c3*/
  return kfree(a1, 0x34u); /*0x1375d3*/
}
