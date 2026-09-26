/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001384bc */

undefined4
_xdrmbuf_putbuf(int param_1,undefined4 param_2,uint param_3,undefined4 param_4,undefined4 param_5)

{
  short *psVar1;
  int iVar2;
  
  if ((param_3 & 3) == 0) {
    iVar2 = *(int *)(param_1 + 0x14) + -4;
    *(int *)(param_1 + 0x14) = iVar2;
    if (-1 < iVar2) {
LAB_0013851b:
      **(uint **)(param_1 + 0xc) =
           param_3 >> 0x18 | (param_3 & 0xff0000) >> 8 | (param_3 & 0xff00) << 8 | param_3 << 0x18;
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 4;
      psVar1 = (short *)(*(int *)(param_1 + 0x10) + 8);
      *psVar1 = *psVar1 - *(short *)(param_1 + 0x14);
      iVar2 = _mclgetx(param_4,param_5,param_2,param_3,1);
      if (iVar2 == 0) {
        _printf(s_xdrmbuf_putbuf__mclgetx_failed_001dd463);
        return 0;
      }
      **(int **)(param_1 + 0x10) = iVar2;
      *(undefined4 *)(param_1 + 0x14) = 0;
      return 1;
    }
    if (iVar2 != -4) {
      _printf(s_xdr_mbuf__putlong__long_crosses_m_001dd423);
    }
    if (*(int **)(param_1 + 0x10) != (int *)0x0) {
      iVar2 = **(int **)(param_1 + 0x10);
      *(int *)(param_1 + 0x10) = iVar2;
      if (iVar2 != 0) {
        *(int *)(param_1 + 0xc) = *(int *)(iVar2 + 4) + iVar2;
        *(int *)(param_1 + 0x14) = *(short *)(iVar2 + 8) + -4;
        goto LAB_0013851b;
      }
    }
  }
  return 0;
}

