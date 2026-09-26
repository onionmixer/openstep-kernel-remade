/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1382d8. */
int __cdecl xdrmbuf_putlong(_DWORD *a1, unsigned int *a2)
{
  int v2; // eax
  bool v3; // sf
  int v4; // eax
  int *v5; // eax
  int v6; // eax

  v2 = a1[5]; /*0x1382e3*/
  v3 = v2 - 4 < 0; /*0x1382e6*/
  v4 = v2 - 4; /*0x1382e6*/
  a1[5] = v4; /*0x1382e9*/
  if ( v3 )
  {
    if ( v4 != -4 )
      printf("xdr_mbuf: putlong, long crosses mbufs!\n");
    v5 = (int *)a1[4]; /*0x1382fd*/
    if ( !v5 ) /*0x138302*/
      return 0; /*0x138302*/
    v6 = *v5; /*0x138304*/
    a1[4] = v6; /*0x138306*/
    if ( !v6 ) /*0x13830b*/
      return 0; /*0x13830f*/
    a1[3] = v6 + *(_DWORD *)(v6 + 4); /*0x138319*/
    a1[5] = *(__int16 *)(v6 + 8) - 4; /*0x138323*/
  }
  *(_DWORD *)a1[3] = _byteswap_ulong(*a2); /*0x13832f*/
  a1[3] += 4; /*0x138331*/
  return 1; /*0x13833d*/
}
