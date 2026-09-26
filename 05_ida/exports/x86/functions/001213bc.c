/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1213bc. */
void __cdecl raw_detach(int a1)
{
  int v1; // esi
  int v2; // eax
  int v3; // eax

  v1 = *(_DWORD *)(a1 + 8); /*0x1213c4*/
  if ( *(_DWORD *)(a1 + 56) ) /*0x1213c7*/
    rtfree(*(_DWORD *)(a1 + 56)); /*0x1213cf*/
  *(_DWORD *)(v1 + 8) = 0; /*0x1213d7*/
  sofree(v1); /*0x1213df*/
  *(_DWORD *)(*(_DWORD *)a1 + 4) = *(_DWORD *)(a1 + 4); /*0x1213ec*/
  **(_DWORD **)(a1 + 4) = *(_DWORD *)a1; /*0x1213f4*/
  v2 = *(_DWORD *)(a1 + 52); /*0x1213f6*/
  if ( v2 ) /*0x1213fb*/
  {
    LOBYTE(v2) = v2 & 0x80; /*0x1213fd*/
    m_freem(v2); /*0x121400*/
  }
  if ( ip_mrouter == v1 ) /*0x12140e*/
    ip_mrouter_done(); /*0x121410*/
  if ( *(_WORD *)(a1 + 44) == 2 ) /*0x12141a*/
    ip_freemoptions(*(_DWORD *)(a1 + 80)); /*0x121420*/
  v3 = a1; /*0x121428*/
  LOBYTE(v3) = a1 & 0x80; /*0x12142a*/
  m_freem(v3); /*0x12142d*/
}
