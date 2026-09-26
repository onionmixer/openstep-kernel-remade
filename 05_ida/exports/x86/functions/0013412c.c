/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13412c. */
int __cdecl xdr_fhandle(XDR *a1, _fhandle a2)
{
  return xdr_opaque(a1, a2, 0x20u) != 0; /*0x134146*/
}
