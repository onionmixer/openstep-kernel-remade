/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1345b4. */
_BOOL4 __cdecl xdr_rddirargs(XDR *a1, char *a2)
{
  return xdr_opaque(a1, a2, 0x20u) /*0x134601*/
      && xdr_u_long(a1, (unsigned __int32 *)a2 + 8)
      && xdr_u_long(a1, (unsigned __int32 *)a2 + 9);
}
