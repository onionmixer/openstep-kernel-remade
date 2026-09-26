/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x138774. */
int __cdecl xdr_reference(XDR *a1, char **a2, unsigned int a3, xdrproc_t a4)
{
  char *v4; // ebx
  int v6; // esi

  v4 = *a2; /*0x138783*/
  if ( !*a2 ) /*0x138783*/
  {
    if ( a1->x_op == XDR_DECODE ) /*0x13878e*/
    {
      v4 = (char *)kalloc(a3); /*0x1387a5*/
      *a2 = v4; /*0x1387aa*/
      bzero(v4, a3); /*0x1387b1*/
    }
    else if ( a1->x_op == XDR_FREE ) /*0x138793*/
    {
      return 1; /*0x13879a*/
    }
  }
  v6 = a4(a1, v4, -1u); /*0x1387bf*/
  if ( a1->x_op == XDR_FREE ) /*0x1387c7*/
  {
    kfree((int)v4, a3); /*0x1387ce*/
    *a2 = nullptr; /*0x1387d6*/
  }
  return v6; /*0x1387e1*/
}
