/* GHIDRADEC_FUNCTION index=1800 start=0xf00860a0 */

/* WARNING: Removing unreachable block (ram,0xf00860f4) */
/* WARNING: Removing unreachable block (ram,0xf0086100) */
/* WARNING: Removing unreachable block (ram,0xf00860d0) */

undefined8
_vm_map_machine_attribute
          (int param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  if ((param_2 < *(uint *)(param_1 + 0x14)) || (*(uint *)(param_1 + 0x18) < param_2 + param_3)) {
    uVar1 = 4;
  }
  else {
    _lock_write(param_1);
    *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
    uVar1 = *(undefined4 *)(param_1 + 0x24);
    _pmap_attribute(uVar1,param_2,param_3,param_4,param_5);
    _lock_done(param_1);
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=1801 start=0xf0086110 */

/* WARNING: Removing unreachable block (ram,0xf0086230) */
/* WARNING: Removing unreachable block (ram,0xf00861d0) */
/* WARNING: Removing unreachable block (ram,0xf0086254) */
/* WARNING: Removing unreachable block (ram,0xf0086144) */
/* WARNING: Removing unreachable block (ram,0xf0086170) */
/* WARNING: Removing unreachable block (ram,0xf00861c0) */
/* WARNING: Removing unreachable block (ram,0xf00861f8) */
/* WARNING: Removing unreachable block (ram,0xf0086264) */
/* WARNING: Removing unreachable block (ram,0xf0086134) */

undefined8
_vm_region(int param_1,int *param_2,uint *param_3,undefined4 *param_4,undefined4 *param_5,
          undefined4 *param_6)

{
  uint uVar1;
  undefined4 unaff_l0;
  int iVar2;
  int iVar3;
  undefined4 unaff_l1;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 unaff_l3;
  uint *puVar6;
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
  puVar6 = *(uint **)((int)register0x00000038 + 0x5c);
  puVar4 = *(undefined4 **)((int)register0x00000038 + 0x60);
  piVar5 = *(int **)((int)register0x00000038 + 100);
  if (param_1 == 0) {
    uVar7 = 4;
  }
  else {
    iVar2 = *param_2;
    _lock_read(param_1);
    iVar3 = param_1;
    _vm_map_lookup_entry(param_1,iVar2,(undefined *)((int)register0x00000038 + -0xc));
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
    if (iVar3 == 0) {
      iVar2 = *(int *)(*(int *)((int)register0x00000038 + -0xc) + 4);
      if (iVar2 == param_1 + 0xc) {
        _lock_done(param_1);
        uVar7 = 3;
        goto locret_F0086270;
      }
      uVar7 = *(undefined4 *)(iVar2 + 0x1c);
    }
    else {
      uVar7 = *(undefined4 *)(iVar2 + 0x1c);
    }
    iVar3 = *(int *)(iVar2 + 8);
    *param_4 = uVar7;
    *param_5 = *(undefined4 *)(iVar2 + 0x20);
    *param_6 = *(undefined4 *)(iVar2 + 0x24);
    *param_2 = iVar3;
    *param_3 = *(int *)(iVar2 + 0xc) - iVar3;
    uVar1 = *(uint *)(iVar2 + 0x18);
    param_2 = *(int **)(iVar2 + 0x14);
    if ((int)uVar1 < 0) {
      iVar3 = *(int *)(iVar2 + 0x10);
      _lock_read(iVar3);
      _vm_map_lookup_entry(iVar3,param_2,(undefined *)((int)register0x00000038 + -0xc));
      if ((uint)(*(int *)(*(int *)((int)register0x00000038 + -0xc) + 0xc) - (int)param_2) < *param_3
         ) {
        *param_3 = *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0xc) - (int)param_2;
      }
      uVar7 = *(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0x10);
      _vm_object_name();
      *puVar4 = uVar7;
      *piVar5 = (int)param_2 +
                (*(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x14) -
                *(int *)(*(int *)((int)register0x00000038 + -0xc) + 8));
      *puVar6 = (uint)(*(int *)(iVar3 + 0x30) != 1);
      _lock_done(iVar3);
    }
    else {
      *puVar6 = 0;
      if ((uVar1 & 0x20000000) == 0) {
        uVar7 = *(undefined4 *)(iVar2 + 0x10);
        _vm_object_name();
        *puVar4 = uVar7;
      }
      else {
        *puVar4 = 0;
      }
      *piVar5 = (int)param_2;
    }
    _lock_done(param_1);
    uVar7 = 0;
  }
locret_F0086270:
  return CONCAT44(param_2,uVar7);
}
/* GHIDRADEC_FUNCTION index=1802 start=0xf0086278 */

/* WARNING: Removing unreachable block (ram,0xf00862ec) */
/* WARNING: Removing unreachable block (ram,0xf0086318) */
/* WARNING: Removing unreachable block (ram,0xf00862c4) */

undefined8
_vm_move(undefined4 param_1,uint param_2,int param_3,int param_4,undefined4 param_5,int *param_6)

{
  undefined4 unaff_l0;
  uint uVar1;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  int iVar3;
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
  if (param_4 == 0) {
    *param_6 = 0;
    iVar2 = 0;
  }
  else {
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
    uVar1 = param_2 & ~_page_mask;
    iVar3 = (param_2 + param_4 + _page_mask & ~_page_mask) - uVar1;
    iVar2 = param_3;
    _vm_allocate(param_3,(undefined *)((int)register0x00000038 + -0xc),iVar3,1);
    if (iVar2 == 0) {
      iVar2 = param_3;
      _vm_map_copy(param_3,param_1,*(undefined4 *)((int)register0x00000038 + -0xc),iVar3,uVar1,0,
                   param_5);
      if (iVar2 == 0) {
        *param_6 = *(int *)((int)register0x00000038 + -0xc) + (param_2 - uVar1);
      }
      else {
        _vm_deallocate(param_3,*(undefined4 *)((int)register0x00000038 + -0xc),iVar3);
      }
    }
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=1803 start=0xf0086328 */

undefined8 _vm_map_pmap_EXTERNAL(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x24));
}
/* GHIDRADEC_FUNCTION index=1804 start=0xf0086338 */

/* WARNING: Removing unreachable block (ram,0xf00863c0) */

undefined8 _vm_mem_ppi(uint param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  puVar3 = _mem_region;
  iVar4 = 0;
  if (_mem_region < _mem_region + _num_regions * 0x1c) {
    piVar2 = (int *)(_mem_region + 0xc);
    do {
      puVar3 = puVar3 + 0x1c;
      if (param_1 < (uint)piVar2[2]) {
        iVar1 = *piVar2;
      }
      else {
        if (param_1 < (uint)piVar2[3]) {
          param_1 = iVar4 + (param_1 - piVar2[2] >> ((byte)_page_shift & 0x1f));
          goto locret_F00863C8;
        }
        iVar1 = *piVar2;
      }
      iVar4 = iVar4 + iVar1;
      piVar2 = piVar2 + 7;
    } while (puVar3 < _mem_region + _num_regions * 0x1c);
  }
  _panic(&aMemPpi);
locret_F00863C8:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1805 start=0xf00863d0 */

undefined8 _vm_valid_page(uint param_1)

{
  uint *puVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar2;
  undefined4 uVar3;
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
  puVar2 = _mem_region;
  if (_mem_region < _mem_region + _num_regions * 0x1c) {
    puVar1 = (uint *)(_mem_region + 0x18);
    do {
      puVar2 = puVar2 + 0x1c;
      if ((puVar1[-1] <= param_1) && (param_1 < *puVar1)) {
        uVar3 = 1;
        goto locret_F0086444;
      }
      puVar1 = puVar1 + 7;
    } while (puVar2 < _mem_region + _num_regions * 0x1c);
    uVar3 = 0;
  }
  else {
    uVar3 = 0;
  }
locret_F0086444:
  return CONCAT44(param_1,uVar3);
}
/* GHIDRADEC_FUNCTION index=1806 start=0xf008644c */

undefined8 _vm_phys_to_vm_page(uint param_1)

{
  int *piVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
  undefined4 unaff_i1;
  undefined *puVar3;
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
  puVar3 = _mem_region;
  iVar2 = 0;
  if (_mem_region < _mem_region + _num_regions * 0x1c) {
    piVar1 = (int *)(_mem_region + 4);
    do {
      if (((uint)piVar1[4] <= param_1) && (param_1 < (uint)piVar1[5])) {
        iVar2 = *(int *)puVar3 + ((param_1 >> ((byte)_page_shift & 0x1f)) - *piVar1) * 0x30;
        goto locret_F00864E4;
      }
      puVar3 = (undefined *)((int)puVar3 + 0x1c);
      piVar1 = piVar1 + 7;
    } while (puVar3 < _mem_region + _num_regions * 0x1c);
    iVar2 = 0;
  }
locret_F00864E4:
  return CONCAT44(puVar3,iVar2);
}
/* GHIDRADEC_FUNCTION index=1807 start=0xf00864ec */

/* WARNING: Removing unreachable block (ram,0xf00864f0) */

undefined8 _vm_region_to_vm_page(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  _vm_phys_to_vm_page(param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1808 start=0xf0086500 */

/* WARNING: Removing unreachable block (ram,0xf00865a8) */
/* WARNING: Removing unreachable block (ram,0xf00865ec) */
/* WARNING: Removing unreachable block (ram,0xf0086518) */

undefined8 _vm_alloc_from_regions(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  undefined *puVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  if (_pmap_initialized != 0) {
    _panic(aVmMemAllocFrom);
  }
  puVar4 = _mem_region;
  if (_mem_region < _mem_region + _num_regions * 0x1c) {
    puVar3 = (uint *)(_mem_region + 0x14);
    do {
      uVar1 = (*puVar3 - 1) + param_2 & -param_2;
      uVar2 = uVar1 + param_1;
      if (uVar2 <= puVar3[1]) {
        *puVar3 = uVar2;
        _econtig = _econtig + -1 + param_2 & -param_2;
        _pmap_map(_econtig,uVar1,0,param_1,3,1);
        _virtual_avail = _econtig + param_1;
        param_1 = _econtig;
        _econtig = _virtual_avail;
        goto locret_F00865F4;
      }
      puVar4 = puVar4 + 0x1c;
      puVar3 = puVar3 + 7;
    } while (puVar4 < _mem_region + _num_regions * 0x1c);
  }
  _panic(aVmMemAllocFrom_0);
locret_F00865F4:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1809 start=0xf00865fc */

/* WARNING: Removing unreachable block (ram,0xf0086778) */
/* WARNING: Removing unreachable block (ram,0xf0086648) */
/* WARNING: Removing unreachable block (ram,0xf0086790) */
/* WARNING: Removing unreachable block (ram,0xf0086624) */

undefined8 _vm_object_init(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  uVar1 = 0x58;
  _zinit(0x58,_page_mask + 0x80000 & ~_page_mask,0,0,&aObjects);
  uVar2 = 0xc;
  _vm_object_zone = uVar1;
  _zinit(0xc,0x19000,0,0,aObjectHashZone);
  unk_F013D41C = &_vm_object_cached_list;
  _vm_object_cached_list = &_vm_object_cached_list;
  dword_F013D834 = &_vm_object_list;
  _vm_object_list = &_vm_object_list;
  _vm_object_count = 0;
  _vm_cache_lock = 0;
  _vm_object_list_lock = 0;
  iVar4 = 0;
  puVar3 = _vm_object_hashtable;
  _object_hash_zone = uVar2;
  do {
    *(undefined **)(puVar3 + 4) = puVar3;
    *(undefined **)puVar3 = puVar3;
    iVar4 = iVar4 + 1;
    puVar3 = puVar3 + 8;
  } while (iVar4 < 0x80);
  _vm_cache_max = (_mem_size >> 0x14) * 0x32;
  if (0x9c4 < _vm_cache_max) {
    _vm_cache_max = 0x9c4;
  }
  DAT_f013d858._0_2_ = 1;
  DAT_f013d858._2_2_ = 0;
  DAT_f013d854._0_4_ = 0;
  DAT_f013d858._4_4_ = 0;
  DAT_f013d858._16_4_ = 0;
  DAT_f013d858._24_4_ = 0;
  DAT_f013d858._28_4_ = 0;
  DAT_f013d858._20_4_ = 0;
  DAT_f013d858._8_4_ = 0;
  DAT_f013d858._12_4_ = 0;
  DAT_f013d858._60_4_ = 0;
  _kernel_object = _kernel_object_store;
  DAT_f013d858._50_2_ = (word)DAT_f013d858._48_4_ & 0x7fff;
  DAT_f013d858._48_2_ = 2;
  DAT_f013d858._44_4_ = DAT_f013d858._44_4_ & 0xcfff | 0x800;
  __vm_object_allocate(0xf000000);
  _vm_submap_object = _vm_submap_object_store;
  __vm_object_allocate(0xf000000);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1810 start=0xf00867a0 */

/* WARNING: Removing unreachable block (ram,0xf00867b8) */
/* WARNING: Removing unreachable block (ram,0xf00867a8) */

undefined8 _vm_object_allocate(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  uVar1 = _vm_object_zone;
  _zalloc(_vm_object_zone);
  __vm_object_allocate(param_1,uVar1);
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=1811 start=0xf00867c8 */

/* WARNING: Removing unreachable block (ram,0xf0086808) */
/* WARNING: Removing unreachable block (ram,0xf00867d8) */

undefined8 __vm_object_allocate(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  _memcpy(param_2,_vm_object_template,0x58);
  *(int *)(param_2 + 4) = param_2;
  *(int *)param_2 = param_2;
  *(undefined4 *)(param_2 + 0x10) = 0;
  *(undefined4 *)(param_2 + 0x14) = param_1;
  do {
    do {
    } while (_vm_object_list_lock != 0);
    puVar2 = &_vm_object_list_lock;
    _simple_lock_try();
  } while (puVar2 == (undefined4 *)0x0);
  iVar1 = param_2;
  if (dword_F013D834 != &_vm_object_list) {
    dword_F013D834[2] = param_2;
    iVar1 = _vm_object_list;
  }
  _vm_object_list = iVar1;
  *(undefined4 **)(param_2 + 0xc) = dword_F013D834;
  *(int **)(param_2 + 8) = &_vm_object_list;
  dword_F013D834 = (undefined4 *)param_2;
  _vm_object_list_lock = 0;
  _vm_object_count = _vm_object_count + 1;
  return CONCAT44(param_2,&_vm_object_list_lock);
}
/* GHIDRADEC_FUNCTION index=1812 start=0xf008686c */

/* WARNING: Removing unreachable block (ram,0xf008688c) */

undefined8 _vm_object_reference(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  if (param_1 != 0) {
    do {
      do {
      } while (*(int *)(param_1 + 0x10) != 0);
      piVar1 = (int *)(param_1 + 0x10);
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(sword *)(param_1 + 0x18) = *(sword *)(param_1 + 0x18) + 1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1813 start=0xf00868b8 */

/* WARNING: Removing unreachable block (ram,0xf00869bc) */
/* WARNING: Removing unreachable block (ram,0xf00869a4) */
/* WARNING: Removing unreachable block (ram,0xf0086918) */
/* WARNING: Removing unreachable block (ram,0xf00869cc) */
/* WARNING: Removing unreachable block (ram,0xf00868f4) */

undefined8 _vm_object_deallocate(int param_1,undefined4 param_2)

{
  sword sVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
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
  do {
    if (param_1 == 0) {
locret_F00869E0:
      return CONCAT44(param_2,param_1);
    }
    do {
      do {
      } while (_vm_cache_lock != 0);
      puVar2 = &_vm_cache_lock;
      _simple_lock_try();
    } while (puVar2 == (undefined4 *)0x0);
    do {
      do {
      } while (*(int *)(param_1 + 0x10) != 0);
      piVar3 = (int *)(param_1 + 0x10);
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
    sVar1 = *(sword *)(param_1 + 0x18);
    *(sword *)(param_1 + 0x18) = sVar1 + -1;
    if (sVar1 != 1) {
      *(undefined4 *)(param_1 + 0x10) = 0;
      _vm_cache_lock = 0;
      goto locret_F00869E0;
    }
    uVar4 = *(uint *)(param_1 + 0x44);
    if ((uVar4 & 0x1000) != 0) {
      if (0 < *(sword *)(param_1 + 0x1a)) {
        iVar5 = param_1;
        if (unk_F013D41C != &_vm_object_cached_list) {
          unk_F013D41C[0x13] = param_1;
          iVar5 = _vm_object_cached_list;
        }
        _vm_object_cached_list = iVar5;
        *(undefined4 **)(param_1 + 0x50) = unk_F013D41C;
        *(int **)(param_1 + 0x4c) = &_vm_object_cached_list;
        _vm_object_cached = _vm_object_cached + 1;
        _vm_cache_lock = 0;
        iVar5 = param_1;
        unk_F013D41C = (undefined4 *)param_1;
        _vm_object_deactivate_pages();
        *(undefined4 *)(param_1 + 0x10) = 0;
        _vm_object_cache_trim();
        return CONCAT44(uVar4,iVar5);
      }
      *(uint *)(param_1 + 0x44) = uVar4 & 0xffffefff;
    }
    _vm_object_remove(*(undefined4 *)(param_1 + 0x28));
    _vm_cache_lock = 0;
    iVar5 = *(int *)(param_1 + 0x20);
    _vm_object_terminate(param_1);
    param_1 = iVar5;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1814 start=0xf00869e8 */

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
/* GHIDRADEC_FUNCTION index=1815 start=0xf0086ce8 */

/* WARNING: Removing unreachable block (ram,0xf0086d00) */
/* WARNING: Removing unreachable block (ram,0xf0086cec) */

undefined8 _vm_object_destroy(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  iVar1 = param_1;
  _vm_object_lookup();
  if (iVar1 != 0) {
    _vm_object_deallocate();
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1816 start=0xf0086d10 */

/* WARNING: Removing unreachable block (ram,0xf0086d64) */
/* WARNING: Removing unreachable block (ram,0xf0086d40) */

undefined8 _vm_object_deactivate_pages(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 unaff_l0;
  int *piVar2;
  undefined4 unaff_l1;
  int *piVar3;
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
  piVar2 = (int *)*param_1;
  if (param_1 != piVar2) {
    piVar3 = (int *)piVar2[2];
    while( true ) {
      do {
        do {
        } while (_vm_page_queue_lock != 0);
        puVar1 = &_vm_page_queue_lock;
        _simple_lock_try();
      } while (puVar1 == (undefined4 *)0x0);
      if ((piVar2[7] & 0x8000U) == 0) {
        _vm_page_deactivate(piVar2);
      }
      _vm_page_queue_lock = 0;
      if (param_1 == piVar3) break;
      piVar2 = piVar3;
      piVar3 = (int *)piVar3[2];
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1817 start=0xf0086d88 */

/* WARNING: Removing unreachable block (ram,0xf0086e10) */
/* WARNING: Removing unreachable block (ram,0xf0086df0) */
/* WARNING: Removing unreachable block (ram,0xf0086e04) */
/* WARNING: Removing unreachable block (ram,0xf0086e2c) */
/* WARNING: Removing unreachable block (ram,0xf0086da4) */

undefined8 _vm_object_cache_trim(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  do {
    do {
    } while (_vm_cache_lock != 0);
    puVar2 = &_vm_cache_lock;
    _simple_lock_try();
  } while (puVar2 == (undefined4 *)0x0);
  if (_vm_cache_max < _vm_object_cached) {
    do {
      iVar1 = _vm_object_cached_list;
      _vm_cache_lock = 0;
      iVar3 = *(int *)(_vm_object_cached_list + 0x28);
      _vm_object_lookup();
      if (iVar1 != iVar3) {
        _panic(aVmObjectDeacti);
      }
      _vm_object_cache_object(iVar1,0);
      do {
        do {
        } while (_vm_cache_lock != 0);
        puVar2 = &_vm_cache_lock;
        _simple_lock_try();
      } while (puVar2 == (undefined4 *)0x0);
    } while (_vm_cache_max < _vm_object_cached);
  }
  _vm_cache_lock = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1818 start=0xf0086e60 */

/* WARNING: Removing unreachable block (ram,0xf0086eb4) */
/* WARNING: Removing unreachable block (ram,0xf0086ef4) */
/* WARNING: Removing unreachable block (ram,0xf0086e8c) */

undefined8 _vm_object_cache_object(int param_1,uint param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
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
  if (param_1 == 0) {
    uVar3 = 4;
  }
  else {
    do {
      do {
      } while (_vm_cache_lock != 0);
      puVar1 = &_vm_cache_lock;
      _simple_lock_try();
    } while (puVar1 == (undefined4 *)0x0);
    do {
      do {
      } while (*(int *)(param_1 + 0x10) != 0);
      piVar2 = (int *)(param_1 + 0x10);
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) & 0xffffefff | (param_2 & 1) << 0xc;
    _vm_cache_lock = 0;
    uVar3 = 0;
    _vm_object_deallocate();
  }
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=1819 start=0xf0086f04 */

/* WARNING: Removing unreachable block (ram,0xf0086f08) */

undefined8 _vm_object_shutdown(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  _vm_object_cache_clear();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1820 start=0xf0086f18 */

/* WARNING: Removing unreachable block (ram,0xf0086f88) */
/* WARNING: Removing unreachable block (ram,0xf0086f38) */

undefined8 _vm_object_pmap_copy(int *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  undefined4 unaff_l0;
  int *piVar2;
  undefined4 unaff_l1;
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
  if (param_1 != (int *)0x0) {
    do {
      do {
      } while (param_1[4] != 0);
      piVar2 = param_1 + 4;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    piVar2 = (int *)*param_1;
    if (param_1 != piVar2) {
      uVar1 = piVar2[6];
      do {
        if (uVar1 < param_2) {
loc_F0086F9C:
          piVar2 = (int *)piVar2[2];
        }
        else if (uVar1 < param_3) {
          if ((piVar2[8] & 0x200000U) == 0) {
            _pmap_copy_on_write(piVar2[9]);
            piVar2[8] = piVar2[8] | 0x200000;
            goto loc_F0086F9C;
          }
          piVar2 = (int *)piVar2[2];
        }
        else {
          piVar2 = (int *)piVar2[2];
        }
        if (param_1 == piVar2) break;
        uVar1 = piVar2[6];
      } while( true );
    }
    param_1[4] = 0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1821 start=0xf0086fb8 */

/* WARNING: Removing unreachable block (ram,0xf0087014) */
/* WARNING: Removing unreachable block (ram,0xf0086fd8) */

undefined8 _vm_object_pmap_remove(int *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  undefined4 unaff_l0;
  int *piVar2;
  undefined4 unaff_l1;
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
  if (param_1 != (int *)0x0) {
    do {
      do {
      } while (param_1[4] != 0);
      piVar2 = param_1 + 4;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    piVar2 = (int *)*param_1;
    if (param_1 != piVar2) {
      uVar1 = piVar2[6];
      do {
        if (uVar1 < param_2) {
loc_F008701C:
          piVar2 = (int *)piVar2[2];
        }
        else {
          if (uVar1 < param_3) {
            _pmap_remove_all(piVar2[9]);
            goto loc_F008701C;
          }
          piVar2 = (int *)piVar2[2];
        }
        if (param_1 == piVar2) break;
        uVar1 = piVar2[6];
      } while( true );
    }
    param_1[4] = 0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1822 start=0xf0087038 */

/* WARNING: Removing unreachable block (ram,0xf008722c) */
/* WARNING: Removing unreachable block (ram,0xf00871cc) */
/* WARNING: Removing unreachable block (ram,0xf008714c) */
/* WARNING: Removing unreachable block (ram,0xf0087108) */
/* WARNING: Removing unreachable block (ram,0xf0087120) */
/* WARNING: Removing unreachable block (ram,0xf00871b0) */
/* WARNING: Removing unreachable block (ram,0xf00871f0) */
/* WARNING: Removing unreachable block (ram,0xf0087064) */

undefined8
_vm_object_copy(int *param_1,uint param_2,int param_3,int *param_4,uint *param_5,undefined4 *param_6
               )

{
  sword sVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  undefined4 unaff_l0;
  int iVar6;
  int iVar7;
  undefined4 unaff_l1;
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
  if (param_1 == (int *)0x0) {
    *param_4 = 0;
    *param_5 = 0;
loc_F00872C8:
    *param_6 = 0;
  }
  else {
    do {
      do {
      } while (param_1[4] != 0);
      piVar5 = param_1 + 4;
      _simple_lock_try();
    } while (piVar5 == (int *)0x0);
    if (param_1[10] == 0) {
      sVar1 = *(sword *)(param_1 + 6);
    }
    else {
      if ((param_1[0x11] & 0x800U) == 0) {
        _vm_object_collapse(param_1);
        iVar6 = param_1[7];
        while (iVar6 != 0) {
          iVar7 = iVar6 + 0x10;
          _simple_lock_try();
          if (iVar7 != 0) {
            if ((*(sword *)(iVar6 + 0x1a) != 0) || (*(int *)(iVar6 + 0x28) != 0)) {
              *(undefined4 *)(iVar6 + 0x10) = 0;
              iVar6 = param_1[5];
              goto loc_F00871AC;
            }
            *(undefined4 *)(iVar6 + 0x10) = 0;
            *(sword *)(iVar6 + 0x18) = *(sword *)(iVar6 + 0x18) + 1;
            param_1[4] = 0;
            *param_4 = iVar6;
            *param_5 = param_2;
            goto loc_F00872C8;
          }
          param_1[4] = 0;
          do {
            do {
            } while (param_1[4] != 0);
            piVar5 = param_1 + 4;
            _simple_lock_try();
          } while (piVar5 == (int *)0x0);
          iVar6 = param_1[7];
        }
        iVar6 = param_1[5];
loc_F00871AC:
        param_1[4] = 0;
        _vm_object_allocate();
        while( true ) {
          do {
            do {
              piVar5 = param_1 + 4;
            } while (*piVar5 != 0);
            _simple_lock_try();
          } while (piVar5 == (int *)0x0);
          iVar7 = param_1[7];
          if (iVar7 == 0) {
            *(int **)(iVar6 + 0x20) = param_1;
            goto loc_F0087258;
          }
          iVar3 = iVar7 + 0x10;
          _simple_lock_try();
          if (iVar3 != 0) break;
          param_1[4] = 0;
        }
        if ((*(int **)(iVar7 + 0x20) != param_1) || (*(int *)(iVar7 + 0x24) != 0)) {
          _panic(aVmObjectCopyCo);
        }
        *(sword *)(param_1 + 6) = *(sword *)(param_1 + 6) + -1;
        *(int *)(iVar7 + 0x20) = iVar6;
        *(sword *)(iVar6 + 0x18) = *(sword *)(iVar6 + 0x18) + 1;
        *(undefined4 *)(iVar7 + 0x10) = 0;
        *(int **)(iVar6 + 0x20) = param_1;
loc_F0087258:
        *(undefined4 *)(iVar6 + 0x24) = 0;
        piVar5 = (int *)*param_1;
        uVar2 = *(uint *)(iVar6 + 0x14);
        *(sword *)(param_1 + 6) = *(sword *)(param_1 + 6) + 1;
        param_1[7] = iVar6;
        if (param_1 != piVar5) {
          uVar4 = piVar5[6];
          while( true ) {
            if (uVar4 < uVar2) {
              piVar5[8] = piVar5[8] | 0x200000;
              piVar5 = (int *)piVar5[2];
            }
            else {
              piVar5 = (int *)piVar5[2];
            }
            if (param_1 == piVar5) break;
            uVar4 = piVar5[6];
          }
        }
        param_1[4] = 0;
        *param_4 = iVar6;
        *param_5 = param_2;
        goto loc_F00872C8;
      }
      sVar1 = *(sword *)(param_1 + 6);
    }
    piVar5 = (int *)*param_1;
    *(sword *)(param_1 + 6) = sVar1 + 1;
    if (param_1 != piVar5) {
      uVar2 = piVar5[6];
      while( true ) {
        if (uVar2 < param_2) {
          piVar5 = (int *)piVar5[2];
        }
        else if (uVar2 < param_2 + param_3) {
          piVar5[8] = piVar5[8] | 0x200000;
          piVar5 = (int *)piVar5[2];
        }
        else {
          piVar5 = (int *)piVar5[2];
        }
        if (param_1 == piVar5) break;
        uVar2 = piVar5[6];
      }
    }
    param_1[4] = 0;
    *param_4 = (int)param_1;
    *param_5 = param_2;
    *param_6 = 1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1823 start=0xf00872d4 */

/* WARNING: Removing unreachable block (ram,0xf00872f4) */
/* WARNING: Removing unreachable block (ram,0xf00872dc) */

undefined8 _vm_object_shadow(int *param_1,undefined4 *param_2,int param_3)

{
  undefined4 unaff_l0;
  int iVar1;
  undefined4 unaff_l1;
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
  iVar1 = *param_1;
  _vm_object_allocate();
  if (param_3 == 0) {
    _panic(aVmObjectShadow);
    iRam00000020 = iVar1;
  }
  else {
    *(int *)(param_3 + 0x20) = iVar1;
  }
  *(undefined4 *)(param_3 + 0x24) = *param_2;
  *param_2 = 0;
  *param_1 = param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1824 start=0xf0087318 */

/* WARNING: Removing unreachable block (ram,0xf0087330) */

undefined8 _vm_object_setpager(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  do {
    do {
    } while (*(int *)(param_1 + 0x10) != 0);
    piVar1 = (int *)(param_1 + 0x10);
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  *(undefined4 *)(param_1 + 0x28) = param_2;
  *(undefined4 *)(param_1 + 0x2c) = param_3;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1825 start=0xf0087358 */

/* WARNING: Removing unreachable block (ram,0xf00873e4) */
/* WARNING: Removing unreachable block (ram,0xf008738c) */

undefined8 _vm_object_lookup(uint param_1,undefined4 param_2)

{
  sword sVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 *puVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar6;
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
  puVar5 = (undefined4 *)(_vm_object_hashtable + (param_1 & 0x7f) * 8);
  do {
    do {
    } while (_vm_cache_lock != 0);
    puVar2 = &_vm_cache_lock;
    _simple_lock_try();
  } while (puVar2 == (undefined4 *)0x0);
  puVar2 = (undefined4 *)*puVar5;
  if (puVar5 == puVar2) {
loc_F008746C:
    iVar6 = 0;
  }
  else {
    iVar6 = puVar2[2];
    while (*(uint *)(iVar6 + 0x28) != param_1) {
      puVar2 = (undefined4 *)*puVar2;
      if (puVar5 == puVar2) goto loc_F008746C;
      iVar6 = puVar2[2];
    }
    do {
      do {
      } while (*(int *)(iVar6 + 0x10) != 0);
      piVar3 = (int *)(iVar6 + 0x10);
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
    if (*(sword *)(iVar6 + 0x18) == 0) {
      puVar5 = *(undefined4 **)(iVar6 + 0x4c);
      puVar4 = *(undefined4 **)(iVar6 + 0x50);
      puVar2 = puVar4;
      if ((undefined4 **)puVar5 != &_vm_object_cached_list) {
        puVar5[0x14] = puVar4;
        puVar2 = unk_F013D41C;
      }
      unk_F013D41C = puVar2;
      if ((undefined4 **)puVar4 != &_vm_object_cached_list) {
        puVar4[0x13] = puVar5;
        puVar5 = _vm_object_cached_list;
      }
      _vm_object_cached_list = puVar5;
      _vm_object_cached = _vm_object_cached + -1;
      sVar1 = *(sword *)(iVar6 + 0x18);
    }
    else {
      sVar1 = *(sword *)(iVar6 + 0x18);
    }
    *(undefined4 *)(iVar6 + 0x10) = 0;
    *(sword *)(iVar6 + 0x18) = sVar1 + 1;
  }
  _vm_cache_lock = 0;
  return CONCAT44(param_2,iVar6);
}
/* GHIDRADEC_FUNCTION index=1826 start=0xf008747c */

/* WARNING: Removing unreachable block (ram,0xf00874e0) */
/* WARNING: Removing unreachable block (ram,0xf00874a8) */

undefined8 _vm_object_enter(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 *puVar3;
  undefined4 unaff_l1;
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
  if ((param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    iVar2 = ((uint)param_2 & 0x7f) * 8;
    puVar3 = (undefined4 *)(_vm_object_hashtable + iVar2);
    param_2 = _object_hash_zone;
    _zalloc();
    param_2[2] = param_1;
    *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) | 0x1000;
    do {
      do {
      } while (_vm_cache_lock != 0);
      puVar1 = &_vm_cache_lock;
      _simple_lock_try();
    } while (puVar1 == (undefined4 *)0x0);
    puVar1 = *(undefined4 **)(_vm_object_hashtable + iVar2 + 4);
    if (puVar3 == puVar1) {
      *puVar3 = param_2;
    }
    else {
      *puVar1 = param_2;
    }
    param_2[1] = puVar1;
    *param_2 = puVar3;
    *(undefined4 **)(_vm_object_hashtable + iVar2 + 4) = param_2;
    _vm_cache_lock = 0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1827 start=0xf0087524 */

/* WARNING: Removing unreachable block (ram,0xf0087590) */

undefined8 _vm_object_remove(uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  iVar3 = (param_1 & 0x7f) * 8;
  puVar6 = *(undefined4 **)(_vm_object_hashtable + iVar3);
  puVar4 = (undefined4 *)(_vm_object_hashtable + iVar3);
  if (puVar4 != puVar6) {
    iVar1 = puVar6[2];
    while (*(uint *)(iVar1 + 0x28) != param_1) {
      puVar6 = (undefined4 *)*puVar6;
      if (puVar4 == puVar6) goto locret_F00875A8;
      iVar1 = puVar6[2];
    }
    puVar5 = (undefined4 *)*puVar6;
    puVar2 = (undefined4 *)puVar6[1];
    if (puVar4 == puVar5) {
      *(undefined4 **)(_vm_object_hashtable + iVar3 + 4) = puVar2;
    }
    else {
      puVar5[1] = puVar2;
    }
    if (puVar4 == puVar2) {
      *puVar4 = puVar5;
    }
    else {
      *puVar2 = puVar5;
    }
    _zfree(_object_hash_zone,puVar6);
  }
locret_F00875A8:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1828 start=0xf00875b0 */

/* WARNING: Removing unreachable block (ram,0xf008762c) */
/* WARNING: Removing unreachable block (ram,0xf008760c) */
/* WARNING: Removing unreachable block (ram,0xf0087620) */
/* WARNING: Removing unreachable block (ram,0xf0087648) */
/* WARNING: Removing unreachable block (ram,0xf00875cc) */

undefined8 _vm_object_cache_clear(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  do {
    do {
    } while (_vm_cache_lock != 0);
    puVar1 = &_vm_cache_lock;
    _simple_lock_try();
  } while (puVar1 == (undefined4 *)0x0);
  if ((undefined4 **)_vm_object_cached_list != &_vm_object_cached_list) {
    do {
      puVar1 = _vm_object_cached_list;
      _vm_cache_lock = 0;
      puVar2 = (undefined4 *)_vm_object_cached_list[10];
      _vm_object_lookup();
      if (puVar1 != puVar2) {
        _panic(aVmObjectCacheC);
      }
      _vm_object_cache_object(puVar1,0);
      do {
        do {
        } while (_vm_cache_lock != 0);
        puVar1 = &_vm_cache_lock;
        _simple_lock_try();
      } while (puVar1 == (undefined4 *)0x0);
    } while ((undefined4 **)_vm_object_cached_list != &_vm_object_cached_list);
  }
  _vm_cache_lock = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1829 start=0xf0087680 */

/* WARNING: Removing unreachable block (ram,0xf0087880) */
/* WARNING: Removing unreachable block (ram,0xf00877f0) */
/* WARNING: Removing unreachable block (ram,0xf00877c4) */
/* WARNING: Removing unreachable block (ram,0xf0087784) */
/* WARNING: Removing unreachable block (ram,0xf0087938) */
/* WARNING: Removing unreachable block (ram,0xf0087960) */
/* WARNING: Removing unreachable block (ram,0xf008779c) */
/* WARNING: Removing unreachable block (ram,0xf00877d8) */
/* WARNING: Removing unreachable block (ram,0xf008785c) */
/* WARNING: Removing unreachable block (ram,0xf00878e0) */
/* WARNING: Removing unreachable block (ram,0xf00876ec) */

undefined8 _vm_object_collapse(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 unaff_l0;
  uint uVar6;
  undefined4 unaff_l1;
  int *piVar7;
  int iVar8;
  undefined4 unaff_l3;
  uint uVar9;
  undefined4 unaff_l4;
  uint uVar10;
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
  if (_vm_object_collapse_allowed == 0) {
locret_F008799C:
    return CONCAT44(param_2,param_1);
  }
loc_F00876A0:
  if (((param_1 == 0) || (*(sword *)(param_1 + 0x44) != 0)) || (*(int *)(param_1 + 0x28) != 0))
  goto locret_F008799C;
  piVar7 = *(int **)(param_1 + 0x20);
  if (piVar7 == (int *)0x0) goto locret_F008799C;
  do {
    do {
    } while (piVar7[4] != 0);
    piVar2 = piVar7 + 4;
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  if ((piVar7[0x11] & 0xffff0800U) == 0x800) {
    if (piVar7[8] == 0) {
      uVar9 = *(uint *)(param_1 + 0x24);
    }
    else {
      if (*(int *)(piVar7[8] + 0x1c) != 0) goto loc_F0087734;
      uVar9 = *(uint *)(param_1 + 0x24);
    }
    uVar10 = *(uint *)(param_1 + 0x14);
    if (*(sword *)(piVar7 + 6) == 1) {
      piVar2 = (int *)*piVar7;
loc_F00877FC:
      do {
        if (piVar7 == piVar2) goto loc_f0087808;
        iVar8 = *piVar7;
        uVar6 = *(uint *)(iVar8 + 0x18) - uVar9;
        if ((*(uint *)(iVar8 + 0x18) < uVar9) || (uVar10 <= uVar6)) {
          do {
            do {
            } while (_vm_page_queue_lock != 0);
            puVar4 = &_vm_page_queue_lock;
            _simple_lock_try();
          } while (puVar4 == (undefined4 *)0x0);
        }
        else {
          iVar3 = param_1;
          _vm_page_lookup(param_1,uVar6);
          if (iVar3 == 0) {
            _vm_page_rename(iVar8,param_1,uVar6);
            piVar2 = (int *)*piVar7;
            goto loc_F00877FC;
          }
          do {
            do {
            } while (_vm_page_queue_lock != 0);
            puVar4 = &_vm_page_queue_lock;
            _simple_lock_try();
          } while (puVar4 == (undefined4 *)0x0);
        }
        _vm_page_free(iVar8);
        _vm_page_queue_lock = 0;
        piVar2 = (int *)*piVar7;
      } while( true );
    }
    if (piVar7[10] == 0) {
      piVar2 = (int *)*piVar7;
      if (piVar7 == piVar2) {
        iVar8 = piVar7[8];
      }
      else {
        uVar6 = piVar2[6];
        while( true ) {
          if (((uVar9 <= uVar6) && (uVar6 - uVar9 <= uVar10)) &&
             (iVar8 = param_1, _vm_page_lookup(param_1,uVar6 - uVar9), iVar8 == 0))
          goto loc_F0087734;
          piVar2 = (int *)piVar2[2];
          if (piVar7 == piVar2) break;
          uVar6 = piVar2[6];
        }
        iVar8 = piVar7[8];
      }
      *(int *)(param_1 + 0x20) = iVar8;
      _vm_object_reference();
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + piVar7[9];
      piVar7[4] = 0;
      _object_bypasses = _object_bypasses + 1;
      *(sword *)(piVar7 + 6) = *(sword *)(piVar7 + 6) + -1;
      goto loc_F00876A0;
    }
  }
loc_F0087734:
  piVar7[4] = 0;
  goto locret_F008799C;
loc_f0087808:
  *(int *)(param_1 + 0x28) = piVar7[10];
  *(uint *)(param_1 + 0x2c) = piVar7[0xb] + uVar9;
  piVar7[10] = 0;
  piVar7[0xc] = 0;
  piVar7[0xd] = 0;
  *(int *)(param_1 + 0x20) = piVar7[8];
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + piVar7[9];
  if ((*(int *)(param_1 + 0x20) != 0) && (*(int *)(*(int *)(param_1 + 0x20) + 0x1c) != 0)) {
    _panic(aVmObjectCollap);
  }
  piVar7[4] = 0;
  do {
    do {
    } while (_vm_object_list_lock != 0);
    puVar4 = &_vm_object_list_lock;
    _simple_lock_try();
  } while (puVar4 == (undefined4 *)0x0);
  puVar4 = (undefined4 *)piVar7[2];
  puVar5 = (undefined4 *)piVar7[3];
  puVar1 = puVar5;
  if ((undefined4 **)puVar4 != &_vm_object_list) {
    puVar4[3] = puVar5;
    puVar1 = dword_F013D834;
  }
  dword_F013D834 = puVar1;
  if ((undefined4 **)puVar5 != &_vm_object_list) {
    puVar5[2] = puVar4;
    puVar4 = _vm_object_list;
  }
  _vm_object_list = puVar4;
  _vm_object_list_lock = 0;
  _vm_object_count = _vm_object_count + -1;
  _zfree(_vm_object_zone,piVar7);
  _object_collapses = _object_collapses + 1;
  goto loc_F00876A0;
}
/* GHIDRADEC_FUNCTION index=1830 start=0xf00879a4 */

/* WARNING: Removing unreachable block (ram,0xf00879fc) */
/* WARNING: Removing unreachable block (ram,0xf0087a10) */
/* WARNING: Removing unreachable block (ram,0xf00879e4) */

undefined8 _vm_object_page_remove(int *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  int *piVar3;
  undefined4 unaff_l1;
  int *piVar4;
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
  if ((param_1 != (int *)0x0) && (piVar3 = (int *)*param_1, param_1 != piVar3)) {
    uVar1 = piVar3[6];
    while( true ) {
      piVar4 = (int *)piVar3[2];
      if ((param_2 <= uVar1) && (uVar1 < param_3)) {
        _pmap_remove_all(piVar3[9]);
        do {
          do {
          } while (_vm_page_queue_lock != 0);
          puVar2 = &_vm_page_queue_lock;
          _simple_lock_try();
        } while (puVar2 == (undefined4 *)0x0);
        _vm_page_free(piVar3);
        _vm_page_queue_lock = 0;
      }
      if (param_1 == piVar4) break;
      uVar1 = piVar4[6];
      piVar3 = piVar4;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1831 start=0xf0087a34 */

/* WARNING: Removing unreachable block (ram,0xf0087a78) */
/* WARNING: Removing unreachable block (ram,0xf0087ad4) */
/* WARNING: Removing unreachable block (ram,0xf0087a64) */

undefined8
_vm_object_coalesce(int param_1,int *param_2,int param_3,undefined4 param_4,int param_5,int param_6)

{
  int *piVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  uint uVar3;
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
  if (param_2 == (int *)0x0) {
    param_2 = (int *)(param_1 + 0x10);
    if (param_1 != 0) {
      do {
        do {
        } while (*param_2 != 0);
        piVar1 = param_2;
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
      _vm_object_collapse(param_1);
      if ((((1 < *(sword *)(param_1 + 0x18)) || (*(int *)(param_1 + 0x28) != 0)) ||
          (*(int *)(param_1 + 0x20) != 0)) || (*(int *)(param_1 + 0x1c) != 0)) {
        *(undefined4 *)(param_1 + 0x10) = 0;
        uVar2 = 0;
        goto locret_F0087AF4;
      }
      uVar3 = param_3 + param_5 + param_6;
      _vm_object_page_remove(param_1,param_3 + param_5,uVar3);
      if (*(uint *)(param_1 + 0x14) < uVar3) {
        *(uint *)(param_1 + 0x14) = uVar3;
      }
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
locret_F0087AF4:
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1832 start=0xf0087afc */

/* WARNING: Removing unreachable block (ram,0xf0087b04) */

sqword _vm_object_request_object(undefined4 param_1,uint param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  _printf(aVmObjectReques);
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=1833 start=0xf0087b14 */

sqword _vm_object_name(undefined4 param_1,uint param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=1834 start=0xf0087b20 */

/* WARNING: Removing unreachable block (ram,0xf0087f00) */
/* WARNING: Removing unreachable block (ram,0xf0087eb0) */
/* WARNING: Removing unreachable block (ram,0xf0087e78) */
/* WARNING: Removing unreachable block (ram,0xf0087e2c) */
/* WARNING: Removing unreachable block (ram,0xf0087df8) */
/* WARNING: Removing unreachable block (ram,0xf0087dc0) */
/* WARNING: Removing unreachable block (ram,0xf0087d88) */
/* WARNING: Removing unreachable block (ram,0xf0087d58) */
/* WARNING: Removing unreachable block (ram,0xf0087d04) */
/* WARNING: Removing unreachable block (ram,0xf0087ca0) */
/* WARNING: Removing unreachable block (ram,0xf0087c80) */
/* WARNING: Removing unreachable block (ram,0xf0087c50) */
/* WARNING: Removing unreachable block (ram,0xf0087bd4) */
/* WARNING: Removing unreachable block (ram,0xf0087b80) */
/* WARNING: Removing unreachable block (ram,0xf0087b48) */
/* WARNING: Removing unreachable block (ram,0xf0087bb4) */
/* WARNING: Removing unreachable block (ram,0xf0087b88) */
/* WARNING: Removing unreachable block (ram,0xf0087c2c) */
/* WARNING: Removing unreachable block (ram,0xf0087b9c) */
/* WARNING: Removing unreachable block (ram,0xf0087c88) */
/* WARNING: Removing unreachable block (ram,0xf0087cd0) */
/* WARNING: Removing unreachable block (ram,0xf0087d1c) */
/* WARNING: Removing unreachable block (ram,0xf0087d64) */
/* WARNING: Removing unreachable block (ram,0xf0087db8) */
/* WARNING: Removing unreachable block (ram,0xf0087de0) */
/* WARNING: Removing unreachable block (ram,0xf0087e14) */
/* WARNING: Removing unreachable block (ram,0xf0087e50) */
/* WARNING: Removing unreachable block (ram,0xf0087ea8) */
/* WARNING: Removing unreachable block (ram,0xf0087ee0) */
/* WARNING: Removing unreachable block (ram,0xf0087f68) */
/* WARNING: Removing unreachable block (ram,0xf0087b24) */

undefined8 _vm_pageout_scan(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 unaff_l0;
  undefined4 *puVar5;
  undefined4 unaff_l1;
  undefined4 *puVar6;
  int iVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar8;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar9;
  bool bVar10;
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
  uVar8 = 0;
  _spltty();
  do {
    do {
    } while (_vm_page_queue_free_lock != 0);
    puVar5 = &_vm_page_queue_free_lock;
    _simple_lock_try();
  } while (puVar5 == (undefined4 *)0x0);
  bVar9 = _vm_page_free_min < _vm_page_free_count;
  if (bVar9) {
    _vm_page_queue_free_lock = 0;
    _splx(param_1);
  }
  else {
    _vm_page_queue_free_lock = 0;
    _splx(param_1);
    _pmap_update();
  }
  do {
    do {
    } while (_vm_page_queue_lock != 0);
    puVar5 = &_vm_page_queue_lock;
    _simple_lock_try();
  } while (puVar5 == (undefined4 *)0x0);
  if (bVar9) {
    uVar8 = 0;
  }
  else {
    param_2 = 0xbfffffff;
    puVar5 = _vm_page_queue_inactive;
    while (puVar6 = puVar5, uVar1 = 0xf0111c00, (undefined4 **)puVar6 != &_vm_page_queue_inactive) {
      _spltty();
      do {
        do {
        } while (_vm_page_queue_free_lock != 0);
        puVar5 = &_vm_page_queue_free_lock;
        _simple_lock_try();
      } while (puVar5 == (undefined4 *)0x0);
      if (_vm_page_free_target <= _vm_page_free_count) {
        _vm_page_queue_free_lock = 0;
        _splx(uVar1);
        break;
      }
      _vm_page_queue_free_lock = 0;
      _splx(uVar1);
      iVar2 = puVar6[9];
      _pmap_is_referenced();
      if (iVar2 == 0) {
        if ((puVar6[7] & 0x400) == 0) {
          if ((puVar6[7] & 0x2000) == 0) {
            puVar5 = (undefined4 *)*puVar6;
          }
          else {
            iVar7 = puVar6[5];
            iVar2 = iVar7 + 0x10;
            _simple_lock_try();
            if (iVar2 == 0) {
              puVar5 = (undefined4 *)*puVar6;
            }
            else {
              puVar6[8] = puVar6[8] | 0x80000000;
              _vm_page_queue_lock = 0;
              DAT_f013c258._8_4_ = DAT_f013c258._8_4_ + 1;
              _pmap_remove_all(puVar6[9]);
              _vm_object_collapse(iVar7);
              *(undefined4 *)(iVar7 + 0x10) = 0;
              *(sword *)(iVar7 + 0x44) = *(sword *)(iVar7 + 0x44) + 1;
              _thread_wakeup_prim(&_vm_page_free_count,0,0);
              iVar2 = *(int *)(iVar7 + 0x28);
              uVar8 = 1;
              bVar9 = false;
              if (iVar2 == 0) {
                iVar2 = *(int *)(iVar7 + 0x14);
                _vm_pager_allocate();
                bVar9 = iVar2 == 0;
                if (!bVar9) {
                  _vm_object_setpager(iVar7,iVar2,0,0);
                  bVar9 = iVar2 == 0;
                }
              }
              bVar10 = false;
              if (!bVar9) {
                _vm_pager_put(iVar2,puVar6);
                bVar10 = iVar2 == 0;
              }
              do {
                do {
                } while (*(int *)(iVar7 + 0x10) != 0);
                piVar4 = (int *)(iVar7 + 0x10);
                _simple_lock_try();
              } while (piVar4 == (int *)0x0);
              do {
                do {
                } while (_vm_page_queue_lock != 0);
                puVar5 = &_vm_page_queue_lock;
                _simple_lock_try();
              } while (puVar5 == (undefined4 *)0x0);
              puVar5 = (undefined4 *)*puVar6;
              if (bVar10) {
                puVar6[7] = puVar6[7] & 0xffffdfff;
              }
              else {
                _vm_page_activate(puVar6);
              }
              _pmap_clear_reference(puVar6[9]);
              uVar3 = puVar6[8];
              puVar6[8] = uVar3 & 0x7fffffff;
              if ((uVar3 & 0x40000000) != 0) {
                puVar6[8] = uVar3 & 0x3fffffff;
                _thread_wakeup_prim(puVar6,0,0);
              }
              *(sword *)(iVar7 + 0x44) = *(sword *)(iVar7 + 0x44) + -1;
              _thread_wakeup_prim(iVar7,0,0);
              *(undefined4 *)(iVar7 + 0x10) = 0;
            }
          }
        }
        else {
          iVar7 = puVar6[5];
          puVar5 = (undefined4 *)*puVar6;
          iVar2 = iVar7 + 0x10;
          _simple_lock_try();
          if (iVar2 != 0) {
            uVar8 = 1;
            puVar6[8] = puVar6[8] | 0x80000000;
            _vm_page_queue_lock = 0;
            _pmap_remove_all(puVar6[9]);
            do {
              do {
              } while (_vm_page_queue_lock != 0);
              puVar5 = &_vm_page_queue_lock;
              _simple_lock_try();
            } while (puVar5 == (undefined4 *)0x0);
            uVar3 = puVar6[8];
            puVar6[8] = uVar3 & 0x7fffffff;
            if ((uVar3 & 0x40000000) != 0) {
              puVar6[8] = uVar3 & 0x3fffffff;
              _thread_wakeup_prim(puVar6,0,0);
            }
            puVar5 = (undefined4 *)*puVar6;
            _vm_page_addfree(puVar6);
            *(undefined4 *)(iVar7 + 0x10) = 0;
          }
        }
      }
      else {
        puVar5 = (undefined4 *)*puVar6;
        _vm_page_activate(puVar6);
        DAT_f013c258._0_4_ = DAT_f013c258._0_4_ + 1;
      }
    }
  }
  iVar2 = (_vm_page_inactive_target - _vm_page_inactive_count) - _vm_page_free_count;
  while ((0 < iVar2 && ((undefined4 **)_vm_page_queue_active != &_vm_page_queue_active))) {
    uVar8 = 1;
    _vm_page_deactivate();
    iVar2 = iVar2 + -1;
  }
  _vm_page_queue_lock = 0;
  return CONCAT44(param_2,uVar8);
}
/* GHIDRADEC_FUNCTION index=1835 start=0xf0087f90 */

/* WARNING: Removing unreachable block (ram,0xf008819c) */
/* WARNING: Removing unreachable block (ram,0xf0088170) */
/* WARNING: Removing unreachable block (ram,0xf00880a0) */
/* WARNING: Removing unreachable block (ram,0xf0087fec) */
/* WARNING: Removing unreachable block (ram,0xf0087fc4) */
/* WARNING: Removing unreachable block (ram,0xf0088008) */
/* WARNING: Removing unreachable block (ram,0xf0088100) */
/* WARNING: Removing unreachable block (ram,0xf0088180) */
/* WARNING: Removing unreachable block (ram,0xf00881b4) */
/* WARNING: Removing unreachable block (ram,0xf0087fa0) */

void _vm_pageout(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined8 *puVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  *(undefined4 *)(_active_threads + 0x78) = 1;
  _spl0();
  if (_vm_page_free_min == (undefined8 *)0x0) {
    puVar3 = _vm_page_free_count;
    .div(_vm_page_free_count,0x32);
    uVar1 = _page_size;
    _vm_page_free_min = puVar3;
    if ((int)puVar3 < 3) {
      _vm_page_free_min = (undefined8 *)0x3;
    }
    puVar3 = _vm_page_free_min;
    .umul(_vm_page_free_min,_page_size);
    if (_vm_page_free_min_sanity < puVar3) {
      puVar3 = _vm_page_free_min_sanity;
      .udiv(_vm_page_free_min_sanity,uVar1);
      _vm_page_free_min = puVar3;
    }
  }
  if (_vm_page_free_reserved == 0) {
    _vm_page_free_reserved = 3;
  }
  if ((_vm_pageout_free_min == 0) &&
     (_vm_pageout_free_min = _vm_page_free_reserved / 2, 10 < _vm_pageout_free_min)) {
    _vm_pageout_free_min = 10;
  }
  if (_vm_page_free_target == 0) {
    _vm_page_free_target = (int)_vm_page_free_min << 2;
  }
  if (_vm_page_inactive_target == (undefined8 *)0x0) {
    puVar3 = _vm_page_free_count;
    .div(_vm_page_free_count,3);
    _vm_page_inactive_target = puVar3;
  }
  if (_vm_page_free_target <= (int)_vm_page_free_min) {
    _vm_page_free_target = (int)_vm_page_free_min + 1;
  }
  if ((int)_vm_page_inactive_target <= _vm_page_free_target) {
    _vm_page_inactive_target = (undefined8 *)(_vm_page_free_target + 1);
  }
  do {
    do {
    } while (_vm_pages_needed_lock != 0);
    puVar2 = &_vm_pages_needed_lock;
    _simple_lock_try();
  } while (puVar2 == (undefined4 *)0x0);
  puVar3 = (undefined8 *)0x1;
  do {
    if ((puVar3 == (undefined8 *)0x0) ||
       ((puVar3 = (undefined8 *)0xf0111c00, (int)_vm_page_free_min < (int)_vm_page_free_count &&
        ((_vm_page_free_target <= (int)_vm_page_free_count ||
         (puVar3 = _vm_page_inactive_target, (int)_vm_page_inactive_target < _vm_page_inactive_count
         )))))) {
      puVar3 = &_vm_pages_needed;
      _thread_sleep(&_vm_pages_needed,&_vm_pages_needed_lock,0);
    }
    else {
      _vm_pages_needed_lock = 0;
    }
    _vm_pageout_scan();
    do {
      do {
      } while (_vm_pages_needed_lock != 0);
      puVar2 = &_vm_pages_needed_lock;
      _simple_lock_try();
    } while (puVar2 == (undefined4 *)0x0);
    _thread_wakeup_prim(&_vm_page_free_count,0,0);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1836 start=0xf00881cc */

undefined8 _vm_pager_init(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1837 start=0xf00881d8 */

/* WARNING: Removing unreachable block (ram,0xf0088208) */
/* WARNING: Removing unreachable block (ram,0xf00881e8) */
/* WARNING: Removing unreachable block (ram,0xf0088218) */

undefined8 _vm_pager_get(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  if (param_1 == (int *)0x0) {
    _vm_page_zero_fill(param_2);
    uVar1 = 0;
  }
  else {
    uVar1 = param_2;
    if (*param_1 == 0) {
      _vnode_pagein(param_2);
    }
    else {
      _device_pagein(param_2,param_3);
    }
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=1838 start=0xf008822c */

/* WARNING: Removing unreachable block (ram,0xf0088264) */
/* WARNING: Removing unreachable block (ram,0xf0088258) */
/* WARNING: Removing unreachable block (ram,0xf0088240) */

undefined8 _vm_pager_put(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  if (param_1 == (int *)0x0) {
    _panic(aVmPagerPutNull);
    iVar1 = iRam00000000;
  }
  else {
    iVar1 = *param_1;
  }
  uVar2 = param_2;
  if (iVar1 == 0) {
    _vnode_pageout(param_2);
  }
  else {
    _device_pageout(param_2);
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1839 start=0xf0088274 */

/* WARNING: Removing unreachable block (ram,0xf00882ac) */
/* WARNING: Removing unreachable block (ram,0xf00882a0) */
/* WARNING: Removing unreachable block (ram,0xf0088288) */

undefined8 _vm_pager_deallocate(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  if (param_1 == (int *)0x0) {
    _panic(aVmPagerDealloc);
    iVar1 = iRam00000000;
  }
  else {
    iVar1 = *param_1;
  }
  if (iVar1 == 0) {
    _vnode_dealloc(param_1);
  }
  else {
    _device_dealloc(param_1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1840 start=0xf00882bc */

/* WARNING: Removing unreachable block (ram,0xf00882c0) */

undefined8 _vm_pager_allocate(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  _vnode_alloc(param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1841 start=0xf00882d0 */

/* WARNING: Removing unreachable block (ram,0xf00882fc) */
/* WARNING: Removing unreachable block (ram,0xf00882f0) */

undefined8 _vm_pager_has_page(int *param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  if ((param_1 == (int *)0x0) || (*param_1 != 0)) {
    _panic(aVmPagerHasPage);
  }
  _vnode_has_page(param_1,param_2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1842 start=0xf0088474 */

/* WARNING: Removing unreachable block (ram,0xf0088554) */
/* WARNING: Removing unreachable block (ram,0xf0088530) */
/* WARNING: Removing unreachable block (ram,0xf008851c) */
/* WARNING: Removing unreachable block (ram,0xf008854c) */
/* WARNING: Removing unreachable block (ram,0xf0088574) */
/* WARNING: Removing unreachable block (ram,0xf00884e0) */

undefined8 _vm_policy_apply(int *param_1,int param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  bool bVar4;
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
  uVar3 = 0;
  if (*(sword *)(param_1 + 6) < 3) {
loc_F00884B4:
    bVar4 = (param_3 & 2) == 0;
  }
  else {
    param_1 = (int *)param_1[10];
    bVar4 = (param_3 & 2) == 0;
    if ((param_1 != (int *)0x0) && (bVar4 = (param_3 & 2) == 0, *param_1 == 0)) {
      uVar3 = (uint)param_1[3] >> 0x1f ^ 1;
      goto loc_F00884B4;
    }
  }
  if ((bVar4) && (uVar3 != 0)) goto locret_F0088584;
  param_1 = &_vm_page_queue_lock;
  do {
    do {
    } while (_vm_page_queue_lock != 0);
    piVar1 = param_1;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  if (param_3 == 0) {
    if ((*(uint *)(param_2 + 0x1c) & 0x400) == 0) {
      uVar3 = *(uint *)(param_2 + 0x1c);
loc_F008853C:
      if ((uVar3 & 0x4000) != 0) {
        _vm_page_deactivate(param_2);
      }
    }
    else {
      iVar2 = *(int *)(param_2 + 0x24);
      _pmap_is_modified();
      if (iVar2 != 0) {
        uVar3 = *(uint *)(param_2 + 0x1c);
        goto loc_F008853C;
      }
      sub_F008830C(param_2);
    }
    _pmap_remove_all(*(undefined4 *)(param_2 + 0x24));
  }
  else if ((param_3 == 1) && ((*(uint *)(param_2 + 0x1c) & 0x4000) != 0)) {
    _vm_page_deactivate(param_2);
  }
  _vm_page_queue_lock = 0;
locret_F0088584:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1843 start=0xf00887e0 */

/* WARNING: Removing unreachable block (ram,0xf0088820) */

undefined8 _vm_set_policy(int param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  if (param_1 == 0) {
    uVar1 = 5;
  }
  else {
    if (param_3 == 0) {
      param_3 = *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14);
    }
    if (param_2 == 0) {
      param_2 = *(int *)(param_1 + 0x14);
    }
    sub_F008872C(param_1,param_2,param_2 + param_3,param_4);
    uVar1 = 0;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=1844 start=0xf0088834 */

undefined8 _vm_fault_range(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  return CONCAT44(param_2,4);
}
/* GHIDRADEC_FUNCTION index=1845 start=0xf0088840 */

/* WARNING: Removing unreachable block (ram,0xf0088880) */

undefined8 _vm_deactivate(int param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  if (param_1 == 0) {
    uVar1 = 5;
  }
  else {
    if (param_3 == 0) {
      param_3 = *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14);
    }
    if (param_2 == 0) {
      param_2 = *(int *)(param_1 + 0x14);
    }
    sub_F0088660(param_1,param_2,param_3,param_4);
    uVar1 = 0;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=1846 start=0xf0088894 */

/* WARNING: Removing unreachable block (ram,0xf00888b8) */

undefined8 _vm_set_page_size(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  _page_mask = _page_size - 1;
  if ((_page_mask & _page_size) != 0) {
    _panic(aVmSetPageSizeP);
  }
  _page_shift = 0;
  if (_page_size != 1) {
    _page_shift = 0;
    do {
      _page_shift = _page_shift + 1;
    } while (1 << ((byte)_page_shift & 0x1f) != _page_size);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1847 start=0xf0088900 */

/* WARNING: Removing unreachable block (ram,0xf0088c04) */
/* WARNING: Removing unreachable block (ram,0xf0088b88) */
/* WARNING: Removing unreachable block (ram,0xf0088b64) */
/* WARNING: Removing unreachable block (ram,0xf0088b40) */
/* WARNING: Removing unreachable block (ram,0xf0088adc) */
/* WARNING: Removing unreachable block (ram,0xf0088af0) */
/* WARNING: Removing unreachable block (ram,0xf0088b50) */
/* WARNING: Removing unreachable block (ram,0xf0088b74) */
/* WARNING: Removing unreachable block (ram,0xf0088b98) */
/* WARNING: Removing unreachable block (ram,0xf0088c40) */
/* WARNING: Removing unreachable block (ram,0xf0088acc) */

undefined8 _vm_page_startup(int *param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  int *piVar9;
  uint *puVar10;
  undefined4 *puVar11;
  uint uVar12;
  uint uVar13;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar14;
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
  uRamf013d964 = 0;
  uRamf013d968 = 0;
  uRamf013d96c = (uint)uRamf013d96c._2_2_;
  uRamf013d974 = 0;
  uRamf013d978 = 0;
  uRamf013d97c = 0;
  uVar2 = 0;
  uRamf013d970 = uRamf013d970 & 0x8047ffff | 0x80000000;
  uRamf013d96c = uRamf013d96c & 0xffff07ff | 0x400;
  _vm_page_queue_free_lock = 0;
  _vm_page_queue_lock = 0;
  dword_F013CC14 = &_vm_page_queue_free;
  _vm_page_queue_free = &_vm_page_queue_free;
  dword_F013CC0C = &_vm_page_queue_active;
  _vm_page_queue_active = &_vm_page_queue_active;
  dword_F013C22C = &_vm_page_queue_inactive;
  _vm_page_queue_inactive = &_vm_page_queue_inactive;
  if (param_1 < param_1 + param_2 * 7) {
    piVar9 = param_1 + 5;
    piVar14 = param_1;
    do {
      piVar14 = piVar14 + 7;
      uVar2 = uVar2 + ((piVar9[1] & ~_page_mask) - (*piVar9 + _page_mask & ~_page_mask));
      piVar9 = piVar9 + 7;
    } while (piVar14 < param_1 + param_2 * 7);
  }
  if (_vm_page_bucket_count == 0) {
    uVar2 = uVar2 >> ((byte)_page_shift & 0x1f);
    _vm_page_bucket_count = 1;
    if (1 < uVar2) {
      do {
        _vm_page_bucket_count = _vm_page_bucket_count << 1;
      } while (_vm_page_bucket_count < uVar2);
    }
  }
  _vm_page_hash_mask = _vm_page_bucket_count - 1;
  if ((_vm_page_hash_mask & _vm_page_bucket_count) != 0) {
    _printf(aVmPageBootstra);
  }
  iVar4 = _vm_page_bucket_count << 3;
  _vm_alloc_from_regions(iVar4,4);
  _vm_page_buckets = iVar4;
  _bzero();
  iVar4 = _vm_page_buckets;
  uVar2 = _vm_page_bucket_count;
  uVar12 = 0;
  iVar7 = _vm_page_buckets;
  if (_vm_page_bucket_count != 0) {
    do {
      *(undefined4 *)(iVar7 + 4) = 0;
      *(undefined4 *)(iVar4 + uVar12 * 8) = 0;
      uVar12 = uVar12 + 1;
      iVar7 = iVar7 + 8;
    } while (uVar12 < uVar2);
  }
  iVar4 = _page_size << 3;
  _zdata_size = iVar4;
  _vm_alloc_from_regions();
  _zdata = iVar4;
  _bzero();
  uVar5 = 800;
  _map_data_size = 800;
  _vm_alloc_from_regions(800,4);
  _map_data = uVar5;
  _bzero();
  uVar5 = 0x16000;
  _kentry_data_size = 0x16000;
  _vm_alloc_from_regions(0x16000,4);
  _kentry_data = uVar5;
  _bzero();
  if (param_1 < param_1 + param_2 * 7) {
    piVar9 = param_1 + 5;
    piVar14 = param_1;
    do {
      iVar4 = ((piVar9[1] & ~_page_mask) - (*piVar9 + _page_mask & ~_page_mask) >>
              ((byte)_page_shift & 0x1f)) * 0x30;
      _vm_alloc_from_regions(iVar4,4);
      *piVar14 = iVar4;
      _bzero();
      piVar14 = piVar14 + 7;
      piVar9 = piVar9 + 7;
    } while (piVar14 < param_1 + param_2 * 7);
  }
  uVar5 = _page_shift;
  uVar2 = _page_mask;
  _vm_page_free_count = 0;
  if (param_1 < param_1 + param_2 * 7) {
    puVar10 = (uint *)(param_1 + 3);
    uVar12 = ~_page_mask;
    piVar14 = param_1;
    do {
      uVar13 = 0;
      puVar10[2] = puVar10[2] + uVar2 & uVar12;
      uVar3 = puVar10[2];
      puVar10[3] = puVar10[3] & uVar12;
      puVar10[-2] = puVar10[2] >> ((byte)uVar5 & 0x1f);
      uVar6 = puVar10[3] >> ((byte)uVar5 & 0x1f);
      puVar10[-1] = uVar6;
      uVar6 = uVar6 - puVar10[-2];
      *puVar10 = uVar6;
      iVar4 = _page_size;
      puVar11 = (undefined4 *)*piVar14;
      _vm_page_free_count = _vm_page_free_count + uVar6;
      if (*puVar10 != 0) {
        puVar8 = puVar11 + 7;
        do {
          puVar8[2] = uVar3;
          puVar1 = puVar11;
          if ((undefined4 **)dword_F013CC14 != &_vm_page_queue_free) {
            *dword_F013CC14 = puVar11;
            puVar1 = _vm_page_queue_free;
          }
          _vm_page_queue_free = puVar1;
          puVar8[-6] = (uint)dword_F013CC14;
          *puVar11 = &_vm_page_queue_free;
          dword_F013CC14 = puVar11;
          *puVar8 = *puVar8 | 0x1000;
          puVar8 = puVar8 + 0xc;
          puVar11 = puVar11 + 0xc;
          uVar13 = uVar13 + 1;
          uVar3 = uVar3 + iVar4;
        } while (uVar13 < *puVar10);
      }
      piVar14 = piVar14 + 7;
      puVar10 = puVar10 + 7;
    } while (piVar14 < param_1 + param_2 * 7);
  }
  _vm_pages_needed_lock = 0;
  return CONCAT44(param_2,_virtual_avail + _page_mask & ~_page_mask);
}
/* GHIDRADEC_FUNCTION index=1848 start=0xf0088dac */

/* WARNING: Removing unreachable block (ram,0xf0088e18) */
/* WARNING: Removing unreachable block (ram,0xf0088dfc) */
/* WARNING: Removing unreachable block (ram,0xf0088e3c) */
/* WARNING: Removing unreachable block (ram,0xf0088dc4) */

undefined8 _vm_page_insert(int param_1,int *param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int *piVar3;
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
  if ((*(uint *)(param_1 + 0x20) & 0x20000000) != 0) {
    _panic(aVmPageInsert);
  }
  *(int **)(param_1 + 0x14) = param_2;
  *(uint *)(param_1 + 0x18) = param_3;
  iVar1 = ((int)param_2 + (param_3 >> ((byte)_page_shift & 0x1f)) & _vm_page_hash_mask) * 8;
  piVar3 = (int *)(_vm_page_buckets + iVar1);
  _spltty();
  do {
    do {
    } while (*piVar3 != 0);
    piVar2 = piVar3;
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  *(int *)(param_1 + 0x10) = piVar3[1];
  piVar3[1] = param_1;
  *piVar3 = 0;
  _splx(iVar1);
  piVar3 = (int *)param_2[1];
  if (param_2 == piVar3) {
    *param_2 = param_1;
  }
  else {
    piVar3[2] = param_1;
  }
  *(int **)(param_1 + 0xc) = piVar3;
  *(int **)(param_1 + 8) = param_2;
  param_2[1] = param_1;
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x20000000;
  *(sword *)((int)param_2 + 0x1a) = *(sword *)((int)param_2 + 0x1a) + 1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1849 start=0xf0088e88 */

/* WARNING: Removing unreachable block (ram,0xf0088ee8) */
/* WARNING: Removing unreachable block (ram,0xf0088f34) */
/* WARNING: Removing unreachable block (ram,0xf0088ecc) */

undefined8 _vm_page_remove(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 unaff_l0;
  int *piVar5;
  undefined4 unaff_l1;
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
  if ((*(uint *)(param_1 + 0x20) & 0x20000000) != 0) {
    iVar1 = (*(int *)(param_1 + 0x14) + (*(uint *)(param_1 + 0x18) >> ((byte)_page_shift & 0x1f)) &
            _vm_page_hash_mask) * 8;
    piVar5 = (int *)(_vm_page_buckets + iVar1);
    _spltty();
    do {
      do {
      } while (*piVar5 != 0);
      piVar2 = piVar5;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    iVar3 = piVar5[1];
    if (iVar3 == param_1) {
      piVar5[1] = *(int *)(param_1 + 0x10);
    }
    else {
      do {
        puVar4 = (undefined4 *)(iVar3 + 0x10);
        iVar3 = *(int *)(iVar3 + 0x10);
      } while (iVar3 != param_1);
      *puVar4 = *(undefined4 *)(iVar3 + 0x10);
    }
    *piVar5 = 0;
    _splx(iVar1);
    iVar1 = *(int *)(param_1 + 8);
    piVar5 = *(int **)(param_1 + 0xc);
    if (*(int *)(param_1 + 0x14) == iVar1) {
      *(int **)(iVar1 + 4) = piVar5;
    }
    else {
      *(int **)(iVar1 + 0xc) = piVar5;
    }
    if (*(int **)(param_1 + 0x14) == piVar5) {
      *piVar5 = iVar1;
    }
    else {
      piVar5[2] = iVar1;
    }
    *(sword *)(*(int *)(param_1 + 0x14) + 0x1a) = *(sword *)(*(int *)(param_1 + 0x14) + 0x1a) + -1;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xdfffffff;
  }
  return CONCAT44(param_2,param_1);
}

