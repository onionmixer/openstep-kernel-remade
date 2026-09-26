
undefined4
_vm_map_lookup(int *param_1,uint param_2,uint param_3,int *param_4,undefined4 *param_5,int *param_6,
              uint *param_7,int *param_8,uint *param_9)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iStack_c;
  int iStack_8;
  
  iVar7 = *param_1;
  do {
    _lock_read(iVar7);
    iVar1 = *(int *)(iVar7 + 0x30);
    *param_4 = iVar1;
    if (((iVar7 + 8 == iVar1) || (param_2 < *(uint *)(iVar1 + 8))) ||
       (*(uint *)(iVar1 + 0xc) <= param_2)) {
      iVar1 = _vm_map_lookup_entry(iVar7,param_2,&iStack_8);
      if (iVar1 == 0) {
        _lock_done(iVar7);
        return 1;
      }
      *param_4 = iStack_8;
      iVar1 = iStack_8;
    }
    if ((*(byte *)(iVar1 + 0x18) & 0x20) != 0) {
      iVar1 = *(int *)(iVar1 + 0x10);
      *param_1 = iVar1;
      goto loc_405F452;
    }
    uVar5 = *(uint *)(iVar1 + 0x1a);
    if (param_3 != (uVar5 & param_3)) {
      _lock_done(iVar7);
      return 2;
    }
    iVar8 = -(int)-(*(sword *)(iVar1 + 0x26) != 0);
    *param_8 = iVar8;
    if (iVar8 != 0) {
      uVar5 = *(uint *)(iVar1 + 0x1a);
      param_3 = uVar5;
    }
    uVar4 = *(uint *)(iVar1 + 0x18) >> 0x1f ^ 1;
    uVar6 = param_2;
    iVar8 = iVar7;
    if (uVar4 == 0) {
      iVar8 = *(int *)(iVar1 + 0x10);
      uVar6 = *(int *)(iVar1 + 0x14) + (param_2 - *(int *)(iVar1 + 8));
      _lock_read(iVar8);
      iVar2 = _vm_map_lookup_entry(iVar8,uVar6,&iStack_c);
      iVar1 = iStack_c;
      if (iVar2 == 0) {
        _lock_done(iVar8);
        _lock_done(iVar7);
        return 1;
      }
    }
    if ((*(byte *)(iVar1 + 0x18) & 2) != 0) {
      if ((param_3 & 2) == 0) {
        uVar5 = uVar5 & 0xfffffffd;
        goto loc_405F436;
      }
      iVar2 = _lock_read_to_write(iVar8);
      if (iVar2 == 0) {
        _vm_object_shadow(iVar1 + 0x10,iVar1 + 0x14,*(int *)(iVar1 + 0xc) - *(int *)(iVar1 + 8));
        *(byte *)(iVar1 + 0x18) = *(byte *)(iVar1 + 0x18) & 0xfd;
        _lock_write_to_read(iVar8);
        goto loc_405F436;
      }
      goto loc_405F44A;
    }
loc_405F436:
    if (*(int *)(iVar1 + 0x10) != 0) goto loc_405F47E;
    iVar2 = _lock_read_to_write(iVar8);
    if (iVar2 == 0) {
      uVar3 = _vm_object_allocate(*(int *)(iVar1 + 0xc) - *(int *)(iVar1 + 8));
      *(undefined4 *)(iVar1 + 0x10) = uVar3;
      *(undefined4 *)(iVar1 + 0x14) = 0;
      _lock_write_to_read(iVar8);
loc_405F47E:
      *param_6 = *(int *)(iVar1 + 0x14) + (uVar6 - *(int *)(iVar1 + 8));
      *param_5 = *(undefined4 *)(iVar1 + 0x10);
      if (uVar4 == 0) {
        uVar4 = -(int)-(*(int *)(iVar8 + 0x2c) == 1);
      }
      *param_7 = uVar5;
      *param_9 = uVar4;
      return 0;
    }
loc_405F44A:
    iVar1 = iVar7;
    if (iVar7 != iVar8) {
loc_405F452:
      _lock_done(iVar7);
      iVar7 = iVar1;
    }
  } while( true );
}
