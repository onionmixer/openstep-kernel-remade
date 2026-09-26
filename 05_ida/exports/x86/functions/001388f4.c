/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1388f4. */
int __cdecl xdr_bp_whoami_arg(XDR *a1, bp_whoami_arg *a2)
{
  return xdr_union( /*0x138925*/
           a1,
           &a2->client_address.address_type,
           (char *)&a2->client_address.bp_address_u,
           &stru_1DD4A4,
           nullptr) != 0;
}
