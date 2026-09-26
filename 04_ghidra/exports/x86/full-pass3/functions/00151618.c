/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00151618 */

int _ipc_splay_traverse_start(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 4);
  if (iVar5 != 0) {
    puVar1 = *(undefined4 **)(param_1 + 0x14);
    **(undefined4 **)(param_1 + 0xc) = *(undefined4 *)(iVar5 + 0x18);
    *puVar1 = *(undefined4 *)(iVar5 + 0x1c);
    *(undefined4 *)(iVar5 + 0x18) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(iVar5 + 0x1c) = *(undefined4 *)(param_1 + 0x10);
    iVar2 = *(int *)(iVar5 + 0x18);
    iVar3 = iVar5;
    iVar4 = 0;
    while (iVar5 = iVar3, iVar2 != 0) {
      iVar3 = *(int *)(iVar5 + 0x18);
      *(int *)(iVar5 + 0x18) = iVar4;
      iVar2 = *(int *)(iVar3 + 0x18);
      iVar4 = iVar5;
    }
    *(int *)(param_1 + 8) = iVar5;
    *(int *)(param_1 + 0x10) = iVar4;
  }
  return iVar5;
}

