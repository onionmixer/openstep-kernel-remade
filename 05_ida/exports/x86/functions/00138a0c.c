/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x138a0c. */
int __cdecl xdr_bp_getfile_res(XDR *a1, bp_getfile_res *a2)
{
  return xdr_string(a1, &a2->server_name, 0xFFu) /*0x138a89*/
      && xdr_union(
           a1,
           &a2->server_address.address_type,
           (char *)&a2->server_address.bp_address_u,
           &stru_1DD4A4,
           nullptr)
      && xdr_string(a1, &a2->server_path, 0x400u);
}
