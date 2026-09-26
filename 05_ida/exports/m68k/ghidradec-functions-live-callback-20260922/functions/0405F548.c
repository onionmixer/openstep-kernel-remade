
undefined4
_vm_region(int param_1,int *param_2,uint *param_3,undefined4 *param_4,undefined4 *param_5,
          undefined4 *param_6,int *param_7,undefined4 *param_8,int *param_9)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iStack_8;
  
  if (param_1 == 0) {
    uVar2 = 4;
  }
  else {
    iVar4 = *param_2;
    _lock_read(param_1);
    iVar3 = _vm_map_lookup_entry(param_1,iVar4,&iStack_8);
    iVar4 = iStack_8;
    if ((iVar3 == 0) && (iVar4 = *(int *)(iStack_8 + 4), param_1 + 8 == *(int *)(iStack_8 + 4))) {
      _lock_done(param_1);
      uVar2 = 3;
    }
    else {
      iVar3 = *(int *)(iVar4 + 8);
      *param_4 = *(undefined4 *)(iVar4 + 0x1a);
      *param_5 = *(undefined4 *)(iVar4 + 0x1e);
      *param_6 = *(undefined4 *)(iVar4 + 0x22);
      *param_2 = iVar3;
      *param_3 = *(int *)(iVar4 + 0xc) - iVar3;
      iVar3 = *(int *)(iVar4 + 0x14);
      if ((char)*(byte *)(iVar4 + 0x18) < '\0') {
        iVar4 = *(int *)(iVar4 + 0x10);
        _lock_read(iVar4);
        _vm_map_lookup_entry(iVar4,iVar3,&iStack_8);
        uVar1 = *(int *)(iStack_8 + 0xc) - iVar3;
        if (uVar1 < *param_3) {
          *param_3 = uVar1;
        }
        uVar2 = _vm_object_name(*(undefined4 *)(iStack_8 + 0x10));
        *param_8 = uVar2;
        *param_9 = *(int *)(iStack_8 + 0x14) + (iVar3 - *(int *)(iStack_8 + 8));
        *param_7 = -(int)-(*(int *)(iVar4 + 0x2c) != 1);
        _lock_done(iVar4);
      }
      else if ((*(byte *)(iVar4 + 0x18) & 0x20) == 0) {
        *param_7 = 0;
        uVar2 = _vm_object_name(*(undefined4 *)(iVar4 + 0x10));
        *param_8 = uVar2;
        *param_9 = iVar3;
      }
      else {
        *param_7 = 0;
        *param_8 = 0;
        *param_9 = iVar3;
      }
      _lock_done(param_1);
      uVar2 = 0;
    }
  }
  return uVar2;
}

