/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x136a6c. */
int __cdecl xdr_callhdr(XDR *a1, rpc_msg *a2)
{
  a2->rm_direction = CALL; /*0x136a77*/
  a2->ru.RM_cmb.cb_rpcvers = 2; /*0x136a7e*/
  if ( a1->x_op == XDR_ENCODE /*0x136abf*/
    && xdr_u_long(a1, &a2->rm_xid)
    && xdr_enum(a1, (int *)&a2->rm_direction)
    && xdr_u_long(a1, &a2->ru.RM_cmb.cb_rpcvers)
    && xdr_u_long(a1, &a2->ru.RM_cmb.cb_prog) )
  {
    return xdr_u_long(a1, &a2->ru.RM_cmb.cb_vers); /*0x136ad0*/
  }
  else
  {
    return 0; /*0x136ad8*/
  }
}
