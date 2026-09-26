/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x134b10. */
_BOOL4 __cdecl xdr_rnmargs(XDR *a1, char *a2)
{
  return xdr_opaque(a1, a2, 0x20u) /*0x134b81*/
      && xdr_string(a1, (char **)a2 + 8, 0xFFu)
      && xdr_opaque(a1, a2 + 36, 0x20u)
      && xdr_string(a1, (char **)a2 + 17, 0xFFu);
}
