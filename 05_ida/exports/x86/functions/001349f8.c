/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1349f8. */
_BOOL4 __cdecl xdr_creatargs(XDR *a1, char *a2)
{
  return xdr_opaque(a1, a2, 0x20u) /*0x134aa5*/
      && xdr_string(a1, (char **)a2 + 8, 0xFFu)
      && xdr_u_long(a1, (unsigned __int32 *)a2 + 9)
      && xdr_u_long(a1, (unsigned __int32 *)a2 + 10)
      && xdr_u_long(a1, (unsigned __int32 *)a2 + 11)
      && xdr_u_long(a1, (unsigned __int32 *)a2 + 12)
      && sub_134924(a1, (__int32 *)a2 + 13)
      && sub_134924(a1, (__int32 *)a2 + 15);
}
