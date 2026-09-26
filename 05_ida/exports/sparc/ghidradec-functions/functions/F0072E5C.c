
/* WARNING: Removing unreachable block (ram,0xf0072e7c) */
/* WARNING: Removing unreachable block (ram,0xf0072e70) */
/* WARNING: Removing unreachable block (ram,0xf0072eb4) */
/* WARNING: Removing unreachable block (ram,0xf0072e68) */

undefined8 _kernel_task_create(undefined4 param_1,int param_2)

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
  int iVar2;
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
  _task_create(param_1,0,(undefined *)((int)register0x00000038 + -0xc));
  _task_deallocate(*(undefined4 *)((int)register0x00000038 + -0xc));
  _vm_map_deallocate(*(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0xc));
  if (param_2 == 0) {
    *(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0xc) = _kernel_map;
  }
  else {
    uVar1 = _kernel_map;
    _kmem_suballoc(_kernel_map,(undefined *)((int)register0x00000038 + -0x10),
                   (undefined *)((int)register0x00000038 + -0x14),param_2,0);
    *(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0xc) = uVar1;
  }
  iVar2 = *(int *)((int)register0x00000038 + -0xc);
  *(undefined4 *)(iVar2 + 0x50) = 1;
  return CONCAT44(param_2,iVar2);
}
