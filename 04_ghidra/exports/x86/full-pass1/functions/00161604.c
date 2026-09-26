/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00161604 */

void _pset_add_thread(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x13c);
  if (param_1 + 0x138 == iVar1) {
    *(int *)(param_1 + 0x138) = param_2;
  }
  else {
    *(int *)(iVar1 + 0x18) = param_2;
  }
  *(int *)(param_2 + 0x1c) = iVar1;
  *(int *)(param_2 + 0x18) = param_1 + 0x138;
  *(int *)(param_1 + 0x13c) = param_2;
  *(int *)(param_2 + 0x180) = param_1;
  *(int *)(param_1 + 0x140) = *(int *)(param_1 + 0x140) + 1;
  return;
}

