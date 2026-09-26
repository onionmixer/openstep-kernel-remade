/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013b5a8 */

int FUN_0013b5a8(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x30);
  iVar2 = *(int *)(iVar1 + 0x3c);
  iVar3 = (**(code **)(*(int *)(iVar2 + 0x1c) + 0x14))(iVar2,param_2,param_3);
  iVar2 = _page_size;
  if (iVar3 == 0) {
    *(int *)(param_2 + 0x18) = *(int *)(iVar1 + 0x50) * _page_size;
    *(int *)(param_2 + 0x1c) = iVar2;
    *(uint *)(param_2 + 0x3c) = *(uint *)(param_2 + 0x18) >> 9;
    *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) | 0xc000;
    iVar3 = 0;
  }
  return iVar3;
}

