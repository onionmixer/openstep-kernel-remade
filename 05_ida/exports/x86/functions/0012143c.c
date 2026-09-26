/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12143c. */
void __cdecl raw_disconnect(int a1)
{
  int v1; // esi
  int v2; // eax
  int v3; // eax

  *(_BYTE *)(a1 + 76) &= ~2u; /*0x121444*/
  v1 = *(_DWORD *)(a1 + 8); /*0x121448*/
  if ( (*(_BYTE *)(v1 + 6) & 1) != 0 ) /*0x12144f*/
  {
    if ( *(_DWORD *)(a1 + 56) ) /*0x121451*/
      rtfree(*(_DWORD *)(a1 + 56)); /*0x121459*/
    *(_DWORD *)(v1 + 8) = 0; /*0x121461*/
    sofree(v1); /*0x121469*/
    *(_DWORD *)(*(_DWORD *)a1 + 4) = *(_DWORD *)(a1 + 4); /*0x121476*/
    **(_DWORD **)(a1 + 4) = *(_DWORD *)a1; /*0x12147e*/
    v2 = *(_DWORD *)(a1 + 52); /*0x121480*/
    if ( v2 ) /*0x121485*/
    {
      LOBYTE(v2) = v2 & 0x80; /*0x121487*/
      m_freem(v2); /*0x12148a*/
    }
    if ( ip_mrouter == v1 ) /*0x121498*/
      ip_mrouter_done(); /*0x12149a*/
    if ( *(_WORD *)(a1 + 44) == 2 ) /*0x1214a4*/
      ip_freemoptions(*(_DWORD *)(a1 + 80)); /*0x1214aa*/
    v3 = a1; /*0x1214b2*/
    LOBYTE(v3) = a1 & 0x80; /*0x1214b4*/
    m_freem(v3); /*0x1214b7*/
  }
}
