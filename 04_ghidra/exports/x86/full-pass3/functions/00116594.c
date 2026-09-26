/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00116594 */

undefined4 _sbreserve(int param_1,uint param_2)

{
  int iVar1;
  
  if (0xcccc < param_2) {
    return 0;
  }
  *(short *)(param_1 + 2) = (short)param_2;
  iVar1 = param_2 * 2;
  if (0xffff < iVar1) {
    iVar1 = 0xffff;
  }
  *(short *)(param_1 + 6) = (short)iVar1;
  return 1;
}

