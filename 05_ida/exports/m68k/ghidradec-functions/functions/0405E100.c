
undefined4
_vm_map_find(int param_1,undefined4 param_2,undefined4 param_3,uint *param_4,int param_5,int param_6
            )

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iStack_8;
  
  uVar4 = *param_4;
  _lock_write(param_1);
  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
  if (param_6 == 0) {
loc_405E1B4:
    uVar3 = _vm_map_insert(param_1,param_2,param_3,uVar4,uVar4 + param_5);
    _lock_done(param_1);
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x10);
    if (uVar4 < uVar1) {
      uVar4 = uVar1;
    }
    if (uVar4 <= *(uint *)(param_1 + 0x14)) {
      if (uVar1 == uVar4) {
        iStack_8 = *(int *)(param_1 + 0x34);
        if (param_1 + 8 != iStack_8) {
          uVar4 = *(uint *)(iStack_8 + 0xc);
        }
      }
      else {
        iVar2 = _vm_map_lookup_entry(param_1,uVar4,&iStack_8);
        if (iVar2 != 0) {
          uVar4 = *(uint *)(iStack_8 + 0xc);
        }
      }
      while ((uVar1 = uVar4 + param_5, uVar1 <= *(uint *)(param_1 + 0x14) && (uVar4 <= uVar1))) {
        iVar2 = *(int *)(iStack_8 + 4);
        if ((param_1 + 8 == iVar2) || (uVar1 <= *(uint *)(iVar2 + 8))) {
          *param_4 = uVar4;
          *(int *)(param_1 + 0x30) = iStack_8;
          goto loc_405E1B4;
        }
        iStack_8 = iVar2;
        uVar4 = *(uint *)(iVar2 + 0xc);
      }
    }
    _lock_done(param_1);
    uVar3 = 3;
  }
  return uVar3;
}
