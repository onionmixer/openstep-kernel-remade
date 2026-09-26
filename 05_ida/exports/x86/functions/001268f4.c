/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1268f4. */
int ip_drain()
{
  int v0; // edi
  int v1; // esi
  int v2; // ebx
  int v3; // eax
  int v4; // eax
  int result; // eax

  for ( ; (int *)ipq != &ipq; result = m_free(v4) ) /*0x126904*/
  {
    ++dword_1EAACC; /*0x126908*/
    v0 = ipq; /*0x12690e*/
    v1 = *(_DWORD *)(ipq + 12); /*0x126914*/
    if ( v1 != ipq ) /*0x126919*/
    {
      do /*0x126936*/
      {
        v2 = *(_DWORD *)(v1 + 12); /*0x12691c*/
        ip_deq(v1); /*0x126920*/
        v3 = v1; /*0x126925*/
        LOBYTE(v3) = v1 & 0x80; /*0x126927*/
        m_freem(v3); /*0x12692a*/
        v1 = v2; /*0x126932*/
      }
      while ( v2 != v0 ); /*0x126936*/
    }
    *(_DWORD *)(*(_DWORD *)v0 + 4) = *(_DWORD *)(v0 + 4); /*0x12693d*/
    **(_DWORD **)(v0 + 4) = *(_DWORD *)v0; /*0x126945*/
    v4 = v0; /*0x126947*/
    LOBYTE(v4) = v0 & 0x80; /*0x126949*/
  }
  return result; /*0x126963*/
}
