
/* WARNING: Removing unreachable block (ram,0xf006c804) */
/* WARNING: Removing unreachable block (ram,0xf006c7c8) */
/* WARNING: Removing unreachable block (ram,0xf006c764) */
/* WARNING: Removing unreachable block (ram,0xf006c784) */
/* WARNING: Removing unreachable block (ram,0xf006c7e0) */
/* WARNING: Removing unreachable block (ram,0xf006c818) */
/* WARNING: Removing unreachable block (ram,0xf006c71c) */

undefined8 _mfs_trunc(int *param_1,uint param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
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
  iVar2 = *param_1;
  if ((*(uint *)(iVar2 + 0x38) & 0x8000000) == 0) {
    *(uint *)(iVar2 + 0x14) = param_2;
    uVar6 = 0;
  }
  else {
    _vmp_get(iVar2);
    uVar3 = param_2 + _page_mask & ~_page_mask;
    uVar5 = 0;
    if (*(uint *)(iVar2 + 0x10) <= uVar3) {
      uVar5 = uVar3 - *(uint *)(iVar2 + 0x10);
    }
    if (uVar5 < *(uint *)(iVar2 + 0xc)) {
      _mfs_map_remove(iVar2,*(int *)(iVar2 + 8) + uVar5,*(int *)(iVar2 + 8) + *(uint *)(iVar2 + 0xc)
                      ,0);
      *(uint *)(iVar2 + 0xc) = uVar5;
    }
    if (uVar3 < *(uint *)(iVar2 + 0x14)) {
      _vno_flush(param_1,uVar3,*(uint *)(iVar2 + 0x14) - uVar3);
    }
    *(uint *)(iVar2 + 0x14) = param_2;
    if (param_2 != uVar3) {
      iVar4 = uVar3 - param_2;
      if ((param_2 < *(uint *)(iVar2 + 0x10)) ||
         (*(uint *)(iVar2 + 0x10) + *(int *)(iVar2 + 0xc) < param_2 + iVar4)) {
        _remap_vnode(param_1,param_2,iVar4);
        iVar1 = *(int *)(iVar2 + 8);
      }
      else {
        iVar1 = *(int *)(iVar2 + 8);
      }
      _bzero((iVar1 + param_2) - *(int *)(iVar2 + 0x10),iVar4);
      *(sword *)(iVar2 + 4) = *(sword *)(iVar2 + 4) + 1;
      *(uint *)(iVar2 + 0x38) = *(uint *)(iVar2 + 0x38) | 0x40000000;
      _vmp_push(iVar2);
      *(sword *)(iVar2 + 4) = *(sword *)(iVar2 + 4) + -1;
    }
    _vmp_put(iVar2);
    uVar6 = 1;
  }
  return CONCAT44(param_2,uVar6);
}
