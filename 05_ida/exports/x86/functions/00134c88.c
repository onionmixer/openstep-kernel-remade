/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x134c88. */
_BOOL4 __cdecl sub_134C88(XDR *a1, char *a2)
{
  return xdr_opaque(a1, a2, 0x20u) && sub_1341F8(a1, (int *)a2 + 8); /*0x134cc5*/
}
