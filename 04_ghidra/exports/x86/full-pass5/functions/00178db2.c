/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00178db2 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00178db2(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined *puVar9;
  int unaff_EBX;
  undefined4 *unaff_ESI;
  
  LOCK();
  *(undefined4 *)(unaff_EBX + 0x10) = 0;
  UNLOCK();
  if (*(short *)(unaff_ESI + 0x11) != 0) {
    piVar1 = unaff_ESI + 4;
    do {
      _thread_sleep();
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar2 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar2 == 1);
    } while (*(short *)(unaff_ESI + 0x11) != 0);
  }
  puVar7 = (undefined4 *)*unaff_ESI;
  while (unaff_ESI != puVar7) {
    do {
    } while (_vm_page_queue_lock != 0);
    LOCK();
    _vm_page_queue_lock = 1;
    UNLOCK();
    if ((*(byte *)((int)puVar7 + 0x1e) & 2) != 0) {
      puVar3 = (undefined4 *)*puVar7;
      puVar4 = (undefined4 *)puVar7[1];
      puVar8 = puVar4;
      if ((undefined4 **)puVar3 != &_vm_page_queue_active) {
        puVar3[1] = puVar4;
        puVar8 = DAT_001f6e44;
      }
      DAT_001f6e44 = puVar8;
      if ((undefined4 **)puVar4 != &_vm_page_queue_active) {
        *puVar4 = puVar3;
        puVar3 = _vm_page_queue_active;
      }
      _vm_page_queue_active = puVar3;
      *(byte *)((int)puVar7 + 0x1e) = *(byte *)((int)puVar7 + 0x1e) & 0xfd;
      _vm_page_active_count = _vm_page_active_count + -1;
    }
    if ((*(byte *)((int)puVar7 + 0x1e) & 1) != 0) {
      puVar3 = (undefined4 *)*puVar7;
      puVar4 = (undefined4 *)puVar7[1];
      puVar8 = puVar4;
      if ((undefined4 **)puVar3 != &_vm_page_queue_inactive) {
        puVar3[1] = puVar4;
        puVar8 = DAT_001f64e4;
      }
      DAT_001f64e4 = puVar8;
      if ((undefined4 **)puVar4 != &_vm_page_queue_inactive) {
        *puVar4 = puVar3;
        puVar3 = _vm_page_queue_inactive;
      }
      _vm_page_queue_inactive = puVar3;
      *(byte *)((int)puVar7 + 0x1e) = *(byte *)((int)puVar7 + 0x1e) & 0xfe;
      _vm_page_inactive_count = _vm_page_inactive_count + -1;
    }
    puVar3 = (undefined4 *)puVar7[2];
    if ((*(byte *)((int)puVar7 + 0x1e) & 8) != 0) {
      _vm_page_free();
    }
    LOCK();
    _vm_page_queue_lock = 0;
    UNLOCK();
    puVar7 = puVar3;
  }
  LOCK();
  unaff_ESI[4] = 0;
  UNLOCK();
  if (unaff_ESI[10] != 0) {
    _vm_pager_deallocate();
  }
  if (*(short *)(unaff_ESI + 0x11) == 0) {
    while ((undefined4 *)*unaff_ESI != unaff_ESI) {
      do {
      } while (_vm_page_queue_lock != 0);
      LOCK();
      _vm_page_queue_lock = 1;
      UNLOCK();
      _vm_page_free();
      LOCK();
      _vm_page_queue_lock = 0;
      UNLOCK();
    }
    do {
    } while (_vm_object_list_lock != 0);
    LOCK();
    UNLOCK();
    puVar5 = (undefined *)unaff_ESI[2];
    puVar6 = (undefined *)unaff_ESI[3];
    puVar9 = puVar6;
    if (puVar5 != &_vm_object_list) {
      *(undefined **)(puVar5 + 0xc) = puVar6;
      puVar9 = DAT_001f7354;
    }
    DAT_001f7354 = puVar9;
    if (puVar6 != &_vm_object_list) {
      *(undefined **)(puVar6 + 8) = puVar5;
      puVar5 = __vm_object_list;
    }
    __vm_object_list = puVar5;
    __vm_object_count = __vm_object_count + -1;
    LOCK();
    _vm_object_list_lock = 0;
    UNLOCK();
    _zfree(_vm_object_zone);
    return;
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_vm_object_deallocate__pageout_in_001e0b88);
}

