
/* WARNING: Removing unreachable block (ram,0xf006db38) */
/* WARNING: Removing unreachable block (ram,0xf006dadc) */
/* WARNING: Removing unreachable block (ram,0xf006daa4) */
/* WARNING: Removing unreachable block (ram,0xf006da3c) */
/* WARNING: Removing unreachable block (ram,0xf006d9dc) */
/* WARNING: Removing unreachable block (ram,0xf006d9b4) */
/* WARNING: Removing unreachable block (ram,0xf006d948) */
/* WARNING: Removing unreachable block (ram,0xf006d9c4) */
/* WARNING: Removing unreachable block (ram,0xf006da04) */
/* WARNING: Removing unreachable block (ram,0xf006da44) */
/* WARNING: Removing unreachable block (ram,0xf006dac0) */
/* WARNING: Removing unreachable block (ram,0xf006db04) */
/* WARNING: Removing unreachable block (ram,0xf006db68) */
/* WARNING: Removing unreachable block (ram,0xf006d920) */

undefined8 _vmp_push_all(int *param_1,undefined *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  undefined4 unaff_l0;
  int *piVar6;
  undefined4 unaff_l1;
  int *piVar7;
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
  piVar7 = (int *)param_1[9];
  param_1[0xe] = param_1[0xe] & 0xbfffffff;
  if (piVar7 == (int *)0x0) {
locret_F006DB8C:
    return CONCAT44(param_2,param_1);
  }
  do {
    do {
    } while (_vm_page_queue_lock != 0);
    puVar1 = &_vm_page_queue_lock;
    _simple_lock_try();
  } while (puVar1 == (undefined4 *)0x0);
  do {
    do {
    } while (piVar7[4] != 0);
    piVar6 = piVar7 + 4;
    _simple_lock_try();
  } while (piVar6 == (int *)0x0);
  piVar6 = (int *)*piVar7;
loc_F006D960:
  if (piVar7 != piVar6) {
    param_2 = DAT_f013c000;
    uVar4 = piVar6[8];
    do {
      if ((uVar4 >> 0x14 & 1) == 0) {
        if ((uVar4 & 0x80000000) != 0) goto loc_f006d9ac;
        if ((piVar6[7] & 0x4000U) == 0) {
          _vm_page_activate(piVar6);
        }
        _vm_page_deactivate(piVar6);
        iVar2 = *piVar6;
        piVar5 = (int *)piVar6[1];
        *(int **)(iVar2 + 4) = piVar5;
        if (piVar5 != &_vm_page_queue_inactive) {
          *piVar5 = iVar2;
          iVar2 = _vm_page_queue_inactive;
        }
        _vm_page_queue_inactive = iVar2;
        piVar6[7] = piVar6[7] & 0xffff7fff;
        _vm_page_inactive_count = _vm_page_inactive_count + -1;
        piVar6[8] = piVar6[8] | 0x80000000;
        if ((piVar6[7] & 0x2000U) != 0) {
          _pmap_remove_all(piVar6[9]);
          piVar7[4] = 0;
          *(sword *)(piVar7 + 0x11) = *(sword *)(piVar7 + 0x11) + 1;
          _vm_page_queue_lock = 0;
          piVar5 = piVar6;
          _vnode_pageout();
          do {
            do {
            } while (_vm_page_queue_lock != 0);
            puVar1 = &_vm_page_queue_lock;
            _simple_lock_try();
          } while (puVar1 == (undefined4 *)0x0);
          param_1 = piVar7 + 4;
          do {
            do {
            } while (*param_1 != 0);
            piVar3 = param_1;
            _simple_lock_try();
          } while (piVar3 == (int *)0x0);
          *(sword *)(piVar7 + 0x11) = *(sword *)(piVar7 + 0x11) + -1;
          if (piVar5 == (int *)0x0) {
            piVar6[7] = piVar6[7] & 0xffffdfff;
          }
        }
        _vm_page_activate(piVar6);
        uVar4 = piVar6[8];
        piVar6[8] = uVar4 & 0x7fffffff;
        if ((uVar4 & 0x40000000) != 0) {
          piVar6[8] = uVar4 & 0x3fffffff;
          _thread_wakeup_prim(piVar6,0,0);
        }
        piVar6 = (int *)piVar6[2];
      }
      else {
        piVar6 = (int *)piVar6[2];
      }
      if (piVar7 == piVar6) break;
      uVar4 = piVar6[8];
    } while( true );
  }
  piVar7[4] = 0;
  _vm_page_queue_lock = 0;
  goto locret_F006DB8C;
loc_f006d9ac:
  piVar6[8] = uVar4 | 0x40000000;
  _assert_wait(piVar6,0);
  piVar7[4] = 0;
  _vm_page_queue_lock = 0;
  _thread_block();
  do {
    do {
    } while (_vm_page_queue_lock != 0);
    puVar1 = &_vm_page_queue_lock;
    _simple_lock_try();
  } while (puVar1 == (undefined4 *)0x0);
  param_1 = piVar7 + 4;
  do {
    do {
    } while (*param_1 != 0);
    piVar6 = param_1;
    _simple_lock_try();
  } while (piVar6 == (int *)0x0);
  piVar6 = (int *)*piVar7;
  goto loc_F006D960;
}
