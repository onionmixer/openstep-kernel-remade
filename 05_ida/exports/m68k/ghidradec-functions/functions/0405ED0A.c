
/* WARNING: Removing unreachable block (ram,0x0405f00c) */
/* WARNING: Removing unreachable block (ram,0x0405f014) */
/* WARNING: Removing unreachable block (ram,0x0405f01a) */
/* WARNING: Removing unreachable block (ram,0x0405f040) */

int _vm_map_copy(int param_1,int param_2,uint param_3,int param_4,uint param_5,int param_6,
                int param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iStack_8;
  
  uVar8 = param_4 + param_5;
  uVar9 = param_3 + param_4;
  if ((uVar9 < param_3) || (uVar8 < param_5)) {
    return 3;
  }
  if (param_1 == param_2) {
    _lock_write(param_1);
    *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
  }
  else if (param_2 < param_1) {
    _lock_write(param_2);
    *(int *)(param_2 + 0x40) = *(int *)(param_2 + 0x40) + 1;
    _lock_write(param_1);
    *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
  }
  else {
    _lock_write(param_1);
    *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
    _lock_write(param_2);
    *(int *)(param_2 + 0x40) = *(int *)(param_2 + 0x40) + 1;
  }
  iVar12 = 0;
  if ((*(int *)(param_2 + 0x28) != 0) && (*(int *)(param_1 + 0x28) != 0)) {
    iVar3 = _vm_map_check_protection(param_2,param_5,uVar8,1);
    if (iVar3 == 0) {
      iVar12 = 2;
      goto loc_405F05E;
    }
    if (param_6 == 0) {
      iVar3 = _vm_map_check_protection(param_1,param_3,uVar9,2);
      if (iVar3 == 0) {
        iVar12 = 2;
        goto loc_405F05E;
      }
    }
    else {
      iVar12 = _vm_map_insert(param_1,0,0,param_3,uVar9);
      if (iVar12 != 0) goto loc_405F05E;
    }
  }
  _vm_map_lookup_entry(param_2,param_5,&iStack_8);
  iVar3 = iStack_8;
  if (*(uint *)(iStack_8 + 8) < param_5) {
    __vm_map_clip_start(param_2 + 8,iStack_8,param_5);
  }
  _vm_map_lookup_entry(param_1,param_3,&iStack_8);
  iVar11 = iStack_8;
  if (*(uint *)(iStack_8 + 8) < param_3) {
    __vm_map_clip_start(param_1 + 8,iStack_8,param_3);
  }
  uVar5 = param_5;
  if ((iVar11 != iVar3) ||
     (_vm_map_lookup_entry(param_2,param_5,&iStack_8), iVar3 = iStack_8, iVar11 != iStack_8)) {
    while (uVar5 < uVar8) {
      if (uVar8 < *(uint *)(iVar3 + 0xc)) {
        __vm_map_clip_end(param_2 + 8,iVar3,uVar8);
      }
      if (uVar9 < *(uint *)(iVar11 + 0xc)) {
        __vm_map_clip_end(param_1 + 8,iVar11,uVar9);
      }
      uVar5 = *(int *)(iVar3 + 8) + (*(int *)(iVar11 + 0xc) - *(int *)(iVar11 + 8));
      if (uVar5 < *(uint *)(iVar3 + 0xc)) {
        __vm_map_clip_end(param_2 + 8,iVar3,uVar5);
      }
      uVar5 = *(int *)(iVar11 + 8) + (*(int *)(iVar3 + 0xc) - *(int *)(iVar3 + 8));
      if (uVar5 < *(uint *)(iVar11 + 0xc)) {
        __vm_map_clip_end(param_1 + 8,iVar11,uVar5);
      }
      if ((*(char *)(iVar3 + 0x18) < '\0') || (*(char *)(iVar11 + 0x18) < '\0')) {
        iVar2 = *(int *)(iVar11 + 0xc) - *(int *)(iVar11 + 8);
        if (*(char *)(iVar3 + 0x18) < '\0') {
          uVar7 = *(undefined4 *)(iVar3 + 0x14);
          iVar6 = *(int *)(iVar3 + 0x10);
        }
        else {
          uVar7 = *(undefined4 *)(iVar3 + 8);
          _lock_set_recursive(param_2);
          iVar6 = param_2;
        }
        if (*(char *)(iVar11 + 0x18) < '\0') {
          iVar10 = *(int *)(iVar11 + 0x10);
          iVar4 = *(int *)(iVar11 + 0x14);
          iVar1 = iVar2 + iVar4;
          if (iVar6 != iVar10) {
            _lock_write(iVar10);
            *(int *)(iVar10 + 0x40) = *(int *)(iVar10 + 0x40) + 1;
            _vm_map_delete(iVar10,iVar4,iVar1);
            _vm_map_insert(iVar10,0,0,iVar4,iVar1);
            _lock_done(iVar10);
          }
        }
        else {
          iVar4 = *(int *)(iVar11 + 8);
          _lock_set_recursive(param_1);
          iVar10 = param_1;
        }
        _vm_map_copy(iVar10,iVar6,iVar4,iVar2,uVar7,0,0);
        if (iVar10 == param_1) {
          _lock_clear_recursive(param_1);
        }
        if (iVar6 == param_2) {
          _lock_clear_recursive(param_2);
        }
      }
      else {
        _vm_map_copy_entry(param_2,param_1,iVar3,iVar11);
      }
      iVar11 = *(int *)(iVar11 + 4);
      uVar5 = *(uint *)(iVar3 + 0xc);
      iVar3 = *(int *)(iVar3 + 4);
    }
  }
loc_405F05E:
  if (param_7 != 0) {
    _vm_map_delete(param_2,param_5,param_4 + param_5);
  }
  _lock_done(param_2);
  if (param_1 != param_2) {
    _lock_done(param_1);
  }
  return iVar12;
}
