
/* WARNING: Removing unreachable block (ram,0xf00849f0) */
/* WARNING: Removing unreachable block (ram,0xf008496c) */
/* WARNING: Removing unreachable block (ram,0xf0084918) */
/* WARNING: Removing unreachable block (ram,0xf008493c) */
/* WARNING: Removing unreachable block (ram,0xf00849cc) */
/* WARNING: Removing unreachable block (ram,0xf00849f8) */
/* WARNING: Removing unreachable block (ram,0xf00848d0) */

undefined8 _vm_map_submap(int param_1,uint param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 uVar3;
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
  uVar3 = 4;
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
  iVar2 = param_1;
  _vm_map_lookup_entry(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
  iVar1 = *(int *)((int)register0x00000038 + -0xc);
  if (iVar2 == 0) {
    *(undefined4 *)((int)register0x00000038 + -0xc) =
         *(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 4);
    iVar1 = *(int *)((int)register0x00000038 + -0xc);
  }
  else if (*(uint *)(iVar1 + 8) < param_2) {
    __vm_map_clip_start(param_1 + 0xc,iVar1,param_2);
    iVar1 = *(int *)((int)register0x00000038 + -0xc);
  }
  if (param_3 < *(uint *)(iVar1 + 0xc)) {
    __vm_map_clip_end(param_1 + 0xc,iVar1,param_3);
  }
  iVar2 = *(int *)((int)register0x00000038 + -0xc);
  if ((((*(uint *)(iVar2 + 8) == param_2) && (*(uint *)(iVar2 + 0xc) == param_3)) &&
      (-1 < (int)*(uint *)(iVar2 + 0x18))) &&
     ((iVar1 = *(int *)(iVar2 + 0x10), iVar1 == _vm_submap_object &&
      ((*(uint *)(iVar2 + 0x18) & 0x10000000) == 0)))) {
    *(undefined4 *)(iVar2 + 0x10) = 0;
    _vm_object_deallocate(iVar1);
    uVar3 = 0;
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
    *(undefined4 *)(iVar2 + 0x10) = param_4;
    *(uint *)(iVar2 + 0x18) = *(uint *)(iVar2 + 0x18) | 0x20000000;
    _vm_map_reference();
  }
  _lock_done(param_1);
  return CONCAT44(param_2,uVar3);
}
