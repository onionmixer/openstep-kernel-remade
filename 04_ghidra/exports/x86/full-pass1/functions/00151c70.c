/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00151c70 */

void _ipc_thread_rmqueue(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_2 + 0x90);
  iVar2 = *(int *)(param_2 + 0x94);
  if (iVar1 == param_2) {
    *param_1 = 0;
  }
  else {
    if (*param_1 == param_2) {
      *param_1 = iVar1;
    }
    *(int *)(iVar1 + 0x94) = iVar2;
    *(int *)(iVar2 + 0x90) = iVar1;
    *(int *)(param_2 + 0x90) = param_2;
    *(int *)(param_2 + 0x94) = param_2;
  }
  return;
}

