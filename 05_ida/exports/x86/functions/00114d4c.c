/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x114d4c. */
void __cdecl sofree(int a1)
{
  int v1; // eax

  if ( !*(_DWORD *)(a1 + 8) && (*(_BYTE *)(a1 + 6) & 1) != 0 ) /*0x114d5d*/
  {
    if ( *(_DWORD *)(a1 + 16) ) /*0x114d5f*/
    {
      if ( !soqremque(a1, 0) && !soqremque(a1, 1) ) /*0x114d77*/
        panic(aSofreeDq); /*0x114d88*/
      *(_DWORD *)(a1 + 16) = 0; /*0x114d90*/
    }
    sbrelease(a1 + 60); /*0x114d9b*/
    sorflush(a1); /*0x114da1*/
    v1 = a1; /*0x114da6*/
    LOBYTE(v1) = a1 & 0x80; /*0x114da8*/
    m_free(v1); /*0x114dab*/
  }
}
