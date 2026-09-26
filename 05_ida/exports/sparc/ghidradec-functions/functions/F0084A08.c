
/* WARNING: Removing unreachable block (ram,0xf0084ca8) */
/* WARNING: Removing unreachable block (ram,0xf0084c50) */
/* WARNING: Removing unreachable block (ram,0xf0084b98) */
/* WARNING: Removing unreachable block (ram,0xf0084a98) */
/* WARNING: Removing unreachable block (ram,0xf0084a78) */
/* WARNING: Removing unreachable block (ram,0xf0084a54) */
/* WARNING: Removing unreachable block (ram,0xf0084a88) */
/* WARNING: Removing unreachable block (ram,0xf0084b50) */
/* WARNING: Removing unreachable block (ram,0xf0084bb8) */
/* WARNING: Removing unreachable block (ram,0xf0084c74) */
/* WARNING: Removing unreachable block (ram,0xf0084cc4) */
/* WARNING: Removing unreachable block (ram,0xf0084a0c) */

undefined8 _vm_map_protect(int param_1,uint param_2,uint param_3,uint param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar8;
  undefined4 unaff_i1;
  int iVar9;
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
  iVar9 = param_1;
  _vm_map_lookup_entry(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar9 == 0) {
    *(undefined4 *)((int)register0x00000038 + -0xc) =
         *(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 4);
  }
  else if (*(uint *)(*(int *)((int)register0x00000038 + -0xc) + 8) < param_2) {
    __vm_map_clip_start(param_1 + 0xc,*(int *)((int)register0x00000038 + -0xc),param_2);
    iVar9 = *(int *)((int)register0x00000038 + -0xc);
    goto loc_F0084AB8;
  }
  iVar9 = *(int *)((int)register0x00000038 + -0xc);
loc_F0084AB8:
  if (iVar9 == param_1 + 0xc) {
    iVar9 = *(int *)((int)register0x00000038 + -0xc);
  }
  else {
    uVar1 = *(uint *)(iVar9 + 8);
    while (uVar1 < param_3) {
      if ((*(uint *)(iVar9 + 0x18) & 0x20000000) != 0) {
        _lock_done(param_1);
        uVar8 = 4;
        goto locret_F0084CD0;
      }
      if ((param_4 & *(uint *)(iVar9 + 0x20)) != param_4) {
        _lock_done(param_1);
        uVar8 = 2;
        goto locret_F0084CD0;
      }
      iVar9 = *(int *)(iVar9 + 4);
      if (iVar9 == param_1 + 0xc) {
        iVar9 = *(int *)((int)register0x00000038 + -0xc);
        goto loc_F0084B1C;
      }
      uVar1 = *(uint *)(iVar9 + 8);
    }
    iVar9 = *(int *)((int)register0x00000038 + -0xc);
  }
loc_F0084B1C:
  if (iVar9 != param_1 + 0xc) {
    uVar1 = *(uint *)(iVar9 + 8);
    while (uVar1 < param_3) {
      if (param_3 < *(uint *)(iVar9 + 0xc)) {
        __vm_map_clip_end(param_1 + 0xc,iVar9,param_3);
      }
      uVar1 = *(uint *)(iVar9 + 0x1c);
      if (param_5 == 0) {
        *(uint *)(iVar9 + 0x1c) = param_4;
      }
      else {
        *(uint *)(iVar9 + 0x20) = param_4;
        *(uint *)(iVar9 + 0x1c) = param_4 & uVar1;
      }
      uVar3 = *(uint *)(iVar9 + 0x1c);
      if (uVar3 == uVar1) {
        iVar9 = *(int *)(iVar9 + 4);
      }
      else if (*(int *)(iVar9 + 0x18) < 0) {
        _lock_write(*(undefined4 *)(iVar9 + 0x10));
        *(int *)(*(int *)(iVar9 + 0x10) + 0x4c) = *(int *)(*(int *)(iVar9 + 0x10) + 0x4c) + 1;
        _vm_map_lookup_entry
                  (*(undefined4 *)(iVar9 + 0x10),*(undefined4 *)(iVar9 + 0x14),
                   (undefined *)((int)register0x00000038 + -0x10));
        uVar1 = *(int *)(iVar9 + 0x14) + (*(int *)(iVar9 + 0xc) - *(int *)(iVar9 + 8));
        if (*(int *)((int)register0x00000038 + -0x10) != *(int *)(iVar9 + 0x10) + 0xc) {
          do {
            iVar7 = *(int *)((int)register0x00000038 + -0x10);
            uVar3 = *(uint *)(iVar7 + 8);
            if (uVar1 <= uVar3) break;
            uVar6 = *(uint *)(iVar9 + 0x14);
            if (uVar3 < uVar6) {
              uVar3 = uVar6;
            }
            uVar4 = *(uint *)(iVar7 + 0xc);
            if (*(uint *)(iVar7 + 0xc) < uVar1) {
              uVar4 = uVar1;
            }
            if ((*(uint *)(iVar7 + 0x18) & 0x10000000) == 0) {
              uVar5 = *(uint *)(iVar9 + 0x1c) & 7;
            }
            else {
              uVar5 = *(uint *)(iVar9 + 0x1c) & 0xfffffffd;
            }
            _pmap_protect(*(undefined4 *)(param_1 + 0x24),(uVar3 - uVar6) + *(int *)(iVar9 + 8),
                          (uVar4 - uVar6) + *(int *)(iVar9 + 8),uVar5);
            iVar2 = *(int *)(*(int *)((int)register0x00000038 + -0x10) + 4);
            iVar7 = *(int *)(iVar9 + 0x10);
            *(int *)((int)register0x00000038 + -0x10) = iVar2;
          } while (iVar2 != iVar7 + 0xc);
        }
        _lock_done(*(undefined4 *)(iVar9 + 0x10));
        iVar9 = *(int *)(iVar9 + 4);
      }
      else {
        if ((*(uint *)(*(int *)((int)register0x00000038 + -0xc) + 0x18) & 0x10000000) == 0) {
          uVar3 = uVar3 & 7;
        }
        else {
          uVar3 = uVar3 & 0xfffffffd;
        }
        _pmap_protect(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(iVar9 + 8),
                      *(undefined4 *)(iVar9 + 0xc),uVar3);
        iVar9 = *(int *)(iVar9 + 4);
      }
      if (iVar9 == param_1 + 0xc) break;
      uVar1 = *(uint *)(iVar9 + 8);
    }
  }
  _lock_done(param_1);
  uVar8 = 0;
locret_F0084CD0:
  return CONCAT44(iVar9,uVar8);
}
