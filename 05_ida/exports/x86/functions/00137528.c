/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x137528. */
SVCXPRT *__cdecl svckudp_create(int a1, unsigned __int16 a2)
{
  SVCXPRT *v2; // edi
  char *v3; // esi

  v2 = (SVCXPRT *)kalloc(0x34u); /*0x137539*/
  v2->xp_p1 = (caddr_t)kalloc(0x2260u); /*0x137545*/
  v3 = (char *)kalloc(0x1CCu); /*0x137552*/
  bzero(v3, 0x1CCu); /*0x13755a*/
  v2->xp_addrlen = 0; /*0x13755f*/
  v2->xp_p2 = v3; /*0x137566*/
  v2->xp_verf.oa_base = v3 + 60; /*0x13756c*/
  v2->xp_ops = (SVCXPRT::xp_ops *)&svckudp_op; /*0x13756f*/
  v2->xp_port = a2; /*0x137576*/
  v2->xp_sock = a1; /*0x13757d*/
  xprt_register(v2); /*0x137580*/
  return v2; /*0x13758a*/
}
