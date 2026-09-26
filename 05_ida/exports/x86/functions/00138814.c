/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x138814. */
int __cdecl xdr_bp_path_t(XDR *a1, bp_path_t *a2)
{
  return xdr_string(a1, a2, 0x400u) != 0; /*0x138834*/
}
