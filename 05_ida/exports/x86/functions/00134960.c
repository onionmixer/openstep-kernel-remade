/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x134960. */
_BOOL4 __cdecl xdr_saargs(XDR *a1, char *a2)
{
  return xdr_opaque(a1, a2, 0x20u) /*0x1349f1*/
      && xdr_u_long(a1, (unsigned __int32 *)a2 + 8)
      && xdr_u_long(a1, (unsigned __int32 *)a2 + 9)
      && xdr_u_long(a1, (unsigned __int32 *)a2 + 10)
      && xdr_u_long(a1, (unsigned __int32 *)a2 + 11)
      && sub_134924(a1, (__int32 *)a2 + 12)
      && sub_134924(a1, (__int32 *)a2 + 14);
}
