
undefined4 _vm_map_inherit(int param_1,uint param_2,uint param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iStack_8;
  
  if ((param_4 < 3) && (-1 < param_4)) {
    _lock_write(param_1);
    *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
    if (param_2 < *(uint *)(param_1 + 0x10)) {
      param_2 = *(uint *)(param_1 + 0x10);
    }
    if (*(uint *)(param_1 + 0x14) < param_3) {
      param_3 = *(uint *)(param_1 + 0x14);
    }
    if (param_3 < param_2) {
      param_2 = param_3;
    }
    iVar2 = _vm_map_lookup_entry(param_1,param_2,&iStack_8);
    if (iVar2 == 0) {
      iStack_8 = *(int *)(iStack_8 + 4);
    }
    else if (*(uint *)(iStack_8 + 8) < param_2) {
      __vm_map_clip_start(param_1 + 8,iStack_8,param_2);
    }
    for (iVar2 = iStack_8; (param_1 + 8 != iVar2 && (*(uint *)(iVar2 + 8) < param_3));
        iVar2 = *(int *)(iVar2 + 4)) {
      if (param_3 < *(uint *)(iVar2 + 0xc)) {
        __vm_map_clip_end(param_1 + 8,iVar2,param_3);
      }
      *(int *)(iVar2 + 0x22) = param_4;
    }
    _lock_done(param_1);
    uVar1 = 0;
  }
  else {
    uVar1 = 4;
  }
  return uVar1;
}

