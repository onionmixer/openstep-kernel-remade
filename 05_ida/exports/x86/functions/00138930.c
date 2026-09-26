/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x138930. */
int __cdecl xdr_bp_whoami_res(XDR *a1, bp_whoami_res *a2)
{
  return xdr_string(a1, &a2->client_name, 0xFFu) /*0x1389ad*/
      && xdr_string(a1, &a2->domain_name, 0xFFu)
      && xdr_union(
           a1,
           &a2->router_address.address_type,
           (char *)&a2->router_address.bp_address_u,
           &stru_1DD4A4,
           nullptr);
}
