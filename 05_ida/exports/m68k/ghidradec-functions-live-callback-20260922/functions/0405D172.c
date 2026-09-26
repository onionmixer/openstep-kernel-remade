
void _vm_fault_copy_entry(int param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  byte bVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  
  uVar1 = *(undefined4 *)(param_4 + 0x10);
  iVar2 = *(int *)(param_4 + 0x14);
  uVar5 = _vm_object_allocate(*(int *)(param_3 + 0xc) - *(int *)(param_3 + 8));
  *(undefined4 *)(param_3 + 0x10) = uVar5;
  *(undefined4 *)(param_3 + 0x14) = 0;
  uVar3 = *(undefined4 *)(param_3 + 0x1e);
  uVar8 = *(uint *)(param_3 + 8);
  iVar9 = 0;
  if (uVar8 < *(uint *)(param_3 + 0xc)) {
    do {
      while( true ) {
        iVar6 = _vm_page_alloc_sequential(uVar5,iVar9,1);
        if (iVar6 != 0) break;
        _thread_wakeup_prim(&_vm_pages_needed,0,0);
        _thread_sleep(&_vm_page_free_count,&_vm_pages_needed_lock,0);
      }
      iVar7 = _vm_page_lookup(uVar1,iVar2 + iVar9);
      if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(aVmFaultCopyWir);
      }
      _vm_page_copy(iVar7,iVar6);
      _pmap_enter(*(undefined4 *)(param_1 + 0x20),uVar8,*(undefined4 *)(iVar6 + 0x22),uVar3,0);
      _vm_page_activate(iVar6);
      bVar4 = *(byte *)(iVar6 + 0x20);
      *(byte *)(iVar6 + 0x20) = bVar4 & 0x7f;
      if ((bVar4 & 0x40) != 0) {
        *(byte *)(iVar6 + 0x20) = bVar4 & 0x3f;
        _thread_wakeup_prim(iVar6,0,0);
      }
      uVar8 = _page_size + uVar8;
      iVar9 = _page_size + iVar9;
    } while (uVar8 < *(uint *)(param_3 + 0xc));
  }
  return;
}

