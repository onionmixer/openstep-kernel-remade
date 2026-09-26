
/* WARNING: Removing unreachable block (ram,0xf0076230) */
/* WARNING: Removing unreachable block (ram,0xf0076338) */
/* WARNING: Removing unreachable block (ram,0xf007626c) */
/* WARNING: Removing unreachable block (ram,0xf007631c) */
/* WARNING: Removing unreachable block (ram,0xf007635c) */
/* WARNING: Removing unreachable block (ram,0xf007623c) */
/* WARNING: Removing unreachable block (ram,0xf00761e8) */

undefined8
_processor_set_stack_usage
          (int param_1,int param_2,undefined4 param_3,undefined4 param_4,uint *param_5,int *param_6)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 unaff_l1;
  int iVar8;
  uint uVar9;
  undefined4 unaff_l3;
  uint uVar10;
  undefined4 unaff_l4;
  uint uVar11;
  undefined4 unaff_l5;
  uint uVar12;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar13;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  *(int *)((int)register0x00000038 + -0xc) = param_2;
  *(undefined4 *)((int)register0x00000038 + -0x14) = param_3;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = param_4;
  if (param_1 == 0) {
    uVar13 = 4;
  }
  else {
    uVar12 = 0;
    uVar11 = 0;
    do {
      do {
        do {
        } while (*(int *)(param_1 + 0x158) != 0);
        piVar1 = (int *)(param_1 + 0x158);
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
      if (*(int *)(param_1 + 0x154) == 0) {
        *(undefined4 *)(param_1 + 0x158) = 0;
        uVar13 = 4;
        goto locret_F00763AC;
      }
      uVar10 = *(uint *)(param_1 + 0x140);
      uVar5 = uVar10 * 4;
      uVar9 = 0;
      if (uVar5 < uVar11 || uVar5 - uVar11 == 0) {
        iVar6 = *(int *)(param_1 + 0x138);
        if (uVar10 != 0) {
          iVar8 = 0;
          do {
            _thread_reference(iVar6);
            *(int *)(iVar8 + uVar12) = iVar6;
            iVar8 = iVar8 + 4;
            uVar9 = uVar9 + 1;
            iVar6 = *(int *)(iVar6 + 0x18);
          } while (uVar9 < uVar10);
        }
        *(undefined4 *)(param_1 + 0x158) = 0;
        iVar6 = 0;
        uVar5 = 0;
        param_2 = 0;
        uVar9 = 0;
        if (uVar10 != 0) {
          iVar8 = 0;
          do {
            iVar7 = *(int *)(iVar8 + uVar12);
            uVar4 = 0;
            if ((*(uint *)(iVar7 + 0x4c) & 0x100) == 0) {
              uVar4 = *(uint *)(iVar7 + 0x2c);
              iVar3 = 0;
              iVar2 = 0;
              do {
                if (*(int *)((int)&_active_threads + iVar2) == iVar7) {
                  uVar4 = *(uint *)((int)&_active_stacks + iVar2);
                  break;
                }
                iVar3 = iVar3 + 1;
                iVar2 = iVar2 + 4;
              } while (iVar3 < 1);
            }
            if (((uVar4 != 0) && (iVar6 = iVar6 + 1, _stack_check_usage != 0)) &&
               (_stack_usage(), uVar5 < uVar4)) {
              uVar5 = uVar4;
              param_2 = iVar7;
            }
            _thread_deallocate(iVar7);
            uVar9 = uVar9 + 1;
            iVar8 = iVar8 + 4;
          } while (uVar9 < uVar10);
        }
        if (uVar11 != 0) {
          _kfree(uVar12,uVar11);
        }
        **(int **)((int)register0x00000038 + -0xc) = iVar6;
        uVar12 = iVar6 * 0x3ff4 + _page_mask & ~_page_mask;
        **(uint **)((int)register0x00000038 + -0x14) = uVar12;
        uVar13 = 0;
        **(uint **)((int)register0x00000038 + -0x1c) = uVar12;
        *param_5 = uVar5;
        *param_6 = param_2;
        goto locret_F00763AC;
      }
      *(undefined4 *)(param_1 + 0x158) = 0;
      if (uVar11 != 0) {
        _kfree(uVar12,uVar11);
      }
      uVar12 = uVar5;
      _kalloc();
      uVar11 = uVar5;
    } while (uVar12 != 0);
    uVar13 = 6;
  }
locret_F00763AC:
  return CONCAT44(param_2,uVar13);
}

