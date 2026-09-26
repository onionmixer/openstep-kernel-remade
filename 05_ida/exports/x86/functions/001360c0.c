/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1360c0. */
int __cdecl xdr_pmap(XDR *a1, pmap *a2)
{
  if ( xdr_u_long(a1, &a2->pm_prog) && xdr_u_long(a1, &a2->pm_vers) && xdr_u_long(a1, &a2->pm_prot) ) /*0x1360ef*/
    return xdr_u_long(a1, &a2->pm_port); /*0x136100*/
  else
    return 0; /*0x136108*/
}
