/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x134154. */
_BOOL4 __cdecl xdr_writeargs(XDR *a1, char *a2)
{
  if ( !xdr_opaque(a1, a2, 0x20u) /*0x13419d*/
    || !xdr_long(a1, (__int32 *)a2 + 8)
    || !xdr_long(a1, (__int32 *)a2 + 9)
    || !xdr_long(a1, (__int32 *)a2 + 10) )
  {
    return 0; /*0x1341a7*/
  }
  if ( a1->x_ops == (const __rpc_xdr::xdr_ops *)&xdrmbuf_ops && a1->x_op == XDR_DECODE ) /*0x1341b5*/
    return xdrmbuf_getmbuf(a1, (int)(a2 + 52), (unsigned int *)a2 + 11) != 0; /*0x1341c0*/
  return xdr_bytes(a1, (char **)a2 + 12, (unsigned int *)a2 + 11, 0x2000u) != 0; /*0x1341f1*/
}
