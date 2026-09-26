/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011654c */

undefined4 _soreserve(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = _sbreserve(param_1 + 0x3c,param_2);
  if (iVar1 != 0) {
    iVar1 = _sbreserve(param_1 + 0x24,param_3);
    if (iVar1 != 0) {
      return 0;
    }
    _sbrelease(param_1 + 0x3c);
  }
  return 0x37;
}

