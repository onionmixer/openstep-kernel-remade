/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00133824 */

void FUN_00133824(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = *(int *)(param_1 + 0x30);
  _bflush(param_1,0xffffffff,0xffffffff);
  iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0x24) + 0x128) + 0x24);
  uVar3 = 0;
  if (*(int *)(iVar1 + 0x98) != 0) {
    do {
      _blkflush(param_1,uVar3 >> 10,iVar2);
      uVar3 = uVar3 + iVar2;
    } while (uVar3 < *(uint *)(iVar1 + 0x98));
  }
  *(byte *)(iVar1 + 0x60) = *(byte *)(iVar1 + 0x60) & 0xef;
  return;
}

