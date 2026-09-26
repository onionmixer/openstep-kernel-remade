/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1388c4. */
int __cdecl xdr_bp_address(XDR *a1, bp_address *a2)
{
  return xdr_union(a1, &a2->address_type, (char *)&a2->bp_address_u, &stru_1DD4A4, nullptr) != 0; /*0x1388ea*/
}
