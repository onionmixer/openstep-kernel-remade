/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1361f4. */
int __cdecl xdr_rmtcallres(XDR *a1, rmtcallres *a2)
{
  char *port_ptr; // [esp+8h] [ebp-4h] BYREF

  port_ptr = (char *)a2->port_ptr; /*0x136204*/
  if ( !xdr_reference(a1, &port_ptr, 4u, (xdrproc_t)xdr_u_long) || !xdr_u_long(a1, &a2->resultslen) ) /*0x136224*/
    return 0; /*0x136244*/
  a2->port_ptr = (unsigned __int32 *)port_ptr; /*0x136233*/
  return ((int (__stdcall *)(XDR *, caddr_t))a2->xdr_results)(a1, a2->results_ptr); /*0x136249*/
}
