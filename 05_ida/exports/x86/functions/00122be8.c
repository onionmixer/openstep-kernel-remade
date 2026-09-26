/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x122be8. */
int __cdecl arptfree(int a1)
{
  int v1; // esi

  v1 = splimp(); /*0x122bf5*/
  if ( *(_DWORD *)(a1 + 12) ) /*0x122bf7*/
    m_freem(*(_DWORD *)(a1 + 12)); /*0x122bff*/
  *(_DWORD *)(a1 + 12) = 0; /*0x122c07*/
  *(_BYTE *)(a1 + 11) = 0; /*0x122c0e*/
  *(_BYTE *)(a1 + 10) = 0; /*0x122c12*/
  *(_DWORD *)a1 = 0; /*0x122c16*/
  return splx(v1); /*0x122c25*/
}
