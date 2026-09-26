/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x134b88. */
_BOOL4 __cdecl xdr_slargs(XDR *a1, char *a2)
{
  return xdr_opaque(a1, a2, 0x20u) /*0x134c4d*/
      && xdr_string(a1, (char **)a2 + 8, 0xFFu)
      && xdr_string(a1, (char **)a2 + 9, 0x400u)
      && xdr_u_long(a1, (unsigned __int32 *)a2 + 10)
      && xdr_u_long(a1, (unsigned __int32 *)a2 + 11)
      && xdr_u_long(a1, (unsigned __int32 *)a2 + 12)
      && xdr_u_long(a1, (unsigned __int32 *)a2 + 13)
      && sub_134924(a1, (__int32 *)a2 + 14)
      && sub_134924(a1, (__int32 *)a2 + 16);
}
