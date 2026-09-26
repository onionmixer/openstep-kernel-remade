/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00161560 */

void _pset_add_task(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x130);
  if (param_1 + 300 == iVar1) {
    *(int *)(param_1 + 300) = param_2;
  }
  else {
    *(int *)(iVar1 + 0x10) = param_2;
  }
  *(int *)(param_2 + 0x14) = iVar1;
  *(int *)(param_2 + 0x10) = param_1 + 300;
  *(int *)(param_1 + 0x130) = param_2;
  *(int *)(param_2 + 0x2c) = param_1;
  *(int *)(param_1 + 0x134) = *(int *)(param_1 + 0x134) + 1;
  return;
}

