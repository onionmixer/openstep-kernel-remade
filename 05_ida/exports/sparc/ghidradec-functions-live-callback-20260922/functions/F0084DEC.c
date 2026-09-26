
/* WARNING: Removing unreachable block (ram,0xf0084f30) */
/* WARNING: Removing unreachable block (ram,0xf0085068) */
/* WARNING: Removing unreachable block (ram,0xf00850c4) */
/* WARNING: Removing unreachable block (ram,0xf0085080) */
/* WARNING: Removing unreachable block (ram,0xf008501c) */
/* WARNING: Removing unreachable block (ram,0xf0084f8c) */
/* WARNING: Removing unreachable block (ram,0xf0084e3c) */
/* WARNING: Removing unreachable block (ram,0xf0084e64) */
/* WARNING: Removing unreachable block (ram,0xf0084fec) */
/* WARNING: Removing unreachable block (ram,0xf0085078) */
/* WARNING: Removing unreachable block (ram,0xf0085058) */
/* WARNING: Removing unreachable block (ram,0xf00850e8) */
/* WARNING: Removing unreachable block (ram,0xf0084f08) */
/* WARNING: Removing unreachable block (ram,0xf00850fc) */
/* WARNING: Removing unreachable block (ram,0xf0084df4) */

undefined8 _vm_map_pageable(int param_1,uint param_2,uint param_3,int param_4)

{
  uint uVar1;
  sword sVar3;
  uint uVar2;
  undefined4 unaff_l0;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar7;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar8;
  bool bVar9;
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
  _lock_write(param_1);
  *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
  if (param_2 < *(uint *)(param_1 + 0x14)) {
    param_2 = *(uint *)(param_1 + 0x14);
  }
  if (*(uint *)(param_1 + 0x18) < param_3) {
    param_3 = *(uint *)(param_1 + 0x18);
  }
  if (param_3 < param_2) {
    param_2 = param_3;
  }
  iVar6 = param_1;
  _vm_map_lookup_entry(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
  iVar4 = *(int *)((int)register0x00000038 + -0xc);
  if (iVar6 == 0) {
    iVar4 = *(int *)(*(int *)((int)register0x00000038 + -0xc) + 4);
  }
  else if (*(uint *)(iVar4 + 8) < param_2) {
    __vm_map_clip_start(param_1 + 0xc,iVar4,param_2);
  }
  *(int *)((int)register0x00000038 + -0xc) = iVar4;
  if (param_4 == 0) {
    iVar6 = *(int *)((int)register0x00000038 + -0xc);
    if (iVar6 != param_1 + 0xc) {
      param_2 = 0xfdffffff;
      uVar5 = *(uint *)(iVar6 + 8);
      while (uVar5 < param_3) {
        if (param_3 < *(uint *)(iVar6 + 0xc)) {
          __vm_map_clip_end(param_1 + 0xc,iVar6,param_3);
        }
        sVar3 = *(sword *)(iVar6 + 0x28) + 1;
        *(sword *)(iVar6 + 0x28) = sVar3;
        if (sVar3 == 1) {
          if (-1 < (int)*(uint *)(iVar6 + 0x18)) {
            if ((*(uint *)(iVar6 + 0x18) & 0x2000000) == 0) {
              iVar4 = *(int *)(iVar6 + 0x10);
            }
            else {
              if ((*(uint *)(iVar6 + 0x1c) & 2) != 0) {
                _vm_object_shadow(iVar6 + 0x10,iVar6 + 0x14,
                                  *(int *)(iVar6 + 0xc) - *(int *)(iVar6 + 8));
                *(uint *)(iVar6 + 0x18) = *(uint *)(iVar6 + 0x18) & 0xfdffffff;
                goto loc_F008502C;
              }
              iVar4 = *(int *)(iVar6 + 0x10);
            }
            if (iVar4 != 0) {
              iVar6 = *(int *)(iVar6 + 4);
              goto loc_F0085030;
            }
            iVar4 = *(int *)(iVar6 + 0xc) - *(int *)(iVar6 + 8);
            _vm_object_allocate();
            *(int *)(iVar6 + 0x10) = iVar4;
            *(undefined4 *)(iVar6 + 0x14) = 0;
          }
loc_F008502C:
          iVar6 = *(int *)(iVar6 + 4);
        }
        else {
          iVar6 = *(int *)(iVar6 + 4);
        }
loc_F0085030:
        if (iVar6 == param_1 + 0xc) break;
        uVar5 = *(uint *)(iVar6 + 8);
      }
    }
    bVar9 = param_1 != _kernel_map;
    if (bVar9) {
      _lock_set_recursive(param_1);
      _lock_write_to_read(param_1);
      uVar5 = *(uint *)((int)register0x00000038 + -0xc);
    }
    else {
      _lock_done(param_1);
      uVar5 = *(uint *)((int)register0x00000038 + -0xc);
    }
    uVar2 = param_1 + 0xc;
    if (uVar5 != uVar2) {
      uVar1 = *(uint *)(uVar5 + 8);
      while (param_2 = uVar2, uVar1 < param_3) {
        if (*(sword *)(uVar5 + 0x28) == 1) {
          _vm_fault_wire(param_1,uVar5);
          uVar5 = *(uint *)(uVar5 + 4);
        }
        else {
          uVar5 = *(uint *)(uVar5 + 4);
        }
        if (uVar5 == uVar2) break;
        uVar1 = *(uint *)(uVar5 + 8);
      }
    }
    bVar8 = !bVar9;
    if (!bVar8) {
      _lock_clear_recursive(param_1);
      bVar8 = !bVar9;
    }
  }
  else {
    if (iVar4 == param_1 + 0xc) {
      uVar5 = *(uint *)((int)register0x00000038 + -0xc);
    }
    else {
      uVar5 = *(uint *)(iVar4 + 8);
      while (uVar5 < param_3) {
        if (*(sword *)(iVar4 + 0x28) == 0) {
          _lock_done(param_1);
          uVar7 = 4;
          goto locret_F0085108;
        }
        iVar4 = *(int *)(iVar4 + 4);
        if (iVar4 == param_1 + 0xc) {
          uVar5 = *(uint *)((int)register0x00000038 + -0xc);
          goto loc_F0084ED4;
        }
        uVar5 = *(uint *)(iVar4 + 8);
      }
      uVar5 = *(uint *)((int)register0x00000038 + -0xc);
    }
loc_F0084ED4:
    uVar2 = param_1 + 0xc;
    bVar8 = false;
    if (uVar5 != uVar2) {
      uVar1 = *(uint *)(uVar5 + 8);
      while (bVar8 = false, param_2 = uVar2, uVar1 < param_3) {
        if (param_3 < *(uint *)(uVar5 + 0xc)) {
          __vm_map_clip_end(param_1 + 0xc,uVar5,param_3);
        }
        sVar3 = *(sword *)(uVar5 + 0x28);
        *(sword *)(uVar5 + 0x28) = sVar3 + -1;
        if (sVar3 == 1) {
          _vm_fault_unwire(param_1,uVar5);
          uVar5 = *(uint *)(uVar5 + 4);
        }
        else {
          uVar5 = *(uint *)(uVar5 + 4);
        }
        bVar8 = false;
        if (uVar5 == uVar2) break;
        uVar1 = *(uint *)(uVar5 + 8);
      }
    }
  }
  if (bVar8) {
    uVar7 = 0;
  }
  else {
    _lock_done(param_1);
    uVar7 = 0;
  }
locret_F0085108:
  return CONCAT44(param_2,uVar7);
}

