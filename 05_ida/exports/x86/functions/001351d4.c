/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1351d4. */
int __cdecl xdr_authunix_parms(XDR *a1, authunix_parms *a2)
{
  return xdr_u_long(a1, &a2->aup_time) /*0x13524d*/
      && xdr_string(a1, &a2->aup_machname, 0xFFu)
      && xdr_int(a1, &a2->aup_uid)
      && xdr_int(a1, &a2->aup_gid)
      && xdr_array(a1, (char **)&a2->aup_gids, &a2->aup_len, 0x10u, 4u, (xdrproc_t)xdr_int);
}
