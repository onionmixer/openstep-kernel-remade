/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00161654 */

void _thread_change_psets(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(param_1 + 0x1c);
  if (param_2 + 0x138 == iVar1) {
    *(int *)(param_2 + 0x13c) = iVar2;
  }
  else {
    *(int *)(iVar1 + 0x1c) = iVar2;
  }
  if (param_2 + 0x138 == iVar2) {
    *(int *)(param_2 + 0x138) = iVar1;
  }
  else {
    *(int *)(iVar2 + 0x18) = iVar1;
  }
  *(int *)(param_2 + 0x140) = *(int *)(param_2 + 0x140) + -1;
  iVar1 = *(int *)(param_3 + 0x13c);
  if (param_3 + 0x138 == iVar1) {
    *(int *)(param_3 + 0x138) = param_1;
  }
  else {
    *(int *)(iVar1 + 0x18) = param_1;
  }
  *(int *)(param_1 + 0x1c) = iVar1;
  *(int *)(param_1 + 0x18) = param_3 + 0x138;
  *(int *)(param_3 + 0x13c) = param_1;
  *(int *)(param_1 + 0x180) = param_3;
  *(int *)(param_3 + 0x140) = *(int *)(param_3 + 0x140) + 1;
  return;
}

