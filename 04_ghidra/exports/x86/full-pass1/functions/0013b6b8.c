/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013b6b8 */

int FUN_0013b6b8(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x128) + 0x30) + 0x3c) + 0x24);
  iVar1 = (**(code **)(*(int *)(iVar1 + 4) + 0xc))(iVar1,param_2);
  if (iVar1 == 0) {
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) | 0xc000;
    iVar1 = 0;
  }
  return iVar1;
}

