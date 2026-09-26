/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x137a44. */
int __cdecl xdr_u_long(XDR *a1, unsigned __int32 *a2)
{
  xdr_op x_op; // eax

  x_op = a1->x_op; /*0x137a4d*/
  if ( a1->x_op == XDR_DECODE ) /*0x137a52*/
    return ((int (__stdcall *)(XDR *, unsigned __int32 *))a1->x_ops->x_getlong)(a1, a2); /*0x137a5b*/
  if ( x_op == XDR_ENCODE ) /*0x137a66*/
    return ((int (__stdcall *)(XDR *, unsigned __int32 *))a1->x_ops->x_putlong)(a1, a2); /*0x137a70*/
  if ( x_op == XDR_FREE ) /*0x137a7b*/
    return 1; /*0x137a90*/
  printf("xdr_u_long: FAILED\n");
  return 0; /*0x137a5f*/
}
