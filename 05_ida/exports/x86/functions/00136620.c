/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x136620. */
int __cdecl xdr_accepted_reply(XDR *a1, int *a2)
{
  int v2; // eax
  int v3; // eax

  if ( xdr_enum(a1, a2) ) /*0x13662d*/
    v2 = xdr_bytes(a1, (char **)a2 + 1, (unsigned int *)a2 + 2, 0x190u); /*0x136647*/
  else
    v2 = 0; /*0x136654*/
  if ( !v2 || !xdr_enum(a1, a2 + 3) ) /*0x13665f*/
    return 0; /*0x13665f*/
  v3 = a2[3]; /*0x13666b*/
  if ( !v3 ) /*0x136670*/
    return ((int (__stdcall *)(XDR *, int))a2[5])(a1, a2[4]); /*0x136686*/
  if ( v3 != 2 ) /*0x136675*/
    return 1; /*0x136677*/
  if ( xdr_u_long(a1, (unsigned __int32 *)a2 + 4) ) /*0x13668d*/
    return xdr_u_long(a1, (unsigned __int32 *)a2 + 5); /*0x1366a5*/
  else
    return 0; /*0x136699*/
}
