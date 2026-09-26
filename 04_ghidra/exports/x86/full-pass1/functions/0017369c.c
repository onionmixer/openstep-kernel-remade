/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017369c */

void _vm_fault_copy_entry(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  uint local_18;
  int local_c;
  
  iVar3 = *(int *)(param_4 + 0x10);
  iVar4 = *(int *)(param_4 + 0x14);
  iVar6 = _vm_object_allocate(*(int *)(param_3 + 0xc) - *(int *)(param_3 + 8));
  *(int *)(param_3 + 0x10) = iVar6;
  *(undefined4 *)(param_3 + 0x14) = 0;
  uVar5 = *(undefined4 *)(param_3 + 0x20);
  local_18 = *(uint *)(param_3 + 8);
  local_c = 0;
  if (local_18 < *(uint *)(param_3 + 0xc)) {
    piVar1 = (int *)(iVar6 + 0x10);
    do {
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar7 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar7 == 1);
      while (iVar7 = _vm_page_alloc_sequential(iVar6,local_c,1), iVar7 == 0) {
        LOCK();
        *(undefined4 *)(iVar6 + 0x10) = 0;
        UNLOCK();
        do {
        } while (_vm_pages_needed_lock != 0);
        LOCK();
        _vm_pages_needed_lock = 1;
        UNLOCK();
        _thread_wakeup_prim(&_vm_pages_needed,0,0);
        _thread_sleep(&_vm_page_free_count,&_vm_pages_needed_lock,0);
        piVar9 = (int *)(iVar6 + 0x10);
        do {
          do {
          } while (*piVar9 != 0);
          LOCK();
          iVar7 = *piVar9;
          *piVar9 = 1;
          UNLOCK();
        } while (iVar7 == 1);
      }
      piVar9 = (int *)(iVar3 + 0x10);
      do {
        do {
        } while (*piVar9 != 0);
        LOCK();
        iVar8 = *piVar9;
        *piVar9 = 1;
        UNLOCK();
      } while (iVar8 == 1);
      iVar8 = _vm_page_lookup(iVar3,local_c + iVar4);
      if (iVar8 == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_vm_fault_copy_wired__page_missin_001e09da);
      }
      _vm_page_copy(iVar8,iVar7);
      LOCK();
      *(undefined4 *)(iVar3 + 0x10) = 0;
      UNLOCK();
      LOCK();
      *(undefined4 *)(iVar6 + 0x10) = 0;
      UNLOCK();
      _pmap_enter(*(undefined4 *)(param_1 + 0x24),local_18,*(undefined4 *)(iVar7 + 0x24),uVar5,0);
      piVar9 = (int *)(iVar6 + 0x10);
      do {
        do {
        } while (*piVar9 != 0);
        LOCK();
        iVar8 = *piVar9;
        *piVar9 = 1;
        UNLOCK();
      } while (iVar8 == 1);
      do {
      } while (_vm_page_queue_lock != 0);
      LOCK();
      _vm_page_queue_lock = 1;
      UNLOCK();
      _vm_page_activate(iVar7);
      LOCK();
      _vm_page_queue_lock = 0;
      UNLOCK();
      bVar2 = *(byte *)(iVar7 + 0x20);
      *(byte *)(iVar7 + 0x20) = bVar2 & 0xfe;
      if ((bVar2 & 2) != 0) {
        *(byte *)(iVar7 + 0x20) = bVar2 & 0xfc;
        _thread_wakeup_prim(iVar7,0,0);
      }
      LOCK();
      *(undefined4 *)(iVar6 + 0x10) = 0;
      UNLOCK();
      local_18 = local_18 + _page_size;
      local_c = local_c + _page_size;
    } while (local_18 < *(uint *)(param_3 + 0xc));
  }
  return;
}

