/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00161504 */

void _pset_remove_task(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_2 + 0x2c) == param_1) {
    iVar1 = *(int *)(param_2 + 0x10);
    iVar2 = *(int *)(param_2 + 0x14);
    if (param_1 + 300 == iVar1) {
      *(int *)(param_1 + 0x130) = iVar2;
    }
    else {
      *(int *)(iVar1 + 0x14) = iVar2;
    }
    if (param_1 + 300 == iVar2) {
      *(int *)(param_1 + 300) = iVar1;
    }
    else {
      *(int *)(iVar2 + 0x10) = iVar1;
    }
    *(undefined4 *)(param_2 + 0x2c) = 0;
    *(int *)(param_1 + 0x134) = *(int *)(param_1 + 0x134) + -1;
  }
  return;
}

