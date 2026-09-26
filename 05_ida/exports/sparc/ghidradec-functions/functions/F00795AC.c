
/* WARNING: Removing unreachable block (ram,0xf00798e8) */
/* WARNING: Removing unreachable block (ram,0xf0079880) */
/* WARNING: Removing unreachable block (ram,0xf00797a4) */
/* WARNING: Removing unreachable block (ram,0xf0079778) */
/* WARNING: Removing unreachable block (ram,0xf0079718) */
/* WARNING: Removing unreachable block (ram,0xf0079728) */
/* WARNING: Removing unreachable block (ram,0xf00796b0) */
/* WARNING: Removing unreachable block (ram,0xf0079658) */
/* WARNING: Removing unreachable block (ram,0xf00796d8) */
/* WARNING: Removing unreachable block (ram,0xf0079744) */
/* WARNING: Removing unreachable block (ram,0xf0079760) */
/* WARNING: Removing unreachable block (ram,0xf007978c) */
/* WARNING: Removing unreachable block (ram,0xf00797c8) */
/* WARNING: Removing unreachable block (ram,0xf00798a4) */
/* WARNING: Removing unreachable block (ram,0xf007990c) */
/* WARNING: Removing unreachable block (ram,0xf00795f0) */

undefined8
_host_zone_info(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 unaff_l0;
  int *piVar6;
  undefined4 unaff_l1;
  int *piVar7;
  undefined4 unaff_l3;
  uint uVar8;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  uint uVar9;
  undefined4 unaff_l6;
  int iVar10;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar11;
  undefined4 unaff_i1;
  int *piVar12;
  undefined4 unaff_i2;
  uint uVar13;
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
  *(undefined4 *)((int)register0x00000038 + -0x5c) = param_3;
  *(undefined4 *)((int)register0x00000038 + -100) = param_4;
  *(undefined4 *)((int)register0x00000038 + -0x6c) = param_5;
  uVar9 = 0;
  uVar13 = 0;
  if (param_1 == 0) {
    iVar11 = 0x16;
  }
  else {
    do {
      do {
      } while (_all_zones_lock != 0);
      puVar5 = &_all_zones_lock;
      _simple_lock_try();
      uVar1 = _num_zones;
      piVar6 = _first_zone;
    } while (puVar5 == (undefined4 *)0x0);
    _all_zones_lock = 0;
    if (**(uint **)((int)register0x00000038 + -0x5c) < _num_zones) {
      uVar9 = _num_zones * 0x50 + _page_mask & ~_page_mask;
      iVar11 = _ipc_kernel_map;
      _kmem_alloc_pageable(_ipc_kernel_map,(undefined *)((int)register0x00000038 + -0xc),uVar9);
      iVar10 = *(int *)((int)register0x00000038 + -0xc);
      if (iVar11 != 0) goto locret_F007992C;
    }
    else {
      iVar10 = *param_2;
    }
    if (**(uint **)((int)register0x00000038 + -0x6c) < uVar1) {
      uVar13 = uVar1 * 0x24 + _page_mask & ~_page_mask;
      iVar11 = _ipc_kernel_map;
      _kmem_alloc_pageable(_ipc_kernel_map,(undefined *)((int)register0x00000038 + -0x10),uVar13);
      piVar12 = *(int **)((int)register0x00000038 + -0x10);
      if (iVar11 != 0) {
        iVar2 = *param_2;
        param_2 = piVar12;
        if (iVar10 != iVar2) {
          _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),uVar9);
        }
        goto locret_F007992C;
      }
    }
    else {
      piVar12 = (int *)**(undefined4 **)((int)register0x00000038 + -100);
    }
    uVar8 = 0;
    piVar7 = piVar12;
    iVar11 = iVar10;
    if (uVar1 != 0) {
      do {
        uVar3 = piVar6[0xb];
        if ((uVar3 & 0x80000000) == 0) {
          _splusclock();
          do {
            do {
            } while (*piVar6 != 0);
            piVar4 = piVar6;
            _simple_lock_try();
          } while (piVar4 == (int *)0x0);
          piVar6[1] = uVar3;
        }
        else {
          _lock_write(piVar6 + 0xc);
        }
        _memcpy((undefined *)((int)register0x00000038 + -0x58),piVar6,0x44);
        if ((piVar6[0xb] & 0x80000000U) == 0) {
          *piVar6 = 0;
          _splx(piVar6[1]);
        }
        else {
          _lock_done(piVar6 + 0xc);
        }
        do {
          do {
          } while (_all_zones_lock != 0);
          puVar5 = &_all_zones_lock;
          _simple_lock_try();
        } while (puVar5 == (undefined4 *)0x0);
        piVar6 = (int *)piVar6[0x10];
        _all_zones_lock = 0;
        _strncpy(iVar11,*(undefined4 *)((int)register0x00000038 + -0x30),0x50);
        *piVar7 = *(int *)((int)register0x00000038 + -0x50);
        piVar7[1] = *(int *)((int)register0x00000038 + -0x44);
        piVar7[2] = *(int *)((int)register0x00000038 + -0x40);
        piVar7[3] = *(int *)((int)register0x00000038 + -0x3c);
        piVar7[4] = *(int *)((int)register0x00000038 + -0x38);
        piVar7[5] = *(uint *)((int)register0x00000038 + -0x2c) >> 0x1f;
        piVar7[6] = *(uint *)((int)register0x00000038 + -0x2c) >> 0x1e & 1;
        piVar7[7] = *(uint *)((int)register0x00000038 + -0x2c) >> 0x1d & 1;
        uVar3 = 0;
        if (*(undefined **)((int)register0x00000038 + -0x1c) != (undefined *)0x0) {
          uVar3 = (uint)(*(undefined **)((int)register0x00000038 + -0x1c) != __zone_default_space);
        }
        piVar7[8] = uVar3;
        uVar8 = uVar8 + 1;
        piVar7 = piVar7 + 9;
        iVar11 = iVar11 + 0x50;
      } while (uVar8 < uVar1);
    }
    if (iVar10 != *param_2) {
      if (uVar1 * 0x50 - uVar9 != 0) {
        _bzero(*(int *)((int)register0x00000038 + -0xc) + uVar1 * 0x50,uVar9 + uVar1 * -0x50);
      }
      _vm_move(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),_ipc_soft_map,uVar9,1
               ,(undefined *)((int)register0x00000038 + -0xc));
      *param_2 = *(int *)((int)register0x00000038 + -0xc);
    }
    **(uint **)((int)register0x00000038 + -0x5c) = uVar1;
    if (piVar12 != (int *)**(undefined4 **)((int)register0x00000038 + -100)) {
      if (uVar1 * 0x24 - uVar13 != 0) {
        _bzero(*(int *)((int)register0x00000038 + -0x10) + uVar1 * 0x24,uVar13 + uVar1 * -0x24);
      }
      _vm_move(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0x10),_ipc_soft_map,uVar13
               ,1,(undefined *)((int)register0x00000038 + -0x10));
      **(undefined4 **)((int)register0x00000038 + -100) =
           *(undefined4 *)((int)register0x00000038 + -0x10);
    }
    iVar11 = 0;
    **(uint **)((int)register0x00000038 + -0x6c) = uVar1;
    param_2 = piVar12;
  }
locret_F007992C:
  return CONCAT44(param_2,iVar11);
}
