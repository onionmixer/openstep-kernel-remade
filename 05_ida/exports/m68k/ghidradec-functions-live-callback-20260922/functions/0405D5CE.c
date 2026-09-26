
int _kmem_realloc(undefined4 param_1,uint param_2,int param_3,int *param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  uVar3 = ~_page_mask;
  iVar2 = (uVar3 & _page_mask + param_3 + param_2) - (uVar3 & param_2);
  uVar1 = param_5 + _page_mask & uVar3;
  iVar4 = _vm_map_find(param_1,0,0,&iStack_8,uVar1,1);
  iVar4 = -(int)-(iVar4 != 0);
  if (iVar4 == 0) {
    _vm_map_lookup_entry(param_1,iStack_8,&iStack_c);
    iVar4 = _vm_map_lookup_entry(param_1,uVar3 & param_2,&iStack_10);
    if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aKmemRealloc);
    }
    iVar4 = *(int *)(iStack_10 + 0x10);
    _vm_object_reference(iVar4);
    if (iVar2 != *(int *)(iVar4 + 0x10)) {
                    /* WARNING: Subroutine does not return */
      _panic(aKmemRealloc);
    }
    *(uint *)(iVar4 + 0x10) = uVar1;
    *(int *)(iStack_c + 0x10) = iVar4;
    *(undefined4 *)(iStack_c + 0x14) = 0;
    _lock_done(param_1);
    sub_405D774(iVar4,iVar2,uVar1,1);
    _vm_map_pageable(param_1,iStack_8,iStack_8 + uVar1,0);
    *param_4 = iStack_8;
    iVar4 = 0;
  }
  return iVar4;
}

