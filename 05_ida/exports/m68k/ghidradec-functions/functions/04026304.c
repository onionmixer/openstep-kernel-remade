
void sub_4026304(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iStack_c;
  undefined4 uStack_8;
  
  iVar1 = *(int *)(param_1 + 0x2e);
  _getthetime(&iStack_c);
  *(int *)(iVar1 + 0xb6) = iStack_c;
  *(undefined4 *)(iVar1 + 0xba) = uStack_8;
  uVar3 = iStack_c - *(int *)(iVar1 + 0xa0) >> 4;
  if (*(int *)(param_1 + 0x28) == 2) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x24) + 0x126);
    uVar4 = *(uint *)(iVar2 + 0x66);
    if (uVar4 <= uVar3) {
      uVar4 = *(uint *)(iVar2 + 0x6a);
loc_402636A:
      if (uVar3 <= uVar4) goto loc_4026370;
    }
  }
  else {
    iVar2 = *(int *)(*(int *)(param_1 + 0x24) + 0x126);
    uVar4 = *(uint *)(iVar2 + 0x5e);
    if (uVar4 <= uVar3) {
      uVar4 = *(uint *)(iVar2 + 0x62);
      goto loc_402636A;
    }
  }
  uVar3 = uVar4;
loc_4026370:
  *(int *)(iVar1 + 0xb6) = uVar3 + *(int *)(iVar1 + 0xb6);
  return;
}
