/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00178d60 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _vm_object_terminate(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined *puVar10;
  
  iVar3 = param_1[8];
  if (iVar3 != 0) {
    piVar1 = (int *)(iVar3 + 0x10);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    if (*(undefined4 **)(iVar3 + 0x1c) == param_1) {
      *(undefined4 *)(iVar3 + 0x1c) = 0;
    }
    else if (*(undefined4 **)(iVar3 + 0x1c) != (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_vm_object_terminate__copy_shadow_001e0b59);
    }
    LOCK();
    *(undefined4 *)(iVar3 + 0x10) = 0;
    UNLOCK();
  }
  if (*(short *)(param_1 + 0x11) != 0) {
    piVar1 = param_1 + 4;
    do {
      _thread_sleep(param_1,piVar1,0);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar3 == 1);
    } while (*(short *)(param_1 + 0x11) != 0);
  }
  puVar8 = (undefined4 *)*param_1;
  while (param_1 != puVar8) {
    do {
    } while (_vm_page_queue_lock != 0);
    LOCK();
    _vm_page_queue_lock = 1;
    UNLOCK();
    if ((*(byte *)((int)puVar8 + 0x1e) & 2) != 0) {
      puVar4 = (undefined4 *)*puVar8;
      puVar5 = (undefined4 *)puVar8[1];
      puVar9 = puVar5;
      if ((undefined4 **)puVar4 != &_vm_page_queue_active) {
        puVar4[1] = puVar5;
        puVar9 = DAT_001f6e44;
      }
      DAT_001f6e44 = puVar9;
      if ((undefined4 **)puVar5 != &_vm_page_queue_active) {
        *puVar5 = puVar4;
        puVar4 = _vm_page_queue_active;
      }
      _vm_page_queue_active = puVar4;
      *(byte *)((int)puVar8 + 0x1e) = *(byte *)((int)puVar8 + 0x1e) & 0xfd;
      _vm_page_active_count = _vm_page_active_count + -1;
    }
    if ((*(byte *)((int)puVar8 + 0x1e) & 1) != 0) {
      puVar4 = (undefined4 *)*puVar8;
      puVar5 = (undefined4 *)puVar8[1];
      puVar9 = puVar5;
      if ((undefined4 **)puVar4 != &_vm_page_queue_inactive) {
        puVar4[1] = puVar5;
        puVar9 = DAT_001f64e4;
      }
      DAT_001f64e4 = puVar9;
      if ((undefined4 **)puVar5 != &_vm_page_queue_inactive) {
        *puVar5 = puVar4;
        puVar4 = _vm_page_queue_inactive;
      }
      _vm_page_queue_inactive = puVar4;
      *(byte *)((int)puVar8 + 0x1e) = *(byte *)((int)puVar8 + 0x1e) & 0xfe;
      _vm_page_inactive_count = _vm_page_inactive_count + -1;
    }
    puVar4 = (undefined4 *)puVar8[2];
    if ((*(byte *)((int)puVar8 + 0x1e) & 8) != 0) {
      _vm_page_free(puVar8);
    }
    LOCK();
    _vm_page_queue_lock = 0;
    UNLOCK();
    puVar8 = puVar4;
  }
  LOCK();
  param_1[4] = 0;
  UNLOCK();
  if (param_1[10] != 0) {
    _vm_pager_deallocate(param_1[10]);
  }
  if (*(short *)(param_1 + 0x11) == 0) {
    while ((undefined4 *)*param_1 != param_1) {
      do {
      } while (_vm_page_queue_lock != 0);
      LOCK();
      _vm_page_queue_lock = 1;
      UNLOCK();
      _vm_page_free(*param_1);
      LOCK();
      _vm_page_queue_lock = 0;
      UNLOCK();
    }
    do {
    } while (_vm_object_list_lock != 0);
    LOCK();
    UNLOCK();
    puVar6 = (undefined *)param_1[2];
    puVar7 = (undefined *)param_1[3];
    puVar10 = puVar7;
    if (puVar6 != &_vm_object_list) {
      *(undefined **)(puVar6 + 0xc) = puVar7;
      puVar10 = DAT_001f7354;
    }
    DAT_001f7354 = puVar10;
    if (puVar7 != &_vm_object_list) {
      *(undefined **)(puVar7 + 8) = puVar6;
      puVar6 = __vm_object_list;
    }
    __vm_object_list = puVar6;
    __vm_object_count = __vm_object_count + -1;
    LOCK();
    _vm_object_list_lock = 0;
    UNLOCK();
    _zfree(_vm_object_zone,param_1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_vm_object_deallocate__pageout_in_001e0b88);
}

