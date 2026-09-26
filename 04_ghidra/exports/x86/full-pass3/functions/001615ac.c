/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001615ac */

void _pset_remove_thread(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_2 + 0x18);
  iVar2 = *(int *)(param_2 + 0x1c);
  if (param_1 + 0x138 == iVar1) {
    *(int *)(param_1 + 0x13c) = iVar2;
  }
  else {
    *(int *)(iVar1 + 0x1c) = iVar2;
  }
  if (param_1 + 0x138 == iVar2) {
    *(int *)(param_1 + 0x138) = iVar1;
  }
  else {
    *(int *)(iVar2 + 0x18) = iVar1;
  }
  *(undefined4 *)(param_2 + 0x180) = 0;
  *(int *)(param_1 + 0x140) = *(int *)(param_1 + 0x140) + -1;
  return;
}

