/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001383c8 */

undefined4 _xdrmbuf_getmbuf(XDR *param_1,int *param_2,uint *param_3)

{
  char *pcVar1;
  boolean_t bVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  bVar2 = _xdr_u_int(param_1,param_3);
  if (bVar2 == 0) {
    uVar3 = 0;
  }
  else {
    pcVar1 = param_1->x_base;
    iVar4 = (int)*(short *)(pcVar1 + 8) - param_1->x_handy;
    *(int *)(pcVar1 + 4) = *(int *)(pcVar1 + 4) + iVar4;
    *(short *)(pcVar1 + 8) = *(short *)(pcVar1 + 8) - (short)iVar4;
    *param_2 = (int)pcVar1;
    uVar5 = 0;
    for (; pcVar1 != (char *)0x0; pcVar1 = *(char **)pcVar1) {
      uVar5 = uVar5 + (int)*(short *)(pcVar1 + 8);
    }
    if (uVar5 < *param_3) {
      _printf(s_xdrmbuf_getmbuf_failed_001dd44b);
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
  }
  return uVar3;
}

