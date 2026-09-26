/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013826c */

undefined4 _xdrmbuf_getlong(int param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = *(int *)(param_1 + 0x14) + -4;
  *(int *)(param_1 + 0x14) = iVar2;
  if (iVar2 < 0) {
    if (iVar2 != -4) {
      _printf(s_xdr_mbuf__long_crosses_mbufs__001dd404);
    }
    if (*(int **)(param_1 + 0x10) != (int *)0x0) {
      iVar2 = **(int **)(param_1 + 0x10);
      *(int *)(param_1 + 0x10) = iVar2;
      if (iVar2 != 0) {
        *(int *)(param_1 + 0xc) = *(int *)(iVar2 + 4) + iVar2;
        *(int *)(param_1 + 0x14) = *(short *)(iVar2 + 8) + -4;
        goto LAB_001382ba;
      }
    }
    uVar3 = 0;
  }
  else {
LAB_001382ba:
    uVar1 = **(uint **)(param_1 + 0xc);
    *param_2 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 4;
    uVar3 = 1;
  }
  return uVar3;
}

