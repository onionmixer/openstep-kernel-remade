
undefined4 _vno_select(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 0x16);
  uVar2 = *(uint *)(iVar1 + 0x28);
  if ((uVar2 == 4) || (((3 < uVar2 && (uVar2 < 10)) && (7 < uVar2)))) {
    uVar3 = (**(code **)(*(int *)(iVar1 + 0x1c) + 0x10))
                      (iVar1,param_2,*(undefined4 *)(param_1 + 0x1e));
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}
