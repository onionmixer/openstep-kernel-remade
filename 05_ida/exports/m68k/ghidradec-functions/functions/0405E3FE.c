
undefined4 _vm_map_protect(int param_1,uint param_2,uint param_3,uint param_4,int param_5)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iStack_c;
  int iStack_8;
  
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
  iVar3 = _vm_map_lookup_entry(param_1,param_2,&iStack_8);
  if (iVar3 == 0) {
    iStack_8 = *(int *)(iStack_8 + 4);
  }
  else if (*(uint *)(iStack_8 + 8) < param_2) {
    __vm_map_clip_start(param_1 + 8,iStack_8,param_2);
  }
  iVar3 = iStack_8;
  while( true ) {
    iVar8 = iStack_8;
    if ((param_1 + 8 == iVar3) || (param_3 <= *(uint *)(iVar3 + 8))) {
      for (; (param_1 + 8 != iVar8 && (*(uint *)(iVar8 + 8) < param_3)); iVar8 = *(int *)(iVar8 + 4)
          ) {
        if (param_3 < *(uint *)(iVar8 + 0xc)) {
          __vm_map_clip_end(param_1 + 8,iVar8,param_3);
        }
        uVar7 = *(uint *)(iVar8 + 0x1a);
        if (param_5 == 0) {
          *(uint *)(iVar8 + 0x1a) = param_4;
        }
        else {
          *(uint *)(iVar8 + 0x1e) = param_4;
          *(uint *)(iVar8 + 0x1a) = uVar7 & param_4;
        }
        if (uVar7 != *(uint *)(iVar8 + 0x1a)) {
          if (*(char *)(iVar8 + 0x18) < '\0') {
            _lock_write(*(undefined4 *)(iVar8 + 0x10));
            piVar1 = (int *)(*(int *)(iVar8 + 0x10) + 0x40);
            *piVar1 = *piVar1 + 1;
            _vm_map_lookup_entry
                      (*(undefined4 *)(iVar8 + 0x10),*(undefined4 *)(iVar8 + 0x14),&iStack_c);
            uVar7 = (*(int *)(iVar8 + 0xc) - *(int *)(iVar8 + 8)) + *(int *)(iVar8 + 0x14);
            for (; (*(int *)(iVar8 + 0x10) + 8 != iStack_c && (*(uint *)(iStack_c + 8) < uVar7));
                iStack_c = *(int *)(iStack_c + 4)) {
              uVar6 = 7;
              if ((*(byte *)(iStack_c + 0x18) & 0x10) != 0) {
                uVar6 = 0xfffffffd;
              }
              uVar4 = *(uint *)(iStack_c + 0xc);
              if (*(uint *)(iStack_c + 0xc) < uVar7) {
                uVar4 = uVar7;
              }
              uVar2 = *(uint *)(iVar8 + 0x14);
              uVar5 = *(uint *)(iStack_c + 8);
              if (*(uint *)(iStack_c + 8) < uVar2) {
                uVar5 = uVar2;
              }
              _pmap_protect(*(undefined4 *)(param_1 + 0x20),*(int *)(iVar8 + 8) + (uVar5 - uVar2),
                            *(int *)(iVar8 + 8) + (uVar4 - uVar2),uVar6 & *(uint *)(iVar8 + 0x1a));
            }
            _lock_done(*(undefined4 *)(iVar8 + 0x10));
          }
          else {
            uVar7 = 7;
            if ((*(byte *)(iStack_8 + 0x18) & 0x10) != 0) {
              uVar7 = 0xfffffffd;
            }
            _pmap_protect(*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(iVar8 + 8),
                          *(undefined4 *)(iVar8 + 0xc),uVar7 & *(uint *)(iVar8 + 0x1a));
          }
        }
      }
      _lock_done(param_1);
      return 0;
    }
    if ((*(byte *)(iVar3 + 0x18) & 0x20) != 0) {
      _lock_done(param_1);
      return 4;
    }
    if (param_4 != (*(uint *)(iVar3 + 0x1e) & param_4)) break;
    iVar3 = *(int *)(iVar3 + 4);
  }
  _lock_done(param_1);
  return 2;
}
