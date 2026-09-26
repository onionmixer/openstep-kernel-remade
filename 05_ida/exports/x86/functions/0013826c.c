/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13826c. */
int __cdecl xdrmbuf_getlong(int a1, _DWORD *a2)
{
  int v2; // eax
  bool v3; // sf
  int v4; // eax
  int *v5; // eax
  int v6; // eax

  v2 = *(_DWORD *)(a1 + 20); /*0x138277*/
  v3 = v2 - 4 < 0; /*0x13827a*/
  v4 = v2 - 4; /*0x13827a*/
  *(_DWORD *)(a1 + 20) = v4; /*0x13827d*/
  if ( v3 )
  {
    if ( v4 != -4 )
      printf("xdr_mbuf: long crosses mbufs!\n");
    v5 = *(int **)(a1 + 16); /*0x138291*/
    if ( !v5 ) /*0x138296*/
      return 0; /*0x138296*/
    v6 = *v5; /*0x138298*/
    *(_DWORD *)(a1 + 16) = v6; /*0x13829a*/
    if ( !v6 ) /*0x13829f*/
      return 0; /*0x1382a3*/
    *(_DWORD *)(a1 + 12) = v6 + *(_DWORD *)(v6 + 4); /*0x1382ad*/
    *(_DWORD *)(a1 + 20) = *(__int16 *)(v6 + 8) - 4; /*0x1382b7*/
  }
  *a2 = _byteswap_ulong(**(_DWORD **)(a1 + 12)); /*0x1382c1*/
  *(_DWORD *)(a1 + 12) += 4; /*0x1382c3*/
  return 1; /*0x1382cf*/
}
