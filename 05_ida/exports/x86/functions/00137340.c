/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x137340. */
auth_stat __cdecl _authenticate(svc_req *a1, rpc_msg *a2)
{
  unsigned int oa_flavor; // eax

  a1->rq_cred = *(opaque_auth *)((_BYTE *)&a2->ru.RM_rmb.ru.RP_dr + 1); /*0x13734d*/
  a1->rq_xprt->xp_verf.oa_flavor = _null_auth.oa_flavor; /*0x137365*/
  a1->rq_xprt->xp_verf.oa_length = 0; /*0x13736b*/
  oa_flavor = a1->rq_cred.oa_flavor; /*0x137372*/
  if ( oa_flavor > 2 ) /*0x137378*/
    return AUTH_REJECTEDCRED; /*0x137388*/
  else
    return ((auth_stat (__cdecl *)(svc_req *, rpc_msg *))funcs_137383[oa_flavor])(a1, a2); /*0x137383*/
}
