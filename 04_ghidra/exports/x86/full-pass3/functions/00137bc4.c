/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00137bc4 */

boolean_t _xdr_bool(XDR *param_1,boolean_t *param_2)

{
  xdr_op xVar1;
  boolean_t bVar2;
  uint local_8;
  
  xVar1 = param_1->x_op;
  if (xVar1 == XDR_DECODE) {
    bVar2 = (*param_1->x_ops->x_getlong)(param_1,(int *)&local_8);
    if (bVar2 == 0) {
      _printf(s_xdr_bool__decode_FAILED_001dd275);
      return 0;
    }
    *param_2 = (uint)(local_8 != 0);
  }
  else {
    if (xVar1 == XDR_ENCODE) {
      local_8 = (uint)(*param_2 != 0);
      bVar2 = (*param_1->x_ops->x_putlong)(param_1,(int *)&local_8);
      return bVar2;
    }
    if (xVar1 != XDR_FREE) {
      _printf(s_xdr_bool__bad_op_FAILED_001dd28e);
      return 0;
    }
  }
  return 1;
}

