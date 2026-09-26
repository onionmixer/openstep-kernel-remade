
/* WARNING: Removing unreachable block (ram,0xf006a82c) */
/* WARNING: Removing unreachable block (ram,0xf006a7d8) */
/* WARNING: Removing unreachable block (ram,0xf006a7b8) */
/* WARNING: Removing unreachable block (ram,0xf006a800) */
/* WARNING: Removing unreachable block (ram,0xf006a81c) */
/* WARNING: Removing unreachable block (ram,0xf006a7a4) */

undefined8
_load_machfile(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 *param_5)

{
  undefined4 unaff_l0;
  undefined4 uVar1;
  undefined4 unaff_l1;
  int iVar2;
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
  iVar2 = *(int *)(*(int *)(_active_threads + 0xc) + 0xc);
  uVar1 = *(undefined4 *)(iVar2 + 0x24);
  _pmap_reference(uVar1);
  _vm_map_create(uVar1,*(undefined4 *)(iVar2 + 0x14),*(undefined4 *)(iVar2 + 0x18),
                 *(undefined4 *)(iVar2 + 0x20));
  if (param_5 == (undefined4 *)0x0) {
    param_5 = (undefined4 *)((int)register0x00000038 + -0x20);
  }
  _memset(param_5,0,0x14);
  *param_5 = 0;
  sub_F006A83C(param_1,uVar1,param_2,param_3,param_4,0,0,param_5);
  if (param_1 == 0) {
    *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc) = uVar1;
    _vm_map_deallocate(iVar2);
    param_1 = 0;
  }
  else {
    _vm_map_deallocate(uVar1);
  }
  return CONCAT44(param_2,param_1);
}

