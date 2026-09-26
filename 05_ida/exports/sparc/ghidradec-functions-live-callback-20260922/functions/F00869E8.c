
/* WARNING: Removing unreachable block (ram,0xf0086c6c) */
/* WARNING: Removing unreachable block (ram,0xf0086c24) */
/* WARNING: Removing unreachable block (ram,0xf0086bd8) */
/* WARNING: Removing unreachable block (ram,0xf0086ae8) */
/* WARNING: Removing unreachable block (ram,0xf0086a64) */
/* WARNING: Removing unreachable block (ram,0xf0086a40) */
/* WARNING: Removing unreachable block (ram,0xf0086a7c) */
/* WARNING: Removing unreachable block (ram,0xf0086ba8) */
/* WARNING: Removing unreachable block (ram,0xf0086bf0) */
/* WARNING: Removing unreachable block (ram,0xf0086c38) */
/* WARNING: Removing unreachable block (ram,0xf0086cd8) */
/* WARNING: Removing unreachable block (ram,0xf0086a0c) */

undefined8 _vm_object_terminate(int *param_1,undefined *param_2)

{
  sword sVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar8 = param_1[8];
  if (iVar8 != 0) {
    do {
      do {
      } while (*(int *)(iVar8 + 0x10) != 0);
      piVar3 = (int *)(iVar8 + 0x10);
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
    if (*(int **)(iVar8 + 0x1c) == param_1) {
      *(undefined4 *)(iVar8 + 0x1c) = 0;
    }
    else if (*(int **)(iVar8 + 0x1c) != (int *)0x0) {
      _panic(aVmObjectTermin);
    }
    *(undefined4 *)(iVar8 + 0x10) = 0;
  }
  piVar3 = param_1 + 4;
  sVar1 = *(sword *)(param_1 + 0x11);
  while (sVar1 != 0) {
    _thread_sleep(param_1,piVar3,0);
    do {
      do {
      } while (*piVar3 != 0);
      piVar5 = piVar3;
      _simple_lock_try();
    } while (piVar5 == (int *)0x0);
    sVar1 = *(sword *)(param_1 + 0x11);
  }
  if (param_1 != (int *)*param_1) {
    param_2 = DAT_f013c000;
    piVar3 = (int *)*param_1;
    do {
      do {
        do {
        } while (_vm_page_queue_lock != 0);
        puVar7 = &_vm_page_queue_lock;
        _simple_lock_try();
      } while (puVar7 == (undefined4 *)0x0);
      uVar4 = piVar3[7];
      if ((uVar4 & 0x4000) != 0) {
        iVar8 = *piVar3;
        piVar5 = (int *)piVar3[1];
        *(int **)(iVar8 + 4) = piVar5;
        if (piVar5 != &_vm_page_queue_active) {
          *piVar5 = iVar8;
          iVar8 = _vm_page_queue_active;
        }
        _vm_page_queue_active = iVar8;
        piVar3[7] = piVar3[7] & 0xffffbfff;
        _vm_page_active_count = _vm_page_active_count + -1;
        uVar4 = piVar3[7];
      }
      if ((uVar4 & 0x8000) == 0) {
        uVar4 = piVar3[7];
      }
      else {
        iVar8 = *piVar3;
        piVar5 = (int *)piVar3[1];
        *(int **)(iVar8 + 4) = piVar5;
        if (piVar5 != &_vm_page_queue_inactive) {
          *piVar5 = iVar8;
          iVar8 = _vm_page_queue_inactive;
        }
        _vm_page_queue_inactive = iVar8;
        piVar3[7] = piVar3[7] & 0xffff7fff;
        _vm_page_inactive_count = _vm_page_inactive_count + -1;
        uVar4 = piVar3[7];
      }
      piVar5 = (int *)piVar3[2];
      if ((uVar4 & 0x1000) != 0) {
        _vm_page_free(piVar3);
      }
      _vm_page_queue_lock = 0;
      piVar3 = piVar5;
    } while (param_1 != piVar5);
  }
  param_1[4] = 0;
  if (param_1[10] == 0) {
    sVar1 = *(sword *)(param_1 + 0x11);
  }
  else {
    _vm_pager_deallocate();
    sVar1 = *(sword *)(param_1 + 0x11);
  }
  if (sVar1 != 0) {
    _panic(aVmObjectDeallo);
  }
  if (param_1 != (int *)*param_1) {
    iVar8 = *param_1;
    while( true ) {
      do {
        do {
        } while (_vm_page_queue_lock != 0);
        puVar7 = &_vm_page_queue_lock;
        _simple_lock_try();
      } while (puVar7 == (undefined4 *)0x0);
      _vm_page_free(iVar8);
      _vm_page_queue_lock = 0;
      if (param_1 == (int *)*param_1) break;
      iVar8 = *param_1;
    }
  }
  do {
    do {
    } while (_vm_object_list_lock != 0);
    puVar7 = &_vm_object_list_lock;
    _simple_lock_try();
  } while (puVar7 == (undefined4 *)0x0);
  puVar7 = (undefined4 *)param_1[2];
  puVar6 = (undefined4 *)param_1[3];
  puVar2 = puVar6;
  if ((undefined4 **)puVar7 != &_vm_object_list) {
    puVar7[3] = puVar6;
    puVar2 = dword_F013D834;
  }
  dword_F013D834 = puVar2;
  if ((undefined4 **)puVar6 != &_vm_object_list) {
    puVar6[2] = puVar7;
    puVar7 = _vm_object_list;
  }
  _vm_object_list = puVar7;
  _vm_object_list_lock = 0;
  _vm_object_count = _vm_object_count + -1;
  _zfree(_vm_object_zone,param_1);
  return CONCAT44(param_2,param_1);
}

