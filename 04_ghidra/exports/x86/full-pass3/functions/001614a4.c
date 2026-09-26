/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001614a4 */

void _pset_add_processor(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x120);
  if (param_1 + 0x11c == iVar1) {
    *(int *)(param_1 + 0x11c) = param_2;
  }
  else {
    *(int *)(iVar1 + 0x134) = param_2;
  }
  *(int *)(param_2 + 0x138) = iVar1;
  *(int *)(param_2 + 0x134) = param_1 + 0x11c;
  *(int *)(param_1 + 0x120) = param_2;
  *(int *)(param_2 + 300) = param_1;
  *(int *)(param_1 + 0x124) = *(int *)(param_1 + 0x124) + 1;
  _quantum_set(param_1);
  return;
}

