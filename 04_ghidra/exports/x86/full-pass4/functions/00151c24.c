/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00151c24 */

int _ipc_thread_dequeue(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 0x90);
    if (iVar2 == iVar1) {
      *param_1 = 0;
    }
    else {
      iVar3 = *(int *)(iVar1 + 0x94);
      *param_1 = iVar2;
      *(int *)(iVar2 + 0x94) = iVar3;
      *(int *)(iVar3 + 0x90) = iVar2;
      *(int *)(iVar1 + 0x90) = iVar1;
      *(int *)(iVar1 + 0x94) = iVar1;
    }
  }
  return iVar1;
}

