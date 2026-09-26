/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00137fa0 */

boolean_t _xdr_string(XDR *param_1,char **param_2,uint param_3)

{
  char cVar1;
  xdr_op xVar2;
  boolean_t bVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  uint local_8;
  
  pcVar6 = *param_2;
  if (param_1->x_op == XDR_ENCODE) {
LAB_00137fcc:
    uVar4 = 0xffffffff;
    pcVar5 = pcVar6;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    local_8 = ~uVar4 - 1;
  }
  else if (param_1->x_op == XDR_FREE) {
    if (pcVar6 == (char *)0x0) {
      return 1;
    }
    goto LAB_00137fcc;
  }
  bVar3 = _xdr_u_long(param_1,&local_8);
  if (bVar3 == 0) {
    _printf(s_xdr_string__size_FAILED_001dd35e);
    return 0;
  }
  if (param_3 < local_8) {
    _printf(s_xdr_string__bad_size_FAILED_001dd377);
    return 0;
  }
  xVar2 = param_1->x_op;
  if (xVar2 == XDR_DECODE) {
    if (pcVar6 == (char *)0x0) {
      pcVar6 = (char *)_kalloc(local_8 + 1);
      *param_2 = pcVar6;
    }
    pcVar6[local_8] = '\0';
  }
  else if (xVar2 != XDR_ENCODE) {
    if (xVar2 == XDR_FREE) {
      _kfree(pcVar6,local_8 + 1);
      *param_2 = (char *)0x0;
      return 1;
    }
    _printf(s_xdr_string__bad_op_FAILED_001dd394);
    return 0;
  }
  if (local_8 != 0) {
    uVar4 = 0;
    if ((local_8 & 3) != 0) {
      uVar4 = 4 - (local_8 & 3);
    }
    xVar2 = param_1->x_op;
    if (xVar2 == XDR_DECODE) {
      bVar3 = (*param_1->x_ops->x_getbytes)(param_1,pcVar6,local_8);
      if (bVar3 == 0) {
        pcVar6 = s_xdr_opaque__decode_FAILED_001dd2a7;
        goto LAB_001380fa;
      }
      if (uVar4 != 0) {
        bVar3 = (*param_1->x_ops->x_getbytes)(param_1,&DAT_001e5a20,uVar4);
        return bVar3;
      }
    }
    else if (xVar2 == XDR_ENCODE) {
      bVar3 = (*param_1->x_ops->x_putbytes)(param_1,pcVar6,local_8);
      if (bVar3 == 0) {
        pcVar6 = s_xdr_opaque__encode_FAILED_001dd2c2;
LAB_001380fa:
        _printf(pcVar6);
        return 0;
      }
      if (uVar4 != 0) {
        bVar3 = (*param_1->x_ops->x_putbytes)(param_1,&DAT_001dd213,uVar4);
        return bVar3;
      }
    }
    else if (xVar2 != XDR_FREE) {
      pcVar6 = s_xdr_opaque__bad_op_FAILED_001dd2dd;
      goto LAB_001380fa;
    }
  }
  return 1;
}

