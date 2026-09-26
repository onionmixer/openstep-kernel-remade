
undefined4 _spec_fsync(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  iVar1 = *(int *)(param_1 + 0x2e);
  if ((((*(word *)(iVar1 + 0x3e) & 0x46) != 0) || (*(int *)(param_1 + 0x28) == 3)) &&
     (iVar2 = *(int *)(iVar1 + 0x36), iVar2 != 0)) {
    iVar3 = _kalloc(0x3a);
    iVar4 = (**(code **)(*(int *)(*(int *)(iVar1 + 0x36) + 0x1c) + 0x14))
                      (*(int *)(iVar1 + 0x36),iVar3,param_2);
    if (iVar4 == 0) {
      iVar4 = _kalloc(0x3a);
      _vattr_null(iVar4);
      if ((*(int *)(iVar1 + 0x4a) < *(int *)(iVar3 + 0x1c)) ||
         ((*(int *)(iVar1 + 0x4a) == *(int *)(iVar3 + 0x1c) &&
          (*(int *)(iVar1 + 0x4e) < *(int *)(iVar3 + 0x20))))) {
        uVar5 = *(undefined4 *)(iVar3 + 0x1c);
        uVar6 = *(undefined4 *)(iVar3 + 0x20);
      }
      else {
        uVar5 = *(undefined4 *)(iVar1 + 0x4a);
        uVar6 = *(undefined4 *)(iVar1 + 0x4e);
      }
      *(undefined4 *)(iVar4 + 0x1c) = uVar5;
      *(undefined4 *)(iVar4 + 0x20) = uVar6;
      if ((*(int *)(iVar1 + 0x52) < *(int *)(iVar3 + 0x24)) ||
         ((*(int *)(iVar1 + 0x52) == *(int *)(iVar3 + 0x24) &&
          (*(int *)(iVar1 + 0x56) < *(int *)(iVar3 + 0x28))))) {
        uVar5 = *(undefined4 *)(iVar3 + 0x24);
        uVar6 = *(undefined4 *)(iVar3 + 0x28);
      }
      else {
        uVar5 = *(undefined4 *)(iVar1 + 0x52);
        uVar6 = *(undefined4 *)(iVar1 + 0x56);
      }
      *(undefined4 *)(iVar4 + 0x24) = uVar5;
      *(undefined4 *)(iVar4 + 0x28) = uVar6;
      (**(code **)(*(int *)(iVar2 + 0x1c) + 0x18))(iVar2,iVar4,param_2);
      _kfree(iVar4,0x3a);
    }
    _kfree(iVar3,0x3a);
    (**(code **)(*(int *)(iVar2 + 0x1c) + 0x48))(iVar2,param_2);
  }
  return 0;
}
