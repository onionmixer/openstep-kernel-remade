/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1366bc. */
int __cdecl xdr_rejected_reply(XDR *a1, int *a2)
{
  if ( !xdr_enum(a1, a2) ) /*0x1366d3*/
    return 0; /*0x1366d3*/
  if ( !*a2 ) /*0x1366d9*/
  {
    if ( xdr_u_long(a1, (unsigned __int32 *)a2 + 1) ) /*0x1366e9*/
      return xdr_u_long(a1, (unsigned __int32 *)a2 + 2); /*0x136706*/
    return 0; /*0x1366f7*/
  }
  if ( *a2 == 1 ) /*0x1366de*/
    return xdr_enum(a1, a2 + 1); /*0x13670d*/
  else
    return 0; /*0x136714*/
}
