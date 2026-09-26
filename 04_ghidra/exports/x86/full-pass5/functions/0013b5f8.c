/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013b5f8 */

int FUN_0013b5f8(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x30);
  uVar2 = *(int *)(iVar1 + 0x50) * _page_size;
  if (*(uint *)(param_2 + 0x18) < uVar2) {
    *(uint *)(param_2 + 0x18) = uVar2;
  }
  iVar3 = (**(code **)(*(int *)(*(int *)(iVar1 + 0x3c) + 0x1c) + 0x18))
                    (*(int *)(iVar1 + 0x3c),param_2,param_3);
  if (iVar3 == 0) {
    *(undefined4 *)(**(int **)(iVar1 + 0x3c) + 0x14) = *(undefined4 *)(param_2 + 0x18);
    iVar3 = 0;
  }
  return iVar3;
}

