/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013b714 */

undefined4 _verify_and_swap_cg(byte *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x20);
  if ((*param_1 & 4) == 0) {
    _byte_swap_cylgroup(iVar1);
    if (*(int *)(iVar1 + 0x3d4) == 0x90255) {
      uVar2 = 1;
    }
    else {
      _byte_swap_cylgroup(iVar1);
      _brelse(param_1);
      uVar2 = 0;
    }
  }
  else {
    _brelse(param_1);
    uVar2 = 0;
  }
  return uVar2;
}

