/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1210b8. */
int __cdecl mbuf_read(int a1, char *a2, unsigned int a3, unsigned int a4)
{
  unsigned int v4; // edi
  int v5; // esi
  int v6; // ecx
  size_t v7; // ebx

  v4 = 0; /*0x1210c1*/
  v5 = a1; /*0x1210c3*/
  if ( !a1 ) /*0x1210c8*/
    return -1; /*0x121128*/
  while ( 1 ) /*0x1210cf*/
  {
    if ( a3 >= v4 ) /*0x1210cf*/
    {
      v6 = *(__int16 *)(v5 + 8); /*0x1210d1*/
      if ( a3 < v6 + v4 ) /*0x1210db*/
      {
        v7 = v6 - (a3 - v4); /*0x1210ec*/
        if ( a4 < v7 ) /*0x1210f1*/
          v7 = a4; /*0x1210f3*/
        bcopy((const void *)(a3 - v4 + *(_DWORD *)(v5 + 4) + v5), a2, v7); /*0x1210ff*/
        a2 += v7; /*0x121104*/
        a3 += v7; /*0x121107*/
        a4 -= v7; /*0x12110a*/
        if ( !a4 ) /*0x121114*/
          break; /*0x121114*/
      }
    }
    v4 += *(__int16 *)(v5 + 8); /*0x121120*/
    v5 = *(_DWORD *)v5; /*0x121122*/
    if ( !v5 ) /*0x121126*/
      return -1; /*0x121126*/
  }
  return 0; /*0x121130*/
}
