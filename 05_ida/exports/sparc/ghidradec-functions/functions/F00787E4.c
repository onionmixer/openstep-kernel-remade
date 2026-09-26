
/* WARNING: Removing unreachable block (ram,0xf0078974) */
/* WARNING: Removing unreachable block (ram,0xf0078828) */
/* WARNING: Removing unreachable block (ram,0xf0078878) */
/* WARNING: Removing unreachable block (ram,0xf00789b4) */
/* WARNING: Removing unreachable block (ram,0xf00789e0) */
/* WARNING: Removing unreachable block (ram,0xf0078998) */
/* WARNING: Removing unreachable block (ram,0xf007885c) */

undefined8 _zget_space(undefined *param_1,uint param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  uint uVar8;
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
  uVar7 = 0;
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
  if ((uint *)param_1 == (uint *)0x0) {
    param_1 = __zone_default_space;
  }
  if (param_2 < 0x11) {
    uVar8 = 0x10;
  }
  else {
    uVar8 = param_2 + 0xf & 0xfffffff0;
  }
  do {
    do {
    } while (_zget_space_lock != 0);
    puVar1 = &_zget_space_lock;
    _simple_lock_try();
  } while (puVar1 == (undefined4 *)0x0);
  do {
    puVar2 = (uint *)param_1;
    sub_F0077DDC(param_1,uVar8);
    if (puVar2 != (uint *)0x0) {
      puVar4 = (uint *)puVar2[2];
      if (puVar2[1] - uVar8 < 0x10) {
        uVar3 = *puVar2;
        *puVar4 = uVar3;
        if (uVar3 != 0) {
          *(uint **)(*puVar2 + 8) = puVar4;
        }
        *(uint *)((int)param_1 + 0xc) = *(uint *)((int)param_1 + 0xc) - 1;
        param_1 = (undefined *)puVar2;
      }
      else {
        uVar6 = (int)puVar2 + uVar8;
        *(uint *)(uVar6 + 4) = puVar2[1] - uVar8;
        uVar3 = *puVar2;
        *(uint *)((int)puVar2 + uVar8) = uVar3;
        if (uVar3 != 0) {
          *(uint *)(uVar3 + 8) = uVar6;
        }
        *(uint **)(uVar6 + 8) = puVar4;
        *puVar4 = uVar6;
        uVar3 = *(uint *)(uVar6 + 4) >> ((byte)*(uint *)((int)param_1 + 0x10) & 0x1f);
        if ((int)*(uint *)((int)param_1 + 0x18) < (int)uVar3) {
          uVar3 = *(uint *)((int)param_1 + 0x18);
        }
        iVar5 = *(uint *)((int)param_1 + 0x14) + uVar3 * 0x10;
        uVar3 = *(uint *)(iVar5 + -0x10);
        if ((uVar3 == 0) || (param_1 = (undefined *)puVar2, uVar6 < uVar3)) {
          *(uint *)(iVar5 + -0x10) = uVar6;
          param_1 = (undefined *)puVar2;
        }
      }
loc_F00789C8:
      _zget_space_lock = 0;
      if (*(int *)((int)register0x00000038 + -0xc) != 0) {
        _kmem_free(_zone_map,*(int *)((int)register0x00000038 + -0xc),uVar7);
      }
locret_F00789E8:
      return CONCAT44(uVar8,param_1);
    }
    if (*(int *)((int)register0x00000038 + -0xc) != 0) {
      _zone_free_space_add(param_1,uVar8,*(int *)((int)register0x00000038 + -0xc),uVar7);
      *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
      goto loc_F00789C8;
    }
    uVar7 = uVar8 + _page_mask & ~_page_mask;
    uVar3 = _zdata_size - uVar7;
    if (uVar7 <= _zdata_size) {
      _zdata_size = uVar3;
      _zone_free_space_add(param_1,uVar8,_zdata + uVar3,uVar7);
      goto loc_F00789C8;
    }
    _zget_space_lock = 0;
    iVar5 = _zone_map;
    _kmem_alloc_zone(_zone_map,(undefined *)((int)register0x00000038 + -0xc),uVar7,param_3);
    if (iVar5 != 0) {
      param_1 = (undefined *)0x0;
      goto locret_F00789E8;
    }
    do {
      do {
      } while (_zget_space_lock != 0);
      puVar1 = &_zget_space_lock;
      _simple_lock_try();
    } while (puVar1 == (undefined4 *)0x0);
  } while( true );
}
