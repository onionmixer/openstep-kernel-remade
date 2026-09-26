/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1384bc. */
int __cdecl xdrmbuf_putbuf(_DWORD *a1, int a2, unsigned int a3, int a4, int a5)
{
  int v6; // eax
  bool v7; // sf
  int v8; // eax
  int *v9; // eax
  int v10; // eax
  int *v11; // eax

  if ( (a3 & 3) != 0 ) /*0x1384d3*/
    return 0; /*0x1384d7*/
  v6 = a1[5]; /*0x1384dc*/
  v7 = v6 - 4 < 0; /*0x1384df*/
  v8 = v6 - 4; /*0x1384df*/
  a1[5] = v8; /*0x1384e2*/
  if ( v7 )
  {
    if ( v8 != -4 )
      printf("xdr_mbuf: putlong, long crosses mbufs!\n");
    v9 = (int *)a1[4]; /*0x1384f9*/
    if ( !v9 ) /*0x1384fe*/
      return 0; /*0x1384fe*/
    v10 = *v9; /*0x138500*/
    a1[4] = v10; /*0x138502*/
    if ( !v10 ) /*0x138507*/
      return 0; /*0x138507*/
    a1[3] = v10 + *(_DWORD *)(v10 + 4); /*0x13850e*/
    a1[5] = *(__int16 *)(v10 + 8) - 4; /*0x138518*/
  }
  *(_DWORD *)a1[3] = _byteswap_ulong(a3); /*0x138525*/
  a1[3] += 4; /*0x138527*/
  *(_WORD *)(a1[4] + 8) -= *((_WORD *)a1 + 10); /*0x138532*/
  v11 = mclgetx(a4, a5, a2, a3, 1); /*0x138545*/
  if ( v11 )
  {
    *(_DWORD *)a1[4] = v11; /*0x138567*/
    a1[5] = 0; /*0x138569*/
    return 1; /*0x138570*/
  }
  else
  {
    printf("xdrmbuf_putbuf: mclgetx failed\n");
    return 0; /*0x13855d*/
  }
}
