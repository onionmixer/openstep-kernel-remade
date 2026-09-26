/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x138a90. */
int __cdecl xdr_fhstatus(XDR *a1, fhstatus *a2)
{
  return xdr_int(a1, (int *)a2) && (a2->fhs_status || xdr_fhandle(a1, a2->fhstatus_u.fhs_fhandle)); /*0x138ac8*/
}
