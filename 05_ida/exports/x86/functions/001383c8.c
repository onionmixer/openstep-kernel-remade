/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1383c8. */
int __cdecl xdrmbuf_getmbuf(XDR *a1, char **a2, unsigned int *a3)
{
  char *x_base; // edx
  unsigned int v5; // eax
  unsigned int i; // ecx

  if ( !xdr_u_int(a1, a3) ) /*0x1383d9*/
    return 0; /*0x1383e5*/
  x_base = a1->x_base; /*0x1383ec*/
  v5 = *((__int16 *)x_base + 4) - a1->x_handy; /*0x1383f3*/
  *((_DWORD *)x_base + 1) += v5; /*0x1383f6*/
  *((_WORD *)x_base + 4) -= v5; /*0x1383f9*/
  *a2 = x_base; /*0x1383fd*/
  for ( i = 0; x_base; x_base = *(char **)x_base ) /*0x138403*/
    i += *((__int16 *)x_base + 4); /*0x13840c*/
  if ( *a3 <= i ) /*0x138416*/
    return 1; /*0x138428*/
  printf("xdrmbuf_getmbuf failed\n"); /*0x13841d*/
  return 0; /*0x138430*/
}
