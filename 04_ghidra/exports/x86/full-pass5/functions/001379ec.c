/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001379ec */

boolean_t _xdr_long(XDR *param_1,int *param_2)

{
  xdr_op xVar1;
  boolean_t bVar2;
  
  xVar1 = param_1->x_op;
  if (xVar1 == XDR_ENCODE) {
    bVar2 = (*param_1->x_ops->x_putlong)(param_1,param_2);
    return bVar2;
  }
  if (xVar1 == XDR_DECODE) {
    bVar2 = (*param_1->x_ops->x_getlong)(param_1,param_2);
    return bVar2;
  }
  if (xVar1 != XDR_FREE) {
    _printf(s_xdr_long__FAILED_001dd217);
    return 0;
  }
  return 1;
}

