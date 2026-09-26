/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1379ec. */
int __cdecl xdr_long(XDR *a1, __int32 *a2)
{
  xdr_op x_op; // eax

  x_op = a1->x_op; /*0x1379f5*/
  if ( a1->x_op == XDR_ENCODE ) /*0x1379f5*/
    return ((int (__stdcall *)(XDR *, __int32 *))a1->x_ops->x_putlong)(a1, a2); /*0x137a03*/
  if ( x_op == XDR_DECODE ) /*0x137a0f*/
    return ((int (__stdcall *)(XDR *, __int32 *))a1->x_ops->x_getlong)(a1, a2); /*0x137a18*/
  if ( x_op == XDR_FREE ) /*0x137a23*/
    return 1; /*0x137a38*/
  printf("xdr_long: FAILED\n");
  return 0; /*0x137a07*/
}
