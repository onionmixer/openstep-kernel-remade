/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x137edc. */
int __cdecl xdr_netobj(XDR *a1, netobj *a2)
{
  return xdr_bytes(a1, &a2->n_bytes, &a2->n_len, 0x400u); /*0x137ef7*/
}
