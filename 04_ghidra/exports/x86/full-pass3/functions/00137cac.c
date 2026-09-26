/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00137cac */

boolean_t _xdr_opaque(XDR *param_1,char *param_2,uint param_3)

{
  xdr_op xVar1;
  boolean_t bVar2;
  uint uVar3;
  
  if (param_3 != 0) {
    uVar3 = 0;
    if ((param_3 & 3) != 0) {
      uVar3 = 4 - (param_3 & 3);
    }
    xVar1 = param_1->x_op;
    if (xVar1 == XDR_DECODE) {
      bVar2 = (*param_1->x_ops->x_getbytes)(param_1,param_2,param_3);
      if (bVar2 == 0) {
        _printf(s_xdr_opaque__decode_FAILED_001dd2a7);
        return 0;
      }
      if (uVar3 != 0) {
        bVar2 = (*param_1->x_ops->x_getbytes)(param_1,&DAT_001e5a20,uVar3);
        return bVar2;
      }
    }
    else {
      if (xVar1 != XDR_ENCODE) {
        if (xVar1 != XDR_FREE) {
          _printf(s_xdr_opaque__bad_op_FAILED_001dd2dd);
          return 0;
        }
        return 1;
      }
      bVar2 = (*param_1->x_ops->x_putbytes)(param_1,param_2,param_3);
      if (bVar2 == 0) {
        _printf(s_xdr_opaque__encode_FAILED_001dd2c2);
        return 0;
      }
      if (uVar3 != 0) {
        bVar2 = (*param_1->x_ops->x_putbytes)(param_1,&DAT_001dd213,uVar3);
        return bVar2;
      }
    }
  }
  return 1;
}

