
undefined4 _vm_map_submap(int param_1,uint param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iStack_8;
  
  uVar2 = 4;
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
  iVar1 = _vm_map_lookup_entry(param_1,param_2,&iStack_8);
  if (iVar1 == 0) {
    iStack_8 = *(int *)(iStack_8 + 4);
  }
  else if (*(uint *)(iStack_8 + 8) < param_2) {
    __vm_map_clip_start(param_1 + 8,iStack_8,param_2);
  }
  if (param_3 < *(uint *)(iStack_8 + 0xc)) {
    __vm_map_clip_end(param_1 + 8,iStack_8,param_3);
  }
  if ((((param_2 == *(uint *)(iStack_8 + 8)) && (param_3 == *(uint *)(iStack_8 + 0xc))) &&
      (-1 < (char)*(byte *)(iStack_8 + 0x18))) &&
     ((iVar1 = *(int *)(iStack_8 + 0x10), iVar1 == _vm_submap_object &&
      ((*(byte *)(iStack_8 + 0x18) & 0x10) == 0)))) {
    *(undefined4 *)(iStack_8 + 0x10) = 0;
    _vm_object_deallocate(iVar1);
    *(byte *)(iStack_8 + 0x18) = *(byte *)(iStack_8 + 0x18) | 0x20;
    *(undefined4 *)(iStack_8 + 0x10) = param_4;
    _vm_map_reference(param_4);
    uVar2 = 0;
  }
  _lock_done(param_1);
  return uVar2;
}

