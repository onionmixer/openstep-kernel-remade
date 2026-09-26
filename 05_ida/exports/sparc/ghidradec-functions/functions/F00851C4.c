
/* WARNING: Removing unreachable block (ram,0xf0085314) */
/* WARNING: Removing unreachable block (ram,0xf00852e0) */
/* WARNING: Removing unreachable block (ram,0xf0085294) */
/* WARNING: Removing unreachable block (ram,0xf0085204) */
/* WARNING: Removing unreachable block (ram,0xf0085220) */
/* WARNING: Removing unreachable block (ram,0xf00852bc) */
/* WARNING: Removing unreachable block (ram,0xf0085304) */
/* WARNING: Removing unreachable block (ram,0xf0085320) */
/* WARNING: Removing unreachable block (ram,0xf00851d0) */

sqword _vm_map_delete(int param_1,uint param_2,uint param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  undefined4 *puVar5;
  undefined4 unaff_l1;
  int iVar6;
  int iVar7;
  undefined4 unaff_l3;
  undefined4 *puVar8;
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
  iVar6 = param_1;
  _vm_map_lookup_entry(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
  puVar5 = *(undefined4 **)((int)register0x00000038 + -0xc);
  if (iVar6 == 0) {
    puVar5 = *(undefined4 **)(*(int *)((int)register0x00000038 + -0xc) + 4);
  }
  else {
    if ((uint)puVar5[2] < param_2) {
      __vm_map_clip_start(param_1 + 0xc,puVar5,param_2);
    }
    do {
      do {
      } while (*(int *)(param_1 + 0x3c) != 0);
      piVar1 = (int *)(param_1 + 0x3c);
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    *(undefined4 *)(param_1 + 0x38) = *puVar5;
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  if (param_2 <= *(uint *)(*(int *)(param_1 + 0x40) + 8)) {
    *(undefined4 *)(param_1 + 0x40) = *puVar5;
  }
  if (puVar5 != (undefined4 *)(param_1 + 0xc)) {
    uVar2 = puVar5[2];
    while (uVar2 < param_3) {
      if (param_3 < (uint)puVar5[3]) {
        __vm_map_clip_end(param_1 + 0xc,puVar5,param_3);
      }
      puVar8 = (undefined4 *)puVar5[1];
      param_2 = puVar5[2];
      iVar7 = puVar5[3];
      iVar6 = puVar5[4];
      if (*(sword *)(puVar5 + 10) != 0) {
        _vm_map_entry_unwire(param_1,puVar5);
      }
      if (iVar6 == _kernel_object) {
        _vm_object_page_remove(iVar6,puVar5[5],puVar5[5] + (iVar7 - param_2));
        iVar3 = *(int *)(param_1 + 0x2c);
      }
      else {
        iVar3 = *(int *)(param_1 + 0x2c);
      }
      if (iVar3 == 0) {
        _vm_object_pmap_remove(iVar6,puVar5[5],puVar5[5] + (iVar7 - param_2));
        uVar4 = *(undefined4 *)(param_1 + 0x24);
      }
      else {
        uVar4 = *(undefined4 *)(param_1 + 0x24);
      }
      _pmap_remove(uVar4,param_2,iVar7);
      _vm_map_entry_delete(param_1,puVar5);
      if (puVar8 == (undefined4 *)(param_1 + 0xc)) break;
      puVar5 = puVar8;
      uVar2 = puVar8[2];
    }
  }
  return (qword)param_2 << 0x20;
}
