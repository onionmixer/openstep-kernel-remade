/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a11c4 */

undefined4 _PCcopyBIOSData(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return 4;
  }
  iVar1 = _copyout(0,param_1,0x1000);
  if (iVar1 == 0) {
    return 0;
  }
  return 4;
}

