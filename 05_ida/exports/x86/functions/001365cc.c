/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1365cc. */
int __cdecl xdr_opaque_auth(XDR *a1, int *a2)
{
  if ( xdr_enum(a1, a2) ) /*0x1365d9*/
    return xdr_bytes(a1, (char **)a2 + 1, (unsigned int *)a2 + 2, 0x190u); /*0x1365f3*/
  else
    return 0; /*0x1365fc*/
}
