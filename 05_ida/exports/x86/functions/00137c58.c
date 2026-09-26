/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x137c58. */
int __cdecl xdr_enum(XDR *a1, int *a2)
{
  xdr_op x_op; // eax

  x_op = a1->x_op; /*0x137c64*/
  if ( a1->x_op == XDR_ENCODE ) /*0x137c64*/
    return ((int (__stdcall *)(XDR *, int *))a1->x_ops->x_putlong)(a1, a2); /*0x137c72*/
  if ( x_op == XDR_DECODE ) /*0x137c7b*/
    return ((int (__stdcall *)(XDR *, int *))a1->x_ops->x_getlong)(a1, a2); /*0x137c84*/
  if ( x_op == XDR_FREE ) /*0x137c8f*/
    return 1; /*0x137c91*/
  printf("xdr_long: FAILED\n");
  return 0; /*0x137c74*/
}
