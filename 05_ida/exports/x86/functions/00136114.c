/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x136114. */
int __cdecl xdr_rmtcall_args(XDR *a1, rmtcallargs *a2)
{
  unsigned int v2; // edi
  unsigned int v4; // [esp+10h] [ebp-8h]
  unsigned int v5; // [esp+14h] [ebp-4h]

  if ( !xdr_u_long(a1, &a2->prog) || !xdr_u_long(a1, &a2->vers) || !xdr_u_long(a1, &a2->proc) ) /*0x13614f*/
    return 0; /*0x1361e8*/
  v5 = a1->x_ops->x_getpostn(a1); /*0x136168*/
  if ( !xdr_u_long(a1, &a2->arglen) ) /*0x136173*/
    return 0; /*0x136173*/
  v4 = a1->x_ops->x_getpostn(a1); /*0x136188*/
  if ( !((int (__cdecl *)(XDR *, caddr_t))a2->xdr_args)(a1, a2->args_ptr) ) /*0x136193*/
    return 0; /*0x136193*/
  v2 = a1->x_ops->x_getpostn(a1); /*0x1361a5*/
  a2->arglen = v2 - v4; /*0x1361ac*/
  a1->x_ops->x_setpostn(a1, v5); /*0x1361ba*/
  if ( !xdr_u_long(a1, &a2->arglen) ) /*0x1361c1*/
    return 0; /*0x1361cd*/
  ((void (__stdcall *)(XDR *, unsigned int))a1->x_ops->x_setpostn)(a1, v2); /*0x1361dc*/
  return 1; /*0x1361ed*/
}
