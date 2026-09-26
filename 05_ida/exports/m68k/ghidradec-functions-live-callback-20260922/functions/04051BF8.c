
int _map_fd(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uStack_c;
  uint uStack_8;
  
  uVar1 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 8);
  iVar5 = _getf(param_1);
  if (((iVar5 == 0) || (piVar2 = *(int **)(iVar5 + 0x16), *(sword *)(iVar5 + 0xc) != 1)) ||
     (piVar2[10] != 1)) {
loc_4051CEE:
    iVar5 = 4;
  }
  else {
    uVar3 = ~_page_mask & _page_mask + param_5;
    if (param_4 == 0) {
      iVar5 = _copyinmsg(param_3,&uStack_8,4);
      if (iVar5 != 0) {
        return 1;
      }
      uVar4 = uStack_8 & ~_page_mask;
      if ((uStack_8 != uVar4) ||
         (iVar5 = _vm_map_check_protection(uVar1,uVar4,uVar4 + uVar3,3), iVar5 == 0))
      goto loc_4051CEE;
    }
    else {
      iVar5 = _vm_allocate(uVar1,&uStack_8,param_5,1);
      if (iVar5 != 0) {
        return iVar5;
      }
      iVar5 = _copyoutmsg(&uStack_8,param_3,4);
      if (iVar5 != 0) {
        _vm_deallocate(uVar1,uStack_8,param_5);
        return 1;
      }
    }
    if (param_5 == 0) {
      iVar5 = 0;
    }
    else {
      uVar6 = _vnode_pager_setup(piVar2,0,0);
      uVar7 = _pmap_create(uVar3,0,uVar3,1);
      uVar7 = _vm_map_create(uVar7);
      uStack_c = 0;
      iVar5 = _vm_allocate_with_pager(uVar7,&uStack_c,uVar3,0,uVar6,param_2);
      if (((iVar5 != 0) || (iVar5 = _vm_map_copy(uVar1,uVar7,uStack_8,uVar3,0,0,0), iVar5 != 0)) &&
         (param_4 != 0)) {
        _vm_deallocate(uVar1,uStack_8,uVar3);
      }
      _vm_map_deallocate(uVar7);
      if (*(int *)(*piVar2 + 0x2c) == 0) {
        **(sword **)(_active_u + 0x1a) = **(sword **)(_active_u + 0x1a) + 1;
        *(undefined4 *)(*piVar2 + 0x2c) = *(undefined4 *)(_active_u + 0x1a);
      }
    }
  }
  return iVar5;
}

