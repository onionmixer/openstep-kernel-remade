
void _kill_tasks(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  
  uVar4 = _pmap_create(0,0,0,1);
  iVar5 = _vm_map_create(uVar4);
  puVar3 = _all_psets;
  while (puVar6 = puVar3, (undefined4 **)puVar6 != &_all_psets) {
    puVar3 = dword_40B6788;
    if (puVar6 != (undefined4 *)_default_pset) {
      _processor_set_destroy(puVar6);
      puVar3 = _all_psets;
    }
  }
  while (iVar2 = dword_40B676C, dword_40B6774 != 0) {
    dword_40B676C = iVar2;
    _pset_remove_task(_default_pset,iVar2);
    iVar1 = *(int *)(iVar2 + 8);
    if ((iVar1 != _kernel_map) && (iVar5 != iVar1)) {
      *(int *)(iVar2 + 8) = iVar5;
      _vm_map_reference(iVar5);
      _vm_map_remove(iVar1,*(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0x14));
    }
  }
  dword_40B676C = iVar2;
  return;
}
