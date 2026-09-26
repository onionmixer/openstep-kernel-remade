/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00137d78 */

boolean_t _xdr_bytes(XDR *param_1,char **param_2,uint *param_3,uint param_4)

{
  uint uVar1;
  xdr_op xVar2;
  boolean_t bVar3;
  uint uVar4;
  char *pcVar5;
  
  pcVar5 = *param_2;
  bVar3 = _xdr_u_long(param_1,param_3);
  if (bVar3 == 0) {
    _printf(s_xdr_bytes__size_FAILED_001dd2f8);
    return 0;
  }
  uVar1 = *param_3;
  if ((param_4 < uVar1) && (param_1->x_op != XDR_FREE)) {
    _printf(s_xdr_bytes__bad_size_FAILED_001dd310);
    return 0;
  }
  xVar2 = param_1->x_op;
  if (xVar2 == XDR_DECODE) {
    if (uVar1 == 0) {
      return 1;
    }
    if (pcVar5 == (char *)0x0) {
      pcVar5 = (char *)_kalloc(uVar1);
      *param_2 = pcVar5;
    }
  }
  else if (xVar2 != XDR_ENCODE) {
    if (xVar2 != XDR_FREE) {
      _printf(s_xdr_bytes__bad_op_FAILED_001dd32c);
      return 0;
    }
    if (pcVar5 == (char *)0x0) {
      return 1;
    }
    _kfree(pcVar5,uVar1);
    *param_2 = (char *)0x0;
    return 1;
  }
  if (uVar1 != 0) {
    uVar4 = 0;
    if ((uVar1 & 3) != 0) {
      uVar4 = 4 - (uVar1 & 3);
    }
    xVar2 = param_1->x_op;
    if (xVar2 == XDR_DECODE) {
      bVar3 = (*param_1->x_ops->x_getbytes)(param_1,pcVar5,uVar1);
      if (bVar3 == 0) {
        pcVar5 = s_xdr_opaque__decode_FAILED_001dd2a7;
        goto LAB_00137e9e;
      }
      if (uVar4 != 0) {
        bVar3 = (*param_1->x_ops->x_getbytes)(param_1,&DAT_001e5a20,uVar4);
        return bVar3;
      }
    }
    else if (xVar2 == XDR_ENCODE) {
      bVar3 = (*param_1->x_ops->x_putbytes)(param_1,pcVar5,uVar1);
      if (bVar3 == 0) {
        pcVar5 = s_xdr_opaque__encode_FAILED_001dd2c2;
LAB_00137e9e:
        _printf(pcVar5);
        return 0;
      }
      if (uVar4 != 0) {
        bVar3 = (*param_1->x_ops->x_putbytes)(param_1,&DAT_001dd213,uVar4);
        return bVar3;
      }
    }
    else if (xVar2 != XDR_FREE) {
      pcVar5 = s_xdr_opaque__bad_op_FAILED_001dd2dd;
      goto LAB_00137e9e;
    }
  }
  return 1;
}

