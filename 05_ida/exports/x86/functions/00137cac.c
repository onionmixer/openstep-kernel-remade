/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x137cac. */
int __cdecl xdr_opaque(XDR *a1, char *a2, unsigned int a3)
{
  unsigned int v3; // ebx
  xdr_op x_op; // eax
  int v6; // [esp+0h] [ebp-Ch]
  int v7; // [esp+4h] [ebp-8h]
  int v8; // [esp+8h] [ebp-4h]
  int savedregs; // [esp+Ch] [ebp+0h]

  if ( !a3 ) /*0x137cbd*/
    return 1; /*0x137d3d*/
  v3 = a3 & 3; /*0x137cc1*/
  if ( (a3 & 3) != 0 ) /*0x137cc4*/
    v3 = 4 - v3; /*0x137ccd*/
  x_op = a1->x_op; /*0x137ccf*/
  if ( a1->x_op == XDR_DECODE )
  {
    if ( !a1->x_ops->x_getbytes(a1, a2, a3) )
    {
      printf("xdr_opaque: decode FAILED\n");
      return 0; /*0x137cf4*/
    }
    if ( v3 ) /*0x137cfa*/
      return ((int (__stdcall *)(XDR *, void *))a1->x_ops->x_getbytes)(a1, &unk_1E5A20); /*0x137d0b*/
    return 1; /*0x137cfa*/
  }
  if ( x_op )
  {
    if ( x_op == XDR_FREE )
    {
      return 1; /*0x137d68*/
    }
    else
    {
      printf("xdr_opaque: bad op FAILED\n");
      return 0; /*0x137d63*/
    }
  }
  else
  {
    if ( !a1->x_ops->x_putbytes(a1, a2, a3) )
    {
      printf("xdr_opaque: encode FAILED\n");
      return 0; /*0x137d32*/
    }
    if ( !v3 ) /*0x137d36*/
      return 1; /*0x137d36*/
    return ((int (__stdcall *)(XDR *, void *, unsigned int, int, int, int, int))a1->x_ops->x_putbytes)( /*0x137d4d*/
             a1,
             &unk_1DD213,
             v3,
             v6,
             v7,
             v8,
             savedregs);
  }
}
