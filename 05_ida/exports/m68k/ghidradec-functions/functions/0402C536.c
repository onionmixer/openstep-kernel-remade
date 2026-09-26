
void sub_402C536(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = *(int *)(param_1 + 0x2e);
  _bflush(param_1,0xffffffff,0xffffffff);
  iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0x24) + 0x126) + 0x22);
  uVar3 = 0;
  if (*(int *)(iVar1 + 0x90) != 0) {
    do {
      _blkflush(param_1,uVar3 >> 10,iVar2);
      uVar3 = iVar2 + uVar3;
    } while (uVar3 < *(uint *)(iVar1 + 0x90));
  }
  *(word *)(iVar1 + 0x5e) = *(word *)(iVar1 + 0x5e) & 0xffef;
  return;
}
