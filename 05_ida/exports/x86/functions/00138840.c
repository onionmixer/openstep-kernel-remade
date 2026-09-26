/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x138840. */
int __cdecl xdr_bp_fileid_t(XDR *a1, bp_fileid_t *a2)
{
  return xdr_string(a1, a2, 0x20u) != 0; /*0x13885d*/
}
