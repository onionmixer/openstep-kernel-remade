/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x134c54. */
_BOOL4 __cdecl xdr_statfs(XDR *a1, int *a2)
{
  return xdr_union(a1, a2, (char *)a2 + 4, &statfs_discrim, (xdrproc_t)xdr_void) != 0; /*0x134c7a*/
}
