/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x137efc. */
int __cdecl xdr_union(XDR *a1, int *a2, char *a3, const xdr_discrim *a4, xdrproc_t a5)
{
  const xdr_discrim *v5; // ebx
  xdr_op x_op; // eax
  int v7; // eax

  v5 = a4; /*0x137f0b*/
  x_op = a1->x_op; /*0x137f0e*/
  if ( a1->x_op )
  {
    if ( x_op == XDR_DECODE )
    {
      v7 = a1->x_ops->x_getlong(a1, a2); /*0x137f2c*/
    }
    else
    {
      if ( x_op == XDR_FREE ) /*0x137f37*/
        goto LABEL_10; /*0x137f37*/
      printf("xdr_long: FAILED\n");
      v7 = 0; /*0x137f43*/
    }
  }
  else
  {
    v7 = a1->x_ops->x_putlong(a1, a2); /*0x137f1c*/
  }
  if ( !v7 )
  {
    printf("xdr_enum: dscmp FAILED\n");
    return 0; /*0x137f94*/
  }
LABEL_10:
  if ( !a4->proc ) /*0x137f5e*/
  {
LABEL_13:
    if ( a5 ) /*0x137f71*/
      return a5(a1, a3, -1u); /*0x137f7f*/
    return 0; /*0x137f71*/
  }
  while ( v5->value != *a2 ) /*0x137f62*/
  {
    ++v5; /*0x137f64*/
    if ( !v5->proc ) /*0x137f67*/
      goto LABEL_13; /*0x137f6b*/
  }
  return v5->proc(a1, a3, -1u); /*0x137f99*/
}
