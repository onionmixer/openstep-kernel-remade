/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x137d78. */
int __cdecl xdr_bytes(XDR *a1, char **a2, unsigned int *a3, unsigned int a4)
{
  char *v4; // edi
  unsigned int v6; // ebx
  unsigned int v7; // esi
  xdr_op x_op; // eax

  v4 = *a2; /*0x137d84*/
  if ( !xdr_u_long(a1, a3) )
  {
    printf("xdr_bytes: size FAILED\n");
    return 0; /*0x137da3*/
  }
  v6 = *a3; /*0x137da8*/
  if ( a4 < *a3 && a1->x_op != XDR_FREE )
  {
    printf("xdr_bytes: bad size FAILED\n");
    return 0; /*0x137dc3*/
  }
  if ( a1->x_op == XDR_DECODE )
  {
    if ( !v6 ) /*0x137de6*/
      return 1; /*0x137de6*/
    if ( !v4 ) /*0x137df6*/
    {
      v4 = (char *)kalloc(v6); /*0x137dfe*/
      *a2 = v4; /*0x137e00*/
    }
  }
  else if ( a1->x_op )
  {
    if ( a1->x_op != XDR_FREE )
    {
      printf("xdr_bytes: bad op FAILED\n");
      return 0; /*0x137ddd*/
    }
    if ( v4 ) /*0x137eaa*/
    {
      kfree((int)v4, v6); /*0x137eb2*/
      *a2 = nullptr; /*0x137eb7*/
    }
    return 1; /*0x137ebd*/
  }
  if ( !v6 ) /*0x137e07*/
    return 1; /*0x137e07*/
  v7 = v6 & 3; /*0x137e0b*/
  if ( (v6 & 3) != 0 ) /*0x137e0e*/
    v7 = 4 - v7; /*0x137e17*/
  x_op = a1->x_op; /*0x137e1c*/
  if ( a1->x_op != XDR_DECODE )
  {
    if ( x_op )
    {
      if ( x_op != XDR_FREE )
      {
        printf("xdr_opaque: bad op FAILED\n");
        return 0; /*0x137e9e*/
      }
    }
    else
    {
      if ( !a1->x_ops->x_putbytes(a1, v4, v6) )
      {
        printf("xdr_opaque: encode FAILED\n");
        return 0; /*0x137e72*/
      }
      if ( v7 ) /*0x137e76*/
        return a1->x_ops->x_putbytes(a1, (const char *)&unk_1DD213, v7); /*0x137e8e*/
    }
    return 1; /*0x137ded*/
  }
  if ( a1->x_ops->x_getbytes(a1, v4, v6) ) /*0x137e2c*/
  {
    if ( v7 ) /*0x137e3e*/
      return a1->x_ops->x_getbytes(a1, (char *)&unk_1E5A20, v7); /*0x137e52*/
    return 1; /*0x137e3e*/
  }
  printf("xdr_opaque: decode FAILED\n");
  return 0; /*0x137ed3*/
}
