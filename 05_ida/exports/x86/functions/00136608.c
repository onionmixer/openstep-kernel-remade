/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x136608. */
int __cdecl xdr_des_block(XDR *a1, des_block *a2)
{
  return xdr_opaque(a1, (char *)a2, 8u); /*0x13661c*/
}
