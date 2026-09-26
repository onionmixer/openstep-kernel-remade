/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x138868. */
int __cdecl xdr_ip_addr_t(XDR *a1, ip_addr_t *a2)
{
  return xdr_char(a1, (char *)a2) && xdr_char(a1, &a2->host) && xdr_char(a1, &a2->lh) && xdr_char(a1, &a2->impno); /*0x1388bd*/
}
