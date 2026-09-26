/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1387e8. */
int __cdecl xdr_bp_machine_name_t(XDR *a1, bp_machine_name_t *a2)
{
  return xdr_string(a1, a2, 0xFFu) != 0; /*0x138808*/
}
