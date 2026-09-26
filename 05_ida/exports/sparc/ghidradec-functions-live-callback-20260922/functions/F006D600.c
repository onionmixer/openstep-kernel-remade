
/* WARNING: Removing unreachable block (ram,0xf006d730) */
/* WARNING: Removing unreachable block (ram,0xf006d708) */
/* WARNING: Removing unreachable block (ram,0xf006d884) */
/* WARNING: Removing unreachable block (ram,0xf006d828) */
/* WARNING: Removing unreachable block (ram,0xf006d7f0) */
/* WARNING: Removing unreachable block (ram,0xf006d788) */
/* WARNING: Removing unreachable block (ram,0xf006d670) */
/* WARNING: Removing unreachable block (ram,0xf006d6cc) */
/* WARNING: Removing unreachable block (ram,0xf006d790) */
/* WARNING: Removing unreachable block (ram,0xf006d80c) */
/* WARNING: Removing unreachable block (ram,0xf006d850) */
/* WARNING: Removing unreachable block (ram,0xf006d8b4) */
/* WARNING: Removing unreachable block (ram,0xf006d718) */
/* WARNING: Removing unreachable block (ram,0xf006d754) */
/* WARNING: Removing unreachable block (ram,0xf006d648) */

undefined8 _vmp_push(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar7;
  undefined4 unaff_l3;
  uint uVar8;
  uint uVar9;
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
  if ((param_1[0xe] & 0x40000000U) != 0) {
    uVar8 = param_1[4];
    piVar7 = (int *)param_1[9];
    param_1[0xe] = param_1[0xe] & 0xbfffffff;
    param_1 = (int *)param_1[3];
    if (piVar7 != (int *)0x0) {
      do {
        do {
        } while (_vm_page_queue_lock != 0);
        puVar1 = &_vm_page_queue_lock;
        _simple_lock_try();
      } while (puVar1 == (undefined4 *)0x0);
      do {
        do {
        } while (piVar7[4] != 0);
        piVar2 = piVar7 + 4;
        _simple_lock_try();
      } while (piVar2 == (int *)0x0);
      uVar9 = uVar8 & ~_page_mask;
      uVar8 = (int)param_1 + _page_mask + uVar8 & ~_page_mask;
      if (uVar9 < uVar8) {
        param_2 = 0x40000000;
        do {
          piVar2 = piVar7;
          _vm_page_lookup(piVar7,uVar9);
          if ((piVar2 == (int *)0x0) || (uVar5 = piVar2[8], (uVar5 >> 0x14 & 1) != 0)) {
loc_F006D8C0:
            uVar9 = uVar9 + _page_size;
          }
          else {
            if ((uVar5 & 0x80000000) == 0) {
              if ((piVar2[7] & 0x4000U) == 0) {
                _vm_page_activate(piVar2);
              }
              _vm_page_deactivate(piVar2);
              iVar3 = *piVar2;
              piVar6 = (int *)piVar2[1];
              *(int **)(iVar3 + 4) = piVar6;
              if (piVar6 != &_vm_page_queue_inactive) {
                *piVar6 = iVar3;
                iVar3 = _vm_page_queue_inactive;
              }
              _vm_page_queue_inactive = iVar3;
              piVar2[7] = piVar2[7] & 0xffff7fff;
              _vm_page_inactive_count = _vm_page_inactive_count + -1;
              piVar2[8] = piVar2[8] | 0x80000000;
              if ((piVar2[7] & 0x2000U) != 0) {
                _pmap_remove_all(piVar2[9]);
                piVar7[4] = 0;
                *(sword *)(piVar7 + 0x11) = *(sword *)(piVar7 + 0x11) + 1;
                _vm_page_queue_lock = 0;
                piVar6 = piVar2;
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
                  piVar4 = param_1;
                  _simple_lock_try();
                } while (piVar4 == (int *)0x0);
                *(sword *)(piVar7 + 0x11) = *(sword *)(piVar7 + 0x11) + -1;
                if (piVar6 == (int *)0x0) {
                  piVar2[7] = piVar2[7] & 0xffffdfff;
                }
              }
              _vm_page_activate(piVar2);
              uVar5 = piVar2[8];
              piVar2[8] = uVar5 & 0x7fffffff;
              if ((uVar5 & 0x40000000) != 0) {
                piVar2[8] = uVar5 & 0x3fffffff;
                _thread_wakeup_prim(piVar2,0,0);
              }
              goto loc_F006D8C0;
            }
            piVar2[8] = uVar5 | 0x40000000;
            _assert_wait(piVar2,0);
            piVar7[4] = 0;
            _vm_page_queue_lock = 0;
            _thread_block();
            do {
              do {
              } while (_vm_page_queue_lock != 0);
              puVar1 = &_vm_page_queue_lock;
              _simple_lock_try();
              param_1 = piVar7 + 4;
            } while (puVar1 == (undefined4 *)0x0);
            do {
              do {
              } while (*param_1 != 0);
              piVar2 = param_1;
              _simple_lock_try();
            } while (piVar2 == (int *)0x0);
          }
        } while (uVar9 < uVar8);
      }
      piVar7[4] = 0;
      _vm_page_queue_lock = 0;
    }
  }
  return CONCAT44(param_2,param_1);
}

