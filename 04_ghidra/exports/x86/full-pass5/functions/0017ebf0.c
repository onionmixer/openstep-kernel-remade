/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017ebf0 */

undefined4 FUN_0017ebf0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0xc);
  *(int *)(param_1 + 0xc) = iVar1 + -1;
  if (iVar1 == 1 || iVar1 + -1 < 0) {
    uVar2 = _objc_msgSend(*(undefined4 *)(param_1 + 4),PTR_s__destroyItem__001f926c,param_1);
    return uVar2;
  }
  return 0;
}

