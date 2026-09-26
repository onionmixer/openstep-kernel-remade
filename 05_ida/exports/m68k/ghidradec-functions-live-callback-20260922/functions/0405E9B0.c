
undefined4 _vm_map_delete(int param_1,uint param_2,uint param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puStack_8;
  
  iVar4 = _vm_map_lookup_entry(param_1,param_2,&puStack_8);
  if (iVar4 == 0) {
    puStack_8 = (undefined4 *)puStack_8[1];
  }
  else {
    if ((uint)puStack_8[2] < param_2) {
      __vm_map_clip_start(param_1 + 8,puStack_8,param_2);
    }
    *(undefined4 *)(param_1 + 0x30) = *puStack_8;
  }
  puVar5 = puStack_8;
  if (param_2 <= *(uint *)(*(int *)(param_1 + 0x34) + 8)) {
    *(undefined4 *)(param_1 + 0x34) = *puStack_8;
  }
  while (((undefined4 *)(param_1 + 8) != puVar5 && ((uint)puVar5[2] < param_3))) {
    if (param_3 < (uint)puVar5[3]) {
      __vm_map_clip_end(param_1 + 8,puVar5,param_3);
    }
    puVar1 = (undefined4 *)puVar5[1];
    iVar4 = puVar5[2];
    iVar2 = puVar5[3];
    iVar3 = puVar5[4];
    if (*(sword *)((int)puVar5 + 0x26) != 0) {
      _vm_map_entry_unwire(param_1,puVar5);
    }
    if (iVar3 == _kernel_object) {
      _vm_object_page_remove(iVar3,puVar5[5],(iVar2 - iVar4) + puVar5[5]);
    }
    if (*(int *)(param_1 + 0x28) == 0) {
      _vm_object_pmap_remove(iVar3,puVar5[5],(iVar2 - iVar4) + puVar5[5]);
    }
    _pmap_remove(*(undefined4 *)(param_1 + 0x20),iVar4,iVar2);
    _vm_map_entry_delete(param_1,puVar5);
    puVar5 = puVar1;
  }
  return 0;
}

