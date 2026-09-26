/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00151be8 */

void _ipc_thread_enqueue(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    *param_1 = param_2;
    return;
  }
  iVar2 = *(int *)(iVar1 + 0x94);
  *(int *)(param_2 + 0x90) = iVar1;
  *(int *)(param_2 + 0x94) = iVar2;
  *(int *)(iVar1 + 0x94) = param_2;
  *(int *)(iVar2 + 0x90) = param_2;
  return;
}

