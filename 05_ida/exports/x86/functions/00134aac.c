/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x134aac. */
_BOOL4 __cdecl xdr_linkargs(XDR *a1, char *a2)
{
  return xdr_opaque(a1, a2, 0x20u) && xdr_opaque(a1, a2 + 32, 0x20u) && xdr_string(a1, (char **)a2 + 16, 0xFFu); /*0x134b09*/
}
