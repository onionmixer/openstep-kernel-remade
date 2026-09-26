/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1389b4. */
int __cdecl xdr_bp_getfile_arg(XDR *a1, bp_getfile_arg *a2)
{
  return xdr_string(a1, &a2->client_name, 0xFFu) && xdr_string(a1, &a2->file_id, 0x20u); /*0x138a05*/
}
