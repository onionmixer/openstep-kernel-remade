/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00138134 */

boolean_t _xdr_array(XDR *param_1,char **param_2,uint *param_3,uint param_4,uint param_5,
                    xdrproc_t param_6)

{
  uint uVar1;
  boolean_t bVar2;
  size_t sVar3;
  uint uVar4;
  char *pcVar5;
  bool bVar6;
  boolean_t bVar7;
  
  pcVar5 = *param_2;
  bVar7 = 1;
  bVar2 = _xdr_u_int(param_1,param_3);
  if (bVar2 == 0) {
    _printf(s_xdr_array__size_FAILED_001dd3af);
    return 0;
  }
  uVar1 = *param_3;
  if ((param_4 < uVar1) && (param_1->x_op != XDR_FREE)) {
    _printf(s_xdr_array__bad_size_FAILED_001dd3c7);
    return 0;
  }
  sVar3 = param_5 * uVar1;
  if (pcVar5 == (char *)0x0) {
    if (param_1->x_op == XDR_DECODE) {
      if (uVar1 == 0) {
        return 1;
      }
      pcVar5 = (char *)_kalloc(sVar3);
      *param_2 = pcVar5;
      _bzero(pcVar5,sVar3);
    }
    else if (param_1->x_op == XDR_FREE) {
      return 1;
    }
  }
  uVar4 = 0;
  if (uVar1 != 0) {
    do {
      bVar6 = bVar7 == 0;
      bVar7 = 0;
      if (bVar6) break;
      bVar7 = (*param_6)(param_1,pcVar5,0xffffffff);
      pcVar5 = pcVar5 + param_5;
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  if (param_1->x_op == XDR_FREE) {
    _kfree(*param_2,sVar3);
    *param_2 = (char *)0x0;
  }
  return bVar7;
}

