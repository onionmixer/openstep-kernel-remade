
undefined4
_vm_object_coalesce(int param_1,int param_2,int param_3,undefined4 param_4,int param_5,int param_6)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    if (param_1 != 0) {
      _vm_object_collapse(param_1);
      if ((((1 < *(sword *)(param_1 + 0x14)) || (*(int *)(param_1 + 0x24) != 0)) ||
          (*(int *)(param_1 + 0x1c) != 0)) || (*(int *)(param_1 + 0x18) != 0)) goto loc_40603CC;
      uVar1 = param_6 + param_5 + param_3;
      _vm_object_page_remove(param_1,param_5 + param_3,uVar1);
      if (*(uint *)(param_1 + 0x10) < uVar1) {
        *(uint *)(param_1 + 0x10) = uVar1;
      }
    }
    uVar2 = 1;
  }
  else {
loc_40603CC:
    uVar2 = 0;
  }
  return uVar2;
}

