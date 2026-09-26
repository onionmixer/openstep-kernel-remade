/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1348a8. */
_BOOL4 __cdecl xdr_diropargs(XDR *a1, char *a2)
{
  return xdr_opaque(a1, a2, 0x20u) && xdr_string(a1, (char **)a2 + 8, 0xFFu); /*0x1348e9*/
}
