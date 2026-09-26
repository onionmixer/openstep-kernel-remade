
/* WARNING: Removing unreachable block (ram,0xf006d548) */
/* WARNING: Removing unreachable block (ram,0xf006d520) */
/* WARNING: Removing unreachable block (ram,0xf006d5a8) */
/* WARNING: Removing unreachable block (ram,0xf006d4b0) */
/* WARNING: Removing unreachable block (ram,0xf006d590) */
/* WARNING: Removing unreachable block (ram,0xf006d5d4) */
/* WARNING: Removing unreachable block (ram,0xf006d530) */
/* WARNING: Removing unreachable block (ram,0xf006d56c) */
/* WARNING: Removing unreachable block (ram,0xf006d488) */

undefined8 _vmp_invalidate(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  int *piVar5;
  undefined4 unaff_l1;
  int *piVar6;
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
      piVar6 = piVar7 + 4;
      _simple_lock_try();
    } while (piVar6 == (int *)0x0);
    if ((int *)param_1[9] == piVar7) {
      piVar6 = (int *)*piVar7;
      if (piVar7 != piVar6) {
        uVar4 = piVar6[8];
        do {
          piVar5 = (int *)piVar6[2];
          if ((uVar4 >> 0x14 & 1) == 0) {
            if ((int)uVar4 < 0) {
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
                param_1 = piVar7 + 4;
              } while (puVar1 == (undefined4 *)0x0);
              do {
                do {
                } while (*param_1 != 0);
                piVar2 = param_1;
                _simple_lock_try();
                piVar5 = piVar6;
              } while (piVar2 == (int *)0x0);
            }
            else if (*(sword *)(piVar6 + 7) == 0) {
              _pmap_remove_all(piVar6[9]);
              if ((piVar6[7] & 0x400U) != 0) {
                iVar3 = piVar6[9];
                _pmap_is_modified();
                if (iVar3 == 0) {
                  _mfs_mclean._0_4_ = _mfs_mclean._0_4_ + 1;
                  _vm_page_free(piVar6);
                  goto loc_F006D5E4;
                }
              }
              _mfs_mdirty._0_4_ = _mfs_mdirty._0_4_ + 1;
            }
          }
loc_F006D5E4:
          if (piVar7 == piVar5) break;
          uVar4 = piVar5[8];
          piVar6 = piVar5;
        } while( true );
      }
      piVar7[4] = 0;
      _vm_page_queue_lock = 0;
    }
  }
  return CONCAT44(param_2,param_1);
}

