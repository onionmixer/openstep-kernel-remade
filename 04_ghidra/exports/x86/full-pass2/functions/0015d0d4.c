/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015d0d4 */

int FUN_0015d0d4(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = _active_threads;
  if (*(int *)(param_2 + 0xc) == 0) {
    iVar3 = param_1 + 8;
    iVar2 = FUN_0015d270(_active_threads,iVar3,*(int *)(param_1 + 4) + -8,param_2 + 8);
    if (iVar2 == 0) {
      iVar2 = FUN_0015d2d4(uVar1,iVar3,*(int *)(param_1 + 4) + -8,param_2 + 4);
      if (iVar2 == 0) {
        iVar2 = FUN_0015d21c(uVar1,iVar3,*(int *)(param_1 + 4) + -8);
        if (iVar2 == 0) {
          *(byte *)(param_2 + 0x10) = *(byte *)(param_2 + 0x10) | 1;
          *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + 1;
          iVar2 = 0;
        }
      }
    }
  }
  else {
    iVar2 = 4;
  }
  return iVar2;
}

